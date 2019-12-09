/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_e.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#ifndef __p10_scom_iohs_e_H_
#define __p10_scom_iohs_e_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


static const uint64_t AXON_CLK_REGION = 0x18030006ull;

static const uint32_t AXON_CLK_REGION_CLOCK_CMD = 0;
static const uint32_t AXON_CLK_REGION_CLOCK_CMD_LEN = 2;
static const uint32_t AXON_CLK_REGION_SLAVE_MODE = 2;
static const uint32_t AXON_CLK_REGION_MASTER_MODE = 3;
static const uint32_t AXON_CLK_REGION_CLOCK_REGION_PERV = 4;
static const uint32_t AXON_CLK_REGION_CLOCK_REGION_UNIT1 = 5;
static const uint32_t AXON_CLK_REGION_CLOCK_REGION_UNIT2 = 6;
static const uint32_t AXON_CLK_REGION_CLOCK_REGION_UNIT3 = 7;
static const uint32_t AXON_CLK_REGION_CLOCK_REGION_UNIT4 = 8;
static const uint32_t AXON_CLK_REGION_CLOCK_REGION_UNIT5 = 9;
static const uint32_t AXON_CLK_REGION_CLOCK_REGION_UNIT6 = 10;
static const uint32_t AXON_CLK_REGION_CLOCK_REGION_UNIT7 = 11;
static const uint32_t AXON_CLK_REGION_CLOCK_REGION_UNIT8 = 12;
static const uint32_t AXON_CLK_REGION_CLOCK_REGION_UNIT9 = 13;
static const uint32_t AXON_CLK_REGION_CLOCK_REGION_UNIT10 = 14;
static const uint32_t AXON_CLK_REGION_CLOCK_REGION_UNIT11 = 15;
static const uint32_t AXON_CLK_REGION_CLOCK_REGION_UNIT12 = 16;
static const uint32_t AXON_CLK_REGION_CLOCK_REGION_UNIT13 = 17;
static const uint32_t AXON_CLK_REGION_CLOCK_REGION_UNIT14 = 18;
static const uint32_t AXON_CLK_REGION_SEL_THOLD_SL = 48;
static const uint32_t AXON_CLK_REGION_SEL_THOLD_NSL = 49;
static const uint32_t AXON_CLK_REGION_SEL_THOLD_ARY = 50;
static const uint32_t AXON_CLK_REGION_CLOCK_PULSE_USE_EVEN = 52;
static const uint32_t AXON_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK = 53;
static const uint32_t AXON_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK = 54;
// iohs/reg00060.H

static const uint64_t AXON_CPLT_CONF0_RW = 0x18000008ull;
static const uint64_t AXON_CPLT_CONF0_WO_CLEAR = 0x18000028ull;
static const uint64_t AXON_CPLT_CONF0_WO_OR = 0x18000018ull;

static const uint32_t AXON_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC = 0;
static const uint32_t AXON_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC_LEN = 6;
static const uint32_t AXON_CPLT_CONF0_RESERVED_6G = 6;
static const uint32_t AXON_CPLT_CONF0_RESERVED_7G = 7;
static const uint32_t AXON_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC = 8;
static const uint32_t AXON_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC_LEN = 6;
static const uint32_t AXON_CPLT_CONF0_RESERVED_14G = 14;
static const uint32_t AXON_CPLT_CONF0_RESERVED_15G = 15;
static const uint32_t AXON_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC = 16;
static const uint32_t AXON_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC_LEN = 6;
static const uint32_t AXON_CPLT_CONF0_RESERVED_22G = 22;
static const uint32_t AXON_CPLT_CONF0_RESERVED_23G = 23;
static const uint32_t AXON_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC = 24;
static const uint32_t AXON_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC_LEN = 6;
static const uint32_t AXON_CPLT_CONF0_RESERVED_30G = 30;
static const uint32_t AXON_CPLT_CONF0_RESERVED_31G = 31;
static const uint32_t AXON_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC = 33;
static const uint32_t AXON_CPLT_CONF0_CTRL_CC_SDIS_DC_N = 34;
static const uint32_t AXON_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC = 35;
static const uint32_t AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_36G = 36;
static const uint32_t AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_37G = 37;
static const uint32_t AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_38G = 38;
static const uint32_t AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_39G = 39;
static const uint32_t AXON_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC = 40;
static const uint32_t AXON_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC = 41;
static const uint32_t AXON_CPLT_CONF0_RESERVED_42G = 42;
static const uint32_t AXON_CPLT_CONF0_RESERVED_43G = 43;
static const uint32_t AXON_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN = 44;
static const uint32_t AXON_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC = 45;
static const uint32_t AXON_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC = 46;
static const uint32_t AXON_CPLT_CONF0_TC_TOPOLOGY_MODE_DC = 47;
static const uint32_t AXON_CPLT_CONF0_TC_TOPOLOGY_ID_DC = 48;
static const uint32_t AXON_CPLT_CONF0_TC_TOPOLOGY_ID_DC_LEN = 4;
static const uint32_t AXON_CPLT_CONF0_FREE_USAGE_52G = 52;
static const uint32_t AXON_CPLT_CONF0_FREE_USAGE_53G = 53;
static const uint32_t AXON_CPLT_CONF0_FREE_USAGE_54G = 54;
static const uint32_t AXON_CPLT_CONF0_FREE_USAGE_55G = 55;
static const uint32_t AXON_CPLT_CONF0_FREE_USAGE_56G = 56;
static const uint32_t AXON_CPLT_CONF0_FREE_USAGE_57G = 57;
static const uint32_t AXON_CPLT_CONF0_FREE_USAGE_58G = 58;
static const uint32_t AXON_CPLT_CONF0_FREE_USAGE_59G = 59;
static const uint32_t AXON_CPLT_CONF0_FREE_USAGE_60G = 60;
static const uint32_t AXON_CPLT_CONF0_FREE_USAGE_61G = 61;
static const uint32_t AXON_CPLT_CONF0_FREE_USAGE_62G = 62;
static const uint32_t AXON_CPLT_CONF0_FREE_USAGE_63G = 63;
// iohs/reg00060.H

