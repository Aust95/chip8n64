#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>//arquivos de cabeçalho 

extern uint8_t cpu_memory[4096];//da acesso a respectiva variavel, vinda de cpu.c

void load_rom(void)
{
	printf("LOAD ROM: TODO IMPLEMENTATION\n");
	int i;

	FILE* romfile = fopen("BRIX", "r");// declara ponteiro do tipo FILE, chamado romfile.argumentos na ordem:caminho do arquivo a ser aberto, modo, no caso abre arquivo para leitura.

	if (romfile == NULL) {
		puts("Couldn't open file...");//caso não seja possivel abrir arquivo a menssagem será exibida na saida
		
		return;
	}

	fread(&cpu_memory[0x200], 1, 280, romfile);//(primeiro argumento determina o endereço inicial, terceiro argumento:tamanho em bits do arquivo a ser lido,quarto argumento:variavel que foi usada para declarar o ponteiro *romfile)

	for(i = 512;i < 512 + 280;i++) {//esse loop serve para que possa ser mostrado na saida,o conteudo de cada endereço de memoria onde houveram informaçoes armazenadas
		printf("%d:%.2x\n", i, (unsigned int) cpu_memory[i]);
	}

	fclose(romfile);//fecha o arquivo especificado no argumento, o arquivo esta no ponteiro *romfile	
}