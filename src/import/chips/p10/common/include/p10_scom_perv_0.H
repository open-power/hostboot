/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_0.H $       */
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

#ifndef __p10_scom_perv_0_H_
#define __p10_scom_perv_0_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> [CLK_REGION]
static const uint64_t CLK_REGION = 0x00030006ull;

static const uint32_t CLK_REGION_CLOCK_CMD = 0;
static const uint32_t CLK_REGION_CLOCK_CMD_LEN = 2;
static const uint32_t CLK_REGION_SLAVE_MODE = 2;
static const uint32_t CLK_REGION_MASTER_MODE = 3;
static const uint32_t CLK_REGION_CLOCK_REGION_PERV = 4;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT1 = 5;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT2 = 6;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT3 = 7;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT4 = 8;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT5 = 9;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT6 = 10;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT7 = 11;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT8 = 12;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT9 = 13;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT10 = 14;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT11 = 15;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT12 = 16;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT13 = 17;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT14 = 18;
static const uint32_t CLK_REGION_SEL_THOLD_SL = 48;
static const uint32_t CLK_REGION_SEL_THOLD_NSL = 49;
static const uint32_t CLK_REGION_SEL_THOLD_ARY = 50;
static const uint32_t CLK_REGION_CLOCK_PULSE_USE_EVEN = 52;
static const uint32_t CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK = 53;
static const uint32_t CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK = 54;
//<< [CLK_REGION]
// perv/reg00000.H

//>> [CPLT_CONF0]
static const uint64_t CPLT_CONF0_RW = 0x00000008ull;
static const uint64_t CPLT_CONF0_WO_CLEAR = 0x00000028ull;
static const uint64_t CPLT_CONF0_WO_OR = 0x00000018ull;

static const uint32_t CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC = 0;
static const uint32_t CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC_LEN = 6;
static const uint32_t CPLT_CONF0_RESERVED_6G = 6;
static const uint32_t CPLT_CONF0_RESERVED_7G = 7;
static const uint32_t CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC = 8;
static const uint32_t CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC_LEN = 6;
static const uint32_t CPLT_CONF0_RESERVED_14G = 14;
static const uint32_t CPLT_CONF0_RESERVED_15G = 15;
static const uint32_t CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC = 16;
static const uint32_t CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC_LEN = 6;
static const uint32_t CPLT_CONF0_RESERVED_22G = 22;
static const uint32_t CPLT_CONF0_RESERVED_23G = 23;
static const uint32_t CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC = 24;
static const uint32_t CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC_LEN = 6;
static const uint32_t CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC = 30;
static const uint32_t CPLT_CONF0_TC_PHYX_REFA_REFB_CLK_SEL_DC_LEN = 2;
static const uint32_t CPLT_CONF0_RESERVED_30G = 30;
static const uint32_t CPLT_CONF0_RESERVED_31G = 31;
static const uint32_t CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC = 32;
static const uint32_t CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC = 33;
static const uint32_t CPLT_CONF0_CTRL_CC_SDIS_DC_N = 34;
static const uint32_t CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC = 35;
static const uint32_t CPLT_CONF0_CTRL_CC_SCAN_DIAG = 35;
static const uint32_t CPLT_CONF0_RESERVED_TEST_CONTROL_36G = 36;
static const uint32_t CPLT_CONF0_RESERVED_TEST_CONTROL_37G = 37;
static const uint32_t CPLT_CONF0_RESERVED_TEST_CONTROL_38G = 38;
static const uint32_t CPLT_CONF0_RESERVED_TEST_CONTROL_39G = 39;
static const uint32_t CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC = 40;
static const uint32_t CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC = 41;
static const uint32_t CPLT_CONF0_RESERVED_42G = 42;
static const uint32_t CPLT_CONF0_RESERVED_43G = 43;
static const uint32_t CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN = 44;
static const uint32_t CPLT_CONF0_RESERVED_45G = 45;
static const uint32_t CPLT_CONF0_TC_IOO_EOL_TOGL_SRC = 45;
static const uint32_t CPLT_CONF0_TC_SKIT_CANARY_MODE_DC = 46;
static const uint32_t CPLT_CONF0_TC_TOPOLOGY_MODE_DC = 47;
static const uint32_t CPLT_CONF0_TC_TOPOLOGY_ID_DC = 48;
static const uint32_t CPLT_CONF0_TC_TOPOLOGY_ID_DC_LEN = 4;
static const uint32_t CPLT_CONF0_FREE_USAGE = 52;
static const uint32_t CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC = 52;
static const uint32_t CPLT_CONF0_TP_AN_NEST_PROGDLY_SETTING_DC_LEN = 4;
static const uint32_t CPLT_CONF0_FREE_USAGE_52G = 52;
static const uint32_t CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC = 53;
static const uint32_t CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC_LEN = 5;
static const uint32_t CPLT_CONF0_FREE_USAGE_53G = 53;
static const uint32_t CPLT_CONF0_FREE_USAGE_54G = 54;
static const uint32_t CPLT_CONF0_FREE_USAGE_55G = 55;
static const uint32_t CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC = 56;
static const uint32_t CPLT_CONF0_TP_AN_NEST_DCC_SETTING_DC_LEN = 8;
static const uint32_t CPLT_CONF0_FREE_USAGE_56G = 56;
static const uint32_t CPLT_CONF0_FREE_USAGE_57G = 57;
static const uint32_t CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC = 58;
static const uint32_t CPLT_CONF0_FREE_USAGE_58G = 58;
static const uint32_t CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC = 59;
static const uint32_t CPLT_CONF0_FREE_USAGE_59G = 59;
static const uint32_t CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC = 60;
static const uint32_t CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC_LEN = 2;
static const uint32_t CPLT_CONF0_FREE_USAGE_60G = 60;
static const uint32_t CPLT_CONF0_FREE_USAGE_61G = 61;
static const uint32_t CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC = 62;
static const uint32_t CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC_LEN = 2;
static const uint32_t CPLT_CONF0_FREE_USAGE_62G = 62;
static const uint32_t CPLT_CONF0_FREE_USAGE_63G = 63;
//<< [CPLT_CONF0]
// perv/reg00000.H

