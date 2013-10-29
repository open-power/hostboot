# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2010,2013
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
#
# IBM_PROLOG_END_TAG

ROOTPATH = ..

SUBDIRS = kernel.d lib.d libc++.d sys.d usr.d build.d runtime.d
IMGS = hbicore hbicore_test hbirt hbirt_test

BASE_OBJECTS = string.o string_ext.o ctype.o math.o builtins.o stdio.o \
	       splaytree.o cxxtest_data.o sprintf.o crc32.o

ifdef HOSTBOOT_PROFILE
BASE_OBJECTS += gcov.o
endif

DIRECT_BOOT_OBJECTS = start.o kernel.o taskmgr.o cpumgr.o syscall.o \
                      scheduler.o exception.o vmmmgr.o timemgr.o \
                      syscall_stub.o syscall_task.o syscall_misc.o \
                      syscall_msg.o syscall_mmio.o syscall_time.o \
                      syscall_mm.o init_main.o vfs_main.o sync.o futexmgr.o \
                      ptmgr.o segmentmgr.o basesegment.o devicesegment.o \
                      block.o misc.o msghandler.o blockmsghdlr.o \
		      stacksegment.o softpatch_p8.o shutdown.o forceattn_p8.o \
		      terminate.o ipc.o machchk.o console.o spinlock.o \
		      heapmgr.o pagemgr.o barrier.o idebug.o intmsghandler.o \
		      deferred.o idletask.o vfs_init.o cpuid.o stdlib.o \
		      assert.o

BASE_MODULES = trace errl devicefw scom xscom initservice \
               secureboot_base pnor vfs

EXTENDED_MODULES = targeting ecmddatabuffer fapi hwp plat	\
                   extinitsvc istepdisp hwas fsi fsiscom i2c intr scan \
                   vpd dmi_training fapiporeve poreve util tracedaemon	\
                   sbe_centaur_init mc_config dram_training \
                   mdia mbox prdf bus_training \
                   activate_powerbus build_winkle_images \
                   core_activate dram_initialization edi_ei_initialization \
                   establish_system_smp occ\
                   nest_chiplets start_payload thread_activate slave_sbe \
                   attn runtime ibscom dump tod_init secureboot_ext \
                   devtree sbe

TESTCASE_MODULES = cxxtest testtrace testerrl testdevicefw testsyslib \
                   testscom testxscom testtargeting testinitservice testkernel \
                   testhwpf testecmddatabuffer initsvctesttask testcxxtest \
                   testpnor testi2c testfsi testvfs testhwas testintr testvpd \
                   testpore testutil testmbox testmdia testprdf testattn \
                   testscan testruntime testibscom testdump testsecureboot \
                   testfsiscom testrtloader testsbe

RUNTIME_OBJECTS = rt_start.o rt_main.o rt_console.o rt_stdlib.o rt_sync.o \
                  rt_assert.o rt_vfs.o rt_task.o

RUNTIME_MODULES = trace_rt errl_rt targeting_rt util_rt devicefw_rt \
		  xscom_rt scom_rt

RUNTIME_DATA_MODULES =
RUNTIME_TESTCASE_MODULES = cxxtest_rt testsyslib_rt testtargeting_rt \
                           testxscom_rt testerrl_rt testdevicefw_rt \
			   testscom_rt testutil_rt

RELOCATABLE_IMAGE_LDFLAGS = -pie --export-dynamic

hbicore_OBJECTS = ${BASE_OBJECTS} ${DIRECT_BOOT_OBJECTS}
hbicore_MODULES = ${BASE_MODULES}
hbicore_EXTENDED_MODULES = ${EXTENDED_MODULES}

# for PRDR_RULE_TABLE_TARGETS
include ${ROOTPATH}/src/usr/diag/prdf/common/prd_ruletable.mk

hbicore_DATA_MODULES =  sample.if p8.dmi.scom.if cen.dmi.scom.if \
                        p8.fbc.scom.if mbs_def.if mba_def.if cen_ddrphy.if \
                        p8.pe.phase1.scom.if p8.pe.phase2.scom.if \
                        ${PRDR_RULE_TABLE_TARGETS} \
                        p8.abus.scom.if p8.xbus.scom.if p8.mcs.scom.if \
                        p8.as.scom.if p8.nx.scom.if p8.dmi.custom.scom.if \
                        cen.dmi.custom.scom.if p8.abus.custom.scom.if \
                        p8.xbus.custom.scom.if p8.psi.scom.if p8.tpbridge.scom.if \
                        p8.cxa.scom.if p8.a_x_pci_dmi_fir.scom.if

hbicore_test_OBJECTS = ${hbicore_OBJECTS}
hbicore_test_MODULES = ${hbicore_MODULES}
hbicore_test_EXTENDED_MODULES = ${hbicore_EXTENDED_MODULES} ${TESTCASE_MODULES}
hbicore_test_DATA_MODULES = ${hbicore_DATA_MODULES} testdata \
                            test_signed_container

hbirt_OBJECTS = ${RUNTIME_OBJECTS} ${BASE_OBJECTS}
hbirt_MODULES = ${RUNTIME_MODULES}
hbirt_DATA_MODULES = ${RUNTIME_DATA_MODULES}
hbirt_LDFLAGS = ${RELOCATABLE_IMAGE_LDFLAGS}

hbirt_test_OBJECTS = ${hbirt_OBJECTS}
hbirt_test_MODULES = ${hbirt_MODULES} ${RUNTIME_TESTCASE_MODULES}
hbirt_test_DATA_MODULES = ${hbirt_DATA_MODULES}
hbirt_test_LDFLAGS = ${RELOCATABLE_IMAGE_LDFLAGS}

IMAGE_PASS_POST += buildpnor imgsizecheck

IMAGE_PASS_POST += $(IMGDIR)/hbotStringFile
CLEAN_TARGETS += $(IMGDIR)/hbotStringFile

include ${ROOTPATH}/config.mk

buildpnor: ${IMAGES}
	cd build/buildpnor/ && ${MAKE} buildpnor

$(IMGDIR)/hbotStringFile : $(IMAGES)
	$(ROOTPATH)/src/build/trace/tracehash_hb.pl -c -d $(ROOTPATH)/obj -s $@

.PHONY: imgsizecheck
#make sure base image isn't over 508k  (512K - 4K for secure header)
#PROCESS: get size of hbicore.bin, sort with respect to 508k (520192), then see if
#last word is 508k.  If not, the base image is too big.
MAX_BASE_SIZE = 520192
imgsizecheck: ${IMGDIR}/hbicore.bin
	$(if $(findstring $(shell (stat -c%s ${IMGDIR}/hbicore.bin; echo $(MAX_BASE_SIZE)) | sort -n | tail -n1), $(MAX_BASE_SIZE)),true, @echo ERROR: ${IMGDIR}/hbicore.bin too large.  Max allowed size is $(MAX_BASE_SIZE); false)
