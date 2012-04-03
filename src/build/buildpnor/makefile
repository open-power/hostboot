#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/buildpnor/makefile $
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
#  IBM_PROLOG_END
#Build PNOR Images for each platform.
#Also builds images which contain the test code.
ROOTPATH = ../../..

PNOR_TARGETS = simics_MURANO simics_VENICE vbu

define PNOR_template
$${IMGDIR}/$(1).pnor: $${IMGDIR}/hbicore_extended.bin $${IMGDIR}/$(1)_targeting.bin
	./buildpnor.pl --pnorLayout ./pnorLayout.xml \
	    --genToc \
	    --pnorOutBin $${IMGDIR}/$(1).pnor \
	    --binFile_TOC $${IMGDIR}/$(1)_pnor.toc \
	    --binFile_HBI $${IMGDIR}/hbicore_extended.bin \
	    --binFile_HBD $${IMGDIR}/$(1)_targeting.bin
endef
define PNOR_test_template
$${IMGDIR}/$(1)_test.pnor: $${IMGDIR}/hbicore_extended.bin $${IMGDIR}/$(1)_targeting.bin
	./buildpnor.pl --pnorLayout ./pnorLayout.xml \
	    --genToc \
	    --pnorOutBin $${IMGDIR}/$(1)_test.pnor \
	    --binFile_TOC $${IMGDIR}/$(1)_pnor.toc \
	    --binFile_HBI $${IMGDIR}/hbicore_test_extended.bin \
	    --binFile_HBD $${IMGDIR}/$(1)_targeting.bin
endef

PNOR_IMAGES = $(addsuffix .pnor, $(addprefix $(IMGDIR)/, ${PNOR_TARGETS})) \
              $(addsuffix _test.pnor, $(addprefix $(IMGDIR)/, ${PNOR_TARGETS}))

EXTRA_CLEAN = ${PNOR_IMAGES} ${PNOR_IMAGES:.pnor=_pnor.toc}

include ${ROOTPATH}/config.mk

buildpnor: ${PNOR_IMAGES}

$(foreach pnor,$(PNOR_TARGETS),$(eval $(call PNOR_template,$(pnor))))
$(foreach pnor,$(PNOR_TARGETS),$(eval $(call PNOR_test_template,$(pnor))))
