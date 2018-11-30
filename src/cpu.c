#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "cpu.h"



/* Declara layout de memória do tipo struct registers */
struct registers {
	/*
	 *  Chip-8 has 16 general purpose 8-bit registers,
	 *  usually referred to as Vx, where x is a hexadecimal digit (0 through F).
	 *  There is also a 16-bit register called I. This register is generally used to store memory addresses,
	 *  so only the lowest (rightmost) 12 bits are usually used.
	 */

    uint8_t v[16];
    uint16_t i;
    uint8_t delay_timer;
    uint8_t sound_timer;
    uint16_t program_counter;
    uint8_t stack_pointer;
};


/*
 * criamos um array de uint8_t (unsigned int de 8 bits / 1 byte)
 * com tamanho definido em CHIP8_CPU_MEMORY_SIZE.
 * Não declaramos como static, pois queremos manipulá-lo de outros módulos
 */
uint8_t cpu_memory[CHIP8_CPU_MEMORY_SIZE];


/* 
 * criamos um array de uint16_t (unsigned int de 16 bits / 2 bytes) com tamanho 16 = total de 32 bytes
 * declaramos como static pois será manipulado apenas neste módulo
 */
static uint16_t stack[16];


/* cria variável registers do tipo struct registers, como static pois será manipulada apenas neste módulo */
static struct registers registers;


/* DEFINE função cpu_reset */
void cpu_reset()
{
	/* Chama a função memset
	 * argumento 1: endereço da variável registers
	 * argumento 2: valor para preencher os bytes
	 * argumento 3: tamanho em bytes do tipo struct registers
	 */
	memset(&registers, 0, sizeof(struct registers));

	/* seta o valor 0x200 (512 em decimal) para o membro program_counter da variável registers */
	registers.program_counter = 0x200;
}

/* DEFINE função cpu_step */
void cpu_step()
{

}