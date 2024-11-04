deps = [CLI11_dep, libpldm_dep, sdeventplus, phosphor_logging_dep]

executable(
    'set-state-effecter',
    'requester/set_state_effecter.cpp',
    '../common/transport.cpp',
    implicit_include_directories: false,
    include_directories: ['..'],
    dependencies: deps,
    install: true,
    install_dir: get_option('bindir'),
)

executable(
    'set-state-effecter-async',
    'requester/set_state_effecter_async.cpp',
    '../common/transport.cpp',
    implicit_include_directories: false,
    include_directories: ['..'],
    dependencies: deps,
    install: true,
    install_dir: get_option('bindir'),
)
