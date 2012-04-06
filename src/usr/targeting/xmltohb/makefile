#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/targeting/makefile $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011
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
#  IBM_PROLOG_END

ROOTPATH = ../../../..

XMLTOHB_HEADER_TARGETS =    \
    attributeenums.H        \
    attributestrings.H      \
    attributetraits.H       \
    attributestructs.H      \
    pnortargeting.H         \
    fapiplatattrmacros.H

XMLTOHB_SOURCE_TARGETS =    \
    attributedump.C         \
    attributestrings.C  

XMLTOHB_SYSTEM_BINARIES = \
   vbu_targeting.bin \
   simics_VENICE_targeting.bin \
   simics_MURANO_targeting.bin \
   TULETA_targeting.bin

XMLTOHB_TARGETS = \
    ${XMLTOHB_HEADER_TARGETS} \
    ${XMLTOHB_SOURCE_TARGETS} 

XMLTOHB_GENERIC_SOURCES = attribute_types.xml target_types.xml

XMLTOHB_FAPIATTR_SOURCES = \
    ${ROOTPATH}/src/usr/hwpf/hwp/memory_attributes.xml \
    ${ROOTPATH}/src/usr/hwpf/hwp/L2_L3_attributes.xml \
    ${ROOTPATH}/src/usr/hwpf/hwp/scratch_attributes.xml \
    ${ROOTPATH}/src/usr/hwpf/hwp/system_attributes.xml \
    ${ROOTPATH}/src/usr/hwpf/hwp/chip_attributes.xml \
    ${ROOTPATH}/src/usr/hwpf/hwp/dimm_spd_attributes.xml \
    ${ROOTPATH}/src/usr/hwpf/hwp/dimm_attributes.xml \
    ${ROOTPATH}/src/usr/hwpf/hwp/unit_attributes.xml \
    ${ROOTPATH}/src/usr/hwpf/hwp/freq_attributes.xml \
    ${ROOTPATH}/src/usr/hwpf/hwp/proc_mvpd_attributes.xml

VMM_CONSTS_FILE = \
    ${ROOTPATH}/src/include/usr/vmmconst.h

GENFILES = ${XMLTOHB_TARGETS} 

EXTRA_PARTS = $(addprefix $(IMGDIR)/, $(XMLTOHB_SYSTEM_BINARIES))

EXTRA_CLEAN = $(addprefix $(GENDIR)/, ${XMLTOHB_SYSTEM_BINARIES}) \
	      $(addprefix $(GENDIR)/, ${XMLTOHB_SYSTEM_BINARIES:.bin=.xml}) \
              ${GENDIR}/generic.xml ${GENDIR}/fapiattrs.xml

include ${ROOTPATH}/config.mk

# Delete any generated file on error 
.DELETE_ON_ERROR:

${EXTRA_PARTS}: ${IMGDIR}/% : ${GENDIR}/%
	cp -f $^ $@

# generic XML is created from the generic sources only
${GENDIR}/generic.xml: ${XMLTOHB_GENERIC_SOURCES}
	./mergexml.sh $^ > $@

# merge all FAPI attribute files into one
${GENDIR}/fapiattrs.xml: ${XMLTOHB_FAPIATTR_SOURCES}
	./mergexml.sh $^ > $@

# create the header files, only needs generic xml
$(call GENTARGET,$(XMLTOHB_TARGETS)) : \
		xmltohb.pl ${GENDIR}/generic.xml ${GENDIR}/fapiattrs.xml
	./$< $(addprefix --hb-xml-file=,${GENDIR}/generic.xml) \
	     $(addprefix --fapi-attributes-xml-file=,${GENDIR}/fapiattrs.xml) \
	     --src-output-dir=$(dir $@) --img-output-dir=none \
	     --img-output-file=none

# system-specific XML needs the generic plus the xxx.system.xml file + the
# MRW file
${GENDIR}/%.hb.xml: %.system.xml ${XMLTOHB_GENERIC_SOURCES} %.mrw.xml
	./mergexml.sh $^ > $@

# create the binary files
${GENDIR}/%_targeting.bin: xmltohb.pl ${GENDIR}/%.hb.xml ${GENDIR}/fapiattrs.xml ${VMM_CONSTS_FILE}
	./$< $(addprefix --hb-xml-file=,${GENDIR}/$*.hb.xml) \
	     $(addprefix --fapi-attributes-xml-file=,${GENDIR}/fapiattrs.xml) \
	     --src-output-dir=none --img-output-dir=$(dir $@) \
	     --img-output-file=$(notdir $@) \
         --vmm-consts-file=$(VMM_CONSTS_FILE)

