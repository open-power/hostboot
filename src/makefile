# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2010,2021
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

SUBDIRS += bootloader.d
SUBDIRS += kernel.d
SUBDIRS += lib.d
SUBDIRS += libc++.d
SUBDIRS += sys.d
SUBDIRS += usr.d
SUBDIRS += build.d
SUBDIRS += runtime.d
SUBDIRS += securerom.d

# Reducing HB extended img size for VPO by disabling certain libs using
# CONFIG_VPO_COMPILE option
IMGS += hbibl
IMGS += hbicore
IMGS += hbicore_test
IMGS += hbirt
IMGS += hbirt_test
IMGS += securerom

BASE_OBJECTS += string.o
BASE_OBJECTS += string_ext.o
BASE_OBJECTS += string_utils.o
BASE_OBJECTS += ctype.o
BASE_OBJECTS += math.o
BASE_OBJECTS += builtins.o
BASE_OBJECTS += stdio.o
BASE_OBJECTS += splaytree.o
BASE_OBJECTS += cxxtest_data.o
BASE_OBJECTS += sprintf.o
BASE_OBJECTS += crc32.o
BASE_OBJECTS += utilmisc.o

BL_BASE_OBJECTS += bl_builtins.o

BOOTLDR_OBJECTS += bl_start.o
BOOTLDR_OBJECTS += bootloader.o
BOOTLDR_OBJECTS += bl_pnorAccess.o
BOOTLDR_OBJECTS += bl_pnor_utils.o
BOOTLDR_OBJECTS += bl_pnor_ecc.o
BOOTLDR_OBJECTS += bl_terminate.o
BOOTLDR_OBJECTS += forceattn_p9.o
BOOTLDR_OBJECTS += bl_string_utils.o
BOOTLDR_OBJECTS += rom_entry.o

SECUREROM_OBJECTS += ROM.o
SECUREROM_OBJECTS += ecverify.o
SECUREROM_OBJECTS += hw_utils.o
SECUREROM_OBJECTS += sha512.o
SECUREROM_OBJECTS += string_utils.o
SECUREROM_OBJECTS += rom_entry.o
SECUREROM_OBJECTS += secureromasm.o

DIRECT_BOOT_OBJECTS += start.o
DIRECT_BOOT_OBJECTS += kernel.o
DIRECT_BOOT_OBJECTS += taskmgr.o
DIRECT_BOOT_OBJECTS += cpumgr.o
DIRECT_BOOT_OBJECTS += syscall.o
DIRECT_BOOT_OBJECTS += doorbell.o
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
DIRECT_BOOT_OBJECTS += forceattn_p9.o
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
DIRECT_BOOT_OBJECTS += workitem.o
DIRECT_BOOT_OBJECTS += bltohbdatamgr.o
DIRECT_BOOT_OBJECTS += errno.o
ifdef HOSTBOOT_PROFILE
DIRECT_BOOT_OBJECTS += gcov.o
endif

BASE_MODULES += trace
BASE_MODULES += errl
BASE_MODULES += devicefw
BASE_MODULES += scom
BASE_MODULES += xscom
BASE_MODULES += initservice
BASE_MODULES += secureboot_base
BASE_MODULES += lpc
BASE_MODULES += $(if $(CONFIG_BMC_IPMI),ipmibase)
BASE_MODULES += pnor
BASE_MODULES += vfs
BASE_MODULES += $(if $(CONFIG_AST2400) || $(CONFIG_AST2500), sio)
BASE_MODULES += $(if $(CONFIG_CONSOLE),console)
BASE_MODULES += $(if $(CONFIG_MCTP)$(CONFIG_MCTP_TESTCASES),mctp)
BASE_MODULES += $(if $(CONFIG_PLDM)$(CONFIG_PLDM_TESTCASES),pldm_base)

# This is exported so that gcov knows the list of base modules to
# exclude from instrumentation. We can't simply export BASE_MODULES or
# else we get duplicate modules in the list which causes linker errors.
export BASE_MODULES_GCOV_BLACKLIST:=$(BASE_MODULES)

