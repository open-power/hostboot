# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/slave_sbe/makefile $
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

MODULE = slave_sbe

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/slave_sbe
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/slave_sbe/proc_revert_sbe_mcs_setup
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/slave_sbe/proc_getecid
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/slave_sbe/proc_cen_ref_clk_enable
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/slave_sbe/proc_spless_sbe_startWA
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/proc_mailbox_utils


##  NOTE: add new object files when you add a new HWP
OBJS += slave_sbe.o
OBJS += proc_revert_sbe_mcs_setup.o
OBJS += proc_check_slave_sbe_seeprom_complete.o
OBJS += proc_extract_sbe_rc.o
OBJS += proc_read_seeprom.o
OBJS += proc_getecid.o
OBJS += proc_cen_ref_clk_enable.o
OBJS += proc_spless_sbe_startWA.o
OBJS += proc_reset_i2cm_bus_fence.o
OBJS += proc_check_master_sbe_seeprom.o

##  NOTE: add a new directory onto the vpaths when you add a new HWP
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/slave_sbe/proc_cen_ref_clk_enable
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/slave_sbe/proc_revert_sbe_mcs_setup
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/slave_sbe/proc_getecid
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/slave_sbe/proc_spless_sbe_startWA


include ${ROOTPATH}/config.mk

