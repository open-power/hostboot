# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/pnor/test/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2021
# [+] Google Inc.
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

EXTRAINCDIR += ${ROOTPATH}/src/usr/pnor/
EXTRAINCDIR += $(if $(CONFIG_FILE_XFER_VIA_PLDM),${ROOTPATH}/src/subtree/openbmc/pldm/libpldm)

MODULE = testpnor

TESTS = pnorddtest.H ecctest.H pnorrptest.H pnorutilsTest.H

#SFC Implementations
TESTS += $(if $(CONFIG_SFC_IS_IBM_DPSS),sfc_ibmtest.H)
#@fixme-RTC:146146-Reenable testcases once ECC issues are resolved
#TESTS += $(if $(CONFIG_SFC_IS_AST2400),sfc_ast2400test.H)

include ${ROOTPATH}/config.mk
