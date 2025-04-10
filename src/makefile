# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2010,2025
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
BASE_OBJECTS += cstring.o
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
BOOTLDR_OBJECTS += bl_console.o
BOOTLDR_OBJECTS += hbbl_plat_hw_access.o
BOOTLDR_OBJECTS += hbbl_plat_utils.o
BOOTLDR_OBJECTS += bl_xscom.o
BOOTLDR_OBJECTS += bl_tpm_spidd.o
BOOTLDR_OBJECTS += p10_sbe_spi_cmd.o
BOOTLDR_OBJECTS += p10_spi_clear_status_errors.o
BOOTLDR_OBJECTS += hbbl_plat_attribute_service.o
# @TODO JIRA PFHB-921 move these .o files back to the
# SECUREROM_OBJECTS section once that support is working
# Note: (bl_)ecverify.o is needed in both places to support both V1 (securerom)
# and V3 (bootloader, for now) algorithms.  bl_ecverify.o is just the
# compilation of ecverify.o but with the Bootloader compile flags
BOOTLDR_OBJECTS += ROM_v3.o
BOOTLDR_OBJECTS += bl_ecverify.o
BOOTLDR_OBJECTS += keccak.o
BOOTLDR_OBJECTS += mlca.o

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
DIRECT_BOOT_OBJECTS += simpletrace.o
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
BASE_MODULES += pnor
BASE_MODULES += vfs
# SIO required for standalone p10 simics as it uses SFC_AST2400
BASE_MODULES += $(if $(CONFIG_SFC_IS_AST2400),sio)
BASE_MODULES += console
ifndef VPO_COMPILE
BASE_MODULES += $(if $(CONFIG_MCTP)$(CONFIG_MCTP_TESTCASES),mctp)
BASE_MODULES += $(if $(CONFIG_PLDM)$(CONFIG_PLDM_TESTCASES),pldm_base)
endif

# This is exported so that gcov knows the list of base modules to
# exclude from instrumentation. We can't simply export BASE_MODULES or
# else we get duplicate modules in the list which causes linker errors.
GCOV_BLACKLIST += $(BASE_MODULES) mctp pldm_base
GCOV_BLACKLIST += $(DIRECT_BOOT_OBJECTS) tls.o
export BASE_MODULES_GCOV_BLACKLIST:=$(GCOV_BLACKLIST)

EXTENDED_MODULES += istep06
EXTENDED_MODULES += isteps
EXTENDED_MODULES += targeting
EXTENDED_MODULES += fapi2
EXTENDED_MODULES += extinitsvc
EXTENDED_MODULES += istepdisp
EXTENDED_MODULES += hwas
EXTENDED_MODULES += fsi
EXTENDED_MODULES += i2c
EXTENDED_MODULES += i2cr
EXTENDED_MODULES += intr
EXTENDED_MODULES += ecc
EXTENDED_MODULES += vpd
EXTENDED_MODULES += util
EXTENDED_MODULES += tracedaemon
EXTENDED_MODULES += mbox
EXTENDED_MODULES += spi
EXTENDED_MODULES += attn
EXTENDED_MODULES += thread_activate
EXTENDED_MODULES += runtime
EXTENDED_MODULES += sbe
EXTENDED_MODULES += $(if $(CONFIG_TPMDD),secureboot_trusted,)
EXTENDED_MODULES += imageprocs
EXTENDED_MODULES += sbeio
EXTENDED_MODULES += $(if $(CONFIG_GPIODD),gpio,)
EXTENDED_MODULES += p9_cpuWkup
EXTENDED_MODULES += mmio
EXTENDED_MODULES += smf
EXTENDED_MODULES += fapiwrap
EXTENDED_MODULES += expaccess
EXTENDED_MODULES += mdsaccess
EXTENDED_MODULES += eeprom
EXTENDED_MODULES += pm
EXTENDED_MODULES += $(if $(CONFIG_PLDM)$(CONFIG_PLDM_TESTCASES),bios_attr_accessors)
ifndef VPO_COMPILE
EXTENDED_MODULES += istep07
EXTENDED_MODULES += istep08
EXTENDED_MODULES += istep09
EXTENDED_MODULES += istep10
EXTENDED_MODULES += istep11
EXTENDED_MODULES += istep12
EXTENDED_MODULES += istep124
EXTENDED_MODULES += istep13
EXTENDED_MODULES += istep14
EXTENDED_MODULES += istep15
EXTENDED_MODULES += istep16
EXTENDED_MODULES += istep18
EXTENDED_MODULES += istep20
EXTENDED_MODULES += istep21
EXTENDED_MODULES += fsiscom
EXTENDED_MODULES += prdf
EXTENDED_MODULES += mdia
EXTENDED_MODULES += dump
#EXTENDED_MODULES += p9_phbPerst   @TODO-RTC:257500
EXTENDED_MODULES += $(if $(CONFIG_SECUREBOOT),secureboot_ext)
EXTENDED_MODULES += tod
EXTENDED_MODULES += fab_iovalid
EXTENDED_MODULES += node_comm
EXTENDED_MODULES += $(if $(CONFIG_UCD_FLASH_UPDATES),ucd)
EXTENDED_MODULES += $(if $(CONFIG_FSP_BUILD),,nvram)
EXTENDED_MODULES += ocmbupd
EXTENDED_MODULES += $(if $(CONFIG_HTMGT),htmgt)
EXTENDED_MODULES += isteps_mss
EXTENDED_MODULES += isteps_nest
EXTENDED_MODULES += nestmemutils
EXTENDED_MODULES += $(if $(CONFIG_ENABLE_HDAT_IN_HOSTBOOT),hdat)
EXTENDED_MODULES += xz
EXTENDED_MODULES += $(if $(CONFIG_CONSOLE_OUTPUT_ERRORDISPLAY),errldisplay)
EXTENDED_MODULES += $(if $(CONFIG_PLDM)$(CONFIG_PLDM_TESTCASES),pldm_extended)
EXTENDED_MODULES += $(if $(CONFIG_DEVTREE),devtree)
endif

