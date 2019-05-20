	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	12(%ebp), %eax
	movl	8(%ebp), %ecx
	xorl	%edx, %edx          ; 清空 edx
	movl	%ecx, -4(%ebp)      
	movl	%eax, -8(%ebp)
	movl	$1, -12(%ebp)           ; a 
	movl	$4, -16(%ebp)           ; b
	movl	-16(%ebp), %eax
	xorl	-12(%ebp), %eax         
	movl	%eax, -12(%ebp)         ; a = a^b 
	movl	-12(%ebp), %eax         
	xorl	-16(%ebp), %eax          
	movl	%eax, -16(%ebp)         ; b = (a^b)^b = a
	movl	-16(%ebp), %eax
	xorl	-12(%ebp), %eax         ; a^(a^b) = b
	movl	%eax, -12(%ebp)         ; a = b
	movl	%edx, %eax
	addl	$16, %esp
	popl	%ebp
	retl


.subsections_via_symbols
