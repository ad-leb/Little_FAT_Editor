.global		_boot___3



.text

_boot___3:
#	1. Check parameters;
#	2. Open descriptor of image by it's name, save it in "data___image_fd";                            yeah, looks little ugly


L_look_for_params:
	movq	(%rbp), %rsi					# < argv[3] and more >
	orq	%rsi, %rsi
	jz	L_open_image
		lodsb
	cmpb	$0x2d, %al					# '-'
	jnz	L_open_image


L_check_param:
		lodsb
L_no:
	orb	%al, %al
	jz	L_fin
L_if_its_clear:
	cmpb	$0x63, %al					# 'c'
	jz	L_clear_case
L_if_its_verbose:
	cmpb	$0x76, %al					# 'v'
	jz	L_verbose_case
L_if_its_decprint:
	cmpb	$0x64, %al					# 'd'
	jz	L_decprint_case
L_unknown_param:
	jmp	_boot___error_param



L_clear_case:
	orb	$0x01, data___params
	clc
	jmp	L_check_param
L_verbose_case:
	orb	$0x02, data___params
	clc
	jmp	L_check_param
L_decprint_case:
	orb	$0x04, data___params
	clc
	jmp	L_check_param


L_fin:
	addq	$8, %rbp					# < next_arg >
	jmp	L_look_for_params








L_open_image:
	leaq	data___image_name,  %rdi
	movq	data___image_flags, %rsi
	movq	data___image_perms, %rdx
	movq	$2, %rax
	syscall							# < open(argv[2], _data___image_flags, _data___image_perms) >

	cmpb	$-1, %al
	jle	_boot___error_imagefile
	movq	%rax, data___image_fd






L_next:
	jmp	_boot___4
