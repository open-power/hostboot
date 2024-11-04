libpldmresponder_deps = [
    phosphor_dbus_interfaces,
    phosphor_logging_dep,
    nlohmann_json_dep,
    sdbusplus,
    sdeventplus,
    libpldm_dep,
    libpldmutils,
]

sources = [
    'base.cpp',
    'bios.cpp',
    'bios_table.cpp',
    'bios_attribute.cpp',
    'bios_string_attribute.cpp',
    'bios_integer_attribute.cpp',
    'bios_enum_attribute.cpp',
    'bios_config.cpp',
    'pdr_utils.cpp',
    'pdr.cpp',
    'platform.cpp',
    'platform_config.cpp',
    'fru_parser.cpp',
    'fru.cpp',
    '../host-bmc/host_pdr_handler.cpp',
    '../host-bmc/utils.cpp',
    '../host-bmc/dbus_to_event_handler.cpp',
    '../host-bmc/dbus_to_terminus_effecters.cpp',
    '../host-bmc/host_condition.cpp',
    '../host-bmc/dbus/custom_dbus.cpp',
    '../host-bmc/dbus/cable.cpp',
    '../host-bmc/dbus/cpu_core.cpp',
    '../host-bmc/utils.cpp',
    '../host-bmc/dbus/pcie_device.cpp',
    '../host-bmc/dbus/pcie_slot.cpp',
    'event_parser.cpp',
]

responder_headers = ['.']

if get_option('oem-ibm').allowed()
    responder_headers += ['../oem/ibm/']
    sources += [
        '../oem/ibm/libpldmresponder/utils.cpp',
        '../oem/ibm/libpldmresponder/file_io.cpp',
        '../oem/ibm/libpldmresponder/file_table.cpp',
        '../oem/ibm/libpldmresponder/file_io_by_type.cpp',
        '../oem/ibm/libpldmresponder/file_io_type_pel.cpp',
        '../oem/ibm/libpldmresponder/file_io_type_dump.cpp',
        '../oem/ibm/libpldmresponder/file_io_type_cert.cpp',
        '../oem/ibm/libpldmresponder/platform_oem_ibm.cpp',
        '../oem/ibm/libpldmresponder/fru_oem_ibm.cpp',
        '../oem/ibm/libpldmresponder/oem_ibm_handler.cpp',
        '../oem/ibm/libpldmresponder/inband_code_update.cpp',
        '../oem/ibm/requester/dbus_to_file_handler.cpp',
        '../oem/ibm/libpldmresponder/collect_slot_vpd.cpp',
        '../oem/ibm/libpldmresponder/file_io_type_progress_src.cpp',
        '../oem/ibm/libpldmresponder/file_io_type_vpd.cpp',
        '../oem/ibm/libpldmresponder/file_io_type_pcie.cpp',
        '../oem/ibm/host-bmc/host_lamp_test.cpp',
    ]
endif

libpldmresponder = library(
    'pldmresponder',
    sources,
    version: meson.project_version(),
    include_directories: include_directories(responder_headers),
    dependencies: libpldmresponder_deps,
    install: true,
)

libpldmresponder_dep = declare_dependency(
    include_directories: include_directories(responder_headers),
    link_with: libpldmresponder,
)

if get_option('tests').allowed()
    subdir('test')
endif

