#pragma once

#include <io.h>
#include <utils.h>

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

// IO Ports
#define FB_COMMAND_PORT 0x3D4
#define FB_DATA_PORT 0x3D5

// Port commands
#define FB_HIGH_BYTE 14
#define FB_LOW_BYTE 15

// Function Decls
void fb_write(unsigned int location, char c, unsigned char fgcolor, unsigned char bgcolor);
void fb_move_cursor(unsigned short pos);
void display_print_string(char* buf, unsigned int fgcolor, unsigned int bgcolor);
void clear_fb();