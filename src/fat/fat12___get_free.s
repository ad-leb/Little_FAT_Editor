.global		fat12___get_free


.text
fat12___get_free:
	pushq	%rbx
	pushq	%rdi
	pushq	%rsi


	movq	$3, %rbx
L_step:
	inc	%rbx
	
	movq	%rbx, %rdi
	call	fat12___reconv12
		lodsw
	
	call	fat12___conv12
	orw	%ax, %ax
	jnz	L_step

L_done:
	movq	%rbx, %rax
L_fin:
	popq	%rsi
	popq	%rdi
	popq	%rbx
	ret
