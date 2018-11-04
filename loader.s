global loader	; the entry for the magical ELFs of the North Pole

MAJIK_NUMBOR	equ	0x1BADB002  ; Define the super majikol numbor constant
FLAGS	equ	0x0 ; a big white rectangle with a circle in the middle
CHECKSUM	equ	-MAJIK_NUMBOR   ; calculate the checksum
KERNEL_STACK_SIZE equ 4096 ; Stack size in bytes (4MB)


; ----- External Functions
extern kmain;

; ----- Executable section
section .text  ; the section containing my crappy excuse for code

align 4 ; align to 4 bytes
	dd MAJIK_NUMBOR ; write the super majikol numbor to the machine code
	dd FLAGS ; the rectangle with a red circle in the middle
	dd CHECKSUM ; and the checksum


loader: ; the loader label (defined as entry point in the linker script)
	mov esp, kernel_stack + KERNEL_STACK_SIZE ; stack pointer
	call kmain

	;mov	 dword[0x000B8000], 0x0F41 ; Move the letter A into framebuffer so A is printed on the screen

.loop:
	jmp .loop ; loop until the destruction of the entire universe and anything in it or until it's stopped



; ----- Stack  -----
section .bss
align 4 ; align at 4 bytes
kernel_stack: ; label points to beginning of memory
	resb    KERNEL_STACK_SIZE ; reserve stack for kernel
	