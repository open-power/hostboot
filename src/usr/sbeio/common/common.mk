# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/sbeio/common/common.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2018,2024
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
#

#Common Include Paths
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/ffdc
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/perv
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/lib
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/sbe
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/sppe
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/utils
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/memory
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/odyssey/common/include
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/perv
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/sbe_utils/include
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/attr
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic/lib/i2c
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic/lib
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/generic/memory/lib
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/common/procedures/hwp/pmic/lib
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/include
EXTRAINCDIR += ${ROOTPATH}/src/import
EXTRAINCDIR += ${ROOTPATH}/src/usr/
EXTRAINCDIR += ${ROOTPATH}/src/usr/sbeio
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/odyssey/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ocmbupd/

#Common Objects
OBJS += sbe_attn.o
OBJS += sbe_retry_handler.o
OBJS += ody_sbe_retry_handler.o
OBJS += p10_sbe_hreset.o
OBJS += p10_start_cbs.o
OBJS += p10_get_sbe_msg_register.o
OBJS += sbe_psudd_common.o
OBJS += sbe_ffdc_parser.o
OBJS += sbe_ffdc_package_parser.o
OBJS += sbe_getCapabilities.o
OBJS += sbe_psuGetHwReg.o
OBJS += sbe_utils.o
OBJS += sbe_psuSendMemConfig.o
OBJS += sbe_psuSendCoreConfig.o
OBJS += pmic_n_mode_detect.o
OBJS += pmic_periodic_telemetry_ddr5.o
OBJS += pmic_health_check_ddr5.o
OBJS += pmic_periodic_telemetry_utils_ddr5.o
OBJS += pmic_health_check_utils_ddr5.o
OBJS += pmic_common_utils_ddr5.o
OBJS += pmic_common_utils.o
OBJS += mss_pmic_attribute_accessors_manual.o
OBJS += sbe_fifo_buffer.o
OBJS += ody_extract_sbe_rc.o
OBJS += sbe_getSBEFFDC.o
OBJS += ody_sbe_hreset.o
OBJS += poz_sbe_hreset.o
OBJS += ody_sppe_check_for_ready.o
OBJS += poz_sppe_check_for_ready.o
OBJS += sbe_attributeAccess.o
OBJS += ody_generate_sbe_attribute_data.o
OBJS += sbe_targets.o
OBJS += sbe_attribute_utils.o
OBJS += ody_apply_sbe_attribute_data.o
OBJS += ody_analyze_sbe_attr_response.o
OBJS += sbe_telemetry.o
OBJS += sbe_getScratchData.o

#Common VPATHs
VPATH += ${ROOTPATH}/src/usr/sbeio/common
VPATH += ${ROOTPATH}/src/usr/isteps_mss/
VPATH += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs
VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/perv/
VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/sbe/
VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/lib/
VPATH += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/memory/
VPATH += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/utils/
VPATH += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic
VPATH += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5
VPATH += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils
VPATH += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic/lib
VPATH += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils
VPATH += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/perv
VPATH += ${ROOTPATH}/src/import/hwpf/sbe_utils/src/
