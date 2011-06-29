ROOTPATH = ..

SUBDIRS = kernel.d lib.d libc++.d sys.d usr.d build.d
IMGS = hbicore hbicore_test
EXTRA_LIDS = dslid

BASE_OBJECTS = console.o spinlock.o string.o stdlib.o assert.o stdio.o \
               builtins.o vfs_init.o heapmgr.o pagemgr.o

DIRECT_BOOT_OBJECTS = start.o kernel.o taskmgr.o cpumgr.o syscall.o \
                      scheduler.o exception.o vmmmgr.o timemgr.o \
                      syscall_stub.o syscall_task.o \
                      syscall_msg.o syscall_mmio.o syscall_time.o \
                      init_main.o vfs_main.o sync.o futexmgr.o \
                      ptmgr.o

RUNTIME_OBJECTS =

BASE_MODULES = trace errl devicefw scom xscom initservice taskargs
EXTENDED_MODULES = targeting ecmddatabuffer hwpf fapi hwp plat extinitsvc

DIRECT_BOOT_MODULES = example
RUNTIME_MODULES =
TESTCASE_MODULES = cxxtest testerrl testdevicefw testsyslib \
                   testscom testxscom testtargeting testinitservice testkernel \
                   testhwpf testecmddatabuffer tasktest2

RELOCATABLE_IMAGE_LDFLAGS = -pie --export-dynamic

hbicore_OBJECTS = ${BASE_OBJECTS} ${DIRECT_BOOT_OBJECTS}
hbicore_MODULES = ${BASE_MODULES} ${EXTENDED_MODULES} ${DIRECT_BOOT_MODULES}
hbicore_LIDNUMBER = 80f00100

hbicore_test_OBJECTS = ${hbicore_OBJECTS}
hbicore_test_MODULES = ${hbicore_MODULES} ${TESTCASE_MODULES}

#halruntime_OBJECTS = ${BASE_OBJECTS} ${RUNTIME_OBJECTS}
#halruntime_MODULES = ${BASE_MODULES} ${EXTENDED_MODULES} ${RUNTIME_MODULES}
#halruntime_LDFLAGS = ${RELOCATABLE_IMAGE_LDFLAGS}
#halruntime_LIDNUMBER = 80f00101

dslid_LIDNUMBER = 80f001fe

include ${ROOTPATH}/config.mk
