# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/plugins/plugins.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2016
# [+] International Business Machines Corp.
#
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
#
# IBM_PROLOG_END_TAG

# This is FSP specific .mk file as error log parser will
# be compiled in FSP enviornment.
# This file only defines the rules for errl plugin libraries.

PLUGIN_NAME = lib${BASE_LIB_NAME}
RULE_LIBRARY_NAME = ${BASE_LIB_NAME}-rule
PRDR_ERRL_LIB = lib${RULE_LIBRARY_NAME}

LIBRARY_OFILES += prdfLogParse.o
LIBRARY_OFILES += prdfLogParse_common.o
#LIBRARY_OFILES += prdfCenLogParse.o TODO RTC 136126
#LIBRARY_OFILES += prdfProcLogParse.o TODO RTC 136050
LIBRARY_OFILES += prdrErrlPluginsSupt.o
LIBRARY_OFILES += prdfParserUtils.o

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

