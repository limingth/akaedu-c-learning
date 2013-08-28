#include <stdio.h>

int main(void)
{
#define N	4
	char buf[N];
//	char buf2[64];

	//gets(buf);
	fgets(buf, N+16, stdin);
	printf("buf = <%s>\n", buf);

	printf("hello");
	scanf("%s", buf);
	printf("printf<%s>\n", buf);

//	while (1);

	return 0;
#if 0
	scanf("%s%s", buf, buf2);
	printf("buf = <%s>\n", buf);
	printf("buf2 = <%s>\n", buf2);
#endif

	return 0;
}
