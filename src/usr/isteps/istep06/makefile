# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep06/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2024
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

#Add all the object files required for istep06 module
OBJS += host_init_fsi.o
OBJS += host_set_ipl_parms.o
OBJS += host_discover_targets.o
OBJS += call_host_update_primary_tpm.o
OBJS += host_gard.o
OBJS += call_host_voltage_config.o
OBJS += dt_trim_read_restart_ddr5.o

SUBDIRS += thread_activate.d

PERV_HWP_PATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/perv
PM_HWP_PATH   += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/pm
LIB_HWP_PATH  += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/lib
PMLIB_PATH += ${ROOTPATH}/src/import/chips/p10/common/pmlib/
DDR5_HWP_PATH += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/

VPATH += ${PERV_HWP_PATH}
VPATH += ${PM_HWP_PATH}
VPATH += ${LIB_HWP_PATH}
VPATH += ${DDR5_HWP_PATH}

#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/plat
EXTRAINCDIR += ${ROOTPATH}/src/usr/sbe
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/secureboot
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include
#EXTRAINCDIR += ${NEST_HWP_PATH}
EXTRAINCDIR += ${PERV_HWP_PATH}
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${PM_HWP_PATH}
EXTRAINCDIR += ${LIB_HWP_PATH}
#EXTRAINCDIR += ${CORE_HWP_PATH}
#EXTRAINCDIR += ${CACHE_HWP_PATH}
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt
EXTRAINCDIR += ${ROOTPATH}/src/usr/
EXTRAINCDIR += ${ROOTPATH}/src/subtree/openbmc/pldm/libpldm/include/libpldm
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic/lib/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic/lib/i2c
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/common/procedures/hwp/pmic/lib/


#Required include before all the procedure.mk are included
include ${ROOTPATH}/procedure.rules.mk

#TODO-RTC:257623-Consolidate this into 3rd-party module to avoid duplication
OBJS += p10_setup_sbe_config.o
OBJS += p10_sbe_scratch_regs.o

#include $(PM_HWP_PATH)/p9_query_core_access_state.mk
#include $(PM_HWP_PATH)/p9_query_cache_access_state.mk
#include $(PM_HWP_PATH)/p9_quad_power_off.mk

#OBJS+=p9_hcd_core_stopclocks.o
#OBJS+=p9_hcd_cache_stopclocks.o
#OBJS+=p9_hcd_l2_stopclocks.o

MODULE=istep06
include ${ROOTPATH}/config.mk
