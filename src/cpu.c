#include <stdlib.h>
#include <stdint.h>

static uint16_t stack[16];
uint8_t cpu_memory[1024 * 4]; //uint_t = unsigned int of 8 bits
/*
Chip-8 has 16 general purpose 8-bit registers, usually referred to as Vx, where x is a hexadecimal digit (0 through F). There is also a 16-bit register called I. This register is generally used to store memory addresses, so only the lowest (rightmost) 12 bits are usually used.
*/
struct registers {
    uint8_t v[16];
    uint16_t i;
    uint8_t delay_timer;
    uint8_t sound_timer;
    uint16_t program_counter;
    uint8_t stack_pointer;
};

struct registers registers;

void cpu_reset(){
	memset(&registers, 0, sizeof(struct registers));
	register.pc = 0x200;
}

void cpu_step(){

}