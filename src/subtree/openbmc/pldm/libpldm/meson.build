project('libpldm', ['c','cpp'],
    default_options: [
      'debug=true',
      'optimization=g',
      'warning_level=3',
      'werror=true',
      'cpp_std=c++20',
      'c_std=c17',
      'tests=' + (meson.is_subproject() ? 'disabled' : 'enabled'),
    ],
    version: '0.2.0',
    meson_version: '>=0.63.0',
)

add_project_arguments('-D_DEFAULT_SOURCE', language: ['c'])

compiler = meson.get_compiler('c')
conf = configuration_data()
if compiler.has_header('poll.h')
  conf.set('PLDM_HAS_POLL', 1)
endif

# ABI control
visible =  '__attribute__((visibility("default")))'
if get_option('abi').contains('deprecated')
  conf.set('LIBPLDM_ABI_DEPRECATED', visible)
  add_project_arguments('-DLIBPLDM_API_DEPRECATED', language: ['c', 'cpp'])
else
  conf.set('LIBPLDM_ABI_DEPRECATED', '')
endif
conf.set('LIBPLDM_ABI_STABLE', visible) # Always expose the stable symbols
if get_option('abi').contains('testing')
  conf.set('LIBPLDM_ABI_TESTING', visible)
  add_project_arguments('-DLIBPLDM_API_TESTING', language: ['c', 'cpp'])
else
  conf.set('LIBPLDM_ABI_TESTING', '')
endif

config = configure_file(output: 'config.h',
  configuration: conf
)

add_project_arguments('-include', '@0@'.format(config), language: 'c')

libpldm_sources = files()
subdir('src')

libpldm_include_dir = ['.', 'include', 'src']
libpldm_headers = files()
libpldm_transport_headers = files()

subdir('include/libpldm')

libpldm = library(
  'pldm',
   libpldm_sources,
   implicit_include_directories: false,
   include_directories: libpldm_include_dir,
   version: meson.project_version(),
   gnu_symbol_visibility: 'hidden',
   install: true
   )

install_headers(
  libpldm_headers,
  subdir:'libpldm'
  )

install_headers(
  libpldm_transport_headers,
  subdir:'libpldm/transport'
  )

libpldm_dep = declare_dependency(
  include_directories: libpldm_include_dir,
  link_with: libpldm)

import('pkgconfig').generate(
  name: 'libpldm',
  description: 'PLDM protocol encode/decode C lib',
  version: meson.project_version(),
  libraries: libpldm)

if get_option('tests').enabled()
  subdir('tests')

  c_suite = meson.get_compiler('c').get_id()
  cpp_suite = meson.get_compiler('cpp').get_id()

  if get_option('abi-compliance-check').allowed() and c_suite == cpp_suite and c_suite == 'gcc'
    host = host_machine.cpu_family()
    baseline_dump = meson.project_source_root() / 'abi' / host / '@0@.dump'.format(c_suite)

    abi_dumper = find_program('abi-dumper',
                              native: true,
                              required: get_option('abi-compliance-check'))
    abi_compliance_checker = find_program('abi-compliance-checker',
                                          native: true,
                                          required: get_option('abi-compliance-check'))

    test_abi_compliance = abi_dumper.found() and \
                          abi_compliance_checker.found() and \
                          import('fs').is_file(baseline_dump)

    if test_abi_compliance
      current_dump = custom_target('abi-dump',
                               input: libpldm,
                               output: 'current.dump',
                               command: [ abi_dumper,
                                          '-public-headers',
                                          meson.project_source_root() / 'include',
                                          '@INPUT@',
                                          '-o',
                                          '@OUTPUT@',
                                          '-lver',
                                          meson.project_version()])
      abi_compliance = custom_target('abi-compliance',
                                     input: [baseline_dump, current_dump],
                                     output: 'abi-compliance',
                                     command: [ abi_compliance_checker,
                                                '-l',
                                                meson.project_name(),
                                                '-old',
                                                '@INPUT0@',
                                                '-new',
                                                '@INPUT1@' ],
                                                build_by_default: true)
    endif
  endif
endif

install_subdir('instance-db',
               install_mode: 'r--r--r--',
               install_dir: get_option('datadir') / meson.project_name())
