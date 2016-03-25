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

build_all: cp_hbfiles
install_all: inject_ecc build_sbe_partitions build_pnor_images

#Some useful search paths
HBFW_OBJPATH = ${.PATH:M*obj*}
ENGD_OBJPATH = ${HBFW_OBJPATH:S/hbfw\/img/engd\/href/g}

#################################################
# Copy Hostboot binary images to obj dir to be grabbed
# during build flash pass and consumption by HWSV.
# Having external users acquire from OBJ dir as there are packaging
# changes expected in the future which will require using OBJ version.
#################################################
BOOTLDR_IMAGE = hostboot_bootloader.bin
HBBL_IMAGE = hbbl.bin
HBBL_ECC_IMAGE = hbbl.bin.ecc
BASE_IMAGE = hostboot.bin
EXT_IMAGE =  hostboot_extended.bin
EXT_FAKE_IMAGE = hostboot_extended.bin.fake
HBRT_IMAGE = hostboot_runtime.bin
HBRT_SHA_IMAGE = hostboot_runtime.sha.bin
HBRT_HEADER_IMAGE = hostboot_runtime.header.bin
HBRT_ECC_HEADER_IMAGE = hostboot_runtime.header.bin.ecc
BASE_IMAGES = ${BASE_IMAGE} ${EXT_IMAGE} ${HBRT_IMAGE} ${BOOTLDR_IMAGE}
BASE_W_HEADER_IMAGE = hostboot.header.bin
BASE_W_HEADER_ECC_IMAGE = hostboot.header.bin.ecc
BASE_ECC_IMAGE = hostboot.bin.ecc
BASE_SHA_IMAGE = hostboot.sha.bin
EXT_PAD_IMAGE = hostboot_extended.bin.pad
EXT_ECC_IMAGE = hostboot_extended.bin.ecc
EXT_ECC_HEADER_IMAGE = hostboot_extended.header.bin.ecc
EXT_SHA_IMAGE = hostboot_extended.sha.bin
EXT_HEADER_IMAGE = hostboot_extended.header.bin
TEMP_IMAGE = hostboot.temp.bin
TESTDATA = hbtestdata.bin
TESTDATA_ECC = hbtestdata.bin.ecc
HBEL_ECC_IMAGE = hbel.bin.ecc
HBEL_IMAGE = hbel.bin
GUARD_ECC_IMAGE = guard.bin.ecc
GLOBAL_ECC_IMAGE = global.bin.ecc
DJVPD_ECC_IMAGE = djvpd.bin.ecc
DJVPD_IMAGE = djvpd.bin
MVPD_ECC_IMAGE = mvpd.bin.ecc
MVPD_IMAGE = mvpd.bin
CVPD_ECC_IMAGE = cvpd.bin.ecc
PAYLOAD_ECC_IMAGE = payload.bin.ecc
SECUREBOOT_HEADER = secureboot.header
SECUREBOOT_SIGNED_CONTAINER = secureboot_signed_container
# DEV_KEY_DIR set by env variable
SIGN_PREFIX_PARAMS=-flag 0x80000000 -hka ${DEV_KEY_DIR}/hw_key_a -hkb ${DEV_KEY_DIR}/hw_key_b -hkc ${DEV_KEY_DIR}/hw_key_c -skp ${DEV_KEY_DIR}/sw_key_a
SIGN_BUILD_PARAMS=-skp ${DEV_KEY_DIR}/sw_key_a
VPO_FAKE_MVPD = vpo_sysmvpd.dat

ALL_HB_IMAGES = ${BASE_IMAGES} \
                ${BASE_W_HEADER_IMAGE} \
                ${BASE_ECC_IMAGE} ${EXT_ECC_IMAGE} \
                ${BASE_W_HEADER_ECC_IMAGE} ${BASE_SHA_IMAGE}\
                ${HBRT_SHA_IMAGE} \
                ${HBRT_HEADER_IMAGE} ${HBRT_ECC_HEADER_IMAGE} \
                ${EXT_PAD_IMAGE} \
                ${EXT_SHA_IMAGE} ${EXT_HEADER_IMAGE} \
                ${EXT_ECC_HEADER_IMAGE} \
                ${BOOTLDR_IMAGE} ${HBBL_IMAGE} ${HBBL_ECC_IMAGE} \
                ${TESTDATA} ${TESTDATA_ECC} \
                ${HBEL_ECC_IMAGE} ${GUARD_ECC_IMAGE} ${GLOBAL_ECC_IMAGE} \
                ${DJVPD_ECC_IMAGE} ${MVPD_ECC_IMAGE} ${CVPD_ECC_IMAGE} \
                ${HBEL_IMAGE} ${DJVPD_IMAGE} ${MVPD_IMAGE} \
                ${PAYLOAD_ECC_IMAGE}

