#include <stdio.h>
#include "../../bin_tool.h"


int main(int argc, char *argv[])
{

    printf("%d\n", (int)tof32("0 10011110 00000000000000000000000"));
    printf("%f\n", tof32("0 10011110 00000000000000000000000"));
    printf("%d\n", (int)tof32("0 10011111 00000000000000000000000"));
}
