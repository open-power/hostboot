# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/dist.rules.mk $
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

#
# Makefile rules defining all the actions for the Hostboot content delivery.
#
# Note: White-space is important for make.  An attempt to make these readable
#       and within the 80-character guidelines was done but in a few cases
#       this was not possible.
#


# Default target to 'ALL' which is equivalent to a release.  ALL will
# build all of the targets as subdirectories within the TARGET_DIR.
.DEFAULT_GOAL := ALL
.PHONY: ALL
ALL: $(addsuffix _TARGET_AS_SUBDIR, $(VALID_TARGETS))

# Dummy target to force building of some ODE mk directives.
.PHONY: FORCE_ALWAYS
FORCE_ALWAYS:

# Comma has special meaning to make function-calls, so need it defined as a
# variable for when you want to concatenate or search against a comma.
COMMA = ,

# ------------- '--test' target directives ---------------------
#
# UNDERSCORE_TEST is set to _test when hbDistribute is called with --test
# and set to the empty string otherwise.
#
# TESTVAR_CHANGED_FILE is a file (.hostboot_testvar_changed) which will hold
# 0 or 1 indicating the --test status for the last execution.  This allows
# us to rebuild a lot of targets when someone switches between test and not.
#
# TESTVAR_CHANGED is a 'function' that will return "changed" or "no-changed"
# depending on the value of the .hostboot_testvar_changed file.  This is used
# to force the TESTVAR_CHANGED_FILE to get rebuilt, which causes anything
# depending on it to also get rebuilt, if the --test parameter has changed.
# The forcing is done via the .PHONY directive.
#
UNDERSCORE_TEST = $(if $(TARGET_TEST),_test)
TESTVAR_CHANGED_FILE = $(TARGET_DIR)/.hostboot_testvar_changed
TESTVAR_CHANGED = $(if $(wildcard $(TESTVAR_CHANGED_FILE)),\
			    $(if $(findstring $(if $(TARGET_TEST),1,0),\
					$(shell cat $(TESTVAR_CHANGED_FILE))),\
					no-change,changed),\
			    changed)
ifeq (changed,$(findstring changed,$(TESTVAR_CHANGED)))
    .PHONY: $(TESTVAR_CHANGED_FILE)
endif
$(TESTVAR_CHANGED_FILE):
	@echo $(if $(TARGET_TEST),1,0) > $@

