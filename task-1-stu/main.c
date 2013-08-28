#include <stdio.h>

int load(int argc, char *argv[]);
int list(int argc, char *argv[]);
int sort(int argc, char *argv[]);
int find(int argc, char *argv[]);

struct cmd
{
	char name[16];
	int (*pf)(int argc, char *argv[]);
} cmds[] =
{
	"load", load,
	"list", list,
	"sort", sort,
	"find", find
};


int main(void)
{
	printf("\nWelcome to student system V1.0\n");

	char * argv[] = {"load", "T66.txt"};
	load(2, argv);

	while (1)
	{
		char buf[128];
		int argc = 0;
		char * argv[8];
		int i = 0;

		printf("student$ ");
		fgets(buf, 128, stdin);

		parse(buf, &argc, argv);

		for (i = 0; i < sizeof(cmds)/sizeof(cmds[0]); i++)
			if (strcmp(argv[0], cmds[i].name) == 0)
				cmds[i].pf(argc, argv);
	}
}
