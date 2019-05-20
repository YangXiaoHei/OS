#include <stdio.h>
#include "../../bin_tool.h"

typedef unsigned pack_t;

int xbyte(pack_t word, int bytenum)
{
    int w = sizeof(int) << 3;
    int nbits = bytenum << 3;
    int nshift = w - 8;
    int byte = (word >> nbits) & 0xff;
    return (byte << nshift) >> nshift;
}

int main(int argc, char *argv[])
{
    /*
     * 100
     * 11111111 11111111 11111111 11001000
     * 11111111 11111111 11111111 10110010
     * 11111111 11111111 11111111 10010011
     */
    pack_t word = tou32("10110010 11001000 00000100 10010011");
    printf("%s\n", i32(xbyte(word, 1)));
    printf("%s\n", i32(xbyte(word, 2)));
    printf("%s\n", i32(xbyte(word, 3)));
    printf("%s\n", i32(xbyte(word, 4)));
}
