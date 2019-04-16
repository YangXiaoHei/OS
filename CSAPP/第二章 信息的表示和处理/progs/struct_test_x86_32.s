	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	8(%ebp), %ecx
	xorl	%edx, %edx
	movl	%ecx, -4(%ebp)
	movl	%eax, -8(%ebp)
	movl	$1, -24(%ebp)
	movl	$2, -20(%ebp)
	movl	$3, -16(%ebp)
	movl	%edx, %eax
	addl	$24, %esp
	popl	%ebp
	retl


.subsections_via_symbols
