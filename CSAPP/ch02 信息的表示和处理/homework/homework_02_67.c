#include <stdio.h>
#include "../../bin_tool.h"

int bad_int_size_is_32(void)
{
    int set_msb = 1 << 31;
    int beyond_msb = 1 << 32; /* 32 位机器没有定义左移 32 位 */
    return set_msb && !beyond_msb;
}

int int_size_is_32_16(void)
{
    int set_msb = 1 << 15;
    set_msb <<= 15;
    set_msb <<= 1;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

int int_size_is_32_32(void)
{
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

int main(int argc, char *argv[])
{
    printf("bad %d\n", bad_int_size_is_32());
    printf("%d\n", int_size_is_32_16());
    printf("%d\n", int_size_is_32_32());
}
