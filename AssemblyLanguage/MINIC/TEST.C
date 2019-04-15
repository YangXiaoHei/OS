
struct A {
  int a:8;
  int b:2;
};

main()
{
	struct A a;
	int c;

	a.a = 1;
	a.b = 2;

	c = sizeof(a);
}
