CC := gcc
LD := ld
AS := nasm
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
	 -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c -I./include
LDFLAGS := -T link.ld -melf_i386
ASFLAGS := -f elf
# the fate of the world relies on those backslashes being aligned
# don't fuck it up sMH
# no i'm serious you have *one* fucking job, i swear if those get misaligned
# i'm going to scream or something
OBJ =	asm/gdt.o		\
	asm/io.o		\
	asm/loader.o		\
	source/framebuffer.o	\
	source/gdt.o		\
	source/main.o		\
	source/serial.o		\
	source/utils.o

all: kernel.elf

kernel.elf: $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o kernel.elf

os.iso: kernel.elf
	cp kernel.elf iso/boot/kernel.elf
# oh yeah don't fuck up these backslashes either
# or else.
	genisoimage -R				\
		-b boot/grub/stage2_eltorito	\
		-no-emul-boot			\
		-boot-load-size 4		\
		-A NLX				\
		-input-charset utf8		\
		-quiet				\
		-boot-info-table		\
		-o os.iso			\
		iso

run: os.iso
	qemu-system-i386 -cdrom os.iso -serial stdio

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

%.o: %.S
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf *.o *.elf
	rm -rf source/*.o
	rm -rf asm/*.o
	rm -rf os.iso
