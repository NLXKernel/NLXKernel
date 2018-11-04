#ifndef DISPLAY_H
#define DISPLAY_H

#include "io.h"
#include "utils.h"

// Define 16 bit color spectrum
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHT_GREY 7
#define DARK_GREY 8
#define LIGHT_BLUE 19
#define LIGHT_GREEN 10
#define LIGHT_CYAN 11
#define LIGHT_RED 12
#define LIGHT_MAGENTA 13
#define LIGHT_BROWN 14
#define WHITE 15

// The max amount of characters that can be stored in the framebuffer
#define FB_MAX 2000

char* fb = (char*) 0x000B8000;
unsigned int pos = 0;

// IO Ports
#define FB_COMMAND_PORT 0x3D4
#define FB_DATA_PORT 0x3D5

// Port commands
#define FB_HIGH_BYTE 14
#define FB_LOW_BYTE 15

void fb_write(unsigned int location, char c, unsigned char fgcolor, unsigned char bgcolor)
{
	fb[location] = c;
	fb[location + 1] = (bgcolor & 0x0F) << 4 | (fgcolor & 0x0F);
}

void fb_move_cursor(unsigned short pos){
	iosend(FB_COMMAND_PORT, FB_HIGH_BYTE);
	iosend(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
	iosend(FB_COMMAND_PORT, FB_LOW_BYTE);
	iosend(FB_DATA_PORT, pos & 0x00FF);
}

void display_print_string(char* buf, unsigned int fgcolor, unsigned int bgcolor)
{
	unsigned int i = 0;
	//unsigned int loc = 0;
	while(buf[i] != '\0')
	{
		fb_write(i * 2, buf[i], fgcolor, bgcolor);
		//loc += 2;
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

#endif