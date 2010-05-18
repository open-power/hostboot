CC = powerpc64-unknown-linux-gnu-gcc
CXX = powerpc64-unknown-linux-gnu-g++
LD = powerpc64-unknown-linux-gnu-ld

COMMONFLAGS = -O3 -nostdlib 
CFLAGS = ${COMMONFLAGS} -mcpu=620 -fno-rtti -fno-exceptions
CXXFLAGS = ${CFLAGS}
LDFLAGS = -static ${COMMONFLAGS}

OBJECTS = start.o kernel.o

all: kernel.elf kernel.bin

kernel.elf: ${OBJECTS} kernel.ld
	${LD} ${LDFLAGS} ${OBJECTS} -T kernel.ld -o kernel.elf

kernel.bin: ${OBJECTS} kernel.ld
	${LD} ${LDFLAGS} ${OBJECTS} --oformat=binary -T kernel.ld -o kernel.bin

clean:
	(rm -f ${OBJECTS} kernel.elf kernel.bin)
