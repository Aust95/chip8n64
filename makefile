CC=gcc
CFLAGS=-Wall -Wextra -ggdb
SRC=src/main.c src/rom.c

chip8n64: $(SRC)
	$(CC) $(CFLAGS) $^ -o $@