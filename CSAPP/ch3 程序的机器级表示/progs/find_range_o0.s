	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_find_range
	.p2align	4, 0x90
_find_range:                            ## @find_range
	pushq	%rbp
	movq	%rsp, %rbp
	xorps	%xmm1, %xmm1            ; 清空 xmm1
	movss	%xmm0, -4(%rbp)         ; 把参数 0 float 放到 %rbp - 4 上
	ucomiss	-4(%rbp), %xmm1         ; 0 - x
	jbe	LBB0_2                       
	movl	$0, -8(%rbp)
	jmp	LBB0_9
LBB0_2:                             ; x >= 0 || NaN
	xorps	%xmm0, %xmm0            ; 清空 xmm0
	movss	-4(%rbp), %xmm1          
	ucomiss	%xmm0, %xmm1            ; x - 0
	jne	LBB0_4                  
	jp	LBB0_4
	movl	$1, -8(%rbp)            
	jmp	LBB0_8                      ; x == 0
LBB0_4:                             ; x > 0 || NaN 
	xorps	%xmm0, %xmm0            ; 清空 xmm0
	movss	-4(%rbp), %xmm1          
	ucomiss	%xmm0, %xmm1            ; x - 0
	jbe	LBB0_6                      ; NaN
	movl	$2, -8(%rbp)            ; x > 0
	jmp	LBB0_7
LBB0_6:
	movl	$3, -8(%rbp)            ; NaN
LBB0_7:
	jmp	LBB0_8
LBB0_8:
	jmp	LBB0_9
LBB0_9:                             ; x == 0
	movl	-8(%rbp), %eax          ; 返回 1
	popq	%rbp
	retq
