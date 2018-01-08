# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep09/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2018
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
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
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

# fabric_erepair
include ${PROCEDURES_PATH}/hwp/io/p9_io_xbus_restore_erepair.mk
include ${PROCEDURES_PATH}/hwp/io/p9_io_erepairAccessorHwpFuncs.mk
include ${PROCEDURES_PATH}/hwp/io/p9_io_erepairGetFailedLanesHwp.mk
include ${PROCEDURES_PATH}/hwp/io/p9_io_erepairSetFailedLanesHwp.mk
#Skipping p9_io_xbus_pdwn_lanes, already included by libprdf.so

# fabric_io_dccal
#p9_io_xbus_dccal.mk has includes we dont need so manually add the .o
OBJS+= p9_io_xbus_dccal.o
include ${PROCEDURES_PATH}/hwp/io/p9_io_common.mk

# fabric_pre_trainadv
include ${PROCEDURES_PATH}/hwp/io/p9_io_xbus_pre_trainadv.mk

# fabric_io_run_training
#p9_io_xbus_linktrain.mk has includes we dont need so manually add the .o
OBJS+= p9_io_xbus_linktrain.o
#Skipping p9_io_xbus_clear_firs, already included by libprdf.so

# fabric_post_trainadv
include ${PROCEDURES_PATH}/hwp/io/p9_io_xbus_post_trainadv.mk

# proc_smp_link_layer : Start SMP link layer
include ${PROCEDURES_PATH}/hwp/nest/p9_smp_link_layer.mk

# p9_fbc_eff_config_aggregate
include ${PROCEDURES_PATH}/hwp/nest/p9_fbc_eff_config_aggregate.mk

include ${ROOTPATH}/config.mk