EXTENDED_MODULES += istep06
EXTENDED_MODULES += istep07
EXTENDED_MODULES += istep08
EXTENDED_MODULES += istep09
EXTENDED_MODULES += istep10
EXTENDED_MODULES += istep11
EXTENDED_MODULES += istep12
EXTENDED_MODULES += istep13
EXTENDED_MODULES += istep14
EXTENDED_MODULES += istep15
EXTENDED_MODULES += istep16
EXTENDED_MODULES += istep18
EXTENDED_MODULES += istep20
EXTENDED_MODULES += istep21
EXTENDED_MODULES += isteps
EXTENDED_MODULES += pm
EXTENDED_MODULES += targeting
EXTENDED_MODULES += fapi2
EXTENDED_MODULES += extinitsvc
EXTENDED_MODULES += istepdisp
EXTENDED_MODULES += hwas
EXTENDED_MODULES += fsi
EXTENDED_MODULES += fsiscom
EXTENDED_MODULES += i2c
EXTENDED_MODULES += intr
EXTENDED_MODULES += scan
EXTENDED_MODULES += vpd
EXTENDED_MODULES += util
EXTENDED_MODULES += tracedaemon
EXTENDED_MODULES += mbox
EXTENDED_MODULES += attn
EXTENDED_MODULES += prdf
EXTENDED_MODULES += $(if $(CONFIG_VPO_COMPILE),,mdia)
EXTENDED_MODULES += ibscom
EXTENDED_MODULES += thread_activate
EXTENDED_MODULES += $(if $(CONFIG_VPO_COMPILE),,dump)
EXTENDED_MODULES += $(if $(CONFIG_VPO_COMPILE),,runtime)
EXTENDED_MODULES += $(if $(CONFIG_TPMDD),secureboot_trusted,)
EXTENDED_MODULES += sbe
EXTENDED_MODULES += cen
EXTENDED_MODULES += imageprocs
EXTENDED_MODULES += sbeio
EXTENDED_MODULES += $(if $(CONFIG_HTMGT),htmgt)
EXTENDED_MODULES += $(if $(CONFIG_GPIODD),gpio,)
EXTENDED_MODULES += $(if $(CONFIG_CONSOLE_OUTPUT_ERRORDISPLAY),errldisplay)
EXTENDED_MODULES += $(if $(CONFIG_BMC_IPMI),ipmiext)
EXTENDED_MODULES += xz
EXTENDED_MODULES += p9_stop_util
EXTENDED_MODULES += isteps_mss
EXTENDED_MODULES += p9_cpuWkup
EXTENDED_MODULES += p9_phbPerst
EXTENDED_MODULES += $(if $(CONFIG_ENABLE_HDAT_IN_HOSTBOOT),hdat)
EXTENDED_MODULES += $(if $(CONFIG_SECUREBOOT),secureboot_ext)
EXTENDED_MODULES += tod
EXTENDED_MODULES += nestmemutils
EXTENDED_MODULES += fab_iovalid
EXTENDED_MODULES += isteps_nest
EXTENDED_MODULES += isteps_io
EXTENDED_MODULES += node_comm
EXTENDED_MODULES += $(if $(CONFIG_NVDIMM),nvdimm)
EXTENDED_MODULES += $(if $(CONFIG_UCD_FLASH_UPDATES),ucd)
EXTENDED_MODULES += $(if $(CONFIG_FSP_BUILD),,nvram)
EXTENDED_MODULES += mmio
EXTENDED_MODULES += smf
EXTENDED_MODULES += expaccess
EXTENDED_MODULES += expupd
EXTENDED_MODULES += fapiwrap
EXTENDED_MODULES += $(if $(CONFIG_PLDM)$(CONFIG_PLDM_TESTCASES),pldm_extended)

#***************************************
# Working test modules
#***************************************
TESTCASE_MODULES += cxxtest
TESTCASE_MODULES += testtrace
TESTCASE_MODULES += testdevicefw
TESTCASE_MODULES += initsvctesttask
TESTCASE_MODULES += testcxxtest
TESTCASE_MODULES += testpnor
TESTCASE_MODULES += testvfs
TESTCASE_MODULES += testutil
TESTCASE_MODULES += testscan
TESTCASE_MODULES += testsecureboot
TESTCASE_MODULES += testfsiscom
TESTCASE_MODULES += testlpc
#TODO: RTC 213102 to properly add & execute HTMGT test
#TESTCASE_MODULES += $(if $(CONFIG_HTMGT),testhtmgt)
TESTCASE_MODULES += testinitservice
TESTCASE_MODULES += testfsi
TESTCASE_MODULES += testibscom
TESTCASE_MODULES += testxscom
TESTCASE_MODULES += testkernel
TESTCASE_MODULES += testtargeting
TESTCASE_MODULES += testmemoize
TESTCASE_MODULES += testprdf
TESTCASE_MODULES += $(if $(CONFIG_VPO_COMPILE),,testmdia)
TESTCASE_MODULES += testpirformat
TESTCASE_MODULES += testi2c
TESTCASE_MODULES += testmbox
TESTCASE_MODULES += $(if $(CONFIG_EARLY_TESTCASES) ,,testrtloader)
TESTCASE_MODULES += testsbe
TESTCASE_MODULES += testsbeio
TESTCASE_MODULES += testerrl
TESTCASE_MODULES += testhwas
TESTCASE_MODULES += testvpd
TESTCASE_MODULES += testsyslib
TESTCASE_MODULES += testtlsmod
TESTCASE_MODULES += testscom
TESTCASE_MODULES += $(if $(CONFIG_VPO_COMPILE),,testruntime)
TESTCASE_MODULES += testintr
TESTCASE_MODULES += testfapi2
TESTCASE_MODULES += $(if $(CONFIG_EARLY_TESTCASES) && $(FSP_BUILD) ,,testnvram)
TESTCASE_MODULES += testsmf
TESTCASE_MODULES += testexpaccess
TESTCASE_MODULES += testexpupd
TESTCASE_MODULES += testmmio

