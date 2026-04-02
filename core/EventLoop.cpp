#include "EventLoop.hpp"
#include "../http/HttpRequest.hpp"
#include "../http/HttpResponse.hpp"
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cerrno>
#include <cstdio>
#include <sys/stat.h>

namespace
{
std::string getContentType(const std::string& path)
{
    size_t dotPos = path.find_last_of('.');
    if (dotPos == std::string::npos)
        return "text/plain";

    const std::string extension = path.substr(dotPos);
    if (extension == ".html")
        return "text/html";
    if (extension == ".css")
        return "text/css";
    if (extension == ".js")
        return "application/javascript";
    if (extension == ".txt")
        return "text/plain";
    return "text/plain";
}

bool isHiddenUri(const std::string& uri)
{
    size_t start = 0;
    if (!uri.empty() && uri[0] == '/')
        start = 1;
    return (start < uri.size() && uri[start] == '.');
}

size_t parseContentLengthHeader(const std::string& requestHeaders)
{
    std::istringstream headerStream(requestHeaders);
    std::string line;

    // Skip request line
    std::getline(headerStream, line);

    while (std::getline(headerStream, line))
    {
        if (!line.empty() && line[line.size() - 1] == '\r')
            line.erase(line.size() - 1);
        if (line.empty())
            break;

        size_t colonPos = line.find(':');
        if (colonPos == std::string::npos)
            continue;

        std::string key = line.substr(0, colonPos);
        std::string value = line.substr(colonPos + 1);
        size_t start = value.find_first_not_of(" \t");
        if (start != std::string::npos)
            value = value.substr(start);
        else
            value.clear();

        if (key == "Content-Length")
        {
            std::istringstream iss(value);
            size_t length = 0;
            char extra = 0;
            if ((iss >> length) && !(iss >> extra))
                return length;
            return 0;
        }
    }
    return 0;
}

std::string stripUriParams(const std::string& uri)
{
    size_t queryPos = uri.find('?');
    if (queryPos == std::string::npos)
        return uri;
    return uri.substr(0, queryPos);
}

bool isBlockedUri(const std::string& uri)
{
    return uri.find("..") != std::string::npos || isHiddenUri(uri);
}

std::string resolvePath(const std::string& uri)
{
    if (uri == "/" || uri.empty())
        return "./www/index.html";
    return "./www" + uri;
}
}

EventLoop::EventLoop(int serverFd) : _serverFd(serverFd), _maxFd(serverFd)
{
    
}

void EventLoop::run()
{
    while (true)
    {
        // FD_ZERO: Initialize/clear a file descriptor set to empty
        FD_ZERO(&_readFds);

        // FD_SET: Add a file descriptor to a set
        FD_SET(_serverFd, &_readFds);

        _maxFd = _serverFd;
        for (size_t i = 0; i < _clients.size(); i++)
        {
            int clientFd = _clients[i]->getFd();
            FD_SET(clientFd, &_readFds);
            if (clientFd > _maxFd)
                _maxFd = clientFd;
        }

        int activity = select(_maxFd + 1, &_readFds, NULL, NULL, NULL);
        if (activity < 0)
        {
            std::cerr << "select() error: " << strerror(errno) << std::endl;
            continue;
        }

        // FD_ISSET: Check if a file descriptor is in a set (returns true if ready)
        if (FD_ISSET(_serverFd, &_readFds))
        {
            handleNewConnection();
        }

        for (size_t i = 0; i < _clients.size(); i++)
        {
            if (FD_ISSET(_clients[i]->getFd(), &_readFds))
            {
                handleClientData(_clients[i]);
            }
        }
    }
}

void EventLoop::handleNewConnection()
{
    int clientFd = accept(_serverFd, NULL, NULL);
    
    if (clientFd >= 0)
    {
        // Set non-blocking
        // F_SETFL: Set file status flags
        // O_NONBLOCK: Non-blocking mode 
        fcntl(clientFd, F_SETFL, O_NONBLOCK);
        
        Client* newClient = new Client(clientFd);
        _clients.push_back(newClient);
        
        std::cout << "New client connected: fd " << clientFd << std::endl;
    }
    else
    {
        std::cerr << "accept() error: " << strerror(errno) << std::endl;
    }
}

