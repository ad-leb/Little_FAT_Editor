.global		helpr___itoh

# void		helpr___itoh (char* TO, long NUM);

#	Convert integer to array of hex numbers


.text
#***************************************************************
#			memreset
#_______________________________________________________________
# input:	rdi -- address of buffer for string;
#		rsi -- number to convert;
# output:	_no result_
#***************************************************************
helpr___itoh:
	pushq	%rbx

	movq	%rsi, %rax
	movq	$16, %rsi
	leaq	hex_table, %rbx
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
	xlatb
		stosb
	loop	L_loop2
	
L_done:
	xorb	%al, %al
		stosb

L_fin:
	popq	%rbx
	ret



.data
hex_table:	.ascii	"0123456789abcdef"
