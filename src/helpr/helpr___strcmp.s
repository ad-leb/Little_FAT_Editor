.global		helpr___strcmp

# int		helpr____strcmp (unsigned char* FIRST, unsigned char* SECOND, int LEN);

# 	Just compare two string. By setting LEN-field, there is
# 	can limit a length of comparing string.		       


.text
#***************************************************************
#			strcmp
#_______________________________________________________________
# input:	rdi -- first string [FIRST];
#		rsi -- second string [SECOND];
#		rdx -- length to compare [LEN];
# output:	rax -- 0 if strings are equal, or unequal bytes;
#***************************************************************
helpr___strcmp:
	cmpq	$8, %rdx
	jl	L_byte_cmp
	movq	%rdx, %rcx
	andq	$0b0111, %rdx

L_quad_cmp:
	shrq	$3, %rcx
	repe	cmpsq
	jnz	L_not_full
L_byte_cmp:
	movq	%rdx, %rcx
	repe	cmpsb
	jnz	L_not_full

L_done:
	xorq	%rax, %rax
L_fin:
	ret






L_not_full:
	decq	%rsi
		lodsb
	jmp	L_fin
