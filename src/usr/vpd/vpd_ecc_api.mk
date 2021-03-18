# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/vpd/vpd_ecc_api.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020,2021
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

# Compile the VPD ECC update/validate algorithms if flag CONFIG_COMPILE_VPD_ECC_ALGORITHMS
# is defined/set.
OBJS += $(if $(CONFIG_COMPILE_VPD_ECC_ALGORITHMS), vpd_ecc_api_algorithms.o, vpd_ecc_api_no_op.o)
OBJS += $(if $(CONFIG_COMPILE_VPD_ECC_ALGORITHMS), vpdecc.o)
OBJS += $(if $(CONFIG_COMPILE_VPD_ECC_ALGORITHMS), vpdecc_support.o)

# Force these files to be present before continuing.  A multi-threaded compile
# can get ahead of itself and spew out bogus errors if these files are not present.
.NOTPARALLEL: vpdecc.h vpdecc.c vpdecc_support.h vpdecc_support.c

# Fetch the VPD ECC algorithm APIs if compiling for VPD ECC algorithms
vpdecc.h vpdecc.c vpdecc_support.h vpdecc_support.c &:  $(ROOTPATH)/src/build/tools/fetchVpdAlgorithms.sh
	$(ROOTPATH)/src/build/tools/fetchVpdAlgorithms.sh

# Remove the VPD ECC algorithm files when user calls 'make clean' or 'make clobber'
.PHONY: CLEAN_PASS
CLEAN_PASS:
	@-rm -rf vpdecc.h vpdecc.c vpdecc_support.h vpdecc_support.c


