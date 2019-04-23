#include <stdio.h>
#include "../../bin_tool.h"

unsigned srl(unsigned x, int k)
{
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;

    int w = sizeof(x) << 3;
    int a = (1 << k) - 1;
    a <<= (w - k);
    xsra &= ~a;
    return xsra;
}

int sra(int x, int k)
{
    /* Perform shift logically */
    int xsrl = (unsigned) x >> k;

    /*
     * 这题挺难的...
     * 最重要的思路是那个 (z + ~(z & xsral))
     */
    int w = sizeof(x) << 3;
    int z = 1 << (w - k - 1);   /* 移动到符号位 */
    int rmask = z - 1;          /* 右边的掩码，不包含符号位 */
    int lmask = ~rmask;          /* 左边的掩码，包含符号位 */
    int right = rmask & xsrl; 
    int left = lmask & (z + ~(z & xsrl));    /* 这个思路有点牛逼 */
    return left | right;
}

int main(int argc, char *argv[])
{
    /*
     * 00000000 00000000 00000000 00000001
     * 11111110 11010000 10010000 00000010
     * 00000010 11010000 10010000 00000010
     */
    printf("%s\n", i32_(srl(tou32("10000000 00000000 00000000 00000000"), 31)));
    printf("%s\n", i32(sra(toi32("11011010 00010010 00000000 01010101"), 5)));
    printf("%s\n", i32_(sra(toi32("01011010 00010010 00000000 01010101"), 5)));
}
