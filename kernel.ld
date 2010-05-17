rom_offset = 0xfff00000;
base_load_address = 0x00000000;
text_load_address = 0x00003000;
hreset_load_address = 0x000ffffc;

SECTIONS
{
    . = base_load_address;

    .text.intvects ALIGN(0x1000): AT(base_load_address + rom_offset) {
	*(.text.intvects)
    }

    . = text_load_address;
    .text ALIGN(0x1000): {
	*(.text)
	*(.rodata)
	*(.rodata.*)

    }
    
    .data ALIGN(0x1000): {
	data_load_address = .;
	*(.data)
	*(.data.*)
	*(.branch_lt)
	*(.bss)

	toc_load_address = .;
	*(.toc)
	opd_load_address = .;
	*(.opd)
	*(.got)
    }

    . = hreset_load_address;
    .text.hreset : {
	*(.text.hreset)
    }

    /DISCARD/ : {
	*(.comment)
	*(.gnu.attributes)
    }
}


