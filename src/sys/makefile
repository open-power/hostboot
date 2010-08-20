ROOTPATH = ../..
IMGDIR = ${ROOTPATH}/img
OBJDIR = ${ROOTPATH}/obj/hbicore

SUBDIRS = init.d vfs.d

all: ${SUBDIRS}

clean: $(patsubst %.d,%.clean, ${SUBDIRS})

include ../../config.mk
