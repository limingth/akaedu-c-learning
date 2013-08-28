#include <stdio.h>

int sum(int a, ...)
{

	return 0;
}

int max(int a, int b, int c, ...)
{
	int * p = &a;
	int i = 0;

#if 0
	printf("max %d\n", a);
	printf("max &a %p\n", &a);
	printf("max &b %p\n", &b);
	printf("max &c %p\n", &c);
#endif

	int n = *p;
	int max = 0;

	p++;
	for (i = 0; i < n; i++)
	{
		if (*p > max)
			max = *p;
		printf("*p++ = %d\n", *p++);
	}

	return max;
}

int main(void)
{
	int ret;

	ret = max(2, 3, 5);
	printf("ret = %d\n", ret);

//	ret = sum(2, 3, 5, 0);
	ret = sum(2);
	ret = sum(2, 3);
	ret = sum(2, 3, 5);


	ret = max(3, 33, 5, 9);
	printf("ret = %d\n", ret);

	ret = max(4, 333, 5, 100, 500);
	printf("ret = %d\n", ret);

	return 0;
}
