#include <stdio.h>
#include "../../bin_tool.h"

int main(int argc, char * argv[])
{
    unsigned x = 0x40490fab; 
    printf("%s\n", f32(*(float *)&x));

    /*
     * 0 10000000000 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 1
     */
    printf("%s\n", d64(22/7.0));
    printf("%s\n", f32(22/7.0));
    printf("\n");
    printf("%s\n", d64(223/71.0));
}
