#include <stdio.h>
#include "../../bin_tool.h"

#define DEBUG 0

unsigned float_i2f(int x)
{
    if (x == -2147483647 - 1)
        return f2u(-2147483648.0);
    
    unsigned sign = 0;
    x = x < 0 ? (sign = 1, (~x + 1)) : x;

#if DEBUG
    printf("x = %s\n", i32_(x));
#endif

    unsigned leading_one = 31;
    while (!((1 << leading_one--) & x));
    ++leading_one;

    unsigned mask = (1 << leading_one) - 1;
    unsigned frac = x & mask;

    unsigned E = leading_one;
    unsigned exp = E + 127;

    if (leading_one <= 23) {
        frac <<= (23 - leading_one);
        goto compose;
    }

    /* exp >= 24 */

    unsigned the_23th_bit = (frac >> (leading_one - 23)) & 1;
    unsigned the_24th_bit = (frac >> (leading_one - 24)) & 1;
    unsigned the_24th_line = 1 << (leading_one - 24);
    unsigned the_trunc_mask = (1 << (leading_one - 23)) - 1;
    unsigned all_trunc_bits = frac & the_trunc_mask;

#if DEBUG
    printf("the_23th_bit %d\n", the_23th_bit);
    printf("the_24th_bit %d\n", the_24th_bit);
    printf("the_24th_line %d\n", the_24th_line);
    printf("the_trunc_mask %s\n", i32(the_trunc_mask));
    printf("all_trunc_bits %s\n", i32(all_trunc_bits));
#endif

    /*
     * if (the_23th_bit == 0)
     *     need_round = (all_trunc_bits > the_24th_line); 
     * else
     *     need_round = (all_trunc_bits >= the_24th_line);
     * 去除分支 
     */

    unsigned ge = all_trunc_bits >= the_24th_line;
    unsigned g = all_trunc_bits > the_24th_line;
    unsigned need_round = the_23th_bit ? ge : g;

    frac >>= (leading_one - 23);
    frac += need_round;

    /*
     * if (frac & (1 << 23)) {
     *     exp++;
     *     frac &= ~(1 << 23);
     * }
     * 去除分支
     */
    unsigned carry = (frac >> 23) & 1;
    exp += carry;

compose:
    return (sign << 31) | (exp << 23) | (frac & 0x7fffff);
}

void observe_bit_mode(void)
{
    int i = toi32("0 00000001 11111111111111111111111");
    printf("%s\n", f32((float)i));

    i = toi32("0 00000011 11111111111111111111111");
    printf("%s\n", f32((float)i));
}

void test_float_i2f(void)
{
    for (int x = 2147483647; x >= -2147483647-1; x--) {
        if ((float)x != u2f(float_i2f(x))) {
            printf("not equal!\n");
            printf("%d\n", x);
            printf("should be : %s\n", f32((float)x));
            printf("now be    : %s\n", f32(u2f(float_i2f(x))));
            break;
        }
    }
}

void test_case(void)
{
    int i = -2147483583;
    printf("should be : %s\n", f32(((float)i)));
    printf("now be    : %s\n", f32(u2f(float_i2f(i))));
}

int main(int argc, char *argv[])
{
    /* observe_bit_mode(); */

  /* test_case(); */
  test_float_i2f();
}
