#include <stdio.h>

//#define ECHO(s)		do { gets(s); if (*s)   puts(s);  } while (0)
//#define ECHO(s)		(gets(s), if (*s != '\0')  puts(s))

#define ECHO(s)		\
	do \
	{ \
		gets(s); \
				\
		if (*s)  \
			puts(s); \
	} while (0)

int main(void)
{
	char str[100];
	int flag = 1;

	do
	{
	} while (0);

	flag = (1, 2, 3);
	printf("flag = %d\n", flag);
	if (flag == 1)
		ECHO(str);
	else
		printf("NULL doing\n");

	return 0;
}
