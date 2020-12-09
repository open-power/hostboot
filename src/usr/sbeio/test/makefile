# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/sbeio/test/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2020
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

EXTRAINCDIR += ${ROOTPATH}/src/usr/sbeio/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/perv
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/sbe


MODULE = testsbeio

#TESTS = *.H
TESTS  = sbe_ffdctest.H
TESTS += sbe_getsbeffdctest.H
TESTS += sbe_fifo_buffer_test.H
TESTS += sbe_retry_handler_test.H
TESTS += sbe_memregiontest.H
TESTS += sbe_psucommandstest.H
TESTS += sbe_psuSendOcmbConfigTest.H

include ${ROOTPATH}/config.mk
