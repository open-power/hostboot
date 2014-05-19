# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/binfile.rules.mk $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2012,2014
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
