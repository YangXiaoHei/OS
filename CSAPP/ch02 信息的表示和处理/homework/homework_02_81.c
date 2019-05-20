#include <stdio.h>
#include "../../bin_tool.h"

int main(int argc, char *argv[])
{
    {
        int k = 10;
        printf("%s\n", i32_(-1 << k)); 
    }

    {
        int k = 10;
        int j = 4;
        printf("%s\n", i32_(((1 << k) - 1) << j));
    }
}
