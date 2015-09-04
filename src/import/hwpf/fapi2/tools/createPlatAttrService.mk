# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: hwpf/fapi2/tools/createPlatAttrService.mk $
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

# Makefile to run fapi2CreateAttrGetSetMacros.pl script.

GENERATED = createPlatAttrService
$(GENERATED)_COMMAND_PATH = $(FAPI2_SCRIPT_PATH)/
COMMAND = fapi2CreateAttrGetSetMacros.pl

SOURCES += $(GENPATH)/attribute_ids.H
TARGETS += plat_attribute_service.H

define createPlatAttrService_RUN
		$(C1) cd $$($(GENERATED)_PATH) && $$<
endef

$(call BUILD_GENERATED)
