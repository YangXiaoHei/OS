#include <stdio.h>
#include "../../bin_tool.h"

unsigned float_half(unsigned x)
{
    /* return f2u(u2f(x) * 0.5f); */
    unsigned exp = (x >> 23) & 0xff;
    unsigned sign = (x >> 31) & 0x1;
    unsigned frac = x & 0x7fffff;

    /*
     * x xxxx xxxxxxxxxxxxxxxxxxxxx01 向偶数舍入到 0, 相当于丢弃第23位
     * x xxxx xxxxxxxxxxxxxxxxxxxxx00 无需舍入，相当于丢弃第 23 位
     * x xxxx xxxxxxxxxxxxxxxxxxxxx10 无需舍入，相当于丢弃第 23 位
     * x xxxx xxxxxxxxxxxxxxxxxxxxx11 向偶数舍入，末尾 + 1
     */
    unsigned need_round = (x & 0x3) == 0x3;

    /* 如果是规格化数，阶码不为 0，直接--exp，相当于把小数点往前挪一位 */
    if (exp != 0) {
        if (--exp == 0) {
            /*
             * 当规格化数转为非规格化数时，补充
             * 开头隐藏的 1
             */
            frac |= (1 << 23);
        }
    }

    /*
     * 如果是非规格化数（注意这里包含了刚刚由于--exp 
     * 从规格化数转变过来的非规格化数）
     */
    if (exp == 0) {
        /* 如果需要向偶数舍入，末尾 +1 以便让第 23 位是 0 */
        frac += (need_round ? 1 : 0);
        /* 小数点往前挪一位, 丢弃多余的位 */
        frac >>= 1;
    }
    return (sign << 31) | (exp << 23) | frac;
}

void test_float_half(void)
{
#define exp(x) ((x >> 23) & 0xff)
    /* 正数 */
    for (unsigned x = 1; exp(x) != 0xff; ++x) {
        if (u2f(x) * 0.5f != u2f(float_half(x))) {
            printf("not equal!\n");
            printf("%s\n", f32(u2f(x)));
            printf("should be: %s\n", f32(0.5f * u2f(x)));
            printf("now    be: %s\n", f32(u2f(float_half(x))));
            return;
        }
    }
    /* 负数 */
    for (unsigned x = (1 << 31) | 1; exp(x) != 0xff; ++x) {
        if (u2f(x) * 0.5f != u2f(float_half(x))) {
            printf("not equal!\n");
            printf("%s\n", f32(u2f(x)));
            printf("should be: %s\n", f32(0.5f * u2f(x)));
            printf("now    be: %s\n", f32(u2f(float_half(x))));
            return;
        }
    }
}

void observe_bit_mode(void)
{
    float i = tof32("0 00101100 11100101100010101001111");
    /* float i = tof32("0 00101100 11111111111111111111111"); */
    for (int j = 0; j < 70; j++) {
        printf("j = %02d, %s\n", j, f32(i));
        i /= 2;
    }
}

int main(int argc, char *argv[])
{
     /* observe_bit_mode(); */
     test_float_half();
}
