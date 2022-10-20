#include "console.h"

void terminalPrint(char* str_input){
	unsigned int str_index = 0;
	unsigned int mem_index = 2 * CURR_ADDR;

	while(str_input[str_index] != '\0'){
		VGA_MEM[mem_index] = str_input[str_index];
		VGA_MEM[mem_index + 1] = 0x07;
		str_index++;
		mem_index += 2;
		CURR_ADDR++;
	}
}

void terminalPrintln(char* string){
	terminalPrint(string);
	CURR_ADDR += (VGA_WIDTH - (CURR_ADDR % VGA_WIDTH));
}
