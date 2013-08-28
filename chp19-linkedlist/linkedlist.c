#include <stdio.h>
#include <stdlib.h>

struct node
{
	char item;
	int age;
	int num;
	struct node * next;
};
typedef struct node * link;

link head = NULL;

int main(void)
{
	link p = NULL;

	printf("size of p = %d\n", sizeof(p));
	printf("size of *p = %d\n", sizeof(*p));
	printf("size of *p = %d\n", sizeof(struct node));

	printf("item & = %p\n", &(((link)0)->num));

//	p = &a;
	p = malloc(sizeof(*p));
	p->item = 'a';
	p->next = NULL;
	printf("p1 = %p\n", p);

	head = p;

	p = malloc(sizeof(*p));
	p->item = 'b';
	p->next = NULL;
	printf("p2 = %p\n", p);

	// a -> b
	head->next = p;

	p = malloc(sizeof(*p));
	p->item = 'c';
	p->next = NULL;
	printf("p3 = %p\n", p);

	// b -> c
	head->next->next = p;

#if 0
	// 1. insert D before head
	p = malloc(sizeof(*p));
	p->item = 'D';
	p->next = head;
	printf("p4 = %p\n", p);

	head = p;
#endif

#if 0
	// 2. insert D after tail
	link tail = NULL;
//	tail = head->next->next;
	p = head;
	while (p != NULL)
	{
		if (p->next == NULL)
			tail = p;

		p = p->next;
	}

	p = malloc(sizeof(*p));
	p->item = 'D';
	p->next = NULL;

	tail->next = p;
#endif

#if 0
	// 3. insert D after pos node
	link pos = head->next;

	p = malloc(sizeof(*p));
	p->item = 'D';
	// step 1:  D->c
	p->next = pos->next;
	// step 2:  b->D
	pos->next = p;
#endif

#if 0
	// 4. insert D before pos node
	link pos = head->next;
	link prev = NULL;

	// search for pos's prev
	p = head;
	while (p != NULL)
	{
		if (p->next == pos)
		{
			prev = p;
			break;
		}
		p = p->next;
	}

	p = malloc(sizeof(*p));
	p->item = 'D';
	p->next = pos;

	prev->next = p;
#endif

#if 0
	// 1. delete pos == head
	link pos = head;

	head = pos->next;
	free(pos);
	pos = NULL;
#endif

	// 2. delete pos != head
//	link pos = head->next;
	link pos = head->next->next;

	link prev = NULL;
	// search for pos's prev
	p = head;
	while (p != NULL)
	{
		if (p->next == pos)
		{
			prev = p;
			break;
		}

		p = p->next;
	}

	prev->next = pos->next;
	free(pos);
	pos = NULL;

	// travel list from head
	p = head;
	while (p != NULL)
	{
		printf("p->item = %c\n", p->item);
		printf("p->next = %p\n", p->next);
		p = p->next;
	}

	return 0;
}
