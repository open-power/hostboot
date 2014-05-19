/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/proc_tod_utils/proc_tod_utils.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: proc_tod_utils.H,v 1.13 2013/03/05 23:21:15 jklazyns Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *!
// *! TITLE : proc_tod_utils.H
// *!
// *! DESCRIPTION : Header for proc_tod_utils.C
// *!
// *! OWNER NAME  : Nick Klazynski  Email: jklazyns@us.ibm.com
// *! BACKUP NAME :                 Email:
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------

#ifndef PROC_TOD_UTILS_H_
#define PROC_TOD_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>
#include <list>   // Required by firmware for std::list use

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// TOD-grid-cycles added to MDMT delay to account for slave staging
const uint32_t MDMT_TOD_GRID_CYCLE_STAGING_DELAY = 6;

// Duration of TOD GRID cycle in picoseconds
const uint32_t  TOD_GRID_PS = 400;

// Minimum/Maximum allowable delay for any node
const uint32_t  MIN_TOD_DELAY = 0;
const uint32_t  MAX_TOD_DELAY = 0xFF;

// TOD operation delay times for HW/sim
const uint32_t PROC_TOD_UTILS_HW_NS_DELAY     = 50000;
const uint32_t PROC_TOD_UTILS_SIM_CYCLE_DELAY = 50000;

// TOD retry count for hardware-cleared bits
const uint32_t PROC_TOD_UTIL_TIMEOUT_COUNT   = 20;

// HANG_PULSE_4_REG is needed for TB[60:63]
const uint32_t HANG_PULSE_4_REG_VAL     = 0;
const uint32_t HANG_PULSE_4_REG_VAL_LEN = 6;

//Bit definitions for SPRC_REG
const uint32_t SPRC_REG_SEL         = 52;
const uint32_t SPRC_REG_SEL_LEN     = 9;
const uint32_t SPRC_REG_SEL_TFMR_T0 = 0;

//Bit definitions for SPR_MODE_REG
const uint32_t SPR_MODE_REG_MODE_SPRC_WR_EN  = 3;
const uint32_t SPR_MODE_REG_MODE_SPRC0_SEL   = 16;
const uint32_t SPR_MODE_REG_MODE_SPRC_T0_SEL = 20;

//Bit definitions for TOD_M_PATH_CTRL_REG
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_0_OSC_NOT_VALID             = 0;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_1_OSC_NOT_VALID             = 1;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_0_STEP_ALIGN_DIS            = 2;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_1_STEP_ALIGN_DIS            = 3;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_0_SYNC_FREQ_SEL             = 4;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_1_SYNC_FREQ_SEL             = 6;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_0_STEP_CHECK_CPS_DEVIATION  = 8;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_0_STEP_CHECK_VALIDITY_COUNT = 13;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_1_STEP_CHECK_CPS_DEVIATION  = 16;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_1_STEP_CHECK_VALIDITY_COUNT = 21;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_STEP_CHECK_DEVIATION_FACTOR = 24;

const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_SYNC_FREQ_SEL_LEN           = 2;

const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_SYNC_FREQ_SEL_512           = 0;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_SYNC_FREQ_SEL_2048          = 1;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_SYNC_FREQ_SEL_1024          = 2;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_SYNC_FREQ_SEL_256           = 3;

//Bit definitions for TOD_I_PATH_CTRL_REG
const uint32_t TOD_I_PATH_CTRL_REG_DELAY_DIS                        = 0;
const uint32_t TOD_I_PATH_CTRL_REG_DELAY_ADJUST_DIS                 = 1;
const uint32_t TOD_I_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR  = 6;
const uint32_t TOD_I_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION         = 8;
const uint32_t TOD_I_PATH_CTRL_REG_STEP_CHECK_VALIDITY_COUNT        = 13;

