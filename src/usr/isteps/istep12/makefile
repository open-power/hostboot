# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep12/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2023
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

OCMB_PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/ocmb/procedures

P10_PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p10/procedures
P10_IO_HWP_PATH     = $(P10_PROCEDURES_PATH)/hwp/io
P10_NEST_HWP_PATH   = $(P10_PROCEDURES_PATH)/hwp/nest
P10_INITFILE_PATH   = $(P10_PROCEDURES_PATH)/hwp/initfiles
P10_MEMORY_HWP_PATH = $(P10_PROCEDURES_PATH)/hwp/memory

EXPLORER_HWP_PATH  = ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/
EXPLORER_INC_PATH  = ${ROOTPATH}/src/import/chips/ocmb/explorer/common/include/
ODYSSEY_HWP_PATH   = ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/
ODYSSEY_INC_PATH   = ${ROOTPATH}/src/import/chips/ocmb/odyssey/common/include/

#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/generic/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/p10/procedures/hwp/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/p10/procedures/hwp/memory/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/explorer/procedures/hwp/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/odyssey/procedures/hwp/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += $(P10_IO_HWP_PATH)
EXTRAINCDIR += $(P10_NEST_HWP_PATH)
EXTRAINCDIR += $(P10_INITFILE_PATH)
EXTRAINCDIR += ${P10_MEMORY_HWP_PATH}
EXTRAINCDIR += ${EXPLORER_HWP_PATH}
EXTRAINCDIR += ${EXPLORER_HWP_PATH}/lib
EXTRAINCDIR += ${EXPLORER_INC_PATH}
EXTRAINCDIR += ${OCMB_PROCEDURES_PATH}/hwp/initfiles
EXTRAINCDIR += ${ODYSSEY_HWP_PATH}/memory
EXTRAINCDIR += ${ODYSSEY_HWP_PATH}/memory/lib
EXTRAINCDIR += ${ODYSSEY_HWP_PATH}/io
EXTRAINCDIR += ${ODYSSEY_HWP_PATH}/io/common
EXTRAINCDIR += ${ODYSSEY_INC_PATH}
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt/

VPATH += $(P10_NEST_HWP_PATH)
VPATH += $(P10_IO_HWP_PATH)
VPATH += $(P10_INITFILE_PATH)

OBJS += call_mss_getecid.o
OBJS += call_omi_attr_update.o
OBJS += call_proc_omi_scominit.o
OBJS += call_ocmb_omi_scominit.o
OBJS += call_omi_pre_trainadv.o
OBJS += call_omi_setup.o
OBJS += call_omi_io_run_training.o
OBJS += call_omi_post_trainadv.o
OBJS += call_omi_train_check.o
OBJS += call_host_attnlisten_memb.o
OBJS += call_host_omi_init.o
OBJS += call_update_omi_firmware.o

#Required before all the <procedure>.mk are included
include ${ROOTPATH}/procedure.rules.mk

VPATH += ${EXPLORER_HWP_PATH}
VPATH += ${EXPLORER_HWP_PATH}/lib/workarounds
VPATH += ${ODYSSEY_HWP_PATH}/memory
VPATH += ${ODYSSEY_HWP_PATH}/memory/lib/inband
VPATH += ${ODYSSEY_HWP_PATH}/io
VPATH += ${ODYSSEY_HWP_PATH}/io/common
VPATH += ${P10_MEMORY_HWP_PATH}

OBJS += exp_omi_setup.o
OBJS += p10_omi_setup.o
OBJS += exp_omi_train.o
OBJS += p10_omi_train.o
OBJS += exp_omi_train_check.o
OBJS += p10_omi_train_check.o
OBJS += p10_omi_scominit.o
OBJS += p10_fbc_utils.o
OBJS += p10_omi_setup_bars.o
OBJS += exp_omi_init.o
OBJS += p10_omi_init.o
OBJS += p10_omi_init_scom.o
OBJS += exp_getecid.o
OBJS += p10_io_omi_pre_trainadv.o
OBJS += p10_io_omi_post_trainadv.o
OBJS += p10_io_lib.o
OBJS += p10_io_power.o
OBJS += p10_io_ppe_lib.o
OBJS += p10_io_ppe_regs.o
OBJS += p10_init_mem_encryption.o
OBJS += p10_io_omi_prbs.o
OBJS += p10_io_tdr.o
OBJS += p10_omi_isolation.o
OBJS += exp_process_image_status.o
OBJS += ody_getecid.o
OBJS += ody_omi_init.o
OBJS += ody_host_draminit.o
OBJS += ody_omi_hss_ppe_load.o
OBJS += ody_omi_hss_config.o
OBJS += ody_omi_hss_ppe_start.o
OBJS += ody_omi_hss_bist_init.o
OBJS += ody_omi_hss_bist_start.o
OBJS += ody_omi_hss_bist_poll.o
OBJS += ody_omi_hss_bist_cleanup.o
OBJS += ody_omi_hss_init.o
OBJS += ody_omi_hss_dccal_start.o
OBJS += ody_omi_hss_dccal_poll.o
OBJS += ody_omi_hss_tx_zcal.o
OBJS += ody_omi_pretrain_adv.o
OBJS += ody_omi_setup.o
OBJS += ody_omi_train.o
OBJS += ody_omi_train_check.o
OBJS += ody_inband.o
OBJS += ody_putsram.o
OBJS += ody_putsram_io_ppe.o
OBJS += io_ppe_cache.o
OBJS += common_io_omi_tdr.o
OBJS += common_io_tdr.o
OBJS += io_scom_lib.o


include ${ROOTPATH}/config.mk
