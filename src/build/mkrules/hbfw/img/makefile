# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/hbfw/img/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2020
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

# TODO RTC 182358
# It's not clear that the open source signing tooling can tolerate parallelism
# when building the signature cache, so force sequential mode until that aspect
# is 100% verified
.NOTPARALLEL:

.if ($(CONTEXT:R) == "ppc")

VPATH += ../fsp

DEFAULT_PATH = ${.PATH}
SRCPATH = ${DEFAULT_PATH:M*src*}

# Modify the dependency list when building a CFM test image
.if (${CFM_TEST_IMAGE} != "")
    BUILD_ALL_DEPS = cp_hbfiles gen_default_images update_image_id
    GEN_DEFAULT_IMAGES_DEPS = cp_hbfiles update_image_id dump-secureboot-config
.else
    BUILD_ALL_DEPS = cp_hbfiles gen_default_images
    GEN_DEFAULT_IMAGES_DEPS = cp_hbfiles dump-secureboot-config
.endif

OBJECTS=hcode_lid
# Be sure to first get the hcode_lid copied at appropriate time
.if (${MAKEFILE_PASS} == "OBJECTS")
build_all: $(OBJECTS)
.else
build_all: $(BUILD_ALL_DEPS)
.endif

build_all: $(BUILD_ALL_DEPS)
install_all: gen_system_specific_images build_sbe_partitions build_pnor_images

#Some useful search paths
HBFW_OBJPATH  = ${.PATH:M*obj*}
HBFW_TARGPATH = ${HBFW_OBJPATH:S/hbfw\/img/hbfw\/fsp\/targeting\/xmltohb/g}
ENGD_OBJPATH  = ${HBFW_OBJPATH:S/hbfw\/img/engd\/href/g}
ENGD_SRCPATH  = ${SRCPATH:S/hbfw\/img/engd\/href/g}
SBEI_OBJPATH  = ${HBFW_OBJPATH:S/hbfw\/img/sbei\/sbfw\/img/g}
ENGD_WOFPATH  = ${HBFW_OBJPATH:S/hbfw\/img/engd\/wofdata/g}
ENGD_MEMDPATH = ${HBFW_OBJPATH:S/hbfw\/img/engd\/memd/g}
ENGD_OCMBPATH = ${HBFW_OBJPATH:S/hbfw\/img/engd\/ocmbfw/g}
HBFW_SIMPATH  = ${HBFW_OBJPATH:S/img/simics/g}
SIMPATH       = ${HBFW_OBJPATH:S/hbfw\/img/..\/..\/simics/g}
EDITED_LAYOUT_PATH = ${DUMMY:!pwd!}

#################################################
# Copy Hostboot binary images to obj dir to be grabbed
# during build flash pass and consumption by HWSV.
# Having external users acquire from OBJ dir as there are packaging
# changes expected in the future which will require using OBJ version.
#################################################

#variables defined to ease finding symbol files used for
#editing image tag for CFM images
hostboot_SYMS=hbicore.syms
hostboot_runtime_SYMS=hbirt.syms
hostboot_securerom_SYMS=securerom.syms
hostboot_bootloader_SYMS=hbibl.syms

IMAGE_EDIT_PROGRAM = ${editimgid:P}

# Input default images
BOOTLDR_IMG = hostboot_bootloader.bin
HBBL_IMG = hbbl.bin
HB_SECROM_IMG = hostboot_securerom.bin
HBB_IMG = hostboot.bin
HBB_ECC_IMG = hostboot.bin.ecc
HBI_IMG =  hostboot_extended.bin
HBRT_IMG = hostboot_runtime.bin
OCMBFW_IMG = ${ENGD_OCMBPATH:Ffwhdr.ocmbfw.bin}

BASE_IMAGES = ${BOOTLDR_IMG} ${HB_SECROM_IMG} ${HBB_IMG} ${HBI_IMG} ${HBRT_IMG}

