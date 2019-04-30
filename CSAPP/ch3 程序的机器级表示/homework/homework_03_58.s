.section __TEXT,__text,regular,pure_instructions
.global _decode2
_decode2:
    subq %rdx, %rsi
    imulq %rsi, %rdi
    movq %rsi, %rax
    salq $63, %rax
    sarq $63, %rax
    xorq %rdi, %rax
    ret
