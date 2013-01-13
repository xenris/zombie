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

    SDLNet_Init();
    socket = SDLNet_UDP_Open(9999);
    packet = SDLNet_AllocPacket(512);
}

ServerState::~ServerState() {
    SDLNet_FreePacket(packet);
    SDLNet_Quit();
    SDL_Quit();
}

void ServerState::processInput() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT)
            running = false;
    }
}

void ServerState::receive() {
    if(SDLNet_UDP_Recv(socket, packet)) {
        printf("UDP Packet incoming\n");
        printf("\tChan:    %d\n", packet->channel);
        printf("\tData:    %s\n", (char*)packet->data);
        printf("\tLen:     %d\n", packet->len);
        printf("\tMaxlen:  %d\n", packet->maxlen);
        printf("\tStatus:  %d\n", packet->status);
        printf("\tAddress: %x %x\n", packet->address.host, packet->address.port);
    }
}

void ServerState::send() {
	SDLNet_UDP_Send(socket, -1, packet);
}

void ServerState::update() {
    gameModel.update();
}

void ServerState::draw() {
    gameModel.draw();
}
