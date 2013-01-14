#include "clientstate.hpp"

ClientState::ClientState(int argc, char* args[]) {
    if(argc != 2) {
        cout << "need to enter ip address" << endl;
        exit(EXIT_FAILURE);
    }
    running = true;

    me = new Player();

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_WM_SetCaption("Zombie Client", NULL);
    screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_OPENGL);

    SDL_EnableKeyRepeat(0, 0);

    SDL_ShowCursor(SDL_DISABLE);

    glMatrixMode(GL_PROJECTION);
    float r = (float)WIDTH/HEIGHT;
    glOrtho(-r, r, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    glClearColor(0, 0, 0, 1);

    SDL_Flip(screen);

    SDLNet_Init();
    socket = SDLNet_UDP_Open(0);
    SDLNet_ResolveHost(&address, args[1], 9999);

    packet = SDLNet_AllocPacket(512);
}

ClientState::~ClientState() {
    strcpy((char*)packet->data, "quit");
    packet->address.host = address.host;
    packet->address.port = address.port;
    packet->len = strlen((char*)packet->data) + 1;
    SDLNet_UDP_Send(socket, -1, packet);

    SDLNet_FreePacket(packet);
    SDLNet_Quit();
    SDL_Quit();
}

void ClientState::processInput() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            running = false;
        } else if(event.type == SDL_KEYDOWN) {
            if(event.key.keysym.sym == SDLK_w)
                me->forward = true;
            else if(event.key.keysym.sym == SDLK_s)
                me->backward = true;
            else if(event.key.keysym.sym == SDLK_a)
                me->left = true;
            else if(event.key.keysym.sym == SDLK_d)
                me->right = true;
        } else if(event.type == SDL_KEYUP) {
            if(event.key.keysym.sym == SDLK_w)
                me->forward = false;
            else if(event.key.keysym.sym == SDLK_s)
                me->backward = false;
            else if(event.key.keysym.sym == SDLK_a)
                me->left = false;
            else if(event.key.keysym.sym == SDLK_d)
                me->right = false;
            if(event.key.keysym.sym == SDLK_ESCAPE)
                running = false;
        } else if(event.type == SDL_MOUSEMOTION) {
            if(event.motion.x != WIDTH/2)
                me->r += (float)event.motion.xrel/5.0;
        }
    }

    SDL_WarpMouse(WIDTH/2, HEIGHT/2);
}

void ClientState::update() {
    gameModel.update();
}

void ClientState::draw() {
    gameModel.draw();
}

void ClientState::receive() {
    if(SDLNet_UDP_Recv(socket, packet)) {
        int serverNumberOfPlayers = packet->data[0];
        float* data = (float*)&packet->data[1];
        int numberOfPlayers = gameModel.numberOfPlayers();

        while(numberOfPlayers < serverNumberOfPlayers) {
            gameModel.addPlayer();
            numberOfPlayers++;
        }
        while(numberOfPlayers > serverNumberOfPlayers) {
            gameModel.removeLastPlayer();
            numberOfPlayers--;
        }
        for(int i = 0; i < serverNumberOfPlayers; i++) {
            gameModel.players[i]->x = data[i*3+0];
            gameModel.players[i]->y = data[i*3+1];
            gameModel.players[i]->r = data[i*3+2];
        }
    }
}

void ClientState::send() {
    bool* data = (bool*)packet->data;
    data[0] = me->forward;
    data[1] = me->backward;
    data[2] = me->left;
    data[3] = me->right;
    float* dataf = (float*)&data[4];
    *dataf = me->r;
    packet->len = 8;
    packet->address.host = address.host;
	packet->address.port = address.port;

	SDLNet_UDP_Send(socket, -1, packet);
}
