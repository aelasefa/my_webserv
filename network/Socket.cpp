#include "Socket.hpp"
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>

Socket::Socket() : _fd(-1), _port(0)
{

}

bool Socket::create()
{
    // AF_INET: IPv4 address family
    // SOCK_STREAM: TCP connection-oriented socket
    _fd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (_fd == -1)
        return false;
    
    int reuse = 1;
    if (setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0)
    {
        close(_fd);
        _fd = -1;
        return false;
    }
    
    return true;
}

bool Socket::bindSocket()
{
    _address.sin_family = AF_INET;           // IPv4 address family
    _address.sin_addr.s_addr = INADDR_ANY;   // Accept connections on any interface
    _address.sin_port = htons(_port);        // htons: Convert port to network byte order
    return bind(_fd, (struct sockaddr *)&_address, sizeof(_address)) != -1;
}

bool Socket::listenSocket()
{
    return listen(_fd, 5) != -1;
}
int Socket::getFd() const
{
    return _fd;
}

Socket::~Socket()
{
    if (_fd != -1)
    {
        close(_fd);
    }
}

void Socket::setPort(int port)
{
    _port = port;
}