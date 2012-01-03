#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/spd/makefile $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2012
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END
ROOTPATH = ../../..
MODULE = spd

OBJS = spd.o dimmPres.o

SUBDIRS = test.d

DIMM_SPD_DATA = dimmspd.dat
EXTRA_PARTS = $(addprefix $(IMGDIR)/, $(DIMM_SPD_DATA))

include ${ROOTPATH}/config.mk

${EXTRA_PARTS}: ${IMGDIR}/% : ./%
	cp -f $^ $@
