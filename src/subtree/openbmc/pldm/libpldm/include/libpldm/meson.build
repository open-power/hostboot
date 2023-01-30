libpldm_include_dir += include_directories('.')

libpldm_headers += files(
  'base.h',
  'pldm_types.h',
  'platform.h',
  'bios.h',
  'bios_table.h',
  'entity.h',
  'states.h',
  'state_set.h',
  'fru.h',
  'utils.h',
  'pdr.h',
  'firmware_update.h'
  )

if get_option('oem-ibm').enabled()
  libpldm_include_dir += include_directories('oem/ibm')
  libpldm_headers += files(
    'oem/ibm/libpldm/entity_oem_ibm.h',
    'oem/ibm/libpldm/file_io.h',
    'oem/ibm/libpldm/host.h',
    'oem/ibm/libpldm/fru_oem_ibm.h',
    'oem/ibm/libpldm/platform_oem_ibm.h',
    'oem/ibm/libpldm/state_set_oem_ibm.h'
  )
endif

if get_option('requester-api').enabled()
   libpldm_headers += files(
    'requester/pldm.h'
    )
endif

