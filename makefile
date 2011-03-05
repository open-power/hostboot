SUBDIRS = src.d
ROOTPATH = .

EXTRA_PARTS = cscope

include ./config.mk

docs: src/build/doxygen/doxygen.conf
	rm -rf obj/doxygen/*
	doxygen src/build/doxygen/doxygen.conf
