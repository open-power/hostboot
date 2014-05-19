# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/slave_sbe/makefile $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2012,2014
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

