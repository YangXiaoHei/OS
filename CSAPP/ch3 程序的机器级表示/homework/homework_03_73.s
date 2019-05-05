	.section	__TEXT,__text,regular,pure_instructions
	.globl	_find_range
_find_range:                              
    movl $3, %eax
    xorps %xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
    jp .L1
    movl $2, %eax
    ja .L1
    movl $1, %eax
    je .L1
    xorl %eax, %eax
.L1:
	retq
