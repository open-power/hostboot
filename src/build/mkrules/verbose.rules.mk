# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/verbose.rules.mk $
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

# File: verbose.rules.mk
# Description:
#     Control the verbosity of make commands by defining some prefixes that
#     other make rules can use.
#
# Setting the environment variable BUILD_VERBOSE=1 echos the full commands
# being executed, while leaving it off echos just a short description.

# Variables:
#     C1 - Prefix for the command to be executed.  ex. '$(C1)$(CC) foo.C'
#     C2 - Prefix for the short description of the command.  ex. '$(C2)CC foo.C'

ifdef BUILD_VERBOSE
    C1=
    C2=@true || echo
else
    C1=@
    C2=@echo
    MAKE+= --no-print-directory
endif

MAKE+= --no-builtin-rules --no-builtin-variables

