OBJDIR = ../../obj
include ../../config.mk

OBJS = builtins.o
OBJECTS = $(addprefix ${OBJDIR}/, ${OBJS})

all: ${OBJECTS}

clean:
	(rm -f ${OBJECTS} )
