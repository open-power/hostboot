# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/hbfw/img/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2016
# [+] International Business Machines Corp.
#
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

#
# FSP Destination: src/hbfw/img/makefile
#
# NOTE: Do NOT modify this file in CMVC directly!  It comes from the Hostboot
#       repository and will be overwritten.

.include <${RULES_MK}>

.if($(CONTEXT:R) == "ppc")

VPATH += ../fsp

DEFAULT_PATH = ${.PATH}
SRCPATH = ${DEFAULT_PATH:M*src*}

build_all: cp_hbfiles gen_default_images
install_all: gen_system_specific_images build_sbe_partitions build_pnor_images

#Some useful search paths
HBFW_OBJPATH = ${.PATH:M*obj*}
ENGD_OBJPATH = ${HBFW_OBJPATH:S/hbfw\/img/engd\/href/g}

#################################################
# Copy Hostboot binary images to obj dir to be grabbed
# during build flash pass and consumption by HWSV.
# Having external users acquire from OBJ dir as there are packaging
# changes expected in the future which will require using OBJ version.
#################################################
BASE_IMAGE = hostboot.bin
BASE_ECC_IMAGE = hostboot.bin.ecc
BASE_FINAL_IMAGE = HBB.bin
EXT_IMAGE =  hostboot_extended.bin
EXT_FINAL_IMAGE = HBI.bin
HBRT_IMAGE = hostboot_runtime.bin
HBRT_SHA_IMAGE = hostboot_runtime.sha.bin
HBRT_HEADER_IMAGE = hostboot_runtime.header.bin
HBRT_ECC_HEADER_IMAGE = hostboot_runtime.header.bin.ecc
BASE_IMAGES = ${BASE_IMAGE} ${EXT_IMAGE} ${HBRT_IMAGE}
TEMP_IMAGE = hostboot.temp.bin
# Zero filled sections final bin names
TEST_IMAGE = TEST.bin
TESTRO_IMAGE = TESTRO.bin
HBEL_IMAGE = HBEL.bin
GUARD_IMAGE = GUARD.bin
GLOBAL_IMAGE = GLOBAL.bin
DJVPD_IMAGE = DJVPD.bin
MVPD_IMAGE = MVPD.bin
CVPD_IMAGE = CVPD.bin
PAYLOAD_IMAGE = PAYLOAD.bin
SBKT_IMAGE = SBKT.bin
ZERO_FILL_IMAGES = ${TEST_IMAGE} ${TESTRO_IMAGE} ${HBEL_IMAGE} ${GUARD_IMAGE} \
                   ${GLOBAL_IMAGE} ${DJVPD_IMAGE} ${MVPD_IMAGE} ${CVPD_IMAGE} \
                   ${PAYLOAD_IMAGE} ${SBKT_IMAGE}
ALL_HB_IMAGES = ${BASE_IMAGES} ${HBRT_SHA_IMAGE} ${HBRT_HEADER_IMAGE} \
                ${HBRT_ECC_HEADER_IMAGE} ${EXT_FINAL_IMAGE} \
                ${BASE_FINAL_IMAGE} ${ZERO_FILL_IMAGES}

# Script to manipulate bin files to prepare for buildpnor (install_all phase)
GEN_PNOR_IMAGE_SCRIPT = ${genPnorImages.pl:P}
# Paramemter passed into GEN_PNOR_IMAGE_SCRIPT. Note zero filled images pass
# EMPTY as their file name. This is so the script knows it needs to generate
# them, rather than use an input.
# Note: HBI depends on HBB for sw signatures. Ensure that both are passed into
#       the same --systemBinFiles parameter for genPnorImages
GEN_DEFAULT_BIN_FILES = HBB=${BASE_IMAGE},HBI=${EXT_IMAGE},TEST=EMPTY,TESTRO=EMPTY,HBEL=EMPTY,GUARD=EMPTY,GLOBAL=EMPTY,PAYLOAD=EMPTY,CVPD=EMPTY,MVPD=EMPTY,DJVPD=EMPTY,SBKT=EMPTY
DEFAULT_PNOR_LAYOUT = ${defaultPnorLayout.xml:P}

################################################################################
# build_all start
################################################################################

cp_hbfiles: .SPECTARG
	${BASE_IMAGES:@image@cp -f ${SRCPATH:F${image}} ${image};@}

