IMGDIR = ../../img
OBJDIR = ../../obj
include ../../config.mk

SUBDIRS = init.d vfs.d

all: ${SUBDIRS}

clean: $(patsubst %.d,%.clean, ${SUBDIRS})
	(rm -f ${IMAGES} )
