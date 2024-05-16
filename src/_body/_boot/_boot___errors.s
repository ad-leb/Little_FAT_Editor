.global		_boot___error_procedure
.global		_boot___error_count
.global		_boot___error_imagefile
.global		_boot___error_param


.data
proce_msg:	.asciz	"Never heard about this procedure.. I'm newby\n\n\t"
proce_msg_end:
count_msg:	.asciz	"Too few arguments\n\n\t"
count_msg_end:
image_msg:	.asciz	"Can't open file of image. Is it real?\n\n\t"
image_msg_end:
param_msg:	.asciz	"Noah, I don't know, what this params should do..\n\n\t"
param_msg_end:
help_msg:	.asciz	"  [ procedure ]  [ image filename ]  <parameters>  <files>\n\n\n  push -- to write files in image;\n  pull -- to get files from image;\n  list -- to get info about image:\n      | - title -- get info about image (only FAT);\n      | - content -- get list of files, that include image;\n  born -- create an image;\n\n"
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
_boot___error_param:
	leaq	param_msg, %rsi
	leaq	param_msg_end, %rdx
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
