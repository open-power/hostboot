# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hdat/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2022
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

ROOTPATH = ../../..
MODULE = hdat

EXTRAINCDIR += ../vpd
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include
EXTRAINCDIR += ../util

# spd_ipz_template.dat contains a pre-defined template which depicts the
# IPZ formatted memory info (DDIMM). It contains the size and offsets for
# required keywords like RT, PN, SN etc under VINI record. Template also
# contains VSPD keyword blocks for #I, #A and #B with in specified offsets.
# So in HDAT, each of the Ms Area (filled from ocmb chip) or RAM area
# (filled from ddimm) contains the VPD data in the IPZ format and data is
# filled up by parsing the raw SPD data from each memory resource.
${ROOTPATH}/img/spd_ipz_template.dat:
	cp spd_ipz_template.dat ${ROOTPATH}/img/spd_ipz_template.dat

code_pass: ${ROOTPATH}/img/spd_ipz_template.dat

EXTRA_PARTS = ${ROOTPATH}/img/spd_ipz_template.dat

OBJS += hdatutil.o
OBJS += hdatpcia.o
OBJS += hdatiplparms.o
OBJS += hdathostslcadata.o
OBJS += hdathdif.o
OBJS += hdatvpd.o
OBJS += hdatnaca.o
OBJS += hdatiohub.o
OBJS += hdatmsvpd.o
OBJS += hdatmsarea.o
OBJS += hdatram.o
OBJS += hdatspsubsys.o
OBJS += hdatpcrd.o
OBJS += hdatbldda.o
OBJS += hdatnodedata.o
OBJS += hdathostservices.o
OBJS += hdathbrt.o
OBJS += hdattpmdata.o
OBJS += hdatspiraS.o
OBJS += hdatspiraH.o

include ${ROOTPATH}/config.mk
