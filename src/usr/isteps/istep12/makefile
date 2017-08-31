# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep12/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2017
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
P9_PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p9/procedures
P9_IO_HWP_PATH     = $(P9_PROCEDURES_PATH)/hwp/io
P9_PERV_HWP_PATH   = $(P9_PROCEDURES_PATH)/hwp/perv
P9_NEST_HWP_PATH   = $(P9_PROCEDURES_PATH)/hwp/nest
P9_INITFILE_PATH   = $(P9_PROCEDURES_PATH)/hwp/initfiles

CENT_PROC_PATH     = ${ROOTPATH}/src/import/chips/centaur/procedures
CENT_IO_HWP_PATH   = $(CENT_PROC_PATH)/hwp/io
CENT_MEM_HWP_PATH  = $(CENT_PROC_PATH)/hwp/memory
CENT_INITFILE_PATH = $(CENT_PROC_PATH)/hwp/initfiles

#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/centaur/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += $(P9_PROCEDURES_PATH)/hwp/ffdc/
EXTRAINCDIR += $(P9_IO_HWP_PATH)
EXTRAINCDIR += $(P9_NEST_HWP_PATH)
EXTRAINCDIR += $(P9_PERV_HWP_PATH)
EXTRAINCDIR += $(P9_INITFILE_PATH)
EXTRAINCDIR += $(CENT_MEM_HWP_PATH)
EXTRAINCDIR += $(CENT_INITFILE_PATH)
EXTRAINCDIR += $(CENT_IO_HWP_PATH)

VPATH += $(P9_NEST_HWP_PATH)
VPATH += $(P9_PERV_HWP_PATH)
VPATH += $(P9_IO_HWP_PATH)
VPATH += $(P9_INITFILE_PATH)
VPATH += $(CENT_MEM_HWP_PATH)
VPATH += $(CENT_INITFILE_PATH)
VPATH += $(CENT_IO_HWP_PATH)
VAPTH += ${ROOTPATH}/src/usr/fapi2

OBJS += call_mss_getecid.o
OBJS += call_dmi_attr_update.o
OBJS += call_proc_dmi_scominit.o
OBJS += call_cen_dmi_scominit.o
OBJS += call_dmi_erepair.o
OBJS += call_dmi_io_dccal.o
OBJS += call_dmi_pre_trainadv.o
OBJS += call_dmi_io_run_training.o
OBJS += call_dmi_post_trainadv.o
OBJS += call_proc_cen_framelock.o
OBJS += call_host_startprd_dmi.o
OBJS += call_host_attnlisten_memb.o
OBJS += call_cen_set_inband_addr.o

#Required before all the <procedure>.mk are included
include ${ROOTPATH}/procedure.rules.mk

include $(CENT_MEM_HWP_PATH)/p9c_mss_get_cen_ecid.mk
include $(P9_IO_HWP_PATH)/p9_io_dmi_attr_update.mk
include $(P9_IO_HWP_PATH)/p9_io_dmi_scominit.mk
include $(P9_INITFILE_PATH)/p9c_dmi_io_scom.mk
include $(CENT_IO_HWP_PATH)/p9_io_cen_scominit.mk
include $(P9_IO_HWP_PATH)/p9_io_dmi_restore_erepair.mk
include $(CENT_IO_HWP_PATH)/p9_io_cen_restore_erepair.mk
include $(P9_IO_HWP_PATH)/p9_io_dmi_dccal.mk
include $(CENT_IO_HWP_PATH)/p9_io_cen_dccal.mk
include $(P9_IO_HWP_PATH)/p9_io_dmi_pre_trainadv.mk
include $(P9_IO_HWP_PATH)/p9_io_dmi_linktrain.mk
include $(P9_IO_HWP_PATH)/p9_io_dmi_post_trainadv.mk
include $(P9_PERV_HWP_PATH)/p9_cen_framelock.mk
include $(P9_NEST_HWP_PATH)/p9c_set_inband_addr.mk
include $(P9_IO_HWP_PATH)/p9_io_common.mk
include $(P9_IO_HWP_PATH)/p9_io_dmi_pdwn_lanes.mk
include $(CENT_IO_HWP_PATH)/p9_io_cen_pdwn_lanes.mk
include $(P9_IO_HWP_PATH)/p9_io_dmi_clear_firs.mk
include $(CENT_INITFILE_PATH)/centaur_dmi_scom.mk


include ${ROOTPATH}/config.mk