cp_hbfiles: .SPECTARG
	${BASE_IMAGES:@image@cp -f ${SRCPATH:F${image}} ${image};@}
	echo "00000000001800000000000008000000000000000007EF80" | xxd -r -ps - sbe.header
	# add version header w/ HBB sha hash
	echo -en VERSION\\0 > ${BASE_SHA_IMAGE}
	sha512sum ${BASE_IMAGE} | awk '{print $$1}' | xxd -pr -r >> ${BASE_SHA_IMAGE}
	dd if=${BASE_SHA_IMAGE} of=secureboot.header ibs=4k conv=sync
	dd if=/dev/zero of=hbb.footer count=1 bs=128K
	cat sbe.header secureboot.header ${BASE_IMAGE} hbb.footer > hostboot.stage.bin
	head -c 524288  hostboot.stage.bin > ${BASE_W_HEADER_IMAGE}
	currentsb -chain
	ecc --inject ${BASE_IMAGE} --output ${BASE_ECC_IMAGE} --p8
	ecc --inject ${BASE_W_HEADER_IMAGE} --output ${BASE_W_HEADER_ECC_IMAGE} --p8

	# Add version header w/ HBRT sha hash
	echo -en VERSION\\0 > ${HBRT_SHA_IMAGE}
	sha512sum ${HBRT_IMAGE} | awk '{print $$1}' | xxd -pr -r >> ${HBRT_SHA_IMAGE}
	dd if=${HBRT_SHA_IMAGE} of=${TEMP_IMAGE} ibs=4k conv=sync
	cat ${HBRT_IMAGE} >> ${TEMP_IMAGE}
	# HBRT partition size w/o ECC = 2MB (2048K)
	dd if=${TEMP_IMAGE} of=${HBRT_HEADER_IMAGE} ibs=2048K conv=sync
	ecc --inject ${HBRT_HEADER_IMAGE} --output ${HBRT_ECC_HEADER_IMAGE} --p8
	# Add version header w/ HBI sha hash
	echo -en VERSION\\0 > ${EXT_SHA_IMAGE}
	sha512sum ${EXT_IMAGE} | awk '{print $$1}' | xxd -pr -r >> ${EXT_SHA_IMAGE}
	dd if=${EXT_SHA_IMAGE} of=${TEMP_IMAGE} ibs=4k conv=sync
	cat ${EXT_IMAGE} >> ${TEMP_IMAGE}
	# HBI partition size w/o ECC = 5MB (5120K)
	# If "--test" flag set do not pad to ibs=5120k, as the test HBI images is
	# possibly larger than parition size and does not need to be fully padded.
	# Size adjustments made in buildpnor.pl
	.if(${TARGET_TEST})
		dd if=${TEMP_IMAGE} of=${EXT_HEADER_IMAGE} ibs=4k conv=sync
	.else
		dd if=${TEMP_IMAGE} of=${EXT_HEADER_IMAGE} ibs=5120k conv=sync
	.endif
	ecc --inject ${EXT_HEADER_IMAGE} --output ${EXT_ECC_HEADER_IMAGE} --p8
	dd if=${EXT_IMAGE} of=${EXT_PAD_IMAGE} ibs=4k count=1280 conv=sync
	ecc --inject ${EXT_PAD_IMAGE} --output ${EXT_ECC_IMAGE} --p8

	# Test signed container, SIGNING_DIR set by env variable
	.if(${SECUREBOOT} && ${SIGNING_DIR})
        # Key prefix used for all partitions
		${SIGNING_DIR}/prefix -good -of ${SECUREBOOT_HEADER} ${SIGN_PREFIX_PARAMS}
		dd if=/dev/zero count=1 | tr "\000" "\377" > ${TEMP_IMAGE}
		${SIGNING_DIR}/build -good -if ${SECUREBOOT_HEADER} -of ${SECUREBOOT_SIGNED_CONTAINER} -bin ${TEMP_IMAGE} ${SIGN_BUILD_PARAMS}
	.endif

	# Pad and add ECC to other partitions that do not need headers
	# create data for a test partition in pnor
	dd if=/dev/urandom of=${TESTDATA} count=1 bs=32K
	ecc --inject ${TESTDATA} --output ${TESTDATA_ECC} --p8
	# Fill the following partitions with FF's and then ECC them
	dd if=/dev/zero bs=128K count=1 | tr "\000" "\377" > ${TEMP_IMAGE}
	ecc --inject ${TEMP_IMAGE} --output ${HBEL_ECC_IMAGE} --p8
        .if(${FAKEPNOR} != "")
	dd if=/dev/zero bs=64K count=1 | tr "\000" "\377" > ${HBEL_IMAGE}
        .endif
	# GUARD partition
	dd if=/dev/zero bs=16K count=1 | tr "\000" "\377" > ${TEMP_IMAGE}
	ecc --inject ${TEMP_IMAGE} --output ${GUARD_ECC_IMAGE} --p8
	# GLOBAL partition
	dd if=/dev/zero bs=32K count=1 | tr "\000" "\377" > ${TEMP_IMAGE}
	ecc --inject ${TEMP_IMAGE} --output ${GLOBAL_ECC_IMAGE} --p8
	# DJVPD partition
	dd if=/dev/zero bs=256K count=1 | tr "\000" "\377" > ${TEMP_IMAGE}
	ecc --inject ${TEMP_IMAGE} --output ${DJVPD_ECC_IMAGE} --p8
        .if(${FAKEPNOR} != "")
	dd if=/dev/zero bs=32K count=1 | tr "\000" "\377" > ${DJVPD_IMAGE}
        .endif
	# MVPD partition
	dd if=/dev/zero bs=512K count=1 | tr "\000" "\377" > ${TEMP_IMAGE}
	ecc --inject ${TEMP_IMAGE} --output ${MVPD_ECC_IMAGE} --p8
        .if(${FAKEPNOR} != "")
	dd if=${${VPO_FAKE_MVPD}:P} bs=128K count=1 > ${MVPD_IMAGE}
        .endif
	# CVPD partition
	dd if=/dev/zero bs=256K count=1 | tr "\000" "\377" > ${TEMP_IMAGE}
	ecc --inject ${TEMP_IMAGE} --output ${CVPD_ECC_IMAGE} --p8
	# PAYLOAD partition
	dd if=/dev/zero bs=20480K count=1 | tr "\000" "\377" > ${TEMP_IMAGE}
	ecc --inject ${TEMP_IMAGE} --output ${PAYLOAD_ECC_IMAGE} --p8
	rm ${TEMP_IMAGE}
        # Remove offset from start of Bootloader image for HBBL partition
        # Actual code is offset from HRMOR by 12k = 12 1k-blocks (space
        # reserved for exception vectors)
	dd if=${BOOTLDR_IMAGE} of=${HBBL_IMAGE} ibs=1k skip=12 conv=sync
	ecc --inject ${HBBL_IMAGE} --output ${HBBL_ECC_IMAGE} --p8

