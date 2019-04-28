	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_find_range
	.p2align	4, 0x90
_find_range:                            ## @find_range
	pushq	%rbp
	movq	%rsp, %rbp          
	xorl	%eax, %eax              ; clean %rax
	xorps	%xmm1, %xmm1            ; clean %xmm1
	ucomiss	%xmm0, %xmm1            ; 0 - x
	ja	LBB0_3                      ; if x < 0  goto LBB0_3 
	movl	$1, %eax                 
	ucomiss	%xmm1, %xmm0            ; x - 0
	jne	LBB0_2                      ; if x > 0 || NaN  
	jnp	LBB0_3                      ; if PF != 1    not NaN this is x == 0
LBB0_2:                             ; x > 0 || NAN
	xorps	%xmm1, %xmm1            ; clean %xmm1 
	xorl	%eax, %eax              ; clean %rax
	ucomiss	%xmm1, %xmm0            ; x - 0
	setbe	%al                     ; NAN then set al == 1 
	orl	$2, %eax                    ; 2 | 1 == 3 %eax is 3     
LBB0_3:                             ; x < 0
	popq	%rbp                 
	retq
	.cfi_endproc


.subsections_via_symbols
