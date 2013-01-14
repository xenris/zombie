#ifndef CLIENTSTATE_HPP
#define CLIENTSTATE_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_net.h>
#include <string.h>
#include <iostream>
using namespace std;
#include "gamemodel.hpp"

#define WIDTH 700
#define HEIGHT 500

class ClientState {
    public:
        GameModel gameModel;
        Player* me;
        bool running;
        SDL_Surface* screen;
        UDPsocket socket;
        IPaddress address;
        UDPpacket* packet;

        ClientState(int argc, char* args[]);
        ~ClientState();
        void processInput();
        void update();
        void draw();
        int addPlayer(Player* player);
        void receive();
        void send();
};

#endif
