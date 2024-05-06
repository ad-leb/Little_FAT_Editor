.global		helpr___itod

# void		helpr___itoa (char* TO, long NUM);

#	Convert integer to array of decimal numbers


.text
#***************************************************************
#			memreset
#_______________________________________________________________
# input:	rdi -- address of buffer for string;
#		rsi -- number to convert;
# output:	_no result_
#***************************************************************
helpr___itod:
	movq	%rsi, %rax
	movq	$10, %rsi
	xorq	%rcx, %rcx

L_loop1:
	xorq	%rdx, %rdx
	divq	%rsi
	pushq	%rdx

	incq	%rcx
	orq	%rax, %rax
	jnz	L_loop1

L_loop2:
	popq	%rax
	orb	$0x30, %al
		stosb
	loop	L_loop2
	
L_done:
	xorb	%al, %al
		stosb
L_fin:
	ret
