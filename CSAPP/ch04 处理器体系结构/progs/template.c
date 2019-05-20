#include <stdio.h>

int fuck(int a)
{
    return a + 2;
}

int main(int argc, char *argv[])
{
    int a = 1;
    printf("%d\n", a + fuck(a));
}
