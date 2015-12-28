# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: chips/p9/procedures/hwp/memory/lib/mss.mk $
#
# IBM CONFIDENTIAL
#
# EKB Project
#
# COPYRIGHT 2015
# [+] International Business Machines Corp.
#
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# IBM_PROLOG_END_TAG

#
# Makefile to build the MSS libraries.
#

# Add common and generated parts to object list.

MSS_PATH := $(ROOTPATH)/chips/p9/procedures/hwp/memory/lib

MSS_SOURCE := $(shell find $(MSS_PATH) -name '*.C' -exec basename {} \;)
MSS_MODULE_OBJS += $(patsubst %.C,%.o,$(MSS_SOURCE))

MSS_SOURCE_DIRS := $(shell find $(MSS_PATH) -type d)

# Define common source and include paths.
define MSS_MODULE_INCLUDES
$(foreach dir, $(MSS_SOURCE_DIRS), $(call ADD_MODULE_SRCDIR,$(1),$(dir)))
$(call ADD_MODULE_INCDIR,$(1),$(GENPATH))
$(call ADD_MODULE_INCDIR,$(1),$(FAPI2_PLAT_INCLUDE))
endef

MODULE = mss
OBJS += $(MSS_MODULE_OBJS)
$(eval $(call MSS_MODULE_INCLUDES,$(MODULE)))
$(call BUILD_MODULE)
