#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *my_calloc(size_t nmem, size_t size)
{
    if (nmem == 0 || size == 0)
        return NULL;

    size_t nbytes = nmem * size;
    if (nbytes / nmem != size)
        return NULL;

    void *ptr = NULL;
    if ((ptr = malloc(nbytes)) == NULL)
        return NULL;

    memset(ptr, 0, nbytes);
    return ptr;
}

int main(int argc, char *argv[])
{
    int *mem = my_calloc(0x9999999999999999, sizeof(int));
    if (mem == NULL) {
        printf("calloc NULL\n");
        return 0;
    }

    for (int i = 0; i < 100; i++)
        mem[i] = i;

    for (int i = 0; i < 100; i++)
        printf("%d\n", mem[i]);
}
