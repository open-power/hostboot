/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_6.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_perv_6_H_
#define __p10_scom_perv_6_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> [COMP_INTR_HOST_MASK_REG]
static const uint64_t COMP_INTR_HOST_MASK_REG = 0x000f0033ull;

static const uint32_t COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0 = 0;
static const uint32_t COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1 = 1;
static const uint32_t COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2 = 2;
static const uint32_t COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3 = 3;
static const uint32_t COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4 = 4;
static const uint32_t COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5 = 5;
static const uint32_t COMP_INTR_HOST_MASK_REG_ERROR_MASK_0 = 6;
static const uint32_t COMP_INTR_HOST_MASK_REG_ERROR_MASK_1 = 7;
static const uint32_t COMP_INTR_HOST_MASK_REG_ERROR_MASK_2 = 8;
static const uint32_t COMP_INTR_HOST_MASK_REG_ERROR_MASK_3 = 9;
static const uint32_t COMP_INTR_HOST_MASK_REG_ERROR_MASK_4 = 10;
static const uint32_t COMP_INTR_HOST_MASK_REG_ERROR_MASK_5 = 11;
//<< [COMP_INTR_HOST_MASK_REG]
// perv/reg00012.H

//>> [CPLT_CONF1]
static const uint64_t CPLT_CONF1_RW = 0x00000009ull;
static const uint64_t CPLT_CONF1_WO_CLEAR = 0x00000029ull;
static const uint64_t CPLT_CONF1_WO_OR = 0x00000019ull;

static const uint32_t CPLT_CONF1_LANE_CFG_DC = 0;
static const uint32_t CPLT_CONF1_LANE_CFG_DC_LEN = 2;
static const uint32_t CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC = 0;
static const uint32_t CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC_LEN = 2;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_DC = 0;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_DC_LEN = 3;
static const uint32_t CPLT_CONF1_OD_IOVALID_DC = 0;
static const uint32_t CPLT_CONF1_EN_EQ_DC = 0;
static const uint32_t CPLT_CONF1_EN_EQ_DC_LEN = 2;
static const uint32_t CPLT_CONF1_0_IOVALID_DC = 0;
static const uint32_t CPLT_CONF1_EV_IOVALID_DC = 1;
static const uint32_t CPLT_CONF1_1_IOVALID_DC = 1;
static const uint32_t CPLT_CONF1_SWAP_DC = 2;
static const uint32_t CPLT_CONF1_SWAP_DC_LEN = 3;
static const uint32_t CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC = 2;
static const uint32_t CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC_LEN = 3;
static const uint32_t CPLT_CONF1_NORTH_DC = 2;
static const uint32_t CPLT_CONF1_NORTH_DC_LEN = 3;
static const uint32_t CPLT_CONF1_2_IOVALID_DC = 2;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC = 3;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC_LEN = 4;
static const uint32_t CPLT_CONF1_3_IOVALID_DC = 3;
static const uint32_t CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC = 5;
static const uint32_t CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC_LEN = 3;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC = 7;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC_LEN = 3;
static const uint32_t CPLT_CONF1_IOVALID_DC = 8;
static const uint32_t CPLT_CONF1_IOVALID_DC_LEN = 3;
static const uint32_t CPLT_CONF1_P_N1_PSI_IOVALID_DC = 10;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC = 10;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC_LEN = 2;
static const uint32_t CPLT_CONF1_RATIO_OVERRIDE_DC = 11;
static const uint32_t CPLT_CONF1_APP0_RATIO_DC = 12;
static const uint32_t CPLT_CONF1_APP0_RATIO_DC_LEN = 5;
static const uint32_t CPLT_CONF1_C_LP_RESET = 12;
static const uint32_t CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC = 12;
static const uint32_t CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC = 13;
static const uint32_t CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC = 14;
static const uint32_t CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC = 15;
static const uint32_t CPLT_CONF1_APP1_RATIO_DC = 17;
static const uint32_t CPLT_CONF1_APP1_RATIO_DC_LEN = 5;
static const uint32_t CPLT_CONF1_APP2_RATIO_DC = 22;
static const uint32_t CPLT_CONF1_APP2_RATIO_DC_LEN = 5;
//<< [CPLT_CONF1]
// perv/reg00012.H

//>> [CPLT_CTRL1]
static const uint64_t CPLT_CTRL1_RW = 0x00000001ull;
static const uint64_t CPLT_CTRL1_WO_CLEAR = 0x00000021ull;
static const uint64_t CPLT_CTRL1_WO_OR = 0x00000011ull;

