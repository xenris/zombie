#ifndef SERVERSTATE_HPP
#define SERVERSTATE_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_net.h>
#include <string.h>

#define WIDTH 700
#define HEIGHT 500

class ServerState {
    public:
        bool running;
        SDL_Surface* screen;
        UDPsocket socket;
        UDPpacket* packet;

        ServerState();
        ~ServerState();
        void processInput();
        void receive();
        void send();
};

#endif