gen_default_images: cp_hbfiles
	currentsb -chain
	ecc --inject ${BASE_IMAGE} --output ${BASE_ECC_IMAGE} --p8
	# Add version header w/ HBRT sha hash
	echo -en VERSION\\0 > ${HBRT_SHA_IMAGE}
	sha512sum ${HBRT_IMAGE} | awk '{print $$1}' | xxd -pr -r >> ${HBRT_SHA_IMAGE}
	dd if=${HBRT_SHA_IMAGE} of=${TEMP_IMAGE} ibs=4k conv=sync
	cat ${HBRT_IMAGE} >> ${TEMP_IMAGE}
	# HBRT partition
	dd if=${TEMP_IMAGE} of=${HBRT_HEADER_IMAGE} ibs=3072K conv=sync
	ecc --inject ${HBRT_HEADER_IMAGE} --output ${HBRT_ECC_HEADER_IMAGE} --p8
	# Eventually use genPnorImages for every default image
	# HBI + HBB partitions and ZERO_FILL_IMAGES
	${GEN_PNOR_IMAGE_SCRIPT} --build-all ${TARGET_TEST:b--test} \
		${CONFIG_SECUREBOOT:b--secureboot} --systemBinFiles ${GEN_DEFAULT_BIN_FILES} \
		--pnorLayout ${DEFAULT_PNOR_LAYOUT} ${KEY_TRANSITION:b--key-transition} \
		${CORRUPT_PARAMS}
	rm ${TEMP_IMAGE}

clobber_gen_default_images:
	rm -f ${ALL_HB_IMAGES} \
	      sbe.header secureboot.header hb.footer hostboot.stage.bin

################################################################################
# install_all start
################################################################################

#################################################
###  SAMPLE for building an SBE Partition with multiple ECs
#################################################
#S1_EC10_BIN = ${ENGD_OBJPATH:Fs1_10.sbe_seeprom.bin}
#s1SbePartition.bin: ${SBE_BUILD_SCRIPT} ${S1_EC10_BIN}
#	${buildSbePart.pl:P} --sbeOutBin s1SbePartition.bin \
#		--ecImg_10 ${S1_EC10_BIN}
#################################################
SBE_BUILD_SCRIPT = ${buildSbePart.pl:P}

S1_EC13_BIN = ${ENGD_OBJPATH:Fs1_13.sbe_seeprom.hdr.bin}
S1_EC20_BIN = ${ENGD_OBJPATH:Fs1_20.sbe_seeprom.hdr.bin}
S1_EC21_BIN = ${ENGD_OBJPATH:Fs1_21.sbe_seeprom.hdr.bin}
P8_EC10_BIN = ${ENGD_OBJPATH:Fp8_10.sbe_seeprom.hdr.bin}
P8_EC20_BIN = ${ENGD_OBJPATH:Fp8_20.sbe_seeprom.hdr.bin}
CENT_EC10_BIN = ${ENGD_OBJPATH:Fcentaur_10.sbe_seeprom.hdr.bin}
CENT_EC20_BIN = ${ENGD_OBJPATH:Fcentaur_20.sbe_seeprom.hdr.bin}

SBE_PART_INFO = \
  s1SbePartition.bin:13=${S1_EC13_BIN},20=${S1_EC20_BIN},21=${S1_EC21_BIN} \
  p8SbePartition.bin:10=${P8_EC10_BIN},20=${P8_EC20_BIN} \
  centSbePartition.bin:10=${CENT_EC10_BIN},20=${CENT_EC20_BIN}

__SBE_PART_BUILD/% : .SPECTARG .PMAKE
	@${MAKE:T:R} BUILD_SPECIFIC_SBEPART \
	    "SBE_PART_PARAMS=${.TARGET:s/__SBE_PART_BUILD\///:s/:/ /g}"

.ifdef SBE_PART_PARAMS

