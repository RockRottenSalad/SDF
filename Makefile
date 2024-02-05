
CC=clang

DEBUG_CFLAGS= -g -march=native -Wall -Wextra -Wpedantic
RELEASE_CFLAGS= -O3
LD_FLAGS= -lglfw3 -lm -lX11 -lGL


SRC=$(wildcard ./src/**/*.c ) $(wildcard ./src/*.c)
LIB=./lib
OBJ=./obj
BIN=./bin

debug:
	$(CC) -c $(SRC) -I $(LIB) $(DEBUG_CFLAGS) || (echo "BUILD FAILED")
	mv *.o $(OBJ)

release:
	$(CC) $(SRC) -I $(LIB) $(RELEASE_CFLAGS) || (echo "BUILD FAILED")
	mv *.o $(OBJ)

build:
	$(CC) $(OBJ)/*.o $(LD_FLAGS) -o $(BIN)/main

run:
	$(BIN)/main

gdb:
	gdb $(BIN)/main


