#include <stdio.h>

int tmult_ok(int x, int y)
{
    int64_t q = (int64_t)x * y;
    return q == (int32_t)q;
}

int tmult_ok_book(int x, int y)
{
    int q = x * y;
    return x == 0 || q / x == y;
}

int main(int argc, char *argv[])
{
    /*
     * 0
     * 0
     * 0
     * 0
     * 1
     * 1
     */
    printf("%d\n", tmult_ok_book(10, 2137483647));
    printf("%d\n", tmult_ok(10, 2137483647));

    printf("%d\n", tmult_ok_book(12345678, 9999999));
    printf("%d\n", tmult_ok(12345678, 9999999));

    printf("%d\n", tmult_ok_book(10, 214748364));
    printf("%d\n", tmult_ok(10, 214748364));
}
