# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep16/makefile $
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
MODULE = istep16

PROCEDURES_PATH    = ${ROOTPATH}/src/import/chips/p10/procedures

EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/pm/
#EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/perv/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/nest/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/lib/
#EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory
#EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/io/
EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
#EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
#EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/scominfo/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/
#EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/xip/
#EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/pmlib/include/registers/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/

OBJS += call_host_activate_boot_core.o
OBJS += call_host_activate_secondary_cores.o
OBJS += call_mss_scrub.o
OBJS += call_host_ipl_complete.o

#HWP object file needed to run istep 16
OBJS += p10_query_core_stop_state.o

include ${ROOTPATH}/procedure.rules.mk
include ${PROCEDURES_PATH}/hwp/pm/p10_block_wakeup_intr.mk
include ${PROCEDURES_PATH}/hwp/nest/p10_gen_fbc_rt_settings.mk
#include  ${PROCEDURES_PATH}/hwp/perv/p10_switch_cfsim.mk
#include  ${PROCEDURES_PATH}/hwp/perv/p10_switch_rec_attn.mk
#include  ${PROCEDURES_PATH}/hwp/io/p10_io_xbus_image_build.mk
#include  ${PROCEDURES_PATH}/hwp/io/p10_io_obus_image_build.mk
#include  ${PROCEDURES_PATH}/hwp/pm/p10_check_idle_stop_done.mk
#include  ${PROCEDURES_PATH}/hwp/pm/p10_cme_sram_access.mk
#include  ${PROCEDURES_PATH}/hwp/pm/p10_pm_ocb_indir_setup_linear.mk
#include  ${PROCEDURES_PATH}/hwp/pm/p10_pm_ocb_indir_access.mk
#include  ${PROCEDURES_PATH}/hwp/pm/p10_pm_recovery_ffdc_base.mk
#include  ${PROCEDURES_PATH}/hwp/pm/p10_pm_recovery_ffdc_sgpe.mk
#include  ${PROCEDURES_PATH}/hwp/pm/p10_pm_recovery_ffdc_cme.mk
include ${ROOTPATH}/config.mk

VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/pm/
#VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/perv/
VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/nest/
VPATH += ${ROOTPATH}/src/import/chips/p10/common/scominfo/
#VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/io/
