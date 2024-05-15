.global		_boot
.global		_boot___0


.text

_boot:
# _boot 	-- start of all execution 


_boot___0:
#	1. Save name of program in "data___program_name";
#	2. Check count of command lines' args;


	movq	%rsp, %rbp
	movq	(%rbp), %rdx					# < argc >
	addq	$8, %rbp					# < next arg >


	movq	(%rbp), %rsi					# < argv[0] >
	leaq	data___program_name, %rdi
	movq	$0xff, %rcx					# stirng limit = 255 bytes
L_copy_loop:
		lodsb
	orb	%al, %al					# < while ( c != '\0' ) >
	jz	L_fin
		stosb

	loop	L_copy_loop
L_fin:
	movq	%rdi, data___program_name_end



	cmpq	$4, %rdx					# check if argc < 4; error handler use "data___program_name", so this 
	jb	_boot___error_count				# 	name must be ready before it will be used in case  of error
L_next:
	addq	$8, %rbp					# < next arg >
	jmp	_boot___1
