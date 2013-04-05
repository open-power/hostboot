# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/cc.env.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2013
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

# File: cc.env.mk
# Description:
#     Configuration of the compiler settings.

CROSS_PREFIX ?= powerpc64-unknown-linux-gnu-
HOST_PREFIX ?= x86_64-pc-linux-gnu-

CC_RAW = $(CROSS_PREFIX)gcc -std=c99
CXX_RAW = $(CROSS_PREFIX)g++
CC = $(TRACEPP) $(CC_RAW)
CXX = $(TRACEPP) $(CXX_RAW)

LD = $(CROSS_PREFIX)ld
OBJDUMP = $(CROSS_PREFIX)objdump
GCOV = $(CROSS_PREFIX)gcov

CUSTOM_LINKER_EXE = $(ROOTPATH)/src/build/linker/linker
CUSTOM_LINKER = $(HOST_PREFIX)jail $(CUSTOM_LINKER_EXE)

