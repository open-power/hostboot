# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/hbfw/img/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2012,2014
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
BASE_IMAGE = hostboot.bin
EXT_IMAGE =  hostboot_extended.bin
HBRT_IMAGE = hostboot_runtime.bin
HBRT_SHA_IMAGE = hostboot_runtime.sha.bin
HBRT_HEADER_IMAGE = hostboot_runtime.header.bin
HBRT_ECC_HEADER_IMAGE = hostboot_runtime.header.bin.ecc
BASE_IMAGES = ${BASE_IMAGE} ${EXT_IMAGE} ${HBRT_IMAGE}
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
GUARD_ECC_IMAGE = guard.bin.ecc
GOLBAL_ECC_IMAGE = global.bin.ecc

ALL_HB_IMAGES = ${BASE_IMAGES} \
                ${BASE_W_HEADER_IMAGE} \
                ${BASE_ECC_IMAGE} ${EXT_ECC_IMAGE} \
                ${BASE_W_HEADER_ECC_IMAGE} ${BASE_SHA_IMAGE}\
                ${HBRT_SHA_IMAGE} \
                ${HBRT_HEADER_IMAGE} ${HBRT_ECC_HEADER_IMAGE} \
                ${EXT_PAD_IMAGE} \
                ${EXT_SHA_IMAGE} ${EXT_HEADER_IMAGE} \
                ${EXT_ECC_HEADER_IMAGE} \
                ${TESTDATA} ${TESTDATA_ECC}

cp_hbfiles: .SPECTARG
	${BASE_IMAGES:@image@cp -f -u ${SRCPATH:F${image}} ${image};@}
	echo "00000000001800000000000008000000000000000007EF80" | xxd -r -ps - sbe.header
	# add version header w/ sha hash
	echo -en VERSION\\0 > ${BASE_SHA_IMAGE}
	sha512sum ${BASE_IMAGE} | awk '{print $$1}' | xxd -pr -r >> ${BASE_SHA_IMAGE}
	dd if=${BASE_SHA_IMAGE} of=secureboot.header ibs=4k conv=sync
	dd if=/dev/zero of=hbb.footer bs=1 count=128K
	cat sbe.header secureboot.header ${BASE_IMAGE} hbb.footer > hostboot.stage.bin
	head -c 524288  hostboot.stage.bin > ${BASE_W_HEADER_IMAGE}
	currentsb -chain
	ecc --inject ${BASE_IMAGE} --output ${BASE_ECC_IMAGE} --p8
	ecc --inject ${BASE_W_HEADER_IMAGE} --output ${BASE_W_HEADER_ECC_IMAGE} --p8
	# dd command will pad image up to the next 4K page
	dd if=${EXT_IMAGE} of=${EXT_PAD_IMAGE} ibs=4k count=1280 conv=sync
	ecc --inject ${EXT_PAD_IMAGE} --output ${EXT_ECC_IMAGE} --p8
	# add version header w/ HBRT sha hash
	echo -en VERSION\\0 > ${HBRT_SHA_IMAGE}
	sha512sum ${HBRT_IMAGE} | awk '{print $$1}' | xxd -pr -r >> ${HBRT_SHA_IMAGE}
	dd if=${HBRT_SHA_IMAGE} of=${TEMP_IMAGE} ibs=4k conv=sync
	cat ${HBRT_IMAGE} >> ${TEMP_IMAGE}
	dd if=${TEMP_IMAGE} of=${HBRT_HEADER_IMAGE} ibs=4k conv=sync
	ecc --inject ${HBRT_HEADER_IMAGE} --output ${HBRT_ECC_HEADER_IMAGE} --p8
	# add version header w/ HBI sha hash
	echo -en VERSION\\0 > ${EXT_SHA_IMAGE}
	sha512sum ${EXT_IMAGE} | awk '{print $$1}' | xxd -pr -r >> ${EXT_SHA_IMAGE}
	dd if=${EXT_SHA_IMAGE} of=${TEMP_IMAGE} ibs=4k conv=sync
	cat ${EXT_IMAGE} >> ${TEMP_IMAGE}
	dd if=${TEMP_IMAGE} of=${EXT_HEADER_IMAGE} ibs=4k conv=sync
	ecc --inject ${EXT_HEADER_IMAGE} --output ${EXT_ECC_HEADER_IMAGE} --p8
	# create data for a test partition in pnor
	dd if=/dev/urandom of=${TESTDATA} bs=1 count=28K
	ecc --inject ${TESTDATA} --output ${TESTDATA_ECC} --p8
	# HBEL, GUARD, and GLOBAL ECC
	dd if=/dev/zero count=128K bs=1 | tr "\000" "\377" > ${TEMP_IMAGE}
	ecc --inject ${TEMP_IMAGE} --output ${HBEL_ECC_IMAGE} --p8
	dd if=/dev/zero count=16K bs=1 | tr "\000" "\377" > ${TEMP_IMAGE}
	ecc --inject ${TEMP_IMAGE} --output ${GUARD_ECC_IMAGE} --p8
	dd if=/dev/zero count=32K bs=1 | tr "\000" "\377" > ${TEMP_IMAGE}
	ecc --inject ${TEMP_IMAGE} --output ${GOLBAL_ECC_IMAGE} --p8
	rm ${TEMP_IMAGE}

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

