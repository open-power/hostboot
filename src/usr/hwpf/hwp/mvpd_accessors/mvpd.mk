# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/mvpd_accessors/mvpd.mk $
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
CFLAGS += -DDQCOMPRESSION_TEST=1

EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/mvpd_accessors
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp/mvpd_accessors

VPATH += ${HWPPATH}/mvpd_accessors
VPATH += ${HWPPATH}/mvpd_accessors/compressionTool
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
OBJS += getControlCapableData.o
OBJS += accessMBvpdL4BankDelete.o
OBJS += getDecompressedISDIMMAttrs.o
OBJS += getISDIMMTOC4DAttrs.o
OBJS += DQCompressionLib.o
