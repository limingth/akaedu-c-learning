#include <stdio.h>

#define DEBUG(x)	printf(#x " is int, value is " #x " = %d  2*" #x " %d\n", x, 2*(x))
#define DEBUGD(x)	printf(#x " is int, value is " #x " = %d  2*" #x " %d\n", x, 2*(x))
#define DEBUGF(x)	printf(#x " is int, value is " #x " = %f  2*" #x " %f\n", x, 2*(x))

#define MYCAT(x, y)		x##y

/*
int int_add(int x, int y)
{
	return x + y;
}

float float_add(float x, float y)
{
	return x + y;
}

double double_add(double x, double y)
{
	return x + y;
}
*/

#define FUNC_TEMPLATE(type)		\
type type##_add(type x, type y)	\
{ \
	return x + y;	\
}

FUNC_TEMPLATE(int)
FUNC_TEMPLATE(float)
FUNC_TEMPLATE(double)


int main(void)
{
//#define MAX 100
#undef MAX
#define MAX 1000
#undef MAX
#define MAX 1000
	int array[MAX];

	int a = 100;
	int b = 200;
	int c = 300;
	int MYCAT(i, 1) = 100;
	int MYCAT(i, 2) = 200;

	int MYCAT(int, var) = 100;
	long MYCAT(long, var) = 10000;

	DEBUGF(float_add(1.1, 2.2));
	DEBUGD(int_add(1, 22));

	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);

	DEBUG(a);
	DEBUG(b);
	DEBUG(c);
	DEBUG((a+b));

	return 0;
}

