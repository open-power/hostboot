# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/assemble.standalone.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2019,2023
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
# Makefile to assemble a P10 standalone PNOR image.
# GNU "make" is run on this makefile from <hb_repo>/standalone/pnor.
#

## Macros

# Argument:
#    $(1): path of a directory
# Resolves to:
#    List of absolute paths of files inside of $(1) dir.
define get_files_full_path
    ${foreach bin, ${shell ls $(1)}, \
    $(shell find $(1) -maxdepth 1 -name *${bin} ) }
endef

## Paths Setup

# HB-repo directories that are used
TOOLSDIR := ${PROJECT_ROOT}/src/build/tools
BUILDPNOR := ${PROJECT_ROOT}/src/build/buildpnor
BASEIMAGESDIR := ${PROJECT_ROOT}/img
PPE_DIR=${PROJECT_ROOT}/src/build/tools/extern/ppe
SBE_SEEPROM_IMAGE_DD1 := ${PPE_DIR}/images/sbe_seeprom_DD1.bin
STANDALONEDIR := ${PROJECT_ROOT}/standalone
# FSS tools directory
FFSTOOLS := ${STANDALONEDIR}/ffs
# Staging directory (items used to assemble PNOR)
STAGINGDIR := ${STANDALONEDIR}/staging
# Path to external pnor dependencies
HB_SIM_DEPS_PATH := ${HOSTBOOT_ENVIRONMENT}/simbuild/dependencies
# P10 PNOR image being assembled
OUTPUTPNOR := ${PNOR_LAYOUT_SELECTED}.pnor
PNOR_LAYOUT = ${BUILDPNOR}/pnorLayoutP10.xml
# FFS tools added to search path
export PATH:=${FFSTOOLS}/ecc/:${FFSTOOLS}/fcp/:${FFSTOOLS}/fpart/:$(PATH)

## Scripts

IMAGE_EDIT_PROGRAM := ${TOOLSDIR}/editimgid
PKG_OCMBFW_SCRIPT := ${BUILDPNOR}/pkgOcmbFw.pl
PNOR_BUILD_SCRIPT := ${BUILDPNOR}/buildpnor.pl
GEN_FAKE_HEADER_SCRIPT := ${BUILDPNOR}/genfakeheader.pl
# Script to manipulate bin files to prepare for buildpnor
# Note: sections with no input files are zero filled images and pass EMPTY as
#        their input file name. This is so the script knows it needs to generate
#        them, rather than use an input.
# Note: HBI depends on HBB for sw signatures. Ensure that both are passed into
#        the same --systemBinFiles parameter for genPnorImages
GEN_PNOR_IMAGE_SCRIPT := ${BUILDPNOR}/genPnorImages.pl
UNPKGD_OCMBFW_IMG := ${STAGINGDIR}/ocmbfw.bin
SBE_BUILD_SCRIPT := ${BUILDPNOR}/buildSbePart.pl
# Needed to sign SBE Image (which will add .sb_settings section to it)
SBE_SIGN_SCRIPT := ${PPE_DIR}/src/tools/scripts/signSbeImage
SBE_SCRATCH_DIR := ${STANDALONEDIR}/sbeScratchDir
SBE_TOOL        := ${PPE_DIR}/images/ipl_image_tool

## Variables and Files Setup

# In this context, fspbuild means enterprise build
BUILD_TYPE_PARAMS := --build-type fspbuild

# Imprint HW keys' hash
IMPRINT_HW_KEY_HASH := ${BUILDPNOR}/imprintHwKeyHash

# # Input default images
BOOTLDR_IMG := ${STAGINGDIR}/hbibl.bin
HB_SECROM_IMG := ${STAGINGDIR}/securerom.bin
HBB_IMG := ${STAGINGDIR}/hbicore$(UNDERSCORE_TEST).bin
HBI_IMG := ${STAGINGDIR}/hbicore$(UNDERSCORE_TEST)_extended.bin
HBRT_IMG := ${STAGINGDIR}/hbirt$(UNDERSCORE_TEST).bin
BASE_IMAGES := ${BOOTLDR_IMG} ${HB_SECROM_IMG} ${HBB_IMG} ${HBI_IMG} ${HBRT_IMG}
HBBL_IMG := hbbl.bin
HBB_ECC_IMG := hostboot.bin.ecc
OCMBFW_IMG = fwhdr.ocmbfw.bin
VERSION_IMG := version.txt

