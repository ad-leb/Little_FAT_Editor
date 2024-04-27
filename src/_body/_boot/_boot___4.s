.global		_boot___4


.text
_boot___4:
	movq	(%rbp), %rdi
	movq	data___procedure, %rsi
	call	*%rsi

	movq	$0x3c, %rax
	syscall
