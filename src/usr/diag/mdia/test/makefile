# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/mdia/test/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2017
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

EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils
##########################################################
# Following is needed to include memdiags.H
##########################################################
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/mcbist
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/targeting/common
EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/ffdc

OBJS += mdiafakesm.o
OBJS += mdiafakecm.o

MODULE = testmdia

TESTS = mdiatestsm.H mdiatesttrace.H mdiatest.H mdiatestworkitem.H mdiatestmonitor.H mdiatestmba.H

include ${ROOTPATH}/config.mk
