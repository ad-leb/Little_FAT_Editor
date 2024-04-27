.global		_boot
.global		_boot___0


.text
_boot:
_boot___0:
	movq	%rsp, %rbp
	movq	(%rbp), %rdx

	addq	$8, %rbp
	movq	(%rbp), %rsi
	leaq	data___program_name, %rdi



	movq	$0xff, %rcx
L_copy_loop:
		lodsb
	orb	%al, %al
	jz	L_fin
		stosb

	decq	%rcx
	jnz	L_copy_loop
L_fin:
	movq	%rdi, data___program_name_end



	cmpq	$4, %rdx
	jb	_boot___error_count
L_next:
	addq	$8, %rbp
	jmp	_boot___1
