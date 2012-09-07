# IBM_PROLOG_BEGIN_TAG 
# This is an automatically generated prolog. 
#  
# $Source: src/usr/runtime/makefile $ 
#  
# IBM CONFIDENTIAL 
#  
# COPYRIGHT International Business Machines Corp. 2012 
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

#
# The runtime module provides code to handle manipulating data
#  for the host.  For example, verifying HDAT fields and writing
#  attribute data for HostServices.
#

ROOTPATH = ../../..
MODULE = runtime

OBJS = populate_attributes.o 

SUBDIRS = test.d

##      support for fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

include ${ROOTPATH}/config.mk
