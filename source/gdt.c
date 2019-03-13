#include <gdt.h>

void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran)
{
	// set up descriptor base address
	gdt[num].base_low = (base & 0xFFFF);
	gdt[num].base_middle = (base >> 16) & 0xFF;
	gdt[num].base_high = (base >> 24) & 0xFF;

	// Set Descriptor Limits
	gdt[num].limit_low = (limit & 0xFFFF);
	gdt[num].granularity = ((limit >> 16) & 0x0F);

	// Set granularity and access flags
	gdt[num].granularity |= (gran & 0xF0);
	gdt[num].access = access;
}

void gdt_init()
{
	// Set up GDT pointer and limit
	gp.limit = (sizeof(struct gdt_entry) * 3) - 1;
	gp.base = (unsigned int) &gdt;

	// Null Descriptor
	gdt_set_gate(0, 0, 0, 0, 0);
	
	// Code Segment (4GB limit, 4KB granularity)
	gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);

	// Data Segment
	gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

	// Flush gdt and initialize a new one
	gdt_flush();

}