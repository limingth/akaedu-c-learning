#include <stdio.h>

void put_hex(int hex)
{
	char hexs[16] = "0123456789abcdef";

	// hex: 0x00 - 0x0F
	//      0,1,2,... a, b, .. f
	putchar(hexs[hex]);

	return;
}

void put_char_hex(char byte)
{
	put_hex((byte >> 4) & 0x0F);
	put_hex((byte >> 0) & 0x0F);

	return;
}

void put_int_hex(int num)
{
	putchar('0');
	putchar('x');

	put_char_hex((num >> 24) & 0xFF);
	put_char_hex((num >> 16) & 0xFF);
	put_char_hex((num >> 8) & 0xFF);
	put_char_hex((num >> 0) & 0xFF);

	putchar('\n');

	return;
}

int main(void)
{
//	printf("%d\n", 0110);
	// 0x64 -> 0 x 6 4
	put_int_hex(100);

	put_int_hex(0x11225566);
	put_int_hex(0x56789876);

	return;
}
