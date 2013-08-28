#include <stdio.h>
#include <string.h>


int main(void)
{
	char * buf = "lhelloworld";
	char * p;

	printf("buf = %s\n", buf);

	p = buf;
	while (1)
	{
		p = strchr(p, 'l');

		if (p == NULL)
			break;

		printf("p = %s  pos = %d\n", p, p - buf);
		p++;
	}
	return 0;



	p = strchr(buf, 'l');
	printf("p = %s\n", p);

	p = strchr(p+1, 'l');
	printf("p = %s\n", p);

	p = strchr(p+1, 'l');
	printf("p = %s\n", p);

	p = strchr(p+1, 'l');
	printf("p = %s\n", p);

	return 0;
}


