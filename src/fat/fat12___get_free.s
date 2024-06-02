.global		fat12___get_free

# int fat12___get_free ();
#	return empty (free) cluster;


.text
#***************************************************************
#			get_free
#_______________________________________________________________
# output:	rax -- next cluster;
#***************************************************************
fat12___get_free:
	pushq	%rbx
	pushq	%rdi
	pushq	%rsi


	movq	$2, %rbx
L_step:
	inc	%rbx
	
	movq	%rbx, %rdi
	call	fat12___reconv12
		lodsw
	
	call	fat12___conv12
	orw	%ax, %ax
	jnz	L_step

L_done:
	movq	%rbx, %rax
L_fin:
	popq	%rsi
	popq	%rdi
	popq	%rbx
	ret
