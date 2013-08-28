#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void _myAssert(char * msg, char * func)
{
	printf("%s <%s> Failed!\n", msg, func);
	abort();
//	return;
}

//#define _STR(x)		#x
#define _STR(x)		_VAL(x)
#define _VAL(x)		#x

#define myassert(test)		(test)? (void)0: \
	_myAssert(__FILE__ ":" _STR(__LINE__)  " " #test, __func__)

int main(int argc, char * argv[])
{
	int a = 100;
	int b = 1;
	int * p = NULL;

	myassert(2>3);

	printf("ok %d, %d\n", a/b, *p);

	return 0;
}
