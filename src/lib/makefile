OBJDIR = ../../obj
include ../../config.mk

OBJS = string.o stdlib.o syscall_stub.o
OBJECTS = $(addprefix ${OBJDIR}/, ${OBJS})

all: ${OBJECTS}

clean:
	(rm -f ${OBJECTS} )
