#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/makefile $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2010 - 2011
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END

ROOTPATH = ..

SUBDIRS = kernel.d lib.d libc++.d sys.d usr.d build.d
IMGS = hbicore hbicore_test
EXTRA_LIDS = dslid

BASE_OBJECTS = console.o spinlock.o string.o string_ext.o stdlib.o ctype.o \
               assert.o stdio.o builtins.o vfs_init.o heapmgr.o pagemgr.o \
               math.o barrier.o idebug.o intmsghandler.o idletask.o

ifdef HOSTBOOT_PROFILE
BASE_OBJECTS += gcov.o
endif

DIRECT_BOOT_OBJECTS = start.o kernel.o taskmgr.o cpumgr.o syscall.o \
                      scheduler.o exception.o vmmmgr.o timemgr.o \
                      syscall_stub.o syscall_task.o syscall_misc.o \
                      syscall_msg.o syscall_mmio.o syscall_time.o \
                      syscall_mm.o init_main.o vfs_main.o sync.o futexmgr.o \
                      ptmgr.o segmentmgr.o basesegment.o devicesegment.o \
                      block.o cxxtest_data.o cpuid.o misc.o msghandler.o \
                      blockmsghdlr.o stacksegment.o softpatch_p7.o

## STUB_TESTCASE_OBJECT = cxxtest_stub.o

RUNTIME_OBJECTS =

BASE_MODULES = trace errl devicefw scom xscom initservice taskargs \
               pnor vfs mbox

EXTENDED_MODULES = targeting ecmddatabuffer fapi hwp plat 	\
                   extinitsvc istepdisp hwas fsi fsiscom i2c intr \
		           spd dmi_training fapiporeve poreve util	\
		           sbe_centaur_init mc_init dram_training \
                           mdia

DIRECT_BOOT_MODULES = example
RUNTIME_MODULES =

TESTCASE_MODULES = cxxtest testerrl testdevicefw testsyslib \
                   testscom testxscom testtargeting testinitservice testkernel \
                   testhwpf testecmddatabuffer initsvctasktest2 testcxxtest \
                   testpnor testi2c testfsi testvfs testhwas testintr testspd \
                   testpore testutil testmbox testmdia

RELOCATABLE_IMAGE_LDFLAGS = -pie --export-dynamic

hbicore_OBJECTS = ${BASE_OBJECTS} ${DIRECT_BOOT_OBJECTS} ${STUB_TESTCASE_OBJECT}
hbicore_MODULES = ${BASE_MODULES} ${DIRECT_BOOT_MODULES}
hbicore_EXTENDED_MODULES = ${EXTENDED_MODULES}
#@todo - Temporary workaround
# The sbe_pnor.bin is manually built from CVS SBE procedure files in CVS then copy
# into HostBoot for now.  HostBoot build team will have a process of building sbe_pnor
# image later.
hbicore_DATA_MODULES =  sample.if dimmspd.dat sbe_pnor.bin

hbicore_LIDNUMBER = 80f00100

hbicore_test_OBJECTS = ${BASE_OBJECTS} ${DIRECT_BOOT_OBJECTS}
hbicore_test_MODULES = ${hbicore_MODULES}
hbicore_test_EXTENDED_MODULES = ${hbicore_EXTENDED_MODULES} ${TESTCASE_MODULES}
hbicore_test_DATA_MODULES = ${hbicore_DATA_MODULES} testdata

#halruntime_OBJECTS = ${BASE_OBJECTS} ${RUNTIME_OBJECTS}
#halruntime_MODULES = ${BASE_MODULES} ${EXTENDED_MODULES} ${RUNTIME_MODULES}
#halruntime_LDFLAGS = ${RELOCATABLE_IMAGE_LDFLAGS}
#halruntime_LIDNUMBER = 80f00101

dslid_LIDNUMBER = 80f001fe

include ${ROOTPATH}/config.mk