static const uint64_t AXON_CPLT_CTRL0_RW = 0x18000000ull;
static const uint64_t AXON_CPLT_CTRL0_WO_CLEAR = 0x18000020ull;
static const uint64_t AXON_CPLT_CTRL0_WO_OR = 0x18000010ull;

static const uint32_t AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC = 0;
static const uint32_t AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC = 1;
static const uint32_t AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH = 2;
static const uint32_t AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN = 3;
static const uint32_t AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC = 4;
static const uint32_t AXON_CPLT_CTRL0_TC_VITL_PROTECTION = 6;
static const uint32_t AXON_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC = 8;
static const uint32_t AXON_CPLT_CTRL0_RESERVED_11A = 11;
static const uint32_t AXON_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC = 12;
static const uint32_t AXON_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC = 13;
static const uint32_t AXON_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC = 15;
static const uint32_t AXON_CPLT_CTRL0_RESERVED_18A = 18;
static const uint32_t AXON_CPLT_CTRL0_RESERVED_19A = 19;
static const uint32_t AXON_CPLT_CTRL0_TC_PSRO_SEL_DC = 20;
static const uint32_t AXON_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN = 8;
static const uint32_t AXON_CPLT_CTRL0_TC_BSC_WRAPSEL_DC = 28;
static const uint32_t AXON_CPLT_CTRL0_TC_BSC_INTMODE_DC = 29;
static const uint32_t AXON_CPLT_CTRL0_TC_BSC_INV_DC = 30;
static const uint32_t AXON_CPLT_CTRL0_TC_BSC_EXTMODE_DC = 31;
static const uint32_t AXON_CPLT_CTRL0_RESERVED_32A = 32;
static const uint32_t AXON_CPLT_CTRL0_RESERVED_33A = 33;
static const uint32_t AXON_CPLT_CTRL0_RESERVED_34A = 34;
static const uint32_t AXON_CPLT_CTRL0_RESERVED_35A = 35;
static const uint32_t AXON_CPLT_CTRL0_RESERVED_36A = 36;
static const uint32_t AXON_CPLT_CTRL0_RESERVED_37A = 37;
static const uint32_t AXON_CPLT_CTRL0_RESERVED_38A = 38;
static const uint32_t AXON_CPLT_CTRL0_RESERVED_39A = 39;
static const uint32_t AXON_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC = 40;
static const uint32_t AXON_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN = 2;
static const uint32_t AXON_CPLT_CTRL0_RESERVED_42A = 42;
static const uint32_t AXON_CPLT_CTRL0_RESERVED_43A = 43;
static const uint32_t AXON_CPLT_CTRL0_CTRL_CC_DCTEST_DC = 44;
static const uint32_t AXON_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC = 47;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_48A = 48;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_49A = 49;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_50A = 50;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_51A = 51;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_52A = 52;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_53A = 53;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_54A = 54;
static const uint32_t AXON_CPLT_CTRL0_RESERVED_55A = 55;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_56A = 56;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_57A = 57;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_58A = 58;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_59A = 59;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_60A = 60;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_61A = 61;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_62A = 62;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_63A = 63;
// iohs/reg00060.H

static const uint64_t AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG = 0x18010005ull;

static const uint32_t AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING = 0;
static const uint32_t AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING = 1;
// iohs/reg00060.H

static const uint64_t AXON_LOCAL_XSTOP = 0x18040003ull;

static const uint32_t AXON_LOCAL_XSTOP_ANY_LOCAL_XSTOP = 0;
static const uint32_t AXON_LOCAL_XSTOP_RESERVED1L = 1;
static const uint32_t AXON_LOCAL_XSTOP_RESERVED2L = 2;
static const uint32_t AXON_LOCAL_XSTOP_RESERVED3L = 3;
static const uint32_t AXON_LOCAL_XSTOP_LOCAL_XSTOP_PERV = 4;
static const uint32_t AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN05 = 5;
static const uint32_t AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN06 = 6;
static const uint32_t AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN07 = 7;
static const uint32_t AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN08 = 8;
static const uint32_t AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN09 = 9;
static const uint32_t AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN10 = 10;
static const uint32_t AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN11 = 11;
static const uint32_t AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN12 = 12;
static const uint32_t AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN13 = 13;
static const uint32_t AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN14 = 14;
static const uint32_t AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN15 = 15;
// iohs/reg00060.H

static const uint64_t AXON_OPCG_ALIGN = 0x18030001ull;

