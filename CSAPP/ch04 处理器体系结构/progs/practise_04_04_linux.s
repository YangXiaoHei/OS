rsum:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	subq	$24, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	cmpl	$0, -28(%rbp)
	jg	.L2
	movl	$0, %eax
	jmp	.L3
.L2:
	movq	-24(%rbp), %rax
	movq	(%rax), %rbx
	movl	-28(%rbp), %eax
	leal	-1(%rax), %edx
	movq	-24(%rbp), %rax
	addq	$8, %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	rsum
	addq	%rbx, %rax
.L3:
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	ret
