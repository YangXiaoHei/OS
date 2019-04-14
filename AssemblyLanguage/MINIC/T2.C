int f(int arg1, int arg2, int arg3);

main()
{
	int a, b, c, d;
	a = 1;
	b = 2;
	c = 3;
	d = f(15, 14, 13);
}

int f(int arg1, int arg2, int arg3)
{
	int e, f, g;
	arg1 *= arg2;
	arg2 *= arg3;
	e = 4;
	f = 5;
	g = 6;
	return e + f + g;
}