SBE_BASE_IMAGES := ${SBE_SEEPROM_IMAGE_DD1}
SBE_SEEPROM_IMAGE_DD1 := ${PPE_DIR}/images/sbe_seeprom_DD1.bin
SBE_SEEPROM_HDR_SHA_DD1 := ${STANDALONEDIR}/pnor/sbe_seeprom.sha.bin.DD1
SBE_SEEPROM_HDR_BIN_DD1 := ${STANDALONEDIR}/pnor/sbe_seeprom.hdr.bin.DD1

# # Input fake images
HBD_FAKE = ${BASEIMAGESDIR}/vbu_P10_targeting.bin
EECACHE_IMG = ${STANDALONEDIR}/simics/eecache_vpo_prebuilt.bin.ecc

# Output final images
HBBL_FINAL_IMG := HBBL.bin
HBB_FINAL_IMG := HBB.bin
HBI_FINAL_IMG := HBI.bin
HBRT_FINAL_IMG := HBRT.bin
TEST_FINAL_IMG := TEST.bin
TESTRO_FINAL_IMG := TESTRO.bin
TESTLOAD_FINAL_IMG := TESTLOAD.bin
HBEL_FINAL_IMG := HBEL.bin
GUARD_FINAL_IMG := GUARD.bin
DJVPD_FINAL_IMG := DJVPD.bin
MVPD_FINAL_IMG := MVPD.bin
PAYLOAD_FINAL_IMG := PAYLOAD.bin
RINGOVD_FINAL_IMG := RINGOVD.bin
SBKT_FINAL_IMG := SBKT.bin
VERSION_FINAL_IMG := VERSION.bin
EECACHE_FINAL_IMG := EECACHE.bin
OCMBFW_FINAL_IMG := OCMBFW.bin
HBD_FINAL_IMG := HBD.bin
HBD_RW_FINAL_IMG := HBD_RW.bin
HCODE_FINAL_IMG := HCODE.bin
HCODE_LID_FINAL_IMG := HCODE_LID.bin
SBE_FINAL_IMG := SBE.bin
OCC_FINAL_IMG := OCC.bin
WOFDATA_FINAL_IMG := WOFDATA.bin
SBE_IMG := unprocessed.SBE.bin
DEVTREE_FINAL_IMG := DEVTREE.bin

# Input image artifacts location
OCC_ARTIFACT_LOCATION := ${HB_SIM_DEPS_PATH}/occ/${OCC_ARTIFACT_ID}/
$(info    OCC_ARTIFACT_LOCATION is $(OCC_ARTIFACT_LOCATION))
HDAT_ARTIFACT_LOCATION := ${HB_SIM_DEPS_PATH}/hdat/${HDAT_ARTIFACT_ID}/
$(info    HDAT_ARTIFACT_LOCATION is $(HDAT_ARTIFACT_LOCATION))
WOF_ARTIFACT_LOCATION := ${HB_SIM_DEPS_PATH}/wof/${WOF_ARTIFACT_ID}/
DEVTREE_ARTIFACT_LOCATION := ${HB_SIM_DEPS_PATH}/devtree/${DEVTREE_ARTIFACT_ID}/

# Input Images
ifeq (${MACHINE}, bonito)
HBD_COMBO_IMG := ${BASEIMAGESDIR}/simics_BONITO_targeting.bin
HBD_RO_IMG := ${BASEIMAGESDIR}/simics_BONITO_targeting.bin.protected
HBD_RW_IMG := ${BASEIMAGESDIR}/simics_BONITO_targeting.bin.unprotected
else
# otherwise default to using P10 xml
HBD_COMBO_IMG := ${BASEIMAGESDIR}/simics_P10_targeting.bin
HBD_RO_IMG := ${BASEIMAGESDIR}/simics_P10_targeting.bin.protected
HBD_RW_IMG := ${BASEIMAGESDIR}/simics_P10_targeting.bin.unprotected
endif

