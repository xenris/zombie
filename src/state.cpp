#include "state.hpp"

State::State() {
    running = true;
    screen = NULL;
    Player player;
    players.push_back(player);
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
            else if(event.key.keysym.sym == SDLK_LEFT)
                leftKey = true;
            else if(event.key.keysym.sym == SDLK_RIGHT)
                rightKey = true;
        } else if(event.type == SDL_KEYUP) {
            if(event.key.keysym.sym == SDLK_UP)
                upKey = false;
            else if(event.key.keysym.sym == SDLK_DOWN)
                downKey = false;
            else if(event.key.keysym.sym == SDLK_LEFT)
                leftKey = false;
            else if(event.key.keysym.sym == SDLK_RIGHT)
                rightKey = false;
        }
    }
}

void State::update() {
    if(downKey) {
        players.begin()->x -= cos(players.begin()->r*M_PI/180 - M_PI/2)*0.01;
        players.begin()->y -= sin(players.begin()->r*M_PI/180 + M_PI/2)*0.01;
    }
    if(upKey) {
        players.begin()->x += cos(players.begin()->r*M_PI/180 - M_PI/2)*0.01;
        players.begin()->y += sin(players.begin()->r*M_PI/180 + M_PI/2)*0.01;
    }
    if(leftKey)
        (players.begin())->r -= 4;
    if(rightKey)
        (players.begin())->r += 4;
}

void State::draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    std::list<Player>::iterator i;
    for(i = players.begin(); i != players.end(); ++i) {
        i->draw();
    }

    SDL_GL_SwapBuffers();
}

void State::init(int argc, char* args[]) {
    screen = NULL;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_WM_SetCaption("Cube", NULL);
    screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_OPENGL);

    SDL_EnableKeyRepeat(0, 0);

    glMatrixMode(GL_PROJECTION);
    glFrustum(-1, 1, -1, 1, -1, 1);
//    gluPerspective(90, (float)WIDTH/HEIGHT, 1, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0, 0, 0, 1);

    SDL_Flip(screen);
}

void State::uninit() {
    SDL_Quit();
}
