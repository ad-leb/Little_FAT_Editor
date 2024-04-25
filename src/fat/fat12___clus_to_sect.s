.global		fat12___reconv12


.text
fat12___reconv12:
	movq	data___fat_table, %rsi
	addq	%rdi, %rsi
	shrq	$1, %rdi
	addq	%rdi, %rsi
	
	ret