#***************************************
# Working test modules
#***************************************
ifndef VPO_COMPILE
TESTCASE_MODULES += cxxtest
TESTCASE_MODULES += testtrace
TESTCASE_MODULES += testdevicefw
TESTCASE_MODULES += initsvctesttask
TESTCASE_MODULES += testcxxtest
TESTCASE_MODULES += testpnor
TESTCASE_MODULES += testvfs
TESTCASE_MODULES += testutil
TESTCASE_MODULES += testsecureboot
TESTCASE_MODULES += testsecureboot_ext
TESTCASE_MODULES += testfsiscom
TESTCASE_MODULES += testlpc
TESTCASE_MODULES += $(if $(CONFIG_HTMGT),testhtmgt)
TESTCASE_MODULES += testi2cr
TESTCASE_MODULES += testinitservice
TESTCASE_MODULES += testfsi
TESTCASE_MODULES += testxscom
TESTCASE_MODULES += testkernel
TESTCASE_MODULES += testtargeting
TESTCASE_MODULES += testmemoize
TESTCASE_MODULES += testprdf
TESTCASE_MODULES += testmdia
TESTCASE_MODULES += testpirformat
TESTCASE_MODULES += testi2c
TESTCASE_MODULES += testmbox
TESTCASE_MODULES += testsbe
TESTCASE_MODULES += testsbeio
TESTCASE_MODULES += testerrl
TESTCASE_MODULES += $(if $(CONFIG_DEVTREE),testdevtree)
TESTCASE_MODULES += testhwas
TESTCASE_MODULES += testvpd
TESTCASE_MODULES += testsyslib
TESTCASE_MODULES += testtlsmod
TESTCASE_MODULES += testscom
TESTCASE_MODULES += testruntime
TESTCASE_MODULES += testintr
TESTCASE_MODULES += testfapi2
TESTCASE_MODULES += testfapi2serial
TESTCASE_MODULES += $(if $(CONFIG_EARLY_TESTCASES) && $(FSP_BUILD) ,,testnvram)
TESTCASE_MODULES += testsmf
TESTCASE_MODULES += testexpaccess
TESTCASE_MODULES += testmdsaccess
TESTCASE_MODULES += testrtloader
TESTCASE_MODULES += testocmbupd
TESTCASE_MODULES += testspi
TESTCASE_MODULES += testspiserial
TESTCASE_MODULES += testmmio
TESTCASE_MODULES += testeeprom
TESTCASE_MODULES += testdump
TESTCASE_MODULES += $(if $(CONFIG_PLDM)$(CONFIG_PLDM_TESTCASES),testpldm_extended)
TESTCASE_MODULES += testmemorymgr
endif

#******************************************************************
#KNOWN ISSUES (I might let these run but there is something wrong)
#All of these are tracked by a RTC story
#******************************************************************
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

