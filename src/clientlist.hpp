#ifndef CLIENTLIST_HPP
#define CLIENTLIST_HPP

#include <stddef.h>
#include "player.hpp"

#define MAX_NUMBER_OF_CLIENTS 20

class Client;

class ClientList {
    public:
        Client* clients[MAX_NUMBER_OF_CLIENTS];

        ClientList();
        Client* addClient(int address, int port, Player* player);
        void removeClient(int address, int port);
        Client* getClient(int address, int port);
};

class Client {
    public:
        int address;
        int port;
        Player* player;

        Client(int address, int port, Player* player);
};

#endif
