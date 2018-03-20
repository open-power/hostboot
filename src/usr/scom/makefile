# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/scom/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2018
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
ROOTPATH = ../../..
MODULE = scom

#include common ojects between hostboot and runtime hostboot
include scom.mk

# Configure virtual paths
GENDIR = ${ROOTPATH}/obj/genfiles
VPATH += ${ROOTPATH}/src/import/chips/p9/security/
VPATH += ${GENDIR}

# Defines for targets/prereqs
CENTAUR_SCOM_REG_DEF_SCRIPT=genCentaurScomCacheRegDefs.pl
CENTAUR_SCOM_REG_DEF_BASE=centaurScomCacheRegDefs
CENTAUR_SCOM_REG_DEF_OBJ=${CENTAUR_SCOM_REG_DEF_BASE}.o
CENTAUR_SCOM_REG_DEF_SRC=${CENTAUR_SCOM_REG_DEF_BASE}.C
CENTAUR_SCOM_REG_DEF_CSV=Centaur_Register_List.csv

#include unique object modules
OBJS += $(if $(CONFIG_SECUREBOOT),centaurScomCache.o,)
OBJS += $(if $(CONFIG_SECUREBOOT),${CENTAUR_SCOM_REG_DEF_OBJ},)
OBJS += $(if $(CONFIG_SECUREBOOT),errlud_cache.o,)

# Build rules
all: GENPASS

GENPASS: ${GENDIR}/${CENTAUR_SCOM_REG_DEF_SRC}

# Bring the Centaur SCOM cache register definition initialization source file
# up to date by executing the generation script (first dependency), passing
# it the input .csv file (second dependency) and passing it the output dir
# (the directory part of the rule target .. namely obj/genfiles)
${GENDIR}/${CENTAUR_SCOM_REG_DEF_SRC}: \
    ${CENTAUR_SCOM_REG_DEF_SCRIPT} \
    ${CENTAUR_SCOM_REG_DEF_CSV}
	./$< \
    --csv=$(word 2,$^) \
    --output-dir=$(@D)

SUBDIRS += test.d
SUBDIRS += runtime.d

include ${ROOTPATH}/config.mk
