#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/ifcompiler/makefile $
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
# add a -d to flex for debug output
# ./bin/initCompiler -init ./sample.initfile -outdir . --debug -attr ./fapiAttributeIds.H

ROOTPATH = ../../..

y.tab.%: initCompiler.y
	yacc -d initCompiler.y

lex.yy.c: initCompiler.lex
	flex initCompiler.lex

bin/initCompiler: y.tab.c y.tab.h lex.yy.c initCompiler.C initCompiler.H initRpn.C initRpn.H initScom.C initScom.H initSymbols.C initSymbols.H
	mkdir -p bin; g++ initCompiler.C lex.yy.c y.tab.c initRpn.C initScom.C initSymbols.C -I ./ -I ${ROOTPATH}/src/include/usr/hwpf/hwp/ -o ./bin/initCompiler

ifcompiler: bin/initCompiler

all: gen_pass

code_pass: 

gen_pass: ifcompiler

clean:
	rm -f ./bin/initCompiler lex.yy.c y.tab.*
beam:

