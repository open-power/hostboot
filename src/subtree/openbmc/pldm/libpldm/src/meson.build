libpldm_sources += files(
  'base.c',
  'bios.c',
  'platform.c',
  'bios_table.c',
  'firmware_update.c',
  'fru.c',
  'pdr.c',
  'utils.c'
  )

subdir('requester')
subdir('transport')

if get_option('oem-ibm').enabled()
   subdir('oem/ibm')
endif
