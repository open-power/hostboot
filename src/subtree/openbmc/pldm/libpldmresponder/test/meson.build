tests = [
    'libpldmresponder_base_test',
    'libpldmresponder_bios_test',
    'libpldmresponder_bios_attribute_test',
    'libpldmresponder_bios_enum_attribute_test',
    'libpldmresponder_bios_integer_attribute_test',
    'libpldmresponder_bios_string_attribute_test',
    'libpldmresponder_bios_table_test',
    'libpldmresponder_fru_test',
    'libpldmresponder_platform_test',
    'libpldmresponder_pdr_effecter_test',
    'libpldmresponder_pdr_sensor_test',
]


if get_option('oem-ibm').allowed()
    tests += [
        '../../oem/ibm/test/libpldmresponder_fileio_test',
        '../../oem/ibm/test/libpldmresponder_oem_platform_test',
        '../../oem/ibm/test/host_bmc_lamp_test',
    ]
endif

if get_option('system-specific-bios-json').allowed()
    tests += ['libpldmresponder_systemspecific_bios_test']
else
    tests += ['libpldmresponder_bios_config_test']
endif

foreach t : tests
    test(
        t,
        executable(
            t.underscorify(),
            t + '.cpp',
            implicit_include_directories: false,
            include_directories: ['../../requester', '../../pldmd'],
            dependencies: [
                libpldm_dep,
                libpldmresponder_dep,
                libpldmutils,
                gtest,
                gmock,
                nlohmann_json_dep,
                phosphor_dbus_interfaces,
                phosphor_logging_dep,
                sdeventplus,
                sdbusplus,
            ],
        ),
        workdir: meson.current_source_dir(),
    )
endforeach