//>> [CPLT_CTRL0]
static const uint64_t CPLT_CTRL0_RW = 0x00000000ull;
static const uint64_t CPLT_CTRL0_WO_CLEAR = 0x00000020ull;
static const uint64_t CPLT_CTRL0_WO_OR = 0x00000010ull;

static const uint32_t CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC = 0;
static const uint32_t CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC = 1;
static const uint32_t CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH = 2;
static const uint32_t CPLT_CTRL0_CTRL_CC_FORCE_ALIGN = 3;
static const uint32_t CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC = 4;
static const uint32_t CPLT_CTRL0_TC_UNIT_AVP_MODE = 5;
static const uint32_t CPLT_CTRL0_TC_VITL_PROTECTION = 6;
static const uint32_t CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC = 8;
static const uint32_t CPLT_CTRL0_RESERVED_11A = 11;
static const uint32_t CPLT_CTRL0_TC_SKIT_MODE_BIST_DC = 12;
static const uint32_t CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC = 13;
static const uint32_t CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC = 14;
static const uint32_t CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC = 15;
static const uint32_t CPLT_CTRL0_RESERVED_18A = 18;
static const uint32_t CPLT_CTRL0_RESERVED_19A = 19;
static const uint32_t CPLT_CTRL0_TC_PSRO_SEL_DC = 20;
static const uint32_t CPLT_CTRL0_TC_PSRO_SEL_DC_LEN = 8;
static const uint32_t CPLT_CTRL0_TC_BSC_WRAPSEL_DC = 28;
static const uint32_t CPLT_CTRL0_TC_BSC_INTMODE_DC = 29;
static const uint32_t CPLT_CTRL0_TC_BSC_INV_DC = 30;
static const uint32_t CPLT_CTRL0_TC_BSC_EXTMODE_DC = 31;
static const uint32_t CPLT_CTRL0_RESERVED_32A = 32;
static const uint32_t CPLT_CTRL0_RESERVED_33A = 33;
static const uint32_t CPLT_CTRL0_RESERVED_34A = 34;
static const uint32_t CPLT_CTRL0_RESERVED_35A = 35;
static const uint32_t CPLT_CTRL0_RESERVED_36A = 36;
static const uint32_t CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC = 36;
static const uint32_t CPLT_CTRL0_RESERVED_37A = 37;
static const uint32_t CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC = 37;
static const uint32_t CPLT_CTRL0_RESERVED_38A = 38;
static const uint32_t CPLT_CTRL0_RESERVED_39A = 39;
static const uint32_t CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC = 40;
static const uint32_t CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN = 2;
static const uint32_t CPLT_CTRL0_RESERVED_42A = 42;
static const uint32_t CPLT_CTRL0_RESERVED_43A = 43;
static const uint32_t CPLT_CTRL0_CTRL_CC_DCTEST_DC = 44;
static const uint32_t CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC = 45;
static const uint32_t CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC = 46;
static const uint32_t CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC = 47;
static const uint32_t CPLT_CTRL0_FREE_USAGE_48A = 48;
static const uint32_t CPLT_CTRL0_FREE_USAGE_49A = 49;
static const uint32_t CPLT_CTRL0_FREE_USAGE_50A = 50;
static const uint32_t CPLT_CTRL0_FREE_USAGE_51A = 51;
static const uint32_t CPLT_CTRL0_FREE_USAGE_52A = 52;
static const uint32_t CPLT_CTRL0_FREE_USAGE_53A = 53;
static const uint32_t CPLT_CTRL0_FREE_USAGE_54A = 54;
static const uint32_t CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC = 55;
static const uint32_t CPLT_CTRL0_RESERVED_55A = 55;
static const uint32_t CPLT_CTRL0_TC_JTAG_TRST0_N_DC = 56;
static const uint32_t CPLT_CTRL0_FREE_USAGE_56A = 56;
static const uint32_t CPLT_CTRL0_TC_JTAG_TRST1_N_DC = 57;
static const uint32_t CPLT_CTRL0_FREE_USAGE_57A = 57;
static const uint32_t CPLT_CTRL0_TC_JTAG_TRST2_N_DC = 58;
static const uint32_t CPLT_CTRL0_FREE_USAGE_58A = 58;
static const uint32_t CPLT_CTRL0_TC_JTAG_TRST3_N_DC = 59;
static const uint32_t CPLT_CTRL0_FREE_USAGE_59A = 59;
static const uint32_t CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC = 60;
static const uint32_t CPLT_CTRL0_FREE_USAGE_60A = 60;
static const uint32_t CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC = 61;
static const uint32_t CPLT_CTRL0_FREE_USAGE_61A = 61;
static const uint32_t CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC = 62;
static const uint32_t CPLT_CTRL0_FREE_USAGE_62A = 62;
static const uint32_t CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC = 63;
static const uint32_t CPLT_CTRL0_FREE_USAGE_63A = 63;
//<< [CPLT_CTRL0]
// perv/reg00000.H

