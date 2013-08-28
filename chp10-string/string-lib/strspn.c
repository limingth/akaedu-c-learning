#include <stdio.h>
#include <string.h>


int main(void)
{
	int len;

	len = strspn("abc<hello><hell>", "<>");

	printf("len = %d\n", len);

	return 0;
}
