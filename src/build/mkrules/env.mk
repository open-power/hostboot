# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/env.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2020
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
INCDIR += $(ROOTPATH)/src/subtree/
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
ifeq ($(strip $(SKIP_CONFIG_FILE_LOAD)),)
-include $(GENDIR)/config.mk
endif
include $(MKRULESDIR)/cc.env.mk
include $(MKRULESDIR)/binfile.env.mk
include $(MKRULESDIR)/beam.env.mk
include $(MKRULESDIR)/gcov.env.mk
include $(MKRULESDIR)/cflags.env.mk
