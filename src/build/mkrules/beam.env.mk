# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/beam.env.mk $
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

# File: beam.env.mk
# Description:
#     Configuration of the BEAM settings.

BEAMVER = beam-3.5.2
BEAMPATH = /afs/rch/projects/esw/beam/$(BEAMVER)
BEAMCMD = $(HOST_PREFIX)jail $(BEAMPATH)/bin/beam_compile
BEAMFLAGS = \
    --beam::source=$(BEAMPATH)/tcl/beam_default_parms.tcl \
    --beam::source=$(ROOTPATH)/src/build/beam/compiler_c_config.tcl \
    --beam::source=$(ROOTPATH)/src/build/beam/compiler_cpp_config.tcl \
    --beam::exit0 \
    -o /dev/null

ifdef MODULE
BEAMDIR = $(ROOTPATH)/obj/beam/$(MODULE)
else
BEAMDIR = $(ROOTPATH)/obj/beam/core
endif

