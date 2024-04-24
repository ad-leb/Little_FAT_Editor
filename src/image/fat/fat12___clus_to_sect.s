.global		fat12___clus_to_sect


.text
fat12___clus_to_sect:
	movq	data___fat_table, %rsi
	addq	%rdi, %rsi
	shrq	$1, %rdi
	addq	%rdi, %rsi
	
	ret
