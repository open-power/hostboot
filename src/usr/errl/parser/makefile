# makefile for errlparser,
# a 32-bit x86 linux binary suitable for running on GFW pool machines. 


ROOTPATH=../../../..

CC=g++ -m32
CFLAGS:=-g -O0   -I $(ROOTPATH)/src/include/usr 
BIN:=bin


all: code_pass

gen_pass:

code_pass: $(BIN)/errlparser 

clean:
	rm -fr $(BIN)

beam: 

$(BIN)/comps.C: $(ROOTPATH)/src/include/usr/hbotcompid.H
	mkdir -p $(BIN)
	grep "const compId_t [A-Z0-9]*_COMP_ID" $^ | \
	grep -v MY_COMP_ID | \
	sed 's/const compId_t \([A-Z0-9]*\)_COMP_ID[ =\t]*\(0[xX][0-9a-fA-F]*\).*/{ "\1", \2 },/' \
	> $@

$(BIN)/errlparser.o: errlparser.C $(ROOTPATH)/src/include/usr/errl/errltypes.H $(BIN)/comps.C
	mkdir -p $(BIN)
	$(CC) -c  $(CFLAGS) -I bin -o $@  $<

$(BIN)/errlparser: $(BIN)/errlparser.o
	$(CC) -o  $@ $<


