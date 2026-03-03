#include "EventLoop.hpp"
#include "../http/HttpRequest.hpp"
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <cerrno>

EventLoop::EventLoop(int serverFd) : _serverFd(serverFd), _maxFd(serverFd)
{
    
}

void EventLoop::run()
{
    while (true)
    {
        // 1. Clear read set
        // FD_ZERO: Initialize/clear a file descriptor set to empty
        FD_ZERO(&_readFds);

        // 2. Add server_fd
        // FD_SET: Add a file descriptor to a set
        FD_SET(_serverFd, &_readFds);

        // 3. Add all client fds and calculate max_fd
        _maxFd = _serverFd;
        for (size_t i = 0; i < _clients.size(); i++)
        {
            int clientFd = _clients[i]->getFd();
            FD_SET(clientFd, &_readFds);
            if (clientFd > _maxFd)
                _maxFd = clientFd;
        }

        // 5. Call select
        int activity = select(_maxFd + 1, &_readFds, NULL, NULL, NULL);
        if (activity < 0)
        {
            std::cerr << "select() error: " << strerror(errno) << std::endl;
            continue;
        }

        // 6. If server_fd is ready, handle new connection
        // FD_ISSET: Check if a file descriptor is in a set (returns true if ready)
        if (FD_ISSET(_serverFd, &_readFds))
        {
            handleNewConnection();
        }

        // 7. Check each client for activity
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
    // 1. Accept the new connection
    int clientFd = accept(_serverFd, NULL, NULL);
    
    // 2. Check if valid
    if (clientFd >= 0)
    {
        // Set non-blocking
        // F_SETFL: Set file status flags
        // O_NONBLOCK: Non-blocking mode (operations return immediately)
        fcntl(clientFd, F_SETFL, O_NONBLOCK);
        
        // Create Client object and add to vector
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
    
    // 1. Read data
    ssize_t bytesReceived = recv(client->getFd(), buffer, sizeof(buffer) - 1, 0);
    
    // 2. If bytes > 0, append to buffer and check for complete request
    if (bytesReceived > 0)
    {
        buffer[bytesReceived] = '\0';
        client->appendToBuffer(buffer);
        
        // Check if HTTP request is complete (headers end with \r\n\r\n)
        const std::string& clientBuffer = client->getBuffer();
        if (clientBuffer.find("\r\n\r\n") != std::string::npos)
        {
            HttpRequest request;
            request.parse(clientBuffer);
            
            // Debug output
            std::cout << "[DEBUG] Method: " << request.getMethod() << std::endl;
            std::cout << "[DEBUG] URI: " << request.getUri() << std::endl;
            std::cout << "[DEBUG] Version: " << request.getVersion() << std::endl;
            
            client->clearBuffer();
        }
    }
    // 3. If bytes == 0, client disconnected
    else if (bytesReceived == 0)
    {
        std::cout << "Client disconnected: fd " << client->getFd() << std::endl;
        removeClient(client);
    }
    // 4. If bytes < 0, error
    else
    {
        std::cerr << "recv() error on fd " << client->getFd() << ": " << strerror(errno) << std::endl;
        removeClient(client);
    }
}

void EventLoop::removeClient(Client* client)
{
    int fd = client->getFd();
    
    // Remove from vector
    for (std::vector<Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it)
    {
        if (*it == client)
        {
            delete *it;  // This will close the fd in Client destructor
            _clients.erase(it);
            break;
        }
    }
    
    // Update max_fd
    _maxFd = _serverFd;
    for (size_t i = 0; i < _clients.size(); i++)
    {
        if (_clients[i]->getFd() > _maxFd)
            _maxFd = _clients[i]->getFd();
    }
    
    std::cout << "Removed client: fd " << fd << std::endl;
}
