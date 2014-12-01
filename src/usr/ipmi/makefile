# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/ipmi/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2014
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
MODULE = ipmi

OBJS += ipmimsg.o
OBJS += $(if $(CONFIG_BMC_BT_LPC_IPMI),ipmibt.o)
OBJS += ipmirp.o
OBJS += $(if $(CONFIG_BMC_BT_LPC_IPMI),ipmidd.o)
OBJS += ipmifru.o
OBJS += ipmiconfig.o
OBJS += ipmisensor.o
OBJS += ipmiwatchdog.o
OBJS += ipmifruinv.o

#SUBDIRS += test.d

include ${ROOTPATH}/config.mk