# Input fake images
HBI_FAKE_IMG = hostboot_extended.bin.fake
HBD_FAKE_IMG = vbu_P10_targeting.bin
VPO_FAKE_MVPD = vpo_sysmvpd.dat
VPO_FAKE_DJVPD = vpo_djvpd.dat
VPO_FAKE_DVPD = dvpd.dat
EECACHE_FAKE_IMG = ${SIMPATH:Feecache_prebuilt_for_fake_img.bin.ecc}
FAKE_IMAGES = ${HBI_FAKE_IMG} ${VPO_FAKE_MVPD} ${VPO_FAKE_DJVPD} ${VPO_FAKE_DVPD} ${HBD_FAKE_IMG}
DEFAULT_INPUT_IMAGES = ${BASE_IMAGES} ${HBB_ECC_IMG} ${HBBL_IMG} ${FAKE_IMAGES} ${OCMBFW_IMG}

# Output final images
HBBL_FINAL_IMG = HBBL.bin
HBB_FINAL_IMG = HBB.bin
HBI_FINAL_IMG = HBI.bin
HBRT_FINAL_IMG = HBRT.bin
TEST_FINAL_IMG = TEST.bin
TESTRO_FINAL_IMG = TESTRO.bin
TESTLOAD_FINAL_IMG = TESTLOAD.bin
HBEL_FINAL_IMG = HBEL.bin
GUARD_FINAL_IMG = GUARD.bin
DJVPD_FINAL_IMG = DJVPD.bin
MVPD_FINAL_IMG = MVPD.bin
PAYLOAD_FINAL_IMG = PAYLOAD.bin
RINGOVD_FINAL_IMG = RINGOVD.bin
SBKT_FINAL_IMG = SBKT.bin
MEMD_FINAL_IMG = MEMD.bin
EECACHE_FINAL_IMG = EECACHE.bin
OCMBFW_FINAL_IMG = OCMBFW.bin
FINAL_OUTPUT_IMAGES = ${HBBL_FINAL_IMG} ${HBB_FINAL_IMG} ${HBI_FINAL_IMG} \
		      ${HBRT_FINAL_IMG} ${TEST_FINAL_IMG} ${TESTRO_FINAL_IMG} \
		      ${HBEL_FINAL_IMG} ${GUARD_FINAL_IMG} \
		      ${DJVPD_FINAL_IMG} ${MVPD_FINAL_IMG} \
		      ${PAYLOAD_FINAL_IMG} ${RINGOVD_FINAL_IMG} ${SBKT_FINAL_IMG} \
		      ${MEMD_FINAL_IMG} ${EECACHE_FINAL_IMG} \
		      $(OCMBFW_FINAL_IMG}

# Aggregate
ALL_DEFAULT_IMAGES = ${DEFAULT_INPUT_IMAGES} ${FINAL_OUTPUT_IMAGES}

# Imprint hw keys hash
IMPRINT_HW_KEY_HASH = ${imprintHwKeyHash:P}

# Script to manipulate bin files to prepare for buildpnor (install_all phase)
# Note: sections with no input files are zero filled images and pass EMPTY as
#	their input file name. This is so the script knows it needs to generate
#	them, rather than use an input.
# Note: HBI depends on HBB for sw signatures. Ensure that both are passed into
#	the same --systemBinFiles parameter for genPnorImages
GEN_PNOR_IMAGE_SCRIPT = ${genPnorImages.pl:P}

