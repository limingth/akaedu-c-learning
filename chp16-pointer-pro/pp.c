#include <stdio.h>

int main(void)
{
	int **ppi;

	ppi = (int **)0x1000;
	ppi = (int **)0x804a010;

	printf("1 finished!\n");

	*ppi = 0x804a050;

	printf("2 finished!\n");

	printf("%x\n", *ppi);
	printf("%x\n", **ppi);

	**ppi = 0x2000;

	printf("3 finished!\n");
	printf("%x\n", **ppi);

	return 0;
}
