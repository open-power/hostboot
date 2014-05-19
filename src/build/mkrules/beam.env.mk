# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/beam.env.mk $
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

# File: beam.env.mk
# Description:
#     Configuration of the BEAM settings.

AFSCELL := austin
BEAMVER = beam-3.6.1
BEAMPATH = /afs/${AFSCELL}/projects/esw/beam/$(BEAMVER)
BEAMCMD = $(HOST_PREFIX)jail $(BEAMPATH)/bin/beam_compile

ifdef MODULE
BEAMDIR = $(ROOTPATH)/obj/beam/$(MODULE)
BEAMMODULE = $(MODULE)
else
BEAMDIR = $(ROOTPATH)/obj/beam/core
BEAMMODULE = core
endif

##	Set BEAM source files.
##  see the beamgen:  target to generate these config files.
BEAMFLAGS += --beam::parms=$(ROOTPATH)/src/build/beam/beam_parms.tcl
BEAMFLAGS += --beam::source=$(ROOTPATH)/src/build/beam/compiler_c_config.tcl
BEAMFLAGS += --beam::source=$(ROOTPATH)/src/build/beam/compiler_cpp_config.tcl

##  point to a directory that BEAM can use for its' working files.
BEAMFLAGS += --beam::data=$(BEAMDIR)/..
BEAMFLAGS += --beam::build_root=$(ROOTPATH)

##  point BEAM to the potential innocent directory for a module.
BEAM_INNOCENT = $(ROOTPATH)/src/build/beam/$(BEAMMODULE)
BEAMFLAGS += $(if $(wildcard $(BEAM_INNOCENT)), \
		  --beam::user_innocent=$(BEAM_INNOCENT))

## tell the "Edison" compiler to generate no warnings.
BEAMFLAGS += --edg=--no_warnings

# make beam continue doing analyses even after first error found
BEAMFLAGS += --beam::exit0

BEAMFLAGS += -o /dev/null
