/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pauc_9.H $       */
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

#ifndef __p10_scom_pauc_9_H_
#define __p10_scom_pauc_9_H_


namespace scomt
{
namespace pauc
{


static const uint64_t CPLT_CTRL4_RW = 0x10000004ull;
static const uint64_t CPLT_CTRL4_WO_CLEAR = 0x10000024ull;
static const uint64_t CPLT_CTRL4_WO_OR = 0x10000014ull;

static const uint32_t CPLT_CTRL4_0_FLUSHMODE_INH = 4;
static const uint32_t CPLT_CTRL4_1_FLUSHMODE_INH = 5;
static const uint32_t CPLT_CTRL4_2_FLUSHMODE_INH = 6;
static const uint32_t CPLT_CTRL4_3_FLUSHMODE_INH = 7;
static const uint32_t CPLT_CTRL4_4_FLUSHMODE_INH = 8;
static const uint32_t CPLT_CTRL4_5_FLUSHMODE_INH = 9;
static const uint32_t CPLT_CTRL4_6_FLUSHMODE_INH = 10;
static const uint32_t CPLT_CTRL4_7_FLUSHMODE_INH = 11;
static const uint32_t CPLT_CTRL4_8_FLUSHMODE_INH = 12;
static const uint32_t CPLT_CTRL4_9_FLUSHMODE_INH = 13;
static const uint32_t CPLT_CTRL4_10_FLUSHMODE_INH = 14;
static const uint32_t CPLT_CTRL4_11_FLUSHMODE_INH = 15;
static const uint32_t CPLT_CTRL4_12_FLUSHMODE_INH = 16;
static const uint32_t CPLT_CTRL4_13_FLUSHMODE_INH = 17;
static const uint32_t CPLT_CTRL4_14_FLUSHMODE_INH = 18;
// pauc/reg00009.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT1 = 0x10050001ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN = 16;
// pauc/reg00009.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA2 = 0x1005001bull;
// pauc/reg00009.H

static const uint64_t EPS_THERM_WSUB_SKITTER_FORCE_REG = 0x10050014ull;

static const uint32_t EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ = 0;
// pauc/reg00009.H

static const uint64_t MULTICAST_GROUP_2 = 0x100f0002ull;

static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP = 3;
static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN = 3;
// pauc/reg00009.H

static const uint64_t PB_CFG_TLPM_MUX1_REG = 0x1001182cull;

static const uint32_t PB_CFG_TLPM_MUX1_REG_LINK_EVENT_0 = 0;
static const uint32_t PB_CFG_TLPM_MUX1_REG_LINK_EVENT_0_LEN = 7;
static const uint32_t PB_CFG_TLPM_MUX1_REG_LINK_EVENT_1 = 7;
static const uint32_t PB_CFG_TLPM_MUX1_REG_LINK_EVENT_1_LEN = 7;
static const uint32_t PB_CFG_TLPM_MUX1_REG_LINK_EVENT_2 = 14;
static const uint32_t PB_CFG_TLPM_MUX1_REG_LINK_EVENT_2_LEN = 7;
static const uint32_t PB_CFG_TLPM_MUX1_REG_LINK_EVENT_3 = 21;
static const uint32_t PB_CFG_TLPM_MUX1_REG_LINK_EVENT_3_LEN = 7;
static const uint32_t PB_CFG_TLPM_MUX1_REG_LINK_EVENT_4 = 28;
static const uint32_t PB_CFG_TLPM_MUX1_REG_LINK_EVENT_4_LEN = 7;
static const uint32_t PB_CFG_TLPM_MUX1_REG_LINK_EVENT_5 = 35;
static const uint32_t PB_CFG_TLPM_MUX1_REG_LINK_EVENT_5_LEN = 7;
static const uint32_t PB_CFG_TLPM_MUX1_REG_LINK_EVENT_6 = 42;
static const uint32_t PB_CFG_TLPM_MUX1_REG_LINK_EVENT_6_LEN = 7;
static const uint32_t PB_CFG_TLPM_MUX1_REG_LINK_EVENT_7 = 49;
static const uint32_t PB_CFG_TLPM_MUX1_REG_LINK_EVENT_7_LEN = 7;
static const uint32_t PB_CFG_TLPM_MUX1_REG_LINK_EVENT_8 = 56;
static const uint32_t PB_CFG_TLPM_MUX1_REG_LINK_EVENT_8_LEN = 7;
static const uint32_t PB_CFG_TLPM_MUX1_REG_ALT_EVENTS = 63;
// pauc/reg00009.H

static const uint64_t PB_CFG_TLPM_MUX2_REG = 0x1001182dull;

static const uint32_t PB_CFG_TLPM_MUX2_REG_9 = 0;
static const uint32_t PB_CFG_TLPM_MUX2_REG_9_LEN = 7;
static const uint32_t PB_CFG_TLPM_MUX2_REG_10 = 7;
static const uint32_t PB_CFG_TLPM_MUX2_REG_10_LEN = 7;
static const uint32_t PB_CFG_TLPM_MUX2_REG_11 = 14;
static const uint32_t PB_CFG_TLPM_MUX2_REG_11_LEN = 7;
static const uint32_t PB_CFG_TLPM_MUX2_REG_12 = 21;
static const uint32_t PB_CFG_TLPM_MUX2_REG_12_LEN = 7;
static const uint32_t PB_CFG_TLPM_MUX2_REG_13 = 28;
static const uint32_t PB_CFG_TLPM_MUX2_REG_13_LEN = 7;
static const uint32_t PB_CFG_TLPM_MUX2_REG_14 = 35;
static const uint32_t PB_CFG_TLPM_MUX2_REG_14_LEN = 7;
static const uint32_t PB_CFG_TLPM_MUX2_REG_15 = 42;
static const uint32_t PB_CFG_TLPM_MUX2_REG_15_LEN = 7;
// pauc/reg00009.H

static const uint64_t PB_EN_DOB_ECC_ERR_REG = 0x10011818ull;
// pauc/reg00009.H

static const uint64_t PB_FP01_CFG = 0x1001180aull;

static const uint32_t PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 = 0;
static const uint32_t PB_FP01_CFG_0_DISABLE_GATHERING = 1;
static const uint32_t PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION = 2;
static const uint32_t PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION = 3;
static const uint32_t PB_FP01_CFG_0_LL_CREDIT_LO_LIMIT = 4;
static const uint32_t PB_FP01_CFG_0_LL_CREDIT_LO_LIMIT_LEN = 8;
static const uint32_t PB_FP01_CFG_0_LL_CREDIT_PS_LIMIT = 12;
static const uint32_t PB_FP01_CFG_0_LL_CREDIT_PS_LIMIT_LEN = 8;
static const uint32_t PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP = 20;
static const uint32_t PB_FP01_CFG_01_CMD_EXP_TIME = 21;
static const uint32_t PB_FP01_CFG_01_CMD_EXP_TIME_LEN = 3;
static const uint32_t PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR = 24;
static const uint32_t PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST = 25;
static const uint32_t PB_FP01_CFG_0_PRS_SPARE = 26;
static const uint32_t PB_FP01_CFG_0_PRS_SPARE_LEN = 6;
static const uint32_t PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 = 32;
static const uint32_t PB_FP01_CFG_1_DISABLE_GATHERING = 33;
static const uint32_t PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION = 34;
static const uint32_t PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION = 35;
static const uint32_t PB_FP01_CFG_1_LL_CREDIT_LO_LIMIT = 36;
static const uint32_t PB_FP01_CFG_1_LL_CREDIT_LO_LIMIT_LEN = 8;
static const uint32_t PB_FP01_CFG_1_LL_CREDIT_PS_LIMIT = 44;
static const uint32_t PB_FP01_CFG_1_LL_CREDIT_PS_LIMIT_LEN = 8;
static const uint32_t PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP = 52;
static const uint32_t PB_FP01_CFG_1_FMR_SPARE = 53;
static const uint32_t PB_FP01_CFG_1_FMR_SPARE_LEN = 3;
static const uint32_t PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR = 56;
static const uint32_t PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST = 57;
static const uint32_t PB_FP01_CFG_1_PRS_SPARE = 58;
static const uint32_t PB_FP01_CFG_1_PRS_SPARE_LEN = 6;
// pauc/reg00009.H

static const uint64_t PB_MISC_CFG = 0x10011825ull;

static const uint32_t PB_MISC_CFG_SCOM_PTLX0_ENABLE = 0;
static const uint32_t PB_MISC_CFG_SCOM_PTLX1_ENABLE = 1;
static const uint32_t PB_MISC_CFG_SCOM_PTLY0_ENABLE = 2;
static const uint32_t PB_MISC_CFG_SCOM_PTLY1_ENABLE = 3;
static const uint32_t PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR = 4;
static const uint32_t PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR = 5;
static const uint32_t PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER = 6;
static const uint32_t PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER = 7;
static const uint32_t PB_MISC_CFG_TRANSPORT_0_ENABLE = 8;
static const uint32_t PB_MISC_CFG_TRANSPORT_1_ENABLE = 9;
static const uint32_t PB_MISC_CFG_TRANSPORT_2_ENABLE = 10;
static const uint32_t PB_MISC_CFG_TRANSPORT_3_ENABLE = 11;
static const uint32_t PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 = 12;
static const uint32_t PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN = 13;
static const uint32_t PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 = 14;
static const uint32_t PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN = 15;
static const uint32_t PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 = 16;
static const uint32_t PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN = 17;
static const uint32_t PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 = 18;
static const uint32_t PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN = 19;
static const uint32_t PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 = 20;
static const uint32_t PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 = 21;
static const uint32_t PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 = 22;
static const uint32_t PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 = 23;
static const uint32_t PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 = 24;
static const uint32_t PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 = 25;
static const uint32_t PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 = 26;
static const uint32_t PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 = 27;
static const uint32_t PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 = 28;
static const uint32_t PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 = 29;
static const uint32_t PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 = 30;
static const uint32_t PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 = 31;
static const uint32_t PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 = 32;
static const uint32_t PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 = 33;
static const uint32_t PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 = 34;
static const uint32_t PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 = 35;
static const uint32_t PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE = 36;
static const uint32_t PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE = 37;
static const uint32_t PB_MISC_CFG_TOD_EVN_IB_MUX_CTL = 38;
static const uint32_t PB_MISC_CFG_TOD_EVN_IB_MUX_CTL_LEN = 2;
static const uint32_t PB_MISC_CFG_TOD_ODD_IB_MUX_CTL = 40;
static const uint32_t PB_MISC_CFG_TOD_ODD_IB_MUX_CTL_LEN = 2;
static const uint32_t PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL = 42;
static const uint32_t PB_MISC_CFG_MISC_SPARE = 43;
static const uint32_t PB_MISC_CFG_MISC_SPARE_LEN = 9;
// pauc/reg00009.H

static const uint64_t PB_PERFTRACE_CFG_REG = 0x1001182bull;

static const uint32_t PB_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE = 0;
static const uint32_t PB_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE = 1;
static const uint32_t PB_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE = 2;
static const uint32_t PB_PERFTRACE_CFG_REG_TSPARE6 = 3;
static const uint32_t PB_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE = 4;
static const uint32_t PB_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE = 5;
static const uint32_t PB_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE = 6;
static const uint32_t PB_PERFTRACE_CFG_REG_TSPARE7 = 7;
static const uint32_t PB_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT = 8;
static const uint32_t PB_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT_LEN = 2;
static const uint32_t PB_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT = 10;
static const uint32_t PB_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT_LEN = 2;
// pauc/reg00009.H

static const uint64_t PB_PSAVE01_MODE_CFG = 0x10011814ull;

static const uint32_t PB_PSAVE01_MODE_CFG_MODE = 0;
static const uint32_t PB_PSAVE01_MODE_CFG_MODE_LEN = 2;
static const uint32_t PB_PSAVE01_MODE_CFG_WIDTH = 2;
static const uint32_t PB_PSAVE01_MODE_CFG_WIDTH_LEN = 3;
static const uint32_t PB_PSAVE01_MODE_CFG_SPARE = 5;
static const uint32_t PB_PSAVE01_MODE_CFG_SPARE_LEN = 3;
static const uint32_t PB_PSAVE01_MODE_CFG_MIN_RAND_UC = 8;
static const uint32_t PB_PSAVE01_MODE_CFG_MIN_RAND_UC_LEN = 8;
// pauc/reg00009.H

//ERRCODE: // Some of the name targets not found in address targets: pauc

static const uint64_t PPE_XIRAMGA = 0x10000012ull;

static const uint32_t PPE_XIRAMGA_GA_IR = 0;
static const uint32_t PPE_XIRAMGA_GA_IR_LEN = 32;
static const uint32_t PPE_XIRAMGA_RA_SPRG0 = 32;
static const uint32_t PPE_XIRAMGA_RA_SPRG0_LEN = 32;
// pauc/reg00009.H

static const uint64_t TRA0_TR0_CONFIG_0 = 0x10010403ull;

static const uint32_t TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// pauc/reg00009.H

static const uint64_t TRA0_TR1_TRACE_HI_DATA_REG = 0x10010440ull;

static const uint32_t TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// pauc/reg00009.H

static const uint64_t TRA0_TR1_CONFIG_9 = 0x10010449ull;

static const uint32_t TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA0_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA0_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA0_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// pauc/reg00009.H

}
}
#include "pauc/reg00009.H"
#endif
