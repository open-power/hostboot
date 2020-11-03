/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_1.H $         */
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

#ifndef __p10_scom_eq_1_H_
#define __p10_scom_eq_1_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> [EPS_THERM_WSUB2_ERR_STATUS_REG]
static const uint64_t EPS_THERM_WSUB2_ERR_STATUS_REG = 0x20050033ull;

static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD = 0;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD = 1;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD = 2;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD = 3;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD = 4;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD = 5;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD = 6;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD = 7;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD = 8;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD = 9;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD = 10;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD = 11;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD = 12;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD = 13;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD = 14;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT = 15;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT = 40;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT_LEN = 4;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT = 44;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT_LEN = 3;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT = 47;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT = 48;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT = 49;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT_LEN = 2;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT = 51;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT_LEN = 4;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT = 55;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT = 56;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT = 57;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT = 58;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED = 59;
//<< [EPS_THERM_WSUB2_ERR_STATUS_REG]
// eq/reg00001.H

//>> [OPCG_CAPT3]
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
//<< [OPCG_CAPT3]
// eq/reg00001.H

//>> [QME_EIPR]
static const uint64_t QME_EIPR_RW = 0x200e0268ull;
static const uint64_t QME_EIPR_WO_CLEAR = 0x200e026bull;
static const uint64_t QME_EIPR_WO_OR = 0x200e026aull;

static const uint32_t QME_EIPR_INTERRUPT_POLARITY = 0;
static const uint32_t QME_EIPR_INTERRUPT_POLARITY_LEN = 64;
//<< [QME_EIPR]
// eq/reg00001.H

//>> [QME_LFIRMASK]
static const uint64_t QME_LFIRMASK_RW = 0x200e0004ull;
static const uint64_t QME_LFIRMASK_WO_AND = 0x200e0005ull;
static const uint64_t QME_LFIRMASK_WO_OR = 0x200e0006ull;

static const uint32_t QME_LFIRMASK_FIR_MASK = 0;
static const uint32_t QME_LFIRMASK_FIR_MASK_LEN = 36;
//<< [QME_LFIRMASK]
// eq/reg00001.H

//>> [QME_SCDR]
static const uint64_t QME_SCDR = 0x200e0144ull;

static const uint32_t QME_SCDR_STOP_GATED = 0;
static const uint32_t QME_SCDR_STOP_GATED_LEN = 4;
static const uint32_t QME_SCDR_STOP_TRANSITION_C0 = 4;
static const uint32_t QME_SCDR_STOP_TRANSITION_C0_LEN = 2;
static const uint32_t QME_SCDR_STOP_TRANSITION_C1 = 6;
static const uint32_t QME_SCDR_STOP_TRANSITION_C1_LEN = 2;
static const uint32_t QME_SCDR_STOP_TRANSITION_C2 = 8;
static const uint32_t QME_SCDR_STOP_TRANSITION_C2_LEN = 2;
static const uint32_t QME_SCDR_STOP_TRANSITION_C3 = 10;
static const uint32_t QME_SCDR_STOP_TRANSITION_C3_LEN = 2;
static const uint32_t QME_SCDR_SPC_WKUP_DONE = 12;
static const uint32_t QME_SCDR_SPC_WKUP_DONE_LEN = 4;
static const uint32_t QME_SCDR_REQ_STOP_LEVEL_C0 = 16;
static const uint32_t QME_SCDR_REQ_STOP_LEVEL_C0_LEN = 4;
static const uint32_t QME_SCDR_REQ_STOP_LEVEL_C1 = 20;
static const uint32_t QME_SCDR_REQ_STOP_LEVEL_C1_LEN = 4;
static const uint32_t QME_SCDR_REQ_STOP_LEVEL_C2 = 24;
static const uint32_t QME_SCDR_REQ_STOP_LEVEL_C2_LEN = 4;
static const uint32_t QME_SCDR_REQ_STOP_LEVEL_C3 = 28;
static const uint32_t QME_SCDR_REQ_STOP_LEVEL_C3_LEN = 4;
static const uint32_t QME_SCDR_REG_WKUP_REQUESTED = 32;
static const uint32_t QME_SCDR_REG_WKUP_REQUESTED_LEN = 4;
static const uint32_t QME_SCDR_SPC_WKUP_REQUESTED = 36;
static const uint32_t QME_SCDR_SPC_WKUP_REQUESTED_LEN = 4;
static const uint32_t QME_SCDR_SELF_SAVE_ACTIVE = 40;
static const uint32_t QME_SCDR_SELF_SAVE_ACTIVE_LEN = 4;
static const uint32_t QME_SCDR_SELF_RESTORE_ACTIVE = 44;
static const uint32_t QME_SCDR_SELF_RESTORE_ACTIVE_LEN = 4;
static const uint32_t QME_SCDR_ACT_STOP_LEVEL_C0 = 48;
static const uint32_t QME_SCDR_ACT_STOP_LEVEL_C0_LEN = 4;
static const uint32_t QME_SCDR_ACT_STOP_LEVEL_C1 = 52;
static const uint32_t QME_SCDR_ACT_STOP_LEVEL_C1_LEN = 4;
static const uint32_t QME_SCDR_ACT_STOP_LEVEL_C2 = 56;
static const uint32_t QME_SCDR_ACT_STOP_LEVEL_C2_LEN = 4;
static const uint32_t QME_SCDR_ACT_STOP_LEVEL_C3 = 60;
static const uint32_t QME_SCDR_ACT_STOP_LEVEL_C3_LEN = 4;
//<< [QME_SCDR]
// eq/reg00001.H

