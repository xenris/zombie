#include "clientstate.hpp"

ClientState::ClientState(int argc, char* args[]) {
    running = true;
    for(int i = 0; i < MAX_NUMBER_OF_PLAYERS; i++)
        players[i] = NULL;
    Player* player = new Player;
    addPlayer(player);

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_WM_SetCaption("Cube", NULL);
    screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_OPENGL);

    SDL_EnableKeyRepeat(0, 0);

    SDL_ShowCursor(SDL_DISABLE);

    glMatrixMode(GL_PROJECTION);
    float r = (float)WIDTH/HEIGHT;
    glOrtho(-r, r, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    glClearColor(0, 0, 0, 1);

    SDL_Flip(screen);
}

ClientState::~ClientState() {
    SDL_Quit();
}

void ClientState::processInput() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            running = false;
        } else if(event.type == SDL_KEYDOWN) {
            if(event.key.keysym.sym == SDLK_w)
                players[0]->forward = true;
            else if(event.key.keysym.sym == SDLK_s)
                players[0]->backward = true;
            else if(event.key.keysym.sym == SDLK_a)
                players[0]->left = true;
            else if(event.key.keysym.sym == SDLK_d)
                players[0]->right = true;
        } else if(event.type == SDL_KEYUP) {
            if(event.key.keysym.sym == SDLK_w)
                players[0]->forward = false;
            else if(event.key.keysym.sym == SDLK_s)
                players[0]->backward = false;
            else if(event.key.keysym.sym == SDLK_a)
                players[0]->left = false;
            else if(event.key.keysym.sym == SDLK_d)
                players[0]->right = false;
            if(event.key.keysym.sym == SDLK_ESCAPE)
                running = false;
        } else if(event.type == SDL_MOUSEMOTION) {
            if(event.motion.x != WIDTH/2)
                players[0]->r += (float)event.motion.xrel/5.0;
        }
    }

    SDL_WarpMouse(WIDTH/2, HEIGHT/2);
}

void ClientState::update() {
    for(int i = 0; i < MAX_NUMBER_OF_PLAYERS; i++)
        if(players[i] != NULL)
            players[i]->update();
}

void ClientState::draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    for(int i = 0; i < MAX_NUMBER_OF_PLAYERS; i++)
        if(players[i] != NULL)
            players[i]->draw();

    SDL_GL_SwapBuffers();
}

int ClientState::addPlayer(Player* player) {
    int i = 0;
    while(players[i] != NULL && i < MAX_NUMBER_OF_PLAYERS)
        i++;
    if(i >= MAX_NUMBER_OF_PLAYERS)
        return -1;
    players[i] = player;
    return 0;
}
