packagedir = join_paths(
    get_option('prefix'),
    get_option('datadir'),
    meson.project_name(),
)


install_subdir('pdr', install_dir: packagedir)

install_subdir('host', install_dir: packagedir)

install_subdir('events', install_dir: packagedir)

if get_option('oem-ibm').disabled()
install_data('fru_master.json', install_dir: packagedir)
endif

if get_option('oem-ibm').enabled()
    install_subdir('../oem/ibm/configurations/fru', install_dir: packagedir)
    install_subdir('../oem/ibm/configurations/events', install_dir: packagedir)
    install_subdir('../oem/ibm/configurations/bios', install_dir: packagedir)
    install_data('../oem/ibm/configurations/fru_master.json',install_dir: packagedir)
    install_data('../oem/ibm/configurations/fileTable.json',
        install_dir: packagedir)
    install_data('../oem/ibm/configurations/host_eid', install_dir: packagedir)
endif

