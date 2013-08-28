#include <stdio.h>
#include <stdlib.h>

struct node
{
	char item;
	struct node *l, *r;
};
typedef struct node * link;


link root = NULL;

link make_node(char item)
{
	link p;

	p = malloc(sizeof(*p));
	p->item = item;
	p->l = NULL;
	p->r = NULL;

	return p;
}

void traverse(link t)
{
	if (t == NULL)
	{
		printf("()");
		return;
	}

	//printf("t->item = %c\n", t->item);
	printf("(%c", t->item);
	traverse(t->l);
	traverse(t->r);
	printf(")", t->item);

	return;
}

int depth(link t)
{
	if (t == NULL)
		return 0;

	int lc = depth(t->l);
	int rc = depth(t->r);

	return 1 + (lc > rc ? lc : rc);

	//return 1 + count(t->l) + count(t->r);
}

int isbalanced(link t)
{
	if (t == NULL)
		return 1;

	int lc = depth(t->l);
	int rc = depth(t->r);

	if (lc - rc >= 2 || rc -lc >= 2)
		printf("t->item = %c is not balanced\n", t->item);

	if (isbalanced(t->l) == 0 || isbalanced(t->r) == 0)
		return 0;

	if (lc - rc >= 2 || rc -lc >= 2)
		return 0;

	return 1;
}

int count(link t)
{
	if (t == NULL)
		return 0;

	int lc = count(t->l);
	int rc = count(t->r);

	return 1 + lc + rc;

	//return 1 + count(t->l) + count(t->r);
}

link init(char VLR[], char LVR[], int n)
{
	link t;
	int k = 0;

	if (n <= 0)
		return NULL;

	for (k = 0; VLR[0] != LVR[k]; k++)
		;

	t = make_node(VLR[0]);
	t->l = init(VLR+1, LVR, k);
	t->r = init(VLR+1+k, LVR+1+k, n-k-1);

	return t;
}

int mypow(int base, int pow)
{
	int ret = 1;
	int i = 0;

	for (i = 0; i < pow; i++)
		ret *= base;

	return ret;
}

link search(link t, char key)
{
	if (t == NULL)
		return NULL;

	if (key > t->item)
		return search(t->r, key);
	else if(key < t->item)
		return search(t->l, key);

	return t;
}

link insert(link t, char key)
{
	if (t == NULL)
		return make_node(key);

	if (key > t->item)
		t->r = insert(t->r, key);
	else if(key < t->item)
		t->l = insert(t->l, key);
	else
		printf("same node (%c) exists\n", key);

	return t;
}

int main(void)
{
#if 0
	char pre_seq[] = "4213657";
	char in_seq[]  = "1234567";

	root = init(pre_seq, in_seq, 7);
#endif

#if 0
	char pre_seq[] = "421356";
	char in_seq[]  = "123456";

	root = init(pre_seq, in_seq, 6);
#endif

#if 0
	link a, b, c;
	link d, e, f;

//	printf("demo binary tree!\n");
	a = make_node('4');
	b = make_node('2');
	c = make_node('5');

	d = make_node('1');
	e = make_node('3');
	f = make_node('6');

	a->l = b;
	a->r = c;
	b->l = d;
	//b->r = e;
	//c->r = f;
	d->r = f;
	f->r = e;

	root = a;
#endif

extern yyin;
	yyin = stdin;

	while (1)
	{
		yylex();
		continue;
		char ch;

		ch = getchar();
		getchar();
		if (ch == 'q')
			break;
		root = insert(root, ch);
		
		printf("\t\\tree ");
		traverse(root);
		printf("\n\n");
		fflush(stdout);
	}

	while (1)
	{
		char ch = getchar();
		getchar();

		link p = search(root, ch);
		if (p != NULL)
			printf("%c is found\n", ch);
		else
			printf("%c is NOT found\n", ch);
	}

	printf("count = %d\n", count(root));
	printf("depth = %d\n", depth(root));
	printf("balance = %d\n", isbalanced(root));

	if (mypow(2, depth(root)) == count(root) + 1)
		printf("it is a FULL Btree\n");
	else
		printf("it is not a FULL Btree\n");


	return 0;
}

