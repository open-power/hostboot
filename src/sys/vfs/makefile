ROOTPATH = ../../..
OBJDIR = ${ROOTPATH}/obj/hbicore

OBJS = vfs_main.o
OBJECTS = $(addprefix ${OBJDIR}/, ${OBJS})

all: ${OBJECTS}

clean:
	(rm -f ${OBJECTS} $(addsuffix .hash, ${OBJECTS}) )

include ${ROOTPATH}/config.mk
