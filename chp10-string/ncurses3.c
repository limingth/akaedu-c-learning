#include <stdio.h>
#include <curses.h>

int main()
{
	int i;
	char c;

	initscr();
	clear();

	move(10, 20);
	addstr("hello");

	move(10, 20);
	standout();     //反白显示

	while (1)
	{
		c = getch();
		if (c == 'q')
			break;
	}

	getch();
	endwin();

	return 0;


	for (i = 0; i < LINES; i++)
	{   
		move(i, i+1);
		if (i%2 == 1)
			standout();     //反白显示
		addstr("Hello, world");
		if (i%2 == 1)
			standend();     //关闭反白显示
	}   
	refresh();
	getch();
	endwin();
	return 0;
}

