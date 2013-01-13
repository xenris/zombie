#include "server.hpp"

void runServer(int argc, char* args[]) {
    ServerState serverState;

    while(serverState.running) {
        serverState.processInput();
    }
}
