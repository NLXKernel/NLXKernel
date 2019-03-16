#include <utils.h>
#include <framebuffer.h>
#include <serial.h>
#include <gdt.h>

int kmain()
{
	clear_fb();
	gdt_init();
	serialinit();
	/* hacker voice - we're in */
	/* print some information */
	display_print_string("NLX", WHITE, BLACK);
	display_print_string("Built on: ", WHITE, BLACK);
	display_print_string(__DATE__, WHITE, BLACK);
	display_print_string(" at ", WHITE, BLACK);
	display_print_string(__TIME__, WHITE, BLACK);
	/* print it over serial as well */
	serialstr("NLX\n");
	serialstr("Built on: ");
	serialstr(__DATE__);
	serialstr(" at ");
	serialstr(__TIME__);
	return(0);
}
