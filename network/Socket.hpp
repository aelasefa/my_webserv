#ifndef Socket_HPP
#define Socket_HPP
#include <sys/socket.h>
#include <netinet/in.h>

class Socket
{
    private:
        int _fd;
        int _port;
        struct sockaddr_in _address;
public:
    Socket();
    ~Socket();
    bool create();
    bool bindSocket();
    bool listenSocket();
    int getFd() const;
    void setPort(int port);
};
#endif