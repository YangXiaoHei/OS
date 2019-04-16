#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 2147483647;
    int b = 10;

    printf("%d\n", (a + b) - a);
    printf("%d\n", (a + b) - b);
}
