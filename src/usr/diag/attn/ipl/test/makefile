# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/attn/ipl/test/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2014,2020
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
ROOTPATH = ../../../../../..

EXTRAINCDIR += ${ROOTPATH}/src/include/usr/diag
CFLAGS += -iquote${ROOTPATH}/src/usr/diag/attn

OBJS += attnfakesys.o
OBJS += attntest.o
OBJS += attnrand.o
OBJS += attnfakepresenter.o
OBJS += attnfakeprd.o
OBJS += attnfaketarget.o
OBJS += attnrandsource.o
OBJS += attnfakegfir.o
OBJS += attnfakeipoll.o
OBJS += attnvalidate.o
OBJS += attnfakemcs.o
OBJS += attnfakegp1.o
OBJS += attnmeminject.o

MODULE = testattn

TESTS = attntestipl.H attntestproc.H attntestscom.H attntesttrace.H attntesttest.H attntestlist.H attntestops.H attntestsvc.H

include ${ROOTPATH}/config.mk
