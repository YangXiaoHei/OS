#include <stdio.h>

int main(int argc, char *argv[])
{
    /*
     * 17
     * -7
     * 60
     * -112
     */
    {
        int x = 100;
        int y = x;
        x = (x << 4) + x;
        printf("%d %d\n", x, y * 17);
    }

    {
        int x = 100;
        int y = x;
        x = x - (x << 3);
        printf("%d %d\n", x, y * -7);
    }

    {
        int x = 100;
        int y = x;
        x = (x << 6) - (x << 2);
        printf("%d %d\n", x, y * 60);
    }

    {
        int x = 100;
        int y = x;
        x = (x << 4) - (x << 7);
        printf("%d %d\n", x, y * -112);
    }
    

}
