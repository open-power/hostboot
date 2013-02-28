# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/passes.env.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2013
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

# File: passes.env.mk
# Description:
#     Definition of the passes and their default contents.
#
# DEFAULT_PASSES are what get run when you do a 'make' or 'make all'.  The
# order of the passes in the variable define an ordering.
#
# OTHER_PASSES are special passes that get triggered by 'make NAME_PASS'.
# Sometimes these have a shortcut, like 'make name'.  The content for these
# are in their own special name.rules.mk.

DEFAULT_PASSES = GEN CODE IMAGE
OTHER_PASSES = CLEAN GCOV BEAM

## GEN_PASS
##    Create the $(GENFILES) content.
GENTARGET = $(addprefix $(GENDIR)/, $(1))
GENPLUGINTARGET = $(addprefix $(GENDIR_PLUGINS)/, $(1))

GEN_PASS_BODY += $(addprefix $(GENDIR)/, $(GENFILES))
CLEAN_TARGETS += $(addprefix $(GENDIR)/, $(GENFILES))
GEN_PASS_BODY += $(addprefix $(GENDIR_PLUGINS)/, $(GENFILES_PLUGINS))
CLEAN_TARGETS += $(addprefix $(GENDIR_PLUGINS)/, $(GENFILES_PLUGINS))

ifneq ($(strip $(GEN_PASS_BODY)),)
make_gendir:
	@mkdir -p $(GENDIR)
	@mkdir -p $(GENDIR_PLUGINS)
.PHONY: make_gendir
GEN_PASS_PRE += make_gendir
endif

## CODE_PASS
##    Compile the $(OBJS) and build the $(LIBS).
CODE_PASS_BODY += $(OBJECTS) $(OBJECTS:.o=.list) $(LIBRARIES) $(EXTRA_PARTS)
CLEAN_TARGETS += $(OBJECTS) $(OBJECTS:.o=.o.hash) $(OBJECTS:.o=.dep) \
                 $(OBJECTS:.o=.list) $(LIBRARIES) $(EXTRA_PARTS)
ifeq ($(MAKECMDGOALS),_BUILD/PASSES/CODE/BODY/ACT)
    -include $(OBJECTS:.o=.dep)
endif


## IMAGE_PASS
##    Build the $(IMGS).
IMAGE_PASS_BODY += $(IMAGES)
CLEAN_TARGETS += $(IMAGES) \
                 $(IMAGES:.bin=.bin.modinfo) $(IMAGES:.bin=_extended.bin)

## CLEAN_PASS
##    Make the repo clean again by removing all the $(CLEAN_TARGETS).
CLEAN_PASS_BODY += $(addprefix _BUILD/CLEAN/,$(wildcard $(CLEAN_TARGETS)))

.PHONY: clean
clean: CLEAN_PASS

