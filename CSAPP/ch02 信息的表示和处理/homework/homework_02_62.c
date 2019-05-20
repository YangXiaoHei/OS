#include <stdio.h>

/*
 * 返回是否采用算术右移
 */
int int_shifts_are_arithmetic(void)
{
    int w = sizeof(int) << 3;
    int a = (1 << (w - 1));
    a >>= 1;
    return (a >> (w - 1)) & 1;
}

int main(int argc, char *argv[])
{
    /*
     * 1
     */
    printf("%d\n", int_shifts_are_arithmetic());
}
