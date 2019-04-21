#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 2, b = 9;
    a ^= b;
    b ^= a;
    a ^= b;

    printf("%d %d\n", a, b);
}
