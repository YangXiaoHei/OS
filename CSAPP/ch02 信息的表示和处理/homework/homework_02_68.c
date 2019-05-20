#include <stdio.h>
#include "../../bin_tool.h"

int lower_one_mask(int n)
{
    return (1 << n) - 1;
}

int main(int argc, char *argv[])
{
    printf("1 %s\n", i32(lower_one_mask(1)));
    printf("10 %s\n", i32(lower_one_mask(10)));
    printf("5 %s\n", i32(lower_one_mask(5)));
    printf("9 %s\n", i32(lower_one_mask(9)));
    printf("4 %s\n", i32(lower_one_mask(4)));
    printf("25 %s\n", i32(lower_one_mask(25)));
}
