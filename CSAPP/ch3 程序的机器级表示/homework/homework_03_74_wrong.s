	.section	__TEXT,__text,regular,pure_instructions
	.globl	_find_range
_find_range:                              
    xorps %xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
    movl $3, %r8d
    movl $2, %r9d
    movl $1, %r10d
    movl $0, %r11d
    cmovpl %r8d, %eax
    cmoval %r9d, %eax
    cmovel %r10d, %eax
    cmovbl %r11d, %eax
	retq
