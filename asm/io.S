global iosend

iosend:
	mov al, [esp + 8] ; Byte to send
	mov dx, [esp + 4] ; I/O Port to send data to
	out dx, al
	ret