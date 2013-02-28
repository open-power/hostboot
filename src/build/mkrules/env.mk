# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/env.mk $
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

# File: env.mk
# Description:
#     Root of the "configuration" (ie. environment) for the build system.

TRACEPP = $(ROOTPATH)/src/build/trace/tracepp

ifdef MODULE
OBJDIR = $(ROOTPATH)/obj/modules/$(MODULE)
GENDIR = $(ROOTPATH)/obj/genfiles
GENDIR_PLUGINS = $(ROOTPATH)/obj/genfiles/plugins
IMGDIR = $(ROOTPATH)/img
LIBS += $(addsuffix .so, $(addprefix lib, $(MODULE)))
INCDIR += $(ROOTPATH)/src/include/usr
MODULE_INIT = $(ROOTPATH)/obj/core/module_init.o
else
OBJDIR = $(ROOTPATH)/obj/core
GENDIR = $(ROOTPATH)/obj/genfiles
GENDIR_PLUGINS = $(ROOTPATH)/obj/genfiles/plugins
IMGDIR = $(ROOTPATH)/img
endif

INCDIR += $(ROOTPATH)/src/include/
INCDIR += $(GENDIR)
INCDIR += $(EXTRAINCDIR)

OBJECTS = $(addprefix $(OBJDIR)/, $(OBJS))
LIBRARIES = $(addprefix $(IMGDIR)/, $(LIBS))

# Translate the HOSTBOOT_DEBUG environment variable to C-preprocessor #define.
#    HOSTBOOT_DEBUG=1 <--- implies debug on everywhere
#    HOSTBOOT_DEBUG=kernel <--- implies any non-module code gets debug.
#    HOSTBOOT_DEBUG=foo,bar <--- enables debug for 'foo' and 'bar' module.
ifdef HOSTBOOT_DEBUG
ifeq ($(HOSTBOOT_DEBUG),1)
    CFLAGS += -DHOSTBOOT_DEBUG=1
else
ifndef MODULE
ifneq (,$(filter kernel,$(call MAKE_SPACE_LIST, $(HOSTBOOT_DEBUG))))
    CFLAGS += -DHOSTBOOT_DEBUG=kernel
endif
else
ifneq (,$(filter $(MODULE), $(call MAKE_SPACE_LIST, $(HOSTBOOT_DEBUG))))
    CFLAGS += -DHOSTBOOT_DEBUG=$(MODULE)
endif
endif
endif
endif

# Import more specialized configuration.
include $(MKRULESDIR)/cc.env.mk
include $(MKRULESDIR)/binfile.env.mk
include $(MKRULESDIR)/beam.env.mk
include $(MKRULESDIR)/gcov.env.mk
include $(MKRULESDIR)/cflags.env.mk
