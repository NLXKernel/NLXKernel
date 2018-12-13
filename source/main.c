#include <utils.h>
#include <framebuffer.h>

int kmain(void)
{
	clear_fb();
	char* buf = "NLX KERNEL\n";
	//char* buildInfo = "Built on: ";
	//char* buildInfo2 = "at: ";
	display_print_string(buf, WHITE, BLACK);
	//display_print_string(buildInfo, WHITE, BLACK);
	//display_print_string(__DATE__, WHITE, BLACK);
	//display_print_string(buildInfo2, WHITE, BLACK);
	//display_print_string(__TIME__, WHITE, BLACK);
	return(0);
}