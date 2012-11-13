# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
# 
# $Source: src/sys/prof/makefile $
# 
# IBM CONFIDENTIAL
# 
# COPYRIGHT International Business Machines Corp. 2010,2012
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

ROOTPATH = ../../..

# If code coverage profiling is enabled we need to add the gcov object to the
# build list.  This is triggered via the HOSTBOOT_PROFILE variable.  We then
# undefine that variable to ensure that none of the code in this directory is
# instrumented itself.  This is the directory where code which is unsafe to
# instrument should go.

ifdef HOSTBOOT_PROFILE
OBJS = gcov.o
HOSTBOOT_PROFILE =
endif

OBJS += idletask.o

include ${ROOTPATH}/config.mk