S1_EC10_BIN = ${ENGD_OBJPATH:Fs1_10.sbe_seeprom.hdr.bin}
S1_EC12_BIN = ${ENGD_OBJPATH:Fs1_12.sbe_seeprom.hdr.bin}
S1_EC13_BIN = ${ENGD_OBJPATH:Fs1_13.sbe_seeprom.hdr.bin}
S1_EC20_BIN = ${ENGD_OBJPATH:Fs1_20.sbe_seeprom.hdr.bin}
P8_EC10_BIN = ${ENGD_OBJPATH:Fp8_10.sbe_seeprom.hdr.bin}
CENT_EC10_BIN = ${ENGD_OBJPATH:Fcentaur_10.sbe_seeprom.hdr.bin}
CENT_EC20_BIN = ${ENGD_OBJPATH:Fcentaur_20.sbe_seeprom.hdr.bin}

SBE_PART_INFO = \
  s1SbePartition.bin:10=${S1_EC10_BIN},12=${S1_EC12_BIN},13=${S1_EC13_BIN},20=${S1_EC20_BIN} \
  p8SbePartition.bin:10=${P8_EC10_BIN} \
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

#early hostboot use of this makefile will be against FSP drivers lacking fips_pnor.mk
#so need to use tryinclude for now.
.tryinclude <${.PATH:Ffips_pnor.mk}>

HOSTBOOT_DEFAULT_SECTIONS = HBB=${BASE_W_HEADER_ECC_IMAGE},HBI=${EXT_ECC_HEADER_IMAGE},HBRT=${HBRT_ECC_HEADER_IMAGE},TEST=${TESTDATA_ECC},HBEL=${HBEL_ECC_IMAGE},GUARD=${GUARD_ECC_IMAGE},GLOBAL=${GOLBAL_ECC_IMAGE}


HBFW_OBJPATH = ${.PATH:M*obj*}
ENGD_OBJPATH = ${HBFW_OBJPATH:S/hbfw\/img/engd\/href/g}
MURANO_TARG_IMG = simics_MURANO_targeting.bin
VENICE_TARG_IMG = simics_VENICE_targeting.bin
MURANO_SLW_IMG = ${ENGD_OBJPATH:Fs1.ref_image.bin}
VENICE_SLW_IMG = ${ENGD_OBJPATH:Fp8.ref_image.bin}
MURANO_LOCAL_SLW_IMG = s1.ref_image.bin
VENICE_LOCAL_SLW_IMG = p8.ref_image.bin
MURANO_SBE_IMG = s1SbePartition.bin
VENICE_SBE_IMG = p8SbePartition.bin
SBEC_IMG = centSbePartition.bin
TEMP_IMG = temp.bin

