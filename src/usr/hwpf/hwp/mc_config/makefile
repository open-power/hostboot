# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/mc_config/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2012,2014
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
#
# IBM_PROLOG_END_TAG
ROOTPATH = ../../../../..

MODULE = mc_config

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

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

##  NOTE: add a new directory onto the vpaths when you add a new HWP
##@ VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/???
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/mc_config/mss_eff_config
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/mc_config/mss_volt
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/mc_config/mss_freq
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/mc_config/mss_eff_pre_config
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/mc_config/mss_attr_cleanup
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/mc_config/mss_eff_mb_interleave

include ${ROOTPATH}/config.mk
