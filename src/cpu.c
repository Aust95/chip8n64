#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
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
	uint8_t op_b2;
	uint8_t op_b1;
	uint16_t opcode;
	
	op_b1 = cpu_memory[registers.program_counter]; /* pega primeiro byte*/
	++registers.program_counter; /* incrementa pc*/
	op_b2 = cpu_memory[registers.program_counter]; /* pega segundo byte*/
	++registers.program_counter; /* incrementa pc*/
	opcode = (op_b2<<8) | (op_b1); /* junta os 2 bytes em uma variável de 2 bytes*/

	printf("OPCODE: $%.4X\n", opcode); /* printa o opcode*/

	if (opcode == 0x00E0) {
		printf("OPCODE = CLS\n");
	} else if (opcode == 0x00EE) {
		printf("OPCODE = RET\n");
	} else  if ((opcode&0xF000) == 0) {
		printf("OPCODE SYS ADDR\n");
	} else  if ((opcode&0xF000) == 0x1000) {
		printf("OPCODE JP ADDR\n");
	} else  if ((opcode&0xF000) == 0x2000) {
		printf("OPCODE  CALL ADDR\n");
	} else {
		printf("UNKNOWN OPCODE = $ %.4x\n", opcode);
	}
}