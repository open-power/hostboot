# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/plugins/plugins.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2004,2013
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
#
# IBM_PROLOG_END_TAG

# This is FSP specific .mk file as error log parser will
# be compiled in FSP enviornment.
# This file only defines the rules for errl plugin libraries.

PLUGIN_NAME = lib${BASE_LIB_NAME}
RULE_LIBRARY_NAME = ${BASE_LIB_NAME}-rule
PRDR_ERRL_LIB = lib${RULE_LIBRARY_NAME}

LIBRARY_OFILES += \
    prdfLogParse.o \
    prdfLogParse_common.o \
    prdfCenLogParse.o \
    prdrErrlPluginsSupt.o

LIBFLAGS = -Efips/lib

#------------------------------------------------------------------
# Stuff for rule-based errl plugin support.
#------------------------------------------------------------------

${PRDR_ERRL_LIB}.a_OFILES = ${PRDR_ERRL_PLUGINS_OFILES}
LIBRARIES EXPLIBS += ${PRDR_ERRL_LIB}.a

${PRDR_ERRL_PLUGINS} :
	echo "Dummy makefile line"
OBJECTS += ${PRDR_ERRL_PLUGINS}


#------------------------------------------------------------------
# End stuff for rule-based errl plugin support.
#------------------------------------------------------------------

.if ($(CONTEXT)=="x86.nfp" || $(CONTEXT)=="x86")

NOAUTODEPS =
LIBRARIES += ${PLUGIN_NAME}.a
EXPLIBS += ${PLUGIN_NAME}.a
${PLUGIN_NAME}.a_OFILES = ${LIBRARY_OFILES}

.else

BUILD_SHARED_OBJECTS =
SHARED_LIBRARIES = ${PLUGIN_NAME}.so
${PLUGIN_NAME}.so_SHLDFLAGS = ${EMPTY_LIBS} -Wl,-soname,${.TARGET} -ldl -L.. -Wl,--whole-archive -l${RULE_LIBRARY_NAME} -Wl,--no-whole-archive
${PLUGIN_NAME}.so_OFILES = ${LIBRARY_OFILES}
${PLUGIN_NAME}.so_EXTRA_LIBS = libbase.so

.endif

.include <${RULES_MK}>

