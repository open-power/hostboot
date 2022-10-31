# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/errldisplay/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2022
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

ROOTPATH = ../../..
MODULE = errldisplay

OBJS += errldisplay.o
OBJS += errldisplaydata.o

#PRDF Error Sigs
include ${ROOTPATH}/src/usr/diag/prdf/common/rule/prdf_rule.mk
prd_rule_disp_targets = ${PRDR_RULE_TABLES:.prf=.prf.disp.o}
OBJS += $(if $(CONFIG_CONSOLE_OUTPUT_FFDCDISPLAY),${prd_rule_disp_targets})

include ${ROOTPATH}/config.mk

# To find errldisplaydata.C - it is generated
# by ../errl/parser/genErrlParsers.pl
vpath %.C ${GENDIR} ${GENDIR}/plugins/prdf/
vpath %.C ${GENDIR} ${GENDIR}/plugins/prdf/rule

#To find hbfwErrDisplayPlatHwpErr add extra include paths
EXTRAINCDIR += ${GENDIR}/plugins
EXTRAINCDIR += ${GENDIR}/plugins/prdf/
EXTRAINCDIR += ${ROOTPATH}/src/usr/diag/prdf/plugins/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/scominfo/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/explorer/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/odyssey/common/include/

