# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/pm/pm.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2021
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

##      support for fapi2
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/pmlib/include/registers/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/customize/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/

HWP_LIB_PATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/lib/
EXTRAINCDIR += ${HWP_LIB_PATH}
HWP_PM_PATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/pm/
EXTRAINCDIR += ${HWP_PM_PATH}
HWP_STOPUTIL_PATH += ${ROOTPATH}/src/import/chips/p10/procedures/utils/stopreg/
EXTRAINCDIR += ${HWP_STOPUTIL_PATH}
NEST_UTIL_PATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/nest/
EXTRAINCDIR += ${NEST_UTIL_PATH}
CUSTOMIZE_HWP_PATH = ${ROOTPATH}/src/import/chips/p10/procedures/hwp/customize
PERV_HWP_PATH = ${ROOTPATH}/src/import/chips/p10/procedures/hwp/perv
EXTRAINCDIR += ${PERV_HWP_PATH}

# for attnsvc in pm_common.C
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/diag/
EXTRAINCDIR += ${ROOTPATH}/src/usr/diag/attn/

## pointer to already consumed procedures.

##  NOTE: add the base istep dir here.
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += ${ROOTPATH}/src/usr/pnor/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/pnor/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/util/

#common PM Complex functions between ipl and runtime
OBJS += pm_common.o
OBJS += occAccess.o
OBJS += scopedHomerMapper.o
OBJS += p10_pm_utils.o
OBJS += p10_setup_evid.o
OBJS += p10_avsbus_lib.o
OBJS += p10_pstate_parameter_block.o
OBJS += p10_pm_set_system_freq.o
OBJS += p10_pm_get_poundv_bucket.o
OBJS += p10_pm_get_poundw_bucket.o
OBJS += p10_pm_sram_access_utils.o
OBJS += p10_pm_qme_firinit.o
OBJS += p10_pm_pba_firinit.o
OBJS += p10_pm_pba_init.o
OBJS += p10_fbc_core_topo.o
OBJS += p10_fbc_utils.o
OBJS += p10_pm_ocb_init.o
OBJS += p10_pm_ocb_indir_setup_linear.o
OBJS += p10_pm_ocb_indir_access.o
OBJS += p10_pm_occ_control.o
OBJS += p10_pm_occ_firinit.o
OBJS += p10_pm_firinit.o
OBJS += p10_pm_pss_init.o
OBJS += p10_hcode_image_build.o
OBJS += p10_qme_build_attributes.o
OBJS += p10_pm_qme_init.o
OBJS += p10_core_special_wakeup.o
OBJS += p10_pm_xgpe_init.o
OBJS += p10_pm_occ_gpe_init.o
OBJS += p10_pm_ocb_indir_setup_circular.o
OBJS += p10_scan_ring_util.o
OBJS += p10_stop_util.o
OBJS += p10_stop_api.o
OBJS += p10_pm_set_homer_bar.o
OBJS += p10_pm_pba_bar_config.o
OBJS += p10_pm_start.o
OBJS += p10_pm_pgpe_init.o
OBJS += p10_pm_halt.o
OBJS += p10_setup_runtime_wakeup_mode.o
OBJS += p10_qme_customize.o
OBJS += p10_check_proc_config.o
OBJS += p10_core_checkstop_handler.o
OBJS += p10_pm_callout.o

##  NOTE: add a new directory onto the vpaths when you add a new HWP
VPATH += ${HWP_PM_PATH}
VPATH += ${HWP_LIB_PATH}
VPATH += ${HWP_STOPUTIL_PATH}
VPATH += ${CUSTOMIZE_HWP_PATH}
VPATH += ${NEST_UTIL_PATH}
VPATH += ${PERV_HWP_PATH}

include ${ROOTPATH}/procedure.rules.mk
