CC = powerpc64-unknown-linux-gnu-gcc
CXX = powerpc64-unknown-linux-gnu-g++
LD = powerpc64-unknown-linux-gnu-ld

COMMONFLAGS = -O3 -nostdlib 
CFLAGS = ${COMMONFLAGS} -mcpu=620 -fno-rtti -fno-exceptions
CXXFLAGS = ${CFLAGS}
LDFLAGS = -static ${COMMONFLAGS}

${OBJDIR}/%.o : %.C
	${CXX} -c ${CXXFLAGS} $< -o $@

${OBJDIR}/%.o : %.S
	${CC} -c ${CFLAGS} $< -o $@

${IMGDIR}/%.elf: kernel.ld
	${LD} ${LDFLAGS} ${OBJDIR}/*.o -T kernel.ld -o $@

${IMGDIR}/%.bin: kernel.ld
	${LD} ${LDFLAGS} ${OBJDIR}/*.o --oformat=binary -T kernel.ld -o $@

%.d:
	cd ${basename $@} && ${MAKE}

%.clean:
	cd ${basename $@} && ${MAKE} clean
