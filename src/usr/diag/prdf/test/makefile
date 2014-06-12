# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/test/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2014
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

MODULE = testprdf

#------------------------------------------------------------------------------
# paths
#------------------------------------------------------------------------------
PRD_USR_PATH = ${ROOTPATH}/src/usr/diag/prdf

EXTRAINCDIR += ${ROOTPATH}/src/include/usr/diag/prdf
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/diag/prdf/common
EXTRAINCDIR += ${PRD_USR_PATH}
EXTRAINCDIR += ${PRD_USR_PATH}/common
EXTRAINCDIR += ${PRD_USR_PATH}/common/plugins
EXTRAINCDIR += ${PRD_USR_PATH}/common/util
EXTRAINCDIR += ${PRD_USR_PATH}/common/framework/service
EXTRAINCDIR += ${PRD_USR_PATH}/common/framework/register
EXTRAINCDIR += ${PRD_USR_PATH}/common/framework/resolution
EXTRAINCDIR += ${PRD_USR_PATH}/common/framework/config
EXTRAINCDIR += ${PRD_USR_PATH}/common/framework/rule
EXTRAINCDIR += ${PRD_USR_PATH}/common/plat
EXTRAINCDIR += ${PRD_USR_PATH}/common/plat/pegasus
EXTRAINCDIR += ${PRD_USR_PATH}/common/mnfgtools
EXTRAINCDIR += ${PRD_USR_PATH}/mnfgtools
EXTRAINCDIR += ${PRD_USR_PATH}/framework/service
EXTRAINCDIR += ${PRD_USR_PATH}/test

EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/errl
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/util
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

#------------------------------------------------------------------------------
# objects
#------------------------------------------------------------------------------

OBJS += prdfsimHomRegisterAccess.o
OBJS += prdfsimRasServices.o
OBJS += prdfsimScrDataSet.o
OBJS += prdfsimScrDB.o
OBJS += prdfsimServices.o
OBJS += prdsimSignatureParser.o
OBJS += prdfsimUtil.o
OBJS += prdfsimMfgSync.o
OBJS += prdfsimFspSyncSvc.o
OBJS += prdfsimFspMfgThresholdFile.o

TESTS += prdfTest_MfgSync.H
TESTS += prdfTest_ABus.H
TESTS += prdfTest_Ex.H
TESTS += prdfTest.H
TESTS += prdfTest_Mba.H
TESTS += prdfTest_Mcs.H
TESTS += prdfTest_Proc.H
TESTS += prdfTest_XBus.H
TESTS += prdfTest_McsMciFir.H
TESTS += prdfTest_ProcCentFir.H
TESTS += prdfTest_ProcMbsFir.H
TESTS += prdfTest_ProcTpLFir.H
TESTS += prdfTest_CentCs.H
TESTS += prdfTest_CenTpLFir.H

include ${ROOTPATH}/config.mk