clobber_cp_hbfiles:
	rm -f ${ALL_HB_IMAGES} \
	      sbe.header secureboot.header hb.footer hostboot.stage.bin

#################################################
###  SAMPLE for building an SBE Partition with multiple ECs
#################################################
#S1_EC10_BIN = ${ENGD_OBJPATH:Fs1_10.sbe_seeprom.bin}
#s1SbePartition.bin: ${SBE_BUILD_SCRIPT} ${S1_EC10_BIN}
#	${buildSbePart.pl:P} --sbeOutBin s1SbePartition.bin \
#		--ecImg_10 ${S1_EC10_BIN}
#################################################
SBE_BUILD_SCRIPT = ${buildSbePart.pl:P}

P9N_EC10_BIN = ${ENGD_OBJPATH:Fp9n_10.sbe_seeprom.hdr.bin}

SBE_PART_INFO = \
  p9nSbePartition.bin:10=${P9N_EC10_BIN}


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

#early hostboot use of this makefile will be against FSP drivers lacking fips_pnor.mk
#so need to use tryinclude for now.
.tryinclude <${.PATH:Ffips_pnor.mk}>

HOSTBOOT_DEFAULT_SECTIONS = HBB=${BASE_W_HEADER_ECC_IMAGE},HBI=${EXT_ECC_HEADER_IMAGE},HBRT=${HBRT_ECC_HEADER_IMAGE},HBBL=${HBBL_ECC_IMAGE},TEST=${TESTDATA_ECC},TESTRO=${TESTDATA_ECC},HBEL=${HBEL_ECC_IMAGE},GUARD=${GUARD_ECC_IMAGE},GLOBAL=${GLOBAL_ECC_IMAGE},PAYLOAD=${PAYLOAD_ECC_IMAGE},CVPD=${CVPD_ECC_IMAGE},MVPD=${MVPD_ECC_IMAGE},DJVPD=${DJVPD_ECC_IMAGE}
HOSTBOOT_FAKEPNOR_SECTIONS = HBI=${EXT_FAKE_IMAGE},HBEL=${HBEL_IMAGE},MVPD=${MVPD_IMAGE},DJVPD=${DJVPD_IMAGE}


