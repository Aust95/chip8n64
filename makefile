CC=gcc
CFLAGS=-Wall -Wextra -ggdb -std=c90 -pedantic-errors -fsanitize=address
SRC=src/main.c src/rom.c src/cpu.c

chip8n64: $(SRC)
	$(CC) $(CFLAGS) $^ -o $@