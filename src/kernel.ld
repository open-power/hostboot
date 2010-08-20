rom_offset = 0xfff00000;
base_load_address = 0x00000000;
text_load_address = 0x00003000;

SECTIONS
{
    . = base_load_address;

    .text ALIGN(0x1000): AT(base_load_address + rom_offset) {
	*(.text.intvects)
	. = text_load_address;
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
	opd_load_address = .;
	*(.opd)
	*(.got)

	*(.bss)
	*(.bss.*)

    }

    end_load_address = .;

    /DISCARD/ : {
	*(.comment)
	*(.gnu.attributes)
	*(.dtors)
    }
}


