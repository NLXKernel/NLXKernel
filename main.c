#include "utils.h"
#include "framebuffer.h"


//char* fb = (char*) 0x000B8000;



// A function to add three numbers, as if that wasn't something we could already do...
int sum_of_three(int arg1, int arg2, int arg3)
{
	return arg1 + arg2 + arg3;
}



int kmain(void)
{
	clear_fb();
	//unsigned short pos = 0;
	//fb_write(0, 'A', WHITE, BLACK);
	//pos += 1;
	//fb_move_cursor(pos);
	//fb_write(2, 'B', WHITE, BLACK);
	// Print to the frame buffer
	char* buf = "NLX KERNEL";
	//unsigned int len = strlen(buf);
	display_print_string(buf, WHITE, BLACK);
	
	
	return 0;
}