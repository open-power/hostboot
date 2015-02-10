# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2015
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

ROOTPATH = ../../../..
MODULE = prdf

SUBDIRS += framework.d  # This will eventually compile the rule code. This only
                        # needs to be done once and not for both IPL and RT
						# compiles. This is because compiling the rule code only
						# generates .prf files, which are compiler independent,
						# and a few .C files needed for the error log parser,
						# which is compiled elsewhere.
SUBDIRS += runtime.d
SUBDIRS += test.d

################################################################################

# ROOTPATH must be defined before including this file.
include prdf_hb_only.mk # Will define PRD_SRC_PATH and PRD_INC_PATH

# PRD_SRC_PATH and PRD_INC_PATH must be defined before including this file.
include common/prdf_common_fsp_and_hb.mk

VPATH += ${prd_vpath}

EXTRAINCDIR += ${prd_incpath}

OBJS += ${prd_obj}
OBJS += ${prd_obj_no_sim}
OBJS += ${prd_rule_plugin}

################################################################################

include ${ROOTPATH}/config.mk
