#include <stdio.h>

// int (*a)[10];
typedef int T[10];
//typedef int[10]  T;
T * a;

typedef int (*ADD)(int a, int b);
//typedef int (*)(int a, int b)   ADD;
ADD pf;
// int (*pf)(int a, int b);

// int * a[10];
typedef int *  T2;
T2 a2[10];

int main(void)
{
	int * p;
	int tmp;
	int b[5][10];
	int c[10];


	c[1100] = 189;
	printf("c[1100] = %d\n", c[1100]);

	p = 0;
	printf("p = %p\n", p);
	printf("p+1 = %p\n", p+1);

//	tmp = p[0];

	a = 0;
	printf("a = %p\n", a);
	printf("a+1 = %p\n", a+1);

	printf("b = %p\n", b);
	printf("b[0] = %p\n", b[0]);
	printf("b[1] = %p\n", b[1]);
	printf("b[2] = %p\n", b[2]);
	printf("b[7] = %p\n", b[7]);
	printf("b[8] = %p\n", b[8]);

	tmp = a[10];
	printf("tmp = %p\n", tmp);

	return 0;
}
