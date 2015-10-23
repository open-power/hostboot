# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2010,2015
# [+] Google Inc.
# [+] International Business Machines Corp.
#
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
#
# IBM_PROLOG_END_TAG

ROOTPATH = ..

SUBDIRS += kernel.d
SUBDIRS += lib.d
SUBDIRS += libc++.d
SUBDIRS += sys.d
SUBDIRS += usr.d
SUBDIRS += build.d
SUBDIRS += runtime.d

# Reducing HB extended img size for VPO by disabling certain libs using
# CONFIG_VPO_COMPILE option
IMGS += hbicore
IMGS += hbicore_test
IMGS += hbirt
IMGS += hbirt_test

BASE_OBJECTS += string.o
BASE_OBJECTS += string_ext.o
BASE_OBJECTS += ctype.o
BASE_OBJECTS += math.o
BASE_OBJECTS += builtins.o
BASE_OBJECTS += stdio.o
BASE_OBJECTS += splaytree.o
BASE_OBJECTS += cxxtest_data.o
BASE_OBJECTS += sprintf.o
BASE_OBJECTS += crc32.o
BASE_OBJECTS += utilmisc.o

ifdef HOSTBOOT_PROFILE
BASE_OBJECTS += gcov.o
endif
DIRECT_BOOT_OBJECTS += start.o
DIRECT_BOOT_OBJECTS += kernel.o
DIRECT_BOOT_OBJECTS += taskmgr.o
DIRECT_BOOT_OBJECTS += cpumgr.o
DIRECT_BOOT_OBJECTS += syscall.o
DIRECT_BOOT_OBJECTS += scheduler.o
DIRECT_BOOT_OBJECTS += exception.o
DIRECT_BOOT_OBJECTS += vmmmgr.o
DIRECT_BOOT_OBJECTS += timemgr.o
DIRECT_BOOT_OBJECTS += syscall_stub.o
DIRECT_BOOT_OBJECTS += syscall_task.o
DIRECT_BOOT_OBJECTS += syscall_misc.o
DIRECT_BOOT_OBJECTS += syscall_msg.o
DIRECT_BOOT_OBJECTS += syscall_mmio.o
DIRECT_BOOT_OBJECTS += syscall_time.o
DIRECT_BOOT_OBJECTS += syscall_mm.o
DIRECT_BOOT_OBJECTS += init_main.o
DIRECT_BOOT_OBJECTS += vfs_main.o
DIRECT_BOOT_OBJECTS += sync.o
DIRECT_BOOT_OBJECTS += futexmgr.o
DIRECT_BOOT_OBJECTS += ptmgr.o
DIRECT_BOOT_OBJECTS += segmentmgr.o
DIRECT_BOOT_OBJECTS += basesegment.o
DIRECT_BOOT_OBJECTS += devicesegment.o
DIRECT_BOOT_OBJECTS += block.o
DIRECT_BOOT_OBJECTS += misc.o
DIRECT_BOOT_OBJECTS += msghandler.o
DIRECT_BOOT_OBJECTS += blockmsghdlr.o
DIRECT_BOOT_OBJECTS += stacksegment.o
DIRECT_BOOT_OBJECTS += softpatch_p8.o
DIRECT_BOOT_OBJECTS += shutdown.o
DIRECT_BOOT_OBJECTS += forceattn_p8.o
DIRECT_BOOT_OBJECTS += terminate.o
DIRECT_BOOT_OBJECTS += ipc.o
DIRECT_BOOT_OBJECTS += machchk.o
DIRECT_BOOT_OBJECTS += console.o
DIRECT_BOOT_OBJECTS += spinlock.o
DIRECT_BOOT_OBJECTS += heapmgr.o
DIRECT_BOOT_OBJECTS += pagemgr.o
DIRECT_BOOT_OBJECTS += barrier.o
DIRECT_BOOT_OBJECTS += idebug.o
DIRECT_BOOT_OBJECTS += intmsghandler.o
DIRECT_BOOT_OBJECTS += deferred.o
DIRECT_BOOT_OBJECTS += idletask.o
DIRECT_BOOT_OBJECTS += vfs_init.o
DIRECT_BOOT_OBJECTS += cpuid.o
DIRECT_BOOT_OBJECTS += stdlib.o
DIRECT_BOOT_OBJECTS += assert.o

