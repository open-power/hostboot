# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/occ/occ.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2014,2015
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
##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

## pointer to already consumed procedures.
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar

##  NOTE: add the base istep dir here.
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/occ

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
##  EXAMPLE:
##  EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/occ/<HWP_dir>
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/occ/occ_procedures
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp/utility_procedures

##  NOTE: add new object files when you add a new HWP
OBJS += p8_pba_init.o
OBJS += p8_pm_init.o
OBJS += p8_pcbs_init.o
OBJS += p8_pmc_init.o
OBJS += p8_poregpe_init.o
OBJS += p8_oha_init.o
OBJS += p8_ocb_init.o
OBJS += p8_pss_init.o
OBJS += p8_occ_control.o
OBJS += p8_occ_sram_init.o
OBJS += p8_pm_firinit.o
OBJS += p8_pm_oha_firinit.o
OBJS += p8_pm_pcbs_firinit.o
OBJS += p8_pm_occ_firinit.o
OBJS += p8_pm_pba_firinit.o
OBJS += p8_pm_pmc_firinit.o
OBJS += p8_pm_utils.o


#These procedures are included per Stradale's request so
#they can implement OCC Reset.
OBJS += p8_pm_prep_for_reset.o
OBJS += p8_pmc_force_vsafe.o
OBJS += p8_ocb_indir_access.o
OBJS += p8_ocb_indir_setup_linear.o

#common occ functions between ipl and runtime
OBJS += occ_common.o
OBJS += occ.o
OBJS += $(if $(CONFIG_HTMGT),occAccess.o)

##  NOTE: add a new directory onto the vpaths when you add a new HWP
##  EXAMPLE:
#   VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/occ/<HWP_dir>
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/occ/occ_procedures


