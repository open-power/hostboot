tests = [
  'libpldmresponder_base_test',
  'libpldmresponder_bios_test',
  'libpldmresponder_bios_attribute_test',
  'libpldmresponder_bios_config_test',
  'libpldmresponder_bios_enum_attribute_test',
  'libpldmresponder_bios_integer_attribute_test',
  'libpldmresponder_bios_string_attribute_test',
  'libpldmresponder_bios_table_test',
  'libpldmresponder_fru_test',
  'libpldmresponder_platform_test',
  'libpldmresponder_pdr_effecter_test',
  'libpldmresponder_pdr_sensor_test',
]

if get_option('oem-ibm').enabled()
  tests += [
    '../../oem/ibm/test/libpldmresponder_fileio_test',
    '../../oem/ibm/test/libpldmresponder_oem_platform_test'
  ]
endif

  dep_src_files = [
  '../../pldmd/instance_id.cpp',
  '../../pldmd/dbus_impl_requester.cpp'
  ]
dep_src = declare_dependency(sources: dep_src_files)

foreach t : tests
  test(t, executable(t.underscorify(), t + '.cpp',
                     implicit_include_directories: false,
                     link_args: dynamic_linker,
                     build_rpath: get_option('oe-sdk').enabled() ? rpath : '',
                     dependencies: [
                         dep_src,
                         libpldm_dep,
                         libpldmresponder,
                         libpldmutils,
                         gtest,
                         gmock,
                         nlohmann_json,
                         phosphor_dbus_interfaces,
                         sdeventplus,
                         sdbusplus]),
       workdir: meson.current_source_dir())
endforeach
