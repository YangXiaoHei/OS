#include <stdio.h>

int main(int argc, char *argv[])
{
    long a = 4294967295;
    long b = 10;

    /*
     * 补码乘法溢出后的值：
     * 等于
     * 先将两个数转成无符号相乘，最后将结果转成补码
     */
    int c = (int)(a * b);
    int d = (int)((unsigned)a * (unsigned)b);
    int e = (a * b) % (1L << 32);

    printf("%d\n", c == d);
    printf("%d\n", e == d);
}
