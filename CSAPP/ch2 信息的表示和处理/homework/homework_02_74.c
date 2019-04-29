#include <stdio.h>

/*
 * buggy code, first try but cause a bug when x = -1 and y = -2147483648
 * int tsub_ok(int x, int y)
 * {
 *     int w = sizeof(int) << 3;
 *     int negy = ~y + 1;
 *     int t = x + negy;
 *     t >>= (w - 1); 
 *     negy >>= (w - 1);
 *     x >>= (w - 1);
 *     int pos_ovf = ~x & ~negy & t;
 *     int neg_ovf = x & negy & ~t;
 *     return pos_ovf || neg_ovf;
 * }
 */

int tsub_ok(int x, int y)
{
    int w = sizeof(int) << 3;
    int t = x - y;
    t >>= (w - 1);
    x >>= (w - 1);
    y >>= (w - 1);
    return (x ^ y) && !(t ^ y);   
}

int main(int argc, char *argv[])
{
    printf("%d\n", tsub_ok(1, -2147483647-1));
    printf("%d\n", tsub_ok(-1, -2147483647-1));
    printf("%d\n", tsub_ok(-3, 2147483647));
}
