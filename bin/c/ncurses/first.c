#include <ncurses.h>

int main() {
	initscr(); /* Start the curses standard screen stdscr */
	raw(); /* Terminal driver doesn't interpret any key presses e.g. CTRL-C wou;dn't quit */
	keypad(stdscr, TRUE); /* Enables full keypad support for stdscr */
	printw("Hello World!"); /* Print "Hello World" to stdscr (not actual screen) */
	refresh(); /* Present any changes to stdscr to user */
	getch(); /* Wait for user input */
	endwin(); /* End ncurses */
	return 0;
}
