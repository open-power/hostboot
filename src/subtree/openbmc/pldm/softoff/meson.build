deps = [
    libpldm,
    libpldmutils,
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

servicedir = systemd.get_pkgconfig_variable('systemdsystemunitdir')

configure_file(input: 'services/pldmSoftPowerOff.service',
                 output: 'pldmSoftPowerOff.service',
                 copy: true,
                 install_dir: servicedir)