static const uint32_t AXON_OPCG_ALIGN_INOP_ALIGN = 0;
static const uint32_t AXON_OPCG_ALIGN_INOP_ALIGN_LEN = 4;
static const uint32_t AXON_OPCG_ALIGN_SNOP_ALIGN = 4;
static const uint32_t AXON_OPCG_ALIGN_SNOP_ALIGN_LEN = 4;
static const uint32_t AXON_OPCG_ALIGN_ENOP_ALIGN = 8;
static const uint32_t AXON_OPCG_ALIGN_ENOP_ALIGN_LEN = 4;
static const uint32_t AXON_OPCG_ALIGN_INOP_WAIT = 12;
static const uint32_t AXON_OPCG_ALIGN_INOP_WAIT_LEN = 8;
static const uint32_t AXON_OPCG_ALIGN_SNOP_WAIT = 20;
static const uint32_t AXON_OPCG_ALIGN_SNOP_WAIT_LEN = 12;
static const uint32_t AXON_OPCG_ALIGN_ENOP_WAIT = 32;
static const uint32_t AXON_OPCG_ALIGN_ENOP_WAIT_LEN = 8;
static const uint32_t AXON_OPCG_ALIGN_INOP_FORCE_SG = 40;
static const uint32_t AXON_OPCG_ALIGN_SNOP_FORCE_SG = 41;
static const uint32_t AXON_OPCG_ALIGN_ENOP_FORCE_SG = 42;
static const uint32_t AXON_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD = 43;
static const uint32_t AXON_OPCG_ALIGN_ALIGN_SOURCE_SELECT = 44;
static const uint32_t AXON_OPCG_ALIGN_ALIGN_SOURCE_SELECT_LEN = 2;
static const uint32_t AXON_OPCG_ALIGN_SCAN_RATIO = 47;
static const uint32_t AXON_OPCG_ALIGN_SCAN_RATIO_LEN = 5;
static const uint32_t AXON_OPCG_ALIGN_OPCG_WAIT_CYCLES = 52;
static const uint32_t AXON_OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN = 12;
// iohs/reg00060.H

static const uint64_t AXON_PHASE_COUNTER_RESET = 0x18030028ull;

static const uint32_t AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET = 0;
// iohs/reg00060.H

static const uint64_t AXON_SCAN_UPDATEDR = 0x1803a000ull;

static const uint32_t AXON_SCAN_UPDATEDR_SCAN_UPDATEDR_REG = 0;
static const uint32_t AXON_SCAN_UPDATEDR_SCAN_UPDATEDR_REG_LEN = 32;
// iohs/reg00060.H

static const uint64_t AXON_SPATTN_MASK_RW = 0x18040042ull;
static const uint64_t AXON_SPATTN_MASK_WO_CLEAR = 0x18040062ull;
static const uint64_t AXON_SPATTN_MASK_WO_OR = 0x18040052ull;

static const uint32_t AXON_SPATTN_MASK_01 = 1;
static const uint32_t AXON_SPATTN_MASK_02 = 2;
static const uint32_t AXON_SPATTN_MASK_03 = 3;
static const uint32_t AXON_SPATTN_MASK_04 = 4;
static const uint32_t AXON_SPATTN_MASK_05 = 5;
static const uint32_t AXON_SPATTN_MASK_06 = 6;
static const uint32_t AXON_SPATTN_MASK_07 = 7;
static const uint32_t AXON_SPATTN_MASK_08 = 8;
static const uint32_t AXON_SPATTN_MASK_09 = 9;
static const uint32_t AXON_SPATTN_MASK_10 = 10;
static const uint32_t AXON_SPATTN_MASK_11 = 11;
static const uint32_t AXON_SPATTN_MASK_12 = 12;
static const uint32_t AXON_SPATTN_MASK_13 = 13;
static const uint32_t AXON_SPATTN_MASK_14 = 14;
static const uint32_t AXON_SPATTN_MASK_15 = 15;
static const uint32_t AXON_SPATTN_MASK_16 = 16;
static const uint32_t AXON_SPATTN_MASK_17 = 17;
static const uint32_t AXON_SPATTN_MASK_18 = 18;
static const uint32_t AXON_SPATTN_MASK_19 = 19;
static const uint32_t AXON_SPATTN_MASK_20 = 20;
static const uint32_t AXON_SPATTN_MASK_21 = 21;
static const uint32_t AXON_SPATTN_MASK_22 = 22;
static const uint32_t AXON_SPATTN_MASK_23 = 23;
static const uint32_t AXON_SPATTN_MASK_24 = 24;
static const uint32_t AXON_SPATTN_MASK_25 = 25;
static const uint32_t AXON_SPATTN_MASK_26 = 26;
static const uint32_t AXON_SPATTN_MASK_27 = 27;
static const uint32_t AXON_SPATTN_MASK_28 = 28;
static const uint32_t AXON_SPATTN_MASK_29 = 29;
static const uint32_t AXON_SPATTN_MASK_30 = 30;
static const uint32_t AXON_SPATTN_MASK_31 = 31;
static const uint32_t AXON_SPATTN_MASK_32 = 32;
static const uint32_t AXON_SPATTN_MASK_33 = 33;
static const uint32_t AXON_SPATTN_MASK_34 = 34;
static const uint32_t AXON_SPATTN_MASK_35 = 35;
// iohs/reg00060.H

static const uint64_t AXON_TRA0_TR0_CONFIG_9 = 0x18010409ull;

static const uint32_t AXON_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t AXON_TRA0_TR0_CONFIG_9_SPARE_LT = 37;
// iohs/reg00060.H

static const uint64_t AXON_XSTOP_MASK_RW = 0x18040040ull;
static const uint64_t AXON_XSTOP_MASK_WO_CLEAR = 0x18040060ull;
static const uint64_t AXON_XSTOP_MASK_WO_OR = 0x18040050ull;

