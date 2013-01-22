# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: config.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2010,2013
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
all:
	${MAKE} gen_pass
	${MAKE} code_pass

## output libs, objs for userdetails parsers
UD_DIR = ${ROOTPATH}/obj/modules/userdetails
UD_OBJS = ${UD_DIR}*.o ${UD_DIR}/*.so ${UD_DIR}/*.a

ifdef MODULE
OBJDIR = ${ROOTPATH}/obj/modules/${MODULE}
BEAMDIR = ${ROOTPATH}/obj/beam/${MODULE}
GENDIR = ${ROOTPATH}/obj/genfiles
GENDIR_PLUGINS = ${ROOTPATH}/obj/genfiles/plugins
IMGDIR = ${ROOTPATH}/img
GCOVNAME = ${MODULE}.lcov
EXTRACOMMONFLAGS += -fPIC -Bsymbolic -Bsymbolic-functions 
ifdef STRICT
        EXTRACOMMONFLAGS += -Weffc++
endif
CUSTOMFLAGS += -D__HOSTBOOT_MODULE=${MODULE}
ifndef TESTS
ifdef HOSTBOOT_PROFILE
vpath %.C ${ROOTPATH}/src/sys/prof
OBJS := gcov.o ${OBJS}
endif
endif
LIBS += $(addsuffix .so, $(addprefix lib, ${MODULE}))
MODULE_INIT = ${ROOTPATH}/obj/core/module_init.o
EXTRAINCDIR += ${ROOTPATH}/src/include/usr ${GENDIR}
else
OBJDIR = ${ROOTPATH}/obj/core
BEAMDIR = ${ROOTPATH}/obj/beam/core
GENDIR = ${ROOTPATH}/obj/genfiles
GENDIR_PLUGINS = ${ROOTPATH}/obj/genfiles/plugins
IMGDIR = ${ROOTPATH}/img
EXTRAINCDIR += ${GENDIR}
GCOVNAME = $(notdir $(shell pwd)).lcov
endif
GCOVDIR = ${ROOTPATH}/obj/gcov

__internal__comma= ,
__internal__empty=
__internal__space=$(__internal__empty) $(__internal__empty)
MAKE_SPACE_LIST = $(subst $(__internal__comma),$(__internal__space),$(1))

ifdef HOSTBOOT_DEBUG
ifeq ($(HOSTBOOT_DEBUG),1)
    CUSTOMFLAGS += -DHOSTBOOT_DEBUG=1
else
ifndef MODULE
ifneq (,$(filter kernel,$(call MAKE_SPACE_LIST, $(HOSTBOOT_DEBUG))))
    CUSTOMFLAGS += -DHOSTBOOT_DEBUG=kernel
endif
else
ifneq (,$(filter $(MODULE), $(call MAKE_SPACE_LIST, $(HOSTBOOT_DEBUG))))
    CUSTOMFLAGS += -DHOSTBOOT_DEBUG=$(MODULE)
endif
endif
endif
endif

ifndef TESTS
ifdef HOSTBOOT_PROFILE
ifndef HOSTBOOT_PROFILE_NO_INSTRUMENT
CUSTOMFLAGS += --coverage
endif
endif
endif

# Current MCP version
MCP_VER = mcp6

TRACEPP = ${ROOTPATH}/src/build/trace/tracepp
CUSTOM_LINKER_EXE = ${ROOTPATH}/src/build/linker/linker
CUSTOM_LINKER = i686-mcp6-jail ${CUSTOM_LINKER_EXE}

CC_RAW = ppc64-mcp6-gcc -std=c99
CXX_RAW = ppc64-mcp6-g++
CC = ${TRACEPP} ${CC_RAW}
CXX = ${TRACEPP} ${CXX_RAW}

LD = ppc64-mcp6-ld
OBJDUMP = ppc64-mcp6-objdump
GCOV = ppc64-mcp6-gcov
APYFIPSHDR = apyfipshdr
APYRUHHDR = apyruhhdr

BINFILE_CACHE_LOCALDIR = ${ROOTPATH}/.git/hb_cache/data/
BINFILE_CACHE_REMOTEDIR = /gsa/ausgsa/projects/h/hostboot/.binary_cache/data/

BEAMVER = beam-3.5.2
BEAMPATH = /afs/rch/projects/esw/beam/${BEAMVER}
BEAMCMD = i686-mcp6-jail ${BEAMPATH}/bin/beam_compile
BEAMFLAGS = \
    --beam::source=${BEAMPATH}/tcl/beam_default_parms.tcl \
    --beam::source=${ROOTPATH}/src/build/beam/compiler_c_config.tcl \
    --beam::source=${ROOTPATH}/src/build/beam/compiler_cpp_config.tcl \
    --beam::exit0 \
    -o /dev/null

ifdef HOSTBOOT_PROFILE
COMMONFLAGS = -Os 
else
COMMONFLAGS = -O3
endif
COMMONFLAGS += -nostdlib ${EXTRACOMMONFLAGS}
CFLAGS = ${COMMONFLAGS} -mcpu=power7 -nostdinc -g -mno-vsx -mno-altivec\
	 -Wall -Werror -mtraceback=no ${CUSTOMFLAGS}
ASMFLAGS = ${COMMONFLAGS} -mcpu=power7
CXXFLAGS = ${CFLAGS} -nostdinc++ -fno-rtti -fno-exceptions -Wall
LDFLAGS = --nostdlib --sort-common ${COMMONFLAGS}

ifdef HOSTBOOT_PROFILE
    PROFILE_FLAGS_FILTER = $(if $(findstring gcov,$(2)),\
				$(filter-out --coverage,$(1)),\
				$(1))
else
    PROFILE_FLAGS_FILTER = $(1)
endif

FLAGS_FILTER = $(call PROFILE_FLAGS_FILTER, $(1), $(2))

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
	${CXX} -c $(call FLAGS_FILTER, ${CXXFLAGS}, $<) $< \
	       -o $@ ${INCFLAGS} -iquote .
	${OBJDUMP} -rdlCS $@ > $(basename $@).list	

# Compiling *.cc files
${OBJDIR}/%.o ${OBJDIR}/%.list : %.cc
	mkdir -p ${OBJDIR}
	${CXX} -c ${CXXFLAGS} $< -o $@ ${INCFLAGS} -iquote .
	${OBJDUMP} -rdlCS $@ > $(basename $@).list	

${OBJDIR}/%.o ${OBJDIR}/%.list : %.c
	mkdir -p ${OBJDIR}
    # Override to use C++ compiler in place of C compiler
    # CC_OVERRIDE is set in the makefile of the component
ifndef CC_OVERRIDE
	${CC} -c $(call FLAGS_FILTER, ${CFLAGS}, $<) $< \
	      -o $@ ${INCFLAGS} -iquote .
else
	${CXX} -c $(call FLAGS_FILTER, ${CXXFLAGS}, $<) $< \
	      -o $@ ${INCFLAGS} -iquote .
endif
	${OBJDUMP} -rdlCS $@ > $(basename $@).list

${OBJDIR}/%.o : %.S
	mkdir -p ${OBJDIR}
	${CC} -c ${ASMFLAGS} $< -o $@ ${ASMINCFLAGS} ${INCFLAGS} -iquote .

${OBJDIR}/%.dep : %.C
	mkdir -p ${OBJDIR}; \
	rm -f $@; \
	${CXX_RAW} -M $(call FLAGS_FILTER, ${CXXFLAGS}, $<) $< \
	           -o $@.$$$$ ${INCFLAGS} -iquote .; \
	sed 's,\($*\)\.o[ :]*,${OBJDIR}/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

${OBJDIR}/%.dep : %.cc
	mkdir -p ${OBJDIR}; \
	rm -f $@; \
	${CXX_RAW} -M ${CXXFLAGS} $< -o $@.$$$$ ${INCFLAGS} -iquote .; \
	sed 's,\($*\)\.o[ :]*,${OBJDIR}/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

${OBJDIR}/%.dep : %.c
	mkdir -p ${OBJDIR}; \
	rm -f $@; \
	${CC_RAW} -M $(call FLAGS_FILTER, ${CFLAGS}, $<) $< \
		  -o $@.$$$$ ${INCFLAGS} -iquote .; \
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

# Rules for BINARY_FILES directive.
#
#    The BINARY_FILES directives are used to include files out of the binary
#    files cache (see 'hb cacheadd' command).  This cache exists to keep
#    binary files outside of git, because they take a larger space in the git
#    database, especially if they change frequently.
#
#    The BINARY_FILES variable is a set of <destination>:<hash_value> pairs.
#    The destination is where the make system should put the file.  The hash
#    value tells which version of a file to use and it comes from the 
#    'hb cacheadd' tool when a version of the file is added to the binary
#    files cache.
#
define __BINARY_CACHE_FILE
_BINARYFILES += $(1)

ifneq "$(wildcard $(addprefix ${BINFILE_CACHE_LOCALDIR},$(2)))" ""
$(1) : $(addprefix $${BINFILE_CACHE_LOCALDIR},$(2))
	echo "$(2) $$<" | sha1sum --check
	cp $$< $$@
else
$(1) : $(addprefix $${BINFILE_CACHE_REMOTEDIR},$(2))
	echo "$(2) $$<" | sha1sum --check
	cp $$< $$@
endif
endef
ifdef BINARY_FILES
$(foreach file,$(BINARY_FILES), \
	  $(eval $(call __BINARY_CACHE_FILE, \
			    $(firstword $(subst :, ,$(file))), \
			    $(lastword $(subst :, ,$(file))) \
	  )) \
)
endif
# end BINARY_FILES rules.

define ELF_template
$${IMGDIR}/$(1).elf: $$(addprefix $${OBJDIR}/, $$($(1)_OBJECTS)) \
		    $${ROOTPATH}/src/kernel.ld
	$${LD} -static $${LDFLAGS} \
	      $$(addprefix $${OBJDIR}/,	$$($(1)_OBJECTS)) \
	      $$($(1)_LDFLAGS) -T $${ROOTPATH}/src/kernel.ld -o $$@
endef
$(foreach img,$(IMGS),$(eval $(call ELF_template,$(img))))

${IMGDIR}/%.bin ${IMGDIR}/%.list ${IMGDIR}/%.syms: ${IMGDIR}/%.elf \
    $(wildcard ${IMGDIR}/*.so) $(addprefix ${IMGDIR}/, $($*_DATA_MODULES)) \
    ${CUSTOM_LINKER_EXE}
	${CUSTOM_LINKER} $@ $< \
	      $(addprefix ${IMGDIR}/lib, $(addsuffix .so, $($*_MODULES))) \
		--extended=0x40000 ${IMGDIR}/$*_extended.bin \
	      $(addprefix ${IMGDIR}/lib, $(addsuffix .so, $($*_EXTENDED_MODULES))) \
	      $(addprefix ${IMGDIR}/, $($*_DATA_MODULES)) \
	      > ${IMGDIR}/.$*.lnkout
	${ROOTPATH}/src/build/tools/addimgid $@ $<
	(cd ${ROOTPATH}; \
	    src/build/tools/gensyms $*.bin $*_extended.bin 0x40000000 > ./img/$*.syms ; \
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

${GENDIR}/hwp_id.html : ${SUBDIRS}
	${ROOTPATH}/src/build/tools/hwp_id.pl -i -l > $@

%.d: ${OBJECTS}
	cd ${basename $@} && ${MAKE} code_pass

%.gen_pass:
	cd ${basename $@} && ${MAKE} gen_pass

%.gcov_pass:
	cd ${basename $@} && ${MAKE} gcov_pass -ik

%.clean:
	cd ${basename $@} && ${MAKE} clean

%.beamdir:
	cd ${basename $@} && ${MAKE} beam

code_pass: ${OBJECTS} ${SUBDIRS} ${LIBRARIES} ${EXTRA_LIDS_} ${EXTRA_PARTS}
ifdef IMAGES
	${MAKE} ${IMAGES} ${IMAGE_EXTRAS} ${IMAGE_EXTRA_TARGETS}
endif

gen_pass:
	mkdir -p ${GENDIR}
	mkdir -p ${GENDIR_PLUGINS}
	${MAKE} GEN_PASS

_GENFILES = $(addprefix ${GENDIR}/, $(GENFILES))
_GENFILES += $(addprefix ${GENDIR_PLUGINS}/, $(GENFILES_PLUGINS))
GEN_PASS: $(_GENFILES) $(_BINARYFILES) ${SUBDIRS:.d=.gen_pass}

GENTARGET = $(addprefix %/, $(1))

${BEAMDIR}/%.beam : %.C
	mkdir -p ${BEAMDIR}
	${BEAMCMD} -I ${INCDIR} ${CXXFLAGS} ${BEAMFLAGS} $< \
	    --beam::complaint_file=$@ --beam::parser_file=/dev/null

${BEAMDIR}/%.beam : %.cc
	mkdir -p ${BEAMDIR}
	${BEAMCMD} -I ${INCDIR} ${CXXFLAGS} ${BEAMFLAGS} $< \
	    --beam::complaint_file=$@ --beam::parser_file=/dev/null

${BEAMDIR}/%.beam : %.c
	mkdir -p ${BEAMDIR}
	${BEAMCMD} -I ${INCDIR} ${CFLAGS} ${BEAMFLAGS} $< \
	    --beam::complaint_file=$@ --beam::parser_file=/dev/null

${BEAMDIR}/%.beam : %.S
	echo Skipping ASM file.

BEAMOBJS = $(addprefix ${BEAMDIR}/, ${OBJS:.o=.beam})
beam: ${SUBDIRS:.d=.beamdir} ${BEAMOBJS}

gcov_pass:
	mkdir -p ${GCOVDIR}
	${MAKE} GCOV_PASS

GCOV_PASS: ${SUBDIRS:.d=.gcov_pass}
ifdef OBJS
	cp ${OBJECTS:.o=.gcno} ${OBJECTS:.o=.gcda} .
	lcov --directory . -c -o ${GCOVDIR}/${GCOVNAME} \
	     --gcov-tool ${GCOV} --ignore-errors source
	rm ${OBJS:.o=.gcno} ${OBJS:.o=.gcda} -f
endif

cleanud :
	rm -f ${UD_OBJS}

clean: cleanud ${SUBDIRS:.d=.clean}
	(rm -f ${OBJECTS} ${OBJECTS:.o=.dep} ${OBJECTS:.o=.list} \
	       ${OBJECTS:.o=.o.hash} ${OBJECTS:.o=.gcno} ${OBJECTS:.o=.gcda} \
	       ${BEAMOBJS} ${LIBRARIES} \
	       ${IMAGES} ${IMAGES:.bin=.list} ${IMAGES:.bin=.syms} \
	       ${IMAGES:.bin=.bin.modinfo} ${IMAGES:.ruhx=.lid} \
	       ${IMAGES:.ruhx=.lidhdr} ${IMAGES:.bin=_extended.bin} \
	       ${IMAGE_EXTRAS} ${EXTRA_LIDS_} \
	       ${EXTRA_OBJS} ${_GENFILES} ${_BINARYFILES} ${EXTRA_PARTS} ${EXTRA_CLEAN} )

cscope: ${SUBDIRS}
	mkdir -p ${ROOTPATH}/obj/cscope
	(cd ${ROOTPATH}/obj/cscope ; rm -f cscope.* ; \
	    find ../../ -name '*.[CHchS]' -type f -fprint cscope.files; \
	    cscope -bqk)

ctags: ${SUBDIRS}
	mkdir -p ${ROOTPATH}/obj/cscope
	(cd ${ROOTPATH}/obj/cscope ; rm -f tags ; \
	    ctags --recurse=yes --fields=+S ../../src)

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),gen_pass)
ifneq ($(MAKECMDGOALS),GEN_PASS)
    -include $(OBJECTS:.o=.dep)
endif
endif
endif
