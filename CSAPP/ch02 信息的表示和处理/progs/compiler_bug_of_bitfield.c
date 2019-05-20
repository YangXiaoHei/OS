#include <stdio.h>

typedef struct float_t {
    unsigned int m : 23;
    unsigned char e : 8;   
  //unsigned short e : 8;   这样是对的
    unsigned char s : 1;
} float_t;

int main(int argc, char *argv[])
{
    /* 0 10001100 10000001110010000000000  */
    float a = 12345;
    union {
        float f;
        struct float_t ft;
    } uf;
    uf.f = a;

    unsigned char b = uf.ft.e;
    if (b == 0x8C) 
        printf("right!\n");
    else
        printf("wrong! result=%x\n", b);
}
