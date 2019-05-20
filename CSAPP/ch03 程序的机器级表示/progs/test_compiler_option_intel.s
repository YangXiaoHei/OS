_main:                                  ## @main
	push	rbp
	mov	rbp, rsp
	sub	rsp, 32
	lea	rax, [rip + L_.str]
	mov	dword ptr [rbp - 4], edi
	mov	qword ptr [rbp - 16], rsi
	mov	dword ptr [rbp - 20], 2
	mov	dword ptr [rbp - 24], 9
	mov	edi, dword ptr [rbp - 24]
	xor	edi, dword ptr [rbp - 20]
	mov	dword ptr [rbp - 20], edi
	mov	edi, dword ptr [rbp - 20]
	xor	edi, dword ptr [rbp - 24]
	mov	dword ptr [rbp - 24], edi
	mov	edi, dword ptr [rbp - 24]
	xor	edi, dword ptr [rbp - 20]
	mov	dword ptr [rbp - 20], edi
	mov	esi, dword ptr [rbp - 20]
	mov	edx, dword ptr [rbp - 24]
	mov	rdi, rax
	mov	al, 0
	call	_printf
	xor	edx, edx
	mov	dword ptr [rbp - 28], eax ## 4-byte Spill
	mov	eax, edx
	add	rsp, 32
	pop	rbp
	ret
L_.str:                                 ## @.str
	.asciz	"%d %d\n"
