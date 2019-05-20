#include <stdio.h>
#include <string.h>

int copy_int(int val, void *buf, int maxbytes)
{
    if (maxbytes >= (int)sizeof(int)) {
       memcpy(buf, (void *)&val, sizeof(int));
       return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    char buf[3];
    bzero(buf, sizeof(buf));
    
    if (copy_int(4, buf, sizeof(buf)) != 0) {
        printf("copy fail!\n");
        return 0;
    }

    printf("%d\n", *(int *)buf);

}
