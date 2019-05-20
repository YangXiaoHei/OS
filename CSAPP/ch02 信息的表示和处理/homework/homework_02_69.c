#include <stdio.h>
#include <stdlib.h>
#include "../../bin_tool.h"

int rotating_left(unsigned x, int n)
{
    int w = sizeof(x) << 3;
    int removed_bits = x >> (w - n); /* 因为是无符号数，一定是逻辑右移，所以不需要再用掩码来 & */
    x <<= n;
    x |= removed_bits ;
    return x;
}

int main(int argc, char *argv[])
{
    int nshift = 4;
    if (argc != 1) {
        nshift = atoi(argv[1]);
    }
    int num = 0x12345678;
    printf("%x\n", rotating_left(num, nshift));
    printf("%s\n", i32_(num));
    printf("%s\n", i32_(rotating_left(num, nshift)));
}
