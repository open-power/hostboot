ROOTPATH = ../../..
MODULE = hwpf

GENFILES = fapiHwpReturnCodes.H fapiAttributeIds.H

SUBDIRS = fapi.d hwp.d plat.d test.d

include ${ROOTPATH}/config.mk

${GENDIR}/fapiHwpReturnCodes.H : fapi/fapiParseErrorInfo.pl hwp/fapiHwpErrorInfo.xml
		$< ${GENDIR} $(filter-out $<,$^)

${GENDIR}/fapiAttributeIds.H : fapi/fapiParseAttributeInfo.pl hwp/fapiHwpAttributeInfo.xml 
		$< ${GENDIR} $(filter-out $<,$^)
