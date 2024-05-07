.global		_boot___2


.text
_boot___2:
	movq	(%rbp), %rsi
	leaq	data___image_name, %rdi

	movq	$0xff, %rcx
L_copy_loop:
		lodsb
	orb	%al, %al
	jz	L_fin
		stosb

	loop	L_copy_loop
L_fin:
	movq	%rdi, data___image_name_end


	movq	(%rbp), %rdi
	movq	$2, %rsi
	movq	$2, %rax
	syscall

	cmpq	$-1, %rax
	jle	_boot___error_imagefile
	movq	%rax, data___image_fd

	addq	$8, %rbp
	jmp	_boot___3
