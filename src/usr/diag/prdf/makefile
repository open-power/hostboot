# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2012,2013
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

ROOTPATH = ../../../..

SUBDIRS = framework.d test.d

MODULE = prdf

#------------------------------------------------------------------------------
# paths
#------------------------------------------------------------------------------
PRD_USR_PATH = ${ROOTPATH}/src/usr/diag/prdf

VPATH =  \
    common \
    common/util \
    common/plat \
    common/plat/pegasus \
    common/framework \
    common/framework/resolution \
    common/framework/register \
    common/framework/service \
    common/framework/config \
    common/framework/rule \
    framework \
    framework/rule \

#FIXME: we can remove most of these as well if we have them include correctly
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/util
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/errl
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer

#FIXME: once we fix the PRD includes, we can move most of the prd subdirs below
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/diag/prdf
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/diag/prdf/common
EXTRAINCDIR += ${PRD_USR_PATH}
EXTRAINCDIR += ${PRD_USR_PATH}/common
EXTRAINCDIR += ${PRD_USR_PATH}/common/util
EXTRAINCDIR += ${PRD_USR_PATH}/common/framework/service
EXTRAINCDIR += ${PRD_USR_PATH}/common/framework/register
EXTRAINCDIR += ${PRD_USR_PATH}/common/framework/resolution
EXTRAINCDIR += ${PRD_USR_PATH}/common/framework/config
EXTRAINCDIR += ${PRD_USR_PATH}/common/framework/rule
EXTRAINCDIR += ${PRD_USR_PATH}/common/plat
EXTRAINCDIR += ${PRD_USR_PATH}/common/plat/pegasus
#conditionally enables profiling of flyweight register and resolution object
ifeq ($(PRD_PROFILER),1)
CUSTOMFLAGS += -DFLYWEIGHT_PROFILING
endif
#------------------------------------------------------------------------------
# objects
#------------------------------------------------------------------------------
include common/prd_framework.mk
include common/prd_ruletable.mk
include common/prd_pegasus.mk

OBJS = ${prd_framework} \
	   ${prd_util} \
	   ${prd_register} \
	   ${prd_resolution} \
	   ${prd_ruletable} \
	   ${prd_service} \
	   ${prd_env_service} \
	   ${prd_config} \
	   ${prd_pegasus_specific} ${prd_pegasus_specific_HB} \
	   ${PRDF_RULE_PLUGINS_PEGASUS_WSIM} \
	   ${PRDF_RULE_PLUGINS_PEGASUS}

include ${ROOTPATH}/config.mk
