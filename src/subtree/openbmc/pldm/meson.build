project('pldm', ['c', 'cpp'],
        version: '0.1', meson_version: '>=0.57.0',
        default_options: [
          'warning_level=3',
          'default_library=shared',
          'werror=true',
          'cpp_std=c++20',
          'buildtype=debugoptimized'
        ])

# Wno-psabi reduces the number of "Note:" messages when cross-compiling some STL
# stuff for ARM. See https://stackoverflow.com/questions/48149323/strange-gcc-warning-when-compiling-qt-project
# Basically, gcc 6 and gcc 7 are not ABI compatible, but since the whole OpenBMC
# project uses the same compiler, we can safely ignmore these info notes.
add_project_arguments('-Wno-psabi', language: 'cpp')


# Disable FORTIFY_SOURCE when compiling with no optimization
if(get_option('optimization') == '0')
  add_project_arguments('-U_FORTIFY_SOURCE',language:['cpp','c'])
  message('Disabling FORTIFY_SOURCE as optimization is set to 0')
endif

package_datadir = join_paths(get_option('prefix'), get_option('datadir'), meson.project_name())
package_localstatedir = join_paths(get_option('prefix'), get_option('localstatedir'), meson.project_name())

conf_data = configuration_data()
if get_option('libpldmresponder').enabled()
conf_data.set_quoted('BIOS_JSONS_DIR', join_paths(package_datadir, 'bios'))
conf_data.set_quoted('BIOS_TABLES_DIR', join_paths(package_localstatedir, 'bios'))
conf_data.set_quoted('PDR_JSONS_DIR', join_paths(package_datadir, 'pdr'))
conf_data.set_quoted('FRU_JSONS_DIR', join_paths(package_datadir, 'fru'))
conf_data.set_quoted('FRU_MASTER_JSON', join_paths(package_datadir, 'fru_master.json'))
conf_data.set_quoted('HOST_JSONS_DIR', join_paths(package_datadir, 'host'))
conf_data.set_quoted('EVENTS_JSONS_DIR', join_paths(package_datadir, 'events'))
add_project_arguments('-DLIBPLDMRESPONDER', language : ['c','cpp'])
endif
if get_option('softoff').enabled()
  conf_data.set('SOFTOFF_TIMEOUT_SECONDS', get_option('softoff-timeout-seconds'))
endif
if get_option('oem-ibm').enabled()
  conf_data.set_quoted('FILE_TABLE_JSON', join_paths(package_datadir, 'fileTable.json'))
  conf_data.set_quoted('LID_RUNNING_DIR', '/var/lib/phosphor-software-manager/hostfw/running')
  conf_data.set_quoted('LID_ALTERNATE_DIR', '/var/lib/phosphor-software-manager/hostfw/alternate')
  conf_data.set_quoted('LID_STAGING_DIR', '/var/lib/phosphor-software-manager/hostfw/staging')
  conf_data.set_quoted('LID_RUNNING_PATCH_DIR', '/usr/local/share/hostfw/running')
  conf_data.set_quoted('LID_ALTERNATE_PATCH_DIR', '/usr/local/share/hostfw/alternate')
  conf_data.set_quoted('LID_STAGING_DIR', '/var/lib/phosphor-software-manager/hostfw/staging')
  conf_data.set('DMA_MAXSIZE', get_option('oem-ibm-dma-maxsize'))
  add_project_arguments('-DOEM_IBM', language : 'c')
  add_project_arguments('-DOEM_IBM', language : 'cpp')
endif
conf_data.set('PLDM_VERBOSITY',get_option('verbosity'))
conf_data.set('NUMBER_OF_REQUEST_RETRIES', get_option('number-of-request-retries'))
conf_data.set('INSTANCE_ID_EXPIRATION_INTERVAL',get_option('instance-id-expiration-interval'))
conf_data.set('RESPONSE_TIME_OUT',get_option('response-time-out'))
if get_option('libpldm-only').disabled()
  conf_data.set_quoted('HOST_EID_PATH', join_paths(package_datadir, 'host_eid'))
endif
configure_file(output: 'config.h',
  configuration: conf_data
)

phosphor_dbus_interfaces = dependency(
  'phosphor-dbus-interfaces',
  fallback: ['phosphor-dbus-interfaces', 'phosphor_dbus_interfaces_dep'],
)
sdbusplus = dependency(
  'sdbusplus',
  fallback: ['sdbusplus', 'sdbusplus_dep'],
)
sdeventplus = dependency(
  'sdeventplus',
  fallback: ['sdeventplus', 'sdeventplus_dep'],
)

cpp = meson.get_compiler('cpp')

if cpp.has_header('nlohmann/json.hpp')
  nlohmann_json = declare_dependency()
