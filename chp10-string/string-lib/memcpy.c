#include <stdio.h>
#include <string.h>

char *strcpy(char *dst, const char *src)
{
	char *ret = dst;
	int *d = (int *)dst;
	int *s = (int *)src;

	int n = strlen(src) / 4;
	// d, s align = 4bytes

	while (1)
	{
		if ((*s & 0xFF) == 0 || (*s & 0xFF00) == 0 || (*s & 0xFF0000) == 0 || (*s & 0xFF000000) == 0)
			break;

		*d = *s;

		s++;
		d++;
	}

	src = s;
	dst = d;

	left = strlen(src) % 4;
	while (left--)
	{
		*dst++ = *src++;
	}

	return ret;

}

char *strcpy(char *dst, const char *src)
{
	char *ret = dst;

	while (1)
	{
		*dst = *src;

		if (*src == '\0')
			break;
		
		dst++;
		src++;
	}

	return ret;
}

char *strcpy(char *dst, const char *src)
{
	char *ret = dst;

	//while ((*dst++ = *src++) != '\0')
	while (*dst++ = *src++)
		;

	return ret;
}

int main(void)
{
	char buf[20] = "hello world\n";

	printf("buf = %s\n", buf);
	//memcpy(buf+1, buf, 13);
	memmove(buf+1, buf, 13);
	printf("buf = %s\n", buf);

	return 0;
}
