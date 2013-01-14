#include "gamemodel.hpp"

GameModel::GameModel() {
    for(int i = 0; i < MAX_NUMBER_OF_PLAYERS; i++)
        players[i] = NULL;
}

Player* GameModel::addPlayer() {
    int i = 0;
    while((players[i] != NULL) && (i < MAX_NUMBER_OF_PLAYERS)) i++;
    if(i < MAX_NUMBER_OF_PLAYERS) {
        players[i] = new Player();
        return players[i];
    }

    return NULL;
}

void GameModel::removeLastPlayer() {
    for(int i = MAX_NUMBER_OF_PLAYERS-1; i >= 0; i--) {
        if(players[i] != NULL) {
            delete(players[i]);
            players[i] = NULL;
            return;
        }
    }
}

void GameModel::removePlayer(Player* player) {
    for(int i = 0; i < MAX_NUMBER_OF_PLAYERS; i++) {
        if(players[i] == player) {
            delete(players[i]);
            players[i] = NULL;
            return;
            //TODO shift any higher players down so that the array doesn't have gaps.
        }
    }
}

void GameModel::update() {
    for(int i = 0; i < MAX_NUMBER_OF_PLAYERS; i++)
        if(players[i] != NULL)
            players[i]->update();
}

void GameModel::draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    for(int i = 0; i < MAX_NUMBER_OF_PLAYERS; i++)
        if(players[i] != NULL)
            players[i]->draw();

    SDL_GL_SwapBuffers();
}

int GameModel::serialize(unsigned char* data) {
    data[0] = 0;
    float* dataf = (float*)&data[1];
    for(int i = 0; i < MAX_NUMBER_OF_PLAYERS; i++) {
        if(players[i] != NULL) {
            data[0]++;
            dataf[i*3+0] = players[i]->x;
            dataf[i*3+1] = players[i]->y;
            dataf[i*3+2] = players[i]->r;
        }
    }

    return data[0]*3*4 + 1;
}

int GameModel::numberOfPlayers() {
    int result = 0;
    for(int i = 0; i < MAX_NUMBER_OF_PLAYERS; i++)
        if(players[i] != NULL)
            result++;

    return result;
}
