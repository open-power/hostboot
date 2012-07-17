#   IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/hwpf/hwp/build_winkle_images/makefile $
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
#  IBM_PROLOG_END_TAG
ROOTPATH = ../../../../..

MODULE = build_winkle_images

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

##  NOTE: add the base istep dir here.
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
##  EXAMPLE:
##  EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/<HWP_dir>
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/proc_slw_build
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/proc_set_pore_bar
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/proc_pba_bar_config
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/pore_gen_cpureg

CUSTOMFLAGS+= -D __FAPI


##  NOTE: add new object files when you add a new HWP
OBJS =  build_winkle_images.o   \
        p8_image_help.o         \
        p8_pore_static_data.o   \
        p8_scan_compression.o   \
        pore_inline_assembler.o \
        proc_slw_build.o        \
        sbe_xip_image.o         \
        proc_set_pore_bar.o     \
        proc_pba_bar_config.o

##  NOTE: add a new directory onto the vpaths when you add a new HWP
##  EXAMPLE:
#   VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/<HWP_dir>
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/proc_slw_build
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/proc_set_pore_bar
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/proc_pba_bar_config
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/pore_gen_cpureg

##  Point to the PORE image in PNOR
BINARY_FILES = $(IMGDIR)/procpore.dat:72cc5bef88f4d55dd9bbc9ad096e7dacff7d46e4

include ${ROOTPATH}/config.mk

