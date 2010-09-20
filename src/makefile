ROOTPATH = ..
IMGDIR = ${ROOTPATH}/img
OBJDIR = ${ROOTPATH}/obj/hbicore

SUBDIRS = kernel.d lib.d libc++.d sys.d usr.d build.d
IMAGES += ${IMGDIR}/hbicore.elf 
IMAGES += ${IMGDIR}/hbicore.bin

all: ${SUBDIRS}
	${MAKE} ${IMAGES}

clean: $(patsubst %.d,%.clean, ${SUBDIRS})
	(rm -f ${IMAGES} $(addsuffix .map, ${IMAGES}) )

include ${ROOTPATH}/config.mk
