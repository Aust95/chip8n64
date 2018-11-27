#include <stdlib.h>
#include <stdint.h>
#include <string.h>

static uint16_t stack[16];//uint16_t = unsigned int de 16 bits
uint8_t cpu_memory[1024 * 4]; //uint8_t = unsigned int de 8 bits
/*
Chip-8 has 16 general purpose 8-bit registers, usually referred to as Vx, where x is a hexadecimal digit (0 through F). There is also a 16-bit register called I. This register is generally used to store memory addresses, so only the lowest (rightmost) 12 bits are usually used.
*/
static struct registers {//variaveis que são parte dos registradores estão nesse escopo
    uint8_t v[16];
    uint16_t i;
    uint8_t delay_timer;
    uint8_t sound_timer;
    uint16_t program_counter;
    uint8_t stack_pointer;
};

struct registers registers;

void cpu_reset()// declara a função cpu_reset
{
	memset(&registers, 0, sizeof(struct registers));//chama a função memset (endereço de registers, conteudo do segundo argumento irá preencher o endereço de memoria que foi apontado no primeiro argumento,retorna o numero de bits de registers)  
	registers.program_counter = 0x200;
}

void cpu_step()// declara a função cpu_step
{

}