WOFDATA_IMG := ${call get_files_full_path, ${WOF_ARTIFACT_LOCATION}}
OCC_IMG := ${call get_files_full_path, ${OCC_ARTIFACT_LOCATION}}
$(info    OCC_IMG is $(OCC_IMG))
DEVTREE_IMG := ${call get_files_full_path, ${DEVTREE_ARTIFACT_LOCATION}}

PAYLOAD_MCL_LID := ${HDAT_ARTIFACT_LOCATION}${HDAT_MCL_LID}
PAYLOAD_PHYP_LID := ${HDAT_ARTIFACT_LOCATION}${HDAT_PHYP_LID}
$(info    PAYLOAD_LIDS are $(PAYLOAD_MCL_LID) $(PAYLOAD_PHYP_LID))

STANDALONE_PAYLOAD_FINAL_IMG := ${STAGINGDIR}/standalone_payload.bin
$(info STANDALONE_PAYLOAD_FINAL_IMG is $(STANDALONE_PAYLOAD_FINAL_IMG))

# Allow for overriding the HCODE image with a user supplied image
ifndef HCODE_OVERRIDE_IMAGE
HCODE_IMG := ${STAGINGDIR}/p10.hw_image.bin
HCODE_LID_IMG := ${STAGINGDIR}/p10.hw_image_lid.bin
else
$(info ***************** OVERIDING HCODE IMAGE WITH USER IMAGE ***********************)
HCODE_IMG := ${HCODE_OVERRIDE_IMAGE}
HCODE_LID_IMG := ${HCODE_LID_OVERRIDE_IMAGE}
endif

# Images that will be used for PNOR layout
DEF_GEN_BIN_FILES := HBBL=${HBBL_IMG},HBB=${HBB_IMG},HBI=${HBI_IMG},\
	HBRT=${HBRT_IMG},HBEL=EMPTY,GUARD=EMPTY,MVPD=EMPTY,RINGOVD=EMPTY,\
	SBKT=EMPTY,TEST=EMPTY,TESTRO=EMPTY,TESTLOAD=EMPTY,PAYLOAD=${STANDALONE_PAYLOAD_FINAL_IMG},\
	VERSION=${VERSION_IMG},HBD_RW=EMPTY

## Set up for img. assembling and building a PNOR image

ifeq (${FAKEPNOR},)
# Parameters passed to GEN_PNOR_IMAGE_SCRIPT.
    _GEN_DEFAULT_BIN_FILES := ${DEF_GEN_BIN_FILES},EECACHE=EMPTY,\
    	OCMBFW=${OCMBFW_IMG}
# GEN_DEFAULT_BIN_FILES string is assembled with spaces that need to be removed
    GEN_DEFAULT_BIN_FILES := $(shell echo ${_GEN_DEFAULT_BIN_FILES} | sed 's/ //g')
    DEFAULT_PARAMS := --build-all --emit-eccless $(if ${TARGET_TEST},--test) \
        --hb-standalone $(if ${CONFIG_SECUREBOOT},--secureboot) \
        --systemBinFiles ${GEN_DEFAULT_BIN_FILES} \
        --pnorLayout ${PNOR_LAYOUT} ${KEY_TRANSITION_PARAMS} ${CORRUPT_PARAMS} \
        --hwKeyHashFile ${IMPRINT_HW_KEY_HASH} \
	--editedLayoutLocation ${STAGINGDIR}

