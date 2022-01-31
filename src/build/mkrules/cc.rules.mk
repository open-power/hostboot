# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/cc.rules.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2022
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

# File: cc.rules.mk
# Description:
#     Rules for compiling C/C++/ASM files.

$(OBJDIR)/%.list : $(OBJDIR)/%.o
	$(C2) "    OBJDUMP    $(notdir $<)"
	$(C1)$(OBJDUMP) -rdlCS $< > $@

# SOURCE_FILE and INCLUDE_DIRS are variables that are either absolute
# paths to the .C file being compiled and the include directories if
# we're building with gcov, or else they are relative paths
# otherwise. The key thing to remember is that they are lazily
# expanded, so they're relevant to whatever rule they're used in. We
# don't want to always have absolute paths because of build
# performance and because it causes the build output with
# BUILD_VERBOSE to be larger and less readable.
ifdef HOSTBOOT_PROFILE_ARTIFACT
SOURCE_FILE=$(shell readlink -f $<)
INCLUDE_DIRS=$(shell $(ROOTPATH)/src/build/tools/cflags.sh $(INCFLAGS))
INCLUDE_PWD=$(shell readlink -f .)
PROFILE_LOG_CMD=
else
# If HOSTBOOT_PROFILE is set (i.e. a gcov build is being produced) but
# HOSTBOOT_PROFILE_ARTIFACT is not set, then we want to log any files
# that are compiled as being omitted from profiling.
ifdef HOSTBOOT_PROFILE
PROFILE_LOG_CMD=@echo $@ >>$(HOSTBOOT_PROFILE_NOCOV_LOG)
endif

SOURCE_FILE=$<
INCLUDE_DIRS=$(INCFLAGS)
INCLUDE_PWD=.
endif


# TODO RTC 215692
# The following script is used to run the cppcheck tool when enabled. If one
# cppcheck error is found, the make process will stop here, the error will be
# printed out to the terminal and stored in a file .`basename $<`.cppcheck in
# the directory where the original file is located
ifdef DOCPPCHECK
	CXX_PRINT=$(C2) "    CPPCHECK        $(notdir $<)"
	# Note: Error code 127 means that the command timed-out. We do not fail
	# for timeouts
	CXX_CPPCHECK_COMMAND=$(C1) set -o pipefail && cd `dirname $<` && timeout 2m $(CXX_CHECK) `basename $<` 2>&1 | tee .`basename $<`.cppcheck; exit_code=$$? ; \
	if [ "$$exit_code" -ne 1 ]; then \
		rm -f .`basename $<`.cppcheck; \
		if [ "$$exit_code" -eq 127 ]; then \
			exit_code=0; \
		fi; \
	else \
		cat .`basename $<`.cppcheck >> $(PROJECT_ROOT)/allCppcheckErrors; \
		echo >> $(PROJECT_ROOT)/allCppcheckErrors; \
		exit_code=0; \
	fi; exit "$$exit_code"
	C_CPPCHECK_COMMAND=$(C1) set -o pipefail && cd `dirname $<` && timeout 2m $(C_CHECK) `basename $<` 2>&1 | tee .`basename $<`.cppcheck; exit_code=$$? ; \
	if [ "$$exit_code" -ne 1 ]; then \
		rm -f .`basename $<`.cppcheck; \
		if [ "$$exit_code" -eq 127 ]; then \
			exit_code=0; \
		fi; \
	else \
		cat .`basename $<`.cppcheck >> $(PROJECT_ROOT)/allCppcheckErrors; \
		echo >> $(PROJECT_ROOT)/allCppcheckErrors; \
		exit_code=0; \
	fi; exit "$$exit_code"
else
	CXX_PRINT=
	CXX_CPPCHECK_COMMAND=
	C_CPPCHECK_COMMAND=
endif

