.global		helpr___strncpy

# void		helpr____strncpy (unsigned char* TO, unsigned char* FROM, int LEN);

#	Just copy LEN bytes of string in FROM to TO buffer    


.text
#***************************************************************
#			strncpy
#_______________________________________________________________
# input:	rdi -- address to copy [TO];
#		rsi -- string to copy [FROM];
#		rdx -- length to copy [LEN];
# output:	_no result_
#***************************************************************
helpr___strncpy:
	cmpq	$8, %rdx
	jl	L_byte_copy
	movq	%rdx, %rcx		# |
	andq	$0b111, %rdx		# --> 'rdx' takes a low 3 bits (<8), 'rcx' takes all the rest (>8)

L_quad_copy:
	shrq	$3, %rcx
	rep	movsq
L_byte_copy:
	movq	%rdx, %rcx
	rep	movsb
L_fin:
	ret
