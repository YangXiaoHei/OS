.section __TEXT,__text,regular,pure_instructions
.global _loop

_loop:
    movl %esi, %ecx
    movl $1, %edx
    movl $0, %eax
    jmp .L2
.L3:
    movq %rdi, %r8
    andq %rdx, %r8
    orq %r8, %rax
    salq %cl, %rdx
.L2:
    testq %rdx, %rdx
    jne .L3
    rep
    ret
