#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>/*arquivos de cabeçalho*/ 
#include "cpu.h"
#include "rom.h"

/*
 * usando extern informamos pro compilador que existe um array
 * com nome de cpu_memory e tamanho definido em CHIP8_CPU_MEMORY_SIZE
 * e queremos manipulá-lo
 */
extern uint8_t cpu_memory[CHIP8_CPU_MEMORY_SIZE]; 

bool load_rom(const char *filename)
{
	long size;
		
	FILE* romfile = fopen(filename, "r");/* declara ponteiro do tipo FILE, chamado romfile.argumentos na ordem:caminho do arquivo a ser aberto, modo, no caso abre arquivo para leitura.*/

	if (romfile == NULL) {
		puts("Couldn't open file...");/*caso não seja possivel abrir arquivo a menssagem será exibida na saida*/
		
		return false;
	}

	fseek(romfile, 0, SEEK_END);
	size = ftell(romfile);
	fseek(romfile, 0,SEEK_SET);

	if (size > (CHIP8_CPU_MEMORY_SIZE - 512)) {
		printf("File exceeds in size, max size is 3584 bytes\n");

		fclose(romfile);
		
		return false;
	}

	fread(&cpu_memory[0x200], 1, size, romfile);/*(primeiro argumento determina o endereço inicial, terceiro argumento:tamanho em bits do arquivo a ser lido,quarto argumento:variavel que foi usada para declarar o ponteiro *romfile*/

	fclose(romfile);/*fecha o arquivo especificado no argumento, o arquivo esta no ponteiro *romfile*/	

	return true;
}
