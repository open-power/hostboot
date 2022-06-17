/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/build/tools/dce/dce.ld $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */






/**************************************************************************
* Note: This is the default GNU LD linker script, obtained by running
* the linker with the Hostboot build flags and adding the flag
* --verbose to the command line.
*
* There were original modifications made to this file to allow DCE to link
* with it:
*
*  1. Change the alignment of the .got section from ALIGN(256) to ALIGN(8):
*
*     <   .got                : ALIGN(256) { *(.got .toc) }
*     ---
*     >   .got                : ALIGN(8) { *(.got .toc) }
*
*  2. Align the .text section to 256 bytes:
*
*     <   .text           :
*     <   {
*     ---
*     >   .text           : ALIGN(256)
*     >   {
*     >       . = ALIGN(256);
*
* These changes are required so that the linker puts the "output" locations
* of the ELF sections at the same alignment that it puts the "input" ELF
* sections.
*
* More changes were made over time, and these are recorded in the git history
* of this file.
***************************************************************************/

/* Script for --shared -z combreloc: shared library, combine & sort relocs */
/* Copyright (C) 2014-2017 Free Software Foundation, Inc.
   Copying and distribution of this script, with or without modification,
   are permitted in any medium without royalty provided the copyright
   notice and this notice are preserved.  */
OUTPUT_FORMAT("elf64-powerpc", "elf64-powerpc",
	      "elf64-powerpc")
