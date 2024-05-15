.global		_boot___4


.text

_boot___4:
#	1. Set stack;
#	2. Set time;
#	3. Read image titles and load it's tables;
#	4. Execute choosen procedure;


	movq	%rbp, %rsp

	call	helpr___get_time
	call	image___load

	movq	%rbp, %rdi					# < argv[4] or more >  =  < files[] >
	movq	data___procedure, %rsi
	call	*%rsi

L_after_execution:
	orb	%al, %al
	jnz	L_recover

L_fin:
	xorq	%rdi, %rdi
	movq	$0x3c, %rax
	syscall




L_recover:
	call	image___recover
	jmp	L_fin
