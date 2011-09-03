#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: config.mk $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2010 - 2011
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

all:
	${MAKE} gen_pass
	${MAKE} code_pass

ifdef MODULE
OBJDIR = ${ROOTPATH}/obj/modules/${MODULE}
BEAMDIR = ${ROOTPATH}/obj/beam/${MODULE}
GENDIR = ${ROOTPATH}/obj/genfiles
IMGDIR = ${ROOTPATH}/img
EXTRACOMMONFLAGS += -fPIC -Bsymbolic -Bsymbolic-functions 
ifdef STRICT
        EXTRACOMMONFLAGS += -Weffc++
endif
CUSTOMFLAGS += -D__HOSTBOOT_MODULE=${MODULE}
LIBS += $(addsuffix .so, $(addprefix lib, ${MODULE}))
MODULE_INIT = ${ROOTPATH}/obj/core/module_init.o
EXTRAINCDIR += ${ROOTPATH}/src/include/usr ${GENDIR}
else
OBJDIR = ${ROOTPATH}/obj/core
BEAMDIR = ${ROOTPATH}/obj/beam/core
GENDIR = ${ROOTPATH}/obj/genfiles
IMGDIR = ${ROOTPATH}/img
EXTRAINCDIR += ${GENDIR}
endif

ifdef HOSTBOOT_DEBUG
CUSTOMFLAGS += -DHOSTBOOT_DEBUG=1
endif

TRACEPP = ${ROOTPATH}/src/build/trace/tracepp
CUSTOM_LINKER_EXE = ${ROOTPATH}/src/build/linker/linker
CUSTOM_LINKER = i686-mcp6-jail ${CUSTOM_LINKER_EXE}

CC_RAW = ppc64-mcp6-gcc
CXX_RAW = ppc64-mcp6-g++
CC = ${TRACEPP} ${CC_RAW}
CXX = ${TRACEPP} ${CXX_RAW}
LD = ppc64-mcp6-ld
OBJDUMP = ppc64-mcp6-objdump
APYFIPSHDR = apyfipshdr
APYRUHHDR = apyruhhdr

BEAMVER = beam-3.5.2
BEAMPATH = /afs/rch/projects/esw/beam/${BEAMVER}
BEAMCMD = i686-mcp6-jail ${BEAMPATH}/bin/beam_compile
BEAMFLAGS = \
    --beam::source=${BEAMPATH}/tcl/beam_default_parms.tcl \
    --beam::source=${ROOTPATH}/src/build/beam/compiler_c_config.tcl \
    --beam::source=${ROOTPATH}/src/build/beam/compiler_cpp_config.tcl \
    --beam::exit0 \
    -o /dev/null

COMMONFLAGS = -O3 -nostdlib ${EXTRACOMMONFLAGS}
CFLAGS = ${COMMONFLAGS} -mcpu=power7 -nostdinc -g -mno-vsx -mno-altivec\
	 -Wall -Werror -fshort-enums ${CUSTOMFLAGS}
ASMFLAGS = ${COMMONFLAGS} -mcpu=power7
CXXFLAGS = ${CFLAGS} -nostdinc++ -fno-rtti -fno-exceptions -Wall
LDFLAGS = --nostdlib --sort-common ${COMMONFLAGS}

ifdef USE_PYTHON
    TESTGEN = ${ROOTPATH}/src/usr/cxxtest/cxxtestgen.py
else
    TESTGEN = ${ROOTPATH}/src/usr/cxxtest/cxxtestgen.pl
endif

ifdef TESTS
ifdef MODULE
OBJS += ${MODULE}.o
EXTRA_OBJS += ${OBJDIR}/${MODULE}.C
vpath %.C ${OBJDIR} $(shell mkdir -p ${OBJDIR})
else
$(error MODULE must be defined for a testcase.)
endif
endif


INCDIR = ${ROOTPATH}/src/include/
_INCDIRS = ${INCDIR} ${EXTRAINCDIR}
INCFLAGS = $(addprefix -I, ${_INCDIRS} )
ASMINCFLAGS = $(addprefix $(lastword -Wa,-I), ${_INCDIRS})

OBJECTS = $(addprefix ${OBJDIR}/, ${OBJS})
LIBRARIES = $(addprefix ${IMGDIR}/, ${LIBS})