//Bit definitions for TOD_START_TOD_REG
const uint32_t TOD_START_TOD_REG_FSM_START_TOD_TRIGGER = 0; // Write-only
const uint32_t TOD_START_TOD_REG_FSM_START_TOD_DATA02  = 2; // Write-only

//Bit definitions for TOD_LOAD_TOD_REG
const uint32_t TOD_LOAD_TOD_REG_LOAD_TOD_VAL     = 0;
const uint32_t TOD_LOAD_TOD_REG_WOF              = 60;

const uint32_t TOD_LOAD_TOD_REG_LOAD_TOD_VAL_LEN = 60;
const uint32_t TOD_LOAD_TOD_REG_WOF_LEN          = 4;

//Bit definitions for TOD_VALUE_REG
const uint32_t TOD_VALUE_REG_TOD_VAL             = 0;
const uint32_t TOD_VALUE_REG_WOF_COUNTER_VAL     = 60;

const uint32_t TOD_VALUE_REG_TOD_VAL_LEN         = 60;
const uint32_t TOD_VALUE_REG_WOF_COUNTER_VAL_LEN = 4;

//Bit definitions for TOD_LOAD_TOD_MOD_REG
const uint32_t TOD_LOAD_TOD_MOD_REG_FSM_LOAD_TOD_MOD_TRIG = 0; //Write-only

//Bit definitions for TOD_TX_TTYPE_CTRL_REG
const uint32_t TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_MST_ADDR_CFG     = 24;
const uint32_t TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_MST_ADDR_CFG_C5  = 0x15;
const uint32_t TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_MST_ADDR_CFG_LEN = 8;

//Bit definitions for TOD_CHIP_CTRL_REG
const uint32_t TOD_CHIP_CTRL_REG_TIMEBASE_EN                    = 0;
const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL    = 1;
const uint32_t TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DIS          = 4;
const uint32_t TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DIS = 5;
const uint32_t TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_EN   = 7;
const uint32_t TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM          = 8;
const uint32_t TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC               = 9;
const uint32_t TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VAL             = 10;
const uint32_t TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET      = 26;
const uint32_t TOD_CHIP_CTRL_REG_XSTOP_GATE                     = 30;
const uint32_t TOD_CHIP_CTRL_STICKY_ERROR_INJECT_EN             = 31;

const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_LEN  = 3;
const uint32_t TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VAL_LEN = 6;

const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_8   = 0;
const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_4   = 1;
const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_2   = 2;
const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_1   = 3;
const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_128 = 4;
const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_64  = 5;
const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_32  = 6;
const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_16  = 7;

const uint32_t TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VAL_1   = 0x1;
const uint32_t TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VAL_2   = 0x2;
const uint32_t TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VAL_3   = 0x3;
const uint32_t TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VAL_4   = 0x4;
const uint32_t TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VAL_3F  = 0x3F;

//Bit definitions for TOD_FSM_REG
const uint32_t TOD_FSM_REG_I_FSM_STATE      = 0;
const uint32_t TOD_FSM_REG_TOD_IS_RUNNING   = 4;

const uint32_t TOD_FSM_REG_I_FSM_STATE_LEN   = 4;

const uint32_t TOD_FSM_REG_I_FSM_STATE_ERROR         = 0x0;
const uint32_t TOD_FSM_REG_I_FSM_STATE_NOT_SET       = 0x7;
const uint32_t TOD_FSM_REG_I_FSM_STATE_STOPPED       = 0x1;
const uint32_t TOD_FSM_REG_I_FSM_STATE_WAIT_FOR_SYNC = 0xD;
const uint32_t TOD_FSM_REG_I_FSM_STATE_RUNNING_2     = 0x2;
const uint32_t TOD_FSM_REG_I_FSM_STATE_RUNNING_A     = 0xA;
const uint32_t TOD_FSM_REG_I_FSM_STATE_RUNNING_E     = 0xE;