# The order of these libraries determines the initialization order
#  of the modules during execution.
RUNTIME_MODULES += errl_rt       # ~/src/usr/errl/runtime/
RUNTIME_MODULES += trace_rt      # ~/src/usr/trace/runtime/
RUNTIME_MODULES += $(if $(CONFIG_MCTP)$(CONFIG_MCTP_TESTCASES),mctp_rt) # ~/src/usr/mctp/runtime/
RUNTIME_MODULES += $(if $(CONFIG_PLDM)$(CONFIG_PLDM_TESTCASES),pldm_rt) # ~/src/usr/pldm/runtime/
RUNTIME_MODULES += targeting_rt  # ~/src/usr/targeting/runtime/
RUNTIME_MODULES += util_rt       # ~/src/usr/util/runtime/
RUNTIME_MODULES += devicefw_rt   # ~/src/usr/devicefw/runtime/
RUNTIME_MODULES += $(if $(CONFIG_FSP_BUILD),,pnor_rt) # ~/src/usr/pnor/runtime/
RUNTIME_MODULES += eeprom_rt     # ~/src/usr/eeprom/runtime/
RUNTIME_MODULES += secureboot_rt # ~/src/usr/secureboot/runtime/
RUNTIME_MODULES += fapi2_rt      # ~/src/usr/fapi2/runtime/
RUNTIME_MODULES += fsi_rt        # ~/src/usr/fsi/runtime/ - no runtime test
RUNTIME_MODULES += fsiscom_rt    # ~/src/usr/fsiscom/runtime/ - no runtime test
RUNTIME_MODULES += imageprocs_rt # ~/src/usr/imageprocs/runtime/ - no runtime test
RUNTIME_MODULES += i2c_rt        # ~/src/usr/i2c/runtime/
RUNTIME_MODULES += mmio_rt       # ~/src/usr/mmio/runtime/ - no runtime test
RUNTIME_MODULES += scom_rt       # ~/src/usr/scom/runtime/
RUNTIME_MODULES += ecc           # ~/src/usr/ecc/
RUNTIME_MODULES += vpd_rt        # ~/src/usr/vpd/runtime/
RUNTIME_MODULES += xscom_rt      # ~/src/usr/xscom/runtime/
RUNTIME_MODULES += sbeio_rt      # ~/src/usr/sbeio/runtime/
RUNTIME_MODULES += tod_rt        # ~/src/usr/isteps/tod/runtime/ - no runtime test
RUNTIME_MODULES += mss_rt        # ~/src/usr/isteps/mss/runtime/ - no runtime test
RUNTIME_MODULES += pm_rt         # ~/src/usr/isteps/pm/runtime/
RUNTIME_MODULES += expaccess_rt  # ~/src/usr/expaccess/runtime/
RUNTIME_MODULES += $(if $(CONFIG_HBRT_PRD),prdf_rt) # ~/src/usr/diag/prdf/runtime/
RUNTIME_MODULES += $(if $(CONFIG_HBRT_PRD),attn_rt) # ~/src/usr/diag/attn/runtime/
RUNTIME_MODULES += $(if $(CONFIG_HTMGT),htmgt_rt)   # ~/src/usr/htmgt/runtime/
RUNTIME_MODULES += hwplibs_rt    # ~src/usr/hwplibs/runtime/


# This is exported so that gcov knows the list of runtime modules to
# exclude from instrumentation. We can't simply export RUNTIME_MODULES or
# else we get duplicate modules in the list which causes linker errors.
#
# @TODO RTC 248021: Remove modules from blacklist when compile is fixed
# Reasons for coverage exclusion:
#     vpd_rt: Duplicate weak symbol errors for AttrRp singleton
export RUNTIME_MODULES_GCOV_BLACKLIST:= vpd_rt

