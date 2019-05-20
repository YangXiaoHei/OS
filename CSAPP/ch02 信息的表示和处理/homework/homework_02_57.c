#include <stdio.h>

void show_bytes(void *vptr, ssize_t nbytes)
{
    unsigned char *ptr = vptr;
    for (int i = nbytes - 1; i >= 0; i--)
        printf("%02x ", ptr[i]);
    printf("\n");
}

#define show_method_decl(_type_)    \
void show_##_type_(_type_ a)        \
{                                   \
    show_bytes(&a, sizeof(a));      \
}

show_method_decl(short)
show_method_decl(int)
show_method_decl(long)
show_method_decl(float)
show_method_decl(double)

int main(int argc, char *argv[])
{
    /*
     * 3f 80 00 00
     * 00 01 23 45
     * 00 00 00 99 88 77 66 55
     * 7f ff
     * 40 09 1e b8 51 eb 85 1f
     */
    show_float(1.0);
    show_int(0x12345);
    show_long(0x9988776655);
    show_short(32767);
    show_double(3.14);
}