//>> [EPS_THERM_WSUB_ERR_STATUS_REG]
static const uint64_t EPS_THERM_WSUB_ERR_STATUS_REG = 0x00050013ull;

static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD = 0;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD = 1;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD = 2;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD = 3;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD = 4;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD = 5;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD = 6;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD = 7;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_ERR_HOLD = 8;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD = 9;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD = 10;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD = 11;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD = 12;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_TIMEOUT_ERR_HOLD = 13;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_F_SKITTER_ERR_HOLD = 14;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_PCB_ERR_HOLD_OUT = 15;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT = 40;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_COUNT_STATE_LT_LEN = 4;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT = 44;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_RUN_STATE_LT_LEN = 3;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_DTS_LT = 47;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_SHIFT_VOLT_LT = 48;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT = 49;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_READ_STATE_LT_LEN = 2;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT = 51;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_STATE_LT_LEN = 4;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_SAMPLE_DTS_LT = 55;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_MEASURE_VOLT_LT = 56;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_READ_CPM_LT = 57;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_WRITE_CPM_LT = 58;
static const uint32_t EPS_THERM_WSUB_ERR_STATUS_REG_UNUSED = 59;
//<< [EPS_THERM_WSUB_ERR_STATUS_REG]
// perv/reg00000.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI = 0x00002935ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FSI_BYTE = 0x00002cd4ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_WO_CLEAR = 0x00050135ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_RESET_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_BYPASS_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TPFSI_RCS_CLK_TEST_IN_DC = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SWO_FORCE_LOW = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_BLOCK_SWO = 5;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_A = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLEAR_CLK_ERROR_B = 7;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_SEL_DEL = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_DESKEW_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FILT_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_PFD_PW_SEL = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_FORCE_ERROR_HIGH = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_EN = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_TESTOUT_SEL_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_A = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_OVERRIDE_B = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_OVRBIT_LEN = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_REFCLK = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_EN_ASYNC_OUT = 31;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR]
// perv/reg00000.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL6_COPY]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI = 0x00002916ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI_BYTE = 0x00002c58ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_RW = 0x00050116ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_ROOT_CTRL6_COPY_REG_LEN = 32;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL6_COPY]
// perv/reg00000.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL8]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_FSI = 0x00002818ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE = 0x00002860ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_RW = 0x00050018ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST1_PORT_MUX_SEL_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST2_PORT_MUX_SEL_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST3_PORT_MUX_SEL_DC = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15 = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_4_15_LEN = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_TP_FSI_FENCE_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_VITL_FENCE_DC = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0_FENCE_DC = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0LL_FENCE_DC = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI0INV_FENCE_DC = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1_FENCE_DC = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSI1LL_FENCE_DC = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_TCFSI_FSIA_FENCE_DC = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31 = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_ROOT_CTRL8_24_31_LEN = 8;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL8]
// perv/reg00000.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI = 0x00002938ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_FSI_BYTE = 0x00002ce0ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR = 0x00050138ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15 = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_4_15_LEN = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TP_FSI_FENCE_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_VITL_FENCE_DC = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0_FENCE_DC = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0LL_FENCE_DC = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI0INV_FENCE_DC = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1_FENCE_DC = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSI1LL_FENCE_DC = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TCFSI_FSIA_FENCE_DC = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31 = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_ROOT_CTRL8_24_31_LEN = 8;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR]
// perv/reg00000.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL8_COPY]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI = 0x00002918ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_FSI_BYTE = 0x00002c60ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_RW = 0x00050118ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_COPY_ROOT_CTRL8_COPY_REG_LEN = 32;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL8_COPY]
// perv/reg00000.H