static const uint32_t CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC = 0;
static const uint32_t CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC = 0;
static const uint32_t CPLT_CTRL1_REGION0_FENCE_DC = 4;
static const uint32_t CPLT_CTRL1_TC_REGION0_FENCE_DC = 4;
static const uint32_t CPLT_CTRL1_REGION1_FENCE_DC = 5;
static const uint32_t CPLT_CTRL1_TC_REGION1_FENCE_DC = 5;
static const uint32_t CPLT_CTRL1_REGION2_FENCE_DC = 6;
static const uint32_t CPLT_CTRL1_TC_REGION2_FENCE_DC = 6;
static const uint32_t CPLT_CTRL1_REGION3_FENCE_DC = 7;
static const uint32_t CPLT_CTRL1_TC_REGION3_FENCE_DC = 7;
static const uint32_t CPLT_CTRL1_REGION4_FENCE_DC = 8;
static const uint32_t CPLT_CTRL1_TC_REGION4_FENCE_DC = 8;
static const uint32_t CPLT_CTRL1_REGION5_FENCE_DC = 9;
static const uint32_t CPLT_CTRL1_TC_REGION5_FENCE_DC = 9;
static const uint32_t CPLT_CTRL1_REGION6_FENCE_DC = 10;
static const uint32_t CPLT_CTRL1_TC_REGION6_FENCE_DC = 10;
static const uint32_t CPLT_CTRL1_REGION7_FENCE_DC = 11;
static const uint32_t CPLT_CTRL1_TC_REGION7_FENCE_DC = 11;
static const uint32_t CPLT_CTRL1_REGION8_FENCE_DC = 12;
static const uint32_t CPLT_CTRL1_TC_REGION8_FENCE_DC = 12;
static const uint32_t CPLT_CTRL1_REGION9_FENCE_DC = 13;
static const uint32_t CPLT_CTRL1_TC_REGION9_FENCE_DC = 13;
static const uint32_t CPLT_CTRL1_REGION10_FENCE_DC = 14;
static const uint32_t CPLT_CTRL1_TC_REGION10_FENCE_DC = 14;
static const uint32_t CPLT_CTRL1_REGION11_FENCE_DC = 15;
static const uint32_t CPLT_CTRL1_TC_REGION11_FENCE_DC = 15;
static const uint32_t CPLT_CTRL1_REGION12_FENCE_DC = 16;
static const uint32_t CPLT_CTRL1_TC_REGION12_FENCE_DC = 16;
static const uint32_t CPLT_CTRL1_REGION13_FENCE_DC = 17;
static const uint32_t CPLT_CTRL1_TC_REGION13_FENCE_DC = 17;
static const uint32_t CPLT_CTRL1_REGION14_FENCE_DC = 18;
static const uint32_t CPLT_CTRL1_TC_REGION14_FENCE_DC = 18;
static const uint32_t CPLT_CTRL1_EXPORT_FREEZE = 20;
static const uint32_t CPLT_CTRL1_STG_ACT_EN_DC = 22;
static const uint32_t CPLT_CTRL1_TC_STG_ACT_EN_DC = 22;
//<< [CPLT_CTRL1]
// perv/reg00012.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL2_COPY]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI = 0x00002912ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE = 0x00002c48ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW = 0x00050112ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG_LEN = 32;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL2_COPY]
// perv/reg00012.H

//>> [LOCAL_XSTOP_MASK]
static const uint64_t LOCAL_XSTOP_MASK_RW = 0x00040043ull;
static const uint64_t LOCAL_XSTOP_MASK_WO_CLEAR = 0x00040063ull;
static const uint64_t LOCAL_XSTOP_MASK_WO_OR = 0x00040053ull;

static const uint32_t LOCAL_XSTOP_MASK_01 = 1;
static const uint32_t LOCAL_XSTOP_MASK_02 = 2;
static const uint32_t LOCAL_XSTOP_MASK_03 = 3;
static const uint32_t LOCAL_XSTOP_MASK_04 = 4;
static const uint32_t LOCAL_XSTOP_MASK_05 = 5;
static const uint32_t LOCAL_XSTOP_MASK_06 = 6;
static const uint32_t LOCAL_XSTOP_MASK_07 = 7;
static const uint32_t LOCAL_XSTOP_MASK_08 = 8;
static const uint32_t LOCAL_XSTOP_MASK_09 = 9;
static const uint32_t LOCAL_XSTOP_MASK_10 = 10;
static const uint32_t LOCAL_XSTOP_MASK_11 = 11;
static const uint32_t LOCAL_XSTOP_MASK_12 = 12;
static const uint32_t LOCAL_XSTOP_MASK_13 = 13;
static const uint32_t LOCAL_XSTOP_MASK_14 = 14;
static const uint32_t LOCAL_XSTOP_MASK_15 = 15;
//<< [LOCAL_XSTOP_MASK]
// perv/reg00012.H

