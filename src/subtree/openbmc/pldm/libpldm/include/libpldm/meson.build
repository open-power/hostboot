libpldm_include_dir += include_directories('.')

libpldm_headers += files(
  'base.h',
  'bios.h',
  'bios_table.h',
  'entity.h',
  'firmware_update.h',
  'fru.h',
  'instance-id.h',
  'pdr.h',
  'platform.h',
  'pldm_types.h',
  'requester/pldm.h',
  'state_set.h',
  'states.h',
  'transport.h',
  'utils.h',
  )

libpldm_transport_headers += files(
  'transport/af-mctp.h',
  'transport/mctp-demux.h'
)

if get_option('oem-ibm').allowed()
  libpldm_include_dir += include_directories('oem/ibm')
  libpldm_headers += files(
    'oem/ibm/libpldm/entity_oem_ibm.h',
    'oem/ibm/libpldm/file_io.h',
    'oem/ibm/libpldm/fru_oem_ibm.h',
    'oem/ibm/libpldm/host.h',
    'oem/ibm/libpldm/platform_oem_ibm.h',
    'oem/ibm/libpldm/state_set_oem_ibm.h'
  )
endif
