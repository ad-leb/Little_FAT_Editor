.global		helpr___get_outter_name

# void		helpr___get_outter_name (unsigned char* TO, unsigned char* FROM);

#	Convert internal 11-bytes FAT name to more handy format


.text
#***************************************************************
#			get_outter_name
#_______________________________________________________________
# input:	rdi -- buffer of outter name [TO];
#		rsi -- string FAT name [FROM];
# output:	_no result_
#***************************************************************
helpr___get_outter_name:
	movq	%rsi, %rdx
	movq	$8, %rcx

L_name_loop:
		lodsb
	cmpb	$0x20, %al
	jle	L_name_done
		stosb
	loop	L_name_loop

L_name_done:
	movb	$0x2e, %al
		stosb


	movq	%rdx, %rsi
	addq	$8, %rsi
	movq	$3, %rcx
L_ext_loop:
		lodsb
	cmpb	$0x20, %al
	jle	L_ext_done
		stosb
	loop	L_ext_loop

L_ext_done:
	movb	$0, %al
		stosb

L_fin:
	ret
