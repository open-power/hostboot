all: ALL ${EXTRA_PARTS}

ifdef MODULE
OBJDIR = ${ROOTPATH}/obj/modules/${MODULE}
BEAMDIR = ${ROOTPATH}/obj/beam/${MODULE}
IMGDIR = ${ROOTPATH}/img
EXTRACOMMONFLAGS += -fPIC -Bsymbolic -Bsymbolic-functions
LIBS += $(addsuffix .so, $(addprefix lib, ${MODULE}))
MODULE_INIT = ${ROOTPATH}/obj/core/module_init.o
else
OBJDIR = ${ROOTPATH}/obj/core
BEAMDIR = ${ROOTPATH}/obj/beam/core
IMGDIR = ${ROOTPATH}/img
endif

TRACEPP = ${ROOTPATH}/src/build/trace/tracepp
CUSTOM_LINKER_EXE = ${ROOTPATH}/src/build/linker/linker
CUSTOM_LINKER = i686-mcp6-jail ${CUSTOM_LINKER_EXE}

CC = ${TRACEPP} ppc64-mcp6-gcc
CXX = ${TRACEPP} ppc64-mcp6-g++
LD = ppc64-mcp6-ld
OBJDUMP = ppc64-mcp6-objdump
APYFIPSHDR = apyfipshdr
APYRUHHDR = apyruhhdr

BEAMVER = beam-3.5.2
BEAMPATH = /afs/rch/projects/esw/beam/${BEAMVER}
BEAMCMD = i686-mcp6-jail ${BEAMPATH}/bin/beam_compile
BEAMFLAGS = \
    --beam::source=${ROOTPATH}/src/build/beam/compiler_c_config.tcl \
    --beam::source=${ROOTPATH}/src/build/beam/compiler_cpp_config.tcl \
    --beam::exit0 \
    -o /dev/null

COMMONFLAGS = -O3 -nostdlib ${EXTRACOMMONFLAGS}
CFLAGS = ${COMMONFLAGS} -mcpu=power7 -nostdinc -g -msoft-float -mno-altivec \
	 -Wall -Werror
ASMFLAGS = ${COMMONFLAGS} -mcpu=power7
CXXFLAGS = ${CFLAGS} -nostdinc++ -fno-rtti -fno-exceptions -Wall
LDFLAGS = --nostdlib --sort-common ${COMMONFLAGS}

INCDIR = ${ROOTPATH}/src/include/

OBJECTS = $(addprefix ${OBJDIR}/, ${OBJS})
LIBRARIES = $(addprefix ${IMGDIR}/, ${LIBS})

ifdef IMGS
IMGS_ = $(addprefix ${IMGDIR}/, ${IMGS})
LIDS = $(foreach lid,$(addsuffix _LIDNUMBER, $(IMGS)),$(addprefix ${IMGDIR}/,$(addsuffix .ruhx, $($(lid)))))
IMAGES = $(addsuffix .bin, ${IMGS_}) $(addsuffix .elf, ${IMGS_}) ${LIDS}
#$(addsuffix .ruhx, ${IMGS_})
endif

ifdef EXTRA_LIDS
EXTRA_LIDS_ = $(foreach lid,$(addsuffix _LIDNUMBER, $(EXTRA_LIDS)),$(addprefix ${IMGDIR}/,$(addsuffix .lidhdr, $($(lid)))))
endif

${OBJDIR}/%.o ${OBJDIR}/%.list : %.C
	mkdir -p ${OBJDIR}
	${CXX} -c ${CXXFLAGS} $< -o $@ -I ${INCDIR}
	${OBJDUMP} -dCS $@ > $(basename $@).list	

${OBJDIR}/%.o ${OBJDIR}/%.list : %.c
	mkdir -p ${OBJDIR}
	${CC} -c ${CFLAGS} -std=c99 $< -o $@ -I ${INCDIR}
	${OBJDUMP} -dCS $@ > $(basename $@).list

