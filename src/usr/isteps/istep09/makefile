# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep09/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2016
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
PROCEDURES_PATH    = ${ROOTPATH}/src/import/chips/p9/procedures
MODULE = istep09

EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/nest/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/io/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/

OBJS += call_fabric_erepair.o
OBJS += call_fabric_io_dccal.o
OBJS += call_fabric_pre_trainadv.o
OBJS += call_fabric_io_run_training.o
OBJS += call_fabric_post_trainadv.o
OBJS += call_proc_smp_link_layer.o
OBJS += call_host_startprd_pbus.o
OBJS += call_host_attnlisten_proc.o
OBJS += call_proc_fab_iovalid.o

VPATH += ${PROCEDURES_PATH}/hwp/nest/ ${PROCEDURES_PATH}/hwp/io/

include ${ROOTPATH}/procedure.rules.mk

#@TODO RTC:134079 Re-enable for l2 story
# 9.1 fabric_erepair
# include ${PROCEDURES_PATH}/hwp/io/p9_io_xbus_restore_erepair.mk
# include ${PROCEDURES_PATH}/hwp/io/p9_io_xbus_pdwn_lanes.mk

# 9.2 fabric_io_dccal
include ${PROCEDURES_PATH}/hwp/io/p9_io_xbus_dccal.mk

# 9.3 fabric_pre_trainadv
include ${PROCEDURES_PATH}/hwp/io/p9_io_xbus_pre_trainadv.mk

#//@TODO RTC:134079 Re-enable for l2 story
# 9.4 fabric_io_run_training
# include ${PROCEDURES_PATH}/hwp/io/p9_io_xbus_linktrain.mk

# 9.5 fabric_post_trainadv
include ${PROCEDURES_PATH}/hwp/io/p9_io_xbus_post_trainadv.mk

# 9.6 proc_smp_link_layer : Start SMP link layer
include ${PROCEDURES_PATH}/hwp/nest/p9_smp_link_layer.mk

# 9.7 & 9.8 - no hwp

# 9.9 p9_fab_iovalid
include ${PROCEDURES_PATH}/hwp/nest/p9_fab_iovalid.mk


include ${ROOTPATH}/config.mk
