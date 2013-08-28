#include <stdio.h>

struct test
{
	int a, b, c, d;
	int t[100];
};

int main(void)
{
//	struct test *p = (int *)100;
//	int *p = 0x8048414;
	int *p = 0x8080000;
	int  a = 0x8048000;

	printf("demo pointer definition\n");
	printf("main = %p\n", main);
	printf("p = 0x%x\n", (int)p);
	printf("*p = 0x%x\n", *p);
	*p = 0x1122;
	printf("*(p+1) = 0x%x\n", *(p+1));

	printf("*a = 0x%x\n", * (int *)  a);
	printf("*0x8048000 = 0x%x\n", *(int *)0x8048000);
	return 0;


	printf("a = 0x%x\n", a);
	printf("a+1 = 0x%x\n", a+1);
	printf("(int *)a+1 = 0x%x\n", (int *)a+1);
	//printf("(int *)a*2 = 0x%x\n", (int *)a*2);
	printf("a*2 = 0x%x\n", a*2);

	printf("p = 0x%x\n", (int)p);
	printf("p+1 = 0x%x\n", (int)p+1);
	printf("p+1 = 0x%x\n", p+1);
	printf("p*2 = 0x%x\n", (int)p*2);
	printf("p*2 = 0x%x\n", (int)p/2);

	return 0;
}
