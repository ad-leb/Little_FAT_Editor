.global		fat12___conv12

# ____no-C____
# 	Convert word from FAT12 to number of cluster, that it store, by parity;


.text
#***************************************************************
#			conv12
#_______________________________________________________________
# input:	ax -- word to convert;
#		bl -- parity of cluster;
# output:	ax -- converted number of cluster;
#***************************************************************
fat12___conv12:
	orb	%bl, %bl
	jz	L_even
L_odd:
	shrw	$4, %ax
	ret
L_even:
	andw	$0x0fff, %ax
	ret

