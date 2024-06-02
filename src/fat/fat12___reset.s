.global		fat12___reset

# void fat12___reset (int cluster);
#	reset passed cluster (make it 0x000);


.text
#***************************************************************
#			get_next
#_______________________________________________________________
# input:	rdi -- number of cluster;
#***************************************************************
fat12___reset:
	pushq	%rdx
	
	
	movq	%rdi, %rdx
	call	fat12___reconv12
	
	movq	%rsi, %rdi
		lodsw
	
	test	$0x1, %dx
	jz	L_even


L_odd:	andw	$0x000f, %ax
	jmp	L_reset
L_even:	andw	$0xf000, %ax


L_reset:
		stosw
L_fin:
	popq	%rdx
	ret
