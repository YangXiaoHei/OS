#include <stdio.h>

struct P1 { 
    int i; char c; int j; char d;
};

struct P2 {
    int i; char c; char d; long j;
};

struct P3 {
    short w[3]; char c[3];
};

struct P4 {
    short w[5]; char *c[3];
};

struct P5 {
    struct P3 a[2];
    struct P2 t;
};

struct S2 {
    int i; int j; char c;
};

#define offset(base, x) ((char *)(&(x)) - (char *)(&(base)))

int main(int argc, char *argv[])
{
    struct P5 p5;
    int a = offset(p5, p5.a[1].c); 
    int b = offset(p5, p5.a[1].c[2]); 
    int c = offset(p5, p5.t); 
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
}
