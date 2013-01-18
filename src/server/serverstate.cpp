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
        Client* client = clientHandler.getClient(packet->address.host, packet->address.port);
        if(client == NULL) {
            client = clientHandler.addClient(packet->address.host, packet->address.port, gameModel.addPlayer());
            if(client == NULL)
                return;
        }
        bool* data = (bool*)packet->data;
        client->player->forward = data[0];
        client->player->backward = data[1];
        client->player->left = data[2];
        client->player->right = data[3];
        float* dataf = (float*)&packet->data[4];
        client->player->r = *dataf;
    }
}

void ServerState::send() {
    packet->len = gameModel.serialize(packet->data);;
    for(int i = 0; i < MAX_NUMBER_OF_CLIENTS; i++) {
        if(clientHandler.clients[i] != NULL) {
            packet->address.host = clientHandler.clients[i]->address;
            packet->address.port = clientHandler.clients[i]->port;
	        SDLNet_UDP_Send(socket, -1, packet);
        }
    }
}

void ServerState::update() {
    gameModel.update();
}

void ServerState::draw() {
    gameModel.draw();
}
