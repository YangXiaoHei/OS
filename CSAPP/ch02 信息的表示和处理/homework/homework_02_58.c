#include <stdio.h>

int is_little_endian(void)
{
    unsigned short a = 0x1;
    return *(char *)&a == 1;
}

int main(int argc, char *argv[])
{
    /*
     * is little endian
     */
    printf("%s little endian\n", is_little_endian() ? "is" : "not");
}
