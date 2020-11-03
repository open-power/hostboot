/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_2.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

#ifndef __p10_scom_perv_2_H_
#define __p10_scom_perv_2_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> [CPLT_STAT0]
static const uint64_t CPLT_STAT0 = 0x00000100ull;

static const uint32_t CPLT_STAT0_ABIST_DONE_DC = 0;
static const uint32_t CPLT_STAT0_EBIST_DONE_DC = 1;
static const uint32_t CPLT_STAT0_RESERVED_2I = 2;
static const uint32_t CPLT_STAT0_RESERVED_3I = 3;
static const uint32_t CPLT_STAT0_TC_DIAG_PORT0_OUT = 4;
static const uint32_t CPLT_STAT0_TC_DIAG_PORT1_OUT = 5;
static const uint32_t CPLT_STAT0_RESERVED_6I = 6;
static const uint32_t CPLT_STAT0_PLL_DESTOUT = 7;
static const uint32_t CPLT_STAT0_CC_CTRL_OPCG_DONE_DC = 8;
static const uint32_t CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC = 9;
static const uint32_t CPLT_STAT0_IOPCI_TC_HSSPRTREADYA = 10;
static const uint32_t CPLT_STAT0_FREE_USAGE_10I = 10;
static const uint32_t CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR = 10;
static const uint32_t CPLT_STAT0_IOPCI_TC_HSSPRTREADYB = 11;
static const uint32_t CPLT_STAT0_FREE_USAGE_11I = 11;
static const uint32_t CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR = 11;
static const uint32_t CPLT_STAT0_FREE_USAGE_12I = 12;
static const uint32_t CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED = 12;
static const uint32_t CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN = 12;
static const uint32_t CPLT_STAT0_FREE_USAGE_13I = 13;
static const uint32_t CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT = 13;
static const uint32_t CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT_LEN = 10;
static const uint32_t CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN = 13;
static const uint32_t CPLT_STAT0_FREE_USAGE_14I = 14;
static const uint32_t CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN = 14;
static const uint32_t CPLT_STAT0_FREE_USAGE_15I = 15;
static const uint32_t CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN = 15;
static const uint32_t CPLT_STAT0_FREE_USAGE_16I = 16;
static const uint32_t CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN = 16;
static const uint32_t CPLT_STAT0_FREE_USAGE_17I = 17;
static const uint32_t CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN = 17;
static const uint32_t CPLT_STAT0_FREE_USAGE_18I = 18;
static const uint32_t CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN = 18;
static const uint32_t CPLT_STAT0_FREE_USAGE_19I = 19;
static const uint32_t CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN = 19;
static const uint32_t CPLT_STAT0_FREE_USAGE_20I = 20;
static const uint32_t CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN = 20;
static const uint32_t CPLT_STAT0_FREE_USAGE_21I = 21;
static const uint32_t CPLT_STAT0_FREE_USAGE_22I = 22;
static const uint32_t CPLT_STAT0_FREE_USAGE_23I = 23;
static const uint32_t CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID = 23;
static const uint32_t CPLT_STAT0_GLOBAL_FEH_DC = 24;
static const uint32_t CPLT_STAT0_FREE_USAGE_25I = 25;
static const uint32_t CPLT_STAT0_FREE_USAGE_26I = 26;
static const uint32_t CPLT_STAT0_FREE_USAGE_27I = 27;
static const uint32_t CPLT_STAT0_FREE_USAGE_28I = 28;
static const uint32_t CPLT_STAT0_FREE_USAGE_29I = 29;
static const uint32_t CPLT_STAT0_FREE_USAGE_30I = 30;
static const uint32_t CPLT_STAT0_FREE_USAGE_31I = 31;
//<< [CPLT_STAT0]
// perv/reg00004.H

//>> [EPS_THERM_WSUB2_MODE_REG]
static const uint64_t EPS_THERM_WSUB2_MODE_REG = 0x0005002full;

static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR = 0;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT = 1;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA = 2;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA_LEN = 3;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA = 5;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT = 6;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN = 4;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA = 10;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA_LEN = 2;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE = 12;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL = 13;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK = 14;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL = 16;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL_LEN = 4;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1 = 20;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1_LEN = 3;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2 = 24;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2_LEN = 3;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3 = 28;
//<< [EPS_THERM_WSUB2_MODE_REG]
// perv/reg00004.H

//>> [FSXCOMP_FSXLOG_PERV_CTRL0]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_FSI = 0x0000281aull;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_FSI_BYTE = 0x00002868ull;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_RW = 0x0005001aull;

