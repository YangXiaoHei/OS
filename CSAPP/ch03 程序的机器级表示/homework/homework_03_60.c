#include <stdio.h>

long disassembly_loop(long x, int n)
{
    long result = 0;
    long mask;
    for (mask = 1; mask != 0; mask <<= 1)
        result |= (x & mask);
    return result;
}

long loop(long x, int n);

int main(int argc, char *argv[])
{
    long x = 0x12345678;
    int n = 1;
    printf("%ld\n", disassembly_loop(x, n));
    printf("%ld\n", loop(x, n));
}
