ROOTPATH = ../../../..
MODULE = fapi

EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

OBJS =  fapiReturnCode.o \
        fapiReturnCodeDataRef.o \
        fapiTarget.o \
        fapiErrorInfo.o \
        fapiErrorInfoMem.o \
        fapiErrorInfoMemInit.o \
        fapiCollectFfdc.o

include ${ROOTPATH}/config.mk

vpath %.C ${GENDIR}