static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_CHIPLET_EN_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_PCB_EP_RESET_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET = 2;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED = 3;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_3_6_RESERVED_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_SCIN_DC = 7;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_8_RESERVED = 8;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_FLUSH_ALIGN_OVERWRITE = 9;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED = 10;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_10_12_RESERVED_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_SBE_CG_DIS = 13;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_CG_DIS = 14;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_TP_TCPERV_VITL_FFDLYLCK_DC = 15;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_TP_VITL_CLKOFF_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_17_RESERVED = 17;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_EN_DC = 18;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED = 19;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_19_21_RESERVED_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE = 22;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_23_RESERVED = 23;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC = 24;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_TP_FENCE_PCB_DC = 25;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED = 26;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_26_27_RESERVED_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_TP_SPI_MVPD0_PROTECT = 28;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_29_RESERVED = 29;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_TP_EX_SINGLE_LPAR_EN_DC = 30;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_PERV_CTRL0_31_SPARE = 31;
//<< [FSXCOMP_FSXLOG_PERV_CTRL0]
// perv/reg00004.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL0]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_FSI = 0x00002810ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_BYTE = 0x00002840ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_RW = 0x00050010ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_0_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_1_SPARE = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_6_7_SPARE_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_1_DC = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PROTECTION_2_DC = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CFAM_PIB_SLV_RESET_DC = 10;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_11_SPARE = 11;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_12_SPARE = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_13_SPARE = 13;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SPARE_FENCE_CONTROL = 14;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC = 15;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_24_SPARE_CBS_CONTROL = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_25_SPARE_CBS_CONTROL = 25;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_26_SPARE_CBS_CONTROL = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_27_SPARE_CBS_CONTROL = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_ROOT_CTRL0_28_SPARE_RESET = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_GLOBAL_EP_RESET_DC = 31;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL0]
// perv/reg00004.H

//>> [FSXCOMP_FSXLOG_SCRATCH_REGISTER_4]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI = 0x0000283bull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI_BYTE = 0x000028ecull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW = 0x0005003bull;

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4 = 0;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_SR_SCRATCH_REGISTER_4_LEN = 32;
//<< [FSXCOMP_FSXLOG_SCRATCH_REGISTER_4]
// perv/reg00004.H

//>> [FSXCOMP_FSXLOG_SNS1LTH]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_FSI = 0x0000281dull;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE = 0x00002874ull;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_RO = 0x0005001dull;

static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A = 0;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B = 1;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A = 2;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B = 3;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A = 4;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B = 5;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A = 6;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A = 7;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B = 8;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B = 9;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A = 10;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B = 11;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A = 12;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B = 13;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A = 14;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B = 15;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_SWITCHED = 16;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A = 17;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B = 18;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A = 19;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B = 20;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A = 21;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B = 22;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A = 23;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B = 24;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A = 25;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B = 26;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A = 27;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B = 28;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A = 29;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B = 30;
static const uint32_t FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31 = 31;
//<< [FSXCOMP_FSXLOG_SNS1LTH]
// perv/reg00004.H

//>> [REC_ERR_REG3]
static const uint64_t REC_ERR_REG3 = 0x000f0014ull;

static const uint32_t REC_ERR_REG3_48_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_REG3_48_ERROR_CODE = 1;
static const uint32_t REC_ERR_REG3_48_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG3_49_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_REG3_49_ERROR_CODE = 5;
static const uint32_t REC_ERR_REG3_49_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG3_50_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_REG3_50_ERROR_CODE = 9;
static const uint32_t REC_ERR_REG3_50_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG3_51_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_REG3_51_ERROR_CODE = 13;
static const uint32_t REC_ERR_REG3_51_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG3_52_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_REG3_52_ERROR_CODE = 17;
static const uint32_t REC_ERR_REG3_52_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG3_53_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_REG3_53_ERROR_CODE = 21;
static const uint32_t REC_ERR_REG3_53_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG3_54_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_REG3_54_ERROR_CODE = 25;
static const uint32_t REC_ERR_REG3_54_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG3_55_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_REG3_55_ERROR_CODE = 29;
static const uint32_t REC_ERR_REG3_55_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG3_56_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_REG3_56_ERROR_CODE = 33;
static const uint32_t REC_ERR_REG3_56_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG3_57_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_REG3_57_ERROR_CODE = 37;
static const uint32_t REC_ERR_REG3_57_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG3_58_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_REG3_58_ERROR_CODE = 41;
static const uint32_t REC_ERR_REG3_58_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG3_59_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_REG3_59_ERROR_CODE = 45;
static const uint32_t REC_ERR_REG3_59_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG3_60_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_REG3_60_ERROR_CODE = 49;
static const uint32_t REC_ERR_REG3_60_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG3_61_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_REG3_61_ERROR_CODE = 53;
static const uint32_t REC_ERR_REG3_61_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG3_62_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_REG3_62_ERROR_CODE = 57;
static const uint32_t REC_ERR_REG3_62_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG3_63_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_REG3_63_ERROR_CODE = 61;
static const uint32_t REC_ERR_REG3_63_ERROR_CODE_LEN = 3;
//<< [REC_ERR_REG3]
// perv/reg00004.H

