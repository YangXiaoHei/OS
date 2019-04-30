#include <stdio.h>

long decode2(long x, long y, long z);

long disassembly_decode2(long x, long y, long z)
{
    long t = y - z;
    long k = x * t;
    t = (t << 63) >> 63;
    return t ^ k;
}

int main(int argc, char *argv[])
{
    /*
     * 1754328933805
     * 1754328933805
     */
    long x = 0x123532;
    long y = 0x832432;
    long z = 0x999321;
    printf("%ld\n", decode2(x, y, z));
    printf("%ld\n", disassembly_decode2(x, y, z));
}