OUTPUT_ARCH(powerpc:common64)
ENTRY(_start)
SEARCH_DIR("=/esw/san5/lpf/repos/op-build/output/host/powerpc64-buildroot-linux-gnu/lib64be"); SEARCH_DIR("=/usr/local/lib64be"); SEARCH_DIR("=/lib64be"); SEARCH_DIR("=/usr/lib64be"); SEARCH_DIR("=/esw/san5/lpf/repos/op-build/output/host/powerpc64-buildroot-linux-gnu/lib"); SEARCH_DIR("=/usr/local/lib"); SEARCH_DIR("=/lib"); SEARCH_DIR("=/usr/lib");
SECTIONS
{
  /* Read-only sections, merged into text segment: */
  . = SEGMENT_START("text-segment", 0) + SIZEOF_HEADERS;
  .note.gnu.build-id : { *(.note.gnu.build-id) }
  .hash           : { *(.hash) }
  .gnu.hash       : { *(.gnu.hash) }
  .dynsym         : { *(.dynsym) }
  .dynstr         : { *(.dynstr) }
  .gnu.version    : { *(.gnu.version) }
  .gnu.version_d  : { *(.gnu.version_d) }
  .gnu.version_r  : { *(.gnu.version_r) }
  .rela.dyn       :
    {
      *(.rela.opd)
      *(.rela.init)
      *(.rela.text .rela.text.* .rela.gnu.linkonce.t.*)
      *(.rela.fini)
      *(.rela.rodata .rela.rodata.* .rela.gnu.linkonce.r.*)
      *(.rela.data .rela.data.* .rela.gnu.linkonce.d.*)
      *(.rela.tdata .rela.tdata.* .rela.gnu.linkonce.td.*)
      *(.rela.tbss .rela.tbss.* .rela.gnu.linkonce.tb.*)
      *(.rela.ctors)
      *(.rela.dtors)
      *(.rela.got)
      *(.rela.toc)
      *(.rela.toc1)
      *(.rela.tocbss)
      *(.rela.branch_lt)
      *(.rela.sdata .rela.sdata.* .rela.gnu.linkonce.s.*)
      *(.rela.sbss .rela.sbss.* .rela.gnu.linkonce.sb.*)
      *(.rela.sdata2 .rela.sdata2.* .rela.gnu.linkonce.s2.*)
      *(.rela.sbss2 .rela.sbss2.* .rela.gnu.linkonce.sb2.*)
      *(.rela.bss .rela.bss.* .rela.gnu.linkonce.b.*)
      *(.rela.iplt)
    }
  .rela.plt       :
    {
      *(.rela.plt)
    }
  .init           :
  {
    KEEP (*(SORT_NONE(.init)))
  } =0x60000000
  .text           : ALIGN(256)
  {
    . = ALIGN(256);
    *(.text.unlikely .text.*_unlikely .text.unlikely.*)
    *(.text.exit .text.exit.*)
    *(.text.startup .text.startup.*)
    *(.text.hot .text.hot.*)
    *(.text .stub .text.* .gnu.linkonce.t.*)
    /* .gnu.warning sections are handled specially by elf32.em.  */
    *(.gnu.warning)
    *(.sfpr .glink)
  } =0x60000000
  .data_segment_addr : ALIGN(4096)
  {

     /* This .data_segment_addr segment exists so that we can forcibly
        align everything after the .text segment to a page
        boundary. We have to do that because Hostboot manages memory
        permissions on page boundaries, and we have to avoid setting
        any data segment memory to "executable" because executable
        memory is not writeable. */

      /* The only thing in this segment is the variable
         _data_segment_addr from start.c++. We put something here so
         that the linker doesn't discard this segment and screw up our
         alignment. */

      *(.data_segment_addr)
  }
  .fini           :
  {
    KEEP (*(SORT_NONE(.fini)))
  } =0x60000000
  PROVIDE (__etext = .);
  PROVIDE (_etext = .);
  PROVIDE (etext = .);
  .rodata         : {

     /* .rodata is special because the linker actually makes space in
        the ELF file for everything in this segment. We are throwing
        all the data-related sections (.rodata, .data, .bss, etc) into
        this .rodata segment so that the linker actually allocates
        space for it in the output ELF (normally since some of this
        data is all zero, the linker would just put it into .bss or
        something and instruct the runtime loader to make space for it
        without actually including all those zeroes in the ELF, which
        saves space; however, our runtime loader executes the ELF
        as-is without making more room for segments that are smaller
        than their on-disk representation, so we want the linker to
        actually include the zeroes in the file. We're not trying to
        be space efficient.)

        Also note that .rodata is not actually read-only memory in
        DCE; the loader gives all data read-write permissions, which
        is why we can put these other sections here. */

     *(.rodata .rodata.* .gnu.linkonce.r.*)
     *(.data .data.* .gnu.linkonce.d.*)
     *(.dynbss)
     *(.bss .bss.* .gnu.linkonce.b.*)
     SORT(CONSTRUCTORS)
     *(COMMON)
   }
  .rodata1        : { *(.rodata1) }
  .eh_frame_hdr : { *(.eh_frame_hdr) *(.eh_frame_entry .eh_frame_entry.*) }
  .eh_frame       : ONLY_IF_RO { KEEP (*(.eh_frame)) *(.eh_frame.*) }
  .gcc_except_table   : ONLY_IF_RO { *(.gcc_except_table
  .gcc_except_table.*) }
  .gnu_extab   : ONLY_IF_RO { *(.gnu_extab*) }
  /* These sections are generated by the Sun/Oracle C++ compiler.  */
  .exception_ranges   : ONLY_IF_RO { *(.exception_ranges
  .exception_ranges*) }
  /* Adjust the address for the data segment.  We want to adjust up to
     the same address within the page on the next page up.  */
  . = DATA_SEGMENT_ALIGN (CONSTANT (MAXPAGESIZE), CONSTANT (COMMONPAGESIZE));
  /* Exception handling  */
  .eh_frame       : ONLY_IF_RW { KEEP (*(.eh_frame)) *(.eh_frame.*) }
  .gnu_extab      : ONLY_IF_RW { *(.gnu_extab) }
  .gcc_except_table   : ONLY_IF_RW { *(.gcc_except_table .gcc_except_table.*) }
  .exception_ranges   : ONLY_IF_RW { *(.exception_ranges .exception_ranges*) }
  /* Thread Local Storage sections  */
  .tdata	  : { *(.tdata .tdata.* .gnu.linkonce.td.*) }
  .tbss		  : { *(.tbss .tbss.* .gnu.linkonce.tb.*) *(.tcommon) }
  .preinit_array     :
  {
    KEEP (*(.preinit_array))
  }
  .init_array     :
  {
    _start_ctors = .;
    KEEP (*(SORT_BY_INIT_PRIORITY(.init_array.*) SORT_BY_INIT_PRIORITY(.ctors.*)))
    KEEP (*(.init_array EXCLUDE_FILE (*crtbegin.o *crtbegin?.o *crtend.o *crtend?.o ) .ctors))
    _end_ctors = .;
  }
  .fini_array     :
  {
    _start_dtors = .;
    KEEP (*(SORT_BY_INIT_PRIORITY(.fini_array.*) SORT_BY_INIT_PRIORITY(.dtors.*)))
    KEEP (*(.fini_array EXCLUDE_FILE (*crtbegin.o *crtbegin?.o *crtend.o *crtend?.o ) .dtors))
    _end_dtors = .;
  }
  .ctors          :
  {
    /* gcc uses crtbegin.o to find the start of
       the constructors, so we make sure it is
       first.  Because this is a wildcard, it
       doesn't matter if the user does not
       actually link against crtbegin.o; the
       linker won't look for a file to match a
       wildcard.  The wildcard also means that it
       doesn't matter which directory crtbegin.o
       is in.  */
    KEEP (*crtbegin.o(.ctors))
    KEEP (*crtbegin?.o(.ctors))
    /* We don't want to include the .ctor section from
       the crtend.o file until after the sorted ctors.
       The .ctor section from the crtend file contains the
       end of ctors marker and it must be last */
    KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .ctors))
    KEEP (*(SORT(.ctors.*)))
    KEEP (*(.ctors))
  }
  .dtors          :
  {
    KEEP (*crtbegin.o(.dtors))
    KEEP (*crtbegin?.o(.dtors))
    KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .dtors))
    KEEP (*(SORT(.dtors.*)))
    KEEP (*(.dtors))
  }
  .jcr            : { KEEP (*(.jcr)) }
  .data.rel.ro : { *(.data.rel.ro.local* .gnu.linkonce.d.rel.ro.local.*) *(.data.rel.ro .data.rel.ro.* .gnu.linkonce.d.rel.ro.*) }
  .dynamic        : { *(.dynamic) }
  .opd		  : ALIGN(8) { KEEP (*(.opd)) }
  .toc1		  : ALIGN(8) { *(.toc1) }
  .branch_lt	  : ALIGN(8) { *(.branch_lt) }
  .got		: ALIGN(8) { *(.got .toc) }
  . = DATA_SEGMENT_RELRO_END (0, .);
  .toc		  : ALIGN(8) { *(.toc) }
  /* We want the small data sections together, so single-instruction offsets
     can access them all, and initialized data all before uninitialized, so
     we can shorten the on-disk segment size.  */
  .sdata          :
  {
    *(.sdata2 .sdata2.* .gnu.linkonce.s2.*)
    *(.sdata .sdata.* .gnu.linkonce.s.*)
  }
  .tocbss	  : ALIGN(8) { *(.tocbss)}
  .sbss           :
  {
    *(.sbss2 .sbss2.* .gnu.linkonce.sb2.*)
    *(.dynsbss)
    *(.sbss .sbss.* .gnu.linkonce.sb.*)
    *(.scommon)
  }
  .plt            : { *(.plt) }
  .iplt           : { *(.iplt) }
  .data           :
  {
  }
  .data1          : { *(.data1) }
  _edata = .; PROVIDE (edata = .);
  . = .;
  __bss_start = .;
  .bss            :
  {
   /* Align here to ensure that the .bss section occupies space up to
      _end.  Align after .bss to ensure correct alignment even if the
      .bss section disappears because there are no input sections.
      FIXME: Why do we need it? When there is no .bss section, we don't
      pad the .data section.  */
   . = ALIGN(. != 0 ? 64 / 8 : 1);
  }
  . = ALIGN(64 / 8);
  . = SEGMENT_START("ldata-segment", .);
  . = ALIGN(64 / 8);
  _end = .; PROVIDE (end = .);
  . = DATA_SEGMENT_END (.);
  /* Stabs debugging sections.  */
  .stab          0 : { *(.stab) }
  .stabstr       0 : { *(.stabstr) }
  .stab.excl     0 : { *(.stab.excl) }
  .stab.exclstr  0 : { *(.stab.exclstr) }
  .stab.index    0 : { *(.stab.index) }
  .stab.indexstr 0 : { *(.stab.indexstr) }
  .comment       0 : { *(.comment) }
  /* DWARF debug sections.
     Symbols in the DWARF debugging sections are relative to the beginning
     of the section so we begin them at 0.  */
  /* DWARF 1 */
  .debug          0 : { *(.debug) }
  .line           0 : { *(.line) }
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *(.debug_srcinfo) }
  .debug_sfnames  0 : { *(.debug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges) }
  .debug_pubnames 0 : { *(.debug_pubnames) }
  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
  .debug_abbrev   0 : { *(.debug_abbrev) }
  .debug_line     0 : { *(.debug_line .debug_line.* .debug_line_end ) }
  .debug_frame    0 : { *(.debug_frame) }
  .debug_str      0 : { *(.debug_str) }
  .debug_loc      0 : { *(.debug_loc) }
  .debug_macinfo  0 : { *(.debug_macinfo) }
  /* SGI/MIPS DWARF 2 extensions */
  .debug_weaknames 0 : { *(.debug_weaknames) }
  .debug_funcnames 0 : { *(.debug_funcnames) }
  .debug_typenames 0 : { *(.debug_typenames) }
  .debug_varnames  0 : { *(.debug_varnames) }
  /* DWARF 3 */
  .debug_pubtypes 0 : { *(.debug_pubtypes) }
  .debug_ranges   0 : { *(.debug_ranges) }
  /* DWARF Extension.  */
  .debug_macro    0 : { *(.debug_macro) }
  .debug_addr     0 : { *(.debug_addr) }
  .gnu.attributes 0 : { KEEP (*(.gnu.attributes)) }
  /DISCARD/ : { *(.note.GNU-stack) *(.gnu_debuglink) *(.gnu.lto_*) }
}
