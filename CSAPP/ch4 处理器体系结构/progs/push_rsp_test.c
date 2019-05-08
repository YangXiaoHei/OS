#include <stdio.h>

/*
 * push %rsp 的行为和下面汇编指令相同
 * 
 * movq %rsp, %rax
 * push %rax
 */
int push_rsp(void);

int main(int argc, char *argv[])
{
    printf("%d\n", push_rsp());
}
