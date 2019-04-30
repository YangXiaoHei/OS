#include <stdio.h>

void A(void)
{
    /*
     * ❌
     * 比如 x == INT_MIN 时，
     * y > 0, 此时 x < 0，但 -x == INT_MIN，
     * -y > 0, 因此 -x < -y
     */
}

void B(void)
{
    /* ✅
     * (x + y) << 4 + y - x = x << 4 + y << 4 + y - x = 17 * y + 15 * x 
     */
}

void C(void)
{
    /*
     * ✅
     * 恒成立
     * ~x + ~y + 1 = ~x + 1 + ~y + 1 - 1 = -x + -y - 1 = -(x + y) - 1 = ~(x + y)
     */
}

void D(void)
{
    /* ✅
     * 恒成立, 二进制位模式都是一致的，没有涉及到类型提升符号扩展
     */
}

void E(void)
{
    /*
     * ✅
     * 如果 x > 0
     * 要么发生舍入，此时 (x >> 2) << 2 < x
     * 如果不发生舍入，此时 (x >> 2) << 2 == x
     * 如果 x < 0
     * 当发生舍入时，此时 (x >> 2) << 2 < x, 如果加上偏置的话就不对咯
     * 如果不发生舍入，那么 (x >> 2) << 2 == x
     */

    int x = -9;
    printf("%d\n", (x >> 2) << 2);
    printf("%d\n", ((x >> 2) << 2) <= x);
}

int main(int argc, char *argv[])
{
    E();
}
