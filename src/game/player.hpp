#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <GL/gl.h>
#include <cmath>

class Player {
    public:
        bool forward;
        bool backward;
        bool left;
        bool right;
        float x;
        float y;
        float r;

        Player();
        void draw();
        void update();
};

#endif
