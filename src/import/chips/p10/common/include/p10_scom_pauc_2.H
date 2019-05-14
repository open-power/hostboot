/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pauc_2.H $       */
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

#ifndef __p10_scom_pauc_2_H_
#define __p10_scom_pauc_2_H_


namespace scomt
{
namespace pauc
{


static const uint64_t CPLT_STAT0 = 0x10000100ull;

static const uint32_t CPLT_STAT0_ABIST_DONE_DC = 0;
static const uint32_t CPLT_STAT0_RESERVED_2I = 2;
static const uint32_t CPLT_STAT0_RESERVED_3I = 3;
static const uint32_t CPLT_STAT0_TC_DIAG_PORT0_OUT = 4;
static const uint32_t CPLT_STAT0_TC_DIAG_PORT1_OUT = 5;
static const uint32_t CPLT_STAT0_RESERVED_6I = 6;
static const uint32_t CPLT_STAT0_CC_CTRL_OPCG_DONE_DC = 8;
static const uint32_t CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC = 9;
static const uint32_t CPLT_STAT0_FREE_USAGE_10I = 10;
static const uint32_t CPLT_STAT0_FREE_USAGE_11I = 11;
static const uint32_t CPLT_STAT0_FREE_USAGE_12I = 12;
static const uint32_t CPLT_STAT0_FREE_USAGE_13I = 13;
static const uint32_t CPLT_STAT0_FREE_USAGE_14I = 14;
static const uint32_t CPLT_STAT0_FREE_USAGE_15I = 15;
static const uint32_t CPLT_STAT0_FREE_USAGE_16I = 16;
static const uint32_t CPLT_STAT0_FREE_USAGE_17I = 17;
static const uint32_t CPLT_STAT0_FREE_USAGE_18I = 18;
static const uint32_t CPLT_STAT0_FREE_USAGE_19I = 19;
static const uint32_t CPLT_STAT0_FREE_USAGE_20I = 20;
static const uint32_t CPLT_STAT0_FREE_USAGE_21I = 21;
static const uint32_t CPLT_STAT0_FREE_USAGE_22I = 22;
static const uint32_t CPLT_STAT0_FREE_USAGE_23I = 23;
static const uint32_t CPLT_STAT0_FREE_USAGE_24I = 24;
static const uint32_t CPLT_STAT0_FREE_USAGE_25I = 25;
static const uint32_t CPLT_STAT0_FREE_USAGE_26I = 26;
static const uint32_t CPLT_STAT0_FREE_USAGE_27I = 27;
static const uint32_t CPLT_STAT0_FREE_USAGE_28I = 28;
static const uint32_t CPLT_STAT0_FREE_USAGE_29I = 29;
static const uint32_t CPLT_STAT0_FREE_USAGE_30I = 30;
static const uint32_t CPLT_STAT0_FREE_USAGE_31I = 31;
// pauc/reg00002.H

static const uint64_t PB_FP23_CFG = 0x1001180bull;

static const uint32_t PB_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 = 0;
static const uint32_t PB_FP23_CFG_2_DISABLE_GATHERING = 1;
static const uint32_t PB_FP23_CFG_2_DISABLE_CMD_COMPRESSION = 2;
static const uint32_t PB_FP23_CFG_2_DISABLE_PRSP_COMPRESSION = 3;
static const uint32_t PB_FP23_CFG_2_LL_CREDIT_LO_LIMIT = 4;
static const uint32_t PB_FP23_CFG_2_LL_CREDIT_LO_LIMIT_LEN = 8;
static const uint32_t PB_FP23_CFG_2_LL_CREDIT_PS_LIMIT = 12;
static const uint32_t PB_FP23_CFG_2_LL_CREDIT_PS_LIMIT_LEN = 8;
static const uint32_t PB_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP = 20;
static const uint32_t PB_FP23_CFG_23_CMD_EXP_TIME = 21;
static const uint32_t PB_FP23_CFG_23_CMD_EXP_TIME_LEN = 3;
static const uint32_t PB_FP23_CFG_2_RUN_AFTER_FRAME_ERROR = 24;
static const uint32_t PB_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST = 25;
static const uint32_t PB_FP23_CFG_2_PRS_SPARE = 26;
static const uint32_t PB_FP23_CFG_2_PRS_SPARE_LEN = 6;
static const uint32_t PB_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 = 32;
static const uint32_t PB_FP23_CFG_3_DISABLE_GATHERING = 33;
static const uint32_t PB_FP23_CFG_3_DISABLE_CMD_COMPRESSION = 34;
static const uint32_t PB_FP23_CFG_3_DISABLE_PRSP_COMPRESSION = 35;
static const uint32_t PB_FP23_CFG_3_LL_CREDIT_LO_LIMIT = 36;
static const uint32_t PB_FP23_CFG_3_LL_CREDIT_LO_LIMIT_LEN = 8;
static const uint32_t PB_FP23_CFG_3_LL_CREDIT_PS_LIMIT = 44;
static const uint32_t PB_FP23_CFG_3_LL_CREDIT_PS_LIMIT_LEN = 8;
static const uint32_t PB_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP = 52;
static const uint32_t PB_FP23_CFG_3_FMR_SPARE = 53;
static const uint32_t PB_FP23_CFG_3_FMR_SPARE_LEN = 3;
static const uint32_t PB_FP23_CFG_3_RUN_AFTER_FRAME_ERROR = 56;
static const uint32_t PB_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST = 57;
static const uint32_t PB_FP23_CFG_3_PRS_SPARE = 58;
static const uint32_t PB_FP23_CFG_3_PRS_SPARE_LEN = 6;
// pauc/reg00002.H

static const uint64_t PB_TRACE_CFG = 0x10011826ull;

static const uint32_t PB_TRACE_CFG_0L_SEL = 0;
static const uint32_t PB_TRACE_CFG_0L_SEL_LEN = 8;
static const uint32_t PB_TRACE_CFG_0R_SEL = 8;
static const uint32_t PB_TRACE_CFG_0R_SEL_LEN = 8;
static const uint32_t PB_TRACE_CFG_1L_SEL = 16;
static const uint32_t PB_TRACE_CFG_1L_SEL_LEN = 8;
static const uint32_t PB_TRACE_CFG_1R_SEL = 24;
static const uint32_t PB_TRACE_CFG_1R_SEL_LEN = 8;
// pauc/reg00002.H

static const uint64_t PPE_XIDBGPRO = 0x10012c15ull;

static const uint32_t PPE_XIDBGPRO_SIBRC = 9;
static const uint32_t PPE_XIDBGPRO_SIBRC_LEN = 3;
static const uint32_t PPE_XIDBGPRO_WE = 14;
static const uint32_t PPE_XIDBGPRO_LP = 20;
// pauc/reg00002.H

static const uint64_t REGS_TX_IMPCAL_PVAL_PB = 0x800f240010012c3full;

static const uint32_t REGS_TX_IMPCAL_PVAL_PB_TX_ZCAL_P = 48;
static const uint32_t REGS_TX_IMPCAL_PVAL_PB_TX_ZCAL_P_LEN = 9;
// pauc/reg00002.H

static const uint64_t REGS_ZCAL_FIR_PB = 0x800f880010012c3full;
// pauc/reg00002.H

static const uint64_t SPATTN = 0x10040002ull;

static const uint32_t SPATTN_ANY_SPATTN = 0;
static const uint32_t SPATTN_RESERVED1S = 1;
static const uint32_t SPATTN_RESERVED2S = 2;
static const uint32_t SPATTN_RESERVED3S = 3;
static const uint32_t SPATTN_SPATTN_PERV = 4;
static const uint32_t SPATTN_SPATTN_IN05 = 5;
static const uint32_t SPATTN_SPATTN_IN06 = 6;
static const uint32_t SPATTN_SPATTN_IN07 = 7;
static const uint32_t SPATTN_SPATTN_IN08 = 8;
static const uint32_t SPATTN_SPATTN_IN09 = 9;
static const uint32_t SPATTN_SPATTN_IN10 = 10;
static const uint32_t SPATTN_SPATTN_IN11 = 11;
static const uint32_t SPATTN_SPATTN_IN12 = 12;
static const uint32_t SPATTN_SPATTN_IN13 = 13;
static const uint32_t SPATTN_SPATTN_IN14 = 14;
static const uint32_t SPATTN_SPATTN_IN15 = 15;
static const uint32_t SPATTN_SPATTN_IN16 = 16;
static const uint32_t SPATTN_SPATTN_IN17 = 17;
static const uint32_t SPATTN_SPATTN_IN18 = 18;
static const uint32_t SPATTN_SPATTN_IN19 = 19;
static const uint32_t SPATTN_SPATTN_IN20 = 20;
static const uint32_t SPATTN_SPATTN_IN21 = 21;
static const uint32_t SPATTN_SPATTN_IN22 = 22;
static const uint32_t SPATTN_SPATTN_IN23 = 23;
static const uint32_t SPATTN_SPATTN_IN24 = 24;
static const uint32_t SPATTN_SPATTN_IN25 = 25;
static const uint32_t SPATTN_SPATTN_IN26 = 26;
static const uint32_t SPATTN_SPATTN_IN27 = 27;
static const uint32_t SPATTN_SPATTN_IN28 = 28;
static const uint32_t SPATTN_SPATTN_IN29 = 29;
static const uint32_t SPATTN_SPATTN_IN30 = 30;
static const uint32_t SPATTN_SPATTN_IN31 = 31;
static const uint32_t SPATTN_SPATTN_IN32 = 32;
static const uint32_t SPATTN_SPATTN_IN33 = 33;
static const uint32_t SPATTN_SPATTN_IN34 = 34;
static const uint32_t SPATTN_SPATTN_IN35 = 35;
// pauc/reg00002.H

static const uint64_t TRA0_TR1_CONFIG_5 = 0x10010448ull;

static const uint32_t TRA0_TR1_CONFIG_5_C = 0;
static const uint32_t TRA0_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TRA0_TR1_CONFIG_5_D = 24;
static const uint32_t TRA0_TR1_CONFIG_5_D_LEN = 24;
// pauc/reg00002.H

static const uint64_t TRA1_TR0_CONFIG_3 = 0x10010486ull;

static const uint32_t TRA1_TR0_CONFIG_3_C = 0;
static const uint32_t TRA1_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TRA1_TR0_CONFIG_3_D = 24;
static const uint32_t TRA1_TR0_CONFIG_3_D_LEN = 24;
// pauc/reg00002.H

}
}
#include "pauc/reg00002.H"
#endif