//>> [HOSTATTN]
static const uint64_t HOSTATTN = 0x00040004ull;

static const uint32_t HOSTATTN_ANY_HOSTATTN = 0;
static const uint32_t HOSTATTN_RESERVED1H = 1;
static const uint32_t HOSTATTN_RESERVED2H = 2;
static const uint32_t HOSTATTN_RESERVED3H = 3;
static const uint32_t HOSTATTN_PERV = 4;
static const uint32_t HOSTATTN_IN05 = 5;
static const uint32_t HOSTATTN_IN06 = 6;
static const uint32_t HOSTATTN_IN07 = 7;
static const uint32_t HOSTATTN_IN08 = 8;
static const uint32_t HOSTATTN_IN09 = 9;
static const uint32_t HOSTATTN_IN10 = 10;
static const uint32_t HOSTATTN_IN11 = 11;
static const uint32_t HOSTATTN_IN12 = 12;
static const uint32_t HOSTATTN_IN13 = 13;
static const uint32_t HOSTATTN_IN14 = 14;
static const uint32_t HOSTATTN_IN15 = 15;
static const uint32_t HOSTATTN_IN16 = 16;
static const uint32_t HOSTATTN_IN17 = 17;
static const uint32_t HOSTATTN_IN18 = 18;
static const uint32_t HOSTATTN_IN19 = 19;
static const uint32_t HOSTATTN_IN20 = 20;
static const uint32_t HOSTATTN_IN21 = 21;
static const uint32_t HOSTATTN_IN22 = 22;
static const uint32_t HOSTATTN_IN23 = 23;
static const uint32_t HOSTATTN_IN24 = 24;
static const uint32_t HOSTATTN_IN25 = 25;
static const uint32_t HOSTATTN_IN26 = 26;
static const uint32_t HOSTATTN_IN27 = 27;
static const uint32_t HOSTATTN_IN28 = 28;
static const uint32_t HOSTATTN_IN29 = 29;
static const uint32_t HOSTATTN_IN30 = 30;
static const uint32_t HOSTATTN_IN31 = 31;
static const uint32_t HOSTATTN_IN32 = 32;
static const uint32_t HOSTATTN_IN33 = 33;
static const uint32_t HOSTATTN_IN34 = 34;
static const uint32_t HOSTATTN_IN35 = 35;
static const uint32_t HOSTATTN_IN36 = 36;
static const uint32_t HOSTATTN_IN37 = 37;
static const uint32_t HOSTATTN_IN38 = 38;
static const uint32_t HOSTATTN_IN39 = 39;
static const uint32_t HOSTATTN_IN40 = 40;
static const uint32_t HOSTATTN_IN41 = 41;
static const uint32_t HOSTATTN_IN42 = 42;
static const uint32_t HOSTATTN_IN43 = 43;
static const uint32_t HOSTATTN_IN44 = 44;
static const uint32_t HOSTATTN_IN45 = 45;
static const uint32_t HOSTATTN_IN46 = 46;
static const uint32_t HOSTATTN_IN47 = 47;
static const uint32_t HOSTATTN_IN48 = 48;
static const uint32_t HOSTATTN_IN49 = 49;
static const uint32_t HOSTATTN_IN50 = 50;
static const uint32_t HOSTATTN_IN51 = 51;
static const uint32_t HOSTATTN_IN52 = 52;
static const uint32_t HOSTATTN_IN53 = 53;
//<< [HOSTATTN]
// perv/reg00000.H

