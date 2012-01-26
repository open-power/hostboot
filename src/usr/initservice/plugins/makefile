#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/initservice/plugins/makefile $
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

# This is a FipS makefile.


# Include the common hostboot plugins makefile
.include "../plugins.mk" 

MY_PLUGIN  = libB-0500
MY_OBJS    = # initserviceParse.o 


.if ( $(CONTEXT) == "x86.nfp" )

LIBRARIES   = ${MY_PLUGIN}.a 
EXPLIBS	    = ${MY_PLUGIN}.a
${MY_PLUGIN}.a_OFILES = ${MY_OBJS}

.else

BUILD_SHARED_OBJS =
SHARED_LIBRARIES EXPSHLIBS = ${MY_PLUGIN}.so
${MY_PLUGIN}.so_EXTRA_LIBS = libbase.so
${MY_PLUGIN}.so_SHLDFLAGS += ${SHLDFLAGS} -Wl,-soname,${.TARGET}
${MY_PLUGIN}.so_OFILES = ${MY_OBJS}

.endif

.include <${RULES_MK}>
