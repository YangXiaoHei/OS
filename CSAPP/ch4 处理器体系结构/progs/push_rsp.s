.section    __TEXT,__text,regular,pure_instructions
.global  _push_rsp

_push_rsp:
    movq %rsp, %rax
    push %rsp            
    pop %rdx
    subq %rdx, %rax
    ret
