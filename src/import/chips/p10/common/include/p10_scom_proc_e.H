/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_proc_e.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __p10_scom_proc_e_H_
#define __p10_scom_proc_e_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> [INT_VC_ESBC_FLUSH_CTRL]
static const uint64_t INT_VC_ESBC_FLUSH_CTRL = 0x02010940ull;

static const uint32_t INT_VC_ESBC_FLUSH_CTRL_POLL_VALID = 0;
static const uint32_t INT_VC_ESBC_FLUSH_CTRL_RESERVED_1 = 1;
static const uint32_t INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE = 2;
static const uint32_t INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7 = 3;
static const uint32_t INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7_LEN = 5;
//<< [INT_VC_ESBC_FLUSH_CTRL]
// proc/reg00070.H

//>> [MCD_BANK0_REC]
static const uint64_t MCD_BANK0_REC = 0x03010810ull;

static const uint32_t MCD_BANK0_REC_ENABLE = 0;
static const uint32_t MCD_BANK0_REC_DONE = 1;
static const uint32_t MCD_BANK0_REC_CONTINUOUS = 2;
static const uint32_t MCD_BANK0_REC_FILTER_ADDR_DIS = 3;
static const uint32_t MCD_BANK0_REC_RETRY_COUNT_EXCEED = 4;
static const uint32_t MCD_BANK0_REC_STATUS = 5;
static const uint32_t MCD_BANK0_REC_PACE = 8;
static const uint32_t MCD_BANK0_REC_PACE_LEN = 12;
static const uint32_t MCD_BANK0_REC_ADDR_ERROR = 20;
static const uint32_t MCD_BANK0_REC_ADDR = 21;
static const uint32_t MCD_BANK0_REC_ADDR_LEN = 15;
static const uint32_t MCD_BANK0_REC_RTY_COUNT = 40;
static const uint32_t MCD_BANK0_REC_RTY_COUNT_LEN = 4;
static const uint32_t MCD_BANK0_REC_VG_COUNT = 49;
static const uint32_t MCD_BANK0_REC_VG_COUNT_LEN = 15;
//<< [MCD_BANK0_REC]
// proc/reg00070.H

//>> [PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT]
static const uint64_t PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT = 0x03011c8bull;

static const uint32_t PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT = 0;
static const uint32_t PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT_LEN = 56;
//<< [PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT]
// proc/reg00070.H

//>> [PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT]
static const uint64_t PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT = 0x03011c8eull;

static const uint32_t PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT = 0;
static const uint32_t PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT_LEN = 56;
//<< [PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT]
// proc/reg00070.H

//>> [PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR]
static const uint64_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR = 0x03011012ull;

static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0 = 0;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0 = 1;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0 = 2;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0 = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0 = 4;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0 = 5;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0 = 6;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0 = 7;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0 = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0 = 9;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0 = 10;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0 = 11;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0 = 12;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0 = 13;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0 = 14;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0 = 15;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0 = 16;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0 = 19;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0 = 22;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0 = 25;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0 = 28;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0 = 31;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0 = 34;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0 = 37;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0 = 40;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0 = 43;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0 = 46;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0 = 49;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0 = 52;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0 = 55;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0 = 58;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0 = 61;
static const uint32_t PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0_LEN = 3;
//<< [PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR]
// proc/reg00070.H

//>> [PB_COM_SCOM_EQ0_STATION_MODE]
static const uint64_t PB_COM_SCOM_EQ0_STATION_MODE = 0x0301100aull;

static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT = 0;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED = 1;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0 = 4;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0 = 5;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0 = 6;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0 = 7;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE = 9;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0 = 10;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0 = 11;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0 = 12;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0 = 13;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0 = 16;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0_LEN = 7;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0 = 23;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0_LEN = 7;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0 = 30;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0_LEN = 6;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0 = 36;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL = 39;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL_LEN = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0 = 42;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0_LEN = 2;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0 = 44;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0 = 45;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0_LEN = 2;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0 = 47;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL = 48;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL_LEN = 4;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0 = 52;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0 = 53;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0 = 54;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0 = 55;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0_LEN = 4;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0 = 59;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0_LEN = 4;
static const uint32_t PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0 = 63;
//<< [PB_COM_SCOM_EQ0_STATION_MODE]
// proc/reg00070.H

//>> [PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT]
static const uint64_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT = 0x0301138full;

static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3 = 0;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3 = 1;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3 = 2;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3 = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3 = 4;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3 = 5;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3 = 6;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3 = 7;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3 = 8;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3 = 9;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3 = 10;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3 = 11;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3 = 12;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3 = 13;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3 = 14;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3 = 15;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3 = 16;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3 = 19;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3 = 22;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3 = 25;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3 = 28;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3 = 31;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3 = 34;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3 = 37;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3 = 40;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3 = 43;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3 = 46;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3 = 49;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3 = 52;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3 = 55;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3 = 58;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3_LEN = 3;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3 = 61;
static const uint32_t PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3_LEN = 3;
//<< [PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT]
// proc/reg00071.H

//>> [TP_TPBR_AD_ALTD_CMD_REG]
static const uint64_t TP_TPBR_AD_ALTD_CMD_REG = 0x00090001ull;

