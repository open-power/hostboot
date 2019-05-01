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

#include "proc_scomt.H"

#ifndef __p10_scom_iohs_e_H_
#define __p10_scom_iohs_e_H_


namespace scomt
{
namespace iohs
{


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
// iohs/reg00014.H

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
static const uint32_t AXON_CPLT_CONF0_FREE_USAGE_47G = 47;
static const uint32_t AXON_CPLT_CONF0_FREE_USAGE_48G = 48;
static const uint32_t AXON_CPLT_CONF0_FREE_USAGE_49G = 49;
static const uint32_t AXON_CPLT_CONF0_FREE_USAGE_50G = 50;
static const uint32_t AXON_CPLT_CONF0_FREE_USAGE_51G = 51;
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
// iohs/reg00014.H

static const uint64_t AXON_CPLT_CTRL0_RW = 0x18000000ull;
static const uint64_t AXON_CPLT_CTRL0_WO_CLEAR = 0x18000020ull;
static const uint64_t AXON_CPLT_CTRL0_WO_OR = 0x18000010ull;

static const uint32_t AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC = 0;
static const uint32_t AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC = 1;
static const uint32_t AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH = 2;
static const uint32_t AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN = 3;
static const uint32_t AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC = 4;
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
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_55A = 55;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_56A = 56;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_57A = 57;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_58A = 58;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_59A = 59;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_60A = 60;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_61A = 61;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_62A = 62;
static const uint32_t AXON_CPLT_CTRL0_FREE_USAGE_63A = 63;
// iohs/reg00014.H

static const uint64_t AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG = 0x18010005ull;

static const uint32_t AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING = 0;
static const uint32_t AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING = 1;
// iohs/reg00014.H

static const uint64_t AXON_LOCAL_XSTOP = 0x18040018ull;

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
// iohs/reg00014.H

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
// iohs/reg00014.H

static const uint64_t AXON_PHASE_COUNTER_RESET = 0x18030028ull;

static const uint32_t AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET = 0;
// iohs/reg00014.H

static const uint64_t AXON_SCAN_UPDATEDR = 0x1803a000ull;
// iohs/reg00014.H

static const uint64_t AXON_SPATTN_MASK = 0x18040007ull;

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
// iohs/reg00014.H

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
// iohs/reg00014.H

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
// iohs/reg00014.H

}
}
#include "iohs/reg00014.H"
#endif
