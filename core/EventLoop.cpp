#include "EventLoop.hpp"
#include "../http/HttpRequest.hpp"
#include "../http/HttpResponse.hpp"
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <cerrno>
#include <cstdio>

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
        if (clientBuffer.find("\r\n\r\n") != std::string::npos)
        {
            HttpRequest request;
            request.parse(clientBuffer);
            
            // Debug output
            std::cout << "[DEBUG] Method: " << request.getMethod() << std::endl;
            std::cout << "[DEBUG] URI: " << request.getUri() << std::endl;
            std::cout << "[DEBUG] Version: " << request.getVersion() << std::endl;
            
            // Create and build response
            HttpResponse response;
            response.setVersion("HTTP/1.1");
            
            std::string uri = request.getUri();
            std::string responseBody;
            
            if (uri == "/" || uri == "")
            {
                response.setStatus("200 OK");
                responseBody = "Hello, World! Welcome to Webserv.";
            }
            else
            {
                response.setStatus("404 Not Found");
                responseBody = "404 Not Found: The requested resource was not found.";
            }
            
            response.setBody(responseBody);
            
            char contentLengthStr[32];
            snprintf(contentLengthStr, sizeof(contentLengthStr), "%lu", responseBody.length());
            response.addHeader("Content-Length", contentLengthStr);
            response.addHeader("Content-Type", "text/plain");
            response.addHeader("Connection", "close");
            
            std::string rawResponse = response.buildRawResponse();
            
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
