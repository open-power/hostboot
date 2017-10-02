# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep16/makefile $
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
MODULE = istep16
PROCEDURES_PATH    = ${ROOTPATH}/src/import/chips/p9/procedures


EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/pm/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/perv/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/nest/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/lib/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/io/
EXTRAINCDIR += ${ROOTPATH}/src/import
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/xip/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/pmlib/include/registers/

OBJS += call_host_activate_master.o
OBJS += call_host_activate_slave_cores.o
OBJS += call_host_secure_rng.o
OBJS += call_mss_scrub.o
OBJS += call_host_ipl_complete.o
OBJS += call_host_load_io_ppe.o

include ${ROOTPATH}/procedure.rules.mk
include  ${PROCEDURES_PATH}/hwp/perv/p9_switch_cfsim.mk
include  ${PROCEDURES_PATH}/hwp/perv/p9_switch_rec_attn.mk
include  ${PROCEDURES_PATH}/hwp/nest/p9_rng_init_phase2.mk
include  ${PROCEDURES_PATH}/hwp/io/p9_io_xbus_image_build.mk
include  ${PROCEDURES_PATH}/hwp/io/p9_io_obus_image_build.mk
include  ${PROCEDURES_PATH}/hwp/pm/p9_check_idle_stop_done.mk
include  ${PROCEDURES_PATH}/hwp/pm/p9_cme_sram_access.mk
include  ${PROCEDURES_PATH}/hwp/pm/p9_pm_ocb_indir_setup_linear.mk
include  ${PROCEDURES_PATH}/hwp/pm/p9_pm_ocb_indir_access.mk
include  ${PROCEDURES_PATH}/hwp/pm/p9_pm_recovery_ffdc_base.mk
include  ${PROCEDURES_PATH}/hwp/pm/p9_pm_recovery_ffdc_sgpe.mk
include  ${PROCEDURES_PATH}/hwp/pm/p9_pm_recovery_ffdc_cme.mk
include ${ROOTPATH}/config.mk


VPATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/pm/
VPATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/perv/
VPATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/nest/
VPATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/io/
