deps = [
    libpldm_dep,
    libpldmutils,
    nlohmann_json,
    sdeventplus,
    sdbusplus,
    phosphor_dbus_interfaces,
    ]

source = ['main.cpp','softoff.cpp']

executable('pldm-softpoweroff',source,
           implicit_include_directories: false,
           dependencies: deps,
           install: true,
           install_dir: get_option('bindir'))

if get_option('systemd').enabled()
  configure_file(input: 'services/pldmSoftPowerOff.service',
                   output: 'pldmSoftPowerOff.service',
                   copy: true,
                   install_dir: systemd_system_unit_dir)
endif

