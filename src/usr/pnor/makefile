# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/pnor/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2022
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
ROOTPATH = ../../..

HIOMAP_DEPS = ast_mboxdd.o pnor_mboxdd.o pnor_hiomapdd.o
PLDM_DEPS = pnor_pldmdd.o pnor_pldm_utils.o

MODULE = pnor
OBJS += pnor_utils.o
OBJS += pnorrp.o
OBJS += $(if $(CONFIG_SECUREBOOT),spnorrp.o)
OBJS += $(if $(CONFIG_PNORDD_IS_SFC),pnor_sfcdd.o)
OBJS += $(if $(CONFIG_PNORDD_IS_BMCMBOX),$(HIOMAP_DEPS))
OBJS += $(if $(CONFIG_PLDM),$(PLDM_DEPS))
OBJS += pnor_common.o
OBJS += pnorvalid.o
OBJS += ecc.o
OBJS += sfcdd.o
OBJS += pnoraltsync.o

#SFC Implementations
OBJS += $(if $(CONFIG_SFC_IS_IBM_DPSS),sfc_ibm.o)
OBJS += $(if $(CONFIG_SFC_IS_AST2400),sfc_ast2X00.o)
OBJS += $(if $(CONFIG_SFC_IS_AST2500),sfc_ast2X00.o)
OBJS += $(if $(CONFIG_SFC_IS_AST2400),sfc_ast2400.o)
OBJS += $(if $(CONFIG_SFC_IS_AST2500),sfc_ast2500.o)
OBJS += $(if $(CONFIG_SFC_IS_FAKE),sfc_fake.o)

#NOR Implementations
OBJS += $(if $(CONFIG_ALLOW_MICRON_PNOR),nor_micron.o)

#Extra includes
EXTRAINCDIR += $(if $(CONFIG_PLDM),${ROOTPATH}/src/subtree/openbmc/pldm/libpldm)

SUBDIRS += test.d
SUBDIRS += runtime.d

include ${ROOTPATH}/config.mk

