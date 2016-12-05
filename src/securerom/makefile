# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/securerom/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2017
# [+] International Business Machines Corp.
#
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
#
# IBM_PROLOG_END_TAG

bootrom := bootrom
bootrom_bin = $(bootrom).bin
bootrom_dis = $(bootrom).dis
#bootrom_srec = $(bootrom).srec

bootrom_vhdl = ../vhdl/tpc_secr_rom_pkg.vhdl

bootrom_nm = $(bootrom).nm

LDSCRIPT = bootrom.lds

HOSTTYPE ?= $(shell uname -p)
CELLSIZE ?= 64

ifeq ($(HOSTTYPE),powerpc)
CROSS	?= powerpc-ibm-aix6.1.0.0-
ONLY_CC	= $(CROSS)gcc -mpowerpc64 -maix64 -Wa,-mANY
ONLY_AS	= $(CROSS)as -m$(CELLSIZE)
ONLY_LD	= $(CROSS)ld -melf$(CELLSIZE)ppc
OBJCOPY	?= $(CROSS)objcopy
OBJDUMP	?= $(CROSS)objdump
else
CROSS	?= powerpc-linux-gnu-
ONLY_CC	= $(CROSS)gcc -m64 -Wa,-mregnames
ONLY_AS	= $(CROSS)as -m64 -mregnames
ONLY_LD	= $(CROSS)ld -melf64ppc
OBJCOPY	?= $(CROSS)objcopy
OBJDUMP	?= $(CROSS)objdump
endif


# Verbose level:
#   V=0 means completely silent
#   V=1 means brief output
#   V=2 means full verbose output
V ?= 2

ifeq ($(V),0)
Q := @
MAKEFLAGS += --silent
MAKE += -s
endif

ifeq ($(V),1)
MAKEFLAGS += --silent
MAKE	+= -s
CC	= printf "\t[CC]\t$@\n"; $(ONLY_CC)
AS	= printf "\t[AS]\t$@\n"; $(ONLY_AS)
LD	= printf "\t[LD]\t$@\n"; $(ONLY_LD)
CLEAN	= printf "\t[CLEAN]\t%s\n" "$(DIRECTORY)$$dir"
else
CC	= $(ONLY_CC)
AS	= $(ONLY_AS)
LD	= $(ONLY_LD)
CLEAN	= echo -n
endif

# need version >= 1_0_0
#OPENSSL ?= ~/openssl/openssl-1.0.0/bin/openssl
#SREC_CAT ?= srec_cat

CPPFLAGS += -DCONFIG_AWAN					\
	-I./src/ -I./include/					\
	-DCELLSIZE=$(CELLSIZE)					\
	-DBYTE_ORDER=BIG_ENDIAN					\
	-g										\

#CPPFLAGS += -DEC_POWER64_ASM
CPPFLAGS += -DBN_POWER64_MUL
CPPFLAGS += -DBN_POWER64_CMP
CPPFLAGS += -DBN_POWER64_CPY
CPPFLAGS += -DBN_POWER64_CLR
CPPFLAGS += -DEC_POWER64_RED
#CPPFLAGS += -DBN_POWER64_SQR
CPPFLAGS += -DEC_POWER64_ALG
#CPPFLAGS += -DBN_POWER64_DBG
CPPFLAGS += -DSHA512_FIX

OBJDIR = obj

ifeq ($(MAMBO),yes)
CPPFLAGS += -DCONFIG_MAMBO
bootrom := bootrom_4mambo
OBJDIR = mambo
endif

asm_srcs = src/branchtable.S
c_srcs   = src/ROM.c src/sha512.c src/ecverify.c
c_srcs  += src/memmove.c src/memcmp.c src/hw_utils.c
#c_srcs += src/memset.c src/memcpy.c

CPPFLAGS += -DCONFIG_SOFTWARE_CRYPTO

srcs = $(asm_srcs) $(c_srcs)
objs = $(subst src/,$(OBJDIR)/,$(asm_srcs:.S=.o) $(c_srcs:.c=.o))
deps = $(subst src/,$(OBJDIR)/,$(asm_srcs:.S=.d) $(c_srcs:.c=.d))

CFLAGS ?= -W -Os -fno-builtin -ffreestanding -nostdinc -mno-toc \
       -msoft-float -mno-altivec -mabi=no-altivec -Wall -mregnames \
        $(CPPFLAGS)

ASFLAGS += $(CPPFLAGS) -Wa,-mregnames -D__ASSEMBLER__

LDFLAGS = -nostdlib -N


default:
	$(MAKE) all
	$(MAKE) MAMBO=yes bootrom_4mambo.dis bootrom_4mambo.bin

$(OBJDIR):
	@if [ -d $(OBJDIR) ] ; then true; else mkdir -p $(OBJDIR); fi

all: $(bootrom_dis) $(bootrom_bin) $(bootrom_vhdl)


NODEPS = clean distclean binclean
ifeq (0, $(words $(findstring $(MAKECMDGOALS), $(NODEPS))))
-include $(deps)
endif


## This was to create a selfsigned rom code but now it is no longer selfsigned :

#ec_private_key.pem:
#	$(OPENSSL) ecparam -name secp521r1 -genkey -out ec_private_key.pem

