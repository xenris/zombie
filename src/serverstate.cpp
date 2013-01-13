#include "serverstate.hpp"

ServerState::ServerState() {
    running = true;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_WM_SetCaption("Zombie Server", NULL);
    screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_OPENGL);

    SDL_EnableKeyRepeat(0, 0);

    glMatrixMode(GL_PROJECTION);
    float r = (float)WIDTH/HEIGHT;
    glOrtho(-r, r, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    glClearColor(0, 0, 0, 1);

    SDL_Flip(screen);
}

ServerState::~ServerState() {
    SDL_Quit();
}

void ServerState::processInput() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT)
            running = false;
    }
}
