.global		helpr___strcat

# int		helpr____strcat (unsigned char* TO, unsigned char* FROM, int LEN);

# 	Copy the FROM string to tail of TO string, which 
# 	signify by \0-byte, but not more then wrote in LIMIT. 
# 	Copiing goes before there is no the \0-byte in the 
# 	FROM string, or before LIMIT (which have been 
# 	decrementing each step) don't equal 0. 		       
# 	If LEN == 0, there're no limit			       


.text
#***************************************************************
#			strcat
#_______________________________________________________________
# input:	rdi -- string to add [TO];
#		rsi -- string from add [FROM];
#		rdx -- limit of adding bytes [LEN];
# output:	rax -- length of result string;
#***************************************************************
helpr___strcat:
	movq	%rdx, %rcx
	xorq	%rdx, %rdx

L_to_end:
	movb	(%rdi), %al
	orb	%al, %al
	jz	L_start

	incq	%rdi
	incq	%rdx
	jmp	L_to_end

L_start:
L_loop:
		lodsb
	orb	%al, %al
	jz	L_done

		stosb
	incq	%rdx
	loop	L_loop

L_done:
	xorq	%rax, %rax
		stosb

L_fin:
	movq	%rdx, %rax
	ret
