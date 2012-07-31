/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/kernel.ld $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2010-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
base_load_address = 0x00000000;
text_load_address = 0x00003000;

SECTIONS
{
    . = base_load_address;

    .text ALIGN(0x1000): {
	*(.text.intvects)
	. = text_load_address;
        *(.text.kernelasm)
	*(.text)
	*(.text._*)
	*(.rodata)
	*(.rodata.*)
	. = ALIGN(0x8);
	ctor_start_address = .;
	*(.ctors)
	ctor_end_address = .;
    }
    
    .data ALIGN(0x1000): {
	data_load_address = .;
	*(.data)
	*(.data.*)
	*(.branch_lt)

	toc_load_address = .;
	*(.toc)
	*(.opd)
	*(.got)

	*(.bss)
	*(.bss.*)

    }

    end_load_address = .;
    
    .dynstr : {
	*(.dynstr)
    }

    .rela : {
	*(.rela.*)
    }
 

    /DISCARD/ : {
	*(.comment)
	*(.gnu.attributes)
	*(.dtors)
	*(.interp)
    }
}


