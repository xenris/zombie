#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <GL/gl.h>
#include <cmath>

class Player {
    public:
        bool forward;
        bool backward;
        float x;
        float y;
        float r;

        Player();
        void draw();
        void update();
};

#endif
