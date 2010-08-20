SUBDIRS = src.d

all: ${SUBDIRS}
clean: $(patsubst %.d,%.clean, ${SUBDIRS})

include ./config.mk