static const uint32_t AXON_XSTOP_MASK_01 = 1;
static const uint32_t AXON_XSTOP_MASK_02 = 2;
static const uint32_t AXON_XSTOP_MASK_03 = 3;
static const uint32_t AXON_XSTOP_MASK_04 = 4;
static const uint32_t AXON_XSTOP_MASK_05 = 5;
static const uint32_t AXON_XSTOP_MASK_06 = 6;
static const uint32_t AXON_XSTOP_MASK_07 = 7;
static const uint32_t AXON_XSTOP_MASK_08 = 8;
static const uint32_t AXON_XSTOP_MASK_09 = 9;
static const uint32_t AXON_XSTOP_MASK_10 = 10;
static const uint32_t AXON_XSTOP_MASK_11 = 11;
static const uint32_t AXON_XSTOP_MASK_12 = 12;
static const uint32_t AXON_XSTOP_MASK_13 = 13;
static const uint32_t AXON_XSTOP_MASK_14 = 14;
static const uint32_t AXON_XSTOP_MASK_15 = 15;
static const uint32_t AXON_XSTOP_MASK_16 = 16;
static const uint32_t AXON_XSTOP_MASK_17 = 17;
static const uint32_t AXON_XSTOP_MASK_18 = 18;
static const uint32_t AXON_XSTOP_MASK_19 = 19;
static const uint32_t AXON_XSTOP_MASK_20 = 20;
static const uint32_t AXON_XSTOP_MASK_21 = 21;
static const uint32_t AXON_XSTOP_MASK_22 = 22;
static const uint32_t AXON_XSTOP_MASK_23 = 23;
static const uint32_t AXON_XSTOP_MASK_24 = 24;
static const uint32_t AXON_XSTOP_MASK_25 = 25;
static const uint32_t AXON_XSTOP_MASK_26 = 26;
static const uint32_t AXON_XSTOP_MASK_27 = 27;
static const uint32_t AXON_XSTOP_MASK_28 = 28;
static const uint32_t AXON_XSTOP_MASK_29 = 29;
static const uint32_t AXON_XSTOP_MASK_30 = 30;
static const uint32_t AXON_XSTOP_MASK_31 = 31;
static const uint32_t AXON_XSTOP_MASK_32 = 32;
static const uint32_t AXON_XSTOP_MASK_33 = 33;
static const uint32_t AXON_XSTOP_MASK_34 = 34;
static const uint32_t AXON_XSTOP_MASK_35 = 35;
static const uint32_t AXON_XSTOP_MASK_36 = 36;
static const uint32_t AXON_XSTOP_MASK_37 = 37;
static const uint32_t AXON_XSTOP_MASK_38 = 38;
static const uint32_t AXON_XSTOP_MASK_39 = 39;
static const uint32_t AXON_XSTOP_MASK_40 = 40;
static const uint32_t AXON_XSTOP_MASK_41 = 41;
static const uint32_t AXON_XSTOP_MASK_42 = 42;
static const uint32_t AXON_XSTOP_MASK_43 = 43;
static const uint32_t AXON_XSTOP_MASK_44 = 44;
static const uint32_t AXON_XSTOP_MASK_45 = 45;
static const uint32_t AXON_XSTOP_MASK_46 = 46;
static const uint32_t AXON_XSTOP_MASK_47 = 47;
static const uint32_t AXON_XSTOP_MASK_48 = 48;
static const uint32_t AXON_XSTOP_MASK_49 = 49;
static const uint32_t AXON_XSTOP_MASK_50 = 50;
static const uint32_t AXON_XSTOP_MASK_51 = 51;
static const uint32_t AXON_XSTOP_MASK_52 = 52;
static const uint32_t AXON_XSTOP_MASK_53 = 53;
// iohs/reg00060.H

static const uint64_t DLP_CONFIG = 0x1801100aull;

static const uint32_t DLP_CONFIG_LINK_PAIR = 0;
static const uint32_t DLP_CONFIG_DISABLE_SL_ECC = 1;
static const uint32_t DLP_CONFIG_DISABLE_RECAL_START = 2;
static const uint32_t DLP_CONFIG_SYN_CAPTURE_SL_ECC = 3;
static const uint32_t DLP_CONFIG_SL_UE_CRC_ERR = 4;
static const uint32_t DLP_CONFIG_REPORT_SL_CHKBIT_ERR = 5;
static const uint32_t DLP_CONFIG_BW_SAMPLE_SIZE = 6;
static const uint32_t DLP_CONFIG_BW_WINDOW_SIZE = 7;
static const uint32_t DLP_CONFIG_PACKET_DELAY_LIMIT = 11;
static const uint32_t DLP_CONFIG_PACKET_DELAY_LIMIT_LEN = 5;
static const uint32_t DLP_CONFIG_TDM_DELAY = 16;
static const uint32_t DLP_CONFIG_TDM_DELAY_LEN = 4;
static const uint32_t DLP_CONFIG_INBOUND_TOD_SELECT = 20;
static const uint32_t DLP_CONFIG_INBOUND_TOD_SELECT_LEN = 2;
static const uint32_t DLP_CONFIG_INBOUND_TOD_CROSS_SELECT = 22;
static const uint32_t DLP_CONFIG_INBOUND_TOD_CROSS_SELECT_LEN = 2;
static const uint32_t DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT = 24;
static const uint32_t DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT = 25;
static const uint32_t DLP_CONFIG_RECAL_TIMER = 29;
static const uint32_t DLP_CONFIG_RECAL_TIMER_LEN = 15;
static const uint32_t DLP_CONFIG_PSAVE_TIMEOUT = 44;
static const uint32_t DLP_CONFIG_PSAVE_TIMEOUT_LEN = 4;
static const uint32_t DLP_CONFIG_TIMEOUT = 48;
static const uint32_t DLP_CONFIG_TIMEOUT_LEN = 4;
static const uint32_t DLP_CONFIG_TIMER_1US = 52;
static const uint32_t DLP_CONFIG_TIMER_1US_LEN = 12;
// iohs/reg00060.H

static const uint64_t DLP_LAT_MEASURE = 0x1801100eull;

