#include <stdio.h>

unsigned f2u(float x)
{
    return *(unsigned *)&x;
}

int float_le(float x, float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return (!(sx ^ sy) && (ux <= uy)) || (sx & 1);
}

int main(int argc, char *argv[])
{
    /*
     * 1
     * 1
     * 0
     * 1
     * 1
     * 0
     */
    printf("%d\n", float_le(-1.0, 1.0));
    printf("%d\n", float_le(1.0, 1.0));
    printf("%d\n", float_le(1.0, -1.0));
    printf("%d\n", float_le(-1.0, 2.0));
    printf("%d\n", float_le(-2.0, 1.0));
    printf("%d\n", float_le(2.0, 1.0));
}
