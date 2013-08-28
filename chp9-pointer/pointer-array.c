#include <stdio.h>

int main(void)
{
	int a[10];
	int *p;
	int *q;
	int i;

	printf("demo pointer vs array\n");

//	printf("i = %p\n", i);
	printf("a = %p\n", a);
	printf("p = %p\n", p);

	printf("&a = %p\n", &a);
	printf("&p = %p\n", &p);
	printf("&q = %p\n", &q);
	printf("&i = %p\n", &i);

	p = a;

	// same
	printf("a+1 = %p\n", a+1);
	printf("p+1 = %p\n", p+1);

	printf("a[0] = %d\n", a[0]);
	a[0] = 1234;
	printf("p[0] = %d\n", p[0]);

	printf("*(p+1) = %d\n", *(p+1));
	*(p+1) = 1234;
	printf("*(a+1) = %d\n", *(a+1));

	// diff
	//a++;
	p++;

	p = &a[2];
	p = a + 2;

	//a = 0x804a000;
	p = (int *)0x804a000;

	p = &a[1];
	//q = &a[4];
	q = &i;

	printf("q-p = %d\n", q-p);

	if (q > p)
		printf("q > p\n");

	return 0;
}
