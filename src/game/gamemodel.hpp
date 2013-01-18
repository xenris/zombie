#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

#define MAX_NUMBER_OF_PLAYERS 20

#include <SDL/SDL.h>
#include "player.hpp"

class GameModel {
    public:
        Player* players[MAX_NUMBER_OF_PLAYERS];

        GameModel();
        Player* addPlayer();
        Player* removePlayer();
        void update();
        void draw();
        int serialize(unsigned char* data);
        int numberOfPlayers();
        void removeLastPlayer();
        void removePlayer(Player* player);
};

#endif
