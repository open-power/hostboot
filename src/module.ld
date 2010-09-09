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
