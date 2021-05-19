tests = [
  'libpldm_base_test',
  'libpldm_platform_test',
  'libpldm_bios_test',
  'libpldm_bios_table_test',
  'libpldm_fru_test',
  'libpldm_utils_test',
  'libpldm_pdr_test'
]

if get_option('oem-ibm').enabled()
  tests += [
    '../../oem/ibm/test/libpldm_fileio_test',
    '../../oem/ibm/test/libpldm_host_test',
  ]
endif

foreach t : tests
  test(t, executable(t.underscorify(), t + '.cpp',
                     implicit_include_directories: false,
                     link_args: dynamic_linker,
                     build_rpath: get_option('oe-sdk').enabled() ? rpath : '',
                     dependencies: [
                         libpldm_dep,
                         gtest,
                         gmock]),
       workdir: meson.current_source_dir())
endforeach

