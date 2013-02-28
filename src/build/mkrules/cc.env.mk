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

MCP_VER = mcp6

CC_RAW = ppc64-$(MCP_VER)-gcc -std=c99
CXX_RAW = ppc64-$(MCP_VER)-g++
CC = $(TRACEPP) $(CC_RAW)
CXX = $(TRACEPP) $(CXX_RAW)

LD = ppc64-$(MCP_VER)-ld
OBJDUMP = ppc64-$(MCP_VER)-objdump
GCOV = ppc64-$(MCP_VER)-gcov

CUSTOM_LINKER_EXE = $(ROOTPATH)/src/build/linker/linker
CUSTOM_LINKER = i686-$(MCP_VER)-jail $(CUSTOM_LINKER_EXE)

