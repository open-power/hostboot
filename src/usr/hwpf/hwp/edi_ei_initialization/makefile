# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/edi_ei_initialization/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2015
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

MODULE = edi_ei_initialization

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training

##  NOTE: add the base istep dir here.
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/edi_ei_initialization

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
##  EXAMPLE:
##  EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/edi_ei_initialization/<HWP_dir>
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/edi_ei_initialization/proc_fab_iovalid
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/edi_ei_initialization/fabric_io_run_training
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/edi_ei_initialization/fabric_io_dccal
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training/io_pre_trainadv
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training/io_post_trainadv

##  NOTE: add new object files when you add a new HWP
OBJS += smp_unfencing_inter_enclosure_abus_links.o
OBJS += proc_fab_iovalid.o
OBJS += fabric_io_run_training.o
OBJS += fabric_io_dccal.o

##  NOTE: add a new directory onto the vpaths when you add a new HWP
##  EXAMPLE:
#   VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/edi_ei_initialization/<HWP_dir>
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/edi_ei_initialization/proc_fab_iovalid
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/edi_ei_initialization/fabric_io_run_training
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/edi_ei_initialization/fabric_io_dccal
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training/io_pre_trainadv
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training/io_post_trainadv

include ${ROOTPATH}/config.mk