#ec_private_key.pem: ec_private_key.pkcs8
#	$(OPENSSL) pkcs8 -inform DER -nocrypt -in ec_private_key.pkcs8 -out ec_private_key.pem
#ec_private_key.pkcs8:
#	./ecdsasig.x86 -r -g x > ec_private_key.pkcs8

#ec_public_key.der: ec_private_key.pem
#	$(OPENSSL) ec -in ec_private_key.pem -pubout -outform DER -out ec_public_key.der

#$(bootrom).stage1: $(objs) $(gen_hdrs) $(prism_hdrs) src/dummy_header.o src/dummy_hash.o
#	$(LD) $(LDFLAGS) -o $@ $(objs) src/dummy_header.o src/dummy_hash.o

#$(bootrom).signed.bin:  $(bootrom).stage1
#	$(OBJCOPY) -j .text -j .data -O binary $^ $@

#dummy_header.bin:  $(bootrom).stage1
#	$(OBJCOPY) -j .image_header -O binary $^ $@

#$(bootrom).signed.sig: $(bootrom).signed.bin ec_private_key.pem
#	$(OPENSSL) dgst -sign ec_private_key.pem -sha512 $^ > $@

#image_header.bin: ec_public_key.der $(bootrom).signed.sig src/dummy_header.o dummy_header.bin
#	./asn1extract_pubkey.pl ec_public_key.der > image_header.bin
#	dd bs=132 count=2 if=/dev/zero >> image_header.bin
#	./asn1extract.pl bootrom.signed.sig | xxd -r -p >> image_header.bin
#	dd bs=132 count=2 if=/dev/zero >> image_header.bin
#	dd bs=1 skip=792 count=88 if=dummy_header.bin >> image_header.bin

#image_header.o: image_header.bin
#	$(OBJCOPY) -I binary -O elf64-powerpc -B powerpc --rename-section .data=.image_header --redefine-sym _binary_image_header_bin_start=rom_image_header  image_header.bin image_header.o

#$(bootrom).stage2: $(objs) $(gen_hdrs) $(prism_hdrs) image_header.o src/dummy_hash.o
#	$(LD) $(LDFLAGS) -o $@ $(objs) image_header.o src/dummy_hash.o

#bootrom.hashed.bin:  $(bootrom).stage2
#	$(OBJCOPY) -j .image_hash -j .text -j .data -O binary $^ $@

#bootrom.hashed.hash: bootrom.hashed.bin
#	$(OPENSSL) dgst -sha512 bootrom.hashed.bin | sed -e "s/.* //" | xxd -r -p > bootrom.hashed.hash

#rom_hash.o: bootrom.hashed.hash
#	$(OBJCOPY) -I binary -O elf64-powerpc -B powerpc \
#	  --rename-section .data=.rom_hash \
#	  --redefine-sym _binary_bootrom_hashed_hash_start=rom_hash \
#	  bootrom.hashed.hash rom_hash.o

#$(bootrom): $(objs) $(gen_hdrs) $(prism_hdrs) image_header.o rom_hash.o
#	$(LD) $(LDFLAGS) -o $@ $(objs) image_header.o rom_hash.o

$(bootrom): $(objs) $(LDSCRIPT)
	$(LD) $(LDFLAGS) -T$(LDSCRIPT) -o $@ $(objs)

$(bootrom_dis): $(bootrom)
	$(OBJDUMP) -j .branchtable -j .text -j .data -j .toc --source $^ > $@

#$(bootrom_srec): $(bootrom)
#	$(OBJCOPY) --change-addresses -0xff80000 $^ -O srec $@

$(bootrom_bin): $(bootrom)
	$(OBJCOPY) -j .branchtable -j .text -j .data -j .toc -O binary $^ $@

$(bootrom_vhdl): $(bootrom_bin) convVhdl.pl
	./convVhdl.pl $^ > $@

$(OBJDIR)/%.o: src/%.S $(OBJDIR)/%.d
	$(CC) $(ASFLAGS) -c $< -o $@

$(OBJDIR)/%.o: src/%.c $(OBJDIR)/%.d
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.d: src/%.S Makefile $(OBJDIR)
	$(CC) -MM $(ASFLAGS) $< | sed 's,\(\S*\)\.o[ :]*,$(OBJDIR)/\1.o $(OBJDIR)/\1.d : ,g' > $@

$(OBJDIR)/%.d: src/%.c Makefile $(OBJDIR)
	$(CC) -MM $(CFLAGS) $< | sed 's,\(\S*\)\.o[ :]*,$(OBJDIR)/\1.o $(OBJDIR)/\1.d : ,g' > $@

#ecdsa: src/ecdsa.c src/ecverify.c
#	gcc -W -Os -fno-builtin -ffreestanding -nostdinc -msoft-float -mno-altivec -mabi=no-altivec -Wall -I./src/ -I./include/ -o ecdsa src/ecdsa.c src/ecverify.c

clean:
	$(RM) -r *~ obj mambo
#		ec_public_key.der \
#		$(bootrom).stage1 $(bootrom).signed.bin $(bootrom).signed.sig dummy_header.bin image_header.bin image_header.o\
#		$(bootrom).stage2 $(bootrom).hashed.bin $(bootrom).hashed.hash rom_hash.o

distclean: clean
	@$(MAKE) binclean
	@$(MAKE) MAMBO=yes binclean

binclean:
	$(RM) $(bootrom) $(bootrom_bin) $(bootrom_dis)

.PHONY: default all clean distclean binclean
