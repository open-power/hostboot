# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/prd_pegasus.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2012,2013
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

# Object files for prdf rule plugins for pegasus
PRDF_RULE_PLUGINS_PEGASUS = \
    prdfP8Proc.o \
    prdfP8Ex.o \
    prdfP8Mcs.o \
    prdfP8Pll.o \
    prdfCenMba.o \
    prdfCenMembuf.o \
    prdfCenPll.o

# Object files for PRDF rule plugins, but include sim extensions.
PRDF_RULE_PLUGINS_PEGASUS_WSIM = \
    prdfP8SystemSpecific.o

# PEGASUS specific objects, not rule related.
prd_pegasus_specific = \
    prdfCalloutUtil.o \
    prdfCenAddress.o \
    prdfLineDelete.o \
    prdfPegasusConfigurator.o \
    prdfCenMbaCaptureData.o \
    prdfRegisterData.o