HBD_RW_EXISTS:= $(shell grep 'HBD_RW' $(PNOR_LAYOUT))
ifeq (${HBD_RW_EXISTS},)
    _GEN_BIN_FILES := SBE=${SBE_IMG},HCODE=${HCODE_IMG},OCC=${OCC_IMG},\
    HBD=${HBD_COMBO_IMG},WOFDATA=${WOFDATA_IMG},DEVTREE=${DEVTREE_IMG},HCODE_LID=${HCODE_LID_IMG}
else
    _GEN_BIN_FILES := SBE=${SBE_IMG},HCODE=${HCODE_IMG},OCC=${OCC_IMG},\
    HBD=${HBD_COMBO_IMG},HBD_RW=${HBD_RW_FINAL_IMG},WOFDATA=${WOFDATA_IMG},DEVTREE=${DEVTREE_IMG},HCODE_LID=${HCODE_LID_IMG}
endif

# Parameters passed to GEN_PNOR_IMAGE_SCRIPT.
    GEN_BIN_FILES := $(shell echo ${_GEN_BIN_FILES} | sed 's/ //g')
    SYSTEM_SPECIFIC_PARAMS := --install-all --emit-eccless \
        $(if ${TARGET_TEST},--test) $(if ${CONFIG_SECUREBOOT},--secureboot) \
        --pnorLayout ${PNOR_LAYOUT} ${CORRUPT_PARAMS} --hb-standalone \
        --systemBinFiles ${GEN_BIN_FILES} \
        --hwKeyHashFile ${IMPRINT_HgitW_KEY_HASH} \
	--editedLayoutLocation ${STAGINGDIR}

# For standalone PNOR layout
    HOSTBOOT_DEFAULT_SECTIONS := HBBL=${HBBL_FINAL_IMG} HBB=${HBB_FINAL_IMG} \
    	HBI=${HBI_FINAL_IMG} HBRT=${HBRT_FINAL_IMG} TEST=${TEST_FINAL_IMG} \
    	TESTRO=${TESTRO_FINAL_IMG} TESTLOAD=${TESTLOAD_FINAL_IMG} \
    	HBEL=${HBEL_FINAL_IMG} GUARD=${GUARD_FINAL_IMG} \
    	PAYLOAD=${PAYLOAD_FINAL_IMG} MVPD=${MVPD_FINAL_IMG} \
    	RINGOVD=${RINGOVD_FINAL_IMG} SBKT=${SBKT_FINAL_IMG} \
    	VERSION=${VERSION_FINAL_IMG}

ifeq (${HBD_RW_EXISTS},)
    SECT := HBD=${HBD_FINAL_IMG} SBE=${SBE_FINAL_IMG} HCODE=${HCODE_FINAL_IMG} \
        OCC=${OCC_FINAL_IMG} WOFDATA=${WOFDATA_FINAL_IMG} \
        EECACHE=${EECACHE_FINAL_IMG} \
        OCMBFW=${OCMBFW_FINAL_IMG} DEVTREE=${DEVTREE_FINAL_IMG} HCODE_LID=${HCODE_LID_FINAL_IMG}
else
    SECT := HBD=${HBD_FINAL_IMG} HBD_RW=${HBD_RW_FINAL_IMG} SBE=${SBE_FINAL_IMG} HCODE=${HCODE_FINAL_IMG} \
        OCC=${OCC_FINAL_IMG} WOFDATA=${WOFDATA_FINAL_IMG} \
        EECACHE=${EECACHE_FINAL_IMG} \
        OCMBFW=${OCMBFW_FINAL_IMG} DEVTREE=${DEVTREE_FINAL_IMG} HCODE_LID=${HCODE_LID_FINAL_IMG}
endif

else
# Parameters passed to GEN_PNOR_IMAGE_SCRIPT.
    PNOR_LAYOUT = ${BUILDPNOR}/pnorLayoutFake.xml
    _GEN_DEFAULT_BIN_FILES := HBI=${HBI_IMG},HBEL=EMPTY,EECACHE=${EECACHE_IMG},HBD=${HBD_FAKE}
    GEN_DEFAULT_BIN_FILES := $(shell echo ${_GEN_DEFAULT_BIN_FILES} | sed 's/ //g')
    DEFAULT_PARAMS := --systemBinFiles ${GEN_DEFAULT_BIN_FILES}\
    	--pnorLayout ${PNOR_LAYOUT} --editedLayoutLocation ${STAGINGDIR}

