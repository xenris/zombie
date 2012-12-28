#include "state.hpp"

State::State() {
    running = true;
    screen = NULL;
    for(int i = 0; i < MAX_NUMBER_OF_PLAYERS; i++)
        players[i] = NULL;
    Player* player = new Player;
    addPlayer(player);
    upKey = false;
    downKey = false;
}

void State::processInput() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            running = false;
        } else if(event.type == SDL_KEYDOWN) {
            if(event.key.keysym.sym == SDLK_UP)
                upKey = true;
            else if(event.key.keysym.sym == SDLK_DOWN)
                downKey = true;
        } else if(event.type == SDL_KEYUP) {
            if(event.key.keysym.sym == SDLK_UP)
                upKey = false;
            else if(event.key.keysym.sym == SDLK_DOWN)
                downKey = false;
            if(event.key.keysym.sym == SDLK_ESCAPE)
                running = false;
        } else if(event.type == SDL_MOUSEMOTION) {
            if(event.motion.x != WIDTH/2)
                players[0]->r += (float)event.motion.xrel/5.0;
        }
    }

    SDL_WarpMouse(WIDTH/2, HEIGHT/2);
}

void State::update() {
    if(downKey) {
        players[0]->x -= cos(players[0]->r*M_PI/180 - M_PI/2)*0.01;
        players[0]->y -= sin(players[0]->r*M_PI/180 + M_PI/2)*0.01;
    }
    if(upKey) {
        players[0]->x += cos(players[0]->r*M_PI/180 - M_PI/2)*0.01;
        players[0]->y += sin(players[0]->r*M_PI/180 + M_PI/2)*0.01;
    }
}

void State::draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    for(int i = 0; i < MAX_NUMBER_OF_PLAYERS; i++)
        if(players[i] != NULL)
            players[i]->draw();

    SDL_GL_SwapBuffers();
}

int State::addPlayer(Player* player) {
    int i = 0;
    while(players[i] != NULL && i < MAX_NUMBER_OF_PLAYERS)
        i++;
    if(i >= MAX_NUMBER_OF_PLAYERS)
        return -1;
    players[i] = player;
    return 0;
}

void State::init(int argc, char* args[]) {
    screen = NULL;
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

void State::uninit() {
    SDL_Quit();
}
