# makefile for errlparser,
# a 32-bit x86 linux binary suitable for running on GFW pool machines. 


ROOTPATH=../../../..

CC=g++ -m32
CFLAGS:=-g -O0   -I $(ROOTPATH)/src/include/usr 
BIN:=bin


all: code_pass

gen_pass:

code_pass: bindir $(BIN)/errlparser 

clean:
	rm -fr $(BIN)

beam: 

bindir: 
	mkdir -p $(BIN) 	

$(BIN)/comps.C: $(ROOTPATH)/src/include/usr/hbotcompid.H   readcomps.rex
	rexx readcomps.rex $(ROOTPATH)/src/include/usr/hbotcompid.H  >$(BIN)/comps.C

$(BIN)/errlparser.o: errlparser.C   $(ROOTPATH)/src/include/usr/errl/errltypes.H $(BIN)/comps.C
	$(CC) -c  $(CFLAGS) -I bin  -o $(BIN)/errlparser.o  errlparser.C

$(BIN)/errlparser: $(BIN)/errlparser.o
	$(CC) -o  $(BIN)/errlparser  $(BIN)/errlparser.o 