//>> [REC_ERR_MST14_REG2]
static const uint64_t REC_ERR_MST14_REG2 = 0x000f007aull;

static const uint32_t REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST14_REG2_32_MST14_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST14_REG2_32_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST14_REG2_33_MST14_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST14_REG2_33_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST14_REG2_34_MST14_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST14_REG2_34_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST14_REG2_35_MST14_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST14_REG2_35_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST14_REG2_36_MST14_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST14_REG2_36_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST14_REG2_37_MST14_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST14_REG2_37_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST14_REG2_38_MST14_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST14_REG2_38_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST14_REG2_39_MST14_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST14_REG2_39_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST14_REG2_40_MST14_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST14_REG2_40_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST14_REG2_41_MST14_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST14_REG2_41_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST14_REG2_42_MST14_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST14_REG2_42_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST14_REG2_43_MST14_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST14_REG2_43_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST14_REG2_44_MST14_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST14_REG2_44_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST14_REG2_45_MST14_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST14_REG2_45_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST14_REG2_46_MST14_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST14_REG2_46_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST14_REG2_47_MST14_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST14_REG2_47_MST14_ERROR_CODE_LEN = 3;
//<< [REC_ERR_MST14_REG2]
// perv/reg00012.H

//>> [TOD_M_PATH_0_STEP_STEER_REG]
static const uint64_t TOD_M_PATH_0_STEP_STEER_REG = 0x0004000eull;

static const uint32_t TOD_M_PATH_0_STEP_STEER_REG_MODE = 0;
static const uint32_t TOD_M_PATH_0_STEP_STEER_REG_RATE = 1;
static const uint32_t TOD_M_PATH_0_STEP_STEER_REG_RATE_LEN = 31;
static const uint32_t TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG = 32;
static const uint32_t TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE = 33;
static const uint32_t TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE_LEN = 31;
//<< [TOD_M_PATH_0_STEP_STEER_REG]
// perv/reg00013.H

//>> [TOD_M_PATH_STATUS_REG]
static const uint64_t TOD_M_PATH_STATUS_REG = 0x00040009ull;

static const uint32_t TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD = 0;
static const uint32_t TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD_LEN = 8;
static const uint32_t TOD_M_PATH_STATUS_REG_0_CPS = 8;
static const uint32_t TOD_M_PATH_STATUS_REG_0_CPS_LEN = 8;
static const uint32_t TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD = 16;
static const uint32_t TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD_LEN = 8;
static const uint32_t TOD_M_PATH_STATUS_REG_1_CPS = 24;
static const uint32_t TOD_M_PATH_STATUS_REG_1_CPS_LEN = 8;
//<< [TOD_M_PATH_STATUS_REG]
// perv/reg00013.H

//>> [TOD_PSS_MSS_CTRL_REG]
static const uint64_t TOD_PSS_MSS_CTRL_REG = 0x00040007ull;

static const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT = 0;
static const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT = 1;
static const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT = 2;
static const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE = 3;
static const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE = 4;
static const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE = 5;
static const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE = 6;
static const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE = 7;
static const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT = 8;
static const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT = 9;
static const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT = 10;
static const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE = 11;
static const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE = 12;
static const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE = 13;
static const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE = 14;
static const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE = 15;
static const uint32_t TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE = 16;
static const uint32_t TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE = 17;
static const uint32_t TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH = 18;
static const uint32_t TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19 = 19;
static const uint32_t TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20 = 20;
static const uint32_t TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD = 21;
static const uint32_t TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31 = 22;
static const uint32_t TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31_LEN = 10;
//<< [TOD_PSS_MSS_CTRL_REG]
// perv/reg00013.H

//>> [TOD_RX_TTYPE_CTRL_REG]
static const uint64_t TOD_RX_TTYPE_CTRL_REG = 0x00040029ull;

static const uint32_t TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA = 0;
static const uint32_t TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA_LEN = 64;
//<< [TOD_RX_TTYPE_CTRL_REG]
// perv/reg00013.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "perv/reg00012.H"
#include "perv/reg00013.H"
#endif
#endif
