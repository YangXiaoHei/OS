#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 1, b = 4;
    /* printf("a=%d b=%d\n", a, b); */
    a ^= b;          /* a = a ^ b */
    b ^= a;         /*  b = b ^ (a ^ b) = a*/
    a ^= b;         /*  a = (a ^ b) ^ a = b*/
    /* printf("a=%d b=%d\n", a, b); */
}
