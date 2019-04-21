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
    int b = -2147483647 - 1;
    unsigned int c = 4294967295;
    int d = 32767;

/*
 *  7f ff ff ff
 *  80 00 00 00
 *  ff ff ff ff
 *  00 00 7f ff
 */
    show_bytes(&a, sizeof(a));    
    show_bytes(&b, sizeof(b));    
    show_bytes(&c, sizeof(c));    
    show_bytes(&d, sizeof(d));    
}
