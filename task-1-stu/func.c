#include <stdio.h>
#include "func.h"

int load(int argc, char *argv[])
{
	printf("load cmd\n");

	load_file(argv[1]);

	return 0;
}

int sort(int argc, char *argv[])
{
	printf("sort cmd\n");

	if (strcmp(argv[1], "name") == 0)
		sort_by_name();

	if (strcmp(argv[1], "age") == 0)
		sort_by_age();

	return 0;
}

int find(int argc, char *argv[])
{
	printf("find cmd\n");

	if (strcmp(argv[1], "native") == 0)
		find_native(argv[2]);

	if (strcmp(argv[1], "hobby") == 0)
		find_hobby(argv[2]);

	return 0;
}