HBFW_OBJPATH = ${.PATH:M*obj*}
ENGD_OBJPATH = ${HBFW_OBJPATH:S/hbfw\/img/engd\/href/g}
NIMBUS_TARG_IMG = simics_NIMBUS_targeting.bin
NIMBUS_VPO_TARG_IMG = vbu_NIMBUS_targeting.bin
NIMBUS_TARG_IMG_ECC = simics_NIMBUS_targeting.bin.ecc
NIMBUS_TARG_IMG_FAKE = vbu_NIMBUS_targeting.bin.fake
NIMBUS_SLW_IMG = ${ENGD_OBJPATH:Fp9n.hw_ref_image.hdr.bin}
NIMBUS_LOCAL_SLW_IMG = p9n.hw_ref_image.hdr.bin
NIMBUS_LOCAL_SLW_IMG_ECC = p9n.hw_ref_image.hdr.bin.ecc
NIMBUS_SBE_IMG = p9nSbePartition.bin
NIMBUS_SBE_IMG_ECC = p9nSbePartition.bin.ecc
SBEC_IMG = centSbePartition.bin
SBEC_IMG_ECC = centSbePartition.bin.ecc
TEMP_IMG = temp.bin

inject_ecc: build_sbe_partitions
	# cp file with full path to one with local path
	cp ${NIMBUS_SLW_IMG} ${NIMBUS_LOCAL_SLW_IMG}
	# HBD partition
	dd if=${${NIMBUS_TARG_IMG}:P} of=${TEMP_IMG} ibs=1024k conv=sync; \
	ecc --inject ${TEMP_IMG} --output ${NIMBUS_TARG_IMG_ECC} --p8; \
	#for NIMBUS fake pnor skip version header
	dd if=${${NIMBUS_VPO_TARG_IMG}:P} of=${NIMBUS_TARG_IMG_FAKE} ibs=4k count=32 skip=1 conv=sync; \
	# SBE partition
	dd if=${${NIMBUS_SBE_IMG}:P} of=${TEMP_IMG} ibs=256k conv=sync; \
	ecc --inject ${TEMP_IMG} --output ${NIMBUS_SBE_IMG_ECC} --p8; \
	# SBEC partition
	dd if=${${SBEC_IMG}:P} of=${TEMP_IMG} ibs=512k conv=sync; \
	ecc --inject ${TEMP_IMG} --output ${SBEC_IMG_ECC} --p8; \
	# WINK partition
	dd if=${${NIMBUS_LOCAL_SLW_IMG}:P} of=${TEMP_IMG} ibs=1024k conv=sync; \
	ecc --inject ${TEMP_IMG} --output ${NIMBUS_LOCAL_SLW_IMG_ECC} --p8; \
	rm ${TEMP_IMG}