static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP = 2;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS = 3;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM = 4;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW = 5;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE = 6;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY = 7;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK = 10;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED = 11;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID = 12;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID_LEN = 4;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE = 16;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE_LEN = 3;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC = 19;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY = 20;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX = 21;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT = 22;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT = 23;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE = 24;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE = 25;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE_LEN = 7;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE = 25;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE_LEN = 7;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE = 32;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE_LEN = 8;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE = 32;
static const uint32_t TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE_LEN = 8;
//<< [TP_TPBR_AD_ALTD_CMD_REG]
// proc/reg00072.H

//>> [TP_TPBR_PBA_PBAO_PBAFIRMASK]
static const uint64_t TP_TPBR_PBA_PBAO_PBAFIRMASK_RW = 0x01010cc3ull;
static const uint64_t TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND = 0x01010cc4ull;
static const uint64_t TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR = 0x01010cc5ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK = 1;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3 = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK = 6;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK = 7;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK = 9;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK = 10;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK = 11;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK = 12;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK = 13;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK = 14;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK = 15;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK = 16;
static const uint32_t TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK_LEN = 4;
static const uint32_t P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK = 16; // p10:20,
static const uint32_t P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK = 17; // p10:20,
static const uint32_t P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK = 18; // p10:20,
static const uint32_t P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK_LEN = 2;
//<< [TP_TPBR_PBA_PBAO_PBAFIRMASK]
// proc/reg00072.H

//>> [TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL]
static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL = 0x0006402bull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 = 31;
//<< [TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL]
// proc/reg00072.H

//>> [TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU]
static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU = 0x0006402aull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER_LEN = 32;
//<< [TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU]
// proc/reg00072.H

//>> [TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR]
static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR = 0x00066001ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN = 23;
//<< [TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR]
// proc/reg00072.H

//>> [TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR]
static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR = 0x00066004ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY = 8;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE = 12;
//<< [TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR]
// proc/reg00072.H

//>> [TP_TPCHIP_OCC_OCI_OCB_ADC_CR2]
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ADC_CR2 = 0x0006c802ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY_LEN = 17;
//<< [TP_TPCHIP_OCC_OCI_OCB_ADC_CR2]
// proc/reg00072.H

//>> [TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6]
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6 = 0x0006c826ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5 = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7 = 48;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7_LEN = 16;
//<< [TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6]
// proc/reg00072.H

//>> [TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B]
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B = 0x0006c717ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B = 1;
//<< [TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B]
// proc/reg00072.H

//>> [TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2]
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2 = 0x0006c741ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2_LEN = 6;
//<< [TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2]
// proc/reg00072.H

//>> [TP_TPCHIP_OCC_OCI_OCB_O2SRD2B]
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SRD2B = 0x0006c759ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B_LEN = 32;
//<< [TP_TPCHIP_OCC_OCI_OCB_O2SRD2B]
// proc/reg00072.H

//>> [TP_TPCHIP_OCC_OCI_OCB_O2SWD0B]
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SWD0B = 0x0006c718ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B_LEN = 32;
//<< [TP_TPCHIP_OCC_OCI_OCB_O2SWD0B]
// proc/reg00072.H

//>> [TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1]
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1 = 0x0006c213ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START_LEN = 26;
//<< [TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1]
// proc/reg00072.H

//>> [TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0]
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0 = 0x0006c204ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR = 21;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR_LEN = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE = 31;
//<< [TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0]
// proc/reg00072.H

//>> [TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3]
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3 = 0x0006d070ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS_LEN = 26;
//<< [TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3]
// proc/reg00073.H

//>> [TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC]
static const uint64_t TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC = 0x000e0009ull;

static const uint32_t TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR = 0;
static const uint32_t TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR_LEN = 27;
static const uint32_t TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR = 32;
static const uint32_t TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING = 34;
static const uint32_t TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING = 35;
static const uint32_t TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID = 36;
static const uint32_t TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID_LEN = 4;
static const uint32_t TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID = 40;
static const uint32_t TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID_LEN = 4;
static const uint32_t TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR = 45;
static const uint32_t TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR = 46;
static const uint32_t TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING = 47;
//<< [TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC]
// proc/reg00073.H

//>> [TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ]
static const uint64_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ = 0x01060151ull;

static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX = 1;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX_LEN = 11;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX = 12;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT = 17;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT_LEN = 11;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT = 28;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT_LEN = 4;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN = 33;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN_LEN = 11;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN = 44;
static const uint32_t TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN_LEN = 4;
//<< [TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ]
// proc/reg00073.H

//>> [TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI = 0x0000281dull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE = 0x00002874ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO = 0x0005001dull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B = 24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B = 26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A = 27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B = 28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A = 29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B = 30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31 = 31;
//<< [TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH]
// proc/reg00073.H

//>> [TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER]
static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI = 0x00000c20ull;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE = 0x00000c80ull;

static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1 = 0;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1_LEN = 32;
//<< [TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER]
// proc/reg00074.H

//>> [TP_TPCHIP_OCC_OCI_OCB_OCCFLG6]
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG6_RW = 0x0006c0beull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG6_WO_CLEAR = 0x0006c0bfull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG6_WO_OR = 0x0006c0c0ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG6_OCB_OCI_OCCFLG6_OCC_FLAGS = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCFLG6_OCB_OCI_OCCFLG6_OCC_FLAGS_LEN = 32;
//<< [TP_TPCHIP_OCC_OCI_OCB_OCCFLG6]
// proc/reg00072.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "proc/reg00070.H"
#include "proc/reg00071.H"
#include "proc/reg00072.H"
#include "proc/reg00073.H"
#include "proc/reg00074.H"
#endif
#endif