# Parameters passed to GEN_PNOR_IMAGE_SCRIPT.
    _GEN_BIN_FILES := HBD=${HBD_FAKE}
    GEN_BIN_FILES := $(shell echo ${_GEN_BIN_FILES} | sed 's/ //g')
    SYSTEM_SPECIFIC_PARAMS := --install-all --emit-eccless \
		--pnorLayout ${PNOR_LAYOUT} --systemBinFiles ${GEN_BIN_FILES} \
		--editedLayoutLocation ${STAGINGDIR}

# For standalone PNOR layout
    HOSTBOOT_DEFAULT_SECTIONS := HBI=${HBI_FINAL_IMG} HBEL=${HBEL_FINAL_IMG}
    SECT := HBD=${HBD_FINAL_IMG} EECACHE=${EECACHE_FINAL_IMG}

endif

# Parameter passed to GEN_PNOR_IMAGE_SCRIPT.
BINARIES := ${HOSTBOOT_DEFAULT_SECTIONS} ${SECT}
IMAGE_BIN_OPTION := $(foreach bin, ${BINARIES}, \
	$(shell echo --binFile_${bin} | sed 's/=/ /'))

# Signing setup

# Determine which version of Redhat we're building on and generate the
# associated sub-directory name used to construct the signing binaries path.
# Most pool machines have back level libraries used for signing, so point to
# usable ones.
RH_DIR:=$(shell sed "s/^.*release \([0-9]*\)\..*$//rh\1/" /etc/redhat-release)

# Use Secure Boot development signing if not specified in the environment
BR2_OPENPOWER_SECUREBOOT_SIGN_MODE?=development
SIGN_MODE_ARG:=--sign-mode ${BR2_OPENPOWER_SECUREBOOT_SIGN_MODE}

# Concatenate the base path, Redhat specific dir, and tool subdir to form the
# complete signing tools path
export SIGNING_DIR:=${SIGNING_BASE_DIR}/${RH_DIR}/${SIGNING_UTILS_DIR}

# Construct the set of libs we need to preload to ensure compatibility
SIGNING_LIBS:=${SIGNING_DIR}/libssl.so:${SIGNING_DIR}/libcrypto.so

# Put signing tool dir in the path so child programs can be located.
# Additionally, put /usr/bin at the front to prevent certain CI situations from
# using old openssl binaries.
export PATH:=/usr/bin:${SIGNING_DIR}:${SIGNING_DIR}/../sb-signing-framework/sb-signing-framework/src/client:$(PATH)

## Rules:

GEN_BUILD = dump-secureboot-config gen_default_images build_sbe_img

# Modify the dependency list when building a CFM test image
# Key transition mode environment var can be set as either "imprint" or
# "production".
ifneq ($(strip ${SECUREBOOT_KEY_TRANSITION_MODE}),)
# If is not empty
    ifeq ($(wildcard $(CFM_TEST_IMAGE)),)
# The file CFM_TEST_IMAGE could be found. The perl script (IMAGE_EDIT_PROGRAM)
# may not detect missing file
        GEN_BUILD = dump-secureboot-config gen_default_images build_sbe_img \
        	update_image_id
# Note that genPnorImages.pl will catch cases when KEY_TRANSITION_MODE_PARAMS
# is set incorrectly and report an error.
        KEY_TRANSITION_MODE_PARAMS = \
			--key-transition ${SECUREBOOT_KEY_TRANSITION_MODE}
# Location of CFM TEST artifacs to use in "update_image_id" rule
        CFM_ARTIFACT_LOCATION:=${HB_SIM_DEPS_PATH}/cfm/${CFM_TEST_ARTIFACT_ID}/
        FILE_CFM_TEST_IMAGES := \
        	${call get_files_full_path, ${CFM_ARTIFACT_LOCATION}}
    endif
