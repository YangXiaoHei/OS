main()
{
	*(short far *)(0xb8000000 + 160*12+35*2) = 0x261;

}