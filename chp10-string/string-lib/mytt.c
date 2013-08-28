#include <stdio.h>
#include <string.h>

struct word
{
	char name[32];
	int len;
	int freq;
	char trans[64];
};

typedef struct word word_t;

#define N	16000
word_t words[N];
int wc = 0;			// word counter

int find(char * word)
{
	int i = 0;

	for (i = 0; i < wc; i++)
	{
		// found a match
		if (strcmp(word, words[i].name) == 0)
			return i;
	}

	return -1;
}

void get_translation(char * word, char * trans)
{
	char cmd[64];
	char buf[10240];
	char * tmpfile = "t.tmp";
	FILE * fp;
	char * p;

	strcpy(cmd, "");
	strcat(cmd, "./trans.rb ");
	strcat(cmd, word);
	strcat(cmd, " > ");
	strcat(cmd, tmpfile);

//	printf("cmd = <%s>\n", cmd);
	system(cmd);

	fp = fopen(tmpfile, "r");
	fscanf(fp, "%s", buf); 
	fclose(fp);

//	printf("buf = <%s>\n", buf);
	p = strtok(buf, "\"");
//	printf("p = <%s>\n", p);

	p = strtok(NULL, "\"");
//	printf("p = <%s>\n", p);

	strcpy(trans, p);
	return;
}

int main(void)
{
	char c;
	int counter = 0;
	int i = 0;
	int j = 0;
	int flag = 0;
	int length = 0;
	int max_len = 0;
	int max_freq = 0;

	printf("demo mytt\n");

	while ((c = getchar()) != EOF)
	{
		char word[32];
		int ret = 0;

		//putchar(c);
		if (isalpha(c))
		{
			word[j++] = c;	
			flag = 1;
		}
		
		if (!isalpha(c) && flag == 1)
		{
			word[j] = '\0';
			j = 0;
			flag = 0;

			// add some new codes
			// not found this word
			ret = find(word);
			if (ret == -1)
			{
				strcpy(words[wc].name, word);
				length = strlen(word);
				words[wc].len = length;
				words[wc].freq = 1;
				wc++;

				if (length > max_len)
					max_len = length;

				strcat(word, ">");
				printf("%3d: word = <%-16s len:%d\n", wc, word, length);
			}
			else // found this word
			{
				words[ret].freq++;
			}
		}
		counter++;
	}
	//printf("char counter = %d\n", counter);

	printf("max len = %d words list here:\n", max_len);
	for (i = 0; i < wc; i++)
	{
		if (words[i].len == max_len)
			printf("<%s>\n", words[i].name);
	}

	int sum = 0;
	for (i = 0; i < wc; i++)
	{
		char trans[64] = "trans";

		if (words[i].freq > max_freq)
			max_freq = words[i].freq;

		// get word translation
		get_translation(words[i].name, trans);	
		strcpy(words[i].trans, trans);

		printf("%3d: %-16s len:%2d  freq:%4d  (%s)\n", i+1, words[i].name, words[i].len, words[i].freq, words[i].trans);

		sum += words[i].freq;
	}

	printf("sum = %d\n", sum);

	getchar();
	for (j = max_freq; j >= 0; j--)
	{
		for (i = 0; i < wc; i++)
		{
			if (words[i].freq == j)
				printf("%3d: %-16s len:%2d  freq:%4d  (%s)\n", i+1, words[i].name, words[i].len, words[i].freq, words[i].trans);
		}
	}

	return 0;
}
