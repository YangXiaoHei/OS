#include <stdio.h>
#include "../../bin_tool.h"

int float_f2i(unsigned x)
{
/* 0 10001001 00110100100001111110000 */
    unsigned exp = (x >> 23) & 0xff;
    if (exp < 127) 
        return 0;

    /* exp >= 127 */

    if (exp >= 31 + 127)
        return 0x80000000;

    /* exp >= 127 && exp < 158 */

    unsigned sign = (x >> 31) & 1;
    unsigned frac = (1 << 23) | (x & 0x7fffff);
    int result = 0;
    if (exp > 23 + 127) {
        result = frac << (exp - 127 - 23);
        goto decide_sign;
    }

    /* exp >= 127 && exp <= 150 */

    /*
     * 因为阶码 > 0, 所以尾数都有隐藏的 1
     * 假设有小数部分，那么 1.xxxx * 2^y
     * 因此我们将小数部分抹去即可
     */

    unsigned E = exp - 127;
    unsigned mbits = 23 - E;

    unsigned mask = (1 << mbits) - 1;
    mask = ~mask;

    frac &= mask;    /* 去掉小数部分, 模拟向 0 舍入效果 */
    frac >>= mbits;  /* 把小数部分占用的位数去掉 */

    result = frac;

decide_sign:
    result = sign ? (~result + 1) : result;
    return result;
}

void observe_bit_mode(void)
{
    unsigned x = 0;
    unsigned exp = 100;
    for (; exp <= 140; exp++, x = 0) {
        x |= (exp << 23);
        printf("exp = %d, %d\n", exp, (int)u2f(x));
    }
}

void test_float_f2i(void)
{
    for (unsigned x = 0; x < 4294967295; x++) {
        if (x % 1000000 == 0)
            printf("x = %zd, %s\n", x, f32(u2f(x)));
        if ((int)u2f(x) != float_f2i(x)) {
            printf("not equal!\n");
            printf("bit mode : %s\n", f32(u2f(x)));
            printf("should be : %d\n", (int)u2f(x));
            printf("now be : %d\n", float_f2i(x));
        }
    }
}

int main(int argc, char *argv[])
{
    /* observe_bit_mode(); */
    printf("%d\n", float_f2i(f2u(-1234.123f)));
    printf("%d\n", float_f2i(f2u(1234.123f)));

    printf("%d\n", float_f2i(f2u(17374752.0f)));
    printf("%d\n", float_f2i(f2u(-17374752.0f)));

    printf("%d\n", float_f2i(f2u(429496729666666.0f)));

    test_float_f2i();
}
