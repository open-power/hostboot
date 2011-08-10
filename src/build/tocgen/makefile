
#Temporary implementation to get a PNOR TOC created.  This will all change once the PNOR
#layout is finalized and we put together some real build tools.
#TODO: restructure to fit the usual makefile structure
ROOTPATH = ../../..

pnortoc: 
	${ROOTPATH}/src/build/tocgen/mkpnortoc.pl -i ${ROOTPATH}/src/build/tocgen/pnortoc.xml \
	    -o ${ROOTPATH}/img/pnor.toc	

all: gen_pass

code_pass: 

gen_pass: pnortoc

clean:

beam:

