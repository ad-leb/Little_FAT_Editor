.global		_boot___3



.text
_boot___3:

L_look_for_params:
	movq	(%rbp), %rsi
	orq	%rsi, %rsi
	jz	L_next
		lodsb
	cmpb	$0x2d, %al
	jnz	L_next


L_check_param:
		lodsb
L_if_its_zero:
	orb	%al, %al
	jz	L_fin
L_if_its_clear:
	cmpb	$0x63, %al	
	jz	L_clear_case
L_if_its_verbose:
	cmpb	$0x76, %al
	jz	L_verbose_case
L_if_its_decprint:
	cmpb	$0x64, %al
	jz	L_decprint_case
L_unknown_param:
	jmp	_boot___error_param



L_clear_case:
	orb	$0x01, data___params
	clc
	jmp	L_check_param
L_verbose_case:
	orb	$0x02, data___params
	clc
	jmp	L_check_param
L_decprint_case:
	orb	$0x04, data___params
	clc
	jmp	L_check_param


L_fin:
	addq	$8, %rbp
	jmp	L_look_for_params





L_next:
	jmp	_boot___4
