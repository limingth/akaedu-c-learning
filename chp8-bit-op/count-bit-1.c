#include <stdio.h>

int count_bit_1(int num)
{
	int counter = 0;
	int pos = 0;

	for (pos = 0; pos < 32; pos++)
		if (num & (1<<pos))
			counter++;

	return counter;
}

int main(void)
{
	int ret = 0;
	int i = 0;

	printf("demo count bit 1\n");

	for (i = 1; i <= 100; i++)
		ret += count_bit_1(i);

	// result = 3 (0x64 = 0110 0100)
	printf("1-100 has %d bit 1\n", ret);

	return 0;
}
