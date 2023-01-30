pldmd_inc = include_directories('../')
test_src = declare_dependency(
          sources: [
            '../pldmd/instance_id.cpp'],
          include_directories:pldmd_inc)

tests = [
  'pldmd_instanceid_test',
  'pldmd_registration_test',
]

foreach t : tests
  test(t, executable(t.underscorify(), t + '.cpp',
                     implicit_include_directories: false,
                     link_args: dynamic_linker,
                     build_rpath: get_option('oe-sdk').enabled() ? rpath : '',
                     dependencies: [
                         libpldm_dep,
                         nlohmann_json,
                         gtest,
                         test_src]),
       workdir: meson.current_source_dir())
endforeach
