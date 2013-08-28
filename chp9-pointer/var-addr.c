#include <stdio.h>

int global = 200;
const int myconst[100] = {300};
static int mystatic = 400;

int main(void)
{
	int local = 100;

	printf("&local = %p\n", &local);
	printf("&global = %p\n", &global);
	printf("&myconst = %p\n", &myconst);
	printf("&mystatic = %p\n", &mystatic);
	printf("const string = %p\n", "hello" );

#include <stdlib.h>
	printf("malloc = %p\n", malloc(2000) );

	printf("main = %p\n", main);

	while (1);

	return 0;
}
