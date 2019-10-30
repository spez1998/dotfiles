#include <ncurses.h>

int main() {
	int ch;
	initscr(); /* Start curses */
	raw(); /* User input passed straight to curses */
	keypad(stdscr, TRUE); /* Full keypad support */
	noecho(); /* Don't echo() while doing getch */
	printw("Type any character to see it in bold\n");
	ch = getch();
	if(ch == KEY_F(1)) {
		printw("F1 key pressed");
	}
	else {
		printw("You pressed the ");
		addch(ACS_LLCORNER);
		printw(" character.");
	}
	refresh();
	getch();
	endwin();
	return 0;
}	
