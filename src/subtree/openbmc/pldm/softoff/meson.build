deps = [
    libpldm_dep,
    libpldmutils,
    nlohmann_json,
    sdeventplus,
    sdbusplus,
    phosphor_dbus_interfaces,
    phosphor_logging_dep,
    ]

source = ['main.cpp','softoff.cpp']

executable('pldm-softpoweroff',source,
           implicit_include_directories: false,
           dependencies: deps,
           install: true,
           install_dir: get_option('bindir'))

if get_option('systemd').enabled()
  filesystem.copyfile(
    'services/pldmSoftPowerOff.service',
    'pldmSoftPowerOff.service',
    install: true,
    install_dir: systemd_system_unit_dir
  )
endif

