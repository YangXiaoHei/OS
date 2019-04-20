#include <stdio.h>
#include "bin_tool.h"

int main(int argc, char *argv[])
{
    float a = 1e400f;
    printf("%s\n", f32(a));
}
