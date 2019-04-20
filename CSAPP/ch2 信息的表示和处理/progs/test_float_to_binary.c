#include <stdio.h>
#include "bin_tool.h"

int main(int argc, char *argv[])
{
    float a = 12345;
    float b = 12345.5;
    float c = 12345.875;
    float d = 12345.9375;
    float e = 0.1;
    printf("%x\n", *(int *)&e);

    printf("%s\n", f32(a));
    printf("%s\n", f32(b));
    printf("%s\n", f32(c));
    printf("%s\n", f32(d));
    printf("%s\n", f32(e));
}
