/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_0.H $         */
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

#ifndef __p10_scom_eq_0_H_
#define __p10_scom_eq_0_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> [CLK_REGION]
static const uint64_t CLK_REGION = 0x20030006ull;

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
// eq/reg00000.H

//>> [CPLT_CONF0]
static const uint64_t CPLT_CONF0_RW = 0x20000008ull;
static const uint64_t CPLT_CONF0_WO_CLEAR = 0x20000028ull;
static const uint64_t CPLT_CONF0_WO_OR = 0x20000018ull;

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
static const uint32_t CPLT_CONF0_RESERVED_30G = 30;
static const uint32_t CPLT_CONF0_RESERVED_31G = 31;
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
static const uint32_t CPLT_CONF0_FREE_USAGE_52G = 52;
static const uint32_t CPLT_CONF0_FREE_USAGE_53G = 53;
static const uint32_t CPLT_CONF0_FREE_USAGE_54G = 54;
static const uint32_t CPLT_CONF0_FREE_USAGE_55G = 55;
static const uint32_t CPLT_CONF0_FREE_USAGE_56G = 56;
static const uint32_t CPLT_CONF0_FREE_USAGE_57G = 57;
static const uint32_t CPLT_CONF0_FREE_USAGE_58G = 58;
static const uint32_t CPLT_CONF0_FREE_USAGE_59G = 59;
static const uint32_t CPLT_CONF0_FREE_USAGE_60G = 60;
static const uint32_t CPLT_CONF0_FREE_USAGE_61G = 61;
static const uint32_t CPLT_CONF0_FREE_USAGE_62G = 62;
static const uint32_t CPLT_CONF0_FREE_USAGE_63G = 63;
//<< [CPLT_CONF0]
// eq/reg00000.H

//>> [CPLT_CTRL0]
static const uint64_t CPLT_CTRL0_RW = 0x20000000ull;
static const uint64_t CPLT_CTRL0_WO_CLEAR = 0x20000020ull;
static const uint64_t CPLT_CTRL0_WO_OR = 0x20000010ull;

static const uint32_t CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC = 0;
static const uint32_t CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH = 2;
static const uint32_t CPLT_CTRL0_CTRL_CC_FORCE_ALIGN = 3;
static const uint32_t CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC = 4;
static const uint32_t CPLT_CTRL0_TC_UNIT_AVP_MODE = 5;
static const uint32_t CPLT_CTRL0_TC_VITL_PROTECTION = 6;
static const uint32_t CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC = 8;
static const uint32_t CPLT_CTRL0_RESERVED_11A = 11;
static const uint32_t CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC = 13;
static const uint32_t CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC = 14;
static const uint32_t CPLT_CTRL0_RESERVED_18A = 18;
static const uint32_t CPLT_CTRL0_RESERVED_19A = 19;
static const uint32_t CPLT_CTRL0_TC_PSRO_SEL_DC = 20;
static const uint32_t CPLT_CTRL0_TC_PSRO_SEL_DC_LEN = 8;
static const uint32_t CPLT_CTRL0_RESERVED_32A = 32;
static const uint32_t CPLT_CTRL0_RESERVED_33A = 33;
static const uint32_t CPLT_CTRL0_RESERVED_34A = 34;
static const uint32_t CPLT_CTRL0_RESERVED_35A = 35;
static const uint32_t CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC = 36;
static const uint32_t CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC = 37;
static const uint32_t CPLT_CTRL0_RESERVED_38A = 38;
static const uint32_t CPLT_CTRL0_RESERVED_39A = 39;
static const uint32_t CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC = 40;
static const uint32_t CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN = 2;
static const uint32_t CPLT_CTRL0_RESERVED_42A = 42;
static const uint32_t CPLT_CTRL0_RESERVED_43A = 43;
static const uint32_t CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC = 46;
static const uint32_t CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC = 47;
static const uint32_t CPLT_CTRL0_FREE_USAGE_48A = 48;
static const uint32_t CPLT_CTRL0_FREE_USAGE_49A = 49;
static const uint32_t CPLT_CTRL0_FREE_USAGE_50A = 50;
static const uint32_t CPLT_CTRL0_FREE_USAGE_51A = 51;
static const uint32_t CPLT_CTRL0_FREE_USAGE_52A = 52;
static const uint32_t CPLT_CTRL0_FREE_USAGE_53A = 53;
static const uint32_t CPLT_CTRL0_FREE_USAGE_54A = 54;
static const uint32_t CPLT_CTRL0_RESERVED_55A = 55;
static const uint32_t CPLT_CTRL0_FREE_USAGE_56A = 56;
static const uint32_t CPLT_CTRL0_FREE_USAGE_57A = 57;
static const uint32_t CPLT_CTRL0_FREE_USAGE_58A = 58;
static const uint32_t CPLT_CTRL0_FREE_USAGE_59A = 59;
static const uint32_t CPLT_CTRL0_FREE_USAGE_60A = 60;
static const uint32_t CPLT_CTRL0_FREE_USAGE_61A = 61;
static const uint32_t CPLT_CTRL0_FREE_USAGE_62A = 62;
static const uint32_t CPLT_CTRL0_FREE_USAGE_63A = 63;
//<< [CPLT_CTRL0]
// eq/reg00000.H

