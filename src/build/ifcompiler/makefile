# IBM_PROLOG_BEGIN_TAG 
# This is an automatically generated prolog. 
#  
# fips730 src/engd/initfiles/ifcompiler/makefile 1.5 
#  
# IBM CONFIDENTIAL 
#  
# OBJECT CODE ONLY SOURCE MATERIALS 
#  
# COPYRIGHT International Business Machines Corp. 2010 
# All Rights Reserved 
#  
# The source code for this program is not published or otherwise 
# divested of its trade secrets, irrespective of what has been 
# deposited with the U.S. Copyright Office. 
#  
# IBM_PROLOG_END_TAG 
#
# Flag  Reason   Userid    Date      Description
# ----  -------  --------  --------  -----------
#                andrewg   05/24/11  Updated for VPL/PgP
#

# To execute initCompiler against sample.initfile, run the following:
#  ./initCompiler -init ./sample.initfile -outdir . --debug -attr ./fapiAttributeIds.H
#
# sample.if will be the binary compiled initfile, used as input to the hardware procedure which
# process it.
#
# sample.if.list will be a listing file describing the binary content of the initfile

all:
	yacc -d initCompiler.y; flex -d initCompiler.lex; g++  initCompiler.C lex.yy.c y.tab.c initRpn.C initScom.C initSymbols.C -I./ -o initCompiler

clean:
	rm -f initCompiler lex.yy.c *.if *.list y.tab.*
