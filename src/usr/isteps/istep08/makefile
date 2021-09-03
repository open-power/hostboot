# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep08/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2021
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
MODULE = istep08

PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p10/procedures
HWP_PATH_P10 += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/perv

EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/nest/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/pm/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/lib/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/io/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/initfiles/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/sbe/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/perv/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/pmlib/include/registers/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt/
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += ${ROOTPATH}/src/usr/sbeio/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/

OBJS += call_host_secondary_sbe_config.o
OBJS += call_host_setup_sbe.o
OBJS += call_host_cbs_start.o
OBJS += call_proc_check_secondary_sbe_seeprom_complete.o
OBJS += call_host_attnlisten_proc.o
OBJS += call_proc_fbc_eff_config.o
OBJS += call_proc_eff_config_links.o
OBJS += call_proc_attr_update.o
OBJS += call_proc_chiplet_fabric_scominit.o
OBJS += call_host_set_voltages.o
OBJS += call_proc_io_scominit.o
OBJS += call_proc_load_ioppe.o
OBJS += call_proc_init_ioppe.o
OBJS += call_proc_iohs_enable_ridi.o

VPATH += $(PROCEDURES_PATH)/hwp/perv/ $(PROCEDURES_PATH)/hwp/nest/
VPATH += ${ROOTPATH}/src/import/chips/p10/common/include/
VPATH += ${PROCEDURES_PATH}/hwp/initfiles/
VPATH += ${PROCEDURES_PATH}/hwp/lib/
VPATH += ${PROCEDURES_PATH}/hwp/pm/
VPATH += ${PROCEDURES_PATH}/hwp/io/
VPATH += ${ROOTPATH}/src/usr/isteps/

include ${ROOTPATH}/procedure.rules.mk

# host_slave_sbe_config
OBJS += p10_setup_sbe_config.o
OBJS += p10_sbe_scratch_regs.o
# proc_check_secondary_sbe_seeprom_complete
OBJS += p10_getecid.o

# host_setup_sbe
OBJS += p10_set_fsi_gp_shadow.o

# host_cbs_start
OBJS += p10_start_cbs.o
OBJS += p10_clock_test.o
OBJS += p10_clock_test_cmn.o

# proc_fbc_eff_config
OBJS += p10_fbc_eff_config.o

# proc_eff_config_links
OBJS += p10_fbc_eff_config_links.o
OBJS += p10_fbc_utils.o

# proc_attr_update: Proc ATTR Update
OBJS += p10_attr_update.o

# proc_chiplet_fabric_scominit : Scom inits to all chiplet fabric
OBJS += p10_smp_link_firs.o
OBJS += p10_chiplet_fabric_scominit.o
OBJS += p10_fbc_ptl_scom.o
OBJS += p10_fbc_no_hp_scom.o
OBJS += p10_fbc_dlp_scom.o

# host_set_voltages
# istep08Dependancies includes p10_pm_utils.o, libpm.so
# istep06 and istep08 use p10_setup_evid.o

# proc_io_scominit
OBJS += p10_iohs_scominit.o
OBJS += p10_iohs_scom.o
OBJS += p10_io_omi_scominit.o
OBJS += p10_omi_scom.o
OBJS += p10_omic_scom.o

# proc_load_ioppe
OBJS += p10_io_load_ppe.o
OBJS += p10_putsram.o
# p10_getputsram_utils.o needed by p10_putsram.o
OBJS += p10_getputsram_utils.o
OBJS += p10_putsram_io_ppe.o
# p10_io_ppe_utils.o needed by p10_putsram_io_ppe.o
OBJS += p10_io_ppe_utils.o
# p10_write_xram.o needed by p10_putsram.o
OBJS += p10_write_xram.o
# need setPhyLoadDone
OBJS += p10_iop_xram_utils.o
# need p10_qme_sram_access_bytes
OBJS += p10_qme_sram_access.o

# proc_init_ioppe
OBJS += p10_io_init_start_ppe.o
OBJS += p10_io_ppe_lib.o
OBJS += p10_io_ppe_regs.o
OBJS += p10_io_power.o
OBJS += p10_io_lib.o

# proc_iohs_enable_ridi : Apply RI/DI for IOHS
OBJS += p10_iohs_enable_ridi.o
OBJS += p10_enable_ridi.o

OBJS+=p10_chiplet_enable_ridi.o

include ${ROOTPATH}/config.mk
