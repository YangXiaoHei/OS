#include <stdio.h>


/*
 * pop %rsp 的行为和下列汇编指令相同:
 * 
 * movq (%rsp), %rax
 * addq $8, %rsp
 * movq %rax, %rsp
 */
int pop_rsp(void);

int main(int argc, char *argv[])
{
    printf("%x\n", pop_rsp());
}
