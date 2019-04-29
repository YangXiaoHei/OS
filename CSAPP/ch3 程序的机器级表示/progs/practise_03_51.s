_cvt:                                   ## @cvt
	pushq	%rbp
	movq	%rsp, %rbp
	cvtss2sd	%xmm0, %xmm0
	popq	%rbp
	retq

_cvt1:                                  ## @cvt1
	pushq	%rbp
	movq	%rsp, %rbp
	cvttss2si	%xmm0, %rax
	popq	%rbp
	retq

_cvt2:                                  ## @cvt2
	pushq	%rbp
	movq	%rsp, %rbp
	cvtsi2ssq	%rdi, %xmm0
	popq	%rbp
	retq
