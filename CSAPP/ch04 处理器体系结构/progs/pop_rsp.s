.section    __TEXT,__text,regular,pure_instructions
.global _pop_rsp

_pop_rsp:
    movq %rsp, %rdi
    pushq $0xabcd
    popq %rsp
    movq %rsp, %rax
    movq %rdi, %rsp
    ret

