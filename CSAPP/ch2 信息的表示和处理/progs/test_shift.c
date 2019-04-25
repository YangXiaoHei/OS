#include <stdio.h>

int main(int argc, char *argv[])
{
    int val = 0x1 << 31;
    val <<= 1;

    printf("%x\n", val);
}
