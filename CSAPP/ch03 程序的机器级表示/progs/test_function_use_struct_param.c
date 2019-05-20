#include <stdio.h>

typedef struct A {
    long a;
    int b;
    double c;
    float d;
    short e;
} A;

void fuck(struct A a)
{
    a.a = 1;
    a.b = 2;
    a.c = 3;
    a.d = 4;  
    a.a = a.a + a.b + a.c + a.d + a.e;
    printf("%d\n", a.a);
}

int main(int argc, char *argv[])
{
    struct A c;
    fuck(c);
    printf("%d\n", c.a);
}
