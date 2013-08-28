#include <stdio.h>

int main(void)
{
//	unsigned char c = 0xfc;
	//char c = 0xfc;
	unsigned char c = ~0x0;
	unsigned int i = ~c;

	printf("demo promotion!\n");
	
	if ((0 & 1) == 0)
		printf("c = %d\n", c);

	//for (c = 0x0; c < 0xff; c++)
		printf("c = 0x%x, i = 0x%x\n", c, i);

	return 0;
}
