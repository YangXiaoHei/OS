#include <stdio.h>
#include "../../bin_tool.h"

int any_odd_one(unsigned x)
{
    return !~(0x55555555 | x);
}

int main(int argc, char *argv[])
{
    /*
     * 1
     * 0
     * 1
     */
   printf("%d\n", any_odd_one(tou32("10101010 10101010 10101010 10101010")));
   printf("%d\n", any_odd_one(tou32("10101010 10101010 10101010 00101010")));
   printf("%d\n", any_odd_one(tou32("10101010 10101010 11111111 10101010")));
}