static const uint32_t DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID = 0;
static const uint32_t DLP_LAT_MEASURE_LINK0_ROUND_TRIP = 2;
static const uint32_t DLP_LAT_MEASURE_LINK0_ROUND_TRIP_LEN = 10;
static const uint32_t DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID = 12;
static const uint32_t DLP_LAT_MEASURE_LINK1_ROUND_TRIP = 14;
static const uint32_t DLP_LAT_MEASURE_LINK1_ROUND_TRIP_LEN = 10;
static const uint32_t DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID = 24;
static const uint32_t DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK = 25;
static const uint32_t DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE = 29;
static const uint32_t DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_LEN = 7;
static const uint32_t DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID = 36;
static const uint32_t DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK = 37;
static const uint32_t DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE = 41;
static const uint32_t DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_LEN = 7;
static const uint32_t DLP_LAT_MEASURE_LINK0_TOD_LATENCY = 49;
static const uint32_t DLP_LAT_MEASURE_LINK0_TOD_LATENCY_LEN = 7;
static const uint32_t DLP_LAT_MEASURE_LINK1_TOD_LATENCY = 57;
static const uint32_t DLP_LAT_MEASURE_LINK1_TOD_LATENCY_LEN = 7;
// iohs/reg00060.H

static const uint64_t DLP_LINK0_QUALITY = 0x18011026ull;

static const uint32_t DLP_LINK0_QUALITY_TX_BW = 1;
static const uint32_t DLP_LINK0_QUALITY_TX_BW_LEN = 11;
static const uint32_t DLP_LINK0_QUALITY_RX_BW = 13;
static const uint32_t DLP_LINK0_QUALITY_RX_BW_LEN = 11;
static const uint32_t DLP_LINK0_QUALITY_ERROR_RATE = 25;
static const uint32_t DLP_LINK0_QUALITY_ERROR_RATE_LEN = 23;
static const uint32_t DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3 = 48;
static const uint32_t DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3_LEN = 8;
static const uint32_t DLP_LINK0_QUALITY_SPARE_COUNTER_2 = 57;
static const uint32_t DLP_LINK0_QUALITY_SPARE_COUNTER_2_LEN = 7;
// iohs/reg00060.H

static const uint64_t DLP_PERF_COUNT_LSB_0 = 0x18011020ull;
// iohs/reg00060.H

static const uint64_t DLP_PHY_CONFIG = 0x1801100cull;

static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ = 0;
static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ_LEN = 2;
static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ = 2;
static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ_LEN = 2;
static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_TIME = 4;
static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_TIME_LEN = 4;
static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_A_HYST = 8;
static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_A_HYST_LEN = 4;
static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_B_HYST = 12;
static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_B_HYST_LEN = 4;
static const uint32_t DLP_PHY_CONFIG_PRBS_PHASE_SELECT = 16;
static const uint32_t DLP_PHY_CONFIG_PRBS_PHASE_SELECT_LEN = 24;
static const uint32_t DLP_PHY_CONFIG_PRBS_CONFIG = 40;
static const uint32_t DLP_PHY_CONFIG_PRBS_CONFIG_LEN = 10;
static const uint32_t DLP_PHY_CONFIG_PRBS_INVERT = 50;
static const uint32_t DLP_PHY_CONFIG_LINK0_SELECT = 56;
static const uint32_t DLP_PHY_CONFIG_LINK1_SELECT = 57;
static const uint32_t DLP_PHY_CONFIG_PRBS15_NPRBS7 = 59;
static const uint32_t DLP_PHY_CONFIG_PRECODER_ENABLE = 60;
static const uint32_t DLP_PHY_CONFIG_50G_MODE = 61;
static const uint32_t DLP_PHY_CONFIG_DL_SELECT = 62;
static const uint32_t DLP_PHY_CONFIG_DL_SELECT_LEN = 2;
// iohs/reg00060.H

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG = 0x8009080010012c3full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC = 49;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT = 50;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG = 51;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG_LEN = 5;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0 = 56;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC = 57;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC = 58;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_REVERSE_LATCH_DAC = 59;
// iohs/reg00060.H

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG = 0x8008880010012c3full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2 = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2_LEN = 3;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3 = 51;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3_LEN = 5;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3 = 56;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3_LEN = 3;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4 = 59;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4_LEN = 5;
// iohs/reg00060.H

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE4_PG = 0x8008200010012c3full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC0 = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC0_LEN = 4;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC0 = 52;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC0_LEN = 4;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC1 = 56;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC1_LEN = 4;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC1 = 60;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC1_LEN = 4;
// iohs/reg00060.H

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG = 0x8009380010012c3full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ_LEN = 11;
// iohs/reg00060.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT15_PG = 0x8009f80010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL_LEN = 5;
// iohs/reg00060.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT25_PG = 0x800a480010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15_LEN = 16;
// iohs/reg00060.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG = 0x8009b00010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN = 8;
// iohs/reg00060.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT13_PG = 0x800af00010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL = 59;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL = 60;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL = 63;
// iohs/reg00060.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT23_PG = 0x800b400010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL_LEN = 8;
// iohs/reg00060.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT6_PG = 0x800ab80010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT6_PG_RX_SERVO_STATUS0_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT6_PG_RX_SERVO_STATUS0_RO_SIGNAL_LEN = 16;
// iohs/reg00060.H

static const uint64_t IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL = 0x8003c80f10012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL =
    52;
// iohs/reg00060.H

static const uint64_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL = 0x8003d00d10012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// iohs/reg00060.H

static const uint64_t IOO_RX0_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL = 0x8003d80b10012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// iohs/reg00060.H

static const uint64_t IOO_RX0_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL = 0x8003d81710012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// iohs/reg00060.H

static const uint64_t IOO_RX0_RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL = 0x8003c00510012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// iohs/reg00060.H

static const uint64_t IOO_RX0_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL = 0x8003e00510012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL = 52;
static const uint32_t IOO_RX0_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL = 53;
// iohs/reg00060.H

static const uint64_t IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL = 0x8003c80810012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL = 52;
// iohs/reg00060.H

