	.section	__TEXT,__text,regular,pure_instructions
	.globl	_find_range
_find_range:                              
    xorl %eax, %eax
    xorps %xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
    jb .L1
    addl $1, %eax       ; 这些指令改变了标志寄存器的值。。。
    je .L1
    addl $1, %eax
    ja .L1
    addl $1, %eax
.L1:
	retq
