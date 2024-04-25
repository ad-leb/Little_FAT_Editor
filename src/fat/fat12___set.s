.global		fat12___set


.text
fat12___set:
	pushq	%rdx
	pushq	%rcx
	
	
	movq	%rdi, %rdx
	movq	%rsi, %rcx
	
	call	fat12___reconv12
	movq	%rsi, %rdi
		lodsw
	
	movq	%rcx, %rsi
	test	$0x1, %dx
	jz	L_even


L_odd:	andw	$0x000f, %ax
	shlw	$4, %si
	jmp	L_set
L_even:	andw	$0xf000, %ax
	andw	$0x0fff, %si


L_set:
	orw	%si, %ax
		stosw


L_fin:
	popq	%rcx
	popq	%rdx
	ret
