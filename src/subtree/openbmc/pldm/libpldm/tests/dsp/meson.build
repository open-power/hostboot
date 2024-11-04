tests += [
    'dsp/base',
    'dsp/bios_table',
    'dsp/bios',
    'dsp/firmware_update',
    'dsp/fru',
    'dsp/pdr',
    'dsp/platform',
]

test(
    'dsp/bios_table_iter',
    executable(
        'bios_table_iter',
        'bios_table_iter.c',
        implicit_include_directories: false,
        include_directories: test_include_dirs,
    ),
)
