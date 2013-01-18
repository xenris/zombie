#ifndef SERVERSTATE_HPP
#define SERVERSTATE_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_net.h>
#include <string.h>
#include "../game/gamemodel.hpp"
#include "clienthandler.hpp"

#define WIDTH 700
#define HEIGHT 500

class ServerState {
    public:
        GameModel gameModel;
        ClientHandler clientHandler;
        bool running;
        SDL_Surface* screen;
        UDPsocket socket;
        UDPpacket* packet;

        ServerState();
        ~ServerState();
        void processInput();
        void receive();
        void send();
        void update();
        void draw();
};

#endif
