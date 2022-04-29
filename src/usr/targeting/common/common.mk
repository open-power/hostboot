# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/common.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2022
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
################################################################################
#
#  @file targeting/common/common.mk
#
#  @brief Common targeting makefile to be included in
#      targeting/makefile
#
################################################################################

CFLAGS += -D__STDC_LIMIT_MACROS
COMMON_TARGETING_SUBDIRS += predicates
COMMON_TARGETING_SUBDIRS += iterators

PREDICATES_OBJS += predicatebase.o
PREDICATES_OBJS += predicatepostfixexpr.o
PREDICATES_OBJS += predicatectm.o
PREDICATES_OBJS += predicateisfunctional.o
PREDICATES_OBJS += predicatehwas.o
PREDICATES_OBJS += predicatehwaschanged.o
PREDICATES_OBJS += predicateisnonfunctional.o

ITERATORS_OBJS += targetiterator.o
ITERATORS_OBJS += rawtargetiterator.o
ITERATORS_OBJS += rangefilter.o

TARGET_OBJS += target.o
TARGET_OBJS += targetservice.o
TARGET_OBJS += entitypath.o
TARGET_OBJS += associationmanager.o
TARGET_OBJS += hbrt_target.o

TARGUTILBASE ?= targutilbase.o # only set UTILBASE if not already defined
OTHER_OBJS += ${TARGUTILBASE}

OTHER_OBJS += util.o
OTHER_OBJS += utilFilter.o
OTHER_OBJS += attributeTank.o
OTHER_OBJS += mapattrmetadata.o
OTHER_OBJS += mfgFlagAccessors.o
OTHER_OBJS += DCMUtils.o

# Common
COMMON_TARGETING_OBJS += ${TARGET_OBJS}
COMMON_TARGETING_OBJS += ${PREDICATES_OBJS}
COMMON_TARGETING_OBJS += ${ITERATORS_OBJS}
COMMON_TARGETING_OBJS += ${OTHER_OBJS}