//Bit definitions for TOD_PSS_MSS_CTRL_REG
const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SEL                             = 0;
const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SEL                            = 1;
const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SEL                         = 2;
const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_S_PATH1_STEP_CHECK_EN                  = 3;
const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_M_PATH0_STEP_CHECK_EN                  = 4;
const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_M_PATH1_STEP_CHECK_EN                  = 5;
const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_S_PATH0_STEP_CHECK_EN                  = 6;
const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_EN                   = 7;
const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SEL                             = 8;
const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SEL                            = 9;
const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SEL                         = 10;
const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_S_PATH1_STEP_CHECK_EN                  = 11;
const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_M_PATH0_STEP_CHECK_EN                  = 12;
const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_M_PATH1_STEP_CHECK_EN                  = 13;
const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_S_PATH0_STEP_CHECK_EN                  = 14;
const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_EN                   = 15;
const uint32_t TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERR_DISABLE                = 16;
const uint32_t TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE  = 17;
const uint32_t TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKENSWITCH            = 18;
const uint32_t TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD                   = 21;

//Bit definitions for TOD_S_PATH_CTRL_REG
const uint32_t TOD_S_PATH_CTRL_REG_PRI_S_PATH_SEL                         = 0;
const uint32_t TOD_S_PATH_CTRL_REG_SEC_S_PATH_SEL                         = 4;
const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR = 6;
const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION      = 8;
const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT     = 13;
const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION      = 16;
const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT     = 21;

const uint32_t STEP_CHECK_CPS_DEVIATION_FACTOR_LEN = 2;
const uint32_t STEP_CHECK_CPS_DEVIATION_FACTOR_1 = 0;
const uint32_t STEP_CHECK_CPS_DEVIATION_FACTOR_2 = 1;
const uint32_t STEP_CHECK_CPS_DEVIATION_FACTOR_4 = 2;
const uint32_t STEP_CHECK_CPS_DEVIATION_FACTOR_8 = 3;

const uint32_t STEP_CHECK_CPS_DEVIATION_LEN         = 4;
const uint32_t STEP_CHECK_CPS_DEVIATION_00_00_PCENT = 0x0;
const uint32_t STEP_CHECK_CPS_DEVIATION_06_25_PCENT = 0x1;
const uint32_t STEP_CHECK_CPS_DEVIATION_12_50_PCENT = 0x2;
const uint32_t STEP_CHECK_CPS_DEVIATION_18_75_PCENT = 0x3;
const uint32_t STEP_CHECK_CPS_DEVIATION_25_00_PCENT = 0x4;
const uint32_t STEP_CHECK_CPS_DEVIATION_31_25_PCENT = 0x5;
const uint32_t STEP_CHECK_CPS_DEVIATION_37_50_PCENT = 0x6;
const uint32_t STEP_CHECK_CPS_DEVIATION_43_75_PCENT = 0x7;
const uint32_t STEP_CHECK_CPS_DEVIATION_50_00_PCENT = 0x8;
const uint32_t STEP_CHECK_CPS_DEVIATION_56_25_PCENT = 0x9;
const uint32_t STEP_CHECK_CPS_DEVIATION_62_50_PCENT = 0xA;
const uint32_t STEP_CHECK_CPS_DEVIATION_68_75_PCENT = 0xB;
const uint32_t STEP_CHECK_CPS_DEVIATION_75_00_PCENT = 0xC;
const uint32_t STEP_CHECK_CPS_DEVIATION_81_25_PCENT = 0xD;
const uint32_t STEP_CHECK_CPS_DEVIATION_87_50_PCENT = 0xE;
const uint32_t STEP_CHECK_CPS_DEVIATION_93_75_PCENT = 0xF;

