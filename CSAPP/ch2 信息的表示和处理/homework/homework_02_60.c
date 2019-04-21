#include <stdio.h>
#include "../../bin_tool.h"

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    return (x & ~(0xff << (i * 8))) | (b << (i * 8)); 
}

int main(int argc, char *argv[])
{
    /*
     * 12 ab 56 78
     * 12 34 56 ab
     */
    show_int(replace_byte(0x12345678, 2, 0xAB));
    show_int(replace_byte(0x12345678, 0, 0xAB));
}
