#include <stdio.h>

void del_space(char *buf)
{
	char *p, *q;
	int flag = 0;

	p = q = buf;

	while (*p)
	{
		if (*p != ' ')
		{
			flag = 1;
			*q++ = *p;
		}
		else
		if (flag == 1 && *p == ' ')
		{
			flag = 0;
			*q++ = *p;
		}
		p++;
	}

	*q = *p;

	return;

	while (*p)
	{
		if (flag == 0 && *p != ' ')
		{
			flag = 1;
			*q++ = *p;
		}
		else
		if (flag == 1 && *p != ' ')
		{
			flag = 1;
			*q++ = *p;
		}
		else
		if (flag == 1 && *p == ' ')
		{
			flag = 0;
			*q++ = *p;
		}
		p++;
	}

	*q = *p;

	return;
}

void parse(char * buf, int * argc, char *argv[])
{
	char * p = buf;
	*argc = 0;
	int flag = 0;

	while (*p)
	{
		if (flag == 0 && (*p != ' ' && *p != '\n'))
		{
			//found a alpha, set header
			argv[*argc] = p;
			(*argc)++;

			flag = 1;
		}
		else
		if (flag == 1 && (*p == ' ' || *p == '\n'))
		{
			// set tailer
			*p = '\0';

			flag = 0;
		}

		p++;
	}
	
	argv[*argc] = NULL;

	return;
}

int a[3];
int * b;

void print1(int b[])
{
	//int b[10];
	//a[0]
	//a[1]
	//a[2]
	b++;
}

void print2(int * a)
{	
#if 0
	*a;
	*(a+1)
	*(a+2)

	*a++;
	*a++;
	*a++;
#endif
}

struct operation
{
	char name[16];
	int (*pf)(int a, int b);
};

typedef struct operation op_t;

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}

int divide(int a, int b)
{
	return a/b;
}


int mul(int a, int b)
{
	return a*b;
}

int power(int a, int b)
{
	int i = 0;
	int ret = 1;

	for (i = 0; i < b; i++)
		ret *= a;

	return ret;
}

op_t ops[] =
{
	{ "add", add },
	{ "sub", sub },
	{ "mul", mul },
	{ "pow", power },
//	{ "power", power },
	{ "div", divide},
//	{ "sin", mysin },
};

int main(void)
//int main(int argc, char *argv[])
//int main(int argc, char **argv)
{
	int i = 0;
	char * p;
	char buf[64];
	int argc = 0;
	char *argv[8];

	printf("demo argc argv\n");

	while (1)
	{

		printf("myshell$$ ");
		fgets(buf, 64, stdin);
		buf[strlen(buf) - 1] = '\0';

		printf("buf = <%s>\n", buf);
		del_space(buf);
		printf("buf = <%s>\n", buf);
		parse(buf, &argc, argv);

		//argc = parse2(buf, argv);

		printf("argc = %d\n", argc);
		for (i = 0; i <= argc; i++)
		{
			printf("argv[%d] = <%s>\n", i, argv[i]);
		}

#if 0
		if (strcmp(argv[0], "add") == 0)
			//printf("%d\n", atoi(argv[1]) + atoi(argv[2]));
			printf("%d\n", add(atoi(argv[1]), atoi(argv[2])));		// 

		if (strcmp(argv[0], "sub") == 0)
//			printf("%d\n", atoi(argv[1]) - atoi(argv[2]));
			printf("%d\n", sub(atoi(argv[1]), atoi(argv[2])));		//

		if (strcmp(argv[0], "pow") == 0)
			printf("%d\n", power(atoi(argv[1]), atoi(argv[2])));		// 2^5 = 32

		if (strcmp(argv[0], "mul") == 0)
			printf("%d\n", mul(atoi(argv[1]), atoi(argv[2])));		// 2^5 = 32
#endif

		for (i = 0; i < sizeof(ops) / sizeof(ops[0]); i++)
		{
			int ret = 0;
			if (strcmp(argv[0], ops[i].name) == 0)
			{
				ret = ops[i].pf(atoi(argv[1]), atoi(argv[2]));
				printf("ret = %d\n", ret);
			}
		}

		for (i = 0; i < argc; i++)
			printf("argv[%d] = <0x%x> at %p\n", i, argv[i], &argv[i]);

	}
	return 0;
#if 0
	printf("argc = %d\n", argc);
	for (i = 0; i < argc; i++)
	{
		printf("argv[%d] = <%s>\n", i, argv[i]);
	}

	for (i = 0; i < argc; i++)
		printf("argv[%d] = <%p>\n", i, argv[i]);

	p = argv[0];
	for (i = 0; i < 20; i++)
		printf("%c (0x%x)\n", *(p+i), *(p+i));


		for (i = 0; i < argc; i++)
			printf("argv[%d] = <0x%x> at %p\n", i, argv[i], &argv[i]);

	}
	return 0;
#endif

#if 0
	printf("argc = %d\n", argc);
	for (i = 0; i < argc; i++)
	{
		printf("argv[%d] = <%s>\n", i, argv[i]);
	}

	for (i = 0; i < argc; i++)
		printf("argv[%d] = <%p>\n", i, argv[i]);

	p = argv[0];
	for (i = 0; i < 20; i++)
		printf("%c (0x%x)\n", *(p+i), *(p+i));

	for (i = 0; i < argc; i++)
		printf("argv[%d] = <0x%x> at %p\n", i, argv[i], &argv[i]);

	return 0;
#endif
}
