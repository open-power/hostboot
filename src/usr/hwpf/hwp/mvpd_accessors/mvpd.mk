# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/mvpd_accessors/mvpd.mk $
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
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/mvpd_accessors
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp/mvpd_accessors

VPATH += ${HWPPATH}/mvpd_accessors

OBJS += getMvpdRing.o
OBJS += getMBvpdRing.o
OBJS += setMvpdRing.o
OBJS += mvpdRingFuncs.o
OBJS += getMvpdExL2SingleMemberEnable.o
OBJS += getMBvpdPhaseRotatorData.o
OBJS += getMBvpdAddrMirrorData.o
OBJS += getMBvpdTermData.o
OBJS += getMBvpdSlopeInterceptData.o
OBJS += getMBvpdSpareDramData.o
OBJS += getMBvpdVersion.o
OBJS += getMBvpdDram2NModeEnabled.o
OBJS += getMBvpdSensorMap.o
OBJS += accessMBvpdL4BankDelete.o

