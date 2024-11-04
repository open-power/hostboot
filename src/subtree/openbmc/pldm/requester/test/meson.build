test_src = declare_dependency(
    sources: ['../mctp_endpoint_discovery.cpp', '../../common/utils.cpp'],
)

tests = ['handler_test', 'request_test', 'mctp_endpoint_discovery_test']

foreach t : tests
    test(
        t,
        executable(
            t.underscorify(),
            t + '.cpp',
            implicit_include_directories: false,
            include_directories: ['../../', '../../pldmd'],
            dependencies: [
                gtest,
                gmock,
                libpldm_dep,
                nlohmann_json_dep,
                phosphor_dbus_interfaces,
                phosphor_logging_dep,
                sdbusplus,
                sdeventplus,
                test_src,
            ],
        ),
        workdir: meson.current_source_dir(),
    )
endforeach
