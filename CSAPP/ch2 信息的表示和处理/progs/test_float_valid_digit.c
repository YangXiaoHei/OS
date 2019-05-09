#include <stdio.h>
#include "../../bin_tool.h"

int main(int argc, char *argv[])
{
    unsigned x = 1;
    float y = u2f(x);
    printf("%.200f\n", y);
}
