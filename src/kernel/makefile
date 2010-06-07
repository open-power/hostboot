OBJDIR = ../../obj
include ../../config.mk

OBJS = start.o kernel.o console.o pagemgr.o heapmgr.o taskmgr.o cpumgr.o
OBJS += syscall.o scheduler.o
OBJECTS = $(addprefix ${OBJDIR}/, ${OBJS})

all: ${OBJECTS}

clean:
	(rm -f ${OBJECTS} )
