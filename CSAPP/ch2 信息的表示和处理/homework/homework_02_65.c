#include <stdio.h>
#include "../../bin_tool.h"

int odd_ones(unsigned x)
{
    x ^= (x >> 16);
    x ^= (x >> 8);
    x ^= (x >> 4);
    x ^= (x >> 2);
    x ^= (x >> 1);
    return x & 1;
}

int main(int argc, char *argv[])
{
    /*
     * 0
     * 0
     * 0
     * 1
     * 0
     */
    printf("%d\n", odd_ones(tou32("10001010 01010111 00001000 01100000")));
    printf("%d\n", odd_ones(tou32("10000000 00000000 00000000 00110000")));
    printf("%d\n", odd_ones(tou32("10000010 00000100 01010010 01000000")));
    printf("%d\n", odd_ones(tou32("10011100 01001001 00100110 00100100")));
    printf("%d\n", odd_ones(tou32("10000101 01010001 00111000 01110100")));
}