void EventLoop::handleClientData(Client* client)
{
    char buffer[4096];
    
    ssize_t bytesReceived = recv(client->getFd(), buffer, sizeof(buffer) - 1, 0);
    
    if (bytesReceived > 0)
    {
        buffer[bytesReceived] = '\0';
        client->appendToBuffer(buffer);
        
        const std::string& clientBuffer = client->getBuffer();
        const size_t headerEnd = clientBuffer.find("\r\n\r\n");
        if (headerEnd != std::string::npos)
        {
            const size_t bodyStart = headerEnd + 4;
            const size_t contentLength = parseContentLengthHeader(clientBuffer.substr(0, bodyStart));
            if (clientBuffer.size() < bodyStart + contentLength)
                return;

            HttpRequest request;
            request.parse(clientBuffer.substr(0, bodyStart + contentLength));
            
            // Debug output
            std::cout << "[DEBUG] Method: " << request.getMethod() << std::endl;
            std::cout << "[DEBUG] URI: " << request.getUri() << std::endl;
            std::cout << "[DEBUG] Version: " << request.getVersion() << std::endl;
            
            // Create and build response
            HttpResponse response;
            response.setVersion("HTTP/1.1");

            const std::string method = request.getMethod();
            const std::string uri = stripUriParams(request.getUri());
            std::string responseBody;

            if (isBlockedUri(uri))
            {
                response.setStatus("403 Forbidden");
                responseBody = "<h1>403 Forbidden</h1>";
                response.setBody(responseBody);
                response.addHeader("Content-Type", "text/html");
            }
            else if (method == "GET")
            {
                const std::string path = resolvePath(uri);

                std::ifstream file(path.c_str(), std::ios::in | std::ios::binary);
                if (!file)
                {
                    response.setStatus("404 Not Found");
                    responseBody = "404 Not Found";
                    response.setBody(responseBody);
                    response.addHeader("Content-Type", "text/plain");
                }
                else
                {
                    std::ostringstream fileBuffer;
                    fileBuffer << file.rdbuf();
                    responseBody = fileBuffer.str();

                    response.setStatus("200 OK");
                    response.setBody(responseBody);
                    response.addHeader("Content-Type", getContentType(path));
                }
            }
            else if (method == "POST")
            {
                response.setStatus("200 OK");
                responseBody = "POST received: " + request.getBody();
                response.setBody(responseBody);
                response.addHeader("Content-Type", "text/plain");
            }
            else if (method == "DELETE")
            {
                const std::string path = resolvePath(uri);
                struct stat pathStat;

                if (stat(path.c_str(), &pathStat) != 0)
                {
                    response.setStatus("404 Not Found");
                    responseBody = "404 Not Found";
                    response.setBody(responseBody);
                    response.addHeader("Content-Type", "text/plain");
                }
                else if (!S_ISREG(pathStat.st_mode))
                {
                    response.setStatus("403 Forbidden");
                    responseBody = "<h1>403 Forbidden</h1>";
                    response.setBody(responseBody);
                    response.addHeader("Content-Type", "text/html");
                }
                else if (std::remove(path.c_str()) == 0)
                {
                    response.setStatus("200 OK");
                    responseBody = "File deleted";
                    response.setBody(responseBody);
                    response.addHeader("Content-Type", "text/plain");
                }
                else
                {
                    response.setStatus("403 Forbidden");
                    responseBody = "<h1>403 Forbidden</h1>";
                    response.setBody(responseBody);
                    response.addHeader("Content-Type", "text/html");
                }
            }
            else
            {
                response.setMethodNotAllowed();
            }

            response.addHeader("Connection", "close");

            std::string rawResponse = response.buildResponse();
            
            // Send response to client
            ssize_t bytesSent = send(client->getFd(), rawResponse.c_str(), rawResponse.length(), 0);
            if (bytesSent < 0)
            {
                std::cerr << "send() error on fd " << client->getFd() << ": " << strerror(errno) << std::endl;
            }
            else
            {
                std::cout << "[DEBUG] Sent response: " << bytesSent << " bytes" << std::endl;
            }
            
            client->clearBuffer();
        }
    }
    else if (bytesReceived == 0)
    {
        std::cout << "Client disconnected: fd " << client->getFd() << std::endl;
        removeClient(client);
    }
    else
    {
        std::cerr << "recv() error on fd " << client->getFd() << ": " << strerror(errno) << std::endl;
        removeClient(client);
    }
}

void EventLoop::removeClient(Client* client)
{
    int fd = client->getFd();
    
    for (std::vector<Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it)
    {
        if (*it == client)
        {
            delete *it;  
            _clients.erase(it);
            break;
        }
    }
    
 
    _maxFd = _serverFd;
    for (size_t i = 0; i < _clients.size(); i++)
    {
        if (_clients[i]->getFd() > _maxFd)
            _maxFd = _clients[i]->getFd();
    }
    
    std::cout << "Removed client: fd " << fd << std::endl;
}