const uint32_t STEP_CHECK_VALIDITY_COUNT_LEN = 3;
const uint32_t STEP_CHECK_VALIDITY_COUNT_1   = 0;
const uint32_t STEP_CHECK_VALIDITY_COUNT_2   = 1;
const uint32_t STEP_CHECK_VALIDITY_COUNT_4   = 2;
const uint32_t STEP_CHECK_VALIDITY_COUNT_8   = 3;
const uint32_t STEP_CHECK_VALIDITY_COUNT_16  = 4;
const uint32_t STEP_CHECK_VALIDITY_COUNT_32  = 5;
const uint32_t STEP_CHECK_VALIDITY_COUNT_64  = 6;
const uint32_t STEP_CHECK_VALIDITY_COUNT_128 = 7;

//Bit definitions for TOD_{PRI,SEC}_PORT_{0,1}_CTRL_REG (40001, 40002, 40003, 40004)
const uint32_t TOD_PORT_CTRL_REG_RX            = 0;
const uint32_t TOD_PORT_CTRL_REG_TX_A0         = 4;
const uint32_t TOD_PORT_CTRL_REG_TX_A1         = 6;
const uint32_t TOD_PORT_CTRL_REG_TX_A2         = 8;
const uint32_t TOD_PORT_CTRL_REG_TX_X0         = 10;
const uint32_t TOD_PORT_CTRL_REG_TX_X1         = 12;
const uint32_t TOD_PORT_CTRL_REG_TX_X2         = 14;
const uint32_t TOD_PORT_CTRL_REG_TX_X3         = 16;
const uint32_t TOD_PORT_CTRL_REG_TX_X4         = 18;
const uint32_t TOD_PORT_CTRL_REG_TX_A0_EN      = 20; // 0->Receiver 1->Sender
const uint32_t TOD_PORT_CTRL_REG_TX_A1_EN      = 21; // 0->Receiver 1->Sender
const uint32_t TOD_PORT_CTRL_REG_TX_A2_EN      = 22; // 0->Receiver 1->Sender
const uint32_t TOD_PORT_CTRL_REG_TX_X0_EN      = 23; // 0->Receiver 1->Sender
const uint32_t TOD_PORT_CTRL_REG_TX_X1_EN      = 24; // 0->Receiver 1->Sender
const uint32_t TOD_PORT_CTRL_REG_TX_X2_EN      = 25; // 0->Receiver 1->Sender
const uint32_t TOD_PORT_CTRL_REG_TX_X3_EN      = 26; // 0->Receiver 1->Sender
const uint32_t TOD_PORT_CTRL_REG_TX_X4_EN      = 27; // 0->Receiver 1->Sender
const uint32_t TOD_PORT_CTRL_REG_I_PATH_DELAY  = 32; // 40001 40003 (port 0) setting only!

const uint32_t TOD_PORT_CTRL_REG_RX_LEN            = 3;
const uint32_t TOD_PORT_CTRL_REG_TX_LEN            = 2;
const uint32_t TOD_PORT_CTRL_REG_I_PATH_DELAY_LEN  = 8;

const uint32_t TOD_PORT_CTRL_REG_RX_A0_SEL = 0x0;
const uint32_t TOD_PORT_CTRL_REG_RX_A1_SEL = 0x1;
const uint32_t TOD_PORT_CTRL_REG_RX_A2_SEL = 0x2;
const uint32_t TOD_PORT_CTRL_REG_RX_X0_SEL = 0x3;
const uint32_t TOD_PORT_CTRL_REG_RX_X1_SEL = 0x4;
const uint32_t TOD_PORT_CTRL_REG_RX_X2_SEL = 0x5;
const uint32_t TOD_PORT_CTRL_REG_RX_X3_SEL = 0x6;
const uint32_t TOD_PORT_CTRL_REG_RX_X4_SEL = 0x7;

const uint32_t TOD_PORT_CTRL_REG_S_PATH_0 = 0x0;
const uint32_t TOD_PORT_CTRL_REG_S_PATH_1 = 0x1;
const uint32_t TOD_PORT_CTRL_REG_M_PATH_0 = 0x2;
const uint32_t TOD_PORT_CTRL_REG_M_PATH_1 = 0x3;

