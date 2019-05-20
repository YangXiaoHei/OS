.LC0:
	.string	"why run here\n"
why_run_here:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$13, %edx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	call	write@PLT
	nop
	popq	%rbp
	ret

my_call:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	why_run_here(%rip), %rax
	movq	%rax, 8(%rbp)
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	ret
.LC1:
	.string	"hello world"

last_call:
.LFB2:
	pushq	%rbp
	movq	%rsp, %rbp
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	nop
	popq	%rbp
	ret

main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	leaq	last_call(%rip), %rax
	movq	%rax, -16(%rbp)
	call	my_call
	movl	$0, %eax
	leave
	ret
