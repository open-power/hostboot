# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: hwpf/fapi2/src/fapi2.mk $
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
# Makefile to build the FAPI2 libraries.
#


# Add common and generated parts to object list.
FAPI2_MODULE_OBJS += error_info.o
FAPI2_MODULE_OBJS += ffdc.o
FAPI2_MODULE_OBJS += fapi2_attribute_service.o
FAPI2_MODULE_OBJS += fapi2_chip_ec_feature.o

# Define common source and include paths.
define FAPI2_MODULE_INCLUDES
$(call ADD_MODULE_SRCDIR,$(1),$(GENPATH))
$(call ADD_MODULE_INCDIR,$(1),$(FAPI2_PATH)/include)
$(call ADD_MODULE_INCDIR,$(1),$(FAPI2_PLAT_INCLUDE))
endef

# Build real FAPI2 library that uses Cronus platform.
MODULE = fapi2
OBJS += $(FAPI2_MODULE_OBJS)
$(eval $(call FAPI2_MODULE_INCLUDES,$(MODULE)))
lib$(MODULE)_EXTRALIBS += $(FAPI2_REQUIRED_LIBS)
lib$(MODULE)_LDFLAGS += -ldl
$(call BUILD_MODULE)

# Build test FAPI2 library that uses the reference platform.
# To do this, we just add the extra 'plat' directories to the srcdir / incdir
# before the Cronus platform directories.
MODULE = fapi2_reference
OBJS += $(FAPI2_MODULE_OBJS)
OBJS += plat_utils.o
$(call ADD_MODULE_SRCDIR,fapi2_reference,$(FAPI2_PATH)/src/plat)
$(call ADD_MODULE_INCDIR,fapi2_reference,$(FAPI2_PATH)/include/plat)
$(eval $(call FAPI2_MODULE_INCLUDES,$(MODULE)))
$(call BUILD_MODULE)
