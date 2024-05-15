.global		helpr___atoi

# int		helpr___atoi (unsigned char* ARRAY);

#	Classic atoi: convert array number (string) to integer.


.text
#***************************************************************
#			atoi
#_______________________________________________________________
# input:	rdi -- string of array number [ARRAY] (0 ended);
# output:	rax -- converted integer
#***************************************************************
helpr___atoi:
	pushq	%rbx
	movq	%rdi, %rsi
	xorq	%rbx, %rbx
	xorq	%rcx, %rcx

L_loop:
		lodsb
	orb	%al, %al
	jz	L_done
	andb	$0xf, %al

	movb	%al, %bl
	movq	%rcx, %rax
	movq	$10, %rcx
	mul	%rcx

	movq	%rax, %rcx
	addq	%rbx, %rcx
	
	jmp	L_loop

L_done:
	movq	%rcx, %rax
L_fin:
	popq	%rbx
	ret
