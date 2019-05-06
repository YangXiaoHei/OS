#include <stdio.h>
#include "../../bin_tool.h"

unsigned float_twice(unsigned x)
{
   /* return f2u(u2f(x) * 2);  */
    unsigned exp = (x >> 23) & 0xff;
    unsigned frac = x & 0x7fffff;
    unsigned sign = (x >> 31) & 1;

    /* NaN 或者 ∞，直接返回 */
    if (exp == 255)
        return x;
    
    /* 溢出到无穷大 */
    if (exp == 254)
        return (sign << 31) | (0xff << 23);

    if (exp != 0) {
        exp++;
    } else {
        if (frac & (1 << 22))
            exp = 1;
        frac <<= 1;
    }
    return (sign << 31) | (exp << 23) | frac; 
}

void observe_bit_mode(void)
{
 /*
  *    for (float i = 0.1; i <= 20; i *= 2) {
  *        printf("%.2f -- %s\n", i, f32(i));
  *    }
  * 
  *    printf("%s\n", f32(0.5));
  *    printf("%s\n", f32(1));
  */

    float j = u2f(tou32("0 00000000 00000000000000001011101"));
    for (int i = 0; i < 300; i++, j *= 2) {
        printf("%s\n", f32(j));
    }
}

void test_float_twice(void)
{
#define exp(x) ((x >> 23) & 0xff)
    /* 正数 */
    for (unsigned x = 1; exp(x) != 0xff; ++x) {
        if (2 * u2f(x) != u2f(float_twice(x))) {
            printf("not equal!\n");
            printf("%s\n", i32(exp(x)));
            printf("should be: %s\n", f32(2 * u2f(x)));
            printf("now be: %s\n", f32(float_twice(x)));
            return;
        }
    }
    /* 负数 */
    for (unsigned x = (1 << 31) | 1; exp(x) != 0xff; ++x) {
        if (2 * u2f(x) != u2f(float_twice(x))) {
            printf("not equal!\n");
            printf("%s\n", i32(exp(x)));
            printf("should be: %s\n", f32(2 * u2f(x)));
            printf("now be: %s\n", f32(float_twice(x)));
            return;
        }
    }
}

int main(int argc, char *argv[])
{
    test_float_twice();
}
