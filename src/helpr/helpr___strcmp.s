.global		helpr___namecmp


.text
helpr___namecmp:

	movq	$10, %rcx
	repe	cmpsb
	jnz	L_not_full

L_fin:
	movq	$0, %rax
	ret


L_not_full:
	decq	%rsi
		lodsb
	orb	%al, %al
	jz	L_fin
L_err:
	movq	$1, %rax
	ret
