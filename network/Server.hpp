#ifndef Server_HPP
#define Server_HPP
#include "Socket.hpp"

class Server
{
private:
    Socket _socket;
    int _port;
public:
    Server(int port);
    ~Server();
    void start();
};
#endif