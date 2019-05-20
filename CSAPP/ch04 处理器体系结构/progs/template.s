	.section	__TEXT,__text,regular,pure_instructions
	.global	_fuck
_fuck:                                  ## @fuck
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	addl	$2, %edi
	movl	%edi, %eax
	popq	%rbp
	retq

	.global	_main
_main:                                  ## @main
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$1, -20(%rbp)
	movl	-20(%rbp), %edi
	movl	-20(%rbp), %eax
	movl	%edi, -24(%rbp)         ## 4-byte Spill
	movl	%eax, %edi
	callq	_fuck
	leaq	L_.str(%rip), %rdi
	movl	-24(%rbp), %ecx         ## 4-byte Reload
	addl	%eax, %ecx
	movl	%ecx, %esi
	movb	$0, %al
	callq	_printf
	xorl	%ecx, %ecx
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	addq	$32, %rsp
	popq	%rbp
	retq

L_.str:                                 ## @.str
	.asciz	"%d\n"
