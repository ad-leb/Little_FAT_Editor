.global		_boot___1


.data
pull_name:	.asciz	"pull"
push_name:	.asciz	"push"
list_name:	.asciz	"list"
born_name:	.asciz	"born"


.text

_boot___1:
#	1. Define using procedure;


L_check_pull:
	movq	(%rbp), %rsi					# < argv[1] > 
	leaq	pull_name, %rdi
	movq	$4, %rdx
	call	helpr___strcmp
	orb	%al, %al
	jz	L_pull_case
L_check_push:
	movq	(%rbp), %rsi					# < argv[1] > 
	leaq	push_name, %rdi
	movq	$4, %rdx
	call	helpr___strcmp
	orb	%al, %al
	jz	L_push_case
L_check_list:
	movq	(%rbp), %rsi					# < argv[1] > 
	leaq	list_name, %rdi
	movq	$4, %rdx
	call	helpr___strcmp
	orb	%al, %al
	jz	L_list_case
L_check_born:
	movq	(%rbp), %rsi					# < argv[1] > 
	leaq	born_name, %rdi
	movq	$4, %rdx
	call	helpr___strcmp
	orb	%al, %al
	jz	L_born_case
L_no_match:
	jmp	_boot___error_procedure




L_pull_case:
	leaq	pull, %rsi					# < void* pull (void**) >
	jmp	L_so
L_push_case:
	leaq	push, %rsi					# < void* push (void**) >
	orq	$0x2, data___image_flags			# < O_RDWR >
	jmp	L_so
L_list_case:
	leaq	list, %rsi					# < void* list (void**) >
	jmp	L_so
L_born_case:
	leaq	born, %rsi					# < void* born (void**) >
	orq	$0x41, data___image_flags			# < O_CREAT | O_WRITE >
	jmp	L_so



L_so:
	movq	%rsi, data___procedure
	addq	$8, %rbp					# < next arg >

	jmp	_boot___2