//>> [HOSTATTN_MASK]
static const uint64_t HOSTATTN_MASK_RW = 0x00040044ull;
static const uint64_t HOSTATTN_MASK_WO_CLEAR = 0x00040064ull;
static const uint64_t HOSTATTN_MASK_WO_OR = 0x00040054ull;

static const uint32_t HOSTATTN_MASK_01 = 1;
static const uint32_t HOSTATTN_MASK_02 = 2;
static const uint32_t HOSTATTN_MASK_03 = 3;
static const uint32_t HOSTATTN_MASK_04 = 4;
static const uint32_t HOSTATTN_MASK_05 = 5;
static const uint32_t HOSTATTN_MASK_06 = 6;
static const uint32_t HOSTATTN_MASK_07 = 7;
static const uint32_t HOSTATTN_MASK_08 = 8;
static const uint32_t HOSTATTN_MASK_09 = 9;
static const uint32_t HOSTATTN_MASK_10 = 10;
static const uint32_t HOSTATTN_MASK_11 = 11;
static const uint32_t HOSTATTN_MASK_12 = 12;
static const uint32_t HOSTATTN_MASK_13 = 13;
static const uint32_t HOSTATTN_MASK_14 = 14;
static const uint32_t HOSTATTN_MASK_15 = 15;
static const uint32_t HOSTATTN_MASK_16 = 16;
static const uint32_t HOSTATTN_MASK_17 = 17;
static const uint32_t HOSTATTN_MASK_18 = 18;
static const uint32_t HOSTATTN_MASK_19 = 19;
static const uint32_t HOSTATTN_MASK_20 = 20;
static const uint32_t HOSTATTN_MASK_21 = 21;
static const uint32_t HOSTATTN_MASK_22 = 22;
static const uint32_t HOSTATTN_MASK_23 = 23;
static const uint32_t HOSTATTN_MASK_24 = 24;
static const uint32_t HOSTATTN_MASK_25 = 25;
static const uint32_t HOSTATTN_MASK_26 = 26;
static const uint32_t HOSTATTN_MASK_27 = 27;
static const uint32_t HOSTATTN_MASK_28 = 28;
static const uint32_t HOSTATTN_MASK_29 = 29;
static const uint32_t HOSTATTN_MASK_30 = 30;
static const uint32_t HOSTATTN_MASK_31 = 31;
static const uint32_t HOSTATTN_MASK_32 = 32;
static const uint32_t HOSTATTN_MASK_33 = 33;
static const uint32_t HOSTATTN_MASK_34 = 34;
static const uint32_t HOSTATTN_MASK_35 = 35;
static const uint32_t HOSTATTN_MASK_36 = 36;
static const uint32_t HOSTATTN_MASK_37 = 37;
static const uint32_t HOSTATTN_MASK_38 = 38;
static const uint32_t HOSTATTN_MASK_39 = 39;
static const uint32_t HOSTATTN_MASK_40 = 40;
static const uint32_t HOSTATTN_MASK_41 = 41;
static const uint32_t HOSTATTN_MASK_42 = 42;
static const uint32_t HOSTATTN_MASK_43 = 43;
static const uint32_t HOSTATTN_MASK_44 = 44;
static const uint32_t HOSTATTN_MASK_45 = 45;
static const uint32_t HOSTATTN_MASK_46 = 46;
static const uint32_t HOSTATTN_MASK_47 = 47;
static const uint32_t HOSTATTN_MASK_48 = 48;
static const uint32_t HOSTATTN_MASK_49 = 49;
static const uint32_t HOSTATTN_MASK_50 = 50;
static const uint32_t HOSTATTN_MASK_51 = 51;
static const uint32_t HOSTATTN_MASK_52 = 52;
static const uint32_t HOSTATTN_MASK_53 = 53;
//<< [HOSTATTN_MASK]
// perv/reg00000.H

