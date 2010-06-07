IMGDIR = ../../img
OBJDIR = ../../obj
include ../../config.mk

SUBDIRS = init.d
IMAGES += ${IMGDIR}/kernel.elf 
IMAGES += ${IMGDIR}/kernel.bin

all: ${SUBDIRS}

clean: $(patsubst %.d,%.clean, ${SUBDIRS})
	(rm -f ${IMAGES} )
