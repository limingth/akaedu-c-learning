#include <stdio.h>

typedef struct {
	unsigned int one:1;
	unsigned int :3;
	unsigned int three:10;
	unsigned int four:5;
	unsigned int :32;
	unsigned int :32;
	unsigned int :32;
	unsigned int :32;
	unsigned int :32;
	unsigned int :32;
	unsigned int :32;
	unsigned int six:32;
} demo_type;

int main(void)
{
//	demo_type s = { 1, 5, 513, 17, 129, 0x81 };
//	demo_type s = { 1, 0x5, 0x321, 0x1a, 0x81, 0x7 };
	demo_type s = { 1, 0x234, 0x1F, 0x7 };
	printf("sizeof demo_type = %u\n", sizeof(demo_type));
	printf("values: s=0x%x\n", *(int *)&s);
//	printf("values: s=%u,%u,%u,%u,%u,%u\n",
//			s.one, s.two, s.three, s.four, s.five, s.six);

	return 0;
}
