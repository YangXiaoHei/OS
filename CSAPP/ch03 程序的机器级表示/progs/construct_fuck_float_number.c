#include <stdio.h>
#include "../../bin_tool.h"

int main(int argc, char *argv[])
{
    float i = 33554432.9;
    float j = 33554432.1;

    float k = 8388608.9;
    float m = 8388608.1;
    printf("%d\n", k > m);

    float p = 8388608.51;
    printf("%d\n", k > p);

    int c = (1 << 24) + 1;
    float d = c;
    printf("%d %f\n", c, d);
}
