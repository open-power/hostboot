# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep12/makefile $
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
MODULE = istep12

# FIXME RTC: 210975

P10_PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p10/procedures
#P9_PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p9/procedures
P10_IO_HWP_PATH     = $(P10_PROCEDURES_PATH)/hwp/io
#P9_IO_HWP_PATH     = $(P9_PROCEDURES_PATH)/hwp/io
#P9_PERV_HWP_PATH   = $(P9_PROCEDURES_PATH)/hwp/perv
P10_NEST_HWP_PATH   = $(P10_PROCEDURES_PATH)/hwp/nest
#P9_NEST_HWP_PATH   = $(P9_PROCEDURES_PATH)/hwp/nest
#P9_INITFILE_PATH   = $(P9_PROCEDURES_PATH)/hwp/initfiles
#P9_MEMORY_HWP_PATH = $(P9_PROCEDURES_PATH)/hwp/memory

#P9A_MSS_HWP_PATH      = ${ROOTPATH}/src/import/chips/p9a/procedures/hwp/memory/
#P9A_MSS_ACCESSOR_PATH = ${ROOTPATH}/obj/genfiles/chips/p9a/procedures/hwp/memory/lib/

#P9A_MSS_HWP_PATH   = ${ROOTPATH}/src/import/chips/p9a/procedures/hwp/memory/
EXPLORER_HWP_PATH  = ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/
EXPLORER_INC_PATH  = ${ROOTPATH}/src/import/chips/ocmb/explorer/common/include/
#EXPLORER_OMI_HWP_PATH  = ${EXPLORER_HWP_PATH}/lib/omi

#GEM_PROCEDURES_PATH  = ${ROOTPATH}/src/import/chips/ocmb/gemini/procedures


#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/
#EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/explorer/procedures/hwp/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
#EXTRAINCDIR += $(P9_PROCEDURES_PATH)/hwp/ffdc/
EXTRAINCDIR += $(P10_IO_HWP_PATH)
EXTRAINCDIR += $(P10_NEST_HWP_PATH)
#EXTRAINCDIR += $(P9_PERV_HWP_PATH)
#EXTRAINCDIR += $(P9_INITFILE_PATH)
#EXTRAINCDIR += ${P9_MEMORY_HWP_PATH}
#EXTRAINCDIR += ${P9A_MSS_HWP_PATH}
EXTRAINCDIR += ${EXPLORER_HWP_PATH}
EXTRAINCDIR += ${EXPLORER_HWP_PATH}/lib
EXTRAINCDIR += ${EXPLORER_INC_PATH}
#EXTRAINCDIR += ${P9A_MSS_ACCESSOR_PATH}
#EXTRAINCDIR += ${GEM_PROCEDURES_PATH}/hwp/memory
#EXTRAINCDIR += ${GEM_PROCEDURES_PATH}/hwp/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt/

VPATH += $(P10_NEST_HWP_PATH)
#VPATH += $(P9_PERV_HWP_PATH)
VPATH += $(P10_IO_HWP_PATH)
#VPATH += $(P9_INITFILE_PATH)
#VAPTH += ${ROOTPATH}/src/usr/fapi2

OBJS += call_mss_getecid.o
OBJS += call_omi_attr_update.o
OBJS += call_proc_omi_scominit.o
OBJS += call_ocmb_omi_scominit.o
OBJS += call_omi_pre_trainadv.o
OBJS += call_omi_setup.o
#OBJS += call_dmi_io_run_training.o
#OBJS += call_dmi_post_trainadv.o
#OBJS += call_proc_cen_framelock.o
#OBJS += call_host_startprd_dmi.o
#OBJS += call_host_attnlisten_memb.o
#OBJS += call_cen_set_inband_addr.o

# HWP objects needed to set inband addr in istep 12
#OBJS+=p9c_set_inband_addr.o

#Required before all the <procedure>.mk are included
include ${ROOTPATH}/procedure.rules.mk

#include $(P9_IO_HWP_PATH)/p9_io_dmi_attr_update.mk
#include $(P9_IO_HWP_PATH)/p9_io_dmi_scominit.mk
#include $(P9_INITFILE_PATH)/p9c_dmi_io_scom.mk
#include $(P9_IO_HWP_PATH)/p9_io_dmi_restore_erepair.mk
#include $(P9_IO_HWP_PATH)/p9_io_dmi_dccal.mk
#include $(P9_IO_HWP_PATH)/p9_io_dmi_pre_trainadv.mk
#include $(P9_IO_HWP_PATH)/p9_io_dmi_linktrain.mk
#include $(P9_IO_HWP_PATH)/p9_io_dmi_post_trainadv.mk
#include $(P9_IO_HWP_PATH)/p9_io_common.mk
#include $(P9_IO_HWP_PATH)/p9_io_dmi_pdwn_lanes.mk
#include $(P9_IO_HWP_PATH)/p9_io_dmi_clear_firs.mk
#include $(P9_IO_HWP_PATH)/p9_io_erepairAccessorHwpFuncs.mk

#VPATH += $(if $(CONFIG_AXONE),${P9A_MSS_HWP_PATH},)
VPATH += ${EXPLORER_HWP_PATH}
VPATH += ${EXPLORER_HWP_PATH}/lib/workarounds
#VPATH += $(if $(CONFIG_AXONE),${EXPLORER_OMI_HWP_PATH},)
#VPATH += $(if $(CONFIG_AXONE),${P9_MEMORY_HWP_PATH},)
#VPATH += $(if $(CONFIG_AXONE),${GEM_PROCEDURES_PATH}/hwp/memory,)

#OBJS  += $(if $(CONFIG_AXONE),exp_omi_utils.o,)
OBJS  += exp_omi_setup.o
#OBJS  += $(if $(CONFIG_AXONE),exp_omi_train.o,)
#OBJS  += $(if $(CONFIG_AXONE),p9a_omi_train.o,)
#OBJS  += $(if $(CONFIG_AXONE),p9a_omi_train_check.o,)
OBJS += p10_omi_scominit.o
OBJS += p10_fbc_utils.o
OBJS += p10_omi_setup_bars.o
#OBJS  += $(if $(CONFIG_AXONE),p9a_addr_ext.o,)
#OBJS  += $(if $(CONFIG_AXONE),exp_omi_init.o,)
#OBJS  += $(if $(CONFIG_AXONE),p9a_omi_init.o,)
#OBJS  += $(if $(CONFIG_AXONE),p9a_omi_init_scom.o,)
#OBJS += $(if $(CONFIG_AXONE),p9a_omi_io_scom.o,)
#OBJS += $(if $(CONFIG_AXONE),p9a_omic_io_scom.o,)
#OBJS += $(if $(CONFIG_AXONE),p9a_io_omi_scominit.o,)
#OBJS += $(if $(CONFIG_AXONE),p9a_io_omi_dccal.o,)
#OBJS += $(if $(CONFIG_AXONE),gem_getecid.o,)
OBJS += exp_getecid.o


include ${ROOTPATH}/config.mk
