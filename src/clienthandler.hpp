#ifndef CLIENTHANDLER_HPP
#define CLIENTHANDLER_HPP

#include <stddef.h>
#include "player.hpp"

#define MAX_NUMBER_OF_CLIENTS 20

class Client;

class ClientHandler {
    public:
        Client* clients[MAX_NUMBER_OF_CLIENTS];

        ClientHandler();
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
