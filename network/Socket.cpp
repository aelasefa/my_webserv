#include "Socket.hpp"
#include <unistd.h>
#include <arpa/inet.h>

Socket::Socket() : _fd(-1), _port(0)
{

}

bool Socket::create()
{
    _fd = socket(AF_INET, SOCK_STREAM, 0);
    return _fd != -1;
}

bool Socket::bindSocket()
{
    _address.sin_family = AF_INET;
    _address.sin_addr.s_addr = INADDR_ANY;
    _address.sin_port = htons(_port);
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