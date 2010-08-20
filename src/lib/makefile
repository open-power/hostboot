ROOTPATH = ../..
OBJDIR = ${ROOTPATH}/obj/hbicore

OBJS = string.o stdlib.o 
OBJS += syscall_stub.o syscall_task.o syscall_mutex.o syscall_msg.o
OBJS += syscall_mmio.o
OBJECTS = $(addprefix ${OBJDIR}/, ${OBJS})

all: ${OBJECTS}

clean:
	(rm -f ${OBJECTS} )

include ../../config.mk
