# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/nest_chiplets/makefile $
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

MODULE = nest_chiplets

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets/proc_start_clocks_chiplets
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets/proc_chiplet_scominit
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets/proc_scomoverride_chiplets
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets/proc_pcie_scominit
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/slave_sbe/proc_cen_ref_clk_enable

##  NOTE: add new object files when you add a new HWP
OBJS += nest_chiplets.o
OBJS += proc_start_clocks_chiplets.o
OBJS += proc_chiplet_scominit.o
OBJS += proc_scomoverride_chiplets.o
OBJS += proc_a_x_pci_dmi_pll_initf.o
OBJS += proc_a_x_pci_dmi_pll_setup.o
OBJS += proc_pcie_scominit.o
OBJS += proc_abus_scominit.o
OBJS += proc_xbus_scominit.o
OBJS += proc_a_x_pci_dmi_pll_utils.o
        
##  NOTE: add a new directory onto the vpaths when you add a new HWP
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets/proc_start_clocks_chiplets
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets/proc_chiplet_scominit
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets/proc_scomoverride_chiplets
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets/proc_pcie_scominit

include ${ROOTPATH}/config.mk

