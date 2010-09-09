ROOTPATH = ../../..
OBJDIR = ${ROOTPATH}/obj/modules/example
IMGDIR = ${ROOTPATH}/img
EXTRACOMMONFLAGS = -fPIC

OBJS = example.o
OBJECTS = $(addprefix ${OBJDIR}/, ${OBJS})
LIBS = libexample.so
LIBRARIES = $(addprefix ${IMGDIR}/, ${LIBS})

all: ${OBJECTS} ${LIBRARIES}

clean:
	(rm -f ${OBJECTS} ${LIBRARIES} )

include ${ROOTPATH}/config.mk
