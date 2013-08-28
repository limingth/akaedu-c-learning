#include <stdio.h>

void bar(void)
{
	printf("haha, You are hacked!\n");
	return;
}

void foo(void)
{
	int i;
	int j;
	printf("<foo> i = %d\n", i);
	printf("<foo> *(&i+1) = 0x%x\n", *(&i+1));
	printf("<foo> *(&i+2) = 0x%x\n", *(&i+2));
	printf("<foo> *(&i+3) = 0x%x\n", *(&i+3));
	printf("<foo> *(&i+4) = 0x%x\n", *(&i+4));
	printf("<foo> *(&i+5) = 0x%x\n", *(&i+5));

	for (j = 0; j < 30; j++)
		printf("<foo> *(&i+%d) = 0x%x (%p)\n", j, *(&i+j), &i+j);
	*(&i + 13) = (int)bar;
	return;
}

int main(void)
{
	int i = 100;
	int * p = &i;

	*(p-12) = 134;
	foo();
	printf("<main> i = %d, finished!\n", i);
	printf("<main> &i = %p, finished!\n", &i);

	return 0;
}
