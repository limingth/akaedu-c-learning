#include <stdio.h>
#include <string.h>

int main(void)
{
	char a;
	char * str = &a;

	char * p = "AAA";
	printf("0\n");
	p[0] = 'b';
	printf("1\n");

	strcpy(str, "hello12345678");
	printf("%s\n", str);

//	exit(0);
	return 0;
}

int testmain(void)
{
	//mymain();
	printf("finish\n");

	return 0;
}
