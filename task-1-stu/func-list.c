#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "public.h"



typedef struct node * link;
struct node
{
	stu_t student;
	struct node * next;
};

link head = NULL;
link tail = NULL;

link students[40];
//stu_t students[40];
int num = 0;

void insert_tail(link p)
{
	// first insert
	if (head == NULL)
	{   
		head = tail = p;
		return;
	}   

	// next insert
	tail->next = p;
	tail = p;

	return;
}

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
		link s = NULL;

		p = fgets(buf, 256, fp); 
		if (p == NULL)
			break;

		s = malloc(sizeof(*s));
		ret = sscanf(buf, "%s %s %d %s %s %s %s %s %s", 
				s->student.name,
				s->student.cname,
				&s->student.age,
				s->student.gender,
				s->student.native,
				s->student.mobile,
				s->student.qq,
				s->student.email,
				s->student.hobby);

		insert_tail(s);
		students[i] = s;
		i++;

		//		printf("ret = %d\n", ret);
		//		printf("line : %d, buf : <%s>\n", i, buf);
	}   

	num = i;
	printf("all students num is %d \n", num);

	return;
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
		printf("%-10s ", p->native);
	else
		printf("%-11s ", p->native);

	printf("%-16s ", p->mobile);
	printf("%-16s ", p->qq);
	printf("%-32s ", p->email);
	printf("%-16s ", p->hobby);

	printf("\n");
	return;
}

void list_name(char * name)
{
	link p;

	p = head;
	while (p != NULL)
	{
		if (strcmp(p->student.name, name) == 0)
			print_info(&p->student);
		p = p->next;
	}

	return;
}

void list_all(void)
{
	int i = 0;

	for (i = 0; i < num; i++)
	{
		link p;

		p = students[i];
		print_info(&p->student);
	}
}

int cmp_name(const void * s1, const void * s2)
{
	int ret = 0;

	ret = strcmp(((link)*(int *)s1)->student.name, ((link)*(int *)s2)->student.name);

	return ret;
}

int cmp_age(const void * s1, const void * s2)
{
	int ret = 0;

	ret = ((link)*(int *)s1)->student.age - ((link)*(int *)s2)->student.age;

	return ret;
}

void sort_by_name(void)
{
	qsort(students, num, sizeof(link), cmp_name);

	list_all();

	return;
}

void sort_by_age(void)
{
	qsort(students, num, sizeof(link), cmp_age);

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
	link p;

	p = head;
	while (p != NULL)
	{
		if (strcmp(p->student.native, native) == 0)
			print_info(&p->student);
		p = p->next;
	}

	return;
}

void find_hobby(char * hobby)
{
	link p;

	p = head;
	while (p != NULL)
	{
		if (p->student.hobby == NULL)
			continue;

		if (strstr(p->student.hobby, hobby) != NULL)
			print_info(&p->student);

		p = p->next;
	}

	return;
}

