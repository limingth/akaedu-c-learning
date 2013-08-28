#include <stdio.h>
#include <curses.h>

#define LEFTEDGE    10 
#define RIGHTEDGE   30 
#define ROW         10  

int main()
{
//	char *message = "Hello";
	char *message = "\x24\x23\x2b\x2b\x2b";
	char *blank = "     ";
	int dir = 1;
	int pos = LEFTEDGE;

	initscr();
	clear();
	while (1) 
	{   
		move(ROW, pos);
		addstr(message);        /* draw string */
		//      move(LINES-1, COLS-1);
		refresh();              /* show string */
		//sleep(1);
		usleep(1000*100);
		move(ROW, pos);         /* move back */
		addstr(blank);          /* erase string */
		//pos += dir;             /* advance position */
		pos += rand() % 10 - 5;
		if (pos >= RIGHTEDGE)   /* check for bounce */
			dir = -1; 
		if (pos <= LEFTEDGE)
			dir = 1;
	}   
	return 0;
}