//>> [SPATTN]
static const uint64_t SPATTN = 0x00040002ull;

static const uint32_t SPATTN_ANY_SPATTN = 0;
static const uint32_t SPATTN_RESERVED1S = 1;
static const uint32_t SPATTN_RESERVED2S = 2;
static const uint32_t SPATTN_RESERVED3S = 3;
static const uint32_t SPATTN_PERV = 4;
static const uint32_t SPATTN_IN05 = 5;
static const uint32_t SPATTN_IN06 = 6;
static const uint32_t SPATTN_IN07 = 7;
static const uint32_t SPATTN_IN08 = 8;
static const uint32_t SPATTN_IN09 = 9;
static const uint32_t SPATTN_IN10 = 10;
static const uint32_t SPATTN_IN11 = 11;
static const uint32_t SPATTN_IN12 = 12;
static const uint32_t SPATTN_IN13 = 13;
static const uint32_t SPATTN_IN14 = 14;
static const uint32_t SPATTN_IN15 = 15;
static const uint32_t SPATTN_IN16 = 16;
static const uint32_t SPATTN_IN17 = 17;
static const uint32_t SPATTN_IN18 = 18;
static const uint32_t SPATTN_IN19 = 19;
static const uint32_t SPATTN_IN20 = 20;
static const uint32_t SPATTN_IN21 = 21;
static const uint32_t SPATTN_IN22 = 22;
static const uint32_t SPATTN_IN23 = 23;
static const uint32_t SPATTN_IN24 = 24;
static const uint32_t SPATTN_IN25 = 25;
static const uint32_t SPATTN_IN26 = 26;
static const uint32_t SPATTN_IN27 = 27;
static const uint32_t SPATTN_IN28 = 28;
static const uint32_t SPATTN_IN29 = 29;
static const uint32_t SPATTN_IN30 = 30;
static const uint32_t SPATTN_IN31 = 31;
static const uint32_t SPATTN_IN32 = 32;
static const uint32_t SPATTN_IN33 = 33;
static const uint32_t SPATTN_IN34 = 34;
static const uint32_t SPATTN_IN35 = 35;
//<< [SPATTN]
// perv/reg00004.H

//>> [TOD_LOAD_REG]
static const uint64_t TOD_LOAD_REG = 0x00040021ull;

static const uint32_t TOD_LOAD_REG_LOAD_TOD_VALUE = 0;
static const uint32_t TOD_LOAD_REG_LOAD_TOD_VALUE_LEN = 60;
static const uint32_t TOD_LOAD_REG_WOF = 60;
static const uint32_t TOD_LOAD_REG_WOF_LEN = 4;
//<< [TOD_LOAD_REG]
// perv/reg00004.H

//>> [TOD_PRI_PORT_1_CTRL_REG]
static const uint64_t TOD_PRI_PORT_1_CTRL_REG = 0x00040002ull;

static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT = 0;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_PORT_1_RX_SELECT_LEN = 3;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_03 = 3;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT = 4;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT = 6;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT = 8;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT = 10;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT = 12;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT = 14;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT = 16;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT = 18;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X0_PORT_1_TX_ENABLE = 20;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X1_PORT_1_TX_ENABLE = 21;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X2_PORT_1_TX_ENABLE = 22;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X3_PORT_1_TX_ENABLE = 23;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X4_PORT_1_TX_ENABLE = 24;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X5_PORT_1_TX_ENABLE = 25;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X6_PORT_1_TX_ENABLE = 26;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_PRI_X7_PORT_1_TX_ENABLE = 27;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31 = 28;
static const uint32_t TOD_PRI_PORT_1_CTRL_REG_REG_0X02_SPARE_28_31_LEN = 4;
//<< [TOD_PRI_PORT_1_CTRL_REG]
// perv/reg00004.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "perv/reg00004.H"
#include "perv/reg00005.H"
#endif
#endif
