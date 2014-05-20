# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/common.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2014
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
################################################################################
#
#  @file targeting/common/common.mk
#
#  @brief Common targeting makefile to be included in
#      targeting/makefile
#
################################################################################

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

OTHER_OBJS += util.o
OTHER_OBJS += utilFilter.o
OTHER_OBJS += attributeTank.o

# Common
COMMON_TARGETING_OBJS += ${TARGET_OBJS}
COMMON_TARGETING_OBJS += ${PREDICATES_OBJS}
COMMON_TARGETING_OBJS += ${ITERATORS_OBJS}
COMMON_TARGETING_OBJS += ${OTHER_OBJS}

