#include <stdio.h>
#include "../../bin_tool.h"

int main(int argc, char *argv[])
{
    int a = -12345;
    printf("%s\n", i32(a));
    printf("%d\n", toi32(i32(a)));
    printf("%u\n", tou32(i32(a)));

    float b = -12345;
    printf("%s\n", f32(b));
    printf("%.3f\n",tof32(f32(b)));
}
