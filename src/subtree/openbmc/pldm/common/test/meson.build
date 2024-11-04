common_test_src = declare_dependency(sources: ['../utils.cpp'])

tests = ['pldm_utils_test']

foreach t : tests
    test(
        t,
        executable(
            t.underscorify(),
            t + '.cpp',
            implicit_include_directories: false,
            dependencies: [
                common_test_src,
                gmock,
                gtest,
                libpldm_dep,
                nlohmann_json_dep,
                phosphor_dbus_interfaces,
                phosphor_logging_dep,
                libpldmutils,
                sdbusplus,
            ],
        ),
        workdir: meson.current_source_dir(),
    )
endforeach
