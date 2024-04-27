.global		_boot___2


.text
_boot___2:
	movq	(%rbp), %rdi
	movq	$2, %rsi
	movq	$2, %rax
	syscall

	cmpq	$-1, %rax
	jle	_boot___error_imagefile
	movq	%rax, data___image_fd

	addq	$8, %rbp
	jmp	_boot___3
