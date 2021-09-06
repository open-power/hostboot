common_test_src = declare_dependency(
          sources: [
            '../utils.cpp'])

tests = [
  'pldm_utils_test',
]

foreach t : tests
  test(t, executable(t.underscorify(), t + '.cpp',
                     implicit_include_directories: false,
                     link_args: dynamic_linker,
                     build_rpath: get_option('oe-sdk').enabled() ? rpath : '',
                     dependencies: [
                         common_test_src,
                         gtest,
                         libpldm_dep,
                         nlohmann_json,
                         phosphor_dbus_interfaces,
                         sdbusplus]),
       workdir: meson.current_source_dir())
endforeach
