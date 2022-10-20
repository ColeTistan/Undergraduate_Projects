#include "./shell/console.h"

void kernel_early(void) {
	CURR_ADDR = 0;
}

int main(void) {
	terminalPrintln("A");
	terminalPrintln("B");
	terminalPrintln("C");
	terminalPrintln("D");
        terminalPrintln("E");
        terminalPrintln("F");
	terminalPrintln("G");
        terminalPrintln("H");
        terminalPrintln("I");
	terminalPrintln("J");
        terminalPrintln("K");
        terminalPrintln("L");
	terminalPrintln("M");
        terminalPrintln("N");
        terminalPrintln("O");
	terminalPrintln("P");
        terminalPrintln("Q");
        terminalPrintln("R");
	terminalPrintln("S");
        terminalPrintln("T");
        terminalPrintln("U");
	terminalPrintln("V");
        terminalPrintln("W");
        terminalPrintln("X");
	terminalPrintln("Y");
        terminalPrintln("Z");
	return 0;
}
