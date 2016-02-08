# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/pm/pm.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016
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

HWP_PATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/pm
EXTRAINCDIR += ${HWP_PATH}
HWP_XIP_PATH += ${ROOTPATH}/src/import/chips/p9/xip
EXTRAINCDIR += ${HWP_XIP_PATH}
HWP_IMAGEPROCS_PATH += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${HWP_IMAGEPROCS_PATH}

## pointer to already consumed procedures.

##  NOTE: add the base istep dir here.
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/

#common PM Complex functions between ipl and runtime
OBJS += pm_common.o

##  NOTE: add a new directory onto the vpaths when you add a new HWP
VPATH += ${HWP_PATH} ${HWP_XIP_PATH} ${HWP_IMAGEPROCS_PATH}

include ${ROOTPATH}/procedure.rules.mk
include ${HWP_PATH}/p9_pm_pba_bar_config.mk
include ${HWP_PATH}/p9_pm_pba_init.mk
include ${HWP_PATH}/p9_pm_pba_firinit.mk
include ${HWP_PATH}/p9_pm_utils.mk
include ${HWP_PATH}/p9_pm_ocb_init.mk
include ${HWP_PATH}/p9_pm_ocb_indir_setup_linear.mk
include ${HWP_PATH}/p9_pm_ocb_indir_access.mk
include ${HWP_PATH}/p9_pm_init.mk
include ${HWP_PATH}/p9_pm_occ_control.mk
include ${HWP_PATH}/p9_pm_occ_firinit.mk
include ${HWP_PATH}/p9_pm_corequad_init.mk
include ${HWP_PATH}/p9_pm_firinit.mk
include ${HWP_PATH}/p9_pm_pss_init.mk
include ${HWP_PATH}/p9_pm_cme_firinit.mk
include ${HWP_PATH}/p9_hcode_image_build.mk
include ${HWP_PATH}/p9_pm_stop_gpe_init.mk
include ${HWP_PATH}/p9_pm_pfet_init.mk
include ${HWP_PATH}/p9_pm_reset.mk
#TODO RTC:147383 Need to create a seperate module for cpu_special_wakeup
include ${HWP_PATH}/p9_cpu_special_wakeup.mk
include ${HWP_PATH}/p9_cpu_special_wakeup_core.mk
include ${HWP_PATH}/p9_cpu_special_wakeup_ex.mk
include ${HWP_PATH}/p9_cpu_special_wakeup_lib.mk
include ${HWP_PATH}/p9_pm_occ_sram_init.mk
include ${HWP_PATH}/p9_pm_occ_gpe_init.mk
include ${HWP_PATH}/p9_pm_ppm_firinit.mk
include ${HWP_PATH}/p9_pm_ocb_indir_setup_circular.mk
include ${HWP_XIP_PATH}/p9_xip_image.mk
include ${HWP_IMAGEPROCS_PATH}/p9_tor.mk
include ${HWP_IMAGEPROCS_PATH}/p9_ring_identification.mk
include ${HWP_IMAGEPROCS_PATH}/p9_ringId.mk