ifdef IMGS
IMGS_ = $(addprefix ${IMGDIR}/, ${IMGS})
LIDS = $(foreach lid,$(addsuffix _LIDNUMBER, $(IMGS)),$(addprefix ${IMGDIR}/,$(addsuffix .ruhx, $($(lid)))))
IMAGES = $(addsuffix .bin, ${IMGS_}) $(addsuffix .elf, ${IMGS_}) ${LIDS}
#$(addsuffix .ruhx, ${IMGS_})
IMAGE_EXTRAS = $(addprefix ${IMGDIR}/, hbotStringFile)
endif

ifdef EXTRA_LIDS
EXTRA_LIDS_ = $(foreach lid,$(addsuffix _LIDNUMBER, $(EXTRA_LIDS)),$(addprefix ${IMGDIR}/,$(addsuffix .lidhdr, $($(lid)))))
endif

${OBJDIR}/%.o ${OBJDIR}/%.list : %.C
	mkdir -p ${OBJDIR}
	${CXX} -c ${CXXFLAGS} $< -o $@ ${INCFLAGS} -iquote .
	${OBJDUMP} -dCS $@ > $(basename $@).list	

${OBJDIR}/%.o ${OBJDIR}/%.list : %.c
	mkdir -p ${OBJDIR}
	${CC} -c ${CFLAGS} -std=c99 $< -o $@ ${INCFLAGS} -iquote .
	${OBJDUMP} -dCS $@ > $(basename $@).list

${OBJDIR}/%.o : %.S
	mkdir -p ${OBJDIR}
	${CC} -c ${ASMFLAGS} $< -o $@ ${ASMINCFLAGS} ${INCFLAGS} -iquote .

${OBJDIR}/%.dep : %.C
	mkdir -p ${OBJDIR}; \
	rm -f $@; \
	${CXX_RAW} -M ${CXXFLAGS} $< -o $@.$$$$ ${INCFLAGS} -iquote .; \
	sed 's,\($*\)\.o[ :]*,${OBJDIR}/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

${OBJDIR}/%.dep : %.c
	mkdir -p ${OBJDIR}; \
	rm -f $@; \
	${CC_RAW} -M ${CFLAGS} -std=c99 $< -o $@.$$$$ ${INCFLAGS} -iquote .; \
	sed 's,\($*\)\.o[ :]*,${OBJDIR}/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

${OBJDIR}/%.dep : %.S
	mkdir -p ${OBJDIR}; \
	rm -f $@; \
	${CC_RAW} -M ${ASMFLAGS} $< -o $@.$$$$ ${ASMINCFLAGS} ${INCFLAGS} -iquote .; \
	sed 's,\($*\)\.o[ :]*,${OBJDIR}/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

ifdef MODULE
${IMGDIR}/%.so : ${OBJECTS} ${ROOTPATH}/src/module.ld ${MODULE_INIT}
	${LD} -shared -z now ${LDFLAGS} \
	      $(filter-out ${ROOTPATH}/src/module.ld,$^) \
	      -T ${ROOTPATH}/src/module.ld -o $@
endif

ifdef TESTS
${OBJDIR}/${MODULE}.C: ${TESTS}
	mkdir -p ${OBJDIR}
	${TESTGEN} --hostboot -o $@ ${TESTS}
endif

define ELF_template
$${IMGDIR}/$(1).elf: $$(addprefix $${OBJDIR}/, $$($(1)_OBJECTS)) \
		    $${ROOTPATH}/src/kernel.ld
	$${LD} -static $${LDFLAGS} \
	      $$(addprefix $${OBJDIR}/,	$$($(1)_OBJECTS)) \
	      $$($(1)_LDFLAGS) -T $${ROOTPATH}/src/kernel.ld -o $$@
endef
$(foreach img,$(IMGS),$(eval $(call ELF_template,$(img))))

