# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2010,2022
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
ROOTPATH = ../..

# Do not instrument the module_init.o
HOSTBOOT_PROFILE_NO_INSTRUMENT = 1
OBJS += module_init.o

SUBDIRS += console.d
SUBDIRS += cxxtest.d
SUBDIRS += devicefw.d
SUBDIRS += $(if $(CONFIG_DEVTREE),devtree.d)
SUBDIRS += diag.d
SUBDIRS += dump.d
SUBDIRS += eeprom.d
SUBDIRS += errl.d
SUBDIRS += errldisplay.d
SUBDIRS += expaccess.d
SUBDIRS += mdsaccess.d
SUBDIRS += fapi2.d
SUBDIRS += fapiwrap.d
SUBDIRS += fsi.d
SUBDIRS += fsiscom.d
SUBDIRS += gpio.d
SUBDIRS += $(if $(CONFIG_ENABLE_HDAT_IN_HOSTBOOT),hdat.d,)
SUBDIRS += $(if $(CONFIG_HTMGT),htmgt.d)
SUBDIRS += hwas.d
SUBDIRS += hwplibs.d
SUBDIRS += i2c.d
SUBDIRS += imageprocs.d
SUBDIRS += initservice.d
SUBDIRS += intr.d
SUBDIRS += isteps.d
SUBDIRS += lpc.d
SUBDIRS += mbox.d
SUBDIRS += $(if $(CONFIG_MCTP)$(CONFIG_MCTP_TESTCASES),mctp.d)
SUBDIRS += mmio.d
SUBDIRS += $(if $(CONFIG_FSP_BUILD),,nvram.d)
SUBDIRS += $(if $(CONFIG_PLDM)$(CONFIG_PLDM_TESTCASES),pldm.d)
SUBDIRS += pnor.d
SUBDIRS += runtime.d
SUBDIRS += spi.d
SUBDIRS += sbe.d
SUBDIRS += sbeio.d
SUBDIRS += scom.d
SUBDIRS += secureboot.d
SUBDIRS += sio.d
SUBDIRS += targeting.d
SUBDIRS += testcore.d
SUBDIRS += trace.d
SUBDIRS += util.d
SUBDIRS += vfs.d
SUBDIRS += vpd.d
SUBDIRS += xscom.d
SUBDIRS += xz.d

#errldisplay relies on some generated files from PRD.
#Enforce that it goes after
_BUILD/SUBDIR/CODE/errldisplay: _BUILD/SUBDIR/CODE/diag

include ${ROOTPATH}/config.mk