#******************************************************************
#KNOWN ISSUES (I might let these run but there is something wrong)
#All of these are tracked by a RTC story
#******************************************************************

#TESTCASE_MODULES += $(if $(CONFIG_VPO_COMPILE),,testdump)  @fixme-RTC:180751
# @TODO DefecT: 1035550 Figure out why testattn is failing sometimes
#TESTCASE_MODULES += testattn

include ${ROOTPATH}/src/usr/runtime/common/common.mk

RUNTIME_OBJECTS += rt_start.o
RUNTIME_OBJECTS += rt_main.o
RUNTIME_OBJECTS += rt_console.o
RUNTIME_OBJECTS += rt_stdlib.o
RUNTIME_OBJECTS += rt_sync.o
RUNTIME_OBJECTS += rt_assert.o
RUNTIME_OBJECTS += rt_vfs.o
RUNTIME_OBJECTS += rt_task.o
RUNTIME_OBJECTS += rt_time.o
RUNTIME_OBJECTS += runtime_utils.o
ifdef HOSTBOOT_PROFILE
# we don't instrument runtime because we don't have space, but we
# still link this in because it uses some object files that need it
RUNTIME_OBJECTS += gcov.o
endif

RUNTIME_MODULES += trace_rt
RUNTIME_MODULES += errl_rt
RUNTIME_MODULES += targeting_rt
RUNTIME_MODULES += util_rt
RUNTIME_MODULES += devicefw_rt
RUNTIME_MODULES += xscom_rt
RUNTIME_MODULES += fsiscom_rt
RUNTIME_MODULES += ibscom_rt
RUNTIME_MODULES += scom_rt
RUNTIME_MODULES += vpd_rt
RUNTIME_MODULES += i2c_rt
RUNTIME_MODULES += $(if $(CONFIG_HTMGT),htmgt_rt)
RUNTIME_MODULES += $(if $(CONFIG_HBRT_PRD),attn_rt)
RUNTIME_MODULES += $(if $(CONFIG_HBRT_PRD),prdf_rt)
RUNTIME_MODULES += $(if $(CONFIG_BMC_IPMI),ipmi_rt)
RUNTIME_MODULES += pm_rt
RUNTIME_MODULES += pnor_rt
RUNTIME_MODULES += fapi2_rt
RUNTIME_MODULES += secureboot_rt
RUNTIME_MODULES += p9_cpuWkup
RUNTIME_MODULES += fsi_rt
RUNTIME_MODULES += sbeio_rt
RUNTIME_MODULES += tod_rt
RUNTIME_MODULES += hwplibs_rt
RUNTIME_MODULES += imageprocs_rt
RUNTIME_MODULES += $(if $(CONFIG_NVDIMM),nvdimm_rt)
RUNTIME_MODULES += mss_rt
RUNTIME_MODULES += expaccess_rt
RUNTIME_MODULES += mmio_rt

# This is exported so that gcov knows the list of runtime modules to
# exclude from instrumentation. We can't simply export RUNTIME_MODULES or
# else we get duplicate modules in the list which causes linker errors.
export RUNTIME_MODULES_GCOV_BLACKLIST:=$(RUNTIME_MODULES)

RUNTIME_DATA_MODULES +=

RUNTIME_TESTCASE_MODULES += cxxtest_rt
RUNTIME_TESTCASE_MODULES += testsyslib_rt
RUNTIME_TESTCASE_MODULES += testxscom_rt
RUNTIME_TESTCASE_MODULES += testerrl_rt
RUNTIME_TESTCASE_MODULES += testdevicefw_rt
RUNTIME_TESTCASE_MODULES += testscom_rt
RUNTIME_TESTCASE_MODULES += testutil_rt
RUNTIME_TESTCASE_MODULES += testvpd_rt
RUNTIME_TESTCASE_MODULES += $(if $(CONFIG_HBRT_PRD),testprdf_rt)
RUNTIME_TESTCASE_MODULES += $(if $(CONFIG_HBRT_PRD),testattn_rt)
RUNTIME_TESTCASE_MODULES += $(if $(CONFIG_BMC_IPMI),testipmi_rt)
RUNTIME_TESTCASE_MODULES += testpnor_rt
RUNTIME_TESTCASE_MODULES += testfapi2_rt
RUNTIME_TESTCASE_MODULES += testsecureboot_rt
RUNTIME_TESTCASE_MODULES += testtargeting_rt
RUNTIME_TESTCASE_MODULES += testsbeio_rt
RUNTIME_TESTCASE_MODULES += testpm_rt
RUNTIME_TESTCASE_MODULES += testrsvdtracebuf_rt
RUNTIME_TESTCASE_MODULES += testexpaccess_rt

