_cread:                                 ## @cread
	pushq	%rbp
	movq	%rsp, %rbp
	movq	$0, -8(%rbp)
	testq	%rdi, %rdi
	leaq	-8(%rbp), %rax
	cmovneq	%rdi, %rax
	movq	(%rax), %rax
	popq	%rbp
	retq

_disassembly_cread:                     ## @disassembly_cread
	pushq	%rbp
	movq	%rsp, %rbp
	testq	%rdi, %rdi
	je	LBB1_1
	movq	(%rdi), %rax
	popq	%rbp
	retq
LBB1_1:
	xorl	%eax, %eax
	popq	%rbp
	retq

_main:                                  ## @main
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	pushq	%rax
	leaq	L_.str(%rip), %rbx
	xorl	%esi, %esi
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	xorl	%esi, %esi
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	xorl	%eax, %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq

L_.str:                                 ## @.str
	.asciz	"%ld\n"


.subsections_via_symbols
