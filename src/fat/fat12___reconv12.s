.global		fat12___reconv12

# ____no-C____
#	convert number of cluster to it's memory address;


.text
#***************************************************************
#			reconv12
#_______________________________________________________________
# input:	rdi -- number of cluster;
# output:	rsi -- address of cluster;
#***************************************************************
fat12___reconv12:
	movq	data___fat_table, %rsi
	addq	%rdi, %rsi
	shrq	$1, %rdi
	addq	%rdi, %rsi

	movl	$data___fat_size, %edi	
	cmpl	%esi, %edi
	jge	L_limit
L_fin:
	ret



L_limit:
	mov	$0012, %rdi
	call	helpr___error
