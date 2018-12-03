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
	int i;
	long size;
		
	FILE* romfile = fopen(filename, "r");/* declara ponteiro do tipo FILE, chamado romfile.argumentos na ordem:caminho do arquivo a ser aberto, modo, no caso abre arquivo para leitura.*/

	if (romfile == NULL) {
		puts("Couldn't open file...");/*caso não seja possivel abrir arquivo a menssagem será exibida na saida*/
		
		return 1;
	}

	fseek(romfile, 0, SEEK_END);
	size = ftell(romfile);
	fseek(romfile, 0,SEEK_SET);

	if (size > (CHIP8_CPU_MEMORY_SIZE - 512)) {
		printf("File exceeds in size, max size is 3584 bytes\n");

		return 1;
	}

	fread(&cpu_memory[0x200], 1, size, romfile);/*(primeiro argumento determina o endereço inicial, terceiro argumento:tamanho em bits do arquivo a ser lido,quarto argumento:variavel que foi usada para declarar o ponteiro *romfile*/

	for(i = 512;i < 512 + 280;i++) {/*esse loop serve para que possa ser mostrado na saida,o conteudo de cada endereço de memoria onde houveram informaçoes armazenadas*/
		printf("%d:%.2x\n", i, (unsigned int) cpu_memory[i]);
	}

	fclose(romfile);/*fecha o arquivo especificado no argumento, o arquivo esta no ponteiro *romfile*/	

	return false;
}