${OBJDIR}/%.o : %.S
	mkdir -p ${OBJDIR}
	${CC} -c ${ASMFLAGS} $< -o $@ -Wa,-I${INCDIR} -I${INCDIR}

${OBJDIR}/%.dep : %.C
	mkdir -p ${OBJDIR}; \
	rm -f $@; \
	${CXX} -M ${CXXFLAGS} $< -o $@.$$$$ -I ${INCDIR}; \
	sed 's,\($*\)\.o[ :]*,${OBJDIR}/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

${OBJDIR}/%.dep : %.c
	mkdir -p ${OBJDIR}; \
	rm -f $@; \
	${CC} -M ${CFLAGS} -std=c99 $< -o $@.$$$$ -I ${INCDIR}; \
	sed 's,\($*\)\.o[ :]*,${OBJDIR}/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

${OBJDIR}/%.dep : %.S
	mkdir -p ${OBJDIR}; \
	rm -f $@; \
	${CC} -M ${ASMFLAGS} $< -o $@.$$$$ -Wa,-I${INCDIR} -I${INCDIR}; \
	sed 's,\($*\)\.o[ :]*,${OBJDIR}/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

ifdef MODULE
${IMGDIR}/%.so : ${OBJECTS} ${ROOTPATH}/src/module.ld ${MODULE_INIT} ${SUBDIRS}
	${LD} -shared -z now ${LDFLAGS} \
	      $(filter-out ${ROOTPATH}/src/module.ld,$^) \
	      -T ${ROOTPATH}/src/module.ld -o $@
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
	      $(addprefix ${IMGDIR}/lib, $(addsuffix .so, \
		$($*_MODULES))) > ${IMGDIR}/.$*.lnkout
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

%.d: ${OBJECTS}
	cd ${basename $@} && ${MAKE}

%.clean:
	cd ${basename $@} && ${MAKE} clean

%.beamdir:
	cd ${basename $@} && ${MAKE} beam

ALL: ${OBJECTS} ${SUBDIRS} ${LIBRARIES} ${EXTRA_LIDS_}
ifdef IMAGES
	${MAKE} ${IMAGES}
endif

${BEAMDIR}/%.beam : %.C
	mkdir -p ${BEAMDIR}
	${BEAMCMD} -I ${INCDIR} ${CXXFLAGS} ${BEAMFLAGS} $< \
	    --beam::complaint_file=$@ --beam::parser_file=$@

${BEAMDIR}/%.beam : %.c
	mkdir -p ${BEAMDIR}
	${BEAMCMD} -I ${INCDIR} ${CXXFLAGS} ${BEAMFLAGS} $< \
	    --beam::complaint_file=$@ --beam::parser_file=$@

${BEAMDIR}/%.beam : %.S
	echo Skipping ASM file.

BEAMOBJS = $(addprefix ${BEAMDIR}/, ${OBJS:.o=.beam})
beam: ${SUBDIRS:.d=.beamdir} ${BEAMOBJS}

clean: ${SUBDIRS:.d=.clean}
	(rm -f ${OBJECTS} ${OBJECTS:.o=.dep} ${OBJECTS:.o=.list} \
	       ${BEAMOBJS} ${LIBRARIES} \
	       ${IMAGES} ${IMAGES:.bin=.list} ${IMAGES:.bin=.syms} \
	       ${IMAGES:.bin=.bin.modinfo} ${IMAGES:.ruhx=.lid} \
	       ${IMAGES:.ruhx=.lidhdr} ${EXTRA_LIDS_})

cscope: ALL
	mkdir -p ${ROOTPATH}/obj/cscope
	(cd ${ROOTPATH}/obj/cscope ; rm -f cscope.* ; \
	    find ../../ -name '*.[CHchS]' -fprint cscope.files; \
	    cscope -bqk)

ifneq ($(MAKECMDGOALS),clean)
    include $(OBJECTS:.o=.dep)
endif