//>> [EPS_THERM_WSUB_ERR_STATUS_REG]
static const uint64_t EPS_THERM_WSUB_ERR_STATUS_REG = 0x20050013ull;

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
// eq/reg00000.H

//>> [HOSTATTN]
static const uint64_t HOSTATTN = 0x20040004ull;

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
// eq/reg00000.H

//>> [HOSTATTN_MASK]
static const uint64_t HOSTATTN_MASK_RW = 0x20040044ull;
static const uint64_t HOSTATTN_MASK_WO_CLEAR = 0x20040064ull;
static const uint64_t HOSTATTN_MASK_WO_OR = 0x20040054ull;

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
// eq/reg00000.H

//>> [OPCG_ALIGN]
static const uint64_t OPCG_ALIGN = 0x20030001ull;

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
// eq/reg00000.H

//>> [QME_BCECSR]
static const uint64_t QME_BCECSR = 0x200e0068ull;

static const uint32_t QME_BCECSR_BUSY = 0;
static const uint32_t QME_BCECSR_ERROR = 1;
static const uint32_t QME_BCECSR_START = 2;
static const uint32_t QME_BCECSR_STOP = 3;
static const uint32_t QME_BCECSR_RNW = 4;
static const uint32_t QME_BCECSR_BARSEL = 5;
static const uint32_t QME_BCECSR_PRIORITY = 6;
static const uint32_t QME_BCECSR_INJECT_ERR = 7;
static const uint32_t QME_BCECSR_TYPE = 13;
static const uint32_t QME_BCECSR_TYPE_LEN = 3;
static const uint32_t QME_BCECSR_NUM_BLOCKS = 17;
static const uint32_t QME_BCECSR_NUM_BLOCKS_LEN = 11;
static const uint32_t QME_BCECSR_SBASE = 28;
static const uint32_t QME_BCECSR_SBASE_LEN = 13;
static const uint32_t QME_BCECSR_MBASE = 42;
static const uint32_t QME_BCECSR_MBASE_LEN = 22;
//<< [QME_BCECSR]
// eq/reg00000.H

//>> [QME_PSREQ]
static const uint64_t QME_PSREQ = 0x200e0130ull;

static const uint32_t QME_PSREQ_PSTATE_REQ_C0 = 0;
static const uint32_t QME_PSREQ_PSTATE_REQ_C0_LEN = 8;
static const uint32_t QME_PSREQ_PSTATE_REQ_C1 = 8;
static const uint32_t QME_PSREQ_PSTATE_REQ_C1_LEN = 8;
static const uint32_t QME_PSREQ_PSTATE_REQ_C2 = 16;
static const uint32_t QME_PSREQ_PSTATE_REQ_C2_LEN = 8;
static const uint32_t QME_PSREQ_PSTATE_REQ_C3 = 24;
static const uint32_t QME_PSREQ_PSTATE_REQ_C3_LEN = 8;
static const uint32_t QME_PSREQ_PSTATE_REQ_QUAD = 32;
static const uint32_t QME_PSREQ_PSTATE_REQ_QUAD_LEN = 8;
static const uint32_t QME_PSREQ_RECENT_CORE_NUM = 42;
static const uint32_t QME_PSREQ_RECENT_CORE_NUM_LEN = 2;
static const uint32_t QME_PSREQ_PSTATE_UPDATE = 44;
static const uint32_t QME_PSREQ_PSTATE_UPDATE_LEN = 4;
static const uint32_t QME_PSREQ_QME_QMCR_CORE_PARTIAL_GOOD = 48;
static const uint32_t QME_PSREQ_QME_QMCR_CORE_PARTIAL_GOOD_LEN = 4;
static const uint32_t QME_PSREQ_QME_QMCR_AUTO_PMCR_UPDATE = 52;
static const uint32_t QME_PSREQ_QME_QMCR_PMCR_RECENT_MODE = 53;
static const uint32_t QME_PSREQ_PMCR_PIG_PENDING = 55;
//<< [QME_PSREQ]
// eq/reg00000.H

