.global		fat12___conv12


.text
fat12___conv12:
	orb	%bl, %bl
	jz	L_even
L_odd:
	shrw	$4, %ax
	ret
L_even:
	andw	$0x0fff, %ax
	ret

