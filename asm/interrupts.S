%macro no_error_code_interrupt_handler %1
global interrupt_handler_%1
interrupt_handler_%1:
	push dword 0	; Error code 0
	push dword %1	; Push interrupt number
	jmp common_interrupt_handler	; Jump to our common handler
%endmacro

%macro error_code_interrupt_handler %1
global interrupt_handler_%1
interrupt_handler_%1:
	push dword %1	; push interrupt number
	jmp common_interrupt_handler	; Jump to common handler
%endmacro

common_interrupt_handler:
	; save registers
	push eax
	push ebx
	push ebp

	; Call interrupt_handler
	call interrupt_handler
	; Restore registers
	pop ebp
	pop eax
	pop ebx

	add esp, 8 	; Restore stack

	; Continue as if nothing ever happened
	iret

no_error_code_interrupt_handler	0
no_error_code_interrupt_handler	1

error_code_handler	7