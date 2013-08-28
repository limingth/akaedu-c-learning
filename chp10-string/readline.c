#include <stdio.h>

int read_line(char str[], int n)
{
	char ch;
	int i = 0;

	while ((ch = getchar()) != '\n')
	{
		if (i < n-1)
			str[i++] = ch;
	}

	str[i] = '\0';

	return i;
}

int main(void)
{
	char buf[8];
	char buf2[8];
	char ch;

//	read_line(buf, 8);
//	fgets(buf, 8, stdin);
	system("stty raw");
	system("clear");
	printf("do you want to continue? y/n\n\r");

	do 
	{
		ch = getchar();
		printf("ch = %c (0x%x) \r\n", ch, ch);
	} while (1);

	if (ch = 'y')
		printf("ok, continue\n");
	else
		printf("good bye!\n");

//	printf("buf = <%s>\n", buf);

	scanf("%s", buf2);
	printf("buf2 = <%s>\n", buf2);

	system("stty -raw");

	return 0;
}
