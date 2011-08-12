ROOTPATH = ../../..
MODULE = hwpf

GENFILES = gen_errfiles fapiAttributeIds.H

SUBDIRS = fapi.d hwp.d plat.d test.d

include ${ROOTPATH}/config.mk

# fapiParseErrorInfo.pl produces multiple output files. Use a dummy target to
# create a single rule to create all files so that the script is only run once
# (instead of once for each output file which could fail in a parallel build).
# The disadvantage is that the script is always run, even if there are no
# updates, but it is safe and there is no easy solution
${GENDIR}/gen_errfiles : fapi/fapiParseErrorInfo.pl hwp/fapiHwpErrorInfo.xml
	$< ${GENDIR} $(filter-out $<,$^)

# fapiParseAttributeInfo.pl produces a single output file so a standard rule
# will work
${GENDIR}/fapiAttributeIds.H : fapi/fapiParseAttributeInfo.pl hwp/fapiHwpAttributeInfo.xml 
	$< ${GENDIR} $(filter-out $<,$^)
