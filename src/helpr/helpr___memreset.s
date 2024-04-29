.global		helpr___memreset


.text
helpr___memreset:
	xorq	%rdx, %rdx
	movq	%rsi, %rcx
	shrq	$3, %rcx

	xorq	%rax, %rax
	rep	stosq

	movq	%rsi, %rcx
	andq	$0b111, %rcx
	rep	stosb

	ret
