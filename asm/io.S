global outb
global inb

outb:
	mov al, [esp + 8] ; Byte to send
	mov dx, [esp + 4] ; I/O Port to send data to
	out dx, al
	ret

inb:
	mov dx, [esp + 4]
	in al, dx
	ret