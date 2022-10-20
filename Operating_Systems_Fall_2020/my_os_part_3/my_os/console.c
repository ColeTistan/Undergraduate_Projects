#include "console.h"
unsigned int mem_index;

// will move the character if it is out of scope
void shift(){
	mem_index = 2 * CURR_ADDR;
	if(mem_index >= (VGA_WIDTH * VGA_HEIGHT * 2)){
		unsigned int index = 0;
		while(index < VGA_WIDTH * VGA_HEIGHT * 2){
			VGA_MEM[index] = VGA_MEM[index + (VGA_WIDTH * 2)];
			index++;
		}
		mem_index = mem_index - (VGA_WIDTH * 2);
	}	
}

// prints on a single line.
void terminalPrint(char* str_input){
	unsigned int str_index = 0;
	mem_index = 2 * CURR_ADDR;

	while(str_input[str_index] != '\0'){
		VGA_MEM[mem_index] = str_input[str_index];
		VGA_MEM[mem_index + 1] = 0x07;
		str_index++;
		mem_index += 2;
		shift();
		CURR_ADDR++;
	}

}

// prints on a single line and then adds a newline.
void terminalPrintln(char* string){
	terminalPrint(string);
	CURR_ADDR += (VGA_WIDTH - (CURR_ADDR % VGA_WIDTH));
}