//Bit definitions for PB_X_MODE_0x04010C0A
const uint32_t PB_X_MODE_LINK_X0_ROUND_TRIP_DELAY = 24;
const uint32_t PB_X_MODE_LINK_X1_ROUND_TRIP_DELAY = 32;
const uint32_t PB_X_MODE_LINK_X2_ROUND_TRIP_DELAY = 40;
const uint32_t PB_X_MODE_LINK_X3_ROUND_TRIP_DELAY = 48;

//Bit definitions for PB_A_MODE_0x0801080A
const uint32_t PB_A_MODE_LINK_A0_ROUND_TRIP_DELAY = 40;
const uint32_t PB_A_MODE_LINK_A1_ROUND_TRIP_DELAY = 48;
const uint32_t PB_A_MODE_LINK_A2_ROUND_TRIP_DELAY = 56;

const uint32_t LINK_ROUND_TRIP_DELAY_LEN = 8;

//Bit definitions for TOD_ERROR_REG
const uint32_t TOD_ERROR_REG_RX_TTYPE_0      = 38;
const uint32_t TOD_ERROR_REG_RX_TTYPE_1      = 39;
const uint32_t TOD_ERROR_REG_RX_TTYPE_2      = 40;
const uint32_t TOD_ERROR_REG_RX_TTYPE_3      = 41;
const uint32_t TOD_ERROR_REG_RX_TTYPE_4      = 42;
const uint32_t TOD_ERROR_REG_RX_TTYPE_5      = 43;

//Bit definitions for TFMR
const uint32_t TFMR_MAX_CYC_BET_STEPS       = 0;
const uint32_t TFMR_N_CLKS_PER_STEP         = 8;
const uint32_t TFMR_MASK_HMI                = 10;
const uint32_t TFMR_SYNC_BIT_SEL            = 11;
const uint32_t TFMR_TB_ECLIPZ               = 14;
const uint32_t TFMR_LOAD_TOD_MOD            = 16;
const uint32_t TFMR_MOVE_CHIP_TOD_TO_TB     = 18;
const uint32_t TFMR_CLEAR_TB_ERRORS         = 24;
const uint32_t TFMR_HDEC_PARITY_ERROR       = 26;
const uint32_t TFMR_TBST_CORRUPT            = 27;
const uint32_t TFMR_TBST_ENCODED            = 28;
const uint32_t TFMR_TBST_LAST               = 32;
const uint32_t TFMR_TB_ENABLED              = 40;
const uint32_t TFMR_TB_VALID                = 41;
const uint32_t TFMR_TB_SYNC_OCCURED         = 42;
const uint32_t TFMR_TB_MISSING_SYNC         = 43;
const uint32_t TFMR_TB_MISSING_STEP         = 44;
const uint32_t TFMR_TB_RESIDUE_ERR          = 45;
const uint32_t TFMR_FIRMWARE_CONTROL_ERROR  = 46;
const uint32_t TFMR_CHIP_TOD_STATUS         = 47;
const uint32_t TFMR_CHIP_TOD_INTERRUPT      = 51;
const uint32_t TFMR_CHIP_TOD_PARITY_ERROR   = 56;
const uint32_t TFMR_TX_PURR_PARITY_ERROR    = 57;
const uint32_t TFMR_TX_SPURR_PARITY_ERROR   = 58;
const uint32_t TFMR_TX_DEC_PARITY_ERROR     = 59;
const uint32_t TFMR_TX_TFMR_CORRUPT         = 60;
const uint32_t TFMR_TX_PURR_OVERFLOW_ERROR  = 61;
const uint32_t TFMR_TX_SPURR_OVERFLOW_ERROR = 62;

