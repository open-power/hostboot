# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/framework/rule/tables.mk $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2005,2014
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

#-------------------------------------------------------------------
# To add a new chip, modify PRDR_RULE_TABLES line.
# To change system type, modify VPATH line in rule/Makefile
#-------------------------------------------------------------------

# Add Rule tables here:
# FIXME: This is now a duplicate of PRDR_RULE_TABLE_TARGETS in prd_ruletable.mk
PRDR_RULE_TABLES += Proc.prf
PRDR_RULE_TABLES += Ex.prf
PRDR_RULE_TABLES += Mcs.prf
PRDR_RULE_TABLES += Membuf.prf
PRDR_RULE_TABLES += Mba.prf

#------------------------------------------------------------------
# Change nothing below this line unless you know what you're doing!
#------------------------------------------------------------------



# Stuff for errl plugin.
    # Define required .o's
PRDR_ERRL_PLUGINS = ${PRDR_RULE_TABLES:S/\.prf/.prf.err.C/g}
PRDR_ERRL_PLUGINS += ${PRDR_RULE_TABLES:S/\.prf/.prf.reg.C/g}
PRDR_ERRL_PLUGINS_OFILES = ${PRDR_ERRL_PLUGINS:S/\.C/.o/g}
    # Ensure that we'll use the latest .C's to build the .o's.
#${PRDR_ERRL_PLUGINS_OFILES} : ${.TARGET:S/\.o/\.C/g}
%.prf.err.o: %.prf.err.C
%.prf.reg.o: %.prf.reg.C
%.prf.err.C: %.prf
%.prf.reg.C: %.prf
%.prf: %.rule
# end errl plugin.

