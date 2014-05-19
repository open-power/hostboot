# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/makefile $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2012,2014
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

ROOTPATH = ../../../..
GENDIR = ${ROOTPATH}/obj/genfiles

SUBDIRS = framework.d test.d

MODULE = prdf

#------------------------------------------------------------------------------
# paths
#------------------------------------------------------------------------------
PRD_USR_PATH = ${ROOTPATH}/src/usr/diag/prdf

VPATH += common
VPATH += common/util
VPATH += common/plat
VPATH += common/plat/pegasus
VPATH += common/framework
VPATH += common/framework/resolution
VPATH += common/framework/register
VPATH += common/framework/service
VPATH += common/framework/config
VPATH += common/framework/rule
VPATH += common/mnfgtools
VPATH += mnfgtools
VPATH += framework
VPATH += framework/config
VPATH += framework/rule
VPATH += framework/service
VPATH += framework/resolution
VPATH += plat
VPATH += plat/pegasus
VPATH += common/plugins

#FIXME: we can remove most of these as well if we have them include correctly
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/util
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/errl
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ibscom
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training

#FIXME: once we fix the PRD includes, we can move most of the prd subdirs below
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/diag/prdf
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/diag/prdf/common
EXTRAINCDIR += ${PRD_USR_PATH}
EXTRAINCDIR += ${PRD_USR_PATH}/common
EXTRAINCDIR += ${PRD_USR_PATH}/common/plugins
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
EXTRAINCDIR += ${PRD_USR_PATH}/framework/config
EXTRAINCDIR += ${PRD_USR_PATH}/framework/resolution
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

OBJS += ${prd_object_files}
OBJS += ${prd_object_files_no_sim}
OBJS += ${prd_ruletable}
OBJS += ${prd_pegasus_specific}
OBJS += ${prd_object_files_HB}
OBJS += ${PRDF_RULE_PLUGINS_PEGASUS}
OBJS += ${PRDF_RULE_PLUGINS_PEGASUS_HB}
OBJS += ${PRDF_RULE_PLUGINS_PEGASUS_WSIM}

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

#------------------------------------------------------------------------------

include ${ROOTPATH}/config.mk
