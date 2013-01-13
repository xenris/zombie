#include "main.hpp"

int main(int argc, char* args[]) {
    if((argc == 2) && (strcmp(args[1], "server") == 0))
        runServer(argc, args);
    else
        runClient(argc, args);

    return 0;
}