endif

.PHONY: update_image_id

#################################################
###  SAMPLE for building a PNOR image
#################################################
#MURANO_TARGETING = simics_MURANO_targeting.bin
#MURANO_LAYOUT = defaultPnorLayout.xml
#murano.pnor: ${MURANO_TARGETING} ${MURANO_LAYOUT} hostboot_extended.bin \
#hostboot.bin
#    ${buildpnor.pl:P} --pnorLayout ${.PATH:F${MURANO_LAYOUT}} \
#       --pnorOutBin ${.TARGET} \
#       --binFile_HBI ${.PATH:Fhostboot_extended.bin} \
#       --binFile_HBD ${.PATH:F${MURANO_TARGETING}} \
#       --binFile_HBB ${.PATH:Fhostboot.bin} \
#       --fpartCmd "${FPARTCMD}" --fcpCmd "${FCPCMD}"
##################################################
OUTPUTPNOR: gen_system_specific_image
	${PNOR_BUILD_SCRIPT} --pnorLayout ${PNOR_LAYOUT} \
        ${IMAGE_BIN_OPTION} \
        --pnorOutBin ${OUTPUTPNOR} $(if ${TARGET_TEST}, "--test", ) \
        --fpartCmd fpart --fcpCmd fcp --editedLayoutLocation ${STAGINGDIR}

gen_system_specific_image: ${GEN_BUILD}
    # Call script to generate final bin file for chip/system specific images
	export LD_PRELOAD=${SIGNING_LIBS} && echo "Fetching OpenSSL vesion(2):" && openssl version && ${GEN_PNOR_IMAGE_SCRIPT} ${SYSTEM_SPECIFIC_PARAMS} ${BUILD_TYPE_PARAMS} ${SIGN_MODE_ARG}

gen_default_images: copy_hb_bins build_standalone_payload
	ecc --inject ${HBB_IMG} --output ${HBB_ECC_IMG} --p8


# Create 4k ocmbfw image for now (all zeroes)
	dd if=/dev/zero of=${UNPKGD_OCMBFW_IMG} bs=1024 count=4

# Add header to ocmbfw image
	${PKG_OCMBFW_SCRIPT} --unpackagedBin ${UNPKGD_OCMBFW_IMG} --packagedBin \
		${OCMBFW_IMG} --timestamp "$(shell date)" \
		--vendorVersion "0.1" --vendorUrl "http://www.ibm.com"

# verify header sha512 hash value matches value calculated against image
# TODO RTC:195547 -- remove the skip when we have a good image packaged into the driver.
	${PKG_OCMBFW_SCRIPT} --verify --packagedBin ${OCMBFW_IMG} --skipImageHashCheck

# Remove offset from start of Bootloader image for HBBL partition
# Actual code is offset from HRMOR by 12k = 12 1k-blocks (space
# reserved for exception vectors)
# Note: ibs=8 conv=sync to ensure this ends at an 8byte boundary for the
#       securerom code to start at.
	dd if=${BOOTLDR_IMG} of=${HBBL_IMG} ibs=8 skip=1536 conv=sync

# Append Hostboot securerom code size to HBBL
	du -b ${HB_SECROM_IMG} | cut -f1 | xargs printf "%016x" | sed 's/.\{2\}/\\\\x&/g' | xargs echo -n -e >> ${HBBL_IMG}
# Append Hostboot securerom code after its size
	cat ${HB_SECROM_IMG} >> ${HBBL_IMG}
# result [hbbl][pad:8:if-applicable][securerom-size:8][securerom]

# Create VERSION txt for standalone
	echo "=== HOSTBOOT_STANDALONE_VERSION ===" > ${VERSION_IMG}
	echo "${USER}-`git rev-parse HEAD`" >> ${VERSION_IMG}

