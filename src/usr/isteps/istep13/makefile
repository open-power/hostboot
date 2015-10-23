# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep13/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015
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
MODULE = istep13

OBJS += call_host_disable_vddr.o
OBJS += call_mem_pll_initf.o
OBJS += call_mem_pll_setup.o
OBJS += call_proc_mcs_skewadjust.o
OBJS += call_mem_startclocks.o
OBJS += call_host_enable_vddr.o
OBJS += call_mss_scominit.o
OBJS += call_mss_ddr_phy_reset.o
OBJS += call_mss_draminit.o
OBJS += call_mss_draminit_training.o
OBJS += call_mss_draminit_trainadv.o
OBJS += call_mss_draminit_mc.o

OBJS += $(if $(CONFIG_PALMETTO_VDDR),palmetto_vddr.o,hbVddrMsg.o)

include ${ROOTPATH}/config.mk
