.global		_boot___1


.data
pull_name:	.asciz	"pull"
push_name:	.asciz	"push"
list_name:	.asciz	"list"


.text
_boot___1:

L_check_pull:
	movq	(%rbp), %rsi
	leaq	pull_name, %rdi
	movq	$4, %rdx
	call	helpr___strcmp
	orb	%al, %al
	jz	L_pull_case
L_check_push:
	movq	(%rbp), %rsi
	leaq	push_name, %rdi
	movq	$4, %rdx
	call	helpr___strcmp
	orb	%al, %al
	jz	L_push_case
L_check_list:
	movq	(%rbp), %rsi
	leaq	list_name, %rdi
	movq	$4, %rdx
	call	helpr___strcmp
	orb	%al, %al
	jz	L_list_case
L_no_match:
	jmp	_boot___error_procedure




L_pull_case:
	leaq	pull, %rsi
	jmp	L_so
L_push_case:
	leaq	push, %rsi
	jmp	L_so
L_list_case:
	leaq	list, %rsi
	jmp	L_so



L_so:
	movq	%rsi, data___procedure
	addq	$8, %rbp
	jmp	_boot___2
