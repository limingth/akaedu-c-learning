#include <stdio.h>

int main(void)
{
	char buf[128];
	int counter = 0;

	while (1)
	{
		char * p;
		int i = 0;
		char ch;

		p = fgets(buf, 128, stdin);
		if (p == NULL)
			break;

//		sleep(1);
		puts(buf);

		while ((ch = buf[i++]) != '\0')
		{
			int j = 0;
			char word[32];

			if (!isalpha(ch))
				continue;

			do
			{
				word[j++] = ch;
				ch = buf[i++];
			} while (isalpha(ch));
			word[j] = '\0';
			printf("%d: word = <%s>\n", counter++, word);
		}
	}

	// analyze buf and print words
	printf("%d: <%s>\n", 1, "This");

	return 0;
}