$(OBJDIR)/%.o : %.C
	@mkdir -p $(OBJDIR)
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CXX) -c $(call FLAGS_FILTER, $(CXXFLAGS), $<) $(CLI_CXXFLAGS) $(SOURCE_FILE) \
	            -o $(TRACEHASH_INPUT_NAME) $(INCLUDE_DIRS) -iquote $(INCLUDE_PWD)
	$(C1)$(TRACE_HASHER) $@ $(TRACE_FLAGS)
	@$(TRACE_HASHER_CLEANUP)
	$(CXX_PRINT)
	$(CXX_CPPCHECK_COMMAND)
	$(PROFILE_LOG_CMD)

# Compiling *.cc files
$(OBJDIR)/%.o : %.cc
	@mkdir -p $(OBJDIR)
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CXX) -c $(CXXFLAGS) $(CLI_CXXFLAGS) $(SOURCE_FILE) -o $(TRACEHASH_INPUT_NAME) \
	               $(INCLUDE_DIRS) -iquote $(INCLUDE_PWD)
	$(C1)$(TRACE_HASHER) $@ $(TRACE_FLAGS)
	@$(TRACE_HASHER_CLEANUP)
	$(CXX_PRINT)
	$(CXX_CPPCHECK_COMMAND)
	$(PROFILE_LOG_CMD)

$(OBJDIR)/%.o : %.c
	@mkdir -p $(OBJDIR)
# Override to use C++ compiler in place of C compiler
# CC_OVERRIDE is set in the makefile of the component
ifndef CC_OVERRIDE
	$(C2) "    CC         $(notdir $<)"
	$(C1)$(CC) -c $(call FLAGS_FILTER, $(CFLAGS), $<) $(CLI_CFLAGS) $(SOURCE_FILE) \
	           -o $(TRACEHASH_INPUT_NAME) $(INCLUDE_DIRS) -iquote $(INCLUDE_PWD)
	$(CXX_PRINT)
	$(C_CPPCHECK_COMMAND)
else
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CXX) -c $(call FLAGS_FILTER, $(CXXFLAGS), $<) $(CLI_CXXFLAGS) $(SOURCE_FILE) \
	            -o $(TRACEHASH_INPUT_NAME) $(INCLUDE_DIRS) -iquote $(INCLUDE_PWD)
	$(CXX_PRINT)
	$(CXX_CPPCHECK_COMMAND)
endif
	$(C1)$(TRACE_HASHER) $@ $(TRACE_FLAGS)
	@$(TRACE_HASHER_CLEANUP)
	$(PROFILE_LOG_CMD)

$(OBJDIR)/%.o : %.S
	@mkdir -p $(OBJDIR)
	$(C2) "    CC         $(notdir $<)"
	$(C1)$(CC) -c $(ASMFLAGS) $< -o $@ $(ASMINCFLAGS) $(INCFLAGS) -iquote .

$(OBJDIR)/%.a : $(ARCHIVE_OBJECTS)
	@mkdir -p $(OBJDIR)
	$(C2) "    AR         $(notdir $@)"
	$(C1)rm -f "$@" # Remove the file (otherwise ar will keep it if it already exists)
	$(C1)$(AR) rcs $@ $^
	$(C1)$(if $(STRIP_ARCHIVES), $(STRIP) --strip-debug "$@")

ifdef MODULE
$(IMGDIR)/lib$(MODULE).so : $(OBJECTS) $(ROOTPATH)/src/module.ld $(MODULE_INIT)
	$(C2) "    LD         $(notdir $@)"
	$(C1)$(LD) -shared -z now -x $(LDFLAGS) \
		   $(OBJECTS) $(MODULE_INIT) \
	           -T $(ROOTPATH)/src/module.ld -o $@
endif

try = $(shell set -e; if ($(1)) >/dev/null 2>&1; \
        then echo "$(2)"; \
        else echo "$(3)"; fi )

try-cflag = $(call try,$(1) $(2) -x c -c /dev/null -o /dev/null,$(2))
