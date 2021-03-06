#include <stdio.h>
#include "../../bin_tool.h"

int odd_ones(unsigned x)
{
/*
 *     将 x 看作一堆 0 1 的集合，把 1 两两相消，那么如果最后剩一个单独的 1，
 *     1 的个数肯定是奇数，否则是偶数。因此，先把 x 高位和低位异或，比如 
 *     1011 0101 先把高 4 位和低 4 位异或，如下
 * 
 *     1011
 *     0101
 *     ----
 *     1110  --> 消除了一对(第 0 个和第 4 个)，而没有被消除的 1，都
 *               被保留到了异或后的结果中，接着，再异或，如下
 * 
 *     11
 *     10
 *     --
 *     01   --> 消除了一对(第 1 个和第 3 个)，而没有被消除的 1，都被
 *              保留到了异或后的结果中，接着，再异或，如下
 * 
 *     0
 *     1
 *     -
 *     1    --> 剩下一个单独的 1，说明在 1011 0101 中 1 的个数是奇数
 */
    x ^= (x >> 16);
    x ^= (x >> 8);
    x ^= (x >> 4);
    x ^= (x >> 2);
    x ^= (x >> 1);
    return x & 1;
}

int main(int argc, char *argv[])
{
    /*
     * 0
     * 0
     * 0
     * 1
     * 0
     */
    printf("%d\n", odd_ones(tou32("10001010 01010111 00001000 01100000")));
    printf("%d\n", odd_ones(tou32("10000000 00000000 00000000 00110000")));
    printf("%d\n", odd_ones(tou32("10000010 00000100 01010010 01000000")));
    printf("%d\n", odd_ones(tou32("10011100 01001001 00100110 00100100")));
    printf("%d\n", odd_ones(tou32("10000101 01010001 00111000 01110100")));
}
