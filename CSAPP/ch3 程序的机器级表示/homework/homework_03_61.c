#include <stdio.h>

/* long cread(long *xp); */

long cread(long *xp)
{
    long t = 0;
    xp = xp ? xp : &t;
    return *xp;
}

long disassembly_cread(long *xp)
{
    return (xp ? *xp : 0);
}

int main(int argc, char *argv[])
{
    printf("%ld\n", disassembly_cread(0));
    printf("%ld\n", cread(0));

    long a = 1;
    printf("%ld\n", disassembly_cread(&a));
    printf("%ld\n", cread(&a));
}
