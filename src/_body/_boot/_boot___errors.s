.global		_boot___error_procedure
.global		_boot___error_count
.global		_boot___error_imagefile


.data
proce_msg:	.asciz	"Never heard about this procedure.. I'm newby\n\n\t"
proce_msg_end:
count_msg:	.asciz	"Too few arguments\n\n\t"
count_msg_end:
image_msg:	.asciz	"Can't open file of image. Is it real?\n\n\t"
image_msg_end:
help_msg:	.asciz	"  [ procedure ]  [ image filename ]  <parameters>  <files>\n\n"
help_msg_end:




.text
_boot___error_procedure:
	leaq	proce_msg, %rsi
	leaq	proce_msg_end, %rdx
	subq	%rsi, %rdx
	jmp	_boot___error_print
_boot___error_count:
	leaq	count_msg, %rsi
	leaq	count_msg_end, %rdx
	subq	%rsi, %rdx
	jmp	_boot___error_print
_boot___error_imagefile:
	leaq	image_msg, %rsi
	leaq	image_msg_end, %rdx
	subq	%rsi, %rdx
	jmp	_boot___error_print


_boot___error_print:
	movq	$1, %rax
	movq	$2, %rdi
	syscall

	movq	$1, %rax
	movq	$2, %rdi
	leaq	data___program_name, %rsi
	movq	data___program_name_end, %rdx 	/* Here we got a pointer, not a just label -- that's why there is 'movq', not 'leaq' */
	subq	%rsi, %rdx
	syscall

	movq	$1, %rax
	movq	$2, %rdi
	leaq	help_msg, %rsi
	leaq	help_msg_end, %rdx
	subq	%rsi, %rdx
	syscall

	movq	$0x3c, %rax
	syscall