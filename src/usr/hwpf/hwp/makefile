# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2016
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
ROOTPATH = ../../../..
HWPPATH = ./
MODULE = hwp

EXTRAINCDIR += ${ROOTPATH}/src/usr/initservice/istepdispatcher

include hwp.mk

OBJS += fapiTestHwp.o
OBJS += fapiTestHwpDq.o
OBJS += fapiHwpExecInitFile.o

#Temporarily compiling these here to avoid linker errors
#This file will eventually be deleted when we delete hwpf/
OBJS += ../isteps/hwpisteperror.o
OBJS += ../isteps/hwpistepud.o

SUBDIRS	+= dmi_training.d
SUBDIRS	+= sbe_centaur_init.d
SUBDIRS	+= dram_training.d
SUBDIRS	+= activate_powerbus.d
SUBDIRS	+= build_winkle_images.d
SUBDIRS	+= core_activate.d
SUBDIRS	+= dram_initialization.d
SUBDIRS	+= edi_ei_initialization.d
SUBDIRS	+= establish_system_smp.d
SUBDIRS	+= bus_training.d
SUBDIRS	+= occ.d
SUBDIRS	+= tod_init.d
SUBDIRS	+= nest_chiplets.d
SUBDIRS	+= start_payload.d
SUBDIRS	+= slave_sbe.d
SUBDIRS	+= pstates.d
SUBDIRS	+= proc_hwreconfig.d
SUBDIRS	+= runtime.d
SUBDIRS	+= secure_boot.d
SUBDIRS	+= mvpd_accessors.d


include ${ROOTPATH}/config.mk
