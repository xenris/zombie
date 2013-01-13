#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

#define MAX_NUMBER_OF_PLAYERS 20

#include "player.hpp"

class GameModel {
    public:
        Player players[MAX_NUMBER_OF_PLAYERS];

        void update();
        void draw();
};

#endif
