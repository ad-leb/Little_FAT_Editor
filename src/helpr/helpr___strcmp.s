.global		helpr___strcmp


.text
helpr___strcmp:
	cmpq	$8, %rdx
	jl	L_byte_cmp
	movq	%rdx, %rcx
	andq	$0b0111, %rdx

L_quad_cmp:
	shrq	$3, %rcx
	repe	cmpsq
	jnz	L_not_full
L_byte_cmp:
	movq	%rdx, %rcx
	repe	cmpsb
	jnz	L_not_full

L_done:
	xorq	%rax, %rax
L_fin:
	ret






L_not_full:
	decq	%rsi
		lodsb
	jmp	L_fin
