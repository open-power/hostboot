ROOTPATH = ../../..
OBJDIR = ${ROOTPATH}/obj/hbicore

OBJS = init_main.o
OBJECTS = $(addprefix ${OBJDIR}/, ${OBJS})

all: ${OBJECTS}

clean:
	(rm -f ${OBJECTS} $(addsuffix .hash, ${OBJECTS}) )

include ${ROOTPATH}/config.mk
