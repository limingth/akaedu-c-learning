#include <stdio.h>

//#define DEBUG  0

//#define DEBUG

int main(void)
{
//#if DEBUG
//#if defined(DEBUG)
#ifndef DEBUG
	printf("debuf info....\n");
#endif

#if DEBUG
	printf("2  debuf info....\n");
//#else
//	#if MAX
#elif MAX
	printf("3  debuf info....\n");
//	#endif
#endif
	return 0;
}
