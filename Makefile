CC := gcc
LD := ld
AS := nasm
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
	 -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c -I./include
LDFLAGS := -T link.ld -melf_i386
ASFLAGS := -f elf
OBJ = source/main.o asm/io.o asm/loader.o source/framebuffer.o source/utils.o

all: kernel.elf

kernel.elf: $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o kernel.elf

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

%.o: %.S
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf *.o *.elf
	rm -rf source/*.o
	rm -rf asm/*.o