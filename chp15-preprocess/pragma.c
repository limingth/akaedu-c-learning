#include <stdio.h>

#pragma  pack(2)

struct test
{
	int a;
	char c;
	int b;
};

int main(void)
{
	printf("sizeof = %d\n", sizeof(struct test));
	printf("&b  = %p\n", &(((struct test *)0)->b));

	return 0;
}
