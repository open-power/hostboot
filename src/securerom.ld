/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/securerom.ld $                                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

SECTIONS {
    .text : {
        *(.branchtable)
        *(.text)
        *(.text._*)
        *(.text.*)
        *(.sfpr)
    }

    .rodata ALIGN(0x8): {
        *(.rodata)
        *(.rodata.*)
        . = ALIGN(8);
        __toc_start = .;
        *(.toc)
        *(.opd)
        *(.got)
        *(.plt)
        *(.data.rel.ro.*)
    }

    .data ALIGN(0x8): {
        *(.data)
        *(.data.*)
        *(.got1)
        *(.sdata)
        *(.bss)
        *(.bss.*)
    }

    end_load_address = .;

    .rela : {
        *(.rela.*)
    }

    .dynsym : { *(.dynsym) }
    .dynstr : { *(.dynstr) }
    .hash : { *(.hash) }
    .gnu.hash : { *(.gnu.hash) }
    .eh_frame : { *(.eh_frame) }

    /DISCARD/ : {
        *(.comment)
        *(.gnu.attributes)
        *(.dtors)
        *(.interp)
    }
}
