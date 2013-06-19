/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel.ld $                                               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
base_load_address = 0x00000000;
text_load_address = 0x00002000;

SECTIONS
{
    . = base_load_address;

    .text ALIGN(0x1000): {
        *(.text.intvects)
        . = text_load_address;
        *(.text.kernelasm)
        *(.text)
        *(.text._*)
        *(.text.*)
    }

    .rodata ALIGN(0x8): {
        __minimum_data_start_addr = ALIGN(0x1000);
        ctor_start_address = .;
        *(.ctors)
        ctor_end_address = .;
        *(.rodata)
        *(.rodata.*)
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