const uint32_t TFMR_MAX_CYC_BET_STEPS_LEN = 8;
const uint32_t TFMR_N_CLKS_PER_STEP_LEN   = 2;
const uint32_t TFMR_SYNC_BIT_SEL_LEN      = 3;
const uint32_t TFMR_TBST_ENCODED_LEN      = 4;
const uint32_t TFMR_TBST_LAST_LEN         = 4;
const uint32_t TFMR_CHIP_TOD_STATUS_LEN   = 4;

const uint32_t TFMR_N_CLKS_PER_STEP_1CLK  = 0;
const uint32_t TFMR_N_CLKS_PER_STEP_2CLK  = 1;
const uint32_t TFMR_N_CLKS_PER_STEP_3CLK  = 2;
const uint32_t TFMR_N_CLKS_PER_STEP_4CLK  = 3;

const uint32_t TFMR_SYNC_BIT_SEL_1US  = 0;
const uint32_t TFMR_SYNC_BIT_SEL_2US  = 1;
const uint32_t TFMR_SYNC_BIT_SEL_4US  = 2;
const uint32_t TFMR_SYNC_BIT_SEL_8US  = 3;
const uint32_t TFMR_SYNC_BIT_SEL_16US = 4;
const uint32_t TFMR_SYNC_BIT_SEL_32US = 5;
const uint32_t TFMR_SYNC_BIT_SEL_64US = 6;

// For TFMR_TBST_ENCODED and TFMR_TBST_LAST
const uint32_t TFMR_TBST_ENCODED_TB_RESET        = 0;
const uint32_t TFMR_TBST_ENCODED_TB_SEND_TOD_MOD = 1;
const uint32_t TFMR_TBST_ENCODED_TB_NOT_SET      = 2;
const uint32_t TFMR_TBST_ENCODED_TB_SYNC_WAIT    = 6;
const uint32_t TFMR_TBST_ENCODED_TB_GET_TOD      = 7;
const uint32_t TFMR_TBST_ENCODED_TB_RUNNING      = 8;
const uint32_t TFMR_TBST_ENCODED_TB_ERROR        = 9;

const uint32_t NUM_A_BUSES = 3;
const uint32_t NUM_X_BUSES = 5;

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

