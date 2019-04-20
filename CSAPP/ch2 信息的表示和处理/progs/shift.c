#include <stdio.h>

int main(int argc, char *argv[])
{
    int val = 0x12345678 << 32;

    printf("%x\n", val);
}
