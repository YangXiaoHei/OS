_fuck:                                  ## @fuck
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	leaq	L_.str(%rip), %rdi
	movsd	%xmm0, -16(%rbp)        ## 实部
	movsd	%xmm1, -8(%rbp)         ## 虚部
	movsd	-16(%rbp), %xmm0       
	movb	$1, %al
	callq	_printf
	movsd	-8(%rbp), %xmm0       
	addsd	-16(%rbp), %xmm0
	movl	%eax, -20(%rbp)      
	addq	$32, %rsp
	popq	%rbp
	retq

LCPI1_0:
	.quad	4613937818241073152     ## double 3
LCPI1_1:
	.quad	4607182418800017408     ## double 1
_main:                                  ## @main
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	leaq	L_.str.1(%rip), %rdi
	movsd	LCPI1_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	movsd	LCPI1_1(%rip), %xmm1    ## xmm1 = mem[0],zero
	movsd	%xmm1, -16(%rbp)
	movsd	%xmm0, -8(%rbp)
	movsd	-16(%rbp), %xmm0        ## xmm0 = mem[0],zero
	movsd	-8(%rbp), %xmm1         ## xmm1 = mem[0],zero
	movb	$2, %al
	callq	_printf
	xorl	%ecx, %ecx
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	addq	$32, %rsp
	popq	%rbp
	retq

L_.str:                                 ## @.str
	.asciz	"%f\n"

L_.str.1:                               ## @.str.1
	.asciz	"%f+%fi\n"
