#include "server.hpp"

void runServer(int argc, char* args[]) {
    ServerState serverState;

    while(serverState.running) {
        serverState.processInput();

        serverState.receive();

        serverState.update();

        serverState.send();

        serverState.draw();
    }
}
