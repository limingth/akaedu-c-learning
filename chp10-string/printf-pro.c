#include <stdio.h>

int main(void)
{
	double pi = 1233.141599;
	char buf[100];

	printf("Hello, world!\n");
	sprintf(buf, "%d %s", 100, "hello");
	puts(buf);

	puts("this is a puts test.");
	printf("%8.8f\n", pi);

	printf("%s", "Hello, world!\n");
	printf("%.5s", "Hello, world!\n");
	printf("\n");
	printf("%5s", "Hello, world!\n");
	printf("%5.2s", "Hello, world!\n");
	printf("\n");
	printf("%-5.2s", "Hello, world!\n");

	printf("\n");
	printf("%-16.6s %-3d %s\n", "liangchaoshuai", 100, "henan");
	printf("%-16.6s %-3d %s\n", "qiyunsheng", 25, "heilongjiang");
	printf("%-16.6s %-3d\t%s\n", "dingmin", 21, "henan");

	return 0;
}
