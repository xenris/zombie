#!/bin/sh
mkdir -p bin
clang++ src/*.cpp -Werror -Wall -lSDL -lSDL_net -lGL -o bin/zombie
