CC = ppc64-linux-gcc
CXX = ppc64-linux-g++
LD = ppc64-linux-ld

COMMONFLAGS = -O3 -nostdlib ${EXTRACOMMONFLAGS}
CFLAGS = ${COMMONFLAGS} -mcpu=power7 -nostdinc -g -msoft-float -mno-altivec \
	 -Wall
ASMFLAGS = ${COMMONFLAGS} -mcpu=power7
CXXFLAGS = ${CFLAGS} -nostdinc++ -fno-rtti -fno-exceptions -Wall
LDFLAGS = --nostdlib --sort-common ${COMMONFLAGS}
LDMAPFLAGS = -Map $@.map 

INCDIR = ${ROOTPATH}/src/include/

${OBJDIR}/%.o : %.C
	${CXX} -c ${CXXFLAGS} $< -o $@ -I ${INCDIR}

${OBJDIR}/%.o : %.c
	${CC} -c ${CFLAGS} $< -o $@ -I ${INCDIR}

${OBJDIR}/%.o : %.S
	${CC} -c ${ASMFLAGS} $< -o $@ -Wa,-I${INCDIR}

${IMGDIR}/%.so : ${OBJECTS} ${ROOTPATH}/src/module.ld
	${LD} -shared -z now --gc-sections ${LDFLAGS} $< \
	      -T ${ROOTPATH}/src/module.ld -o $@

${IMGDIR}/%.elf: kernel.ld ${OBJDIR}/*.o ${ROOTPATH}/src/kernel.ld
	${LD} -static ${LDFLAGS} ${LDMAPFLAGS} ${OBJDIR}/*.o \
	      -T ${ROOTPATH}/src/kernel.ld -o $@

${IMGDIR}/%.bin: ${IMGDIR}/%.elf $(wildcard ${IMGDIR}/*.so)
	${ROOTPATH}/src/bld/linker $@ $^

%.d:
	cd ${basename $@} && ${MAKE}

%.clean:
	cd ${basename $@} && ${MAKE} clean