else
  subproject('nlohmann-json')
  nlohmann_json = declare_dependency(
    include_directories: [
      'subprojects/nlohmann-json/single_include',
      'subprojects/nlohmann-json/single_include/nlohmann',
    ]
  )
endif

if cpp.has_header('CLI/CLI.hpp')
  CLI11_dep = declare_dependency()
else
  CLI11_dep = dependency(
    'CLI11',
    fallback: [ 'CLI11', 'CLI11_dep' ],
  )
endif

if cpp.has_header_symbol('function2/function2.hpp', 'fu2::unique_function')
  function2_dep = declare_dependency()
else
  subproject('function2')
  function2_dep = declare_dependency(
    include_directories: [
      'subprojects/function2/include/function2'
    ]
  )
endif

if get_option('oe-sdk').enabled()
  # Setup OE SYSROOT
  OECORE_TARGET_SYSROOT = run_command('sh', '-c', 'echo $OECORE_TARGET_SYSROOT').stdout().strip()
  if OECORE_TARGET_SYSROOT == ''
      error('Unable to get $OECORE_TARGET_SYSROOT, check your environment.')
  endif
  message('OE_SYSROOT: ' + OECORE_TARGET_SYSROOT)
  rpath = ':'.join([OECORE_TARGET_SYSROOT + '/lib', OECORE_TARGET_SYSROOT + '/usr/lib'])
  ld_so = run_command('sh', '-c', 'find ' + OECORE_TARGET_SYSROOT + '/lib/ld-*.so | sort -r -n | head -n1').stdout().strip()
  dynamic_linker = ['-Wl,-dynamic-linker,' + ld_so]
else
  dynamic_linker = []
endif

if get_option('tests').enabled()
    gtest = dependency('gtest', main: true, disabler: true, required: false)
    gmock = dependency('gmock', disabler: true, required: false)
    if not gtest.found() or not gmock.found()
        gtest_proj = import('cmake').subproject('googletest', required: false)
        if gtest_proj.found()
            gtest = declare_dependency(
                dependencies: [
                    dependency('threads'),
                    gtest_proj.dependency('gtest'),
                    gtest_proj.dependency('gtest_main'),
                ]
            )
            gmock = gtest_proj.dependency('gmock')
        else
            assert(
                not get_option('tests').enabled(),
                'Googletest is required if tests are enabled'
            )
        endif
    endif
endif

subdir('libpldm')

if get_option('libpldm-only').disabled()

libpldmutils_headers = ['.']
libpldmutils = library(
  'pldmutils',
  'common/utils.cpp',
  version: meson.project_version(),
  dependencies: [
      libpldm_dep,
      phosphor_dbus_interfaces,
      nlohmann_json,
      sdbusplus,
  ],
  install: true,
  include_directories: include_directories(libpldmutils_headers),
)

libpldmutils = declare_dependency(
  include_directories: include_directories(libpldmutils_headers),
  link_with: libpldmutils)

deps = [
  function2_dep,
  libpldm_dep,
  libpldmutils,
  nlohmann_json,
  sdbusplus,
  sdeventplus,
  phosphor_dbus_interfaces,
]

if get_option('libpldmresponder').enabled()
subdir('libpldmresponder')
deps += [
  libpldmresponder
]
endif

executable(
  'pldmd',
  'pldmd/pldmd.cpp',
  'pldmd/dbus_impl_requester.cpp',
  'pldmd/instance_id.cpp',
  'pldmd/dbus_impl_pdr.cpp',
  implicit_include_directories: false,
  dependencies: deps,
  install: true,
  install_dir: get_option('bindir'))

if get_option('systemd').enabled()
  systemd_system_unit_dir = dependency('systemd').get_variable(
          pkgconfig: 'systemdsystemunitdir')

  configure_file(
    copy: true,
    input: 'pldmd/service_files/pldmd.service',
    install: true,
    install_dir: systemd_system_unit_dir,
    output: 'pldmd.service',
  )

  configure_file(
    input: 'pldmd/verbosity/verbosity',
    output: 'pldm_verbosity',
    configuration: conf_data,
    install: true,
    install_dir: join_paths(get_option('sysconfdir'), 'default'))

  if get_option('oem-ibm').enabled()
    subdir('oem/ibm/service_files')
  endif
endif

subdir('pldmtool')

subdir('configurations')

if get_option('utilities').enabled()
  subdir('utilities')
endif

if get_option('softoff').enabled()
  subdir('softoff')
endif

if get_option('tests').enabled()
  subdir('common/test')
  subdir('host-bmc/test')
  subdir('requester/test')
  subdir('test')
endif

endif # pldm-only
