#include "main.hpp"

int main(int argc, char* args[]) {
    State state(argc, args);

    while(state.running) {
        state.processInput();

        state.update();

        state.draw();
    }

    return 0;
}
