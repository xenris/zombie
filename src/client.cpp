#include "client.hpp"

void runClient(int argc, char* args[]) {
    ClientState clientState(argc, args);

    while(clientState.running) {
        clientState.processInput();

        clientState.update();

        clientState.draw();
    }
}
