#include <serial.h>
#include <io.h>

void serialinit()
{
	outb(PORT + 1, 0x0);
	outb(PORT + 3, 0x80);
	outb(PORT, 0x3);
	outb(PORT + 1, 0x0);
	outb(PORT + 3, 0x3);
	outb(PORT + 2, 0xC7);
	outb(PORT + 4, 0xB);
}

int serialrecv()
{
	return inb(PORT + 5) & 1;
}

char serialread()
{
	while(!serialrecv());
	return inb(PORT);
}

int transmitempty()
{
	return inb(PORT + 5) & 0x20;
}

void serialwrite(char buf)
{
	while(!transmitempty());

	outb(PORT, buf);
}

void serialstr(char* buf)
{
	int i = 0;
	while(buf[i] != '\0')
	{
		serialwrite(buf[i]);
		i++;
	}
}