ROOTPATH = ../../..
MODULE = targeting

VPATH =         \
    predicates: \
    iterators:  

PREDICATES_OBJS =           \
    predicatebase.o         \
    predicatepostfixexpr.o  \
    predicatectm.o       
    
ITERATORS_OBJS =        \
    targetiterator.o    \
    rangefilter.o

TARGET_OBJS =       \
    target.o        \
    targetservice.o \
    entitypath.o    \
    fakepnordata.o

OBJS = ${TARGET_OBJS} ${PREDICATES_OBJS} ${ITERATORS_OBJS}

SUBDIRS = test.d

include ${ROOTPATH}/config.mk
