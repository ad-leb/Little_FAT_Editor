.global		helpr___strcpy


.text
helpr___strcpy:
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