SBEPART_TARGET = ${SBE_PART_PARAMS:xs/ .*//}
SBEPART_SECTIONS = ${SBE_PART_PARAMS:xs/[^ ]* //:xs/ .*//}
SBEPART_BINS = ${SBEPART_SECTIONS:s/,/ /g:xS/[^=]*=//g}
SBEPART_BIN_OPTION = ${SBEPART_SECTIONS:s/,/ /g:S/^/--ecImg_/g:s/=/ /g:p}

BUILD_SPECIFIC_SBEPART: .SPECTARG ${SBEPART_TARGET}
	#@echo TARGET ${SBEPART_TARGET}
	#@echo LAYOUT ${SBEPART_LAYOUT}
	#@echo BINARIES ${SBEPART_BINS}
	#@echo BIN_OPTION ${SBEPART_BIN_OPTION}

${SBEPART_TARGET}: ${SBEPART_LAYOUT} ${SBEPART_BINS} ${PNOR_BUILD_SCRIPT}
	 ${SBE_BUILD_SCRIPT}  --sbeOutBin ${SBEPART_TARGET} \
		${SBEPART_BIN_OPTION}

.endif

build_sbe_partitions: .SPECTARG ${SBE_PART_INFO:S/^/__SBE_PART_BUILD\//g}

clobber_build_sbe_partitions:
	${SBE_PART_INFO:@image@${pnorimg:!rm -f ${image:s/:/ /g:xs/ .*//};!e}@}

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
#	   --fpartCmd "${FPARTCMD}" --fcpCmd "${FCPCMD}"
##################################################
PNOR_BUILD_SCRIPT = ${buildpnor.pl:P}
GEN_FAKE_HEADER_SCRIPT = ${genfakeheader.pl:P}

#early hostboot use of this makefile will be against FSP drivers lacking fips_pnor.mk
#so need to use tryinclude for now.
.tryinclude <${.PATH:Ffips_pnor.mk}>

ZERO_FILL_SECTIONS = TEST=${TEST_IMAGE},TESTRO=${TESTRO_IMAGE},HBEL=${HBEL_IMAGE},GUARD=${GUARD_IMAGE},GLOBAL=${GLOBAL_IMAGE},PAYLOAD=${PAYLOAD_IMAGE},CVPD=${CVPD_IMAGE},MVPD=${MVPD_IMAGE},DJVPD=${DJVPD_IMAGE},SBKT=${SBKT_IMAGE}
HOSTBOOT_DEFAULT_SECTIONS = HBB=${BASE_FINAL_IMAGE},HBI=${EXT_FINAL_IMAGE},HBRT=${HBRT_ECC_HEADER_IMAGE},${ZERO_FILL_SECTIONS}

HBFW_OBJPATH = ${.PATH:M*obj*}
ENGD_OBJPATH = ${HBFW_OBJPATH:S/hbfw\/img/engd\/href/g}
# Define system name strings
MURANO = MURANO
NAPLES = NAPLES
VENICE = VENICE
MURANO_TARG_IMG = simics_MURANO_targeting.bin
NAPLES_TARG_IMG = simics_NAPLES_targeting.bin
VENICE_TARG_IMG = simics_VENICE_targeting.bin
MURANO_TARG_FINAL_IMG = ${MURANO}.HBD.bin
NAPLES_TARG_FINAL_IMG = ${NAPLES}.HBD.bin
VENICE_TARG_FINAL_IMG = ${VENICE}.HBD.bin
MURANO_SLW_IMG = ${ENGD_OBJPATH:Fs1.ref_image.bin}
NAPLES_SLW_IMG = ${ENGD_OBJPATH:Fs1.ref_image.bin}
VENICE_SLW_IMG = ${ENGD_OBJPATH:Fp8.ref_image.bin}
MURANO_SLW_FINAL_IMG = ${MURANO}.WINK.bin
NAPLES_SLW_FINAL_IMG = ${NAPLES}.WINK.bin
VENICE_SLW_FINAL_IMG = ${VENICE}.WINK.bin
MURANO_SBE_IMG = s1SbePartition.bin
NAPLES_SBE_IMG = s1SbePartition.bin
VENICE_SBE_IMG = p8SbePartition.bin
MURANO_SBE_FINAL_IMG = ${MURANO}.SBE.bin
NAPLES_SBE_FINAL_IMG = ${NAPLES}.SBE.bin
VENICE_SBE_FINAL_IMG = ${VENICE}.SBE.bin
SBEC_IMG = centSbePartition.bin
SBEC_FINAL_IMG = SBEC.bin
# Paramemters passed into GEN_PNOR_IMAGE_SCRIPT.
GEN_MURANO_BIN_FILES = ${MURANO}:HBD=${${MURANO_TARG_IMG}:P},SBE=${${MURANO_SBE_IMG}:P},WINK=${${MURANO_SLW_IMG}:P}
GEN_NAPLES_BIN_FILES = ${NAPLES}:HBD=${${NAPLES_TARG_IMG}:P},SBE=${${NAPLES_SBE_IMG}:P},WINK=${${NAPLES_SLW_IMG}:P}
GEN_VENICE_BIN_FILES = ${VENICE}:HBD=${${VENICE_TARG_IMG}:P},SBE=${${VENICE_SBE_IMG}:P},WINK=${${VENICE_SLW_IMG}:P}

gen_system_specific_images: build_sbe_partitions
	# SBE and SBECs and WINK partitions handled with genPnorImages below
	# Eventually use genPnorImages for every system specific image
	${GEN_PNOR_IMAGE_SCRIPT} ${TARGET_TEST:b--test} ${CONFIG_SECUREBOOT:b--secureboot} \
		--pnorLayout ${DEFAULT_PNOR_LAYOUT} ${CORRUPT_PARAMS} \
		--systemBinFiles ${GEN_MURANO_BIN_FILES} \
		--systemBinFiles ${GEN_NAPLES_BIN_FILES} \
		--systemBinFiles ${GEN_VENICE_BIN_FILES} \
		--systemBinFile  SBEC=${${SBEC_IMG}:P}

MURANO_SECT = HBD=${MURANO_TARG_FINAL_IMG},SBE=${MURANO_SBE_FINAL_IMG},SBEC=${SBEC_FINAL_IMG},WINK=${MURANO_SLW_FINAL_IMG}
NAPLES_SECT = HBD=${NAPLES_TARG_FINAL_IMG},SBE=${NAPLES_SBE_FINAL_IMG},SBEC=${SBEC_FINAL_IMG},WINK=${NAPLES_SLW_FINAL_IMG}
VENICE_SECT = HBD=${VENICE_TARG_FINAL_IMG},SBE=${VENICE_SBE_FINAL_IMG},SBEC=${SBEC_FINAL_IMG},WINK=${VENICE_SLW_FINAL_IMG}

PNOR_IMG_INFO = \
   murano.pnor:defaultPnorLayout.xml:${MURANO_SECT},${HOSTBOOT_DEFAULT_SECTIONS} \
   naples.pnor:defaultPnorLayout.xml:${NAPLES_SECT},${HOSTBOOT_DEFAULT_SECTIONS} \
   venice.pnor:defaultPnorLayout.xml:${VENICE_SECT},${HOSTBOOT_DEFAULT_SECTIONS} \
   ${FIPS_PNOR_INFO}

# Added a different dependency chain for hostboot standalone so we can compile
# faster and call one rule in dist.targets.mk 'update_images_for_sandbox'
.if( ${HB_STANDALONE} == 1)
__IMAGE_BUILD/% : .SPECTARG .PMAKE gen_default_images gen_system_specific_images
# In FSP this is run at install_all phase, so it's assumed all build_all rules
# have completed. If build_all rule dependencies are added they will run again.
.else
__IMAGE_BUILD/% : .SPECTARG .PMAKE gen_system_specific_images
.endif
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
	.if(${PNOR} == ${IMAGE_TARGET} || ${PNOR} == "")
		${PNOR_BUILD_SCRIPT} --pnorOutBin ${IMAGE_TARGET} \
			${TARGET_TEST:b--test} --pnorLayout ${IMAGE_LAYOUT} \
			${IMAGE_BIN_OPTION} --fpartCmd "fpart" --fcpCmd "fcp"
	.endif
.endif

build_pnor_images:.SPECTARG ${PNOR_IMG_INFO:S/^/__IMAGE_BUILD\//g}

clobber_build_pnor_images:
	${PNOR_IMG_INFO:@image@${pnorimg:!rm -f ${image:s/:/ /g:xs/ .*//};!e}@}

################################################################################
# Special rule used for hb standalone simics
################################################################################

#################################################
#Special target to copy images to flash dir for simics
#################################################
FLASH_DEST = $(MAKETOP)$(OBJECTDIRTOP)../images/$(CONTEXT)/lab/flash
FLASH_IMG = ${BASE_IMAGE} ${BASE_ECC_IMAGE}

update_images_for_sandbox: gen_default_images gen_system_specific_images build_sbe_partitions build_pnor_images
	mkdir -p ${FLASH_DEST}
	#Copy hostboot base image to flash dir
	${FLASH_IMG:@image@${baseimg:!cd ${FLASH_DEST}; cp -f ${.PATH:F${image}} ${image};!e}@}
	#Copy pnor images to flash dir
	${PNOR_IMG_INFO:@image@${pnorimg:!cd ${FLASH_DEST}; if [ "${PNOR}" == "${image:s/:/ /g:xs/ .*//}" ] || [ "${PNOR}" == "" ]; then cp -f ${.PATH:F${image:s/:/ /g:xs/ .*//}} ${image:s/:/ /g:xs/ .*//}; fi !e}@}
.endif
