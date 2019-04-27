_why_run_here:                          ## @why_run_here
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	$1, %edi
	leaq	L_.str(%rip), %rsi
	movl	$13, %eax
	movl	%eax, %edx
	callq	_write
	movq	%rax, -8(%rbp)          ## 8-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq

_my_call:                               ## @my_call
	pushq	%rbp
	movq	%rsp, %rbp
	leaq	_why_run_here(%rip), %rax
	movq	$1, -32(%rbp)
	movq	$2, -24(%rbp)
	movq	%rax, 8(%rbp)
	popq	%rbp
	retq

_main:                                  ## @main
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	callq	_my_call
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq

L_.str:                                 ## @.str
	.asciz	"why run here\n"
