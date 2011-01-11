all: ALL

ifdef MODULE
OBJDIR = ${ROOTPATH}/obj/modules/${MODULE}
IMGDIR = ${ROOTPATH}/img
EXTRACOMMONFLAGS += -fPIC
else
OBJDIR = ${ROOTPATH}/obj/hbicore
IMGDIR = ${ROOTPATH}/img
endif

CUSTOM_LINKER = ${ROOTPATH}/src/build/linker/linker
TRACEPP = ${ROOTPATH}/src/build/trace/tracepp

CC = ${TRACEPP} ppc64-linux-gcc
CXX = ${TRACEPP} ppc64-linux-g++
LD = ppc64-linux-ld

COMMONFLAGS = -O3 -nostdlib ${EXTRACOMMONFLAGS}
CFLAGS = ${COMMONFLAGS} -mcpu=power7 -nostdinc -g -msoft-float -mno-altivec \
	 -Wall
ASMFLAGS = ${COMMONFLAGS} -mcpu=power7
CXXFLAGS = ${CFLAGS} -nostdinc++ -fno-rtti -fno-exceptions -Wall
LDFLAGS = --nostdlib --sort-common ${COMMONFLAGS}
LDMAPFLAGS = -Map $@.map 

INCDIR = ${ROOTPATH}/src/include/

OBJECTS = $(addprefix ${OBJDIR}/, ${OBJS})
LIBRARIES = $(addprefix ${IMGDIR}/, ${LIBS})

${OBJDIR}/%.o : %.C
	mkdir -p ${OBJDIR}
	${CXX} -c ${CXXFLAGS} $< -o $@ -I ${INCDIR}

${OBJDIR}/%.o : %.c
	mkdir -p ${OBJDIR}
	${CC} -c ${CFLAGS} $< -o $@ -I ${INCDIR}

${OBJDIR}/%.o : %.S
	mkdir -p ${OBJDIR}
	${CC} -c ${ASMFLAGS} $< -o $@ -Wa,-I${INCDIR}

${IMGDIR}/%.so : ${OBJECTS} ${ROOTPATH}/src/module.ld
	${LD} -shared -z now --gc-sections ${LDFLAGS} $< \
	      -T ${ROOTPATH}/src/module.ld -o $@

${IMGDIR}/%.elf: kernel.ld ${OBJDIR}/*.o ${ROOTPATH}/src/kernel.ld
	${LD} -static ${LDFLAGS} ${LDMAPFLAGS} ${OBJDIR}/*.o \
	      -T ${ROOTPATH}/src/kernel.ld -o $@

${IMGDIR}/%.bin: ${IMGDIR}/%.elf $(wildcard ${IMGDIR}/*.so)
	${CUSTOM_LINKER} $@ $^

%.d:
	cd ${basename $@} && ${MAKE}

%.clean:
	cd ${basename $@} && ${MAKE} clean

ALL: ${SUBDIRS} ${OBJECTS} ${LIBRARIES}
ifdef IMAGES
	    ${MAKE} ${IMAGES}
endif

clean: $(patsubst %.d,%.clean, ${SUBDIRS})
	(rm -f ${OBJECTS} $(addsuffix .hash, ${OBJECTS}) ${LIBRARIES} \
	       ${IMAGES} $(addsuffix .map, ${IMAGES}) )

