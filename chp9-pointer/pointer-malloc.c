#include <stdio.h>
#include <stdlib.h>

#define N 0x10000000
	char a[N];
int main(void)
{
	char *p = NULL;
	int *p2;
	int size;
	int i;

	a[N-4] = 'P';
	printf("a = %p\n", a);
	printf("a[N-4] = %c\n", a[N-4]);
	while (1);
	return 0;

	printf("demo malloc\n");
	printf("p = %p\n", p);
	//p = malloc(0x47100000);
	p = alloca(0x9f0000);
	printf("p = %p\n", p);
	while (1);
	return 0;

	printf("p = %p\n", p);
	p = malloc(4);
	printf("p = %p\n", p);
	p2 = p - 8;
	printf("p2 = %p\n", p2);
	printf("*p2 = 0x%x\n", *p2);

	for (i = 0; i < 16; i++)
		printf("%p: 0x%x\n", p2+i, *(p2+i));

	//free(p);
	getchar();

	for (i = 0; i < 16; i++)
		printf("%p: 0x%x\n", p2+i, *(p2+i));
	getchar();

	p = malloc(16);
	printf("p = %p\n", p);

	for (i = 0; i < 16; i++)
		printf("%p: 0x%x\n", p2+i, *(p2+i));

	for (i = 0; i < 16; i++)
		printf("%p: 0x%x\n", p2+i, *(p2+i));
	p = malloc(4);
	printf("p = %p\n", p);

	printf("*p = %d\n", *p);
	p++;
	printf("*p = %d\n", *p);

	return 0;

	while(1)
	{
		scanf("%x", &size);
		p[size] = 123;
		printf("p[] = %d\n", p[size]);
	}

	while(1);

	return 0;
}
