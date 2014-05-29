# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/passes.rules.mk $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2013,2014
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

# File: passes.rules.mk
# Description:
#     Definition of the generic rules for executing a pass.
#
# Passes have 3 stages: PRE, BODY, POST.  The 'pre' stage is where required
# directories are created.  The 'body' stage is where most of the actions
# occur.  The 'post' stage is where subdirectories are recursed into.
#
# Other makefiles can extend any stage to include more than the default
# behavior by adding to [NAME]_PASS_[STAGE].

ALL_PASSES = $(DEFAULT_PASSES) $(OTHER_PASSES)

# In order to build all, we just have to satisfy all of the dependencies for
# the last pass's 'POST' stage.
.PHONY: all
all: _BUILD/PASSES/$(lastword $(DEFAULT_PASSES))/POST

# A bogus recipe to suppress makes 'nothing to do' messages.
.PHONY: suppress_nothing_to_do
suppress_nothing_to_do:
	@true

# A big template to define the actions for each pass/stage pair.
#
# Each of the passes/stages have two goals named _BUILD/PASSES/[PASS]/[STAGE]
# and _BUILD/PASSES/[PASS]/[STAGE]/ACT.  The ACT goal is where the work goes
# and the non-ACT goal is just a redirection into a sub-make process.
#
# If we do not do the redirection then make would deeply interrogate the
# dependencies and think that PRE actions can run at the same time as BODY
# actions.  By having the redirection the [STAGE] is not complete until the
# [STAGE]/ACT make invocation is complete, and therefore [STAGE+1] won't start
# since [STAGE+1] requires [STAGE].
#
# We also define a shortcut to 'make [PASS]_PASS' for each pass.
define PASS_template

    # Add subdirectories to the 'post' requirements.
ifeq ($(1),CLEAN)
$(1)_PASS_PRE += $$(addprefix _BUILD/SUBDIR/$(1)/,$$(SUBDIRS:.d=))
else
$(1)_PASS_POST += $$(addprefix _BUILD/SUBDIR/$(1)/,$$(SUBDIRS:.d=))
endif

    # Definition on how to build a subdirectory.
_BUILD/SUBDIR/$(1)/%:
	$$(C2) "    MAKE       $$(notdir $$@) $(1)"
	$$(C1)cd $$(notdir $$@) && $$(MAKE) $(1)_PASS

.PHONY: _BUILD/PASSES/$(1)/PRE
.PHONY: _BUILD/PASSES/$(1)/PRE/ACT
.PHONY: _BUILD/PASSES/$(1)/BODY
.PHONY: _BUILD/PASSES/$(1)/BODY/ACT
.PHONY: _BUILD/PASSES/$(1)/POST
.PHONY: _BUILD/PASSES/$(1)/POST/ACT

_BUILD/PASSES/$(1)/POST : _BUILD/PASSES/$(1)/BODY
ifneq ($$(strip $$($(1)_PASS_POST)),)
	@$$(MAKE) _BUILD/PASSES/$(1)/POST/ACT
endif
_BUILD/PASSES/$(1)/POST/ACT : $$($(1)_PASS_POST) suppress_nothing_to_do

_BUILD/PASSES/$(1)/BODY : _BUILD/PASSES/$(1)/PRE
ifneq ($$(strip $$($(1)_PASS_BODY)),)
	@$$(MAKE) _BUILD/PASSES/$(1)/BODY/ACT
endif
_BUILD/PASSES/$(1)/BODY/ACT : $$($(1)_PASS_BODY) suppress_nothing_to_do

_BUILD/PASSES/$(1)/PRE :  suppress_nothing_to_do
ifneq ($$(strip $$($(1)_PASS_PRE)),)
	@$$(MAKE) _BUILD/PASSES/$(1)/PRE/ACT
endif
_BUILD/PASSES/$(1)/PRE/ACT : $$($(1)_PASS_PRE) suppress_nothing_to_do

.PHONY: $(1)_PASS
$(1)_PASS : _BUILD/PASSES/$(1)/POST

endef

# Instantiate the pass-template for each pass.
$(foreach pass,$(ALL_PASSES),$(eval $(call PASS_template,$(pass))))

# If we are executing 'make' or 'make all' we need to create the dependency
# chain for all of the DEFAULT_PASSES.  Only do this if in this special make
# invocation because otherwise when we recurse to SUBDIR/PASS that directory
# would re-execute SUBDIR/PASS-1.

define PASS_REQ_template
_BUILD/PASSES/$(1)/PRE : _BUILD/PASSES/$(2)/POST
endef

APPLY_PASS_REQ=$(if $(findstring $(lastword $(1)),$(firstword $(1))),, \
		 $(eval \
		    $(call PASS_REQ_template,$(word 2, $(1)),$(word 1, $(1)))) \
		 $(call APPLY_PASS_REQ,$(wordlist 2, 100, $(1))))

# Apply the dependency chain to all of the DEFAULT_PASSES if no make directive
# or 'make all'.
ifeq ($(MAKECMDGOALS),)
$(call APPLY_PASS_REQ,$(DEFAULT_PASSES))
endif

ifeq ($(MAKECMDGOALS),all)
$(call APPLY_PASS_REQ,$(DEFAULT_PASSES))
endif

# Special rule for CLEAN pass that will delete a file (path/to/file) from
# a rule _BUILD/CLEAN/path/to/file.
.PHONY: _BUILD/CLEAN/%
_BUILD/CLEAN/% :
	$(C2) "    RM         $(notdir $@)"
	$(C1) rm -f $(subst _BUILD/CLEAN/,,$@)

