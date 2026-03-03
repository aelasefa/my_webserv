#include "Server.hpp"
#include "../core/EventLoop.hpp"
#include <iostream>
#include <fcntl.h>

Server::Server(int port) : _port(port)
{
    _socket.setPort(port);
}

Server::~Server()
{
}

void Server::start()
{
    // 1. Create socket
    if (!_socket.create())
    {
        std::cerr << "Failed to create socket" << std::endl;
        return;
    }
    
    // 2. Bind
    if (!_socket.bindSocket())
    {
        std::cerr << "Failed to bind socket" << std::endl;
        return;
    }
    
    // 3. Listen
    if (!_socket.listenSocket())
    {
        std::cerr << "Failed to listen on socket" << std::endl;
        return;
    }
    
    // 4. Set listening socket non-blocking
    // F_SETFL: Set file status flags
    // O_NONBLOCK: Non-blocking mode (operations return immediately instead of waiting)
    fcntl(_socket.getFd(), F_SETFL, O_NONBLOCK);
    
    std::cout << "Server listening on port " << _port << std::endl;

    // 5. Create EventLoop
    EventLoop eventLoop(_socket.getFd());
    
    // 6. Run event loop
    eventLoop.run();
}
