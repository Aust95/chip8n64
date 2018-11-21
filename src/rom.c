#include <stdio.h>

void load_rom(void)
{
	printf("LOAD ROM: TODO IMPLEMENTATION\n");

	/*
	 * Primeiro chamamos fopen e passamos os 2 argumentos que a função pede
	 * como esclarecidos na sua documentação.
	 * O primeiro argumento 'filename' é o nome do arquivo que queremos abrir.
	 * O segundo argumento 'modes' é o modo de abertura, passa 'r' que quer dizer read,
	 * queremos apenas ler o arquivo e não escrever nele.
	 */

	FILE* romfile = fopen("rom.ch8", "r");

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

	char buffer[512] = { 0 };

	/*
	 * Agora usamos fgets passando 3 argumentos que ela pede,
	 * como esclarecidos na documentação dela
	 * O primeiro argumento '*s' é um ponteiro para uma area de memória que ele pode usar para escrever
	 * os dados que vai ler do arquivo, passamos o endereço do primeiro byte em buffer
	 *
	 * O segundo argumento 'n' é o tamanho máximo de bytes que ele deve ler do arquivo, usamos o 
	 * operador sizeof e passamos o array buffer pra ele, o sizeof consegue dizer o tamanho em bytes
	 * da variável
	 *
	 * O terceiro argument 'stream' é o ponteiro para FILE aberto por fopen, passamos nosso romfile
	 */
	fgets(&buffer[0], sizeof(buffer), romfile);

	/*
	 * Neste ponto já não precisamos mais do arquivo aberto para leitura,
	 * podemos fechá-lo. a função fclose vai fechar o arquivo e liberar 
	 * qualquer memória que fora alocada por fopen 
	 */

	fclose(romfile);

	/*
	 * Chamamos puts passando o endereço do primeiro byte em buffer
	 * ele vai escrever no terminal até que chegue no primeiro valor 
	 * em buffer que seja 0 que significa final de string
	 * como iniciamos o buffer com zeros anteriormente
	 * ele vai printar no terminal o conteudo do arquivo que lemos 
	 * e parar pq o resto será zeros
	 */
	puts(&buffer[0]);
	
}