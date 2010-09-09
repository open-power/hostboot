ROOTPATH = ../..
OBJDIR = ${ROOTPATH}/obj/hbicore

OBJS = builtins.o
OBJECTS = $(addprefix ${OBJDIR}/, ${OBJS})

all: ${OBJECTS}

clean:
	(rm -f ${OBJECTS} )

include ${ROOTPATH}/config.mk