static const uint64_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL6_PL = 0x8003880010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL = 48;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN = 2;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A = 50;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B = 51;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A = 52;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B = 53;
// iohs/reg00060.H

static const uint64_t IOO_RX0_0_RD_RX_BIT_REGS_STAT6_PL = 0x8003b80010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL_LEN = 16;
// iohs/reg00060.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX62_PL = 0x8001f00010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN = 8;
// iohs/reg00060.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX72_PL = 0x8002400010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN = 8;
// iohs/reg00060.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX89_PL = 0x8002c80010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN = 8;
// iohs/reg00060.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL10_PL = 0x8000500010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS = 49;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M = 50;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL10_PL_SIGDET_PD = 51;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP = 52;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP = 53;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS = 54;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP_LEN = 2;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP = 58;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP_LEN = 2;
// iohs/reg00060.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x8000000010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// iohs/reg00060.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX35_PL = 0x8001180110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN = 8;
// iohs/reg00060.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX45_PL = 0x8001680110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN = 8;
// iohs/reg00060.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX55_PL = 0x8001b80110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN = 8;
// iohs/reg00060.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX59_PL = 0x8001d80110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN = 8;
// iohs/reg00060.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX69_PL = 0x8002280110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN = 8;
// iohs/reg00060.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX79_PL = 0x8002780110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN = 8;
// iohs/reg00060.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX82_PL = 0x8002900110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN = 8;
// iohs/reg00060.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL16_PL = 0x8000800110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// iohs/reg00060.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX67_PL = 0x8002180210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 = 56;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN = 8;
// iohs/reg00060.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX77_PL = 0x8002680210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 = 56;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN = 8;
// iohs/reg00060.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL17_PL = 0x8000880210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL4_PL = 0x8000200210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL4_PL_ZERO = 51;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL4_PL_ZERO_LEN = 3;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE7_PL = 0x8003500310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN = 2;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO = 50;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN = 10;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL = 61;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_3_RX_BIT_REGS_STAT1_PL = 0x8003900310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL = 49;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL = 50;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL = 51;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL = 52;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL = 53;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL = 54;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL = 57;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL = 58;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL = 59;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO = 60;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX20_PL = 0x8000a00310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX30_PL = 0x8000f00310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX40_PL = 0x8001400310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX50_PL = 0x8001900310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX87_PL = 0x8002b80310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL11_PL = 0x8000580310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL11_PL_TERM_PD = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL11_PL_FREQ_ADJUST = 49;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL11_PL_FREQ_ADJUST_LEN = 5;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL11_PL_OFF_CM = 54;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL11_PL_OFF_CM_LEN = 4;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL11_PL_OFF_DM = 58;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL11_PL_OFF_DM_LEN = 6;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL1_PL = 0x8000080310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 54;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL3_PL = 0x8003700410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET = 49;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A = 50;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B = 51;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A = 52;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B = 53;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE = 54;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK = 57;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN = 4;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR = 61;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN = 3;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE5_PL = 0x8003400410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN = 4;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN = 7;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_STAT3_PL = 0x8003a00410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL_LEN = 15;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b80410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f80410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x8002480410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c00410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL2_PL = 0x8000100410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL2_PL_NS_DATA = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL2_PL_NS_DATA_LEN = 4;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL2_PL_EW_DATA = 52;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL2_PL_EW_DATA_LEN = 4;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL2_PL_NS_EDGE = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL2_PL_NS_EDGE_LEN = 4;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL2_PL_EW_EDGE = 60;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL2_PL_EW_EDGE_LEN = 4;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE9_PL = 0x8003e80510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX_LEN = 4;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE = 52;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE_LEN = 4;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE9_PL_MARGIN = 57;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x8001100510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x8001600510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b00510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x8002200510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x8002700510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x8002980510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL18_PL = 0x8000900510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// iohs/reg00061.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL7_PL = 0x8000380510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL7_PL_EN_DC = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL7_PL_PR_POS = 49;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL7_PL_PR_POS_LEN = 5;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS = 54;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL_LEN = 3;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC = 58;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC_LEN = 3;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC = 61;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC_LEN = 2;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTLX1_PL = 0x8003600610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 59;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A = 60;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A = 61;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN = 62;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b00610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x8001000610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x8001500610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a00610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a80610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL16_PL = 0x8000800610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_RX_BIT_REGS_MODE7_PL = 0x8003500710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL = 48;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN = 2;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO = 50;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN = 10;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL = 61;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_RX_BIT_REGS_STAT1_PL = 0x8003900710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL = 49;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL = 50;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL = 51;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL = 52;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL = 53;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL = 54;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL = 55;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL = 56;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL = 57;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL = 58;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL = 59;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO = 60;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x8000980710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e80710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x8001380710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x8001880710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c80710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x8002080710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x8002580710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL10_PL = 0x8000500710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB = 48;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS = 49;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M = 50;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL10_PL_SIGDET_PD = 51;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP = 52;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP = 53;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS = 54;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP_LEN = 2;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP = 58;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP_LEN = 2;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL6_PL = 0x8003880810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN = 2;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A = 50;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B = 51;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A = 52;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B = 53;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_2_RX_BIT_REGS_STAT6_PL = 0x8003b80810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL_LEN = 16;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX27_PL = 0x8000d80810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX37_PL = 0x8001280810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX47_PL = 0x8001780810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN = 8;
// iohs/reg00061.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX57_PL = 0x8001c80810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX80_PL = 0x8002800810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX90_PL = 0x8002d00810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL11_PL = 0x8000580810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL11_PL_TERM_PD = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL11_PL_FREQ_ADJUST = 49;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL11_PL_FREQ_ADJUST_LEN = 5;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL11_PL_OFF_CM = 54;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL11_PL_OFF_CM_LEN = 4;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL11_PL_OFF_DM = 58;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL11_PL_OFF_DM_LEN = 6;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL4_PL = 0x8000200810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL4_PL_ZERO = 51;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL4_PL_ZERO_LEN = 3;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX60_PL = 0x8001e01110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX70_PL = 0x8002301110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL17_PL = 0x8000881110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL1_PL = 0x8000081110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 54;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX5_PL = 0x8003801010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL = 49;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL = 50;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL = 51;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL = 52;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL = 53;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 54;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 57;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL = 58;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL = 59;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL = 60;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL = 61;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL = 62;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x8001081010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x8001581010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a81010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a01010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL18_PL = 0x8000901010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL2_PL = 0x8000101010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL2_PL_NS_DATA = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL2_PL_NS_DATA_LEN = 4;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL2_PL_EW_DATA = 52;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL2_PL_EW_DATA_LEN = 4;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL2_PL_NS_EDGE = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL2_PL_NS_EDGE_LEN = 4;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL2_PL_EW_EDGE = 60;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL2_PL_EW_EDGE_LEN = 4;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL4_PL = 0x8003780f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL4_PL_RX_PR_PHASE_FORCE_A_WO_PULSE_SLOW_SIGNAL = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL4_PL_RX_PR_PHASE_FORCE_VAL_A = 49;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL4_PL_RX_PR_PHASE_FORCE_VAL_A_LEN = 7;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL4_PL_RX_PR_PHASE_FORCE_B_WO_PULSE_SLOW_SIGNAL = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL4_PL_RX_PR_PHASE_FORCE_VAL_B = 57;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL4_PL_RX_PR_PHASE_FORCE_VAL_B_LEN = 7;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE2_PL = 0x8003280f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR = 49;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN = 50;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN = 51;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN = 52;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE2_PL_LOCK_RATIO = 53;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE2_PL_LOCK_RATIO_LEN = 10;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_STAT4_PL = 0x8003a80f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL_LEN = 12;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL = 60;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL = 61;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL = 62;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e00f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x8001300f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x8001800f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d00f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c00f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x8002000f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x8002500f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL7_PL = 0x8000380f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL7_PL_EN_DC = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL7_PL_PR_POS = 49;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL7_PL_PR_POS_LEN = 5;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS = 54;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL_LEN = 3;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC = 58;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC_LEN = 3;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC = 61;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC_LEN = 2;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL3_PL = 0x8003700e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL3_PL_IORESET = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET = 49;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A = 50;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B = 51;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A = 52;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B = 53;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE = 54;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK = 57;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN = 4;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR = 61;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN = 3;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE5_PL = 0x8003400e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN = 4;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN = 7;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_STAT3_PL = 0x8003a00e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL_LEN = 15;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX35_PL = 0x8001180e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX45_PL = 0x8001680e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX55_PL = 0x8001b80e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX59_PL = 0x8001d80e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX69_PL = 0x8002280e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX79_PL = 0x8002780e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX82_PL = 0x8002900e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL5_PL = 0x8000280e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL5_PL_NS_DATA = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL5_PL_NS_DATA_LEN = 4;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL5_PL_EW_DATA = 52;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL5_PL_EW_DATA_LEN = 4;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL5_PL_NS_EDGE = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL5_PL_NS_EDGE_LEN = 4;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL5_PL_EW_EDGE = 60;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL5_PL_EW_EDGE_LEN = 4;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE9_PL = 0x8003e80d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX_LEN = 4;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE = 52;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE_LEN = 4;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE9_PL_MARGIN = 57;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_SPARE_MODE_PL = 0x8003000d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_SPARE_MODE_PL_7 = 55;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL = 0x8001f00d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL = 0x8002400d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL = 0x8002c80d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX20_PL = 0x8000a00c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX30_PL = 0x8000f00c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX40_PL = 0x8001400c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX50_PL = 0x8001900c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX87_PL = 0x8002b80c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN = 8;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL4_PL = 0x8003780b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL4_PL_RX_PR_PHASE_FORCE_A_WO_PULSE_SLOW_SIGNAL = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL4_PL_RX_PR_PHASE_FORCE_VAL_A = 49;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL4_PL_RX_PR_PHASE_FORCE_VAL_A_LEN = 7;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL4_PL_RX_PR_PHASE_FORCE_B_WO_PULSE_SLOW_SIGNAL = 56;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL4_PL_RX_PR_PHASE_FORCE_VAL_B = 57;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL4_PL_RX_PR_PHASE_FORCE_VAL_B_LEN = 7;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE2_PL = 0x8003280b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR = 49;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN = 50;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN = 51;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN = 52;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_RATIO = 53;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_RATIO_LEN = 10;
// iohs/reg00062.H