extern "C"
{

// Used by wrapper to determine which FAPI procedure to call
enum tod_action
{
    TOD_SETUP,
    TOD_INIT,
    TOD_STATUS
};

// Input which determines the topology being configured
enum proc_tod_setup_tod_sel
{
    TOD_PRIMARY,      // configure primary TOD
    TOD_SECONDARY     // configure secondary TOD
};

// Input which determines the master oscillator to use
enum proc_tod_setup_osc_sel
{
    TOD_OSC_0,      // oscillator connected to OSC0 and not OSC1
    TOD_OSC_1,      // oscillator connected to OSC1 and not OSC0
    TOD_OSC_0_AND_1 // oscillators connected to both OSC0 and OSC1

};

// Defines the upstream connection for the given node
enum proc_tod_setup_bus
{
    NONE,  // MDMT has no bus_in
    XBUS0,
    XBUS1,
    XBUS2,
    XBUS3,
    ABUS0,
    ABUS1,
    ABUS2
};

// Saves the final configuration (register values) for each node
// Port 0 will always be used for Primary, 1 will always be used for Secondary
struct proc_tod_setup_conf_regs
{
    ecmdDataBufferBase tod_m_path_ctrl_reg;
    ecmdDataBufferBase tod_pri_port_0_ctrl_reg;
    ecmdDataBufferBase tod_pri_port_1_ctrl_reg;
    ecmdDataBufferBase tod_sec_port_0_ctrl_reg;
    ecmdDataBufferBase tod_sec_port_1_ctrl_reg;
    ecmdDataBufferBase tod_s_path_ctrl_reg;
    ecmdDataBufferBase tod_i_path_ctrl_reg;
    ecmdDataBufferBase tod_pss_mss_ctrl_reg;
    ecmdDataBufferBase tod_chip_ctrl_reg;
};

// i_bus_rx and i_bus_tx can differ, based on system configuration (see *'d lines)
// Example (croquery eiinfo)
//                Drive Chip,     Drive Port,              Bus,   Receive Port,            Receive Chip, Depth, Bus Flags,  Group Id
//   s1.xbus:k0:n0:s0:p00:c1,     PRT_EI4_X1,        BUS_EI4_X,     PRT_EI4_X1, s1.xbus:k0:n0:s0:p01:c1,    00, 0x80000000, 0000
//   s1.xbus:k0:n0:s0:p01:c1,     PRT_EI4_X1,        BUS_EI4_X,     PRT_EI4_X1, s1.xbus:k0:n0:s0:p00:c1,    10, 0x80000000, 0001
//   s1.xbus:k0:n2:s0:p00:c1,     PRT_EI4_X1,        BUS_EI4_X,     PRT_EI4_X1, s1.xbus:k0:n2:s0:p01:c1,    00, 0x80000000, 0200
//   s1.xbus:k0:n2:s0:p01:c1,     PRT_EI4_X1,        BUS_EI4_X,     PRT_EI4_X1, s1.xbus:k0:n2:s0:p00:c1,    10, 0x80000000, 0201
// * s1.abus:k0:n0:s0:p00:c1,     PRT_EDI_A1,        BUS_EDI_A,     PRT_EDI_A0, s1.abus:k0:n2:s0:p00:c0,    00, 0x80000000, 0000
// * s1.abus:k0:n2:s0:p00:c0,     PRT_EDI_A0,        BUS_EDI_A,     PRT_EDI_A1, s1.abus:k0:n0:s0:p00:c1,    10, 0x80000000, 0200
// * s1.abus:k0:n0:s0:p01:c1,     PRT_EDI_A1,        BUS_EDI_A,     PRT_EDI_A0, s1.abus:k0:n2:s0:p01:c0,    00, 0x80000000, 0001
// * s1.abus:k0:n2:s0:p01:c0,     PRT_EDI_A0,        BUS_EDI_A,     PRT_EDI_A1, s1.abus:k0:n0:s0:p01:c1,    10, 0x80000000, 0201

// TOD Topology node definition
struct tod_topology_node
{
    fapi::Target* i_target;
    bool i_tod_master;
    bool i_drawer_master;
    proc_tod_setup_bus i_bus_rx;              // Current node's bus from which step/sync is received ("Receive Port" in eiinfo)
    proc_tod_setup_bus i_bus_tx;              // Upstream node's bus from which step/sync is transmitted ("Drive Port" in eiinfo)
    std::list<tod_topology_node*> i_children;
    proc_tod_setup_conf_regs o_todRegs;
    uint32_t o_int_path_delay;
};

// no function pointer; direct access not needed

/**
 * @brief Retrieves TFMR using indirect SPRC/SPRD method
 *
 * @param[in]  i_target     => chip target
 *
 * @param[out] o_tfmr_val   => TFMR value read
 *
 * @return FAPI_RC_SUCCESS if TFMR read is successful
 *         else FAPI or ECMD error is sent through
 */
fapi::ReturnCode proc_tod_utils_get_tfmr_reg(
    const fapi::Target& i_target,
    ecmdDataBufferBase& o_tfmr_val);

/**
 * @brief Sets TFMR using indirect SPRC/SPRD method
 *
 * @param[in]  i_target     => chip target
 *             i_tfmr_val   => TFMR value to write
 *
 * @return FAPI_RC_SUCCESS if TFMR write is successful
 *         else FAPI or ECMD error is sent through
 */
fapi::ReturnCode proc_tod_utils_set_tfmr_reg(
    const fapi::Target& i_target,
    ecmdDataBufferBase& i_tfmr_val);

} // extern "C"

#endif // PROC_TOD_UTILS_H_