//>> [OPCG_ALIGN]
static const uint64_t OPCG_ALIGN = 0x00030001ull;

static const uint32_t OPCG_ALIGN_INOP_ALIGN = 0;
static const uint32_t OPCG_ALIGN_INOP_ALIGN_LEN = 4;
static const uint32_t OPCG_ALIGN_SNOP_ALIGN = 4;
static const uint32_t OPCG_ALIGN_SNOP_ALIGN_LEN = 4;
static const uint32_t OPCG_ALIGN_ENOP_ALIGN = 8;
static const uint32_t OPCG_ALIGN_ENOP_ALIGN_LEN = 4;
static const uint32_t OPCG_ALIGN_INOP_WAIT = 12;
static const uint32_t OPCG_ALIGN_INOP_WAIT_LEN = 8;
static const uint32_t OPCG_ALIGN_SNOP_WAIT = 20;
static const uint32_t OPCG_ALIGN_SNOP_WAIT_LEN = 12;
static const uint32_t OPCG_ALIGN_ENOP_WAIT = 32;
static const uint32_t OPCG_ALIGN_ENOP_WAIT_LEN = 8;
static const uint32_t OPCG_ALIGN_INOP_FORCE_SG = 40;
static const uint32_t OPCG_ALIGN_SNOP_FORCE_SG = 41;
static const uint32_t OPCG_ALIGN_ENOP_FORCE_SG = 42;
static const uint32_t OPCG_ALIGN_NO_WAIT_ON_CLK_CMD = 43;
static const uint32_t OPCG_ALIGN_ALIGN_SOURCE_SELECT = 44;
static const uint32_t OPCG_ALIGN_ALIGN_SOURCE_SELECT_LEN = 2;
static const uint32_t OPCG_ALIGN_SCAN_RATIO = 47;
static const uint32_t OPCG_ALIGN_SCAN_RATIO_LEN = 5;
static const uint32_t OPCG_ALIGN_OPCG_WAIT_CYCLES = 52;
static const uint32_t OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN = 12;
//<< [OPCG_ALIGN]
// perv/reg00000.H

//>> [REC_ERR_MST14_REG3]
static const uint64_t REC_ERR_MST14_REG3 = 0x000f007bull;

