#include <stdio.h>

void show_bytes(void *vptr, ssize_t nbytes)
{
    unsigned char *ptr = vptr;
    for (int i = nbytes - 1; i >= 0; i--)
        printf("%02x ", ptr[i]);
    printf("\n");
}

int main(int argc, char *argv[])
{
    int a = 2147483647;
/*
 *  7f ff ff ff
 */
    show_bytes(&a, sizeof(a));    
}
