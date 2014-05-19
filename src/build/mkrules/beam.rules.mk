# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/beam.rules.mk $
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

# File: beam.rules.mk
# Description:
#     Rules for running BEAM on C/C++/ASM files.
##
##  NOTE,   export BUILD_VERBOSE=1 to expose the BEAM invocation for debug.
##          (export -n BUILD_VERBOSE to turn it back off)
##
##  collect "real" BEAM errors into the *.beam files
##  push parser errors to the *.parser files
##  push stats (for debug) to *.stats files.

BEAMOBJS = $(addprefix $(BEAMDIR)/, $(OBJS:.o=.beam))

$(BEAMDIR)/%.beam : %.C
	$(C2) "    BEAM       $(notdir $<)"
	@rm -f  $@ $@.parser $@.stats
	$(C1)$(BEAMCMD) $(INCFLAGS) -I . $(CXXFLAGS) $(BEAMFLAGS)   \
    --beam::complaint_file=$@        \
    --beam::parser_file=$@.parser    \
    --beam::stats_file=$@.stats      \
    $<

$(BEAMDIR)/%.beam : %.cc
	$(C2) "    BEAM       $(notdir $<)"
	@rm -f  $@ $@.parser $@.stats
	$(C1)$(BEAMCMD) $(INCFLAGS) -I . $(CXXFLAGS) $(BEAMFLAGS)   \
    --beam::complaint_file=$@        \
    --beam::parser_file=$@.parser    \
    --beam::stats_file=$@.stats      \
    $<

$(BEAMDIR)/%.beam : %.c
	$(C2) "    BEAM       $(notdir $<)"
	@rm -f  $@ $@.parser $@.stats
	$(C1)$(BEAMCMD) $(INCFLAGS) -I . $(CFLAGS) $(BEAMFLAGS)   \
    --beam::complaint_file=$@        \
    --beam::parser_file=$@.parser    \
    --beam::stats_file=$@.stats      \
    $<

$(BEAMDIR)/%.beam : %.S
	@echo Skipping ASM file: $<

beam: BEAM_PASS

##  Run beam_configure for the C++ and C compilers.
##  This outputs the config files to ./obj/beam, you have to copy them
##  to the correct location.
##  This only needs to be done when something in the build environment changes.
##  See https://w3.eda.ibm.com/beam/beam_configure.html for documentation.
beamgen:
	$(BEAMPATH)/bin/beam_configure $(firstword $(CXX_RAW))  \
    --cpp   \
    --force \
    -o $(ROOTPATH)/src/build/beam/compiler_cpp_config.tcl \
    --compile_flag="$(wordlist 2, $(words $(CXX_RAW)), $(CXX_RAW)) $(CXXFLAGS)"\
    --verbose
	$(BEAMPATH)/bin/beam_configure  $(firstword $(CC_RAW))  \
    --c   \
    --force \
    -o $(ROOTPATH)/src/build/beam/compiler_c_config.tcl \
    --compile_flag="$(wordlist 2, $(words $(CC_RAW)), $(CC_RAW)) $(CFLAGS)" \
    --verbose

.PHONY: make_beamdir
make_beamdir:
	@mkdir -p $(BEAMDIR)


BEAM_PASS_PRE   += make_beamdir
BEAM_PASS_BODY  += $(BEAMOBJS)

CLEAN_TARGETS += $(BEAMOBJS) $(BEAMOBJS:.beam=.beam.parser) \
                 $(BEAMOBJS:.beam=.beam.stats)
