	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$20, %esp
	movl	12(%ebp), %eax          ; argv
	movl	8(%ebp), %ecx           ; argc
	xorl	%edx, %edx              ; 清空 edx
	movl	%ecx, -4(%ebp)          
	movl	%eax, -8(%ebp)
	movl	$1, -12(%ebp)           
	movl	$4, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	%edx, %eax
	addl	$20, %esp
	popl	%ebp
	retl


.subsections_via_symbols
