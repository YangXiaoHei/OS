#include <stdio.h>
#include "../../bin_tool.h"

int find_range(float x);

int main(int argc, char *argv[])
{
    /*
     * 2
     * 0
     * 2
     * 1
     * 3
     * 2
     */
    printf("%d\n", find_range(1.0));
    printf("%d\n", find_range(-1.0));
    printf("%d\n", find_range(2.0));
    printf("%d\n", find_range(0));
    printf("%d\n", (find_range(tof32("0 11111111 01000000000000000000000"))));
    printf("%d\n", (find_range(tof32("0 11111111 00000000000000000000000"))));
}
