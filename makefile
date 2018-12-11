CC=gcc
CFLAGS=-Wall -Wextra -ggdb -std=c90 -pedantic-errors -fsanitize=address -lSDL2 -I./src -I./src/sdl2
SRC=src/sdl2/main.c src/rom.c src/cpu.c

chip8n64: $(SRC)
	$(CC) $(CFLAGS) $^ -o $@