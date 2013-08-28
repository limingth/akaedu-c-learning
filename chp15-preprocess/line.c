#include <stdio.h>

#define DEBUG(x)	printf("<%s>@(%s) line:%d " #x " = %d\n", __func__, __FILE__, __LINE__, x)

//#define MAX		0
#if MAX
//#if defined(MAX)

int b;
int b;
int b;
int b;

/*
int a;
*/

int c;
int b;
int b;
int b;

#endif

void mytestf(void)
{
	int i = 100;

	DEBUG(i);

	printf("current func is %s\n", __func__);
	printf("current func is %s\n", __FUNCTION__);

	return;
}

int main(void)
{
	int i = 100;

	DEBUG(i);

	printf("current line is %d\n", __LINE__);
	printf("current line is %d\n", __LINE__);
	printf("current line is %d\n", __LINE__);
	printf("current line is %d\n", __LINE__);
	printf("current line is %d\n", __LINE__);

	printf("current file name is %s\n", __FILE__);
	printf("current time is %s\n", __TIME__);
	printf("current time is %s\n", __DATE__);

	printf("current stdc is %d\n", __STDC__);
	printf("current func is %s\n", __func__);

	mytestf();
	return 0;
}
