ROOTPATH = ../..
OBJDIR = ${ROOTPATH}/obj/hbicore

OBJS = start.o kernel.o console.o pagemgr.o heapmgr.o taskmgr.o cpumgr.o
OBJS += syscall.o scheduler.o spinlock.o exception.o vmmmgr.o timemgr.o
OBJECTS = $(addprefix ${OBJDIR}/, ${OBJS})

all: ${OBJECTS}

clean:
	(rm -f ${OBJECTS} $(addsuffix .hash, ${OBJECTS}) )

include ${ROOTPATH}/config.mk

