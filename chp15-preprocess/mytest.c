#include <stdio.h>

int main(void)
{
	printf("current line is %d\n", __LINE__);
	printf("current line is %d\n", __LINE__);
	printf("current line is %d\n", __LINE__);
	printf("current line is %d\n", __LINE__);
	printf("current line is %d\n", __LINE__);

	printf("current file name is %s\n", __FILE__);

	return 0;
}
