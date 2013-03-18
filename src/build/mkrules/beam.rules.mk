# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/beam.rules.mk $
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
