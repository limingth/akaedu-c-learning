#include <stdio.h>
#include <string.h>


int main(void)
{
	char * buf = "llhelloworlllodlo";
	char * p;

	printf("buf = %s\n", buf);

	p = buf;
	while (1)
	{
		p = strstr(p, "ll");

		if (p == NULL)
			break;

		printf("p = %s  pos = %d\n", p, p - buf);
		//p++;
		p += strlen("ll");
	}

	return 0;
}


