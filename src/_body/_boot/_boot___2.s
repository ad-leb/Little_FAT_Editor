.global		_boot___2


.text

_boot___2:
#	1. Save name of image in "data___image_name";


	movq	(%rbp), %rsi					# < argv[2] >
	leaq	data___image_name, %rdi
	movq	$0xff, %rcx					# string limit = 255 bytes
L_copy_loop:
		lodsb
	orb	%al, %al					# < while (c != '\0' ) >
	jz	L_fin
		stosb

	loop	L_copy_loop
L_fin:
	movq	%rdi, data___image_name_end



L_next:
	addq	$8, %rbp					# < next_arg >
	jmp	_boot___3
