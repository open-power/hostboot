/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pec_0.H $        */
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

#ifndef __p10_scom_pec_0_H_
#define __p10_scom_pec_0_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pec
{
#endif


//>> [CLK_REGION]
static const uint64_t CLK_REGION = 0x08030006ull;

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
// pec/reg00000.H

//>> [CPLT_CONF0]
static const uint64_t CPLT_CONF0_RW = 0x08000008ull;
static const uint64_t CPLT_CONF0_WO_CLEAR = 0x08000028ull;
static const uint64_t CPLT_CONF0_WO_OR = 0x08000018ull;

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
static const uint32_t CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC = 32;
static const uint32_t CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC = 33;
static const uint32_t CPLT_CONF0_CTRL_CC_SDIS_DC_N = 34;
static const uint32_t CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC = 35;
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
static const uint32_t CPLT_CONF0_TC_SKIT_CANARY_MODE_DC = 46;
static const uint32_t CPLT_CONF0_TC_TOPOLOGY_MODE_DC = 47;
static const uint32_t CPLT_CONF0_TC_TOPOLOGY_ID_DC = 48;
static const uint32_t CPLT_CONF0_TC_TOPOLOGY_ID_DC_LEN = 4;
static const uint32_t CPLT_CONF0_FREE_USAGE = 52;
static const uint32_t CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC = 53;
static const uint32_t CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC_LEN = 5;
static const uint32_t CPLT_CONF0_TC_PHY_LANEX_RX2TX_PAR_LB_EN_DC = 58;
static const uint32_t CPLT_CONF0_TC_PIPE_LANEX_TX2RX_LOOPBK_DC = 59;
static const uint32_t CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC = 60;
static const uint32_t CPLT_CONF0_TC_PHYX_NOMINAL_VP_SEL_DC_LEN = 2;
static const uint32_t CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC = 62;
static const uint32_t CPLT_CONF0_TC_PHYX_NOMINAL_VPH_SEL_DC_LEN = 2;
//<< [CPLT_CONF0]
// pec/reg00000.H

//>> [CPLT_CTRL0]
static const uint64_t CPLT_CTRL0_RW = 0x08000000ull;
static const uint64_t CPLT_CTRL0_WO_CLEAR = 0x08000020ull;
static const uint64_t CPLT_CTRL0_WO_OR = 0x08000010ull;

static const uint32_t CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC = 0;
static const uint32_t CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC = 1;
static const uint32_t CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH = 2;
static const uint32_t CPLT_CTRL0_CTRL_CC_FORCE_ALIGN = 3;
static const uint32_t CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC = 4;
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
static const uint32_t CPLT_CTRL0_RESERVED_37A = 37;
static const uint32_t CPLT_CTRL0_RESERVED_38A = 38;
static const uint32_t CPLT_CTRL0_RESERVED_39A = 39;
static const uint32_t CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC = 40;
static const uint32_t CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN = 2;
static const uint32_t CPLT_CTRL0_RESERVED_42A = 42;
static const uint32_t CPLT_CTRL0_RESERVED_43A = 43;
static const uint32_t CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC = 47;
static const uint32_t CPLT_CTRL0_FREE_USAGE_48A = 48;
static const uint32_t CPLT_CTRL0_FREE_USAGE_49A = 49;
static const uint32_t CPLT_CTRL0_FREE_USAGE_50A = 50;
static const uint32_t CPLT_CTRL0_FREE_USAGE_51A = 51;
static const uint32_t CPLT_CTRL0_FREE_USAGE_52A = 52;
static const uint32_t CPLT_CTRL0_FREE_USAGE_53A = 53;
static const uint32_t CPLT_CTRL0_FREE_USAGE_54A = 54;
static const uint32_t CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC = 55;
static const uint32_t CPLT_CTRL0_TC_JTAG_TRST0_N_DC = 56;
static const uint32_t CPLT_CTRL0_TC_JTAG_TRST1_N_DC = 57;
static const uint32_t CPLT_CTRL0_TC_JTAG_TRST2_N_DC = 58;
static const uint32_t CPLT_CTRL0_TC_JTAG_TRST3_N_DC = 59;
static const uint32_t CPLT_CTRL0_TC_JTAG_MUX0_SEL_DC = 60;
static const uint32_t CPLT_CTRL0_TC_JTAG_MUX1_SEL_DC = 61;
static const uint32_t CPLT_CTRL0_TC_JTAG_MUX2_SEL_DC = 62;
static const uint32_t CPLT_CTRL0_TC_JTAG_MUX3_SEL_DC = 63;
//<< [CPLT_CTRL0]
// pec/reg00000.H

//>> [EPS_THERM_WSUB_ERR_STATUS_REG]
static const uint64_t EPS_THERM_WSUB_ERR_STATUS_REG = 0x08050013ull;

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
// pec/reg00000.H

//>> [OPCG_ALIGN]
static const uint64_t OPCG_ALIGN = 0x08030001ull;

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
// pec/reg00000.H

//>> [XSTOP_MASK]
static const uint64_t XSTOP_MASK_RW = 0x08040040ull;
static const uint64_t XSTOP_MASK_WO_CLEAR = 0x08040060ull;
static const uint64_t XSTOP_MASK_WO_OR = 0x08040050ull;

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
// pec/reg00000.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pec/reg00000.H"
#endif
#endif
