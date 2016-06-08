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
OBJS += call_proc_fab_iovalid.o
OBJS += call_host_fbc_eff_config_aggregate.o

VPATH += ${PROCEDURES_PATH}/hwp/nest/ ${PROCEDURES_PATH}/hwp/io/

include ${ROOTPATH}/procedure.rules.mk

#@TODO RTC:134079 Re-enable for l2 story
# -- waiting for ekb fix for p9_io_xbus_restore_erepair.mk
# fabric_erepair
#include ${PROCEDURES_PATH}/hwp/io/p9_io_xbus_restore_erepair.mk
#include ${PROCEDURES_PATH}/hwp/io/p9_io_xbus_pdwn_lanes.mk

# fabric_io_dccal
include ${PROCEDURES_PATH}/hwp/io/p9_io_xbus_dccal.mk

# fabric_pre_trainadv
include ${PROCEDURES_PATH}/hwp/io/p9_io_xbus_pre_trainadv.mk

# fabric_io_run_training
include ${PROCEDURES_PATH}/hwp/io/p9_io_xbus_linktrain.mk
include ${PROCEDURES_PATH}/hwp/io/p9_io_xbus_clear_firs.mk

# fabric_post_trainadv
include ${PROCEDURES_PATH}/hwp/io/p9_io_xbus_post_trainadv.mk

# proc_smp_link_layer : Start SMP link layer
include ${PROCEDURES_PATH}/hwp/nest/p9_smp_link_layer.mk

# p9_fab_iovalid
include ${PROCEDURES_PATH}/hwp/nest/p9_fab_iovalid.mk

# p9_fbc_eff_config_aggregate
include ${PROCEDURES_PATH}/hwp/nest/p9_fbc_eff_config_aggregate.mk

include ${ROOTPATH}/config.mk
