.global		helpr___exit


.text
helpr___exit:
	movq	$0x3c, %rax
	syscall
