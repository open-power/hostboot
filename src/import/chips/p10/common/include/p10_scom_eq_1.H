/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_1.H $         */
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

#ifndef __p10_scom_eq_1_H_
#define __p10_scom_eq_1_H_


namespace scomt
{
namespace eq
{


static const uint64_t DBG_CBS_CC = 0x20030013ull;

static const uint32_t DBG_CBS_CC_DBG_RESET_EP = 0;
static const uint32_t DBG_CBS_CC_DBG_OPCG_IP = 1;
static const uint32_t DBG_CBS_CC_DBG_VITL_CLKOFF = 2;
static const uint32_t DBG_CBS_CC_DBG_TEST_ENABLE = 3;
static const uint32_t DBG_CBS_CC_DBG_CBS_REQ = 4;
static const uint32_t DBG_CBS_CC_DBG_CBS_CMD = 5;
static const uint32_t DBG_CBS_CC_DBG_CBS_CMD_LEN = 3;
static const uint32_t DBG_CBS_CC_DBG_CBS_STATE = 8;
static const uint32_t DBG_CBS_CC_DBG_CBS_STATE_LEN = 5;
static const uint32_t DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE = 13;
static const uint32_t DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR = 14;
static const uint32_t DBG_CBS_CC_DBG_PCB_IDLE = 15;
static const uint32_t DBG_CBS_CC_DBG_CURRENT_OPCG_MODE = 16;
static const uint32_t DBG_CBS_CC_DBG_CURRENT_OPCG_MODE_LEN = 4;
static const uint32_t DBG_CBS_CC_DBG_LAST_OPCG_MODE = 20;
static const uint32_t DBG_CBS_CC_DBG_LAST_OPCG_MODE_LEN = 4;
static const uint32_t DBG_CBS_CC_DBG_PCB_ERROR = 24;
static const uint32_t DBG_CBS_CC_DBG_PARITY_ERROR = 25;
static const uint32_t DBG_CBS_CC_DBG_CC_ERROR = 26;
static const uint32_t DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED = 27;
static const uint32_t DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET = 28;
static const uint32_t DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE = 29;
static const uint32_t DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE = 30;
static const uint32_t DBG_CBS_CC_TP_TPFSI_CBS_ACK = 31;
// eq/reg00001.H

static const uint64_t EPS_THERM_WSUB2_DTS_TRC_RESULT = 0x20050023ull;

static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE = 0;
static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE_LEN = 44;
static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR = 44;
static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT = 48;
static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT_LEN = 16;
// eq/reg00001.H

static const uint64_t EPS_THERM_WSUB2_ERR_STATUS_REG = 0x20050033ull;
// eq/reg00001.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_DATA1 = 0x2005003aull;
// eq/reg00001.H

static const uint64_t HEARTBEAT_REG = 0x200f0018ull;

static const uint32_t HEARTBEAT_REG_HEARTBEAT_DEAD = 0;
// eq/reg00001.H

static const uint64_t L3TRA0_TR1_CONFIG_2 = 0x20018225ull;

static const uint32_t L3TRA0_TR1_CONFIG_2_A = 0;
static const uint32_t L3TRA0_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t L3TRA0_TR1_CONFIG_2_B = 24;
static const uint32_t L3TRA0_TR1_CONFIG_2_B_LEN = 24;
// eq/reg00001.H

static const uint64_t L3TRA1_TR0_CONFIG_4 = 0x20018247ull;

static const uint32_t L3TRA1_TR0_CONFIG_4_A = 0;
static const uint32_t L3TRA1_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t L3TRA1_TR0_CONFIG_4_B = 24;
static const uint32_t L3TRA1_TR0_CONFIG_4_B_LEN = 24;
// eq/reg00001.H

static const uint64_t L3TRA2_TR0_CONFIG_3 = 0x20018286ull;

static const uint32_t L3TRA2_TR0_CONFIG_3_C = 0;
static const uint32_t L3TRA2_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t L3TRA2_TR0_CONFIG_3_D = 24;
static const uint32_t L3TRA2_TR0_CONFIG_3_D_LEN = 24;
// eq/reg00001.H

static const uint64_t L3TRA3_TR1_CONFIG_5 = 0x200182e8ull;

static const uint32_t L3TRA3_TR1_CONFIG_5_C = 0;
static const uint32_t L3TRA3_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t L3TRA3_TR1_CONFIG_5_D = 24;
static const uint32_t L3TRA3_TR1_CONFIG_5_D_LEN = 24;
// eq/reg00001.H

static const uint64_t OPCG_CAPT3 = 0x20030012ull;

static const uint32_t OPCG_CAPT3_07EVEN = 4;
static const uint32_t OPCG_CAPT3_07EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_07ODD = 9;
static const uint32_t OPCG_CAPT3_07ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_08EVEN = 14;
static const uint32_t OPCG_CAPT3_08EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_08ODD = 19;
static const uint32_t OPCG_CAPT3_08ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_09EVEN = 24;
static const uint32_t OPCG_CAPT3_09EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_09ODD = 29;
static const uint32_t OPCG_CAPT3_09ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_10EVEN = 34;
static const uint32_t OPCG_CAPT3_10EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_10ODD = 39;
static const uint32_t OPCG_CAPT3_10ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_11EVEN = 44;
static const uint32_t OPCG_CAPT3_11EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_11ODD = 49;
static const uint32_t OPCG_CAPT3_11ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_12EVEN = 54;
static const uint32_t OPCG_CAPT3_12EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_12ODD = 59;
static const uint32_t OPCG_CAPT3_12ODD_LEN = 5;
// eq/reg00001.H

static const uint64_t QME_EIPR_RW = 0x200e0268ull;
static const uint64_t QME_EIPR_WO_CLEAR = 0x200e026bull;
static const uint64_t QME_EIPR_WO_OR = 0x200e026aull;

static const uint32_t QME_EIPR_QME_EIPR_INTERRUPT_POLARITY = 0;
static const uint32_t QME_EIPR_QME_EIPR_INTERRUPT_POLARITY_LEN = 64;
// eq/reg00001.H

static const uint64_t QME_LFIRMASK_RW = 0x200e0004ull;
static const uint64_t QME_LFIRMASK_WO_AND = 0x200e0005ull;
static const uint64_t QME_LFIRMASK_WO_OR = 0x200e0006ull;

static const uint32_t QME_LFIRMASK_QME_LFIRMASK_FIR_MASK = 0;
static const uint32_t QME_LFIRMASK_QME_LFIRMASK_FIR_MASK_LEN = 28;
// eq/reg00001.H

static const uint64_t QME_SCDR = 0x200e0144ull;
// eq/reg00001.H

static const uint64_t QME_SCOM_XIDBGPRO = 0x200e0214ull;
// eq/reg00001.H

static const uint64_t QME_SSDR = 0x200e0140ull;

static const uint32_t QME_SSDR_0_QME_SCSR_PM_EXIT = 8;
static const uint32_t QME_SSDR_1_QME_SCSR_PM_EXIT = 9;
static const uint32_t QME_SSDR_2_QME_SCSR_PM_EXIT = 10;
static const uint32_t QME_SSDR_3_QME_SCSR_PM_EXIT = 11;
static const uint32_t QME_SSDR_0_QME_SCSR_BLOCK_INTR_OUTPUTS = 32;
static const uint32_t QME_SSDR_1_QME_SCSR_BLOCK_INTR_OUTPUTS = 33;
static const uint32_t QME_SSDR_2_QME_SCSR_BLOCK_INTR_OUTPUTS = 34;
static const uint32_t QME_SSDR_3_QME_SCSR_BLOCK_INTR_OUTPUTS = 35;
static const uint32_t QME_SSDR_0_QME_SCSR_PM_BLOCK_INTR = 36;
static const uint32_t QME_SSDR_1_QME_SCSR_PM_BLOCK_INTR = 37;
static const uint32_t QME_SSDR_2_QME_SCSR_PM_BLOCK_INTR = 38;
static const uint32_t QME_SSDR_3_QME_SCSR_PM_BLOCK_INTR = 39;
static const uint32_t QME_SSDR_0_QME_SSH_SRC_SAMPLED_STOP_ACTIVE = 44;
static const uint32_t QME_SSDR_1_QME_SSH_SRC_SAMPLED_STOP_ACTIVE = 45;
static const uint32_t QME_SSDR_2_QME_SSH_SRC_SAMPLED_STOP_ACTIVE = 46;
static const uint32_t QME_SSDR_3_QME_SSH_SRC_SAMPLED_STOP_ACTIVE = 47;
static const uint32_t QME_SSDR_0_QME_SSH_SRC_SAMPLED_STOP_STATE = 48;
static const uint32_t QME_SSDR_0_QME_SSH_SRC_SAMPLED_STOP_STATE_LEN = 4;
static const uint32_t QME_SSDR_1_QME_SSH_SRC_SAMPLED_STOP_STATE = 52;
static const uint32_t QME_SSDR_1_QME_SSH_SRC_SAMPLED_STOP_STATE_LEN = 4;
static const uint32_t QME_SSDR_2_QME_SSH_SRC_SAMPLED_STOP_STATE = 56;
static const uint32_t QME_SSDR_2_QME_SSH_SRC_SAMPLED_STOP_STATE_LEN = 4;
static const uint32_t QME_SSDR_3_QME_SSH_SRC_SAMPLED_STOP_STATE = 60;
static const uint32_t QME_SSDR_3_QME_SSH_SRC_SAMPLED_STOP_STATE_LEN = 4;
// eq/reg00001.H

static const uint64_t QME_SWHR = 0x200e014cull;

static const uint32_t QME_SWHR_0_QME_SSH_SRC_SPC_WKUP_RECENT_SET = 4;
static const uint32_t QME_SWHR_0_QME_SSH_SRC_SPC_WKUP_RECENT_SET_LEN = 2;
static const uint32_t QME_SWHR_0_QME_SSH_SRC_SPC_WKUP_RECENT_CLR = 6;
static const uint32_t QME_SWHR_0_QME_SSH_SRC_SPC_WKUP_RECENT_CLR_LEN = 2;
static const uint32_t QME_SWHR_0_QME_SSH_SRC_SPC_WKUP_RECENT_ACT = 8;
static const uint32_t QME_SWHR_0_QME_SSH_SRC_SPC_WKUP_RECENT_ACT_LEN = 2;
static const uint32_t QME_SWHR_0_QME_SSH_SRC_SPC_WKUP_RECENT_DRP = 10;
static const uint32_t QME_SWHR_0_QME_SSH_SRC_SPC_WKUP_RECENT_DRP_LEN = 2;
static const uint32_t QME_SWHR_0_QME_SPWU_OTR_SPECIAL_WKUP_REQ = 12;
static const uint32_t QME_SWHR_0_QME_SPWU_FSP_SPECIAL_WKUP_REQ = 13;
static const uint32_t QME_SWHR_0_QME_SPWU_OCC_SPECIAL_WKUP_REQ = 14;
static const uint32_t QME_SWHR_0_QME_SPWU_HYP_SPECIAL_WKUP_REQ = 15;
static const uint32_t QME_SWHR_1_QME_SSH_SRC_SPC_WKUP_RECENT_SET = 20;
static const uint32_t QME_SWHR_1_QME_SSH_SRC_SPC_WKUP_RECENT_SET_LEN = 2;
static const uint32_t QME_SWHR_1_QME_SSH_SRC_SPC_WKUP_RECENT_CLR = 22;
static const uint32_t QME_SWHR_1_QME_SSH_SRC_SPC_WKUP_RECENT_CLR_LEN = 2;
static const uint32_t QME_SWHR_1_QME_SSH_SRC_SPC_WKUP_RECENT_ACT = 24;
static const uint32_t QME_SWHR_1_QME_SSH_SRC_SPC_WKUP_RECENT_ACT_LEN = 2;
static const uint32_t QME_SWHR_1_QME_SSH_SRC_SPC_WKUP_RECENT_DRP = 26;
static const uint32_t QME_SWHR_1_QME_SSH_SRC_SPC_WKUP_RECENT_DRP_LEN = 2;
static const uint32_t QME_SWHR_1_QME_SPWU_OTR_SPECIAL_WKUP_REQ = 28;
static const uint32_t QME_SWHR_1_QME_SPWU_FSP_SPECIAL_WKUP_REQ = 29;
static const uint32_t QME_SWHR_1_QME_SPWU_OCC_SPECIAL_WKUP_REQ = 30;
static const uint32_t QME_SWHR_1_QME_SPWU_HYP_SPECIAL_WKUP_REQ = 31;
static const uint32_t QME_SWHR_2_QME_SSH_SRC_SPC_WKUP_RECENT_SET = 36;
static const uint32_t QME_SWHR_2_QME_SSH_SRC_SPC_WKUP_RECENT_SET_LEN = 2;
static const uint32_t QME_SWHR_2_QME_SSH_SRC_SPC_WKUP_RECENT_CLR = 38;
static const uint32_t QME_SWHR_2_QME_SSH_SRC_SPC_WKUP_RECENT_CLR_LEN = 2;
static const uint32_t QME_SWHR_2_QME_SSH_SRC_SPC_WKUP_RECENT_ACT = 40;
static const uint32_t QME_SWHR_2_QME_SSH_SRC_SPC_WKUP_RECENT_ACT_LEN = 2;
static const uint32_t QME_SWHR_2_QME_SSH_SRC_SPC_WKUP_RECENT_DRP = 42;
static const uint32_t QME_SWHR_2_QME_SSH_SRC_SPC_WKUP_RECENT_DRP_LEN = 2;
static const uint32_t QME_SWHR_2_QME_SPWU_OTR_SPECIAL_WKUP_REQ = 44;
static const uint32_t QME_SWHR_2_QME_SPWU_FSP_SPECIAL_WKUP_REQ = 45;
static const uint32_t QME_SWHR_2_QME_SPWU_OCC_SPECIAL_WKUP_REQ = 46;
static const uint32_t QME_SWHR_2_QME_SPWU_HYP_SPECIAL_WKUP_REQ = 47;
static const uint32_t QME_SWHR_3_QME_SSH_SRC_SPC_WKUP_RECENT_SET = 52;
static const uint32_t QME_SWHR_3_QME_SSH_SRC_SPC_WKUP_RECENT_SET_LEN = 2;
static const uint32_t QME_SWHR_3_QME_SSH_SRC_SPC_WKUP_RECENT_CLR = 54;
static const uint32_t QME_SWHR_3_QME_SSH_SRC_SPC_WKUP_RECENT_CLR_LEN = 2;
static const uint32_t QME_SWHR_3_QME_SSH_SRC_SPC_WKUP_RECENT_ACT = 56;
static const uint32_t QME_SWHR_3_QME_SSH_SRC_SPC_WKUP_RECENT_ACT_LEN = 2;
static const uint32_t QME_SWHR_3_QME_SSH_SRC_SPC_WKUP_RECENT_DRP = 58;
static const uint32_t QME_SWHR_3_QME_SSH_SRC_SPC_WKUP_RECENT_DRP_LEN = 2;
static const uint32_t QME_SWHR_3_QME_SPWU_OTR_SPECIAL_WKUP_REQ = 60;
static const uint32_t QME_SWHR_3_QME_SPWU_FSP_SPECIAL_WKUP_REQ = 61;
static const uint32_t QME_SWHR_3_QME_SPWU_OCC_SPECIAL_WKUP_REQ = 62;
static const uint32_t QME_SWHR_3_QME_SPWU_HYP_SPECIAL_WKUP_REQ = 63;
// eq/reg00001.H

static const uint64_t QME_SWPR0 = 0x200e0090ull;

static const uint32_t QME_SWPR0_BAR = 0;
static const uint32_t QME_SWPR0_BAR_LEN = 27;
static const uint32_t QME_SWPR0_SIZE = 44;
static const uint32_t QME_SWPR0_SIZE_LEN = 15;
// eq/reg00001.H

static const uint64_t QME_TBR = 0x200e0248ull;

static const uint32_t QME_TBR_TIMEBASE = 0;
static const uint32_t QME_TBR_TIMEBASE_LEN = 32;
static const uint32_t QME_TBR_CYCLES = 32;
static const uint32_t QME_TBR_CYCLES_LEN = 32;
// eq/reg00001.H

static const uint64_t RECOV_INTERRUPT_REG = 0x200f001bull;
// eq/reg00001.H

static const uint64_t SCAN32 = 0x20038000ull;
// eq/reg00001.H

static const uint64_t SCAN64 = 0x2003e000ull;
// eq/reg00001.H

}
}
#include "eq/reg00001.H"
#endif
