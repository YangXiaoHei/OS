_A:                                     ## @A
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	leaq	L_.str(%rip), %rdi
	movl	$-255, -4(%rbp)
	movl	-4(%rbp), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq

_B:                                     ## @B
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	leaq	L_.str(%rip), %rdi
	movl	$1, -4(%rbp)
	movl	-4(%rbp), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq

_C:                                     ## @C
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	leaq	L_.str(%rip), %rdi
	movl	$-1, -4(%rbp)
	movl	-4(%rbp), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq

_D:                                     ## @D
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	leaq	L_.str(%rip), %rdi
	movl	$-1, -4(%rbp)
	movl	-4(%rbp), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq
	
_E:                                     ## @E
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	leaq	L_.str(%rip), %rdi
	movl	$128, -4(%rbp)
	movl	-4(%rbp), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq

_main:                                  ## @main
	pushq	%rbp
	movq	%rsp, %rbp
	xorl	%eax, %eax
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	popq	%rbp
	retq

L_.str:                                 ## @.str
	.asciz	"%x\n"
