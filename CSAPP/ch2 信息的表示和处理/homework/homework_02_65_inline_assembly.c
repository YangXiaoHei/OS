#include <stdio.h>
#include "../../bin_tool.h"

int odd_ones_for_lowest_byte(unsigned x)
{
    /*
     * xxxx OF DF IF TF SF ZF x AF x PF x CF
     */
    unsigned long flags = 0;
    __asm__ __volatile__ 
            (
                "testl %1, %1   \n\t"
                "pushfq         \n\t"
                "pop %0       \n\t"
                : "=r" (flags)
                : "r" (x)
            );
    int pf = (flags >> 2) & 1;
    return -1 + pf + pf;
}

int odd_ones(unsigned x)
{
    int r0 = odd_ones_for_lowest_byte(x);
    int r1 = odd_ones_for_lowest_byte(x >> 8);
    int r2 = odd_ones_for_lowest_byte(x >> 16);
    int r3 = odd_ones_for_lowest_byte(x >> 24);
    int r = r0 * r1 * r2 * r3;
    return (r >> 31) & 1;
}

int main(int argc, char *argv[])
{
    /*
     * 1
     * 0
     * 0
     * 0
     * 1
     */
    printf("%d\n", odd_ones(tou32("10000000 00000000 00000100 00000111")));
    printf("%d\n", odd_ones(tou32("10000000 00100000 00000100 00000111")));
    printf("%d\n", odd_ones(tou32("10000000 01011000 00000100 00000111")));
    printf("%d\n", odd_ones(tou32("10000000 00001000 00100100 01000111")));
    printf("%d\n", odd_ones(tou32("10101010 10100000 10001100 00010111")));
}
