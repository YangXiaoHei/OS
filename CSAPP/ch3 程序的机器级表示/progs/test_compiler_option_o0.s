	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	leaq	L_.str(%rip), %rax
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$2, -20(%rbp)
	movl	$9, -24(%rbp)
	movl	-24(%rbp), %edi
	xorl	-20(%rbp), %edi
	movl	%edi, -20(%rbp)
	movl	-20(%rbp), %edi
	xorl	-24(%rbp), %edi
	movl	%edi, -24(%rbp)
	movl	-24(%rbp), %edi
	xorl	-20(%rbp), %edi
	movl	%edi, -20(%rbp)
	movl	-20(%rbp), %esi
	movl	-24(%rbp), %edx
	movq	%rax, %rdi
	movb	$0, %al
	callq	_printf
	xorl	%edx, %edx
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	movl	%edx, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d %d\n"


.subsections_via_symbols
