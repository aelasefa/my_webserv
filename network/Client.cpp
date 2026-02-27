#include "Client.hpp"
#include <unistd.h>

Client::Client(int fd) : _fd(fd)
{

}

Client::~Client()
{
    if (_fd != -1)
    {
        close(_fd);
    }
}

int Client::getFd() const
{
    return _fd;
}

const std::string& Client::getBuffer() const
{
    return _buffer;
}

void Client::appendToBuffer(const std::string& data)
{
    _buffer += data;
}

void Client::clearBuffer()
{  
      _buffer.clear();
}