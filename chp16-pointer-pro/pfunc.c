#include <stdio.h>

void say_hello(char *str)
{
	printf("hello, %s\n", str);

	return;
}

typedef  void (*FP)(char *);
typedef  void FF(char *);
// wrong!!! typedef  void (*)(char *)	FP2;

#if 0
FP  table[] = { say_hello1, say_hello2 };

tbl[0]("abc");
tbl[1]("123");

void (*f[2])(char *);
f[0]();
#endif

int main(void)
{
	void (*f)(char *);
	// void (*)(char *)   f;
	int a;
	FP f2;
	FF * f3;

	f = say_hello;
	f2 = say_hello;
	f3 = say_hello;
	printf("f = %p\n", f);
	printf("say_hello = %p\n", say_hello);

	f2("I am f2");
	f3("I am f3");

	a = 0x80483e4;
//	a = 0x8048400;
	((void (*)(char *))a)("August 20th");

	((FP)0x80483e4)("Today is August 20th");
	((FF *)0x80483e4)("Today is August 20th");

//	say_hello("akaedu");
	f("akaedu");
	
	return 0;
}

