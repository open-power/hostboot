# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep10/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2017
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
MODULE = istep10

NEST_HWP_PATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/nest
INITFILES_HWP_PATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/initfiles
PERV_HWP_PATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/perv

EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/
EXTRAINCDIR += ${NEST_HWP_PATH}
EXTRAINCDIR += ${INITFILES_HWP_PATH}
EXTRAINCDIR += ${PERV_HWP_PATH}

OBJS += call_proc_build_smp.o
OBJS += call_host_slave_sbe_update.o
OBJS += call_host_update_redundant_tpm.o

VPATH += ${NEST_HWP_PATH}
VPATH += ${INITFILES_HWP_PATH}
VPATH += ${PERV_HWP_PATH}

#Required include before all the procedure.mk are included
include ${ROOTPATH}/procedure.rules.mk

#Include all the procedure makefiles
include $(NEST_HWP_PATH)/p9_build_smp.mk
include ${INITFILES_HWP_PATH}/p9_fbc_ab_hp_scom.mk
include ${INITFILES_HWP_PATH}/p9_fbc_cd_hp_scom.mk
include ${PERV_HWP_PATH}/p9_update_security_ctrl.mk

include ${ROOTPATH}/config.mk