//>> [QME_SCOM_XIDBGPRO]
static const uint64_t QME_SCOM_XIDBGPRO = 0x200e0214ull;

static const uint32_t QME_SCOM_XIDBGPRO_XSR_HS = 0;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_HC = 1;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_HC_LEN = 3;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_HCP = 4;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_RIP = 5;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_SIP = 6;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_TRAP = 7;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_IAC = 8;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_SIB = 9;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_SIB_LEN = 3;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_RDAC = 12;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_WDAC = 13;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_WS = 14;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_TRH = 15;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_SMS = 16;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_SMS_LEN = 4;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_LP = 20;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_EP = 21;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_PTR = 24;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_ST = 25;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_MFE = 28;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_MCS = 29;
static const uint32_t QME_SCOM_XIDBGPRO_XSR_MCS_LEN = 3;
static const uint32_t QME_SCOM_XIDBGPRO_IAR = 32;
static const uint32_t QME_SCOM_XIDBGPRO_IAR_LEN = 30;
//<< [QME_SCOM_XIDBGPRO]
// eq/reg00001.H

//>> [QME_SSDR]
static const uint64_t QME_SSDR = 0x200e0140ull;

static const uint32_t QME_SSDR_PC_UNMASKED_ATTN = 0;
static const uint32_t QME_SSDR_PC_UNMASKED_ATTN_LEN = 4;
static const uint32_t QME_SSDR_INSTR_RUNNING = 4;
static const uint32_t QME_SSDR_INSTR_RUNNING_LEN = 4;
static const uint32_t QME_SSDR_QME_SCSR_PM_EXIT = 8;
// ERROR Duplicate Dial         static const uint32_t QME_SSDR_QME_SCSR_PM_EXIT = 9;
// ERROR Duplicate Dial         static const uint32_t QME_SSDR_QME_SCSR_PM_EXIT = 10;
// ERROR Duplicate Dial         static const uint32_t QME_SSDR_QME_SCSR_PM_EXIT = 11;
static const uint32_t QME_SSDR_PM_STATE_ACTIVE = 12;
static const uint32_t QME_SSDR_PM_STATE_ACTIVE_LEN = 4;
static const uint32_t QME_SSDR_PM_STATE_C0 = 16;
static const uint32_t QME_SSDR_PM_STATE_C0_LEN = 4;
static const uint32_t QME_SSDR_PM_STATE_C1 = 20;
static const uint32_t QME_SSDR_PM_STATE_C1_LEN = 4;
static const uint32_t QME_SSDR_PM_STATE_C2 = 24;
static const uint32_t QME_SSDR_PM_STATE_C2_LEN = 4;
static const uint32_t QME_SSDR_PM_STATE_C3 = 28;
static const uint32_t QME_SSDR_PM_STATE_C3_LEN = 4;
static const uint32_t QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS = 32;
// ERROR Duplicate Dial         static const uint32_t QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS = 33;
// ERROR Duplicate Dial         static const uint32_t QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS = 34;
// ERROR Duplicate Dial         static const uint32_t QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS = 35;
static const uint32_t QME_SSDR_QME_SCSR_PM_BLOCK_INTR = 36;
// ERROR Duplicate Dial         static const uint32_t QME_SSDR_QME_SCSR_PM_BLOCK_INTR = 37;
// ERROR Duplicate Dial         static const uint32_t QME_SSDR_QME_SCSR_PM_BLOCK_INTR = 38;
// ERROR Duplicate Dial         static const uint32_t QME_SSDR_QME_SCSR_PM_BLOCK_INTR = 39;
static const uint32_t QME_SSDR_PC_DPES_INTR_PEND = 40;
static const uint32_t QME_SSDR_PC_DPES_INTR_PEND_LEN = 4;
static const uint32_t QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE = 44;
// ERROR Duplicate Dial         static const uint32_t QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE = 45;
// ERROR Duplicate Dial         static const uint32_t QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE = 46;
// ERROR Duplicate Dial         static const uint32_t QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE = 47;
static const uint32_t QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE = 48;
static const uint32_t QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE_LEN = 4;
// ERROR Duplicate Dial         static const uint32_t QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE = 52;
// ERROR Duplicate Dial         static const uint32_t QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE_LEN = 4;
// ERROR Duplicate Dial         static const uint32_t QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE = 56;
// ERROR Duplicate Dial         static const uint32_t QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE_LEN = 4;
// ERROR Duplicate Dial         static const uint32_t QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE = 60;
// ERROR Duplicate Dial         static const uint32_t QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE_LEN = 4;
//<< [QME_SSDR]
// eq/reg00001.H

