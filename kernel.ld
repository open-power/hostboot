base_load_address = 0xfff00000;
text_load_address = 0xfff08000;
hreset_load_address = 0xfffffffc;

SECTIONS
{
    . = base_load_address;

    .text.intvects ALIGN(0x1000): {
	*(.text.intvects)
    }

    . = text_load_address;
    .text ALIGN(0x1000): {
	*(.text)
	*(.rodata)
	*(.rodata.*)
    }

    .data ALIGN(0x1000): {
	*(.data)
	*(.data.*)
	*(.branch_lt)
	*(.opd)

	*(.bss)
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