BASE_MODULES += trace
BASE_MODULES += errl
BASE_MODULES += devicefw
BASE_MODULES += scom
BASE_MODULES += xscom
BASE_MODULES += initservice
BASE_MODULES += secureboot_base
BASE_MODULES += lpc
BASE_MODULES += pnor
BASE_MODULES += vfs
BASE_MODULES += $(if $(CONFIG_AST2400), sio)

EXTENDED_MODULES += istep06
EXTENDED_MODULES += istep07
EXTENDED_MODULES += istep08
EXTENDED_MODULES += istep09
EXTENDED_MODULES += istep10
EXTENDED_MODULES += targeting
EXTENDED_MODULES += ecmddatabuffer
EXTENDED_MODULES += fapi
EXTENDED_MODULES += hwp
EXTENDED_MODULES += plat
EXTENDED_MODULES += extinitsvc
EXTENDED_MODULES += istepdisp
EXTENDED_MODULES += hwas
EXTENDED_MODULES += fsi
EXTENDED_MODULES += fsiscom
EXTENDED_MODULES += i2c
EXTENDED_MODULES += intr
EXTENDED_MODULES += scan
EXTENDED_MODULES += vpd
EXTENDED_MODULES += dmi_training
EXTENDED_MODULES += $(if $(CONFIG_VPO_COMPILE),,fapiporeve)
EXTENDED_MODULES += poreve
EXTENDED_MODULES += util
EXTENDED_MODULES += tracedaemon
EXTENDED_MODULES += $(if $(CONFIG_VPO_COMPILE),,sbe_centaur_init)
EXTENDED_MODULES += $(if $(CONFIG_VPO_COMPILE),,dram_training)
EXTENDED_MODULES += $(if $(CONFIG_VPO_COMPILE),,mdia)
EXTENDED_MODULES += mbox
EXTENDED_MODULES += prdf
EXTENDED_MODULES += bus_training
EXTENDED_MODULES += $(if $(CONFIG_VPO_COMPILE),,activate_powerbus)
EXTENDED_MODULES += build_winkle_images
EXTENDED_MODULES += core_activate
EXTENDED_MODULES += $(if $(CONFIG_VPO_COMPILE),,dram_initialization)
EXTENDED_MODULES += edi_ei_initialization
EXTENDED_MODULES += establish_system_smp
EXTENDED_MODULES += occ
EXTENDED_MODULES += nest_chiplets
EXTENDED_MODULES += $(if $(CONFIG_VPO_COMPILE),,start_payload)
EXTENDED_MODULES += thread_activate
EXTENDED_MODULES += slave_sbe
EXTENDED_MODULES += attn
EXTENDED_MODULES += $(if $(CONFIG_VPO_COMPILE),,runtime)
EXTENDED_MODULES += ibscom
EXTENDED_MODULES += $(if $(CONFIG_VPO_COMPILE),,dump)
EXTENDED_MODULES += $(if $(CONFIG_VPO_COMPILE),,tod_init)
EXTENDED_MODULES += secureboot_ext
EXTENDED_MODULES += $(if $(CONFIG_TPMDD),secureboot_trusted,)
EXTENDED_MODULES += devtree
EXTENDED_MODULES += sbe
EXTENDED_MODULES += proc_hwreconfig
EXTENDED_MODULES += pstates
EXTENDED_MODULES += $(if $(CONFIG_HTMGT),htmgt)
EXTENDED_MODULES += $(if $(CONFIG_GPIODD),gpio,)
EXTENDED_MODULES += $(if $(CONFIG_CONSOLE),console)
EXTENDED_MODULES += $(if $(CONFIG_CONSOLE_OUTPUT_ERRORDISPLAY),errldisplay)
EXTENDED_MODULES += $(if $(CONFIG_BMC_IPMI),ipmi)
EXTENDED_MODULES += secure_boot

