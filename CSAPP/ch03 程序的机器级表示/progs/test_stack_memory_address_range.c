#include <stdio.h>

int main(int argc, char *argv[])
{
    int local;
    printf("%ld %lx\n",(long)&local, (long)&local);
}
