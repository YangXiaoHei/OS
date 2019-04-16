#include <stdio.h>

typedef unsigned char *byte_ptr;

/*
 * 这里使用 void * 作为参数，是为了避免编译警告
 * 同时可以避免在调用函数时执行强制类型转换
 */
void show_bytes(void *vptr, ssize_t len)
{
    byte_ptr ptr = vptr;
    /*
     * 0x12345678 从左到右是从高位到低位，即从高地址到低地址
     * 因此想打印出和字面量一样的效果的话，需要从高地址开始
     */
    for (int i = len - 1; i >= 0; i--) {
        printf("%2x", ptr[i]); 
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int a = 0x12345678;
    show_bytes(&a, sizeof(a));
}
