#include "client.hpp"

void runClient(int argc, char* args[]) {
    ClientState clientState(argc, args);

    while(clientState.running) {
        clientState.processInput();

        clientState.send();

        clientState.receive();

//        clientState.update();

        clientState.draw();
    }
}
