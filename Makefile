CC := gcc
LD := ld
AS := nasm
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
	 -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c -I./include
LDFLAGS := -T link.ld -melf_i386
ASFLAGS := -f elf
OBJ = source/main.o asm/io.o asm/loader.o asm/gdt.o  source/framebuffer.o source/utils.o source/serial.o source/gdt.o

all: kernel.elf

kernel.elf: $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o kernel.elf

os.iso: kernel.elf
	cp kernel.elf iso/boot/kernel.elf
	genisoimage -R                              \
		-b boot/grub/stage2_eltorito    \
		-no-emul-boot                   \
		-boot-load-size 4               \
		-A NLX                           \
		-input-charset utf8             \
		-quiet                          \
		-boot-info-table                \
		-o os.iso                       \
		iso

run: os.iso
	bochs -f bochsrc.txt -q

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

%.o: %.S
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf *.o *.elf
	rm -rf source/*.o
	rm -rf asm/*.o
