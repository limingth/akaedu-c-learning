#include <stdio.h>
#include <string.h>


int main(void)
{
	char buf[] = "abc<html><head><title>404 Not Found</title></head>";
	char * p;

	printf("buf = %s\n", buf);

	p = buf;
	printf("p = %p\n", p);
	printf("buf[3] = %c(0x%x)\n", buf[3], buf[3]);
	p = strtok(p, "<");
	while (1)
	{
		char *p1, *p2;
		p1 = strtok(NULL, "<>");
		//printf("p = %s\n", p);
		//printf("p = %s\n", p + 4);
		printf("p1 = %s\n", p1);
		
		if (p1 == NULL)
			break;
	}

	printf("p = %p\n", p);
	printf("buf[3] = %c(0x%x)\n", buf[3], buf[3]);

	return 0;
}
