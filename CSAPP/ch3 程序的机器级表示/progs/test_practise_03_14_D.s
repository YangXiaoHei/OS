_test:                                  ## @test
	pushq	%rbp
	movq	%rsp, %rbp
	xorl	%eax, %eax
	testl	%edi, %edi
	setne	%al
	popq	%rbp
	retq
