# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/framework/rule/tables.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2005,2012
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

#-------------------------------------------------------------------
# To add a new chip, modify PRDR_RULE_TABLES line.
# To change system type, modify VPATH line in rule/Makefile
#-------------------------------------------------------------------

# Add Rule tables here:
# FIXME: This is now a duplicate of PRDR_RULE_TABLE_TARGETS in prd_ruletable.mk
PRDR_RULE_TABLES = \
	Proc.prf \
	Ex.prf \
	Mcs.prf \
	Membuf.prf \
	Mba.prf

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