# ------------- File searching directives ----------------------
# ROOTPATH_WILDCARD and ROOTPATH_WILDCARD_RECURSIVE are useful functions
# for defining targets (in dist.targets.mk) where a .../path/* is wanted.
#
# ROOTPATH_WILDCARD takes a file-path-pattern relative to the ROOTPATH and
# returns all the files matching it.  (Ex. src/build/debug/Hostboot/*.pm).
#
# ROOTPATH_WILDCARD_RECURSIVE takes a file-path relative to the ROOTPATH and
# returns all the files beneith it.  (Ex. src/usr/targeting/common)
#
#
# The utility functions _RECURSIVE_WILDCARD and RECURSIVE_WILDCARD are used
# to perform the searching. _RECURSIVE_WILDCARD finds all files inside a
# specific directory. RECURSIVE_WILDCARD finds all non-directory entities
# inside a specific directory.
#
_RECURSIVE_WILDCARD = $(wildcard $(addsuffix /*,$(1)))
RECURSIVE_WILDCARD = $(if $(call _RECURSIVE_WILDCARD, $(1)),\
			$(foreach path,$(call _RECURSIVE_WILDCARD, $(1)), \
			          $(call RECURSIVE_WILDCARD, $(path))), \
			$(1))

ROOTPATH_WILDCARD = $(subst $(ROOTPATH)/,,$(wildcard $(ROOTPATH)/$(1)))
ROOTPATH_WILDCARD_RECURSIVE = $(subst $(ROOTPATH)/,,\
				$(call RECURSIVE_WILDCARD, $(ROOTPATH)/$(1)))

# ------------- ODE sandbox directives ----------------------
# If we are trying to build the FSP target and SANDBOXROOT/SANDBOXNAME
# is part of the destination directory then we are trying to populate an
# ODE sandbox.  Therefore, we need to define some variables to allow
# running commands in the sandbox.  Otherwise, we'll define a simple echo
# that tells the user what we would have done.
#
# EXECUTE_IN_SANDBOX is the define command for running something in a
# sandbox.  We have to create a small shell script containing what we
# want to run in the sandbox and then point 'workon' at it.
#
ifeq ($(MAKECMDGOALS),fsp_TARGET)
ifdef SANDBOXROOT
ifdef SANDBOXNAME
HB_SANDBOX = $(SANDBOXROOT)/$(SANDBOXNAME)
HB_SANDBOXRC = $(SANDBOXROOT)/hbsandboxrc
HB_SANDBOX_CMD = $(HB_SANDBOX)/src/.sandbox_execute_cmd
ifneq (,$(findstring $(HB_SANDBOX), $(TARGET_DIR)))
HB_FOUND_A_SANDBOX = yes
EXECUTE_IN_SANDBOX = echo "$(strip $(1))" > $(HB_SANDBOX_CMD) && \
		     chmod 700 $(HB_SANDBOX_CMD) && \
		     workon -rc $(HB_SANDBOXRC) -m $(2) -sb $(SANDBOXNAME) \
			    -c $(HB_SANDBOX_CMD) && \
		     rm $(HB_SANDBOX_CMD)
endif
endif
endif
endif

ifndef HB_FOUND_A_SANDBOX
HB_FOUND_A_SANDBOX = no
EXECUTE_IN_SANDBOX = echo "    [CONTEXT=$(strip $(2))] $(1)"
endif

#
# __SOURCE_FOR_TARGET utility function takes a three-tuple of
# [ 1=target, 2=source, 3=comma-separated-targets ].
#
# If the current target (1) is in the list (3) then the source is returned.
# If the list (3) contains 'all' then the source is returned, unless the
# current target (1) is 'tools'.
#
# Ex:
#     __SOURCE_FOR_TARGET("fsp", "foobar", "vpo,tools") => ""
#     __SOURCE_FOR_TARGET("fsp", "foobar", "fsp,vpo") => "foobar"
#     __SOURCE_FOR_TARGET("fsp", "foobar", "all") => "foobar"
#     __SOURCE_FOR_TARGET("tools", "foobar", "all") => ""
#
__SOURCE_FOR_TARGET = $(if $(findstring tools,$(1)), \
			   $(if $(findstring $(1),$(3)),$(2)),\
			   $(if $(or $(findstring $(1),$(3)),\
			             $(findstring all,$(3))\
			         ),\
			         $(2)) \
		       )
# ------------- COPY_FILE directives ----------------------
# COPY_FILES format is <source file>:<comma separated targets>
#
# For each file in COPY_FILES and target, we need to create a recipe of:
# $(TARGET_DIR)$(TARGET)/$(FILE) depends on $(ROOTPATH)/$(FILE)
#
# Since we don't have a $(TARGET) sub-directory when building a single
# target, there is also a recipe for the root $(TARGET_DIR)/$(FILE).
#
# __COPY_TARGET_RULE is a function that creates a single recipe from
#                    parameters (1=filepath, 2=target).
#
# COPY_TARGET_RULE is a function that creates a recipe for each target
#                  from parameter (1=filepath).
#
# Finally, a for-loop is done over every file in COPY_FILES to
# instantiate their recipes.
#
define __COPY_TARGET_RULE
$(TARGET_DIR)$(2)/$(notdir $(1)): $(ROOTPATH)/$(1) $(TESTVAR_CHANGED_FILE)
	@mkdir -p $$(dir $$@)
	@echo "    CP $$(notdir $$@)" && cp -r $$< $$@
endef
define COPY_TARGET_RULE
$(call __COPY_TARGET_RULE,$(1))
$(foreach targ,$(VALID_TARGETS), \
    $(eval $(call __COPY_TARGET_RULE,$(1),/$(targ))))
endef
$(foreach targ,$(COPY_FILES), \
    $(eval $(call COPY_TARGET_RULE,$(firstword $(subst :, ,$(targ))))))

# ------------- COPY_RENAME_FILE directives ----------------------
# COPY_RENAME_FILES format is:
#     <dest file>:<source file>:<comma separated targets>
#
# For each file in COPY_RENAME_FILES and target, we need to create a recipe:
# $(TARGET_DIR)$(TARGET)/$(DEST) depends on $(ROOTPATH)/$(SOURCE)
#
# Since we don't have a $(TARGET) sub-directory when building a single
# target, there is also a recipe for the root $(TARGET_DIR)/$(DEST).
#
# __COPY_RENAME_TARGET_RULE is a function that creates a single recipe from
#                           parameters (1=dest, 2=source, 3=target).
#
# COPY_RENAME_TARGET_RULE is a function that creates a recipe for each target
#                         from parameter (1=dest, 2=source).
#
# Finally, a for-loop is done over every file in COPY_RENAME_FILES to
# instantiate their recipes.
#
define __COPY_RENAME_TARGET_RULE
$(TARGET_DIR)$(3)/$(1): $(ROOTPATH)/$(2) $(TESTVAR_CHANGED_FILE)
	@mkdir -p $$(dir $$@)
	@echo "    CP-RENAME $$(notdir $$<) $$(notdir $$@)" && cp -r $$< $$@
endef
define COPY_RENAME_TARGET_RULE
$(call __COPY_RENAME_TARGET_RULE,$(1),$(2))
$(foreach targ,$(VALID_TARGETS), \
    $(eval $(call __COPY_RENAME_TARGET_RULE,$(1),$(2),/$(targ))))
endef
$(foreach targ,$(COPY_RENAME_FILES), \
    $(eval $(call COPY_RENAME_TARGET_RULE,$(firstword $(subst :, ,$(targ))),$(word 2,$(subst :, ,$(targ))))))

# ------------- LINK_FILE directives ----------------------
# LINK_FILES format is:
#     <dest link>:<source file>:<comma separated targets>
#
# For each file in LINK_FILES and target, we need to create a recipe:
# $(TARGET_DIR)$(TARGET)/$(DEST) depends on $(TARGET_DIR)$(TARGET)/$(SOURCE)
#
# Since we don't have a $(TARGET) sub-directory when building a single
# target, there is also a recipe for the root $(TARGET_DIR)/$(DEST).
#
# __LINK_TARGET_RULE is a function that creates a single recipe from
#                    parameters (1=dest, 2=source, 3=target).
#
# LINK_TARGET_RULE is a function that creates a recipe for each target
#                  from parameter (1=dest, 2=source).
#
# Finally, a for-loop is done over every file in LINK_FILES to
# instantiate their recipes.
#
define __LINK_TARGET_RULE
$(TARGET_DIR)$(3)/$(1): $(TARGET_DIR)$(3)/$(2) $(TESTVAR_CHANGED_FILE)
	@mkdir -p $$(dir $$@)
	@echo "    LINK $$(notdir $$<) $$(notdir $$@)" && \
	    ln -sf $$(notdir $$<) $$@
endef
define LINK_TARGET_RULE
$(call __LINK_TARGET_RULE,$(1),$(2))
$(foreach targ,$(VALID_TARGETS), \
    $(eval $(call __LINK_TARGET_RULE,$(1),$(2),/$(targ))))
endef
$(foreach targ,$(LINK_FILES), \
    $(eval $(call LINK_TARGET_RULE,$(firstword $(subst :, ,$(targ))),$(word 2,$(subst :, ,$(targ))))))

# ------------- TAR file directives ----------------------
# <TARFILE>_CONTENTS format is:
#     <file>[:<kept root of path>]
#
# For each file in TAR_FILES and target, we need to create a recipe:
# $(TARGET_DIR)$(TARGET)/$(TARFILE) depends on [a bunch of content].
#
# The content is determined by iterating through all of the files listed
# in <TARFILE>_CONTENTS and calling TAR_CONTENT_SOURCEFILE.
#
# Since there is potential renaming going on as part of the TAR creation
# process, the recipe template for creating a TAR is longer than the others.
# We need to create a temporary directory, populate it with the content,
# create the TAR file, and then remove the temporary directory.
#
# Since we don't have a $(TARGET) sub-directory when building a single
# target, there is also a recipe for the root $(TARGET_DIR)/$(DEST).
#
# TAR_CONTENT_SOURCEFILE / DESTFILE are functions for extrapolating the
# source / dest names from a line in the <TARFILE>_CONTENTS.  The source
# is simply $(ROOTPATH)/$(FILE).  The dest is relative to the root of the
# TAR file.  When the file in _CONTENTS doesn't have the optional parameter
# then the destination is just the filename, otherwise we have to strip
# everything before the optional parameter from the source path.
#
# __TAR_TARGET_RULE is a function that creates a single recipe from
#                    parameters (1=tar file, 2=target).
#
# TAR_TARGET_RULE is a function that creates a recipe for each target
#                  from parameter (1=tar file).
#
# Finally, a for-loop is done over every file in TAR_FILES to
# instantiate their recipes.
#
TAR_CONTENT_SOURCEFILE = \
    $(addprefix $(ROOTPATH)/,$(firstword $(subst :, ,$(1))))
TAR_CONTENT_DESTFILE = \
    $(addprefix $(word 2, $(subst :, ,$(1))), \
	$(if $(word 2, $(subst :, ,$(1))),\
	    $(lastword $(subst $(word 2, $(subst :, ,$(1))), , \
			   $(firstword $(subst :, ,$(1))))), \
	    $(notdir $(1))\
	 )\
     )

define __TAR_TARGET_RULE
$(TARGET_DIR)$(2)/$(1): TAR_TEMP_DIR:=$$(shell mktemp -du)
$(TARGET_DIR)$(2)/$(1): $$(foreach file, $$($(1)_CONTENTS), \
			    $$(call TAR_CONTENT_SOURCEFILE, $$(file))) \
			$(TESTVAR_CHANGED_FILE)
	@echo "    TAR $$(notdir $$@)"
	@mkdir $$(TAR_TEMP_DIR)
	@$$(foreach file, $$($(1)_CONTENTS), \
	    echo "        ADD-FILE" $$(call TAR_CONTENT_DESTFILE,$$(file)) ; \
	    mkdir -p $$(TAR_TEMP_DIR)/$$(dir \
		    $$(call TAR_CONTENT_DESTFILE, $$(file))) ;\
	    cp $$(call TAR_CONTENT_SOURCEFILE, $$(file)) \
	       $$(addprefix $$(TAR_TEMP_DIR)/, \
	           $$(subst $$(UNDERSCORE_TEST),,\
		       $$(call TAR_CONTENT_DESTFILE, $$(file)))) ;\
	    )
	@tar --create --file $$@ -C $$(TAR_TEMP_DIR)/ .
	@touch $$@
	@rm -rf $$(TAR_TEMP_DIR)
endef
define TAR_TARGET_RULE
$(call __TAR_TARGET_RULE,$(1))
$(foreach targ,$(VALID_TARGETS), \
    $(eval $(call __TAR_TARGET_RULE,$(1),/$(targ))))
endef
$(foreach targ,$(TAR_FILES), \
    $(eval $(call TAR_TARGET_RULE,$(firstword $(subst :, ,$(targ))))))

# ------------- ODE_REMAKE directives ----------------------
# <TARGET>_ODE_REMAKES format is:
#     <fsp dir>:<mk target>:<context>:<dependency>.
#
# For each directive in <TARGET>_ODE_REMAKES, we need to create a recipe
# that calls into the ODE sandbox and performs a 'mk' operation.  In
# order to reduce the number of 'mk' calls done we allow the ODE_REMAKE
# directives to be dependent upon something created for the target (such
# as a tarfile).  __ODE_REMAKE_TARGET is a function that creates a
# filename to touch based on the sandbox subdirectory and context where the
# 'mk' operation is being performed.
#
# The recipes override the environment variable MAKEFLAGS because ODE 'mk'
# interprets this in bad ways.  (Error about not knowing how to build target
# "rR".)
#
# The recipes are defined as ".NOTPARALLEL" as a safe-guard to ensure we only
# call into the sandbox one at a time even if someone were to call this
# makefile with '-j'.
#
# ODE_REMAKE_RULE is a function called when instantiating a target
# (see _ODE_REMAKE_DEPS below) to instantiate the ODE remake receipe and
# return the __ODE_REMAKE_TARGET filename for the ODE directive.
#
__ODE_REMAKE_TARGET = .ode_built_$(subst /,_,$(firstword $(subst :, ,$(1)))__$(word 2,$(subst :, ,$(1))))
define __ODE_REMAKE_RULE
.NOTPARALLEL : $(TARGET_DIR)/$(1)$(call __ODE_REMAKE_TARGET,$(2))
$(TARGET_DIR)/$(1)$(call __ODE_REMAKE_TARGET, $(2)) : MAKEFLAGS=
$(TARGET_DIR)/$(1)$(call __ODE_REMAKE_TARGET, $(2)) : \
    $(lastword $(subst :, ,$(2)))
	@echo ODE_MK $(firstword $(subst :, ,$(2)))
	@$$(call EXECUTE_IN_SANDBOX,\
	    mkdir -p $(firstword $(subst :, ,$(2))) && \
	    cd $(firstword $(subst :, ,$(2))) && \
	    mk -O1 -a $(subst NOTARGET,,$(word 2, $(subst :, ,$(2)))),\
	    $(word 3, $(subst :, ,$(2))))
	@touch $$@
endef
ODE_REMAKE_RULE = $(eval $(call __ODE_REMAKE_RULE,,$(2)))\
		  $(call __ODE_REMAKE_TARGET,$(2))

# ------------- Global target directives ----------------------
# The INSTANTIATE_TARGET function is where all of the top-level
# directives (called directly by 'make' or 'make fsp_TARGET') are
# created.
#
# For each possible target, we need to instantiate a recipe for how
# to create target when we are only making the target and one for when
# we are building all targets (a release).  This is the _TARGET and
# _TARGET_AS_SUBDIR recipe templates.
#
# Within a template we need to determine what to build, which is
# determined by the global actions like COPY_FILES, TAR_FILES, etc.
# The variables <TARGET>_<ACTION> are determined here by filtering the
# global <ACTION> variable for matches against the <TARGET> name.
# (__SOURCE_FOR_TARGET from above is used as the filtering mechanism).
#
# Building a target is 3 simple stages:
#     1) Print a "Starting <TARGET>" message.
#     2) Build all of the target dependencies
#             (based on the <TARGET>_<ACTION> variables).
#     3) Print a "Completed <TARGET>" message.
#
# At the end we loop over all VALID_TARGETS to call INSTANTIATE_TARGET
# against them.
#
define INSTANTIATE_TARGET
$(1)_COPY_FILE += $$(foreach file, $$(COPY_FILES), \
		     $$(call __SOURCE_FOR_TARGET,$(1), \
			    $$(firstword $$(subst :, ,$$(file))), \
			    $$(lastword $$(subst :, ,$$(file))) \
			) \
		    )

$(1)_COPY_RENAME_FILE += $$(foreach file, $$(COPY_RENAME_FILES), \
				$$(call __SOURCE_FOR_TARGET,$(1), \
				    $$(firstword $$(subst :, ,$$(file))), \
				    $$(lastword $$(subst :, ,$$(file))) \
				  ) \
			   )

$(1)_LINK_FILE += $$(foreach file, $$(LINK_FILES), \
			$$(call __SOURCE_FOR_TARGET,$(1), \
			    $$(firstword $$(subst :, ,$$(file))), \
			    $$(lastword $$(subst :, ,$$(file))) \
			  ) \
		    )

$(1)_TAR_FILE += $$(foreach file, $$(TAR_FILES), \
			$$(call __SOURCE_FOR_TARGET,$(1), \
			    $$(firstword $$(subst :, ,$$(file))), \
			    $$(lastword $$(subst :, ,$$(file))) \
			  ) \
		   )

$(1)_ODE_REMAKE_DEPS += $$(foreach file, $$($(1)_ODE_REMAKES), \
				$$(call ODE_REMAKE_RULE,$(1),$$(file)))

.PHONY: $(1)_TARGET $(1)_TARGET_AS_SUBDIR
$(1)_TARGET: \
    $(1)_TARGET_ECHO_START \
    $$(addprefix $$(TARGET_DIR)/,$$(notdir $$($(1)_COPY_FILE))) \
    $$(addprefix $$(TARGET_DIR)/,$$($(1)_COPY_RENAME_FILE)) \
    $$(addprefix $$(TARGET_DIR)/,$$($(1)_LINK_FILE)) \
    $$(addprefix $$(TARGET_DIR)/,$$($(1)_TAR_FILE)) \
    $$(addprefix $$(TARGET_DIR)/,$$($(1)_ODE_REMAKE_DEPS))
	@echo TARGET $(1) complete.

$(1)_TARGET_AS_SUBDIR: \
    $(1)_TARGET_ECHO_START \
    $$(addprefix $$(TARGET_DIR)/$(1)/,$$(notdir $$($(1)_COPY_FILE))) \
    $$(addprefix $$(TARGET_DIR)/$(1)/,$$($(1)_COPY_RENAME_FILE)) \
    $$(addprefix $$(TARGET_DIR)/$(1)/,$$($(1)_LINK_FILE)) \
    $$(addprefix $$(TARGET_DIR)/$(1)/,$$($(1)_TAR_FILE))
	@echo TARGET $(1) complete.

$(1)_TARGET_ECHO_START:
	@echo TARGET $(1) start...

endef
$(foreach targ,$(VALID_TARGETS),$(eval $(call INSTANTIATE_TARGET,$(targ))))

