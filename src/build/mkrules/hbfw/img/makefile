#   IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/mkrules/hbfw/img/makefile $
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

#
# FSP Destination: src/hbfw/img/makefile
#
# NOTE: Do NOT modify this file in CMVC directly!  It comes from the Hostboot
#       repository and will be overwritten.

.include <${RULES_MK}>

.if($(CONTEXT:R) == "ppc")

PNOR_IMAGES = tuleta.pnor murano.pnor venice.pnor
OTHER_IMAGES = hostboot.bin

ALL_IMAGES = ${PNOR_IMAGES} ${OTHER_IMAGES}

DEFAULT_PATH = ${.PATH}
SRCPATH = ${DEFAULT_PATH:M*src*}

OTHERS = cp_hbfiles

cp_hbfiles:
	${ALL_IMAGES:@image@cp -f ${SRCPATH:F${image}} ${image};@}

clobber_cp_hbfiles:
	rm ${ALL_IMAGES}

FLASH_DEST = $(MAKETOP)$(OBJECTDIRTOP)../images/$(CONTEXT)/lab/flash

update_images_for_sandbox:
	mkdir -p ${FLASH_DEST}
	${ALL_IMAGES:@image@${hbimg:!cd ${FLASH_DEST}; cp -f ${.PATH:F${image}} ${image};!e}@}

.endif

