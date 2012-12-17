#include "main.hpp"

int main(int argc, char* args[]) {
    State state;
    state.init(argc, args);

    while(state.running) {
        state.processInput();

        state.update();

        state.draw();
    }

    state.uninit();

    return 0;
}
