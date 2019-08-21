/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pauc_e.H $       */
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

#ifndef __p10_scom_pauc_e_H_
#define __p10_scom_pauc_e_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pauc
{
#endif


static const uint64_t DL_PPE_WRAP_SCOM_FUNC = 0x10012c67ull;

static const uint32_t DL_PPE_WRAP_SCOM_FUNC_EOL_SLOW_TOGGLE = 0;
static const uint32_t DL_PPE_WRAP_SCOM_FUNC_EOL_FAST_TOGGLE = 1;
static const uint32_t DL_PPE_WRAP_SCOM_FUNC_PPE_INTERRUPT = 2;
static const uint32_t DL_PPE_WRAP_SCOM_FUNC_PPE_FUNC_SPARES = 3;
static const uint32_t DL_PPE_WRAP_SCOM_FUNC_PPE_FUNC_SPARES_LEN = 13;
// pauc/reg00014.H

static const uint64_t EPS_DBG_TRACE_REG_1 = 0x100107ceull;

static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO = 0;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO = 4;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO = 6;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO = 8;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO = 10;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_WAITN = 24;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_WAITN = 25;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_WAITN = 26;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_WAITN = 27;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_WAITN = 28;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_WAITN = 29;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_BANK = 36;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_BANK = 37;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_BANK = 38;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_BANK = 39;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_BANK = 40;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_BANK = 41;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT = 48;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_SELECTOR = 51;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT = 52;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_SELECTOR = 55;
// pauc/reg00014.H

static const uint64_t EPS_FIR_LOCAL_ACTION1 = 0x10040107ull;

static const uint32_t EPS_FIR_LOCAL_ACTION1_00 = 0;
static const uint32_t EPS_FIR_LOCAL_ACTION1_01 = 1;
static const uint32_t EPS_FIR_LOCAL_ACTION1_02 = 2;
static const uint32_t EPS_FIR_LOCAL_ACTION1_03 = 3;
static const uint32_t EPS_FIR_LOCAL_ACTION1_04 = 4;
static const uint32_t EPS_FIR_LOCAL_ACTION1_05 = 5;
static const uint32_t EPS_FIR_LOCAL_ACTION1_06 = 6;
static const uint32_t EPS_FIR_LOCAL_ACTION1_07 = 7;
static const uint32_t EPS_FIR_LOCAL_ACTION1_08 = 8;
static const uint32_t EPS_FIR_LOCAL_ACTION1_09 = 9;
static const uint32_t EPS_FIR_LOCAL_ACTION1_10 = 10;
static const uint32_t EPS_FIR_LOCAL_ACTION1_11 = 11;
static const uint32_t EPS_FIR_LOCAL_ACTION1_12 = 12;
static const uint32_t EPS_FIR_LOCAL_ACTION1_13 = 13;
static const uint32_t EPS_FIR_LOCAL_ACTION1_14 = 14;
static const uint32_t EPS_FIR_LOCAL_ACTION1_15 = 15;
static const uint32_t EPS_FIR_LOCAL_ACTION1_16 = 16;
static const uint32_t EPS_FIR_LOCAL_ACTION1_17 = 17;
static const uint32_t EPS_FIR_LOCAL_ACTION1_18 = 18;
static const uint32_t EPS_FIR_LOCAL_ACTION1_19 = 19;
static const uint32_t EPS_FIR_LOCAL_ACTION1_20 = 20;
static const uint32_t EPS_FIR_LOCAL_ACTION1_21 = 21;
static const uint32_t EPS_FIR_LOCAL_ACTION1_22 = 22;
static const uint32_t EPS_FIR_LOCAL_ACTION1_23 = 23;
static const uint32_t EPS_FIR_LOCAL_ACTION1_24 = 24;
static const uint32_t EPS_FIR_LOCAL_ACTION1_25 = 25;
static const uint32_t EPS_FIR_LOCAL_ACTION1_26 = 26;
static const uint32_t EPS_FIR_LOCAL_ACTION1_27 = 27;
static const uint32_t EPS_FIR_LOCAL_ACTION1_28 = 28;
static const uint32_t EPS_FIR_LOCAL_ACTION1_29 = 29;
static const uint32_t EPS_FIR_LOCAL_ACTION1_30 = 30;
static const uint32_t EPS_FIR_LOCAL_ACTION1_31 = 31;
static const uint32_t EPS_FIR_LOCAL_ACTION1_32 = 32;
static const uint32_t EPS_FIR_LOCAL_ACTION1_33 = 33;
static const uint32_t EPS_FIR_LOCAL_ACTION1_34 = 34;
static const uint32_t EPS_FIR_LOCAL_ACTION1_35 = 35;
static const uint32_t EPS_FIR_LOCAL_ACTION1_36 = 36;
static const uint32_t EPS_FIR_LOCAL_ACTION1_37 = 37;
static const uint32_t EPS_FIR_LOCAL_ACTION1_38 = 38;
static const uint32_t EPS_FIR_LOCAL_ACTION1_39 = 39;
static const uint32_t EPS_FIR_LOCAL_ACTION1_40 = 40;
static const uint32_t EPS_FIR_LOCAL_ACTION1_41 = 41;
static const uint32_t EPS_FIR_LOCAL_ACTION1_42 = 42;
static const uint32_t EPS_FIR_LOCAL_ACTION1_43 = 43;
static const uint32_t EPS_FIR_LOCAL_ACTION1_44 = 44;
static const uint32_t EPS_FIR_LOCAL_ACTION1_45 = 45;
static const uint32_t EPS_FIR_LOCAL_ACTION1_46 = 46;
static const uint32_t EPS_FIR_LOCAL_ACTION1_47 = 47;
static const uint32_t EPS_FIR_LOCAL_ACTION1_48 = 48;
static const uint32_t EPS_FIR_LOCAL_ACTION1_49 = 49;
static const uint32_t EPS_FIR_LOCAL_ACTION1_50 = 50;
static const uint32_t EPS_FIR_LOCAL_ACTION1_51 = 51;
static const uint32_t EPS_FIR_LOCAL_ACTION1_52 = 52;
static const uint32_t EPS_FIR_LOCAL_ACTION1_53 = 53;
static const uint32_t EPS_FIR_LOCAL_ACTION1_54 = 54;
static const uint32_t EPS_FIR_LOCAL_ACTION1_55 = 55;
static const uint32_t EPS_FIR_LOCAL_ACTION1_56 = 56;
static const uint32_t EPS_FIR_LOCAL_ACTION1_57 = 57;
static const uint32_t EPS_FIR_LOCAL_ACTION1_58 = 58;
static const uint32_t EPS_FIR_LOCAL_ACTION1_59 = 59;
static const uint32_t EPS_FIR_LOCAL_ACTION1_60 = 60;
static const uint32_t EPS_FIR_LOCAL_ACTION1_61 = 61;
static const uint32_t EPS_FIR_LOCAL_ACTION1_62 = 62;
static const uint32_t EPS_FIR_LOCAL_ACTION1_63 = 63;
// pauc/reg00014.H

static const uint64_t OPCG_REG1 = 0x10030003ull;

static const uint32_t OPCG_REG1_SCAN_COUNT = 0;
static const uint32_t OPCG_REG1_SCAN_COUNT_LEN = 12;
static const uint32_t OPCG_REG1_MISR_A_VAL = 12;
static const uint32_t OPCG_REG1_MISR_A_VAL_LEN = 12;
static const uint32_t OPCG_REG1_MISR_B_VAL = 24;
static const uint32_t OPCG_REG1_MISR_B_VAL_LEN = 12;
static const uint32_t OPCG_REG1_MISR_INIT_WAIT = 36;
static const uint32_t OPCG_REG1_MISR_INIT_WAIT_LEN = 12;
static const uint32_t OPCG_REG1_SCAN_CLK_USE_EVEN = 49;
static const uint32_t OPCG_REG1_RTIM_THOLD_FORCE = 52;
static const uint32_t OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL = 53;
static const uint32_t OPCG_REG1_SG_HIGH_DURING_FILL = 54;
static const uint32_t OPCG_REG1_LBIST_SKITTER_CTL = 55;
static const uint32_t OPCG_REG1_LBIST_SKITTER_CTL_LEN = 2;
static const uint32_t OPCG_REG1_MISR_MODE = 57;
static const uint32_t OPCG_REG1_INFINITE_MODE = 58;
static const uint32_t OPCG_REG1_NSL_FILL_COUNT = 59;
static const uint32_t OPCG_REG1_NSL_FILL_COUNT_LEN = 5;
// pauc/reg00014.H

static const uint64_t PB_DOB23_DIB23_INT_ERR_REG = 0x1001182aull;

static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_RTAG_PBITERR = 0;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_RTAG_PERR = 1;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_MISC_PERR = 2;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F0VC0_EVENPERR = 3;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F0VC0_ODDPERR = 4;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F0VC1_EVENPERR = 5;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F0VC1_ODDPERR = 6;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F1VC0_EVENPERR = 7;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F1VC0_ODDPERR = 8;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F1VC1_EVENPERR = 9;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F1VC1_ODDPERR = 10;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F0_UNDERFLOW = 11;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F0_OVERFLOW = 12;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F1_UNDERFLOW = 13;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F1_OVERFLOW = 14;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_VC0_UNDERFLOW = 15;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_VC0_OVERFLOW = 16;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_VC1_UNDERFLOW = 17;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_VC1_OVERFLOW = 18;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F0VC0_UNDERFLOW = 19;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F0VC0_OVERFLOW = 20;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F0VC1_UNDERFLOW = 21;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F0VC1_OVERFLOW = 22;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F1VC0_UNDERFLOW = 23;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F1VC0_OVERFLOW = 24;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F1VC1_UNDERFLOW = 25;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_F1VC1_OVERFLOW = 26;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_VC0_PREFETCH_OVERFLOW = 27;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_VC1_PREFETCH_OVERFLOW = 28;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_IB23_EVN0_UNDERFLOW = 29;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_IB23_EVN0_OVERFLOW = 30;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_IB23_EVN1_UNDERFLOW = 31;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_IB23_EVN1_OVERFLOW = 32;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_IB23_RTAG_PBITERR = 33;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_IB23_RTAG_PERR = 34;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_IB23_MISC_PERR = 35;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_IB23_ODD0_UNDERFLOW = 36;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_IB23_ODD0_OVERFLOW = 37;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_IB23_ODD1_UNDERFLOW = 38;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_IB23_ODD1_OVERFLOW = 39;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_IB23_RTAG_UNDERFLOW = 40;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_IB23_RTAG_OVERFLOW = 41;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_IB23_DATA_UNDERFLOW = 42;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_IB23_DATA_OVERFLOW = 43;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_IB23_VC0_UNDERFLOW = 44;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_IB23_VC0_OVERFLOW = 45;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_IB23_VC1_UNDERFLOW = 46;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_IB23_VC1_OVERFLOW = 47;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_DIBF0VC0_OVER_UNDERFLOW = 48;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_DIBF0VC1_OVER_UNDERFLOW = 49;
static const uint32_t PB_DOB23_DIB23_INT_ERR_REG_OB23_DIBF1VC0_OVER_UNDERFLOW = 50;
// pauc/reg00014.H

static const uint64_t PB_MAILBOX_10_REG = 0x10011832ull;
// pauc/reg00014.H

static const uint64_t PB_MAILBOX_11_REG = 0x10011833ull;
// pauc/reg00014.H

static const uint64_t PB_PMU2_CNPM_COUNTER = 0x10011823ull;

static const uint32_t PB_PMU2_CNPM_COUNTER_0 = 0;
static const uint32_t PB_PMU2_CNPM_COUNTER_0_LEN = 16;
static const uint32_t PB_PMU2_CNPM_COUNTER_1 = 16;
static const uint32_t PB_PMU2_CNPM_COUNTER_1_LEN = 16;
static const uint32_t PB_PMU2_CNPM_COUNTER_2 = 32;
static const uint32_t PB_PMU2_CNPM_COUNTER_2_LEN = 16;
// pauc/reg00014.H

static const uint64_t PB_PTL_FIR_MASK_REG_RW = 0x10011803ull;
static const uint64_t PB_PTL_FIR_MASK_REG_WO_AND = 0x10011804ull;
static const uint64_t PB_PTL_FIR_MASK_REG_WO_OR = 0x10011805ull;

static const uint32_t PB_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK = 0;
static const uint32_t PB_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK = 1;
static const uint32_t PB_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK = 2;
static const uint32_t PB_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK = 3;
static const uint32_t PB_PTL_FIR_MASK_REG_DOB01_UE_MASK = 4;
static const uint32_t PB_PTL_FIR_MASK_REG_DOB01_CE_MASK = 5;
static const uint32_t PB_PTL_FIR_MASK_REG_DOB01_SUE_MASK = 6;
static const uint32_t PB_PTL_FIR_MASK_REG_DOB01_ERR_MASK = 7;
static const uint32_t PB_PTL_FIR_MASK_REG_DOB23_UE_MASK = 8;
static const uint32_t PB_PTL_FIR_MASK_REG_DOB23_CE_MASK = 9;
static const uint32_t PB_PTL_FIR_MASK_REG_DOB23_SUE_MASK = 10;
static const uint32_t PB_PTL_FIR_MASK_REG_DOB23_ERR_MASK = 11;
static const uint32_t PB_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK = 12;
static const uint32_t PB_PTL_FIR_MASK_REG_CROB01_ATTN_MASK = 13;
static const uint32_t PB_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK = 14;
static const uint32_t PB_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK = 15;
static const uint32_t PB_PTL_FIR_MASK_REG_CROB23_ATTN_MASK = 16;
static const uint32_t PB_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK = 17;
static const uint32_t PB_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK = 18;
static const uint32_t PB_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK = 19;
static const uint32_t PB_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK = 20;
static const uint32_t PB_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK = 21;
static const uint32_t PB_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK = 22;
static const uint32_t PB_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK = 23;
static const uint32_t PB_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK = 24;
static const uint32_t PB_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK = 25;
static const uint32_t PB_PTL_FIR_MASK_REG_DIB01_ERR_MASK = 26;
static const uint32_t PB_PTL_FIR_MASK_REG_DIB23_ERR_MASK = 27;
static const uint32_t PB_PTL_FIR_MASK_REG_MB00_SPATTN_MASK = 28;
static const uint32_t PB_PTL_FIR_MASK_REG_MB01_SPATTN_MASK = 29;
static const uint32_t PB_PTL_FIR_MASK_REG_MB10_SPATTN_MASK = 30;
static const uint32_t PB_PTL_FIR_MASK_REG_MB11_SPATTN_MASK = 31;
static const uint32_t PB_PTL_FIR_MASK_REG_MB20_SPATTN_MASK = 32;
static const uint32_t PB_PTL_FIR_MASK_REG_MB21_SPATTN_MASK = 33;
static const uint32_t PB_PTL_FIR_MASK_REG_MB30_SPATTN_MASK = 34;
static const uint32_t PB_PTL_FIR_MASK_REG_MB31_SPATTN_MASK = 35;
static const uint32_t PB_PTL_FIR_MASK_REG_PTL0_SPARE_MASK = 36;
static const uint32_t PB_PTL_FIR_MASK_REG_PTL1_SPARE_MASK = 37;
static const uint32_t PB_PTL_FIR_MASK_REG_PTL2_SPARE_MASK = 38;
static const uint32_t PB_PTL_FIR_MASK_REG_PTL3_SPARE_MASK = 39;
// pauc/reg00014.H

static const uint64_t PHY_SCOM_MAC_FIR_ACTION0_REG = 0x10012c06ull;

static const uint32_t PHY_SCOM_MAC_FIR_ACTION0_REG_FIR_ACTION0 = 0;
static const uint32_t PHY_SCOM_MAC_FIR_ACTION0_REG_FIR_ACTION0_LEN = 26;
// pauc/reg00014.H

static const uint64_t PHY_SCOM_MAC_FIR_ACTION1_REG = 0x10012c07ull;

static const uint32_t PHY_SCOM_MAC_FIR_ACTION1_REG_FIR_ACTION1 = 0;
static const uint32_t PHY_SCOM_MAC_FIR_ACTION1_REG_FIR_ACTION1_LEN = 26;
// pauc/reg00014.H

static const uint64_t RCMD_RATE_CFG = 0x1001180cull;

static const uint32_t RCMD_RATE_CFG_X_RCMD_RATE = 0;
static const uint32_t RCMD_RATE_CFG_X_RCMD_RATE_LEN = 8;
static const uint32_t RCMD_RATE_CFG_Y_RCMD_RATE = 8;
static const uint32_t RCMD_RATE_CFG_Y_RCMD_RATE_LEN = 8;
static const uint32_t RCMD_RATE_CFG_X_RCMD_RATE_ADDER = 16;
static const uint32_t RCMD_RATE_CFG_X_RCMD_RATE_ADDER_LEN = 4;
static const uint32_t RCMD_RATE_CFG_Y_RCMD_RATE_ADDER = 20;
static const uint32_t RCMD_RATE_CFG_Y_RCMD_RATE_ADDER_LEN = 4;
static const uint32_t RCMD_RATE_CFG_X_DISABLE_TURBO = 24;
static const uint32_t RCMD_RATE_CFG_X_CMD_GAP_REFERENCE = 25;
static const uint32_t RCMD_RATE_CFG_X_CMD_GAP_MODE = 26;
static const uint32_t RCMD_RATE_CFG_X_CMD_GAP_TABLE = 27;
static const uint32_t RCMD_RATE_CFG_X_DISABLE_CREDIT_BANK = 28;
static const uint32_t RCMD_RATE_CFG_X_CMD_GAP_CFG = 29;
static const uint32_t RCMD_RATE_CFG_X_CMD_GAP_CFG_LEN = 3;
static const uint32_t RCMD_RATE_CFG_Y_DISABLE_TURBO = 32;
static const uint32_t RCMD_RATE_CFG_Y_CMD_GAP_REFERENCE = 33;
static const uint32_t RCMD_RATE_CFG_Y_CMD_GAP_MODE = 34;
static const uint32_t RCMD_RATE_CFG_Y_CMD_GAP_TABLE = 35;
static const uint32_t RCMD_RATE_CFG_Y_DISABLE_CREDIT_BANK = 36;
static const uint32_t RCMD_RATE_CFG_Y_CMD_GAP_CFG = 37;
static const uint32_t RCMD_RATE_CFG_Y_CMD_GAP_CFG_LEN = 3;
// pauc/reg00014.H

static const uint64_t SLAVE_CONFIG_REG = 0x100f001eull;

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
// pauc/reg00014.H

static const uint64_t TRA1_TR0_CONFIG_1 = 0x10010484ull;

static const uint32_t TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// pauc/reg00014.H

static const uint64_t XSTOP2 = 0x1003000dull;

static const uint32_t XSTOP2_MASK_B = 0;
static const uint32_t XSTOP2_ALIGNED_XSTOP2 = 1;
static const uint32_t XSTOP2_TRIGGER_OPCG_ON_XSTOP2 = 2;
static const uint32_t XSTOP2_WAIT_ALLWAYS = 3;
static const uint32_t XSTOP2_PERV = 4;
static const uint32_t XSTOP2_UNIT1 = 5;
static const uint32_t XSTOP2_UNIT2 = 6;
static const uint32_t XSTOP2_UNIT3 = 7;
static const uint32_t XSTOP2_UNIT4 = 8;
static const uint32_t XSTOP2_UNIT5 = 9;
static const uint32_t XSTOP2_UNIT6 = 10;
static const uint32_t XSTOP2_UNIT7 = 11;
static const uint32_t XSTOP2_UNIT8 = 12;
static const uint32_t XSTOP2_UNIT9 = 13;
static const uint32_t XSTOP2_UNIT10 = 14;
static const uint32_t XSTOP2_UNIT11 = 15;
static const uint32_t XSTOP2_UNIT12 = 16;
static const uint32_t XSTOP2_UNIT13 = 17;
static const uint32_t XSTOP2_UNIT14 = 18;
static const uint32_t XSTOP2_WAIT_CYCLES = 48;
static const uint32_t XSTOP2_WAIT_CYCLES_LEN = 12;
// pauc/reg00014.H

#ifndef __PPE_HCODE__
}
}
#include "pauc/reg00014.H"
#endif
#endif