${IMGDIR}/%.bin ${IMGDIR}/%.list ${IMGDIR}/%.syms: ${IMGDIR}/%.elf \
    $(wildcard ${IMGDIR}/*.so) ${CUSTOM_LINKER_EXE}
	${CUSTOM_LINKER} $@ $< \
	      $(addprefix ${IMGDIR}/lib, $(addsuffix .so, $($*_MODULES))) \
		--extended=0x40000 ${IMGDIR}/$*_extended.bin \
	      $(addprefix ${IMGDIR}/lib, $(addsuffix .so, $($*_EXTENDED_MODULES))) \
	      > ${IMGDIR}/.$*.lnkout
	${ROOTPATH}/src/build/tools/addimgid $@ $<
	(cd ${ROOTPATH}; \
	    src/build/tools/gensyms $*.bin > ./img/$*.syms ; \
	    src/build/tools/genlist $*.bin > ./img/$*.list)


define RUHX_template
${IMGDIR}/$$($(1)_LIDNUMBER).ruhx: $${ROOTPATH}/src/build/lids/$(1).lidhdr \
				   $${IMGDIR}/$(1).bin
	$${APYFIPSHDR} -r $$< -l $${IMGDIR}/$(1).bin -o $${IMGDIR}/$(1).fips
	$${APYRUHHDR} -r $$< -l ${IMGDIR}/$(1).fips -o $${IMGDIR}/$$($(1)_LIDNUMBER).ruhx
	(rm -f $${IMGDIR}/$(1).fips)
	ln -sf $${IMGDIR}/$(1).bin $${IMGDIR}/$$($(1)_LIDNUMBER).lid
	ln -sf $${ROOTPATH}/src/build/lids/$(1).lidhdr $${IMGDIR}/$$($(1)_LIDNUMBER).lidhdr
endef
$(foreach img,$(IMGS),$(eval $(call RUHX_template,$(img))))

define LIDHDR_template
${IMGDIR}/$$($(1)_LIDNUMBER).lidhdr: $${ROOTPATH}/src/build/lids/$(1).lidhdr
	ln -sf $$^ $$@
endef
$(foreach lid,$(EXTRA_LIDS),$(eval $(call LIDHDR_template,$(lid))))

${IMGDIR}/hbotStringFile : ${IMAGES}
	${ROOTPATH}/src/build/trace/tracehash_hb.pl -c -d ${ROOTPATH}/obj -s $@

%.d: ${OBJECTS}
	cd ${basename $@} && ${MAKE} code_pass

%.gen_pass:
	cd ${basename $@} && ${MAKE} gen_pass

%.clean:
	cd ${basename $@} && ${MAKE} clean

%.beamdir:
	cd ${basename $@} && ${MAKE} beam

code_pass: ${OBJECTS} ${SUBDIRS} ${LIBRARIES} ${EXTRA_LIDS_} ${EXTRA_PARTS}
ifdef IMAGES
	${MAKE} ${IMAGES} ${IMAGE_EXTRAS}
endif

gen_pass:
	mkdir -p ${GENDIR}
	${MAKE} GEN_PASS

_GENFILES = $(addprefix ${GENDIR}/, ${GENFILES})
GEN_PASS: ${_GENFILES} ${SUBDIRS:.d=.gen_pass}

GENTARGET = $(addprefix %/, $(1))

${BEAMDIR}/%.beam : %.C
	mkdir -p ${BEAMDIR}
	${BEAMCMD} -I ${INCDIR} ${CXXFLAGS} ${BEAMFLAGS} $< \
	    --beam::complaint_file=$@ --beam::parser_file=/dev/null

${BEAMDIR}/%.beam : %.c
	mkdir -p ${BEAMDIR}
	${BEAMCMD} -I ${INCDIR} ${CXXFLAGS} ${BEAMFLAGS} $< \
	    --beam::complaint_file=$@ --beam::parser_file=/dev/null

${BEAMDIR}/%.beam : %.S
	echo Skipping ASM file.

BEAMOBJS = $(addprefix ${BEAMDIR}/, ${OBJS:.o=.beam})
beam: ${SUBDIRS:.d=.beamdir} ${BEAMOBJS}

clean: ${SUBDIRS:.d=.clean}
	(rm -f ${OBJECTS} ${OBJECTS:.o=.dep} ${OBJECTS:.o=.list} \
	       ${OBJECTS:.o=.o.hash} ${BEAMOBJS} ${LIBRARIES} \
	       ${IMAGES} ${IMAGES:.bin=.list} ${IMAGES:.bin=.syms} \
	       ${IMAGES:.bin=.bin.modinfo} ${IMAGES:.ruhx=.lid} \
	       ${IMAGES:.ruhx=.lidhdr} ${IMAGES:.bin=_extended.bin} \
	       ${IMAGE_EXTRAS} ${EXTRA_LIDS_} \
	       ${EXTRA_OBJS} ${_GENFILES})

cscope: code_pass
	mkdir -p ${ROOTPATH}/obj/cscope
	(cd ${ROOTPATH}/obj/cscope ; rm -f cscope.* ; \
	    find ../../ -name '*.[CHchS]' -type f -fprint cscope.files; \
	    cscope -bqk)

ctags: code_pass
	mkdir -p ${ROOTPATH}/obj/cscope
	(cd ${ROOTPATH}/obj/cscope ; rm -f tags ; \
	    ctags --recurse=yes --fields=+S ../../src)

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),gen_pass)
ifneq ($(MAKECMDGOALS),GEN_PASS)
    include $(OBJECTS:.o=.dep)
endif
endif
endif
