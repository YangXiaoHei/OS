#include <stdio.h>

int i32_tmul_ok(int x, int y)
{
    int q = x * y;
    return x == 0 || q / x == y;
}

int i64_tmul_ok(long x, long y)
{
    long q = x * y;
    return x == 0 || q / x == y;
}

int main(int argc, char *argv[])
{
    /*
     * i32 max n = 12
     * i64 max n = 20
     */
    int i32_result = 1;
    int n;
    for (n = 1; i32_tmul_ok(i32_result, n); ++n)
        i32_result *= n; 

    printf("i32 max n = %d\n", --n);

    long i64_result = 1;
    for (n = 1; i64_tmul_ok(i64_result, n); ++n)
        i64_result *= n; 

    printf("i64 max n = %d\n", --n);
}
