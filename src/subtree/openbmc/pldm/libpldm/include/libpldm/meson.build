libpldm_headers = files(
    'base.h',
    'bios.h',
    'bios_table.h',
    'compiler.h',
    'entity.h',
    'firmware_update.h',
    'fru.h',
    'instance-id.h',
    'pdr.h',
    'platform.h',
    'pldm.h',
    'pldm_types.h',
    'state_set.h',
    'states.h',
    'transport.h',
    'transport/af-mctp.h',
    'transport/mctp-demux.h',
    'utils.h',
)

if get_option('oem-ibm').allowed()
    libpldm_headers += files(
        'oem/ibm/entity.h',
        'oem/ibm/file_io.h',
        'oem/ibm/fru.h',
        'oem/ibm/host.h',
        'oem/ibm/platform.h',
        'oem/ibm/state_set.h',
    )
endif

if get_option('oem-meta').allowed()
    libpldm_headers += files('oem/meta/file_io.h')
endif


install_headers(libpldm_headers, subdir: 'libpldm', preserve_path: true)
