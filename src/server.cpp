#include "server.hpp"

void runServer(int argc, char* args[]) {
    cout << "server running" << endl;

    ServerState serverState;

    while(serverState.running) {
        serverState.processInput();
    }

    cout << "server finished" << endl;
}
