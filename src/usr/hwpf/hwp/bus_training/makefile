# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/bus_training/makefile $
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

MODULE = bus_training

SUBDIRS += runtime.d

# ROOTPATH must be defined before including this file.
include io_hwp_common_ipl_and_rt.mk

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

OBJS += io_funcs.o
OBJS += io_run_training.o
OBJS += pbusLinkSvc.o
OBJS += io_dccal.o
OBJS += io_restore_erepair.o
OBJS += io_post_trainadv.o
OBJS += io_pre_trainadv.o

##  NOTE: add a new directory onto the vpaths when you add a new HWP
## vpath   %.C proc_cen_framelock:io_run_training
## vpath   %.H proc_cen_framelock:io_run_training

include ${ROOTPATH}/config.mk
