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

$(BEAMDIR)/%.beam : %.C
	$(C2) "    BEAM       $(notdir $<)"
	$(C1)$(BEAMCMD) $(INCFLAGS) $(CXXFLAGS) $(BEAMFLAGS) $< \
	                --beam::complaint_file=$@ --beam::parser_file=/dev/null

$(BEAMDIR)/%.beam : %.cc
	$(C2) "    BEAM       $(notdir $<)"
	$(C1)$(BEAMCMD) $(INCFLAGS) $(CXXFLAGS) $(BEAMFLAGS) $< \
	                --beam::complaint_file=$@ --beam::parser_file=/dev/null

$(BEAMDIR)/%.beam : %.c
	$(C2) "    BEAM       $(notdir $<)"
	$(C1)$(BEAMCMD) $(INCFLAGS) $(CXXFLAGS) $(BEAMFLAGS) $< \
	                --beam::complaint_file=$@ --beam::parser_file=/dev/null

$(BEAMDIR)/%.beam : %.S
	@echo Skipping ASM file: $<


BEAMOBJS = $(addprefix $(BEAMDIR)/, $(OBJS:.o=.beam))

beam: BEAM_PASS

.PHONY: make_beamdir
make_beamdir:
	@mkdir -p $(BEAMDIR)

BEAM_PASS_PRE += make_beamdir
BEAM_PASS_BODY += $(BEAMOBJS)
