# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/build_winkle_images/makefile $
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
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/mvpd_accessors

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
##  EXAMPLE:
##  EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/<HWP_dir>
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/p8_slw_build
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar

CFLAGS += -D __FAPI


##  NOTE: add new object files when you add a new HWP
OBJS =  build_winkle_images.o   \
        p8_image_help.o         \
        p8_scan_compression.o   \
        pore_inline_assembler.o \
        p8_pba_bar_config.o     \
        sbe_xip_image.o         \
        p8_pore_table_static_data.o   \
        p8_pore_table_gen_api.o \
        p8_pore_table_gen_api_fixed.o \
        p8_pmc_deconfig_setup.o \
        p8_poreslw_init.o       \
        p8_set_pore_bar.o       \
        p8_xip_customize.o      \
        p8_ring_identification.o  \
        p8_slw_build.o          \
        p8_image_help_base.o    \
        p8_pfet_init.o

##  NOTE: add a new directory onto the vpaths when you add a new HWP
##  EXAMPLE:
#   VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/<HWP_dir>
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/p8_slw_build
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar

include ${ROOTPATH}/config.mk

