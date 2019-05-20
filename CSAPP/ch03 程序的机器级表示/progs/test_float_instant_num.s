LCPI0_0:
	.quad	4629700416936869888     ## double 32
LCPI0_1:
	.quad	4610785298501913805     ## double 1.8
_cel2fahr:                              ## @cel2fahr
	pushq	%rbp
	movq	%rsp, %rbp
	movsd	LCPI0_0(%rip), %xmm1    ## xmm1 = mem[0],zero
	movsd	LCPI0_1(%rip), %xmm2    ## xmm2 = mem[0],zero
	movsd	%xmm0, -8(%rbp)
	mulsd	-8(%rbp), %xmm2
	addsd	%xmm1, %xmm2
	movaps	%xmm2, %xmm0
	popq	%rbp
	retq
