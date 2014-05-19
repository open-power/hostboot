# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/sbe_centaur_init/makefile $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2011,2014
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

MODULE = sbe_centaur_init

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

## pointer to fapiporeve files
EXTRAINCDIR += ${ROOTPATH}/src/usr/pore/fapiporeve
EXTRAINCDIR += ${ROOTPATH}/src/usr/pore/poreve/model
EXTRAINCDIR += ${ROOTPATH}/src/usr/pore/poreve/porevesrc

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/sbe_centaur_init
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/p8_slw_build
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/mvpd_accessors


OBJS += sbe_centaur_init.o
OBJS += cen_xip_customize.o

##  NOTE: add a new directory onto the vpaths when you add a new HWP
## VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/sbe_centaur_init/????

include ${ROOTPATH}/config.mk
