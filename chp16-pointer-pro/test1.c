
int main(void)
{
	int a[10];

	int * p;	// a
	int (*p2)[10];	// &a

	p = a;
	p2 = &a;

	printf("a  = %p\n", a);
	printf("&a = %p\n", &a);

	printf("a + 1 = %p\n", a + 1);
	printf("&a + 1= %p\n", &a + 1);

	return 0;
}
