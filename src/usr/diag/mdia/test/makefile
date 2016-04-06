# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/mdia/test/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2016
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

EXTRAINCDIR += ${ROOTPATH}/src/include/usr/diag

##########################################################
# Following are needed to include hwpf/hwp/fapi.H
##########################################################
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp
##########################################################
# Following is needed to include mss_maint_cmds.H
##########################################################
#EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp TODO RTC 145132

OBJS += mdiafakesm.o
OBJS += mdiafakecm.o

MODULE = testmdia

#TODO RTC 148565 - reenable test cases once they are updated
#TESTS = *.H

include ${ROOTPATH}/config.mk
