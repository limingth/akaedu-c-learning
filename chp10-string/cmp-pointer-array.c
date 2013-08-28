#include <stdio.h>

//char * s1 = "hello";
char s1[] = "hello";
//char s2[] = "hello";
int a[] = {1,2};

struct stu
{
	int a;
	int b[100];
	char c[100];
} A, b;

void func(struct stu a)
{
	return a;
}

int main(void)
{
//	char * s2 = "HELLO";
	char s2[32+0x10000] = "HELLOalksdjlfkjasdkjflasjdfkjasdkfal;sdjflkajsdlkfjlkasdjflkjasdlkjflkajsdlkfjaslkjdflkajsdlkfjlaksjdflkjasdljflasjdfj";

	func(b);

	A = b;
	//printf("strlen(s2) = %d\n", strlen(s2));
//	s2[0] = 'A';
//	s2 = 0x1234;
//	s2 = 0x12345678;
#if 0
	char * p;

	s1[0] = 'H';
	s1[4] = 'I';

	p = s1 + 8;
#endif


	printf("demo cmp char * vs char s[] \n");

	return 0;
}