# Call script to generate final bin files for default images
	export LD_PRELOAD=${SIGNING_LIBS} && echo "Fetching OpenSSL version(1):" && openssl version && ${GEN_PNOR_IMAGE_SCRIPT} ${DEFAULT_PARAMS} ${BUILD_TYPE_PARAMS} ${KEY_TRANSITION_MODE_PARAMS} ${SIGN_MODE_ARG}

# Generate the standalone payload.bin
build_standalone_payload:
	${TOOLSDIR}/create-standalone-payload ${PAYLOAD_MCL_LID} ${PAYLOAD_PHYP_LID}
	mv standalone_payload.bin ${STAGINGDIR}

#################################################
###  SAMPLE for building an SBE Partition with multiple ECs
#################################################
#S1_EC10_BIN = ${ENGD_OBJPATH:Fs1_10.sbe_seeprom.bin}
#s1SbePartition.bin: ${SBE_BUILD_SCRIPT} ${S1_EC10_BIN}
#    ${buildSbePart.pl:P} --sbeOutBin s1SbePartition.bin \
#        --ecImg_10 ${S1_EC10_BIN}
#################################################

sign_sbe_img:
	${SBE_SIGN_SCRIPT} -s ${SBE_SCRATCH_DIR} -t ${SBE_TOOL} \
		-i $(shell basename ${SBE_SEEPROM_IMAGE_DD1})

build_sbe_img: add_pnor_header
	${SBE_BUILD_SCRIPT} --sbeOutBin ${SBE_IMG} --ecImg_10 ${SBE_SEEPROM_HDR_BIN_DD1}

add_pnor_header: sign_sbe_img
	echo -en VERSION\\0 > ${SBE_SEEPROM_HDR_SHA_DD1}
	sha512sum ${SBE_SEEPROM_HDR_SHA_DD1} | awk '{print $1}' | xxd -pr -r >> ${SBE_SEEPROM_HDR_SHA_DD1}
	dd if=${SBE_SEEPROM_HDR_SHA_DD1} of=${SBE_SEEPROM_HDR_BIN_DD1} ibs=4k conv=sync
	cat $(shell basename ${SBE_SEEPROM_IMAGE_DD1}) >> ${SBE_SEEPROM_HDR_BIN_DD1}

# Copy over hostboot bins
copy_hb_bins:
	${foreach img, ${BASE_IMAGES}, \
		$(shell cp -f ${BASEIMAGESDIR}/$(shell basename ${img}) ${img} )}

# Copy over SBE bins
copy_sbe_bins:
	${foreach img, ${SBE_BASE_IMAGES}, \
		$(shell cp -f ${img} $(shell basename ${img}))}

# rule to update hostboot image tags for custom CFM image, only enabled
# when the enviroment variable CFM_TEST_IMAGE is populated
update_image_id: ${IMAGE_EDIT_PROGRAM} ${CFM_TEST_IMAGE} ${FILE_CFM_TEST_IMAGES}
	${IMAGE_EDIT_PROGRAM} --binFile=${CFM_TEST_IMAGE} \
		--symsFile=${FILE_CFM_TEST_IMAGES}

clobber:
	@-rm -rf ${STANDALONEDIR}/pnor/*
	@-rm -rf ${STANDALONEDIR}/staging/*

# Dump information about the Secure Boot configuration
# NOTE: fips/$bb/src/Buildconf sets $CONFIG_SECUREBOOT
dump-secureboot-config:
	echo -e "\n\n\
Secure Boot Signing Config:\n\
	Signing base dir     [${SIGNING_BASE_DIR}]\n\
	Redhat subdir        [${RH_DIR}]\n\
	Signing utils subdir [${SIGNING_UTILS_DIR}]\n\
	Final signing dir    [${SIGNING_DIR}]\n\
	Development key dir  [${DEV_KEY_DIR}]\n\
	Signing mode         [${BR2_OPENPOWER_SECUREBOOT_SIGN_MODE}]\n\
	Compile secureboot?  [${CONFIG_SECUREBOOT}]\n\
	Libs to preload      [${SIGNING_LIBS}]\n\
	Path                 [${PATH}]\n\n"
