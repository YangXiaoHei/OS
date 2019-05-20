_fun:                                   ## @fun
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	$0, -12(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jge	LBB0_3
	movl	-4(%rbp), %eax
	addl	-8(%rbp), %eax
	imull	-12(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB0_1
LBB0_3:
	movl	-12(%rbp), %eax
	popq	%rbp
	retq
