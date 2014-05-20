# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/test/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2012,2014
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
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

include ${ROOTPATH}/config.mk
