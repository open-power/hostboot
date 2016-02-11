# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: tools/build/common.dir/script.rules.mk $
#
# IBM CONFIDENTIAL
#
# EKB Project
#
# COPYRIGHT 2015,2016
# [+] International Business Machines Corp.
#
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# IBM_PROLOG_END_TAG

# Makefile that defines how we build generated files, often from scripts that
# process other content in the repository, such as XML files.

# BUILD_GENERATED
#    This macro will automatically generate all the recipes for running a tool
#    that generates other files.  Requires that the following variables are
#    defined prior to calling this macro:
#       * GENERATED=name - Give a name to this generator.
#       * COMMAND=tool - Name of the tool to run.
#       * SOURCES=file1 file2 - List of files as 'input' to the tool.
#       * TARGETS=file3 file4 - List of files that are created as 'output'.
#       * $(GENERATED)_RUN - A macro that identifies how to run this tool.
#    Special variables:
#       * $(GENERATED)_PATH - Optional path to put output into.
#       * $(GENERATED)_COMMAND_PATH - Path to tool, assumed to be the current
#                                     directory of the .mk file if not given.
#    Input:
#       * Optional input to delay the running of BUILD_GENERATED macro to a
#       later phase  EXE or MODULE.
BUILD_GENERATED = $(eval $(call __BUILD_GENERATED,$1))

# Order of operations:
#   * Define _PATH and _COMMAND_PATH if they do not exist.
#   * Define a recipe for a $(GENERATED).built timestamp file.
#      - Depend on $(COMMAND) and $(SOURCES)
#      - Ensure $(GENERATED)_PATH output path exists.
#      - Call $(GENERATED)_RUN macro.
#      - Touch timestamp file.
#   * Add dependency from TARGETS to .built timestamp file.
#   * Add timestamp and TARGETS to 'clean' target.
#   * Add timestamp to GEN_TARGETS.
#   * Clear out GENERATED, COMMAND, SOURCES, and TARGETS variables.
define __BUILD_GENERATED
$(GENERATED)_PATH ?= $$(GENPATH)
$(GENERATED)_COMMAND_PATH ?= $(dir $(lastword $(MAKEFILE_LIST)))

$$($(GENERATED)_PATH)/.$(GENERATED).built : \
	$$($(GENERATED)_COMMAND_PATH)$(COMMAND) $(SOURCES)
		$(C2) "    GEN        $(GENERATED)"
		$(C1) mkdir -p $$($(GENERATED)_PATH)
		$(call $(GENERATED)_RUN)
		@touch $$@

$$(addprefix $$($(GENERATED)_PATH)/,$(TARGETS)): \
	$$($(GENERATED)_PATH)/.$(GENERATED).built

$(call __CLEAN_TARGET,$$($(GENERATED)_PATH)/.$(GENERATED).built)
$(foreach target,$(TARGETS),\
	$(call CLEAN_TARGET,$$($(GENERATED)_PATH)/$(target)))

$(or $1,GEN)_TARGETS += $$($(GENERATED)_PATH)/.$(GENERATED).built

GENERATED:=
COMMAND:=
SOURCES:=
TARGETS:=
endef

