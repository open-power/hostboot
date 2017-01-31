# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/pm/pm.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2017
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
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/pmlib/include/registers/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/lib/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/utils/stopreg/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/

HWP_PM_PATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/pm
EXTRAINCDIR += ${HWP_PM_PATH}
HWP_CUST_PATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/customize
EXTRAINCDIR += ${HWP_CUST_PATH}
HWP_ACC_PATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/accessors
EXTRAINCDIR += ${HWP_ACC_PATH}
HWP_XIP_PATH += ${ROOTPATH}/src/import/chips/p9/xip
EXTRAINCDIR += ${HWP_XIP_PATH}
HWP_IMAGEPROCS_PATH += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
HWP_STOPUTIL_PATH += ${ROOTPATH}/src/import/chips/p9/procedures/utils/stopreg/
EXTRAINCDIR += ${HWP_STOPUTIL_PATH}
EXTRAINCDIR += ${HWP_IMAGEPROCS_PATH}
NEST_UTIL_PATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/nest
EXTRAINCDIR += ${NEST_UTIL_PATH}

## pointer to already consumed procedures.

##  NOTE: add the base istep dir here.
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += ${ROOTPATH}/src/usr/pnor/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/pnor/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/util/

#common PM Complex functions between ipl and runtime
OBJS += pm_common.o
OBJS += occAccess.o
OBJS += occCheckstop.o

##  NOTE: add a new directory onto the vpaths when you add a new HWP
VPATH += ${HWP_PM_PATH} ${HWP_CUST_PATH} ${HWP_ACC_PATH}
VPATH += ${HWP_XIP_PATH} ${HWP_IMAGEPROCS_PATH}
VPATH += ${HWP_XIP_PATH} ${HWP_IMAGEPROCS_PATH} ${HWP_STOPUTIL_PATH}
VPATH += ${NEST_UTIL_PATH}

# TODO RTC: 164237
# Take another look at PM lib

include ${ROOTPATH}/procedure.rules.mk
include ${HWP_PM_PATH}/p9_pm_pba_bar_config.mk
include ${HWP_PM_PATH}/p9_pm_pba_init.mk
include ${HWP_PM_PATH}/p9_pm_pba_firinit.mk
include ${HWP_PM_PATH}/p9_pm_utils.mk
include ${HWP_PM_PATH}/p9_pm_ocb_init.mk
include ${HWP_PM_PATH}/p9_pm_ocb_indir_setup_linear.mk
include ${HWP_PM_PATH}/p9_pm_ocb_indir_access.mk
include ${HWP_PM_PATH}/p9_pm_init.mk
include ${HWP_PM_PATH}/p9_pm_occ_control.mk
include ${HWP_PM_PATH}/p9_pm_occ_firinit.mk
include ${HWP_PM_PATH}/p9_pm_corequad_init.mk
include ${HWP_PM_PATH}/p9_pm_firinit.mk
include ${HWP_PM_PATH}/p9_query_cache_access_state.mk
include ${HWP_PM_PATH}/p9_pm_pss_init.mk
include ${HWP_PM_PATH}/p9_pm_cme_firinit.mk
include ${HWP_PM_PATH}/p9_hcode_image_build.mk
include ${HWP_PM_PATH}/p9_pm_stop_gpe_init.mk
include ${HWP_PM_PATH}/p9_pm_pfet_init.mk
include ${HWP_PM_PATH}/p9_pm_reset.mk
include ${HWP_PM_PATH}/p9_pm_occ_sram_init.mk
include ${HWP_PM_PATH}/p9_pm_occ_gpe_init.mk
include ${HWP_PM_PATH}/p9_pm_ppm_firinit.mk
include ${HWP_PM_PATH}/p9_pm_ocb_indir_setup_circular.mk
include ${HWP_PM_PATH}/p9_scan_ring_util.mk
include ${HWP_CUST_PATH}/p9_xip_customize.mk
include ${HWP_ACC_PATH}/p9_get_mvpd_ring.mk
include ${HWP_ACC_PATH}/p9_mvpd_ring_funcs.mk
include ${HWP_XIP_PATH}/p9_xip_image.mk
include ${HWP_IMAGEPROCS_PATH}/p9_dd_container.mk
include ${HWP_IMAGEPROCS_PATH}/p9_tor.mk
include ${HWP_IMAGEPROCS_PATH}/p9_ring_identification.mk
include ${HWP_IMAGEPROCS_PATH}/p9_ringId.mk
include ${HWP_STOPUTIL_PATH}/p9_stop_util.mk
include ${HWP_STOPUTIL_PATH}/p9_stop_api.mk
include ${HWP_IMAGEPROCS_PATH}/p9_scan_compression.mk
include ${NEST_UTIL_PATH}/p9_fbc_utils.mk
include ${HWP_PM_PATH}/p9_pstate_parameter_block.mk
include ${HWP_PM_PATH}/p9_pm_get_poundv_bucket.mk
include ${HWP_PM_PATH}/p9_pm_pstate_gpe_init.mk
include ${HWP_PM_PATH}/p9_check_proc_config.mk
