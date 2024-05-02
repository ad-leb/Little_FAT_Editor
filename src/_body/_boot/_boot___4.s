.global		_boot___4


.text
_boot___4:
	movq	%rbp, %rsp

	call	image___load
	call	helpr___get_time

	movq	%rbp, %rdi
	movq	data___procedure, %rsi
	call	*%rsi
	orb	%al, %al
	jnz	L_recover

L_fin:
	xorq	%rdi, %rdi
	movq	$0x3c, %rax
	syscall




L_recover:
	call	image___recover
	jmp	L_fin
