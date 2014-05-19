# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/bus_training/makefile $
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

MODULE = bus_training

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

OBJS += gcr_funcs.o
OBJS += io_funcs.o
OBJS += io_run_training.o
OBJS += pbusLinkSvc.o
OBJS += io_dccal.o
OBJS += io_power_down_lanes.o
OBJS += io_read_erepair.o
OBJS += io_clear_firs.o
OBJS += io_fir_isolation.o
OBJS += io_restore_erepair.o
OBJS += erepairAccessorHwpFuncs.o
OBJS += erepairGetFailedLanesHwp.o
OBJS += erepairSetFailedLanesHwp.o
OBJS += io_post_trainadv.o
OBJS += io_pre_trainadv.o
OBJS += io_cleanup.o


##  NOTE: add a new directory onto the vpaths when you add a new HWP
## vpath   %.C proc_cen_framelock:io_run_training
## vpath   %.H proc_cen_framelock:io_run_training

include ${ROOTPATH}/config.mk
