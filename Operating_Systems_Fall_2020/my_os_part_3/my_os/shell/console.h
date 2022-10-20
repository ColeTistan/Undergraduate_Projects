/*
 * Cole Tistan
 * header stores variables needed
 */

#ifndef CONSOLE_H
#define CONSOLE_H

// variables needed 
static char* const VGA_MEM = (char*) 0xb8000;
static const int VGA_HEIGHT = 25;
static const int VGA_WIDTH = 80;
static unsigned int CURR_ADDR;

//function(s) being implemented
void terminalPrint(char* string);
void terminalPrintln(char* string);

#endif
