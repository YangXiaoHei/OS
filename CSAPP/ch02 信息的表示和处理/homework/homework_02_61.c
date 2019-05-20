#include <stdio.h>
#include "../../bin_tool.h"

int A(int x)
{
    /*
     * 如果 x 的所有位都为 1，那么 ~x 肯定为 0
     */
    return !~x;
}

int B(int x)
{
    return !x;
}

int C(int x)
{
    /*
     * 这里如果写成 !~(unsigned char)(x & 0xff) 就不行
     * 因为对一个小整形做 ~、-、+、- 等任何运算
     * 小整形先被提升为 int
     * 比如如果按照上面的写法，0xaa 先被强转为 unsigned char
     * 然而当接下来执行 ~ 时，被提升为 int，即 0x000000aa (a 代表任意数)
     * 然后取 ~，则是 0xffffffbb ( b 代表任意数)
     * 于是最后取 !，就得到 0
     */
    return !(unsigned char)~(x & 0xff);
}

int D(int x)
{
    int nshift = (sizeof(int) - 1) << 3;
    return !(unsigned char)((x >> nshift) & 0xff);
}

int main(int argc, char *argv[])
{
    /*
     * 0
     * 1
     *
     * 0
     * 1
     *
     * 0
     * 1
     *
     * 0
     * 1
     */
    printf("%d\n", A(toi32("11111111 11111111 11111111 11111110")));
    printf("%d\n", A(toi32("11111111 11111111 11111111 11111111")));

    printf("%d\n", B(toi32("00000000 11111111 11111111 11111110")));
    printf("%d\n", B(toi32("00000000 00000000 00000000 00000000")));

    printf("%d\n", C(toi32("00000000 00000000 00100000 11101111")));
    printf("%d\n", C(toi32("00000000 00000000 00000000 11111111")));

    printf("%d\n", D(toi32("00001000 00110010 10010100 11101011")));
    printf("%d\n", D(toi32("00000000 00101000 11111100 10111111")));
}
