#include "client.hpp"

void runClient(int argc, char* args[]) {
    State state(argc, args);

    while(state.running) {
        state.processInput();

        state.update();

        state.draw();
    }
}
