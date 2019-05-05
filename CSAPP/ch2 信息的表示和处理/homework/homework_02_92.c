#include <stdio.h>
#include "../../bin_tool.h"

unsigned float_negate(unsigned f)
{
    unsigned exp = (f >> 23) & 0xffff;
    unsigned frac = f & 0x7fffff;
    if (exp == 0xffff && frac != 0)
        return f;
    return f ^ (1 << 31);
}

float u2f(unsigned x)
{
    return *(float *)&x;
}

unsigned f2u(float x)
{
    return *(unsigned *)&x;
}

int main(int argc, char *argv[])
{
    /*
     * 3.00
     * -3.00
     * -0.00
     * 0.00
     * -inf
     * inf
     * nan
     */
    printf("%.2f\n", u2f(float_negate(f2u(-3.0f))));
    printf("%.2f\n", u2f(float_negate(f2u(3.0f))));
    printf("%.2f\n", u2f(float_negate(f2u(0.0f))));
    printf("%.2f\n", u2f(float_negate(f2u(-0.0f))));

    printf("%.2f\n", u2f(float_negate(f2u(tof32("0 11111111 00000000000000000000000")))));
    printf("%.2f\n", u2f(float_negate(f2u(tof32("1 11111111 00000000000000000000000")))));
    printf("%.2f\n", u2f(float_negate(f2u(tof32("1 11111111 10000000000000000000000")))));
}
