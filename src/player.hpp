#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <GL/gl.h>

class Player {
    public:
        float x;
        float y;
        float r;

        Player();
        void draw();
};

#endif
