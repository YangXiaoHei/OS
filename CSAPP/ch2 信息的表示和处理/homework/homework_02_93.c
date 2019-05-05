#include <stdio.h>
#include "../../bin_tool.h"

unsigned float_absval(unsigned f)
{
    unsigned exp = (f >> 21) & 0xffff;
    unsigned frac = f & 0x7fffff;
    if (exp == 0xffff && frac != 0)
        return f;
    return f & 0x7fffffff;
}

int main(int argc, char *argv[])
{
    /*
     * 3.00
     * 3.00
     * 100000.00
     * 100000.00
     * 0.00
     * inf
     * inf
     * nan
     */
    printf("%.2f\n", u2f(float_absval(f2u(-3.0))));
    printf("%.2f\n", u2f(float_absval(f2u(3.0))));
    printf("%.2f\n", u2f(float_absval(f2u(-100000.0))));
    printf("%.2f\n", u2f(float_absval(f2u(100000.0))));
    printf("%.2f\n", u2f(float_absval(f2u(-0.0))));
    printf("%.2f\n", u2f(float_absval(f2u(tof32("1 11111111 00000000000000000000000")))));
    printf("%.2f\n", u2f(float_absval(f2u(tof32("0 11111111 00000000000000000000000")))));
    printf("%.2f\n", u2f(float_absval(f2u(tof32("0 11111111 00000001001000000000000")))));
}
