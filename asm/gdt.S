global gdt_flush
extern gp
extern kmain
extern kernel_stack


gdt_flush:
    cli
    lgdt [gp]
    mov eax, cr0
    or al, 1
    mov cr0, eax
    jmp 0x08:flush2

flush2:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    ret