//>> [QME_QHTMODE]
static const uint64_t QME_QHTMODE = 0x200e01a0ull;

static const uint32_t QME_QHTMODE_HTM_ENABLE = 0;
static const uint32_t QME_QHTMODE_MODE_WRAP = 1;
static const uint32_t QME_QHTMODE_DIS_TSTAMP = 2;
static const uint32_t QME_QHTMODE_SINGLE_TSTAMP = 3;
//<< [QME_QHTMODE]
// eq/reg00000.H

//>> [QME_RCOCR]
static const uint64_t QME_RCOCR = 0x200e017cull;

static const uint32_t QME_RCOCR_0_RESCLK_CONTROL = 0;
static const uint32_t QME_RCOCR_0_RESCLK_CONTROL_LEN = 8;
static const uint32_t QME_RCOCR_1_RESCLK_CONTROL = 8;
static const uint32_t QME_RCOCR_1_RESCLK_CONTROL_LEN = 8;
static const uint32_t QME_RCOCR_2_RESCLK_CONTROL = 16;
static const uint32_t QME_RCOCR_2_RESCLK_CONTROL_LEN = 8;
static const uint32_t QME_RCOCR_3_RESCLK_CONTROL = 24;
static const uint32_t QME_RCOCR_3_RESCLK_CONTROL_LEN = 8;
static const uint32_t QME_RCOCR_0_RESCLK_ACTUAL = 32;
static const uint32_t QME_RCOCR_0_RESCLK_ACTUAL_LEN = 8;
static const uint32_t QME_RCOCR_1_RESCLK_ACTUAL = 40;
static const uint32_t QME_RCOCR_1_RESCLK_ACTUAL_LEN = 8;
static const uint32_t QME_RCOCR_2_RESCLK_ACTUAL = 48;
static const uint32_t QME_RCOCR_2_RESCLK_ACTUAL_LEN = 8;
static const uint32_t QME_RCOCR_3_RESCLK_ACTUAL = 56;
static const uint32_t QME_RCOCR_3_RESCLK_ACTUAL_LEN = 8;
//<< [QME_RCOCR]
// eq/reg00000.H

//>> [QME_RCTAR3]
static const uint64_t QME_RCTAR3 = 0x200e019cull;

static const uint32_t QME_RCTAR3_DATA = 0;
static const uint32_t QME_RCTAR3_DATA_LEN = 64;
//<< [QME_RCTAR3]
// eq/reg00000.H

//>> [QME_SCOM_PBTXTR2]
static const uint64_t QME_SCOM_PBTXTR2 = 0x200e0042ull;

static const uint32_t QME_SCOM_PBTXTR2_VALID = 0;
static const uint32_t QME_SCOM_PBTXTR2_VALID_LEN = 8;
static const uint32_t QME_SCOM_PBTXTR2_0 = 8;
static const uint32_t QME_SCOM_PBTXTR2_0_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR2_1 = 12;
static const uint32_t QME_SCOM_PBTXTR2_1_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR2_2 = 16;
static const uint32_t QME_SCOM_PBTXTR2_2_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR2_3 = 20;
static const uint32_t QME_SCOM_PBTXTR2_3_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR2_4 = 24;
static const uint32_t QME_SCOM_PBTXTR2_4_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR2_5 = 28;
static const uint32_t QME_SCOM_PBTXTR2_5_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR2_6 = 32;
static const uint32_t QME_SCOM_PBTXTR2_6_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR2_7 = 36;
static const uint32_t QME_SCOM_PBTXTR2_7_LEN = 4;
//<< [QME_SCOM_PBTXTR2]
// eq/reg00000.H

//>> [QME_SCOM_XIVDRX]
static const uint64_t QME_SCOM_XIVDRX = 0x200e0294ull;

static const uint32_t QME_SCOM_XIVDRX_0 = 0;
static const uint32_t QME_SCOM_XIVDRX_0_LEN = 32;
static const uint32_t QME_SCOM_XIVDRX_3 = 32;
static const uint32_t QME_SCOM_XIVDRX_3_LEN = 32;
//<< [QME_SCOM_XIVDRX]
// eq/reg00000.H

//>> [XSTOP_MASK]
static const uint64_t XSTOP_MASK_RW = 0x20040040ull;
static const uint64_t XSTOP_MASK_WO_CLEAR = 0x20040060ull;
static const uint64_t XSTOP_MASK_WO_OR = 0x20040050ull;

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
// eq/reg00000.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00000.H"
#endif
#endif
