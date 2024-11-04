project(
    'libpldm',
    'c',
    default_options: [
        'debug=true',
        'optimization=g',
        'warning_level=3',
        'werror=true',
        'cpp_std=c++23',
        'c_std=c17',
        'b_ndebug=if-release',
        'tests=' + (meson.is_subproject() ? 'disabled' : 'enabled'),
    ],
    version: '0.10.0',
    meson_version: '>=1.3.0',
)

if get_option('tests').allowed()
    add_languages('cpp')
endif

# For memmem() in src/msgbuf.h
add_project_arguments('-D_GNU_SOURCE', language: ['c'])

compiler = meson.get_compiler('c')
if compiler.has_argument('-Wvla')
    add_project_arguments('-Wvla', language: ['c'])
endif

conf = configuration_data()
if compiler.has_header('poll.h')
    conf.set('PLDM_HAS_POLL', 1)
endif

# ABI control
compiler.has_function_attribute('visibility:default', required: true)
entrypoint = '__attribute__((visibility("default")))'

## Compile test until meson supports it via compiler.has_function_attribute()
have_tainted_args_test = '#if !__has_attribute(tainted_args)\n#error\n#endif'
if compiler.compiles(
    have_tainted_args_test,
    args: '-E',
    name: 'compiler supports function attribute tainted_args',
)
    entrypoint += ' __attribute__((tainted_args))'
endif

libpldm_deprecated_aliases = []
if get_option('abi').contains('deprecated')
    conf.set('LIBPLDM_ABI_DEPRECATED', entrypoint)
    conf.set(
        'LIBPLDM_ABI_DEPRECATED_UNSAFE',
        '__attribute((visibility("default")))',
    )
    add_project_arguments('-DLIBPLDM_API_DEPRECATED', language: ['c', 'cpp'])
else
    conf.set('LIBPLDM_ABI_DEPRECATED', '')
endif
conf.set('LIBPLDM_ABI_STABLE', entrypoint)  # Always expose the stable symbols
if get_option('abi').contains('testing')
    conf.set('LIBPLDM_ABI_TESTING', entrypoint)
    add_project_arguments('-DLIBPLDM_API_TESTING', language: ['c', 'cpp'])
else
    conf.set('LIBPLDM_ABI_TESTING', '')
endif

config = configure_file(output: 'config.h', configuration: conf)

add_project_arguments('-include', '@0@'.format(config), language: 'c')

libpldm_include_dir = include_directories('include', is_system: true)

subdir('include')
subdir('src')

if get_option('tests').allowed()
    subdir('tests')
endif

install_subdir(
    'instance-db',
    install_mode: 'r--r--r--',
    install_dir: get_option('datadir') / meson.project_name(),
)
