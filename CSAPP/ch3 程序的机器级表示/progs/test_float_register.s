	.file	"test_float_register.c"
	.text
	.globl	fun
	.type	fun, @function
fun:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movsd	%xmm0, -8(%rbp)
	movss	%xmm1, -12(%rbp)
	movl	%edi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cvtsi2ss	-16(%rbp), %xmm0
	addss	-12(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movsd	-8(%rbp), %xmm1
	divsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	cvtsi2sdq	-24(%rbp), %xmm1
	subsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	fun, .-fun
	.globl	funct
	.type	funct, @function

funct:
	pushq	%rbp
	movq	%rsp, %rbp
	movsd	%xmm0, -8(%rbp)         ; d1
	movss	%xmm1, -12(%rbp)        ; f2
	movsd	%xmm2, -24(%rbp)        ; d3
	movl	%edi, -16(%rbp)         ; i4
	cvtss2sd	-12(%rbp), %xmm0    ; f2 -> d2 : float -> double 
	mulsd	-8(%rbp), %xmm0         ; xmm0 stores d1 * d2
	cvtsi2sd	-16(%rbp), %xmm1    ; i4 -> d4 : int -> double 
	movsd	-24(%rbp), %xmm2        ; xmm2 stores d3
	divsd	%xmm1, %xmm2            ; xmm2 stores d3 / d4
	movapd	%xmm2, %xmm1            ; xmm1 stores d3 / d4 
	subsd	%xmm1, %xmm0            ; xmm0 stores d1 * d2 - d3 / d4
	popq	%rbp
	ret
.LC2:
	.string	"%.2f\n"

main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movq	.LC0(%rip), %rax
	movl	$200, %esi
	movl	$1000, %edi
	movss	.LC1(%rip), %xmm1
	movq	%rax, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	call	fun
	cvtss2sd	%xmm0, %xmm0
	leaq	.LC2(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	1374389535
	.long	1074339512
	.align 4
.LC1:
	.long	1092154819
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
