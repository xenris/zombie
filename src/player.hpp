#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <GL/gl.h>

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
};

#endif
