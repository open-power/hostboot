# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/binfile.rules.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2021
# [+] International Business Machines Corp.
#
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

ifndef SKIP_BINARY_FILES
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
# This rule will only get invoked when GSA is down (hopefully
# temporarily) and as a result Make won't see the binary cache
# file. It will then run this rule to try to "create" the file, and
# the recipe will simply poll for a time until the file comes back. If
# the file doesn't come back in a certain amount of time, the build
# will fail.
$(addprefix $$(BINFILE_CACHE_REMOTEDIR),$(2)):
	@echo GSA Redundancy: Checking existence of $$@ ; \
	CTR=1; \
	while [ ! -f $$@ ] ; do \
	  echo GSA redundancy: waiting on filesystem for file $$@ ... ; \
	  if [ $$$$CTR -gt $$$$((10*60)) ] ; then \
	    echo Timeout waiting for binary cache file $$@ to exist ; \
	    exit 1 ; \
	  fi ; \
	  (( CTR += 1 )) ; \
	  sleep 1 ; \
	done ; \
	echo GSA redundancy: File $$@ became accessible

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
endif
