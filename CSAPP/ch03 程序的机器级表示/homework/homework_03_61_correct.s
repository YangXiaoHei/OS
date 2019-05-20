.section __TEXT,__text,regular,pure_instructions
.global _cread

# 下面是手写的汇编代码
_cread:
    subq $8, %rsp
    movq $0, (%rsp)
    movq %rsp, %rax
    testq %rdi, %rdi
    cmovneq %rdi, %rax
    movq (%rax), %rax
    addq $8, %rsp
    ret
