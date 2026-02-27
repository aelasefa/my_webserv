#include "Server.hpp"
#include <iostream>
#include <unistd.h>

Server::Server(int port) : _port(port)
{
    _socket.setPort(port);
}

Server::~Server()
{
}

void Server::start()
{
    if (!_socket.create())
    {
        std::cerr << "Failed to create socket" << std::endl;
        return;
    }
    if (!_socket.bindSocket())
    {
        std::cerr << "Failed to bind socket" << std::endl;
        return;
    }
    if (!_socket.listenSocket())
    {
        std::cerr << "Failed to listen on socket" << std::endl;
        return;
    }
    std::cout << "Server listening on port " << _port << std::endl;

    while (true)
    {
        int client_fd = accept(_socket.getFd(), NULL, NULL);
        if (client_fd >= 0)
        {
            std::cout << "Client connected" << std::endl;
            close(client_fd);
        }
    }
}
