#include <stdio.h>

/* long rsum(long *start, int size); */


long rsum(long *start, int size)
{
    if (size <= 0)
        return 0;
    return *start + rsum(start + 1, size - 1);
}

int main(int argc, char *argv[])
{
    long a[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(a) / sizeof(a[0]);
    printf("%ld\n", rsum(a, size));
}
