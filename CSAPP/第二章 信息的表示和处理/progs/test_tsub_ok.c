#include <stdio.h>
#include "bin_tool.h"

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX-1)

int tadd_ok(int x, int y)
{
    return (x^y) > 0 && ((x+y)^x) < 0;
}

int buggy_tsub_ok(int x, int y)
{
    /*
     * 当 y == INT_MIN 时，若 x < 0，那么相当于 -1+2147483648 <= INT_MAX
     * 因此不会溢出，当 x > 0 时，相当于 1+2147483648 < 0 正溢出
     * 因此 y == INT_MIN 需要单独作处理
     */
    return tadd_ok(x, -y);
}

int tsub_ok(int x, int y)
{
    /*
     * 若 x == 0，那么若 y == INT_MIN，此时也会发生溢出，因为 |TMAX| + 1 = |TMIN|, x+2147483648 < 0
     */
    if (y == INT_MIN)
        return x > 0;
    return tadd_ok(x, -y);
}

int main(int argc, char *argv[])
{
    /*
     * 2147483647
     * -2147483649
     * 2147483647
     * -2147483647
     * 01111111 11111111 11111111 11111111
     * ----- wrong answer -------
     * 0
     * 1
     * ----- correct answer -------
     * 1
     * 0
     */
    printf("%d\n", -1 - INT_MIN);
    printf("%ld\n", -1 - 2147483648);
    printf("%d\n", -1 - 2147483648);
    printf("%d\n", 1 - 2147483648);
    printf("%s\n", u32ToBinaryString(-1-2147483648, eight));

    printf("----- wrong answer -------\n");
    
    /*
     * 1-(-2147483648) = 1+2147483648=-2147483647 产生负溢出
     * 但 buggy_tsub_ok 将返回 0
     */
    printf("%d\n", buggy_tsub_ok(1, INT_MIN));

    /*
     * -1 - (-2147483648) = -1+2147483648 = 2147483647
     * 因此，这没有溢出, 但是 buggy_tsub_ok 将返回 1
     */
    printf("%d\n", buggy_tsub_ok(-1, INT_MIN));

    printf("----- correct answer -------\n");
    printf("%d\n", tsub_ok(1, INT_MIN));
    printf("%d\n", tsub_ok(-1, INT_MIN));
}
