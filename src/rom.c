#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

extern uint8_t cpu_memory[4096];

void load_rom(void)
{


	printf("LOAD ROM: TODO IMPLEMENTATION\n");
	int i;

	/*
	 * Primeiro chamamos fopen e passamos os 2 argumentos que a função pede
	 * como esclarecidos na sua documentação.
	 * O primeiro argumento 'filename' é o nome do arquivo que queremos abrir.
	 * O segundo argumento 'modes' é o modo de abertura, passa 'r' que quer dizer read,
	 * queremos apenas ler o arquivo e não escrever nele.
	 */

	FILE* romfile = fopen("BRIX", "r");

	/*
	 * A função fopen nos retornou um ponteiro para um tipo FILE
	 * se este ponteiro for igual a NULL alguma coisa errada aconteceu
	 */
	if (romfile == NULL) {
		puts("Couldn't open file...");
		return;
	}
	/*
	 * Criamos um buffer de 512 bytes na area STACK da memória e inicializamos com 0.
	 * será nosso buffer para guardar temporariamente os dados do arquivo
	 */

	fread(&cpu_memory[0x200], 1, 280, romfile);

	/*
	 * Neste ponto já não precisamos mais do arquivo aberto para leitura,
	 * podemos fechá-lo. a função fclose vai fechar o arquivo e liberar 
	 * qualquer memória que fora alocada por fopen 
	 */
	for(i = 512;i < 512 + 280;i++) {
    printf("%d:%.2x\n", i, (unsigned int) cpu_memory[i]);
	}

	fclose(romfile);

	/*
	 * Chamamos puts passando o endereço do primeiro byte em buffer
	 * ele vai escrever no terminal até que chegue no primeiro valor 
	 * em buffer que seja 0 que significa final de string
	 * como iniciamos o buffer com zeros anteriormente
	 * ele vai printar no terminal o conteudo do arquivo que lemos 
	 * e parar pq o resto será zeros
	 */
	
}