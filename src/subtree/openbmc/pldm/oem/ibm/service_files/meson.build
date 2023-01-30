subdir('scripts')

configure_file(
  copy: true,
  input: 'pldm-create-phyp-nvram.service',
  install: true,
  install_dir: systemd_system_unit_dir,
  output: 'pldm-create-phyp-nvram.service',
)
configure_file(
  copy: true,
  input: 'pldm-create-phyp-nvram-cksum.service',
  install: true,
  install_dir: systemd_system_unit_dir,
  output: 'pldm-create-phyp-nvram-cksum.service',
)
