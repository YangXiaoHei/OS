#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y)
{
    int w = sizeof(int) << 3;
    int sum = x + y;
    int t = sum;
    sum >>= (w - 1);
    x >>= (w - 1);
    y >>= (w - 1);
    int pos_ovf = ~x & ~y & sum;
    int neg_ovf = x & y & ~sum;
    int no_ovf = ~(pos_ovf | neg_ovf);
    return (pos_ovf & INT_MAX) | (neg_ovf & INT_MIN) | (no_ovf & t);
}

int main(int argc, char *argv[])
{
    printf("%d\n", saturating_add(1, 2147483647));
    printf("%d\n", saturating_add(1, 2));
    printf("%d\n", saturating_add(-1, -2147483648));
}
