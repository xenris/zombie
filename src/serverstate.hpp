#ifndef SERVERSTATE_HPP
#define SERVERSTATE_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#define WIDTH 700
#define HEIGHT 500

class ServerState {
    public:
        bool running;
        SDL_Surface* screen;

        ServerState();
        ~ServerState();
        void processInput();
};

#endif
