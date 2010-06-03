CC = powerpc64-unknown-linux-gnu-gcc
CXX = powerpc64-unknown-linux-gnu-g++
LD = powerpc64-unknown-linux-gnu-ld

COMMONFLAGS = -O3 -nostdlib
CFLAGS = ${COMMONFLAGS} -mcpu=620 -nostdinc -g
ASMFLAGS = ${COMMONFLAGS} -mcpu=620
CXXFLAGS = ${CFLAGS} -nostdinc++ -fno-rtti -fno-exceptions
LDFLAGS = -static --sort-common  -Map $@.map ${COMMONFLAGS}

INCDIR = ${OBJDIR}/../src/include/

${OBJDIR}/%.o : %.C
	${CXX} -c ${CXXFLAGS} $< -o $@ -I ${INCDIR}

${OBJDIR}/%.o : %.c
	${CC} -c ${CFLAGS} $< -o $@ -I ${INCDIR}

${OBJDIR}/%.o : %.S
	${CC} -c ${ASMFLAGS} $< -o $@ -Wa,-I${INCDIR}

${IMGDIR}/%.elf: kernel.ld ${OBJDIR}/*.o
	${LD} ${LDFLAGS} ${OBJDIR}/*.o -T kernel.ld -o $@

${IMGDIR}/%.bin: kernel.ld ${OBJDIR}/*.o
	${LD} ${LDFLAGS} ${OBJDIR}/*.o --oformat=binary -T kernel.ld -o $@

%.d:
	cd ${basename $@} && ${MAKE}

%.clean:
	cd ${basename $@} && ${MAKE} clean
