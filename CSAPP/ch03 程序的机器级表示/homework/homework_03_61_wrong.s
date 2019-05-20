.section __TEXT,__text,regular,pure_instructions
.global _cread

_cread:
    xorl %eax, %eax
    testq %rdi, %rdi
    cmovneq (%rdi), %rax    ; 这里即使条件判断为假也会取 %rdi 内存地址的值然后非法内存访问
    ret