RELOCATABLE_IMAGE_LDFLAGS = -pie --export-dynamic

hbibl_OBJECTS += ${BL_BASE_OBJECTS}
hbibl_OBJECTS += ${BOOTLDR_OBJECTS}
hbibl_LDFILE = bootloader.ld
hbibl_NO_RELOCATION = 1

hbicore_OBJECTS += ${BASE_OBJECTS} tls.o
hbicore_OBJECTS += ${DIRECT_BOOT_OBJECTS}
hbicore_MODULES += ${BASE_MODULES}
hbicore_EXTENDED_MODULES += ${EXTENDED_MODULES}
hbicore_LDFILE = kernel.ld

securerom_OBJECTS += ${SECUREROM_OBJECTS}
securerom_LDFILE = securerom.ld
securerom_NO_RELOCATION = 1

# for PRDR_RULE_TABLE_TARGETS
include ${ROOTPATH}/src/usr/diag/prdf/common/rule/prdf_rule.mk

hbicore_DATA_MODULES += ${prd_rule_prf_targets}

hbicore_test_OBJECTS += ${hbicore_OBJECTS}
hbicore_test_MODULES += ${hbicore_MODULES}
hbicore_test_EXTENDED_MODULES += ${hbicore_EXTENDED_MODULES}
hbicore_test_EXTENDED_MODULES += ${TESTCASE_MODULES}
hbicore_test_DATA_MODULES += ${hbicore_DATA_MODULES}
hbicore_test_DATA_MODULES += testdata
ifndef SKIP_BINARY_FILES
hbicore_test_DATA_MODULES += secureboot_signed_container
hbicore_test_DATA_MODULES += secureboot_hash_page_table_container
endif

hbicore_test_LDFILE = kernel.ld

hbirt_OBJECTS += ${RUNTIME_OBJECTS}
hbirt_OBJECTS += ${BASE_OBJECTS} tlsrt.o
hbirt_MODULES += ${RUNTIME_MODULES}
hbirt_DATA_MODULES += ${RUNTIME_DATA_MODULES}
hbirt_DATA_MODULES += $(if $(CONFIG_HBRT_PRD),$(prd_rule_prf_targets))
hbirt_LDFLAGS = ${RELOCATABLE_IMAGE_LDFLAGS}
hbirt_LDFILE = kernel.ld

hbirt_test_OBJECTS += ${hbirt_OBJECTS}
hbirt_test_MODULES += ${hbirt_MODULES}
hbirt_test_MODULES += ${RUNTIME_TESTCASE_MODULES}
hbirt_test_DATA_MODULES += ${hbirt_DATA_MODULES}
hbirt_test_LDFLAGS = ${RELOCATABLE_IMAGE_LDFLAGS}
hbirt_test_LDFILE = kernel.ld

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
#make sure base image isn't over 904K (908K - 4K for secure header)
#PROCESS: get size of hbicore.bin, sort with respect to 904k (925696), then see
# if last word is 904k.  If not, the base image is too big.
#NOTE: HBB size is 1MB in pnor layout. 908K is the size without ECC rounded down
#      to the nearest 4K page.
#make sure bootloader image isn't over 32k (32K = 12K for exception vectors +
#20K for bootloader code and data)
#PROCESS: get size of hbibl.bin, sort with respect to 32k (32768),
#then see if last word is 32k.  If not, the bootloader image is too big.

MAX_BASE_SIZE = 925696
MAX_BTLDR_SIZE = 32768

imgsizecheck: ${IMGDIR}/hbicore.bin ${IMGDIR}/hbibl.bin
	$(if $(findstring $(shell (stat -c%s ${IMGDIR}/hbicore.bin; echo $(MAX_BASE_SIZE)) | sort -n | tail -n1), $(MAX_BASE_SIZE)),true, @echo ERROR: ${IMGDIR}/hbicore.bin too large.  Max allowed size is $(MAX_BASE_SIZE); false)
	$(if $(findstring $(shell (stat -c%s ${IMGDIR}/hbibl.bin; echo $(MAX_BTLDR_SIZE)) | sort -n | tail -n1), $(MAX_BTLDR_SIZE)),true, @echo ERROR: ${IMGDIR}/hbibl.bin too large.  Max allowed size is $(MAX_BTLDR_SIZE); false)
