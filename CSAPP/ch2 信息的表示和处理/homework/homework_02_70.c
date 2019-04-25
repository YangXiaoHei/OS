#include <stdio.h>
#include "../../bin_tool.h"

int fits_bits(int x, int n)
{
    int w = sizeof(x) << 3;
    int nshift = w - n;
    int nth_sign_explain = (x << nshift) >> nshift;
    return !(nth_sign_explain ^ x);
}

int main(int argc, char *argv[])
{
    /*
     * 0
     * 1
     * 1
     * 0
     */
    printf("%d\n", fits_bits(5, 3));
    printf("%d\n", fits_bits(-4, 3));
    printf("%d\n", fits_bits(3, 3));
    printf("%d\n", fits_bits(4, 3));
    
}
