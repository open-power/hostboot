OBJDIR = ../../obj
include ../../config.mk

OBJS = string.o stdlib.o 
OBJS += syscall_stub.o syscall_task.o syscall_mutex.o syscall_msg.o
OBJECTS = $(addprefix ${OBJDIR}/, ${OBJS})

all: ${OBJECTS}

clean:
	(rm -f ${OBJECTS} )
