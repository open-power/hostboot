# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep09/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2020
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

PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p10/procedures
MODULE = istep09

EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/nest/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/io/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc

OBJS += call_proc_io_dccal_done.o
OBJS += call_fabric_dl_pre_trainadv.o
OBJS += call_fabric_dl_setup_training.o
OBJS += call_proc_fabric_link_layer.o
OBJS += call_fabric_dl_post_trainadv.o
OBJS += call_proc_fabric_iovalid.o
OBJS += call_proc_fbc_eff_config_aggregate.o
OBJS += p10_smp_wrap.o

VPATH += ${PROCEDURES_PATH}/hwp/nest/ ${PROCEDURES_PATH}/hwp/io/

# HWP objects
OBJS += p10_io_init_done.o
OBJS += p10_io_ppe_lib.o
OBJS += p10_io_ppe_regs.o
OBJS += p10_fabric_dl_setup_linktrain.o
OBJS += p10_fabric_dl_pre_trainadv.o
OBJS += p10_fabric_link_layer.o
OBJS += p10_fabric_dl_post_trainadv.o
OBJS += p10_fabric_iovalid.o
OBJS += p10_fbc_eff_config_aggregate.o
OBJS += p10_fbc_utils.o

include ${ROOTPATH}/config.mk
