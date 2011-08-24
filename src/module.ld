/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/module.ld $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2010 - 2011
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
 *  IBM_PROLOG_END
 */
SECTIONS
{
    .text : {
	*(.text)
	*(.text._*)
	*(.rodata)
	*(.rodata.*)
	*(.glink)

	. = ALIGN(0x8);
	ctor_start_address = .;
	*(.ctors)
	ctor_end_address = .;
    }
    
    .data ALIGN(0x1000): {
	*(.data)
	*(.data.*)
	*(.branch_lt)
	*(.toc)
	*(.opd)
	*(.got)
	*(.plt)
	*(.bss)
	*(.bss.*)
    }

    .rela : {
	*(.rela.*)
    }

    /DISCARD/ : {
	*(.dtors)
    }
}
