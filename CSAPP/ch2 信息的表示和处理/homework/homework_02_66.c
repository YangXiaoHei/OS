#include <stdio.h>
#include <string.h>
#include "../../bin_tool.h"

int leftmost_one(unsigned x)
{
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    return x;
}

int main(int argc, char *argv[])
{
    unsigned x = tou32("10000000 00000000 00000000 00000000");
    printf("%s\n%s\n\n", strdup(i32_(x)), strdup(i32_(leftmost_one(x))));

    x = tou32("00000100 01011000 10010100 01001000");
    printf("%s\n%s\n\n", strdup(i32_(x)), strdup(i32_(leftmost_one(x))));

    x = tou32("00000010 00100010 00100100 01001000");
    printf("%s\n%s\n\n", strdup(i32_(x)), strdup(i32_(leftmost_one(x))));

    x = tou32("00000000 01001001 00100000 00010000");
    printf("%s\n%s\n\n", strdup(i32_(x)), strdup(i32_(leftmost_one(x))));
}
