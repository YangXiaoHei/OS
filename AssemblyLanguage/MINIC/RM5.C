#define buffer ((char *)*(int far *)0x200)

main()
{
	buffer = (char *)malloc(20);
	buffer[10] = 0;
	while (buffer[10] != 8) {
		buffer[buffer[10]] = 'a' + buffer[10];
		buffer[10]++;
	}
	free(buffer);

}