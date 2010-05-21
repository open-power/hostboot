OBJDIR = ../../obj
include ../../config.mk

OBJS = start.o kernel.o console.o pagemgr.o
OBJECTS = $(addprefix ${OBJDIR}/, ${OBJS})

all: ${OBJECTS}

clean:
	(rm -f ${OBJECTS} )