static const uint64_t IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL = 0x8003a80b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL_LEN = 12;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL = 60;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL = 61;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL = 62;
// iohs/reg00063.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL = 0x8002180b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 = 56;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN = 8;
// iohs/reg00063.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL = 0x8002680b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 = 56;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN = 8;
// iohs/reg00063.H

static const uint64_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL = 0x8003880a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN = 2;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A = 50;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B = 51;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A = 52;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B = 53;
// iohs/reg00063.H

static const uint64_t IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL = 0x8003b80a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL_LEN = 16;
// iohs/reg00063.H

static const uint64_t IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL = 0x8003100a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN = 3;
// iohs/reg00063.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x8001100a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 8;
// iohs/reg00063.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x8001600a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 8;
// iohs/reg00063.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b00a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 8;
// iohs/reg00063.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x8002200a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 8;
// iohs/reg00063.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x8002700a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 8;
// iohs/reg00063.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x8002980a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 8;
// iohs/reg00063.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b80910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 8;
// iohs/reg00063.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f80910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 8;
// iohs/reg00063.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x8002480910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 8;
// iohs/reg00063.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c00910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 8;
// iohs/reg00063.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL = 0x8000700910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE = 54;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE_LEN = 5;
// iohs/reg00063.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL = 0x8004a40010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// iohs/reg00063.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL = 0x8004f40010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00063.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL = 0x8005240010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL = 48;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL = 49;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL = 50;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL_LEN = 2;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL = 63;
// iohs/reg00063.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL = 0x8004c40210012c3full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// iohs/reg00063.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL = 0x8005140210012c3full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// iohs/reg00063.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL = 0x80046c0210012c3full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00063.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL = 0x8004040210012c3full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL_LEN = 2;
// iohs/reg00063.H

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL = 0x8004e40310012c3full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00063.H

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL = 0x8004540310012c3full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL_LEN = 5;
// iohs/reg00063.H

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL = 0x80042c0310012c3full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL = 48;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN = 2;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL = 50;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN = 2;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN = 52;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN = 53;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL = 54;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL = 55;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL_LEN = 3;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL = 58;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL_LEN = 3;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL = 61;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL_LEN = 2;
// iohs/reg00063.H

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL = 0x80049c0510012c3full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// iohs/reg00063.H

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL = 0x8004ec0510012c3full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN_LEN = 9;
// iohs/reg00063.H

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL = 0x80045c0510012c3full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// iohs/reg00063.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL = 0x80049c0610012c3full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// iohs/reg00063.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL = 0x8004ec0610012c3full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN_LEN = 9;
// iohs/reg00063.H

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL = 0x80043c0710012c3full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// iohs/reg00063.H

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL = 0x80052c0710012c3full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL_LEN = 8;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL = 56;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL_LEN = 8;
// iohs/reg00063.H

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL = 0x8004bc0810012c3full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// iohs/reg00063.H

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL = 0x80045c0810012c3full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// iohs/reg00063.H

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8004140810012c3full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// iohs/reg00063.H

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL = 0x8004dc1110012c3full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// iohs/reg00063.H

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL = 0x8004541010012c3full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL_LEN = 5;
// iohs/reg00063.H

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL = 0x80042c1010012c3full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL = 48;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN = 2;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL = 50;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN = 2;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN = 52;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN = 53;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL = 54;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL = 55;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL_LEN = 3;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL = 58;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL_LEN = 3;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL = 61;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL_LEN = 2;
// iohs/reg00063.H

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL = 0x8004a40f10012c3full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// iohs/reg00063.H

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL = 0x8004f40f10012c3full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00063.H

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL = 0x80046c0f10012c3full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00063.H

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL = 0x80040c0f10012c3full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// iohs/reg00063.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL = 0x8004ac0d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE = 48;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN = 6;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE = 54;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN = 6;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL = 60;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL = 61;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL = 62;
// iohs/reg00063.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL = 0x8004fc0d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN_LEN = 9;
// iohs/reg00063.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL = 0x8004440d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE = 54;
// iohs/reg00063.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL = 0x80040c0d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// iohs/reg00063.H

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL = 0x80047c0c10012c3full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00063.H

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL = 0x8004cc0c10012c3full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL_LEN = 5;
// iohs/reg00063.H

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL30_PL = 0x80051c0c10012c3full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE = 48;
// iohs/reg00064.H

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL7_PL = 0x8004640c10012c3full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// iohs/reg00064.H

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_MODE1_PL = 0x80041c0c10012c3full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 48;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 49;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN = 51;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN = 52;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 53;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 54;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 55;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// iohs/reg00064.H

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL17_PL = 0x8004b40a10012c3full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN = 61;
// iohs/reg00064.H

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL4_PL = 0x80044c0a10012c3full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// iohs/reg00064.H

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_MODE2_PL = 0x8004240a10012c3full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// iohs/reg00064.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL9_PL = 0x8004740910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_24_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_24_HS_EN_LEN = 9;
// iohs/reg00064.H

