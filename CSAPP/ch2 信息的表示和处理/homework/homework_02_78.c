#include <stdio.h>

int divide_power2(int x, int k)
{
    int w = sizeof(x) << 3;
    int sign = x >> (w - 1);
    int bias = (1 << k) - 1;
    bias &= sign;
    return (x + bias) >> k;
}

int main(int argc, char *argv[])
{
    /*
     * -3
     * 3
     * 7
     * -7
     */
    printf("%d\n", divide_power2(-7, 1));
    printf("%d\n", divide_power2(7, 1));
    printf("%d\n", divide_power2(57, 3));
    printf("%d\n", divide_power2(-57, 3));
}
