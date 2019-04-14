void showchar(char a, char b);

main()
{
	showchar('a', 2);
}

void showchar(char a, char b)
{
	*(char far *)(0xb8000000 + 160 * 10 + 80) = a;
	*(char far *)(0xb8000000 + 160 * 10 + 81) = b;

}