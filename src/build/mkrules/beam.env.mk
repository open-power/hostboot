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

BEAMVER = beam-3.6.1
BEAMPATH = /afs/rch/projects/esw/beam/$(BEAMVER)
BEAMCMD = $(HOST_PREFIX)jail $(BEAMPATH)/bin/beam_compile

ifdef MODULE
BEAMDIR = $(ROOTPATH)/obj/beam/$(MODULE)
else
BEAMDIR = $(ROOTPATH)/obj/beam/core
endif

##	Set BEAM source files.
##  see the beamgen:  target to generate these config files.
BEAMFLAGS += --beam::parms=$(BEAMPATH)/tcl/beam_default_parms.tcl   \
    $(ROOTPATH)/src/build/beam/beam_parms.tcl
BEAMFLAGS += --beam::source=$(ROOTPATH)/src/build/beam/compiler_c_config.tcl
BEAMFLAGS += --beam::source=$(ROOTPATH)/src/build/beam/compiler_cpp_config.tcl

##  point to a directory that BEAM can use for its' working files.
BEAMFLAGS += --beam::data=${BEAMDIR}

## tell the "Edison" compiler to generate no warnings.
BEAMFLAGS += --edg=--no_warnings

# make beam continue doing analyses even after first error found
BEAMFLAGS += --beam::exit0

BEAMFLAGS += -o /dev/null