TESTCASE_MODULES += cxxtest
TESTCASE_MODULES += testtrace
TESTCASE_MODULES += testerrl
TESTCASE_MODULES += testdevicefw
TESTCASE_MODULES += testsyslib
TESTCASE_MODULES += testscom
TESTCASE_MODULES += testxscom
TESTCASE_MODULES += testtargeting
TESTCASE_MODULES += testinitservice
TESTCASE_MODULES += testkernel
TESTCASE_MODULES += testhwpf
TESTCASE_MODULES += testecmddatabuffer
TESTCASE_MODULES += initsvctesttask
TESTCASE_MODULES += testcxxtest
TESTCASE_MODULES += testpnor
TESTCASE_MODULES += testi2c
TESTCASE_MODULES += testfsi
TESTCASE_MODULES += testvfs
TESTCASE_MODULES += testhwas
TESTCASE_MODULES += testintr
TESTCASE_MODULES += testvpd
TESTCASE_MODULES += testpore
TESTCASE_MODULES += testutil
TESTCASE_MODULES += testmbox
TESTCASE_MODULES += $(if $(CONFIG_VPO_COMPILE),,testmdia)
TESTCASE_MODULES += testprdf
TESTCASE_MODULES += testattn
TESTCASE_MODULES += testscan
TESTCASE_MODULES += $(if $(CONFIG_VPO_COMPILE),,testruntime)
TESTCASE_MODULES += testibscom
TESTCASE_MODULES += $(if $(CONFIG_VPO_COMPILE),,testdump)
TESTCASE_MODULES += $(if $(CONFIG_VPO_COMPILE),,testsecureboot)
TESTCASE_MODULES += $(if $(CONFIG_TPMDD),testtrusted)
TESTCASE_MODULES += testfsiscom
#FIXME: RTC 129630
#TESTCASE_MODULES += testrtloader
#TESTCASE_MODULES += testsbe
#TESTCASE_MODULES += testlpc
TESTCASE_MODULES += $(if $(CONFIG_HTMGT),testhtmgt)
TESTCASE_MODULES += $(if $(CONFIG_AST2400), testsio)

RUNTIME_OBJECTS += rt_start.o
RUNTIME_OBJECTS += rt_main.o
RUNTIME_OBJECTS += rt_console.o
RUNTIME_OBJECTS += rt_stdlib.o
RUNTIME_OBJECTS += rt_sync.o
RUNTIME_OBJECTS += rt_assert.o
RUNTIME_OBJECTS += rt_vfs.o
RUNTIME_OBJECTS += rt_task.o
RUNTIME_OBJECTS += rt_time.o

RUNTIME_MODULES += trace_rt
RUNTIME_MODULES += errl_rt
RUNTIME_MODULES += targeting_rt
RUNTIME_MODULES += util_rt
RUNTIME_MODULES += devicefw_rt
RUNTIME_MODULES += xscom_rt
RUNTIME_MODULES += scom_rt
RUNTIME_MODULES += vpd_rt
RUNTIME_MODULES += i2c_rt
RUNTIME_MODULES += ecmddatabuffer
RUNTIME_MODULES += fapi_rt
RUNTIME_MODULES += hwp_rt
RUNTIME_MODULES += plat_rt
RUNTIME_MODULES += build_winkle_images_rt
RUNTIME_MODULES += occ_rt
RUNTIME_MODULES += pstates
RUNTIME_MODULES += $(if $(CONFIG_HTMGT),htmgt_rt)
RUNTIME_MODULES += $(if $(CONFIG_HBRT_PRD),bus_training_rt)
RUNTIME_MODULES += $(if $(CONFIG_HBRT_PRD),attn_rt)
RUNTIME_MODULES += $(if $(CONFIG_HBRT_PRD),prdf_rt)
RUNTIME_MODULES += $(if $(CONFIG_BMC_IPMI),ipmi_rt)
RUNTIME_MODULES += pnor_rt

RUNTIME_DATA_MODULES +=
RUNTIME_TESTCASE_MODULES += cxxtest_rt
RUNTIME_TESTCASE_MODULES += testsyslib_rt
RUNTIME_TESTCASE_MODULES += testtargeting_rt
RUNTIME_TESTCASE_MODULES += testxscom_rt
RUNTIME_TESTCASE_MODULES += testerrl_rt
RUNTIME_TESTCASE_MODULES += testdevicefw_rt
RUNTIME_TESTCASE_MODULES += testscom_rt
RUNTIME_TESTCASE_MODULES += testutil_rt
RUNTIME_TESTCASE_MODULES += testvpd_rt
RUNTIME_TESTCASE_MODULES += testhwpf_rt
RUNTIME_TESTCASE_MODULES += $(if $(CONFIG_HBRT_PRD),testprdf_rt)
RUNTIME_TESTCASE_MODULES += $(if $(CONFIG_HBRT_PRD),testattn_rt)
RUNTIME_TESTCASE_MODULES += $(if $(CONFIG_BMC_IPMI),testipmi_rt)
RUNTIME_TESTCASE_MODULES += testpnor_rt

