CC=gcc
CFLAGS=-Wall -Wextra -ggdb
SRC=src/main.c src/rom.c src/cpu.c

chip8n64: $(SRC)
	$(CC) $(CFLAGS) $^ -o $@