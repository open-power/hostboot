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
GENDIR = ${ROOTPATH}/obj/genfiles

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
    common/mnfgtools \
    mnfgtools \
    framework \
    framework/rule \
    framework/service \
    plat \
    plat/pegasus \

#FIXME: we can remove most of these as well if we have them include correctly
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/util
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/errl
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training

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
EXTRAINCDIR += ${PRD_USR_PATH}/common/mnfgtools
EXTRAINCDIR += ${PRD_USR_PATH}/mnfgtools
EXTRAINCDIR += ${PRD_USR_PATH}/framework/service
EXTRAINCDIR += ${PRD_USR_PATH}/plat/pegasus

# Conditionally enables profiling of flyweight register and resolution object
ifeq ($(PRD_PROFILER),1)
CUSTOMFLAGS += -DFLYWEIGHT_PROFILING
endif

#------------------------------------------------------------------------------
# objects
#------------------------------------------------------------------------------

include common/prd_framework.mk
include common/prd_ruletable.mk
include common/prd_pegasus.mk
include prdf_hb_only.mk

OBJS = \
 ${prd_object_files} \
 ${prd_object_files_no_sim} \
 ${prd_ruletable} \
 ${prd_pegasus_specific} \
 ${prd_pegasus_specific_HB} \
 ${PRDF_RULE_PLUGINS_PEGASUS} \
 ${PRDF_RULE_PLUGINS_PEGASUS_WSIM} \

#------------------------------------------------------------------------------
# Generated Mfg Threshold Header file
#------------------------------------------------------------------------------
MFG_THRES	    = prdfMfgThresholds
MFG_THRES_H	    = ${MFG_THRES}.H
MFG_THRES_PL    = ${PRD_USR_PATH}/common/mnfgtools/${MFG_THRES}.pl
MFG_THRES_LIST	= ${PRD_USR_PATH}/common/mnfgtools/${MFG_THRES}.lst
RULEOBJDIR      = ${ROOTPATH}/obj/modules/prdf/rule
MFG_THRES_PATH	= ${GENDIR}/${MFG_THRES_H}

GENFILES       = ${MFG_THRES_H}

${MFG_THRES_PATH} : ${MFG_THRES_LIST}
	${MFG_THRES_PL} $^ > $@

EXTRA_CLEAN    = ${MFG_THRES_PATH}




include ${ROOTPATH}/config.mk