//>> [QME_SWHR]
static const uint64_t QME_SWHR = 0x200e014cull;

static const uint32_t QME_SWHR_SPC_WKUP_HISTORY_C0 = 0;
static const uint32_t QME_SWHR_SPC_WKUP_HISTORY_C0_LEN = 4;
static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET = 4;
static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET_LEN = 2;
static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR = 6;
static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR_LEN = 2;
static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT = 8;
static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT_LEN = 2;
static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP = 10;
static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP_LEN = 2;
static const uint32_t QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ = 12;
static const uint32_t QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ = 13;
static const uint32_t QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ = 14;
static const uint32_t QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ = 15;
static const uint32_t QME_SWHR_SPC_WKUP_HISTORY_C1 = 16;
static const uint32_t QME_SWHR_SPC_WKUP_HISTORY_C1_LEN = 4;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET = 20;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET_LEN = 2;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR = 22;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR_LEN = 2;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT = 24;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT_LEN = 2;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP = 26;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP_LEN = 2;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ = 28;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ = 29;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ = 30;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ = 31;
static const uint32_t QME_SWHR_SPC_WKUP_HISTORY_C2 = 32;
static const uint32_t QME_SWHR_SPC_WKUP_HISTORY_C2_LEN = 4;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET = 36;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET_LEN = 2;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR = 38;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR_LEN = 2;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT = 40;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT_LEN = 2;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP = 42;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP_LEN = 2;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ = 44;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ = 45;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ = 46;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ = 47;
static const uint32_t QME_SWHR_SPC_WKUP_HISTORY_C3 = 48;
static const uint32_t QME_SWHR_SPC_WKUP_HISTORY_C3_LEN = 4;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET = 52;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET_LEN = 2;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR = 54;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR_LEN = 2;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT = 56;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT_LEN = 2;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP = 58;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP_LEN = 2;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ = 60;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ = 61;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ = 62;
// ERROR Duplicate Dial         static const uint32_t QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ = 63;
//<< [QME_SWHR]
// eq/reg00001.H

//>> [QME_SWPR0]
static const uint64_t QME_SWPR0 = 0x200e0090ull;

static const uint32_t QME_SWPR0_BAR = 0;
static const uint32_t QME_SWPR0_BAR_LEN = 27;
static const uint32_t QME_SWPR0_SIZE = 44;
static const uint32_t QME_SWPR0_SIZE_LEN = 15;
//<< [QME_SWPR0]
// eq/reg00001.H

//>> [QME_TBR]
static const uint64_t QME_TBR = 0x200e0248ull;

static const uint32_t QME_TBR_TIMEBASE = 0;
static const uint32_t QME_TBR_TIMEBASE_LEN = 32;
static const uint32_t QME_TBR_CYCLES = 32;
static const uint32_t QME_TBR_CYCLES_LEN = 32;
//<< [QME_TBR]
// eq/reg00001.H

//>> [SCAN32]
static const uint64_t SCAN32 = 0x20038000ull;

static const uint32_t SCAN32_SCAN32_REG = 0;
static const uint32_t SCAN32_SCAN32_REG_LEN = 32;
//<< [SCAN32]
// eq/reg00001.H

//>> [SCAN64]
static const uint64_t SCAN64 = 0x2003e000ull;

static const uint32_t SCAN64_SCAN64_REG = 0;
static const uint32_t SCAN64_SCAN64_REG_LEN = 64;
//<< [SCAN64]
// eq/reg00001.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00001.H"
#endif
#endif
