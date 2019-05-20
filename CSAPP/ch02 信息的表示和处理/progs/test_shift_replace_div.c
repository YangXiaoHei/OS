#include <stdio.h>

int negative_div16(int a)
{
    return a < 0 ? (a + 15) >> 4 : a >> 4;
}

int negative_div8(int a)
{
    return a < 0 ? (a + 7) >> 3 : a >> 3;
}

int negative_div4(int a)
{
    return a < 0 ? (a + 3) >> 2 : a >> 2;
}

int div16(int a)
{
    /*
     * 这里采用的技巧是，将 a 的符号位扩展后作为掩码，
     * 如果 a >> 31 是全 1，那么自然 bias 就非 0，否则
     * bias 是 0
     */
    int bias = (a >> 31) & 0xF;
    return (a + bias) >> 4;
}

int div8(int a)
{
    int bias = (a >> 31) & 0x7;
    return (a + bias) >> 3;
}

int div4(int a)
{
    int bias = (a >> 31) & 0x3;
    return (a + bias) >> 2;
}
int main(int argc, char *argv[])
{
    int a = -19;
    printf("%d\n", div16(a));
    printf("%d\n", div8(a));
    printf("%d\n", div4(a));

    int b = 19;
    printf("%d\n", div16(b));
    printf("%d\n", div8(b));
    printf("%d\n", div4(b));
}