ifndef VPO_COMPILE
RUNTIME_TESTCASE_MODULES += cxxtest_rt
RUNTIME_TESTCASE_MODULES += testerrl_rt   # ~/src/usr/errl/runtime/test/
RUNTIME_TESTCASE_MODULES += testtrace_rt  # ~/src/usr/trace/runtime/test/
RUNTIME_TESTCASE_MODULES += testtargeting_rt  # ~/src/usr/targeting/runtime/test/
RUNTIME_TESTCASE_MODULES += testutil_rt   # ~/src/usr/util/runtime/test/
RUNTIME_TESTCASE_MODULES += testdevicefw_rt   # ~/src/usr/devicefw/runtime/test/
RUNTIME_TESTCASE_MODULES += testsecureboot_rt # ~/src/usr/secureboot/runtime/test/
RUNTIME_TESTCASE_MODULES += testfapi2_rt  # ~/src/usr/fapi2/runtime/test/
RUNTIME_TESTCASE_MODULES += testscom_rt   # ~/src/usr/scom/runtime/test/
RUNTIME_TESTCASE_MODULES += testvpd_rt    # ~/src/usr/vpd/runtime/test/
RUNTIME_TESTCASE_MODULES += testxscom_rt  # ~/src/usr/xscom/runtime/test/
RUNTIME_TESTCASE_MODULES += testsbeio_rt  # ~/src/usr/sbeio/runtime/test/
RUNTIME_TESTCASE_MODULES += $(if $(CONFIG_ODYSSEY_BRINGUP), ,testpm_rt)     # ~/src/usr/isteps/pm/runtime/test/
RUNTIME_TESTCASE_MODULES += testsyslib_rt # ~/src/usr/testcore/lib/runtime/
RUNTIME_TESTCASE_MODULES += testexpaccess_rt # ~/src/usr/expaccess/runtime/test/
RUNTIME_TESTCASE_MODULES += $(if $(CONFIG_HBRT_PRD),testprdf_rt)
RUNTIME_TESTCASE_MODULES += $(if $(CONFIG_HBRT_PRD),testattn_rt)
RUNTIME_TESTCASE_MODULES += $(if $(CONFIG_MCTP)$(CONFIG_MCTP_TESTCASES),testmctp_rt) # ~/src/usr/mctp/runtime/
RUNTIME_TESTCASE_MODULES += testi2c_rt
RUNTIME_TESTCASE_MODULES += testmmio_rt
endif

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
hbicore_test_OBJECTS += random.o
hbicore_test_OBJECTS += rand.o
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

# MAX_BASE_SIZE is for hbicore.bin, aka HBB (Hostboot Base image)
# - HBB size is 1MB in pnor layout
# - 908KB is the size without ECC rounded down
# - Then genPnorImages.pl will add 2 headers:
#   - The V1 header (size 4KB) at the start o the image
#   - The V3 header (size 15KB) to the end of the image
#   - Rounding up the header sizes to a 4KB boundary and we need to account for 20KB
# - This leaves us with a goal of 888KB for the raw hbicore.bin file
MAX_BASE_SIZE = 909312

# The maximum size of the bootloader image (hbibl.bin) is 94KB
# - this includes 12KB for exception vectors
# - bootloader code and data
# - securerom binary
# - HBBL does NOT have ecc added in the pnor layout files
MAX_BTLDR_SIZE = 96256

THRESH_HBIRT_SIZE = 10485760
MAX_HBIRT_SIZE = 16252928


imgsizecheck: ${IMGDIR}/hbicore.bin ${IMGDIR}/hbibl.bin ${IMGDIR}/hbirt.bin
#Comment out line below if your HBIRTLID exceeds the threshold and open a JIRA/Defect to track the issue when this fails in CI
ifndef HOSTBOOT_PROFILE
	$(if $(findstring $(shell (stat -c%s ${IMGDIR}/hbirt.bin; echo $(THRESH_HBIRT_SIZE)) | sort -n | tail -n1), $(THRESH_HBIRT_SIZE)),true, @echo WARNING: ${IMGDIR}/hbirt.bin is $(shell (stat -c%s ${IMGDIR}/hbirt.bin)) bytes which is close to the max size.  Search "HBIRTLID" in src/makefile for instructions to disable this warning; false)
	$(if $(findstring $(shell (stat -c%s ${IMGDIR}/hbirt.bin; echo $(MAX_HBIRT_SIZE)) | sort -n | tail -n1), $(MAX_HBIRT_SIZE)),true, @echo ERROR: ${IMGDIR}/hbirt.bin too large.  Max allowed size is $(MAX_HBIRT_SIZE); false)
endif
	$(if $(findstring $(shell (stat -c%s ${IMGDIR}/hbicore.bin; echo $(MAX_BASE_SIZE)) | sort -n | tail -n1), $(MAX_BASE_SIZE)),true, @echo ERROR: ${IMGDIR}/hbicore.bin too large.  Max allowed size is $(MAX_BASE_SIZE); false)
	$(if $(findstring $(shell (stat -c%s ${IMGDIR}/hbibl.bin; echo $(MAX_BTLDR_SIZE)) | sort -n | tail -n1), $(MAX_BTLDR_SIZE)),true, @echo ERROR: ${IMGDIR}/hbibl.bin too large.  Max allowed size is $(MAX_BTLDR_SIZE); false)
