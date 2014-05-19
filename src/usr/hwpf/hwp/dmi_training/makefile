# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/dmi_training/makefile $
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

MODULE = dmi_training

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/proc_cen_framelock
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/dmi_io_run_training
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/proc_cen_set_inband_addr
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/mss_getecid
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/dmi_io_dccal
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training/io_pre_trainadv
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training/io_post_trainadv
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/proc_dmi_scominit
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/cen_dmi_scominit

OBJS += dmi_training.o
OBJS += proc_cen_framelock.o
OBJS += dmi_io_run_training.o
OBJS += proc_cen_set_inband_addr.o
OBJS += mss_get_cen_ecid.o
OBJS += dmi_io_dccal.o
OBJS += proc_dmi_scominit.o
OBJS += cen_dmi_scominit.o
OBJS += mss_get_cen_ecid_decode.o

##  NOTE: add a new directory onto the vpaths when you add a new HWP
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/proc_cen_framelock
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/dmi_io_run_training
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/proc_cen_set_inband_addr
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/mss_getecid
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/dmi_io_dccal
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training/io_pre_trainadv
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training/io_post_trainadv
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/proc_dmi_scominit
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/cen_dmi_scominit

include ${ROOTPATH}/config.mk
