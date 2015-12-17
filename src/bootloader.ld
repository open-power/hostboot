/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader.ld $                                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
/* [+] Google Inc.                                                        */
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
base_load_address = 0x00000000;
text_load_address = 0x00000020;

SECTIONS
{
    . = base_load_address;

    . = text_load_address;
    .text ALIGN(0x0020): {
        *(.text.intvects)
        *(.text.bootloaderasm)
        *(.text)
        *(.text._*)
        *(.text.*)
    }

    .rodata ALIGN(0x8): {
        __minimum_data_start_addr = ALIGN(0x1000);
        ctor_start_address = .;
        *(.ctors)
        *(.ctors.*)
        ctor_end_address = .;
        *(.rodata)
        *(.rodata.*)
        . = ALIGN(8);
        toc_load_address = .;
        *(.toc)
        *(.opd)
        *(.got)
        *(.plt)
        *(.data.rel.ro.*)
        *(.data.*traceData_codeInfo*)

        . = __minimum_data_start_addr > . ? __minimum_data_start_addr : .;
    }

    .data ALIGN(0x8): {
        data_load_address = .;
        *(.data)
        *(.data.*)

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


