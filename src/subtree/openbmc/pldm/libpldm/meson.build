project('libpldm', ['c','cpp'],
    default_options: [
      'buildtype=debugoptimized',
      'warning_level=3',
      'werror=true',
      'cpp_std=c++20',
      'c_std=c17',
      'tests=' + (meson.is_subproject() ? 'disabled' : 'enabled'),
    ],
    version: '0.2.0',
    meson_version: '>=0.63.0',
)

add_project_arguments('-D_DEFAULT_SOURCE',language:['c'])

libpldm_sources = files()
subdir('src')

libpldm_include_dir = ['include', 'src']
libpldm_headers = files()
libpldm_transport_headers = files()

subdir('include/libpldm')

libpldm = library(
  'pldm',
   libpldm_sources,
   implicit_include_directories: false,
   include_directories: libpldm_include_dir,
   version: meson.project_version(),
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

compiler = meson.get_compiler('c')
conf = configuration_data()
if compiler.has_header('poll.h')
  conf.set('PLDM_HAS_POLL', 1)
endif
configure_file(output: 'config.h',
  configuration: conf
)

if get_option('tests').enabled()
  subdir('tests')
endif

install_subdir('instance-db',
               install_mode: 'r--r--r--',
               install_dir: get_option('datadir') / meson.project_name())
