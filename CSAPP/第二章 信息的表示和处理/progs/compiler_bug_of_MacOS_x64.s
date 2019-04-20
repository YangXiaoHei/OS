	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.section	__TEXT,__literal4,4byte_literals
	.p2align	2
LCPI0_0:
	.long	1178657792              ## float 12345
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	leaq	L_.str(%rip), %rax
	movss	LCPI0_0(%rip), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movss	%xmm0, -20(%rbp)
	movss	-20(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movss	%xmm0, -32(%rbp)
	movw	-29(%rbp), %cx
	andw	$255, %cx
	movb	%cl, %dl
	movb	%dl, -33(%rbp)
	movzbl	-33(%rbp), %esi
	movq	%rax, %rdi
	movb	$0, %al
	callq	_printf
	xorl	%esi, %esi
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	movl	%esi, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%x\n"


.subsections_via_symbols
