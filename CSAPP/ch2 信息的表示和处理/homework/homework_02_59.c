#include <stdio.h>
#include "../../bin_tool.h"

int lowestx_or_highesty(int x, int y)
{
    return (x & 0xff) | (y & 0xffffff00);
}

int main(int argc, char *argv[])
{
    /*
     * 76 54 32 ef
     */
   show_int(lowestx_or_highesty(0x89ABCDEF, 0x76543210));
}
