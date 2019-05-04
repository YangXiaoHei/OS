	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3
LCPI0_0:
	.quad	4613937818241073152     ## double 3
LCPI0_1:
	.quad	4616189618054758400     ## double 4
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_fuck
	.p2align	4, 0x90
_fuck:                                  ## @fuck
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
	movq	$1, 16(%rbp)
	movl	$2, 24(%rbp)
	movabsq	$4613937818241073152, %rax ## imm = 0x4008000000000000
	movq	%rax, 32(%rbp)
	movl	$1082130432, 40(%rbp)   ## imm = 0x40800000
	movq	16(%rbp), %rax
	addq	$2, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	LCPI0_0(%rip), %xmm0
	addsd	LCPI0_1(%rip), %xmm0
	movswl	44(%rbp), %eax
	cvtsi2sdl	%eax, %xmm1
	addsd	%xmm0, %xmm1
	cvttsd2si	%xmm1, %rsi
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	popq	%rbp
	jmp	_printf                 ## TAILCALL
	.cfi_endproc

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi3:
	.cfi_def_cfa_offset 16
Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi5:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	-8(%rbp), %rax
	movq	%rax, 24(%rsp)
	movq	-16(%rbp), %rax
	movq	%rax, 16(%rsp)
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rcx
	movq	%rcx, 8(%rsp)
	movq	%rax, (%rsp)
	callq	_fuck
	movq	-32(%rbp), %rsi
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	xorl	%eax, %eax
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d\n"


.subsections_via_symbols
