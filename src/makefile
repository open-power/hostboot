IMGDIR = ../img
OBJDIR = ../obj
include ../config.mk

SUBDIRS = kernel.d
IMAGES += ${IMGDIR}/kernel.elf 
IMAGES += ${IMGDIR}/kernel.bin

all: ${SUBDIRS}
	${MAKE} ${IMAGES}

clean: $(patsubst %.d,%.clean, ${SUBDIRS})
	(rm -f ${IMAGES} )