NIMBUS_SECT = HBD=${NIMBUS_TARG_IMG_ECC},SBE=${NIMBUS_SBE_IMG_ECC},SBEC=${SBEC_IMG_ECC},WINK=${NIMBUS_LOCAL_SLW_IMG_ECC}
FAKE_SECT = HBD=${NIMBUS_TARG_IMG_FAKE},WINK=${NIMBUS_LOCAL_SLW_IMG}

# To build fake PNOR, set FAKEPNOR to filename of file to build,
#    ie, 'export FAKEPNOR=fake8m.pnor'
# To not build fake PNOR, do not set FAKEPNOR or clear its setting,
#    ie, 'export FAKEPNOR='
.if(${FAKEPNOR} != "")
    FAKE_PNOR_IMG_INFO = \
        ${FAKEPNOR}:pnorLayoutFake.xml:${FAKE_SECT},${HOSTBOOT_FAKEPNOR_SECTIONS}
.endif

PNOR_IMG_INFO = \
   nimbus.pnor:defaultPnorLayout.xml:${NIMBUS_SECT},${HOSTBOOT_DEFAULT_SECTIONS} \
   ${FAKE_PNOR_IMG_INFO} \
   ${FIPS_PNOR_INFO}


__IMAGE_BUILD/% : .SPECTARG .PMAKE cp_hbfiles inject_ecc
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
	.if empty(FFSCMD)
		.if(${PNOR} == ${IMAGE_TARGET} || ${PNOR} == "" || \
                    ${FAKEPNOR} == ${IMAGE_TARGET})
			${PNOR_BUILD_SCRIPT} --pnorOutBin ${IMAGE_TARGET} \
				${TARGET_TEST:b--test} --pnorLayout ${IMAGE_LAYOUT} \
				${IMAGE_BIN_OPTION} --fpartCmd "fpart" --fcpCmd "fcp"
		.endif
	.else
		.if(${PNOR} == ${IMAGE_TARGET})
			${PNOR_BUILD_SCRIPT} --pnorOutBin ${IMAGE_TARGET} \
				${TARGET_TEST:b--test} --pnorLayout ${IMAGE_LAYOUT} \
				${IMAGE_BIN_OPTION} --ffsCmd "ffs"
		.endif
	.endif
.endif

build_pnor_images:.SPECTARG ${PNOR_IMG_INFO:S/^/__IMAGE_BUILD\//g}

clobber_build_pnor_images:
	${PNOR_IMG_INFO:@image@${pnorimg:!rm -f ${image:s/:/ /g:xs/ .*//};!e}@}

#################################################
#Special target to copy images to flash dir for simics
#################################################
FLASH_DEST = $(MAKETOP)$(OBJECTDIRTOP)../images/$(CONTEXT)/lab/flash
FLASH_IMG = ${BASE_IMAGE} ${BASE_ECC_IMAGE} ${HBBL_IMAGE}
FAKE_PNOR = fake6m.pnor

update_images_for_sandbox: inject_ecc build_sbe_partitions build_pnor_images
	mkdir -p ${FLASH_DEST}
	#Copy hostboot base image and bootloader image to flash dir
	${FLASH_IMG:@image@${baseimg:!cd ${FLASH_DEST}; cp -f ${.PATH:F${image}} ${image};!e}@}
	#Truncate fake pnor image down to 6MB and copy to flash dir
	${FAKE_PNOR_IMG_INFO:@image@${pnorimg:!dd if=${image:s/:/ /g:xs/ .*//} of=${FAKE_PNOR} bs=6M count=1; \
	    cp -f ${FAKE_PNOR} ${FLASH_DEST}/${FAKE_PNOR};!e}@}
	#Copy pnor images to flash dir
	${PNOR_IMG_INFO:@image@${pnorimg:!cd ${FLASH_DEST}; \
            if [ "${PNOR}" == "${image:s/:/ /g:xs/ .*//}" ] || \
               [ "${PNOR}" == "" ] || \
               [ "${FAKEPNOR}" == "${image:s/:/ /g:xs/ .*//}" ]; \
            then cp -f ${.PATH:F${image:s/:/ /g:xs/ .*//}} ${image:s/:/ /g:xs/ .*//}; fi !e}@}

.endif

