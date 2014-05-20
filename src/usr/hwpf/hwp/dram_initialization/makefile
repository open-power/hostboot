# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/dram_initialization/makefile $
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

MODULE = dram_initialization

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training

EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/cen_stopclocks

##  NOTE: add the base istep dir here.
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
##  EXAMPLE:
##  EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/<HWP_dir>
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/proc_exit_cache_contained
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/mss_extent_setup
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/proc_setup_bars
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/mss_memdiag
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/proc_pcie_config
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/host_mpipl_service
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/mss_thermal_init
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp/dram_initialization/mss_memdiag
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/mc_config/mss_eff_config/
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/mss_power_cleanup
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/proc_throttle_sync

##  NOTE: add new object files when you add a new HWP
OBJS += dram_initialization.o
OBJS += proc_exit_cache_contained.o
OBJS += mss_extent_setup.o
OBJS += mss_setup_bars.o
OBJS += proc_fab_smp.o
OBJS += proc_setup_bars.o
OBJS += proc_pcie_config.o
OBJS += proc_mpipl_ex_cleanup.o
OBJS += proc_mpipl_chip_cleanup.o
OBJS += mss_thermal_init.o
OBJS += mss_power_cleanup.o
OBJS += proc_throttle_sync.o


##  NOTE: add a new directory onto the vpaths when you add a new HWP
##  EXAMPLE:
#   VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/<HWP_dir>
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/proc_exit_cache_contained
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/mss_extent_setup
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/proc_setup_bars
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/mss_memdiag
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/proc_pcie_config
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/host_mpipl_service
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/mss_thermal_init
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/mss_power_cleanup
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/proc_throttle_sync

include ${ROOTPATH}/config.mk

