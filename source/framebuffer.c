#include <io.h>
#include <framebuffer.h>

char* fb = (char*) 0x000B8000;
unsigned int pos = 0;

void fb_write(unsigned int location, char c, unsigned char fgcolor, unsigned char bgcolor)
{
	fb[location] = c;
	fb[location + 1] = (bgcolor & 0x0F) << 4 | (fgcolor & 0x0F);
}

void fb_move_cursor(unsigned short pos)
{
	outb(FB_COMMAND_PORT, FB_HIGH_BYTE);
	outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
	outb(FB_COMMAND_PORT, FB_LOW_BYTE);
	outb(FB_DATA_PORT, pos & 0x00FF);
}

void display_print_string(char* buf, unsigned int fgcolor, unsigned int bgcolor)
{
	unsigned int i = 0;
	while(buf[i] != '\0')
	{
		fb_write(i * 2, buf[i], fgcolor, bgcolor);
		pos++;
		fb_move_cursor(pos);
		i++;
	}
}

void clear_fb()
{
	unsigned int i = 0;
	while(i < FB_MAX)
	{
		fb_write(i * 2, ' ', 0, 0);
		i++;
	}
}
