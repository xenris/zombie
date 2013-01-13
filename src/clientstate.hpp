#ifndef CLIENTSTATE_HPP
#define CLIENTSTATE_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include "player.hpp"

#define WIDTH 700
#define HEIGHT 500
#define MAX_NUMBER_OF_PLAYERS 20

class ClientState {
    public:
        bool running;
        SDL_Surface* screen;
        Player* players[MAX_NUMBER_OF_PLAYERS];

        ClientState(int argc, char* args[]);
        ~ClientState();
        void processInput();
        void update();
        void draw();
        int addPlayer(Player* player);
};

#endif
