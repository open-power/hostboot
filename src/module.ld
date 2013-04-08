/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/module.ld $                                               */
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
SECTIONS
{
    .text : {
	*(.text)
	*(.text._*)
        *(.text.*)
	*(.rodata)
	*(.rodata.*)
	*(.glink)
    }
    
    .data ALIGN(0x1000): {
	*(.data)
	*(.data.*)
	*(.branch_lt)

        . = ALIGN(0x8);
	ctor_start_address = .;
	*(.ctors)
	ctor_end_address = .;
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
