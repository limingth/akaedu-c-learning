#include <stdio.h>

#define OFFSET(member)	 (&(((struct test *)0x0)->member))	

struct test
{
	char a;
	short b;
	int c;
	char d;
} __attribute__ ((packed));

int main(void)
{
	printf("%p\n", OFFSET(a));
	printf("%p\n", OFFSET(b));
	printf("%p\n", OFFSET(c));
	printf("%p\n", OFFSET(d));
	return 0;
}

