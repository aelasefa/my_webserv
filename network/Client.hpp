#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

class Client
{
private:
    int _fd;
    std::string _buffer;

public:
    Client(int fd);
    ~Client();

    int getFd() const;

    const std::string& getBuffer() const;
    void appendToBuffer(const std::string& data);
    void clearBuffer();
};

#endif