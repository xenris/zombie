#ifndef STATE_HPP
#define STATE_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <list>
#include <cmath>
#include "player.hpp"

#define WIDTH 700
#define HEIGHT 500

class State {
    public:
        bool running;
        SDL_Surface* screen;
        std::list<Player> players;
        bool upKey;
        bool downKey;
        bool leftKey;
        bool rightKey;
//        Input input; //TODO

        State();
        void processInput();
        void update();
        void draw();
        void init(int argc, char* args[]);
        void uninit();
};

#endif
