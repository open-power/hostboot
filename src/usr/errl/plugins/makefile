#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/errl/plugins/errl/makefile $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2012
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END


# This is a FipS makefile. This file and C sources will be built
# in a FipS tree. 

# All Hostboot plugins/makefile should .include ../plugins.mk
.include "../plugins.mk"


ERRL_PLUGIN  = libB-0100
ERRL_OBJS    = errlParse.o symbols.o


CFLAGS +=  -O0 

.if ( $(CONTEXT) == "x86.nfp" )

LIBRARIES   = ${ERRL_PLUGIN}.a 
EXPLIBS	    = ${ERRL_PLUGIN}.a
${ERRL_PLUGIN}.a_OFILES = ${ERRL_OBJS}

.else

BUILD_SHARED_OBJS =
SHARED_LIBRARIES EXPSHLIBS = ${ERRL_PLUGIN}.so
${ERRL_PLUGIN}.so_EXTRA_LIBS = libbase.so

${ERRL_PLUGIN}.so_SHLDFLAGS += ${SHLDFLAGS} -Wl,-soname,${.TARGET}

${ERRL_PLUGIN}.so_OFILES = ${ERRL_OBJS}

.endif

.include <${RULES_MK}>
