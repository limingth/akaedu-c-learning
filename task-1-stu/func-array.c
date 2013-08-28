#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "public.h"

stu_t students[40];
int num = 0;

void load_file(char * filename)
{
	FILE *fp;

	printf("loading file %s\n", filename);

	fp = fopen(filename, "r");

	int i = 0;
	while (1) 
	{   
		int ret;
		char buf[256] = ""; 
		char * p;

		p = fgets(buf, 256, fp); 
		if (p == NULL)
			break;

		ret = sscanf(buf, "%s %s %d %s %s %s %s %s %s", 
						students[i].name,
						students[i].cname,
						&students[i].age,
						students[i].gender,
						students[i].native,
						students[i].mobile,
						students[i].qq,
						students[i].email,
						students[i].hobby);

		i++;

//		printf("ret = %d\n", ret);
//		printf("line : %d, buf : <%s>\n", i, buf);
	}   

	num = i;
	printf("all students num is %d \n", num);

	return;
}

int cmp_name(const void * s1, const void * s2)
{
	int ret = 0;

	ret = strcmp(((stu_t *)s1)->name, ((stu_t *)s2)->name);

	return ret;
}

int cmp_age(const void * s1, const void * s2)
{
	int ret = 0;

	ret = ((stu_t *)s1)->age - ((stu_t *)s2)->age;

	return ret;
}

void print_info(stu_t * p)
{
//	printf("%s : %d\n", p->cname, strlen(p->cname));
	printf("%-16s ", p->name);

	if (strlen(p->cname) == 6)
		printf("%-10s ", p->cname);
	else
		printf("%-11s ", p->cname);

	printf("%2d ", p->age);
	printf("%-4s ", p->gender);

	if (strlen(p->native) == 6)
		printf("%-8s ", p->native);
	else
		printf("%-9s ", p->native);

	printf("%-12s ", p->mobile);
	printf("%-12s ", p->qq);
	printf("%-26s ", p->email);
	printf("%-16s ", p->hobby);

	printf("\n");
	return;
}

void list_name(char * name)
{
	int i = 0;

	for (i = 0; i < num; i++)
	{
		if (strcmp(students[i].name, name) == 0)
			print_info(&students[i]);
	}

	return;
}

void list_all(void)
{
	int i = 0;

	for (i = 0; i < num; i++)
		print_info(&students[i]);
}

void sort_by_name(void)
{
	qsort(students, 35, sizeof(stu_t), cmp_name);

	list_all();

	return;
}

void sort_by_age(void)
{
	qsort(students, 35, sizeof(stu_t), cmp_age);
	list_all();

	return;
}

int list(int argc, char *argv[])
{
	printf("list cmd\n");

	if (argc == 1)
		list_all();
	else
		list_name(argv[1]);

	return 0;
}

void find_native(char * native)
{
	int i = 0;

	for (i = 0; i < num; i++)
	{
		if (strcmp(students[i].native, native) == 0)
			print_info(&students[i]);
	}

	return;
}

void find_hobby(char * hobby)
{
	int i = 0;

	for (i = 0; i < num; i++)
	{
		if (hobby == NULL)
			continue;

		if (strstr(students[i].hobby, hobby) != NULL)
			print_info(&students[i]);
	}

	return;
}


