#include "clientlist.hpp"

ClientList::ClientList() {
    for(int i = 0; i < MAX_NUMBER_OF_CLIENTS; i++)
        clients[i] = NULL;
}

Client* ClientList::addClient(int address, int port, Player* player) {
    int i = 0;
    while((clients[i] != NULL) && (i < MAX_NUMBER_OF_CLIENTS)) i++;
    if(i < MAX_NUMBER_OF_CLIENTS) {
        clients[i] = new Client(address, port, player);
        return clients[i];
    }

    return NULL;
}

void ClientList::removeClient(int address, int port) {
    for(int i = 0; i < MAX_NUMBER_OF_CLIENTS; i++) {
        if(clients[i] != NULL) {
            if((clients[i]->address == address) && (clients[i]->port == port)) {
                delete(clients[i]);
                clients[i] = NULL;
            }
        }
    }
}

Client* ClientList::getClient(int address, int port) {
    for(int i = 0; i < MAX_NUMBER_OF_CLIENTS; i++)
        if(clients[i] != NULL)
            if((clients[i]->address == address) && (clients[i]->port == port))
                return clients[i];

    return NULL;
}

Client::Client(int address, int port, Player* player) {
    this->address = address;
    this->port = port;
    this->player = player;
}
