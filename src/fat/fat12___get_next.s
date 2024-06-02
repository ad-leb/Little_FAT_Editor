.global		fat12___get_next

# int fat12___get_next (int current cluster);
#	return next by passed cluster;


.text
#***************************************************************
#			get_next
#_______________________________________________________________
# input:	rdi -- current cluster;
# output:	rax -- next cluster;
#***************************************************************
fat12___get_next:
	pushq	%rbx
	pushq	%rsi


L_base:
	test	$0x0001, %di
	setnz	%bl
	
	call	fat12___reconv12
		lodsw
	
	or	%bl, %bl
	jz	L_even


L_odd:	shrw	$4, %ax
	jmp	L_fin
L_even:	andw	$0x0fff, %ax



L_fin:
	popq	%rsi
	popq	%rbx
	ret