INPUT_ECC = ${${MURANO_TARG_IMG}:P} ${${VENICE_TARG_IMG}:P} \
		${MURANO_LOCAL_SLW_IMG} ${VENICE_LOCAL_SLW_IMG} \
		${MURANO_SBE_IMG} ${VENICE_SBE_IMG} \
		${SBEC_IMG}

inject_ecc: build_sbe_partitions
	# cp file with full path to one with local path
	cp ${MURANO_SLW_IMG} ${MURANO_LOCAL_SLW_IMG}
	cp ${VENICE_SLW_IMG} ${VENICE_LOCAL_SLW_IMG}
	for file in ${INPUT_ECC}; do\
		dd if=$$file of=${TEMP_IMG} ibs=4k conv=sync; \
		ecc --inject ${TEMP_IMG} --output $$file.ecc --p8; \
	done
	rm ${TEMP_IMG}

MURANO_SECT = HBD=${MURANO_TARG_IMG}.ecc,SBE=${MURANO_SBE_IMG}.ecc,SBEC=${SBEC_IMG}.ecc,WINK=${MURANO_LOCAL_SLW_IMG}.ecc
VENICE_SECT = HBD=${VENICE_TARG_IMG}.ecc,SBE=${VENICE_SBE_IMG}.ecc,SBEC=${SBEC_IMG}.ecc,WINK=${VENICE_LOCAL_SLW_IMG}.ecc

PNOR_IMG_INFO = \
   murano.pnor:defaultPnorLayout.xml:${MURANO_SECT},${HOSTBOOT_DEFAULT_SECTIONS} \
   venice.pnor:defaultPnorLayout.xml:${VENICE_SECT},${HOSTBOOT_DEFAULT_SECTIONS} \
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

FFSCMD = ${DUMMY:!which ffs 2>/dev/null!i}

${IMAGE_TARGET}: ${IMAGE_LAYOUT} ${IMAGE_BINS} ${PNOR_BUILD_SCRIPT}
	.if empty(FFSCMD)
		${PNOR_BUILD_SCRIPT} --pnorOutBin ${IMAGE_TARGET} \
			${TARGET_TEST:b--test} --pnorLayout ${IMAGE_LAYOUT} \
			${IMAGE_BIN_OPTION} --fpartCmd "fpart" --fcpCmd "fcp"
	.else
		${PNOR_BUILD_SCRIPT} --pnorOutBin ${IMAGE_TARGET} \
			${TARGET_TEST:b--test} --pnorLayout ${IMAGE_LAYOUT} \
			${IMAGE_BIN_OPTION} --ffsCmd "ffs"

	.endif

.endif

build_pnor_images:.SPECTARG ${PNOR_IMG_INFO:S/^/__IMAGE_BUILD\//g}

clobber_build_pnor_images:
	${PNOR_IMG_INFO:@image@${pnorimg:!rm -f ${image:s/:/ /g:xs/ .*//};!e}@}


#################################################
#Special target to copy images to flash dir for simics
#################################################
FLASH_DEST = $(MAKETOP)$(OBJECTDIRTOP)../images/$(CONTEXT)/lab/flash
FLASH_IMG = ${BASE_IMAGE} ${BASE_ECC_IMAGE}

update_images_for_sandbox: inject_ecc build_sbe_partitions build_pnor_images
	mkdir -p ${FLASH_DEST}
	#Copy hostboot base image to flash dir
	${FLASH_IMG:@image@${baseimg:!cd ${FLASH_DEST}; cp -f ${.PATH:F${image}} ${image};!e}@}
	#Copy pnor images to flash dir
	${PNOR_IMG_INFO:@image@${pnorimg:!cd ${FLASH_DEST}; cp -f ${.PATH:F${image:s/:/ /g:xs/ .*//}} ${image:s/:/ /g:xs/ .*//};!e}@}

.endif

