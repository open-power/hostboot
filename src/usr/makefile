ROOTPATH = ../..

SUBDIRS = example.d

all: ${SUBDIRS}

clean: $(patsubst %.d,%.clean, ${SUBDIRS})

include ${ROOTPATH}/config.mk
