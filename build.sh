#!/bin/sh
mkdir -p bin
clang++ src/*.cpp -Werror -Wall -lSDL -lGL -o bin/zombie