static const uint64_t REGS_PRX0_DLR_APOR = 0x1801103aull;

static const uint32_t REGS_PRX0_DLR_APOR_ACTIVITY_ACCUM = 0;
static const uint32_t REGS_PRX0_DLR_APOR_ACTIVITY_ACCUM_LEN = 32;
static const uint32_t REGS_PRX0_DLR_APOR_BASE_ACCUM = 32;
static const uint32_t REGS_PRX0_DLR_APOR_BASE_ACCUM_LEN = 32;
// iohs/reg00064.H

static const uint64_t SLAVE_CONFIG_REG = 0x180f001eull;

static const uint32_t SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK = 0;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN = 1;
static const uint32_t SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP = 2;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK = 3;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_HEARTBEAT = 4;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO = 5;
static const uint32_t SLAVE_CONFIG_REG_PM_DISABLE = 6;
static const uint32_t SLAVE_CONFIG_REG_PM_MUX_DISABLE = 7;
static const uint32_t SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS = 8;
static const uint32_t SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS = 9;
static const uint32_t SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS = 10;
static const uint32_t SLAVE_CONFIG_REG_MASK_PCBSL_ERRS = 11;
static const uint32_t SLAVE_CONFIG_REG_MASK_PLL_ERRS = 12;
static const uint32_t SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN = 8;
static const uint32_t SLAVE_CONFIG_REG_QME_PAR_DIS = 20;
static const uint32_t SLAVE_CONFIG_REG_FORCE_0_QME = 21;
// iohs/reg00064.H

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00060.H"
#include "iohs/reg00061.H"
#include "iohs/reg00062.H"
#include "iohs/reg00063.H"
#include "iohs/reg00064.H"
#endif
#endif
