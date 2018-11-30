#include <stdio.h>
#include <stdlib.h>
#include "rom.h"

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s [rom name]\n", argv[0]);
			return EXIT_FAILURE;
	}

	printf("Hello World, casual\n");
	load_rom(argv[1]);/*chama a função load_rom*/
	

	return 0;
}