static const uint32_t REC_ERR_MST14_REG3_48_MST14_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST14_REG3_48_MST14_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST14_REG3_48_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG3_49_MST14_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST14_REG3_49_MST14_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST14_REG3_49_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG3_50_MST14_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST14_REG3_50_MST14_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST14_REG3_50_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG3_51_MST14_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST14_REG3_51_MST14_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST14_REG3_51_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG3_52_MST14_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST14_REG3_52_MST14_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST14_REG3_52_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG3_53_MST14_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST14_REG3_53_MST14_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST14_REG3_53_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG3_54_MST14_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST14_REG3_54_MST14_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST14_REG3_54_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG3_55_MST14_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST14_REG3_55_MST14_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST14_REG3_55_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG3_56_MST14_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST14_REG3_56_MST14_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST14_REG3_56_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG3_57_MST14_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST14_REG3_57_MST14_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST14_REG3_57_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG3_58_MST14_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST14_REG3_58_MST14_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST14_REG3_58_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG3_59_MST14_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST14_REG3_59_MST14_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST14_REG3_59_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG3_60_MST14_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST14_REG3_60_MST14_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST14_REG3_60_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG3_61_MST14_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST14_REG3_61_MST14_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST14_REG3_61_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG3_62_MST14_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST14_REG3_62_MST14_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST14_REG3_62_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG3_63_MST14_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST14_REG3_63_MST14_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST14_REG3_63_MST14_ERROR_CODE_LEN = 3;
//<< [REC_ERR_MST14_REG3]
// perv/reg00000.H

//>> [RESET_REG]
static const uint64_t RESET_REG = 0x000f001dull;

static const uint32_t RESET_REG_RESET_PCB = 0;
static const uint32_t RESET_REG_RESET_ENDPOINTS = 1;
static const uint32_t RESET_REG_TIMEOUT_RESET_EN = 2;
static const uint32_t RESET_REG_QUIESCE_PCB = 3; // p10:20,
//<< [RESET_REG]
// perv/reg00001.H

//>> [TOD_MISC_RESET_REG]
static const uint64_t TOD_MISC_RESET_REG = 0x0004000bull;

static const uint32_t TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE = 0;
static const uint32_t TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE = 1;
static const uint32_t TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE = 2;
static const uint32_t TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE = 3;
static const uint32_t TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05 = 4;
static const uint32_t TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05_LEN = 2;
static const uint32_t TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE = 6;
static const uint32_t TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE = 7;
static const uint32_t TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE = 8;
static const uint32_t TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE = 9;
static const uint32_t TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE = 10;
static const uint32_t TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE = 11;
// ERROR Duplicate Dial         static const uint32_t TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE = 12;
static const uint32_t TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER = 13;
static const uint32_t TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE = 14;
static const uint32_t TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER = 15;
static const uint32_t TOD_MISC_RESET_REG_TRACE_ENABLE = 16;
static const uint32_t TOD_MISC_RESET_REG_REG_0X0B_SPARE_17 = 17;
static const uint32_t TOD_MISC_RESET_REG_TRACE_DATA_SELECT = 18;
static const uint32_t TOD_MISC_RESET_REG_TRACE_DATA_SELECT_LEN = 2;
static const uint32_t TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE = 20;
static const uint32_t TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE = 21;
static const uint32_t TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD = 22;
static const uint32_t TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET = 23;
static const uint32_t TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE = 24;
static const uint32_t TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE_LEN = 9;
static const uint32_t TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39 = 33;
static const uint32_t TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39_LEN = 7;
//<< [TOD_MISC_RESET_REG]
// perv/reg00001.H

//>> [TOD_SEC_PORT_0_CTRL_REG]
static const uint64_t TOD_SEC_PORT_0_CTRL_REG = 0x00040003ull;

