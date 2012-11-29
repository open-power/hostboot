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

FFSCMD = ffs
VPATH += ../fsp

DEFAULT_PATH = ${.PATH}
SRCPATH = ${DEFAULT_PATH:M*src*}

OTHERS = cp_hbfiles build_pnor_images 

#################################################
# Copy Hostboot binary images to obj dir to be grabbed
# during build flash pass and consumption by HWSV.
# Having external users acquire from OBJ dir as there are packaging
# changes expected in the future which will require using OBJ version.
#################################################
BASE_IMAGE = hostboot.bin
EXT_IMAGE =  hostboot_extended.bin
BASE_IMAGES = ${BASE_IMAGE} ${EXT_IMAGE}
BASE_W_HEADER_IMAGE = hostboot.header.bin
BASE_W_HEADER_ECC_IMAGE = hostboot.header.bin.ecc
BASE_ECC_IMAGE = hostboot.bin.ecc


cp_hbfiles: .SPECTARG
	${BASE_IMAGES:@image@cp -f -u ${SRCPATH:F${image}} ${image};@}
	echo "0000000000180000000000000800000000081000" | xxd -r -ps - sbe.header
	dd if=/dev/zero of=secureboot.header bs=1 count=4K
	cat sbe.header secureboot.header ${BASE_IMAGE} > ${BASE_W_HEADER_IMAGE}
	currentsb -chain
	ecc --inject ${BASE_IMAGE} --output ${BASE_ECC_IMAGE}
	ecc --inject ${BASE_W_HEADER_IMAGE} --output ${BASE_W_HEADER_ECC_IMAGE}


clobber_cp_hbfiles:
	rm -f ${BASE_IMAGES} ${BASE_W_HEADER_IMAGE} {BASE_W_HEADER_ECC_IMAGE} \
	      sbe.header secureboot.header


#################################################
###  SAMPLE for building a PNOR image
#################################################
#MURANO_TARGETING = simics_MURANO_targeting.bin 
#MURANO_LAYOUT = defaultPnorLayout.xml
#murano.pnor: ${MURANO_TARGETING} ${MURANO_LAYOUT} hostboot_extended.bin hostboot.bin
#	${buildpnor.pl:P} --pnorLayout ${.PATH:F${MURANO_LAYOUT}} \
#	   --pnorOutBin ${.TARGET} \
#	   --binFile_HBI ${.PATH:Fhostboot_extended.bin} \
#	   --binFile_HBD ${.PATH:F${MURANO_TARGETING}} \
#	   --binFile_HBB ${.PATH:Fhostboot.bin} \
#	   --ffsCmd "${FFSCMD}"
##################################################
PNOR_BUILD_SCRIPT = ${buildpnor.pl:P}

#early hostboot use of this makefile will be against FSP drivers lacking fips_pnor.mk
#so need to use tryinclude for now.
.tryinclude <${.PATH:Ffips_pnor.mk}>

HOSTBOOT_DEFAULT_SECTIONS = HBB=${BASE_W_HEADER_ECC_IMAGE},HBI=${EXT_IMAGE}

PNOR_IMG_INFO = murano.pnor:defaultPnorLayout.xml:HBD=simics_MURANO_targeting.bin,${HOSTBOOT_DEFAULT_SECTIONS} \
	      venice.pnor:defaultPnorLayout.xml:HBD=simics_VENICE_targeting.bin,${HOSTBOOT_DEFAULT_SECTIONS} \
              ${FIPS_PNOR_INFO}

__IMAGE_BUILD/% : .SPECTARG .PMAKE cp_hbfiles
	@${MAKE:T:R} BUILD_SPECIFIC_IMAGE \
	    "IMAGE_PARAMS=${.TARGET:s/__IMAGE_BUILD\///:s/:/ /g}"

.ifdef IMAGE_PARAMS

IMAGE_TARGET = ${IMAGE_PARAMS:xs/ .*//}
IMAGE_LAYOUT = ${IMAGE_PARAMS:xs/[^ ]* //:xs/ .*//:p}
IMAGE_SECTIONS = ${IMAGE_PARAMS:xs/[^ ]* //:xs/[^ ]* //:xs/ .*//}
IMAGE_BINS = ${IMAGE_SECTIONS:s/,/ /g:xS/[^=]*=//g}
IMAGE_BIN_OPTION = ${IMAGE_SECTIONS:s/,/ /g:S/^/--binFile_/g:s/=/ /g:p}

BUILD_SPECIFIC_IMAGE: .SPECTARG ${IMAGE_TARGET}
	#@echo TARGET ${IMAGE_TARGET}
	#@echo LAYOUT ${IMAGE_LAYOUT}
	#@echo BINARIES ${IMAGE_BINS}
	#@echo BIN_OPTION ${IMAGE_BIN_OPTION}

${IMAGE_TARGET}: ${IMAGE_LAYOUT} ${IMAGE_BINS} ${PNOR_BUILD_SCRIPT}
	${PNOR_BUILD_SCRIPT} --pnorOutBin ${IMAGE_TARGET} \
		${TARGET_TEST:b--test} --pnorLayout ${IMAGE_LAYOUT} \
		${IMAGE_BIN_OPTION} --ffsCmd "${FFSCMD}"

.endif

build_pnor_images: .SPECTARG ${PNOR_IMG_INFO:S/^/__IMAGE_BUILD\//g}

clobber_build_pnor_images:
	${PNOR_IMG_INFO:@image@${pnorimg:!rm -f ${image:s/:/ /g:xs/ .*//};!e}@}


#################################################
#Special target to copy images to flash dir for simics
#################################################
FLASH_DEST = $(MAKETOP)$(OBJECTDIRTOP)../images/$(CONTEXT)/lab/flash
FLASH_IMG = ${BASE_IMAGE} ${BASE_ECC_IMAGE}

update_images_for_sandbox: build_pnor_images 
	mkdir -p ${FLASH_DEST}
	#Copy hostboot base image to flash dir
	${FLASH_IMG:@image@${baseimg:!cd ${FLASH_DEST}; cp -f ${.PATH:F${image}} ${image};!e}@}
	#Copy pnor images to flash dir
	${PNOR_IMG_INFO:@image@${pnorimg:!cd ${FLASH_DEST}; cp -f ${.PATH:F${image:s/:/ /g:xs/ .*//}} ${image:s/:/ /g:xs/ .*//};!e}@}

.endif

