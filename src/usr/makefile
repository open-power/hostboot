# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2010,2016
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

SUBDIRS += sio.d
SUBDIRS += isteps.d
SUBDIRS += trace.d
SUBDIRS += cxxtest.d
SUBDIRS += testcore.d
SUBDIRS += errl.d
SUBDIRS += devicefw.d
SUBDIRS += scom.d
SUBDIRS += xscom.d
SUBDIRS += targeting.d
SUBDIRS += initservice.d
SUBDIRS += fapi2.d
SUBDIRS += pnor.d
SUBDIRS += i2c.d
SUBDIRS += vfs.d
SUBDIRS += fsi.d
SUBDIRS += hwas.d
SUBDIRS += fsiscom.d
SUBDIRS += intr.d
SUBDIRS += util.d
SUBDIRS += mbox.d
SUBDIRS += vpd.d
SUBDIRS += scan.d
SUBDIRS += runtime.d
SUBDIRS += ibscom.d
SUBDIRS += dump.d
SUBDIRS += secureboot.d
SUBDIRS += devtree.d
#@TODO RTC:142091
#SUBDIRS += sbe.d
SUBDIRS += gpio.d
SUBDIRS += lpc.d
SUBDIRS += console.d
SUBDIRS += errldisplay.d
SUBDIRS += ipmi.d
#SUBDIRS += htmgt.d
SUBDIRS += diag.d

include ${ROOTPATH}/config.mk
