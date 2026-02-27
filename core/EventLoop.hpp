#ifndef EVENTLOOP_HPP
#define EVENTLOOP_HPP  
#include <vector>
#include <sys/select.h>
#include "../network/Client.hpp"

class EventLoop
{
private:
    int _serverFd;
    std::vector<Client*> _clients;
    fd_set _readFds;
    int _maxFd;
public:
    EventLoop(int serverFd);
    void run();
private:
    void handleNewConnection();
    void handleClientData(Client* client);
    void removeClient(Client* client);
};
#endif