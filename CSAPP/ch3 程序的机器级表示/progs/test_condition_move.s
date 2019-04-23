_fun:                                   ## @fun
	pushq	%rbp
	movq	%rsp, %rbp
	cmpl	%esi, %edi
	cmovgel	%edi, %esi
	movl	%esi, %eax
	popq	%rbp
	retq
