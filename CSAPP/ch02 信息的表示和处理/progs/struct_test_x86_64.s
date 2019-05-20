_main:                                  ## @main
	pushq	%rbp
	movq	%rsp, %rbp
	xorl	%eax, %eax
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$1, -32(%rbp)
	movl	$2, -28(%rbp)
	movl	$3, -24(%rbp)
	popq	%rbp
	retq
