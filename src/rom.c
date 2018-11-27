#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

extern uint8_t cpu_memory[4096];

void load_rom(void)
{
	printf("LOAD ROM: TODO IMPLEMENTATION\n");
	int i;

	FILE* romfile = fopen("BRIX", "r");

	if (romfile == NULL) {
		puts("Couldn't open file...");
		
		return;
	}

	fread(&cpu_memory[0x200], 1, 280, romfile);

	for(i = 512;i < 512 + 280;i++) {
		printf("%d:%.2x\n", i, (unsigned int) cpu_memory[i]);
	}

	fclose(romfile);	
}