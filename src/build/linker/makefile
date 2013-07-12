# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/linker/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2013
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
ROOTPATH = ../../..

CODE_PASS_POST += linker gensyms genlist
CLEAN_TARGETS += linker gensyms genlist

include $(ROOTPATH)/config.mk

linker: linker.C
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ -O3 -g linker.C -o linker \
				         -lbfd -liberty -lz

gensyms: gensyms.C
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ -O3 -g gensyms.C -o gensyms \
					 -lpthread

genlist: genlist.C
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ -O3 -g genlist.C -o genlist \
					 -lpthread
