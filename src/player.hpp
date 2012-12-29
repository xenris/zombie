#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <GL/gl.h>
#include <cmath>

enum MOVEMENT {
    NONE,
    WALKING_FORWARD,
    WALKING_BACKWARD
};

class Player {
    public:
        MOVEMENT movement;
        float x;
        float y;
        float r;

        Player();
        void draw();
        void update();
};

#endif
