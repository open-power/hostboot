# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/binfile.rules.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2012,2013
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

# File: binfile.rules.mk
# Description:
#     Rules for copying files from the binary file cache.

ifdef BINARY_FILES

# Rules for BINARY_FILES directive.
#
#    The BINARY_FILES directives are used to include files out of the binary
#    files cache (see 'hb cacheadd' command).  This cache exists to keep
#    binary files outside of git, because they take a larger space in the git
#    database, especially if they change frequently.
#
#    The BINARY_FILES variable is a set of <destination>:<hash_value> pairs.
#    The destination is where the make system should put the file.  The hash
#    value tells which version of a file to use and it comes from the
#    'hb cacheadd' tool when a version of the file is added to the binary
#    files cache.
#
define __BINARY_CACHE_FILE
GEN_PASS_POST += $(1)
CLEAN_TARGETS += $(1)

ifneq "$(wildcard $(addprefix $(BINFILE_CACHE_LOCALDIR),$(2)))" ""
$(1) : $(addprefix $$(BINFILE_CACHE_LOCALDIR),$(2))
	$$(C2) "    BINFILE    $$(notdir $$@)"
	$$(C1)echo "$(2) $$<" | sha1sum --check > /dev/null
	$$(C1)cp $$< $$@
else
$(1) : $(addprefix $$(BINFILE_CACHE_REMOTEDIR),$(2))
	$$(C2) "    BINFILE    $$(notdir $$@)"
	$$(C1)echo "$(2) $$<" | sha1sum --check > /dev/null
	$$(C1)cp $$< $$@
endif
endef

$(foreach file,$(BINARY_FILES), \
	  $(eval $(call __BINARY_CACHE_FILE, \
			    $(firstword $(subst :, ,$(file))), \
			    $(lastword $(subst :, ,$(file))) \
	  )) \
)

endif
