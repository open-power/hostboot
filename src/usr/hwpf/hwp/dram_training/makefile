#   IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/hwpf/hwp/dram_training/makefile $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2012
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END_TAG
ROOTPATH = ../../../../..

MODULE = dram_training

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

##  NOTE: add the base istep dir here. 
##@ EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/@istepname
EXTRAINCDIR	+= ${ROOTPATH}/src/usr/hwpf/hwp/dram_training

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
##@ EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/???
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_draminit_training
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_draminit_mc
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_draminit
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_ddr_phy_reset
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mem_startclocks
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_scominit
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mem_pll_setup

##  NOTE: add new object files when you add a new HWP
OBJS =  dram_training.o \
        mss_draminit.o \
        mss_funcs.o \
        mss_draminit_mc.o \
        mss_draminit_training.o \
        mss_ddr_phy_reset.o \
        cen_mem_startclocks.o \
		mss_scominit.o \
        cen_mem_pll_initf.o \
        cen_mem_pll_setup.o
        
   		
##  NOTE: add a new directory onto the vpaths when you add a new HWP
##@ VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/???
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_draminit_training
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_draminit_mc
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_draminit
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_ddr_phy_reset
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mem_startclocks
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_scominit
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mem_pll_setup

include ${ROOTPATH}/config.mk
