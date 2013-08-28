#include <stdio.h>

int main(void)
{
//	unsigned char c = 0xfc;
	//char c = 0xfc;
	//unsigned char c = 0x80;
	//char c = 0x80;
	unsigned int c = 0x80000000;

	printf("demo shifter!\n");
	
	printf("c = 0x%x\n", c);
	printf("c >> 1 = 0x%x\n", c >> 1);
	printf("1 << 35 = 0x%x\n", 1 << 32);

	return 0;
}
