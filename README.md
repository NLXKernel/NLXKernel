# NLXKernel
###### By PlanetAaron and 0xFF
NLX is a lightweight unix-like kernel made for x86 processors (support for other architextures is planned)


## Compiling

**Linux**
You will need gcc and nasm. 
These should be pretty easy to get on most distros so I won't cover package names.

Once you have that all set up, just run make
```make```


**MacOS**
You will need the homebrew package manager [https://brew.sh](https://brew.sh)

Once that's installed, you will need to install nasm and i386-elf-gcc from it
```brew install nasm i386-elf-gcc```
For some reason, you need to relink i386-elf-gcc in order for it to be in your path. Probably a bug but it's not hard to fix.
```brew unlink i386-elf-gcc && brew link i386-elf-gcc```
This should fix the symlinks for i386-elf-binutils (installed as a dependency) as well so you don't have to relink that.

After that, run make overriding CC with i386-elf-gcc and LD with i386-elf-ld
```make CC=i386-elf-gcc LD=i386-elf-ld```


**Windows**
Building on Windows is not officially supported. It should be possible by installing GCC and nasm with cygwin but, beyond that you're on your own for now


## Testing
Install qemu on your system. 
Then load the kernel with qemu-system-i386 (if you have used qemu in the past this will be fairly straightforward)
```qemu-system-i386 -kernel kernel.elf```

You don't have to use qemu to test it but, it's just really nice not to have to hassle with getting a bootloader to work. 

## TODO
- [x] Call Stack
- [x] Sending data to I/O ports
- [x] Writing to framebuffer
- [x] Serial Driver
- [ ] Enter Protected Mode
- [ ] Enter Long Mode (64 bit support)
- [ ] Keyboard Driver
- [ ] Filesystem Driver 
- [ ] Basic Userland support
- [ ] Basic Bootloader to load it 