# Determine which version of Redhat we're building on and generate the
# associated sub-directory name used to construct the signing binaries path.
# Most pool machines have back level libraries used for signing, so point to
# usable ones.
# The unescaped version of the command is:
#     sed "s/^.*release \([0-9]*\)\..*$/rh\1/" /etc/redhat-release
# Any character not in the following set must be escaped:
#     [a-zA-Z0-9,._+:@%/-]
RH_DIR%=${DUMMY:!sed "s/\^.\*release \\\(\[0-9\]\*\\\)\..\*\$/rh\\1/\" /etc/redhat-release!e}

# Use Secure Boot development signing if not specified in the environment
BR2_OPENPOWER_SECUREBOOT_SIGN_MODE?=development
SIGN_MODE_ARG=--sign-mode ${BR2_OPENPOWER_SECUREBOOT_SIGN_MODE}

# Concatenate the base path, Redhat specific dir, and tool subdir to form the
# complete signing tools path
SIGNING_DIR%=${SIGNING_BASE_DIR}/${RH_DIR}/${SIGNING_UTILS_DIR}

# Construct the set of libs we need to preload to ensure compatibility
SIGNING_LIBS%=${SIGNING_DIR}/libssl.so:${SIGNING_DIR}/libcrypto.so

# Put signing tool dir in the path so child programs can be located.
# Additionally, put /usr/bin at the front to prevent certain CI situations from
# using old openssl binaries.
PATH%=/usr/bin:${SIGNING_DIR}:${SIGNING_DIR}/../sb-signing-framework/sb-signing-framework/src/client:${PATH}

# Dump information about the Secure Boot configuration
# NOTE: fips/$bb/src/Buildconf sets $CONFIG_SECUREBOOT
dump-secureboot-config : .FORCEBLD
	echo -e "\n\n\
Secure Boot Signing Config:\n\
    Signing base dir	 [${SIGNING_BASE_DIR}]\n\
    Redhat subdir	 [${RH_DIR}]\n\
    Signing utils subdir [${SIGNING_UTILS_DIR}]\n\
    Final signing dir	 [${SIGNING_DIR}]\n\
    Development key dir  [${DEV_KEY_DIR}]\n\
    Signing mode	 [${BR2_OPENPOWER_SECUREBOOT_SIGN_MODE}]\n\
    Compile secureboot?  [${CONFIG_SECUREBOOT}]\n\
    Libs to preload	 [${SIGNING_LIBS}]\n\
    Path		 [${PATH}]\n\n"

# Use FSP layout for any FSP based system
# Use Default layout for standalone simics
# Use P10 layout for P10 simics
PNOR_LAYOUT = ${pnorLayoutFSP.xml:P}
# default PNOR_LAYOUT_SELECTED to be FSP unless it is already defined
PNOR_LAYOUT_SELECTED ?= "FSP"

.if (${PNOR_LAYOUT_SELECTED} == "STANDALONE")
    PNOR_LAYOUT = ${defaultPnorLayout.xml:P}
.endif

.if (${PNOR_LAYOUT_SELECTED} == "P10")
    PNOR_LAYOUT = ${pnorLayoutP10.xml:P}
.endif

# Since this makefile is only ever used for an FSP signing environment, then
# we can just specify that we want an fspbuild here without any condition.
BUILD_TYPE_PARAMS = --build-type fspbuild

# Here we check to see if a key transition mode was set in the environment.
# This can be either 'imprint' or 'production'. The genPnorImages.pl will catch
# cases when it is set incorrectly and report an error.
.if (${SECUREBOOT_KEY_TRANSITION_MODE} != "") # genPnorImages handles bad parm
    KEY_TRANSITION_MODE_PARAMS = --key-transition ${SECUREBOOT_KEY_TRANSITION_MODE}
.endif

# Decide which images to use for each PNOR layout
GEN_COMMON_BIN_FILES = HBBL=${HBBL_IMG},HBB=${HBB_IMG},HBI=${HBI_IMG},HBRT=${HBRT_IMG},HBEL=EMPTY,GUARD=EMPTY,RINGOVD=EMPTY,SBKT=EMPTY
GEN_STANDALONE_BIN_FILES = ${GEN_COMMON_BIN_FILES},TEST=EMPTY,TESTRO=EMPTY,TESTLOAD=EMPTY,PAYLOAD=EMPTY
.if (${FAKEPNOR} == "")
    # Parameters passed into GEN_PNOR_IMAGE_SCRIPT.
    .if (${PNOR_LAYOUT_SELECTED} == "STANDALONE")
	GEN_DEFAULT_BIN_FILES = ${GEN_STANDALONE_BIN_FILES},MEMD=${${ZZ_MEMD_IMG}:P}DJVPD=EMPTY,MVPD=EMPTY,EECACHE=EMPTY
    .elif(${PNOR_LAYOUT_SELECTED} == "P10")
	GEN_DEFAULT_BIN_FILES = ${GEN_STANDALONE_BIN_FILES},EECACHE=EMPTY,OCMBFW=${${OCMBFW_IMG}:P}
    .else
	GEN_DEFAULT_BIN_FILES = ${GEN_COMMON_BIN_FILES},MEMD=${${ZZ_MEMD_IMG}:P},EECACHE=EMPTY,OCMBFW=${${OCMBFW_IMG}:P}
    .endif
    DEFAULT_PARAMS = --build-all --emit-eccless ${TARGET_TEST:b--test} ${HB_STANDALONE:b--hb-standalone} \
                     ${CONFIG_SECUREBOOT:b--secureboot} --systemBinFiles ${GEN_DEFAULT_BIN_FILES} \
                     --pnorLayout ${PNOR_LAYOUT} ${KEY_TRANSITION_PARAMS} ${CORRUPT_PARAMS} \
                     --hwKeyHashFile ${IMPRINT_HW_KEY_HASH} \
                     --secure-version ${SIGNING_SECURITY_VERSION} \
                     --editedLayoutLocation ${EDITED_LAYOUT_PATH}
.else
    PNOR_LAYOUT = ${pnorLayoutFake.xml:P}
    # Parameters passed into GEN_PNOR_IMAGE_SCRIPT.
    GEN_DEFAULT_BIN_FILES = HBI=${HBI_IMG},HBEL=EMPTY,EECACHE=${${EECACHE_FAKE_IMG}:P}
    DEFAULT_PARAMS = --systemBinFiles ${GEN_DEFAULT_BIN_FILES} --pnorLayout ${PNOR_LAYOUT} \
		     --editedLayoutLocation ${EDITED_LAYOUT_PATH}
.endif

# rule to update hostboot image tags for custom CFM image, only enabled
# when the enviroment variable CFM_TEST_IMAGE is populated
update_image_id: cp_hbfiles validate_cfm_image_name
	${IMAGE_EDIT_PROGRAM} --binFile=${CFM_TEST_IMAGE:p} \
	--symsFile=${HBFW_SIMPATH:F${${CFM_TEST_IMAGE:R}_SYMS}}

# make sure the files exist - the perl script isnt all that smart
validate_cfm_image_name: ${CFM_TEST_IMAGE:p} \
	${HBFW_SIMPATH:F${${CFM_TEST_IMAGE:R}_SYMS}}

cp_hbfiles: .SPECTARG
	${BASE_IMAGES:@image@cp -f ${SRCPATH:F${image}} ${image};@}

gen_default_images: ${GEN_DEFAULT_IMAGES_DEPS}
	currentsb -chain
	${JAILCMD} ecc --inject ${HBB_IMG} --output ${HBB_ECC_IMG} --p8

    # Remove offset from start of Bootloader image for HBBL partition
    # Actual code is offset from HRMOR by 12k = 12 1k-blocks (space
    # reserved for exception vectors)
    # Note: ibs=8 conv=sync to ensure this ends at an 8byte boundary for the
    #	    securerom code to start at.
	dd if=${BOOTLDR_IMG} of=${HBBL_IMG} ibs=8 skip=1536 conv=sync

    # Append Hostboot securerom code size to HBBL
	du -b ${HB_SECROM_IMG} | cut -f1 | xargs printf "%016x" | sed 's/.\{2\}/\\\\x&/g' | xargs echo -n -e >> ${HBBL_IMG}
    # Append Hostboot securerom code after its size
	cat ${HB_SECROM_IMG} >> ${HBBL_IMG}
    # result [hbbl][pad:8:if-applicable][securerom-size:8][securerom]

	# Call script to generate final bin files for default images
	export LD_PRELOAD=${SIGNING_LIBS} && echo "Fetching OpenSSL version(1):" && openssl version && ${GEN_PNOR_IMAGE_SCRIPT} ${DEFAULT_PARAMS} ${BUILD_TYPE_PARAMS} ${KEY_TRANSITION_MODE_PARAMS} ${SIGN_MODE_ARG}

clobber_cp_hbfiles:
	rm -f ${ALL_DEFAULT_IMAGES}

#################################################
###  SAMPLE for building an SBE Partition with multiple ECs
#################################################
#S1_EC10_BIN = ${ENGD_OBJPATH:Fs1_10.sbe_seeprom.bin}
#s1SbePartition.bin: ${SBE_BUILD_SCRIPT} ${S1_EC10_BIN}
#	${buildSbePart.pl:P} --sbeOutBin s1SbePartition.bin \
#		--ecImg_10 ${S1_EC10_BIN}
#################################################
SBE_BUILD_SCRIPT = ${buildSbePart.pl:P}

P10_SBE_IMG   = p10.SbePartition.bin

# Fix this when SBE is generating p10_10.sbe_seeprom.hdr.bin
P10_EC10_BIN = ${SBEI_OBJPATH:Fp10_10.sbe_seeprom.hdr.bin}

SBE_PART_INFO = \
  ${P10_SBE_IMG}:10=${P10_EC10_BIN}

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

${SBEPART_TARGET}: ${SBEPART_LAYOUT} ${SBEPART_BINS} ${PNOR_BUILD_SCRIPT} ${GEN_PNOR_IMAGE_SCRIPT}
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

HBFW_OBJPATH = ${.PATH:M*obj*}
ENGD_OBJPATH = ${HBFW_OBJPATH:S/hbfw\/img/engd\/href/g}

# Input images
## Chip Specific
P10_HBD_IMG = simics_P10_targeting.bin

# Needs to also appear in /fips1010/src/fipsfs/engd.fipsfs.db
# #hw ref image
# ||hbfw/img/p10.hw_ref_image.header.bin|opt/fips/components/hwsv/p10.hw_ref_image.hdr.bin|p10cec(CP_755)|
# ||hbfw/img/p10.hw_ref_image_lid.header.bin|opt/fips/components/hwsv/p10.hw_ref_image_lid.hdr.bin|p10cec(CP_755)|
P10_HCODE_IMG = ${ENGD_SRCPATH:Fp10.hw_ref_image.bin}
P10_HCODE_LID_IMG = p10.hw_ref_image_lid.bin

hcode_lid: ${ENGD_SRCPATH:Fp10.hw_ref_image.bin}
	cp ${ENGD_SRCPATH:Fp10.hw_ref_image.bin} ${P10_HCODE_LID_IMG}

P10_OCC_IMG = ${bb}/images/ppc/lab/fs/p9le/rootfs/opt/extucode/81e00430.lid

## System Specific

DENALI_WOFDATA_IMG = ${ENGD_WOFPATH:Fdenali_wof_data.bin}

# Create list of images for each node (in node order)
# genPnorImages will handle multiple HBD=binfile pairs
DENALI_HBD_IMGS = HBD=${${HBFW_TARGPATH:FDENALI_node_0_hb_targeting.bin}:P},HBD=${${HBFW_TARGPATH:FDENALI_node_1_hb_targeting.bin}:P},HBD=${${HBFW_TARGPATH:FDENALI_node_2_hb_targeting.bin}:P},HBD=${${HBFW_TARGPATH:FDENALI_node_3_hb_targeting.bin}:P},HBD=${${HBFW_TARGPATH:FDENALI_SMP_WRAP_node_0_hb_targeting.bin}:P},HBD=${${HBFW_TARGPATH:FDENALI_2N_node_0_hb_targeting.bin}:P},HBD=${${HBFW_TARGPATH:FDENALI_2N_node_1_hb_targeting.bin}:P}

# Input fake images

# Output final images
# Final eyecatch name must match PNOR xml layout
## Chip Specific
P10_HBD_FINAL_IMG = P10.HBD.bin
P10_HCODE_FINAL_IMG = P10.HCODE.bin
P10_HCODE_LID_FINAL_IMG = P10.HCODE_LID.bin
P10_SBE_FINAL_IMG = P10.SBE.bin
P10_OCC_FINAL_IMG = P10.OCC.bin
## System Specific
DENALI_HBD_FINAL_IMG = DENALI.HBD_NODE_0.bin
DENALI_WOFDATA_FINAL_IMG = DENALI.WOFDATA.bin
# Fips has its own build process and will not use these, but rather what's
# defined in fipsfs.db.



# Decide which PNOR to build
# Paramemters passed into GEN_PNOR_IMAGE_SCRIPT.
.if (${PNOR_LAYOUT_SELECTED} == "STANDALONE")
    GEN_P10_BIN_FILES = P10:SBE=${${P10_SBE_IMG}:P},HCODE=${${P10_HCODE_IMG}:P},HCODE_LID=${${P10_HCODE_LID_IMG}:P},OCC=${${P10_OCC_IMG}:P},HBD=${${P10_HBD_IMG}:P}
.else
    GEN_P10_BIN_FILES = P10:SBE=${${P10_SBE_IMG}:P},HCODE=${${P10_HCODE_IMG}:P},HCODE_LID=${${P10_HCODE_LID_IMG}:P},OCC=${${P10_OCC_IMG}:P},HBD=${${P10_HBD_IMG}:P}
.endif
GEN_DENALI_BIN_FILES = DENALI:WOFDATA=${${DENALI_WOFDATA_IMG}:P},${DENALI_HBD_IMGS}
SYSTEM_SPECIFIC_PARAMS = --install-all --emit-eccless ${TARGET_TEST:b--test} ${CONFIG_SECUREBOOT:b--secureboot}  \
			 --pnorLayout ${PNOR_LAYOUT} ${CORRUPT_PARAMS} ${HB_STANDALONE:b--hb-standalone} \
			 --systemBinFiles ${GEN_DENALI_BIN_FILES} \
			 --systemBinFiles ${GEN_P10_BIN_FILES} \
			 --hwKeyHashFile ${IMPRINT_HW_KEY_HASH} \
                         --secure-version ${SIGNING_SECURITY_VERSION} \
			 --editedLayoutLocation ${EDITED_LAYOUT_PATH}

gen_system_specific_images_bypass_cache : dump-secureboot-config hcode_lid
	# Call script to generate final bin file for chip/system specific images
	export LD_PRELOAD=${SIGNING_LIBS} && echo "Fetching OpenSSL vesion(2):" && openssl version && ${GEN_PNOR_IMAGE_SCRIPT} ${SYSTEM_SPECIFIC_PARAMS} ${BUILD_TYPE_PARAMS} ${SIGN_MODE_ARG}

# build_sbe_partitions build step generates SBE partition files that ODE is
# unaware of due to the file cache that we cannot disable.  To work around that,
# build the PNOR images under recursive make, which gets a fresh view of the
# updated file system
gen_system_specific_images: build_sbe_partitions .PMAKE
	@${MAKE:T:R} gen_system_specific_images_bypass_cache


.if (${PNOR_LAYOUT_SELECTED} == "FSP")
    HOSTBOOT_DEFAULT_SECTIONS = HBBL=${HBBL_FINAL_IMG},HBB=${HBB_FINAL_IMG},HBI=${HBI_FINAL_IMG},HBRT=${HBRT_FINAL_IMG},HBEL=${HBEL_FINAL_IMG},GUARD=${GUARD_FINAL_IMG},RINGOVD=${RINGOVD_FINAL_IMG},SBKT=${SBKT_FINAL_IMG}
.else
    HOSTBOOT_DEFAULT_SECTIONS = HBBL=${HBBL_FINAL_IMG},HBB=${HBB_FINAL_IMG},HBI=${HBI_FINAL_IMG},HBRT=${HBRT_FINAL_IMG},TEST=${TEST_FINAL_IMG},TESTRO=${TESTRO_FINAL_IMG},TESTLOAD=${TESTLOAD_FINAL_IMG},HBEL=${HBEL_FINAL_IMG},GUARD=${GUARD_FINAL_IMG},PAYLOAD=${PAYLOAD_FINAL_IMG},RINGOVD=${RINGOVD_FINAL_IMG},SBKT=${SBKT_FINAL_IMG}
.endif

DENALI_SECT = HBD=${DENALI_HBD_FINAL_IMG},SBE=${P10_SBE_FINAL_IMG},HCODE=${P10_HCODE_FINAL_IMG},HCODE_LID=${P10_HCODE_LID_FINAL_IMG},OCC=${P10_OCC_FINAL_IMG},WOFDATA=${DENALI_WOFDATA_FINAL_IMG},EECACHE=${EECACHE_FINAL_IMG},OCMBFW=${OCMBFW_FINAL_IMG}
P10_SECT = HBD=${P10_HBD_FINAL_IMG},SBE=${P10_SBE_FINAL_IMG},HCODE=${P10_HCODE_FINAL_IMG},HCODE_LID=${P10_HCODE_LID_FINAL_IMG},OCC=${P10_OCC_FINAL_IMG},WOFDATA=${DENALI_WOFDATA_FINAL_IMG},EECACHE=${EECACHE_FINAL_IMG},OCMBFW=${OCMBFW_FINAL_IMG}


.if (${PNOR_LAYOUT_SELECTED} == "P10")
PNOR_IMG_INFO = \
   p10.pnor:${PNOR_LAYOUT}:${P10_SECT},${HOSTBOOT_DEFAULT_SECTIONS}
.else
PNOR_IMG_INFO = \
   ${FIPS_PNOR_INFO}
.endif

# Added a different dependency chain for hostboot builds so we can compile
# faster and call one rule in dist.targets.mk 'update_images_for_sandbox'
.if ( ${HB_STANDALONE} == 1 )
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
	.if (${PNOR} == ${IMAGE_TARGET} || ${PNOR} == "" || \
			${FAKEPNOR} == ${IMAGE_TARGET})
		${PNOR_BUILD_SCRIPT} --pnorOutBin ${IMAGE_TARGET} \
			${TARGET_TEST:b--test} --pnorLayout ${IMAGE_LAYOUT} \
			${IMAGE_BIN_OPTION} --fpartCmd "fpart" --fcpCmd "fcp" \
			--editedLayoutLocation ${EDITED_LAYOUT_PATH}
	.endif
.endif

build_pnor_images:.SPECTARG ${PNOR_IMG_INFO:S/^/__IMAGE_BUILD\//g}

clobber_build_pnor_images:
	${PNOR_IMG_INFO:@image@${pnorimg:!rm -f ${image:s/:/ /g:xs/ .*//};!e}@}

#################################################
#Special target to copy images to flash dir for simics
#################################################
FLASH_DEST = $(MAKETOP)$(OBJECTDIRTOP)../images/$(CONTEXT)/lab/flash
FLASH_IMG = ${HBB_IMG} ${HBB_ECC_IMG} ${HBBL_IMG}

update_images_for_sandbox:  gen_default_images gen_system_specific_images build_sbe_partitions build_pnor_images
	mkdir -p ${FLASH_DEST}
	#Copy hostboot base image and bootloader image to flash dir
	${FLASH_IMG:@image@${baseimg:!cd ${FLASH_DEST}; cp -f ${.PATH:F${image}} ${image};!e}@}
	#Copy pnor images to flash dir
	${PNOR_IMG_INFO:@image@${pnorimg:!cd ${FLASH_DEST}; \
		if [ "${PNOR}" == "${image:s/:/ /g:xs/ .*//}" ] || \
			[ "${PNOR}" == "" ] ; \
		then cp -f ${.PATH:F${image:s/:/ /g:xs/ .*//}} ${image:s/:/ /g:xs/ .*//}; fi !e}@}

.endif

