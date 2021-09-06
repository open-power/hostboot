test_src = declare_dependency(
          sources: [
            '../../pldmd/dbus_impl_requester.cpp',
            '../../pldmd/instance_id.cpp'])

tests = [
  'handler_test',
  'request_test',
]

foreach t : tests
  test(t, executable(t.underscorify(), t + '.cpp',
                     implicit_include_directories: false,
                     link_args: dynamic_linker,
                     build_rpath: get_option('oe-sdk').enabled() ? rpath : '',
                     dependencies: [
                         gtest,
                         gmock,
                         libpldm_dep,
                         nlohmann_json,
                         phosphor_dbus_interfaces,
                         sdbusplus,
                         sdeventplus,
                         test_src]),
       workdir: meson.current_source_dir())
endforeach
