# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/sbe_centaur_init/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2014
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

ROOTPATH = ../../../../..

MODULE = sbe_centaur_init

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

## pointer to fapiporeve files
EXTRAINCDIR += ${ROOTPATH}/src/usr/pore/fapiporeve
EXTRAINCDIR += ${ROOTPATH}/src/usr/pore/poreve/model
EXTRAINCDIR += ${ROOTPATH}/src/usr/pore/poreve/porevesrc

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/sbe_centaur_init
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/p8_slw_build
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/mvpd_accessors


OBJS += sbe_centaur_init.o
OBJS += cen_xip_customize.o

##  NOTE: add a new directory onto the vpaths when you add a new HWP
## VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/sbe_centaur_init/????

include ${ROOTPATH}/config.mk
