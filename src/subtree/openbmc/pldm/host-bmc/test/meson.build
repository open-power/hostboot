host_bmc_test_src = declare_dependency(
    sources: ['../dbus_to_terminus_effecters.cpp'],
    include_directories: '../../requester',
)

test_sources = [
    '../../common/utils.cpp',
    '../utils.cpp',
    '../dbus/custom_dbus.cpp',
    '../dbus/cable.cpp',
    '../dbus/cpu_core.cpp',
    '../dbus/pcie_device.cpp',
    '../dbus/pcie_slot.cpp',
]

tests = ['dbus_to_terminus_effecter_test', 'utils_test', 'custom_dbus_test']

foreach t : tests
    test(
        t,
        executable(
            t.underscorify(),
            t + '.cpp',
            test_sources,
            implicit_include_directories: false,
            dependencies: [
                gtest,
                gmock,
                host_bmc_test_src,
                libpldm_dep,
                libpldmutils,
                nlohmann_json_dep,
                phosphor_dbus_interfaces,
                phosphor_logging_dep,
                sdbusplus,
                sdeventplus,
            ],
        ),
        workdir: meson.current_source_dir(),
    )
endforeach
