gtest_dep = dependency('gtest', main: true, disabler: true, required: false)
gmock_dep = dependency('gmock', disabler: true, required: false)
if not gtest_dep.found() or not gmock_dep.found()
    gtest_proj = import('cmake').subproject('googletest', required: true)
    gtest_dep = declare_dependency(
        dependencies: [
            dependency('threads'),
            gtest_proj.dependency('gtest'),
            gtest_proj.dependency('gtest_main'),
        ],
    )
    gmock_dep = gtest_proj.dependency('gmock')
endif

test_include_dirs = [libpldm_include_dir, include_directories('../src')]

tests = ['instance-id', 'msgbuf', 'responder', 'utils']

subdir('dsp')

# The 'test' transport APIs will never be marked stable as they are just for
# testing.
if get_option('abi').contains('testing')
    subdir('transport')
endif

if get_option('oem-ibm').allowed()
    subdir('oem/ibm')
endif

if get_option('oem-meta').allowed()
    subdir('oem/meta')
endif

foreach t : tests
    test(
        t,
        executable(
            t.underscorify(),
            t + '.cpp',
            implicit_include_directories: false,
            include_directories: test_include_dirs,
            dependencies: [libpldm_dep, gtest_dep, gmock_dep],
        ),
        workdir: meson.current_source_dir(),
    )
endforeach

test(
    'msgbuf_generic',
    executable(
        'msgbuf_generic',
        'msgbuf_generic.c',
        implicit_include_directories: false,
        include_directories: test_include_dirs,
    ),
)