static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT = 0;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT_LEN = 3;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03 = 3;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT = 4;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT = 6;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT = 8;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT = 10;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT = 12;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT = 14;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT = 16;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT = 18;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE = 20;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE = 21;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE = 22;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE = 23;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE = 24;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE = 25;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE = 26;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE = 27;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31 = 28;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31_LEN = 4;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29 = 28; // p10:20,
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29_LEN = 2;
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE = 30; // p10:20,
static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE_LEN = 10;
// ERROR Duplicate Dial         static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE = 32;
// ERROR Duplicate Dial         static const uint32_t TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE_LEN = 8;
//<< [TOD_SEC_PORT_0_CTRL_REG]
// perv/reg00001.H

//>> [XSTOP_MASK]
static const uint64_t XSTOP_MASK_RW = 0x00040040ull;
static const uint64_t XSTOP_MASK_WO_CLEAR = 0x00040060ull;
static const uint64_t XSTOP_MASK_WO_OR = 0x00040050ull;

static const uint32_t XSTOP_MASK_01 = 1;
static const uint32_t XSTOP_MASK_02 = 2;
static const uint32_t XSTOP_MASK_03 = 3;
static const uint32_t XSTOP_MASK_04 = 4;
static const uint32_t XSTOP_MASK_05 = 5;
static const uint32_t XSTOP_MASK_06 = 6;
static const uint32_t XSTOP_MASK_07 = 7;
static const uint32_t XSTOP_MASK_08 = 8;
static const uint32_t XSTOP_MASK_09 = 9;
static const uint32_t XSTOP_MASK_10 = 10;
static const uint32_t XSTOP_MASK_11 = 11;
static const uint32_t XSTOP_MASK_12 = 12;
static const uint32_t XSTOP_MASK_13 = 13;
static const uint32_t XSTOP_MASK_14 = 14;
static const uint32_t XSTOP_MASK_15 = 15;
static const uint32_t XSTOP_MASK_16 = 16;
static const uint32_t XSTOP_MASK_17 = 17;
static const uint32_t XSTOP_MASK_18 = 18;
static const uint32_t XSTOP_MASK_19 = 19;
static const uint32_t XSTOP_MASK_20 = 20;
static const uint32_t XSTOP_MASK_21 = 21;
static const uint32_t XSTOP_MASK_22 = 22;
static const uint32_t XSTOP_MASK_23 = 23;
static const uint32_t XSTOP_MASK_24 = 24;
static const uint32_t XSTOP_MASK_25 = 25;
static const uint32_t XSTOP_MASK_26 = 26;
static const uint32_t XSTOP_MASK_27 = 27;
static const uint32_t XSTOP_MASK_28 = 28;
static const uint32_t XSTOP_MASK_29 = 29;
static const uint32_t XSTOP_MASK_30 = 30;
static const uint32_t XSTOP_MASK_31 = 31;
static const uint32_t XSTOP_MASK_32 = 32;
static const uint32_t XSTOP_MASK_33 = 33;
static const uint32_t XSTOP_MASK_34 = 34;
static const uint32_t XSTOP_MASK_35 = 35;
static const uint32_t XSTOP_MASK_36 = 36;
static const uint32_t XSTOP_MASK_37 = 37;
static const uint32_t XSTOP_MASK_38 = 38;
static const uint32_t XSTOP_MASK_39 = 39;
static const uint32_t XSTOP_MASK_40 = 40;
static const uint32_t XSTOP_MASK_41 = 41;
static const uint32_t XSTOP_MASK_42 = 42;
static const uint32_t XSTOP_MASK_43 = 43;
static const uint32_t XSTOP_MASK_44 = 44;
static const uint32_t XSTOP_MASK_45 = 45;
static const uint32_t XSTOP_MASK_46 = 46;
static const uint32_t XSTOP_MASK_47 = 47;
static const uint32_t XSTOP_MASK_48 = 48;
static const uint32_t XSTOP_MASK_49 = 49;
static const uint32_t XSTOP_MASK_50 = 50;
static const uint32_t XSTOP_MASK_51 = 51;
static const uint32_t XSTOP_MASK_52 = 52;
static const uint32_t XSTOP_MASK_53 = 53;
//<< [XSTOP_MASK]
// perv/reg00001.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "perv/reg00000.H"
#include "perv/reg00001.H"
#endif
#endif
