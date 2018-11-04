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
	// Print to the frame buffer
	char* buf = "NLX KERNEL";
	display_print_string(buf, WHITE, BLACK);
	
	
	return 0;
}