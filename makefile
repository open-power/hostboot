SUBDIRS = src.d
include ./config.mk

all: ${SUBDIRS}
clean: $(patsubst %.d,%.clean, ${SUBDIRS})
