#include <stdio.h>

int tadd_ok(int x, int y)
{
    return (x ^ y) > 0 && ((x + y) ^ x) < 0;
}

int main(int argc, char *argv[])
{
    printf("%d\n", tadd_ok(1, 0xFFFFFFFF));
    printf("%d\n", tadd_ok(-1, 2147483647));
    printf("%d\n", tadd_ok(1, 2147483647));
    printf("%d\n", tadd_ok(-1, -2147483647-1));
}
