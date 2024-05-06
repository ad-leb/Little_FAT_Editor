.global		helpr___memreset

# void		helpr___memreset (void* BUFFER, int LEN);

#	Fill struct in BUFFER by LEN zero-bytes		       


.text
#***************************************************************
#			memreset
#_______________________________________________________________
# input:	rdi -- address of struct to reset [BUFFER];
#		rsi -- length of struct to reset [LEN];
# output:	_no result_
#***************************************************************
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
