# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep06/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2016
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
MODULE = istep06

#Add all the object files required for istep06 module
OBJS += host_init_fsi.o
OBJS += host_set_ipl_parms.o
OBJS += host_discover_targets.o
OBJS += call_host_update_master_tpm.o
OBJS += host_gard.o
OBJS += call_host_revert_sbe_mcs_setup.o
OBJS += host_start_occ_xstop_handler.o
OBJS += call_host_voltage_config.o

SUBDIRS	+= thread_activate.d

HWP_PATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/nest
VPATH    += ${HWP_PATH}

#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/usr/sbe
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/secureboot
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/nest
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include

#Required include before all the procedure.mk are included
include ${ROOTPATH}/procedure.rules.mk

#Include all the procedure makefiles
include $(HWP_PATH)/p9_revert_sbe_mcs_setup.mk

include ${ROOTPATH}/config.mk
