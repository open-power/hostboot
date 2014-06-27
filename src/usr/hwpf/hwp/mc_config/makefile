# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/mc_config/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2014
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
ROOTPATH = ../../../../..

MODULE = mc_config

CFLAGS += $(if $(CONFIG_PALMETTO_VDDR), -D FAPI_MSSLABONLY -D FAPI_LRDIMM)
EXTRAINCDIR += $(if $(CONFIG_PALMETTO_VDDR), ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_draminit)

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp/utility_procedures/

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
##@ EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/???
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/mc_config/mss_eff_config
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/mc_config/mss_volt
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/mc_config/mss_freq
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_lrdimm_funcs
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/mc_config/mss_eff_pre_config
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/mc_config/mss_attr_cleanup
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/mc_config/mss_eff_mb_interleave

OBJS +=  mc_config.o
OBJS += mss_volt.o
OBJS += mss_freq.o
OBJS += mss_eff_config.o
OBJS += mss_eff_grouping.o
OBJS += opt_memmap.o
OBJS += mss_eff_config_thermal.o
OBJS += mss_eff_config_termination.o
OBJS += mss_eff_config_rank_group.o
OBJS += mss_eff_config_cke_map.o
OBJS += mss_bulk_pwr_throttles.o
OBJS += mss_throttle_to_power.o
OBJS += mss_eff_config_shmoo.o
OBJS += mss_error_support.o
OBJS += mss_eff_pre_config.o
OBJS += mss_attr_cleanup.o
OBJS += mss_eff_mb_interleave.o
OBJS += mss_volt_vdd_offset.o
OBJS += mss_volt_avdd_offset.o
OBJS += mss_volt_vcs_offset.o
OBJS += mss_volt_vpp_offset.o
OBJS += mss_volt_vddr_offset.o
OBJS += mss_count_active_centaurs.o

##  NOTE: add a new directory onto the vpaths when you add a new HWP
##@ VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/???
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/mc_config/mss_eff_config
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/mc_config/mss_volt
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/mc_config/mss_freq
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/mc_config/mss_eff_pre_config
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/mc_config/mss_attr_cleanup
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/mc_config/mss_eff_mb_interleave

include ${ROOTPATH}/config.mk
