# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/nest/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2018
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
MODULE = isteps_nest

PROCEDURES_PATH += ${ROOTPATH}/src/import/chips/p9/procedures

EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/initfiles
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/io
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/perv
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/nest
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/

EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/initfiles

OBJS += nestHwpHelperFuncs.o
OBJS += p9_io_obus_firmask_save_restore.o

VPATH += ${PROCEDURES_PATH}/hwp/initfiles
VPATH += ${PROCEDURES_PATH}/hwp/io
VPATH += ${PROCEDURES_PATH}/hwp/nest
VPATH += ${PROCEDURES_PATH}/hwp/perv

# Required include before all the procedure.mk are included
include ${ROOTPATH}/procedure.rules.mk

# proc_chiplet_scominit : Scom inits to all chiplets (sans Quad)
include ${PROCEDURES_PATH}/hwp/initfiles/p9_psi_scom.mk
include ${PROCEDURES_PATH}/hwp/initfiles/p9_fbc_ioo_tl_scom.mk
include ${PROCEDURES_PATH}/hwp/initfiles/p9_fbc_ioo_dl_scom.mk
include ${PROCEDURES_PATH}/hwp/initfiles/p9_nx_scom.mk
include ${PROCEDURES_PATH}/hwp/initfiles/p9_cxa_scom.mk
include ${PROCEDURES_PATH}/hwp/initfiles/p9_mmu_scom.mk
include ${PROCEDURES_PATH}/hwp/initfiles/p9_vas_scom.mk
include ${PROCEDURES_PATH}/hwp/initfiles/p9c_dmi_scom.mk
include ${PROCEDURES_PATH}/hwp/initfiles/p9c_mi_scom.mk
include ${PROCEDURES_PATH}/hwp/initfiles/p9c_mc_scom.mk
include ${PROCEDURES_PATH}/hwp/nest/p9_chiplet_scominit.mk
include ${PROCEDURES_PATH}/hwp/nest/p9_psi_scominit.mk
include ${PROCEDURES_PATH}/hwp/initfiles/p9n_mcs_scom.mk
include ${PROCEDURES_PATH}/hwp/initfiles/p9_int_scom.mk

# call_host_p9_fbc_eff_config_links: Determine powerbus config
include ${PROCEDURES_PATH}/hwp/nest/p9_fbc_eff_config_links.mk

# call_host_set_voltages: Set correct chip voltages
include ${PROCEDURES_PATH}/hwp/nest/p9_sys_chiplet_scominit.mk

# proc_chiplet_enable_ridi : Apply RI/DI chip wide
include ${PROCEDURES_PATH}/hwp/perv/p9_chiplet_enable_ridi.mk

# proc_obus_scominit : Apply scom inits to Obus
include ${PROCEDURES_PATH}/hwp/io/p9_io_obus_scominit.mk
include ${PROCEDURES_PATH}/hwp/initfiles/p9_obus_scom.mk

# proc_npu_scominit : Apply scom inits to NPU bus
include ${PROCEDURES_PATH}/hwp/initfiles/p9_npu_scom.mk
include ${PROCEDURES_PATH}/hwp/nest/p9_npu_scominit.mk
include ${PROCEDURES_PATH}/hwp/perv/p9_nv_ref_clk_enable.mk

include ${ROOTPATH}/config.mk
