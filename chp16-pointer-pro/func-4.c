
void func(const int p)
{
	int * pp;

	pp = &p;

	//p = 100;

	printf("p = %d\n", p);
	//*pp = 200;
	*(int *)&p = 300;
	printf("p = %d\n", p);

	return;
}

int main(void)
{
	int a = 10;

	func(a);

	return 0;
}
