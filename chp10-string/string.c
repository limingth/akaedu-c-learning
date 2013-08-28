#include <stdio.h>

char str1[5] = "hello";
char str2[5] = "world";


int main(void)
{
	char str[100] = "";
	char * p;

	printf("str = %s\n", str);

	p = str;
	printf("p = %p\n", p);

	//p = "hello";
	printf("p = %p\n", p);

#include <string.h>
	strcpy(p, "hello");

	printf("str = %s\n", str);
	printf("\n");
	printf("ttt\n");

	printf('\n' + 0x8048170);

	return 0;
}