RELOCATABLE_IMAGE_LDFLAGS = -pie --export-dynamic

hbicore_OBJECTS += ${BASE_OBJECTS}
hbicore_OBJECTS += ${DIRECT_BOOT_OBJECTS}
hbicore_MODULES += ${BASE_MODULES}
hbicore_EXTENDED_MODULES += ${EXTENDED_MODULES}

# for PRDR_RULE_TABLE_TARGETS
include ${ROOTPATH}/src/usr/diag/prdf/common/framework/rule/prdf_rule.mk

hbicore_DATA_MODULES += sample.if
hbicore_DATA_MODULES += p8.dmi.scom.if
hbicore_DATA_MODULES += cen.dmi.scom.if
hbicore_DATA_MODULES += p8.fbc.scom.if
hbicore_DATA_MODULES += mbs_def.if
hbicore_DATA_MODULES += mba_def.if
hbicore_DATA_MODULES += cen_ddrphy.if
hbicore_DATA_MODULES += p8.pe.phase1.scom.if
hbicore_DATA_MODULES += p8.pe.phase2.scom.if
hbicore_DATA_MODULES += ${prd_rule_prf_targets}
hbicore_DATA_MODULES += p8.abus.scom.if
hbicore_DATA_MODULES += p8.xbus.scom.if
hbicore_DATA_MODULES += p8.mcs.scom.if
hbicore_DATA_MODULES += p8.as.scom.if
hbicore_DATA_MODULES += p8.nx.scom.if
hbicore_DATA_MODULES += p8.dmi.custom.scom.if
hbicore_DATA_MODULES += cen.dmi.custom.scom.if
hbicore_DATA_MODULES += p8.abus.custom.scom.if
hbicore_DATA_MODULES += p8.xbus.custom.scom.if
hbicore_DATA_MODULES += p8.psi.scom.if
hbicore_DATA_MODULES += p8.tpbridge.scom.if
hbicore_DATA_MODULES += p8.cxa.scom.if
hbicore_DATA_MODULES += p8.a_x_pci_dmi_fir.scom.if
hbicore_DATA_MODULES += p8.npu.scom.if

hbicore_test_OBJECTS += ${hbicore_OBJECTS}
hbicore_test_MODULES += ${hbicore_MODULES}
hbicore_test_EXTENDED_MODULES += ${hbicore_EXTENDED_MODULES}
hbicore_test_EXTENDED_MODULES += ${TESTCASE_MODULES}
hbicore_test_DATA_MODULES += ${hbicore_DATA_MODULES}
hbicore_test_DATA_MODULES += testdata
ifndef SKIP_BINARY_FILES
hbicore_test_DATA_MODULES += test_signed_container
endif

hbirt_OBJECTS += ${RUNTIME_OBJECTS}
hbirt_OBJECTS += ${BASE_OBJECTS}
hbirt_MODULES += ${RUNTIME_MODULES}
hbirt_DATA_MODULES += ${RUNTIME_DATA_MODULES}
hbirt_DATA_MODULES += $(if $(CONFIG_HBRT_PRD),$(prd_rule_prf_targets))
hbirt_LDFLAGS = ${RELOCATABLE_IMAGE_LDFLAGS}

hbirt_test_OBJECTS += ${hbirt_OBJECTS}
hbirt_test_MODULES += ${hbirt_MODULES}
hbirt_test_MODULES += ${RUNTIME_TESTCASE_MODULES}
hbirt_test_DATA_MODULES += ${hbirt_DATA_MODULES}
hbirt_test_LDFLAGS = ${RELOCATABLE_IMAGE_LDFLAGS}

IMAGE_PASS_POST += buildpnor
IMAGE_PASS_POST += imgsizecheck

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
