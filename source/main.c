#include <utils.h>
#include <framebuffer.h>
#include <serial.h>

#define KERNEL_NAME "NLX-KERNEL"

int kmain(void)
{
	clear_fb();
	//char* buildInfo = "Built on: ";
	//char* buildInfo2 = "at: ";
	display_print_string(KERNEL_NAME, WHITE, BLACK);
	//display_print_string(buildInfo, WHITE, BLACK);
	//display_print_string(__DATE__, WHITE, BLACK);
	//display_print_string(buildInfo2, WHITE, BLACK);
	//display_print_string(__TIME__, WHITE, BLACK);
	serialinit();
	serialstr(KERNEL_NAME);
	//serialwrite('\n');
	return(0);
}