#include <stdio.h>

int global = 100;
extern _start;

int main(void)
{
	printf("hello, akaedu\n");
	printf("&global = %p\n", &global);
	printf("&_start = %p\n", &_start);
	return 511;
}
