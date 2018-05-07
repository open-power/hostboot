/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/common/include/p9a_obus_scom_addresses_fld.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
///
/// @file p9a_obus_scom_addresses_fld.H
/// @brief  Defines constants for scom addresses
///
// *HWP HWP Owner: Ben Gass <bgass@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: SOA
// *HWP Level: 1
// *HWP Consumed by: FSP:HB:HS:OCC:SBE:CME:SGPE:PGPE:FPPE:IPPE


#ifndef __P9A_OBUS_SCOM_ADDRESSES_FLD_H
#define __P9A_OBUS_SCOM_ADDRESSES_FLD_H



static const uint8_t P9A_OBUS_CSAR_SRAM_ADDRESS                              = 16  ;
static const uint8_t P9A_OBUS_CSAR_SRAM_ADDRESS_LEN                          = 13  ;

static const uint8_t P9A_OBUS_CSCR_SRAM_ACCESS_MODE                          = 0   ;
static const uint8_t P9A_OBUS_CSCR_SRAM_SCRUB_ENABLE                         = 1   ;
static const uint8_t P9A_OBUS_CSCR_ECC_CORRECT_DIS                           = 2   ;
static const uint8_t P9A_OBUS_CSCR_ECC_DETECT_DIS                            = 3   ;
static const uint8_t P9A_OBUS_CSCR_ECC_INJECT_TYPE                           = 4   ;
static const uint8_t P9A_OBUS_CSCR_ECC_INJECT_ERR                            = 5   ;
static const uint8_t P9A_OBUS_CSCR_SPARE_6_7                                 = 6   ;
static const uint8_t P9A_OBUS_CSCR_SPARE_6_7_LEN                             = 2   ;
static const uint8_t P9A_OBUS_CSCR_SRAM_SCRUB_INDEX                          = 47  ;
static const uint8_t P9A_OBUS_CSCR_SRAM_SCRUB_INDEX_LEN                      = 13  ;

static const uint8_t P9A_OBUS_CSDR_SRAM_DATA                                 = 0   ;
static const uint8_t P9A_OBUS_CSDR_SRAM_DATA_LEN                             = 64  ;

static const uint8_t P9A_OBUS_FIR_ACTION0_REG_ACTION0                        = 0   ;
static const uint8_t P9A_OBUS_FIR_ACTION0_REG_ACTION0_LEN                    = 50  ;

static const uint8_t P9A_OBUS_FIR_ACTION1_REG_ACTION1                        = 0   ;
static const uint8_t P9A_OBUS_FIR_ACTION1_REG_ACTION1_LEN                    = 50  ;

static const uint8_t P9A_OBUS_FIR_MASK_REG_RX_INVALID_STATE_OR_PARITY_ERROR  = 0   ;
static const uint8_t P9A_OBUS_FIR_MASK_REG_TX_INVALID_STATE_OR_PARITY_ERROR  = 1   ;
static const uint8_t P9A_OBUS_FIR_MASK_REG_GCR_HANG_ERROR                    = 2   ;
static const uint8_t P9A_OBUS_FIR_MASK_REG_UNUSED                            = 3   ;
static const uint8_t P9A_OBUS_FIR_MASK_REG_UNUSED_LEN                        = 45  ;
static const uint8_t P9A_OBUS_FIR_MASK_REG_INTERNAL_SCOM_ERROR               = 48  ;
static const uint8_t P9A_OBUS_FIR_MASK_REG_INTERNAL_SCOM_ERROR_CLONE         = 49  ;

static const uint8_t P9A_OBUS_FIR_REG_RX_INVALID_STATE_OR_PARITY_ERROR       = 0   ;
static const uint8_t P9A_OBUS_FIR_REG_TX_INVALID_STATE_OR_PARITY_ERROR       = 1   ;
static const uint8_t P9A_OBUS_FIR_REG_GCR_HANG_ERROR                         = 2   ;
static const uint8_t P9A_OBUS_FIR_REG_UNUSED                                 = 3   ;
static const uint8_t P9A_OBUS_FIR_REG_UNUSED_LEN                             = 45  ;
static const uint8_t P9A_OBUS_FIR_REG_SCOMFIR_ERROR                          = 48  ;
static const uint8_t P9A_OBUS_FIR_REG_SCOMFIR_ERROR_CLONE                    = 49  ;

static const uint8_t P9A_OBUS_FIR_WOF_REG_WOF                                = 0   ;
static const uint8_t P9A_OBUS_FIR_WOF_REG_WOF_LEN                            = 50  ;

static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_LINK_PAIR                      = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_DISABLE_SL_ECC                 = 1   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_CRC_LANE_ID                    = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_EDPL_LANE_ID                   = 3   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_SL_UE_CRC_ERR                  = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_REPORT_SL_CHKBIT_ERR           = 5   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_BW_SAMPLE_SIZE                 = 6   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_BW_WINDOW_SIZE                 = 7   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_UNUSED1                        = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_UNUSED1_LEN                    = 3   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_PACKET_DELAY_LIMIT             = 11  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_PACKET_DELAY_LIMIT_LEN         = 5   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_TDM_DELAY                      = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_TDM_DELAY_LEN                  = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_AUTO_TDM_TX                    = 20  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_AUTO_TDM_RX                    = 21  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_AUTO_TDM_AND_NOT_OR            = 22  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_UNUSED2                        = 23  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_AUTO_TDM_BW_DIFF               = 24  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_AUTO_TDM_BW_DIFF_LEN           = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_AUTO_TDM_ERROR_RATE            = 28  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_AUTO_TDM_ERROR_RATE_LEN        = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_AUTO_TDM_EXIT_RATE             = 32  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_AUTO_TDM_EXIT_RATE_LEN         = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_UNUSED3                        = 36  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_UNUSED3_LEN                    = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_TIMEOUT                        = 48  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_TIMEOUT_LEN                    = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_TIMER_1US                      = 52  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONFIG_TIMER_1US_LEN                  = 12  ;

static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK0_PHY_TRAINING            = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK0_STARTUP                 = 1   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK0_HOLD_PATT_A             = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK0_HOLD_PATT_B             = 3   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK0_RUN_LANE_DISABLE        = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK0_RUN_LANE_OVERRIDE       = 5   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK0_IGNORE_PHY              = 6   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK0_IGNORE_FENCE            = 7   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK0_ERR_INJ_COMMAND         = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK0_ERR_INJ_COMMAND_LEN     = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK0_ERR_INJ_COMMAND_LANES   = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK0_ERR_INJ_COMMAND_LANES_LEN = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_UNUSED0                       = 24  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_UNUSED0_LEN                   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK0_COMMAND                 = 28  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK0_COMMAND_LEN             = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK1_PHY_TRAINING            = 32  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK1_STARTUP                 = 33  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK1_HOLD_PATT_A             = 34  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK1_HOLD_PATT_B             = 35  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK1_RUN_LANE_DISABLE        = 36  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK1_RUN_LANE_OVERRIDE       = 37  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK1_IGNORE_PHY              = 38  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK1_IGNORE_FENCE            = 39  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK1_ERR_INJ_COMMAND         = 40  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK1_ERR_INJ_COMMAND_LEN     = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK1_ERR_INJ_COMMAND_LANES   = 44  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK1_ERR_INJ_COMMAND_LANES_LEN = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_UNUSED1                       = 56  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_UNUSED1_LEN                   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK1_COMMAND                 = 60  ;
static const uint8_t P9A_OBUS_LL0_IOOL_CONTROL_LINK1_COMMAND_LEN             = 4   ;

static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK0_CURRENT_STATE        = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK0_CURRENT_STATE_LEN    = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK0_PRIOR_STATE          = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK0_PRIOR_STATE_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK0_OPTICS_RST_B         = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK0_OPTICS_IRQ           = 17  ;
static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK0_TRAINING             = 18  ;
static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK0_MAX_PKT_TIMER        = 19  ;
static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK0_MAX_PKT_TIMER_LEN    = 5   ;
static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK1_CURRENT_STATE        = 28  ;
static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK1_CURRENT_STATE_LEN    = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK1_PRIOR_STATE          = 36  ;
static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK1_PRIOR_STATE_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK1_OPTICS_RST_B         = 40  ;
static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK1_OPTICS_IRQ           = 41  ;
static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK1_TRAINING             = 42  ;
static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK1_MAX_PKT_TIMER        = 43  ;
static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK1_MAX_PKT_TIMER_LEN    = 5   ;
static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK0_LINK_CAP_VALID       = 62  ;
static const uint8_t P9A_OBUS_LL0_IOOL_DLL_STATUS_LINK1_LINK_CAP_VALID       = 63  ;

static const uint8_t P9A_OBUS_LL0_IOOL_ERR_INJ_LFSR_LFSR                     = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_ERR_INJ_LFSR_LFSR_LEN                 = 61  ;

static const uint8_t P9A_OBUS_LL0_IOOL_FIR_WOF_REG_WOF                       = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_FIR_WOF_REG_WOF_LEN                   = 64  ;

static const uint8_t P9A_OBUS_LL0_IOOL_LAT_MEASURE_LINK0_ROUND_TRIP_VALID    = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LAT_MEASURE_LINK0_ROUND_TRIP          = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LAT_MEASURE_LINK0_ROUND_TRIP_LEN      = 10  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LAT_MEASURE_LINK1_ROUND_TRIP_VALID    = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LAT_MEASURE_LINK1_ROUND_TRIP          = 14  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LAT_MEASURE_LINK1_ROUND_TRIP_LEN      = 10  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID = 24  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK = 25  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE  = 29  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_LEN = 7   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID = 36  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK = 37  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE = 41  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_LEN = 7   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LAT_MEASURE_LINK0_TOD_LATENCY         = 49  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LAT_MEASURE_LINK0_TOD_LATENCY_LEN     = 7   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LAT_MEASURE_LINK1_TOD_LATENCY         = 57  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LAT_MEASURE_LINK1_TOD_LATENCY_LEN     = 7   ;

static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_0       = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_0_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_1       = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_1_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_2       = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_2_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_3       = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_3_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_4       = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_4_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_5       = 20  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_5_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_6       = 24  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_6_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_7       = 28  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_7_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_8       = 32  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_8_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_9       = 36  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_9_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_10      = 40  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_10_LEN  = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_11      = 44  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_EDPL_STATUS_ERROR_COUNT_11_LEN  = 4   ;

static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_ERROR_STATUS_RESET_KEEPER       = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_ERROR_STATUS_CE                 = 1   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_ERROR_STATUS_CE_LEN             = 7   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_ERROR_STATUS_UE                 = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_ERROR_STATUS_UE_LEN             = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_ERROR_STATUS_OSC                = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_ERROR_STATUS_OSC_LEN            = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_ERROR_STATUS_TRAIN              = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_ERROR_STATUS_TRAIN_LEN          = 5   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_ERROR_STATUS_UNRECOV            = 24  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_ERROR_STATUS_UNRECOV_LEN        = 14  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_ERROR_STATUS_INTERNAL           = 40  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_ERROR_STATUS_INTERNAL_LEN       = 22  ;

static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_INFO_MAX_TIMEOUT                = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_INFO_MAX_TIMEOUT_LEN            = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_INFO_FRAME_CAP_VALID            = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_INFO_FRAME_CAP_INST             = 17  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_INFO_FRAME_CAP_ADDR             = 18  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_INFO_FRAME_CAP_ADDR_LEN         = 6   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_INFO_FRAME_CAP_SYN              = 24  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_INFO_FRAME_CAP_SYN_LEN          = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_INFO_REPLAY_CAP_VALID           = 32  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_INFO_REPLAY_CAP_INST            = 33  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_INFO_REPLAY_CAP_INST_LEN        = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_INFO_REPLAY_CAP_ADDR            = 35  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_INFO_REPLAY_CAP_ADDR_LEN        = 9   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_INFO_REPLAY_CAP_SYN             = 44  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_INFO_REPLAY_CAP_SYN_LEN         = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_INFO_ACK_FIFO_CAP_VALID         = 52  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_INFO_ACK_FIFO_CAP_ADDR          = 55  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_INFO_ACK_FIFO_CAP_ADDR_LEN      = 9   ;

static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_QUALITY_TX_BW                   = 1   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_QUALITY_TX_BW_LEN               = 11  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_QUALITY_RX_BW                   = 13  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_QUALITY_RX_BW_LEN               = 11  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_QUALITY_ERROR_RATE              = 25  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_QUALITY_ERROR_RATE_LEN          = 23  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_QUALITY_SPARE_COUNTER_1         = 49  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_QUALITY_SPARE_COUNTER_1_LEN     = 7   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_QUALITY_SPARE_COUNTER_2         = 57  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_QUALITY_SPARE_COUNTER_2_LEN     = 7   ;

static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_RX_LANE_CONTROL_DISABLED        = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_RX_LANE_CONTROL_DISABLED_LEN    = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_RX_LANE_CONTROL_BRINGUP         = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_RX_LANE_CONTROL_BRINGUP_LEN     = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_RX_LANE_CONTROL_SPARED          = 24  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_RX_LANE_CONTROL_SPARED_LEN      = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_RX_LANE_CONTROL_LOCKED          = 36  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_RX_LANE_CONTROL_LOCKED_LEN      = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_RX_LANE_CONTROL_FAILED          = 48  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_RX_LANE_CONTROL_FAILED_LEN      = 12  ;

static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_SYN_CAPTURE_LINK_CAP_CRC        = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_SYN_CAPTURE_LINK_CAP_CRC_LEN    = 36  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_SYN_CAPTURE_LINK_CAP_SLECC_SYN0 = 36  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_SYN_CAPTURE_LINK_CAP_SLECC_SYN0_LEN = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_SYN_CAPTURE_LINK_CAP_SLECC_SYN1 = 44  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_SYN_CAPTURE_LINK_CAP_SLECC_SYN1_LEN = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_SYN_CAPTURE_LINK_CAP_SLECC_SYN2 = 52  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_SYN_CAPTURE_LINK_CAP_SLECC_SYN2_LEN = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_SYN_CAPTURE_LINK_CAP_CRC_LANE   = 60  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_SYN_CAPTURE_LINK_CAP_CRC_LANE_LEN = 4   ;

static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE00          = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE00_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE01          = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE01_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE02          = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE02_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE03          = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE03_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE04          = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE04_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE05          = 20  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE05_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE06          = 24  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE06_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE07          = 28  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE07_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE08          = 32  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE08_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE09          = 36  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE09_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE10          = 40  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE10_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE11          = 44  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_LANE11_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_FAILED          = 48  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL_FAILED_LEN      = 12  ;

static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_0       = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_0_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_1       = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_1_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_2       = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_2_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_3       = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_3_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_4       = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_4_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_5       = 20  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_5_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_6       = 24  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_6_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_7       = 28  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_7_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_8       = 32  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_8_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_9       = 36  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_9_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_10      = 40  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_10_LEN  = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_11      = 44  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_EDPL_STATUS_ERROR_COUNT_11_LEN  = 4   ;

static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_ERROR_STATUS_RESET_KEEPER       = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_ERROR_STATUS_CE                 = 1   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_ERROR_STATUS_CE_LEN             = 7   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_ERROR_STATUS_UE                 = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_ERROR_STATUS_UE_LEN             = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_ERROR_STATUS_OSC                = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_ERROR_STATUS_OSC_LEN            = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_ERROR_STATUS_TRAIN              = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_ERROR_STATUS_TRAIN_LEN          = 5   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_ERROR_STATUS_UNRECOV            = 24  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_ERROR_STATUS_UNRECOV_LEN        = 14  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_ERROR_STATUS_INTERNAL           = 40  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_ERROR_STATUS_INTERNAL_LEN       = 22  ;

static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_INFO_MAX_TIMEOUT                = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_INFO_MAX_TIMEOUT_LEN            = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_INFO_FRAME_CAP_VALID            = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_INFO_FRAME_CAP_INST             = 17  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_INFO_FRAME_CAP_ADDR             = 18  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_INFO_FRAME_CAP_ADDR_LEN         = 6   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_INFO_FRAME_CAP_SYN              = 24  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_INFO_FRAME_CAP_SYN_LEN          = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_INFO_REPLAY_CAP_VALID           = 32  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_INFO_REPLAY_CAP_INST            = 33  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_INFO_REPLAY_CAP_INST_LEN        = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_INFO_REPLAY_CAP_ADDR            = 35  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_INFO_REPLAY_CAP_ADDR_LEN        = 9   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_INFO_REPLAY_CAP_SYN             = 44  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_INFO_REPLAY_CAP_SYN_LEN         = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_INFO_ACK_FIFO_CAP_VALID         = 52  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_INFO_ACK_FIFO_CAP_ADDR          = 55  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_INFO_ACK_FIFO_CAP_ADDR_LEN      = 9   ;

static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_QUALITY_TX_BW                   = 1   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_QUALITY_TX_BW_LEN               = 11  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_QUALITY_RX_BW                   = 13  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_QUALITY_RX_BW_LEN               = 11  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_QUALITY_ERROR_RATE              = 25  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_QUALITY_ERROR_RATE_LEN          = 23  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_QUALITY_SPARE_COUNTER_1         = 49  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_QUALITY_SPARE_COUNTER_1_LEN     = 7   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_QUALITY_SPARE_COUNTER_2         = 57  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_QUALITY_SPARE_COUNTER_2_LEN     = 7   ;

static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_RX_LANE_CONTROL_DISABLED        = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_RX_LANE_CONTROL_DISABLED_LEN    = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_RX_LANE_CONTROL_BRINGUP         = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_RX_LANE_CONTROL_BRINGUP_LEN     = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_RX_LANE_CONTROL_SPARED          = 24  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_RX_LANE_CONTROL_SPARED_LEN      = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_RX_LANE_CONTROL_LOCKED          = 36  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_RX_LANE_CONTROL_LOCKED_LEN      = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_RX_LANE_CONTROL_FAILED          = 48  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_RX_LANE_CONTROL_FAILED_LEN      = 12  ;

static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_SYN_CAPTURE_LINK_CAP_CRC        = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_SYN_CAPTURE_LINK_CAP_CRC_LEN    = 36  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_SYN_CAPTURE_LINK_CAP_SLECC_SYN0 = 36  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_SYN_CAPTURE_LINK_CAP_SLECC_SYN0_LEN = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_SYN_CAPTURE_LINK_CAP_SLECC_SYN1 = 44  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_SYN_CAPTURE_LINK_CAP_SLECC_SYN1_LEN = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_SYN_CAPTURE_LINK_CAP_SLECC_SYN2 = 52  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_SYN_CAPTURE_LINK_CAP_SLECC_SYN2_LEN = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_SYN_CAPTURE_LINK_CAP_CRC_LANE   = 60  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_SYN_CAPTURE_LINK_CAP_CRC_LANE_LEN = 4   ;

static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE00          = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE00_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE01          = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE01_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE02          = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE02_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE03          = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE03_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE04          = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE04_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE05          = 20  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE05_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE06          = 24  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE06_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE07          = 28  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE07_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE08          = 32  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE08_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE09          = 36  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE09_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE10          = 40  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE10_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE11          = 44  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_LANE11_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_FAILED          = 48  ;
static const uint8_t P9A_OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL_FAILED_LEN      = 12  ;

static const uint8_t P9A_OBUS_LL0_IOOL_MISC_ERROR_STATUS_RESET_KEEPER        = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_MISC_ERROR_STATUS_LINKX               = 1   ;
static const uint8_t P9A_OBUS_LL0_IOOL_MISC_ERROR_STATUS_LINKX_LEN           = 5   ;
static const uint8_t P9A_OBUS_LL0_IOOL_MISC_ERROR_STATUS_DLX0                = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_MISC_ERROR_STATUS_DLX0_LEN            = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_MISC_ERROR_STATUS_DLX1                = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_MISC_ERROR_STATUS_DLX1_LEN            = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_MISC_ERROR_STATUS_OLL                 = 24  ;
static const uint8_t P9A_OBUS_LL0_IOOL_MISC_ERROR_STATUS_OLL_LEN             = 18  ;
static const uint8_t P9A_OBUS_LL0_IOOL_MISC_ERROR_STATUS_ODL                 = 44  ;
static const uint8_t P9A_OBUS_LL0_IOOL_MISC_ERROR_STATUS_ODL_LEN             = 18  ;

static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_DISABLE_BAD_LANE_COUNT = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_DISABLE_CLEAR_BAD_LANE_COUNT = 1   ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_LINK_FAIL_NO_SPARE     = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_LINK_FAIL_CRC_ERROR    = 3   ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_BAD_LANE_DURATION      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_BAD_LANE_DURATION_LEN  = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_OPT_UNUSED2            = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_BAD_LANE_MAX           = 9   ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_BAD_LANE_MAX_LEN       = 7   ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_DISABLE_LINK_FAIL_COUNT = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_OPT_UNUSED3            = 17  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_OPT_UNUSED3_LEN        = 3   ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_LINK_FAIL_DURATION     = 20  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_LINK_FAIL_DURATION_LEN = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_OPT_UNUSED4            = 24  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_LINK_FAIL_MAX          = 25  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_LINK_FAIL_MAX_LEN      = 7   ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER = 32  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER = 33  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_OPT_UNUSED5            = 34  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_OPT_UNUSED5_LEN        = 3   ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_ELEVEN_LANE_MODE       = 37  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_LINK0_ELEVEN_LANE_SHIFT = 38  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_LINK1_ELEVEN_LANE_SHIFT = 39  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP     = 40  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP     = 41  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP     = 42  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP     = 43  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_ACK_QUEUE_LOW          = 44  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_ACK_QUEUE_LOW_LEN      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_ACK_QUEUE_START        = 48  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_ACK_QUEUE_START_LEN    = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_ACK_QUEUE_HIGH         = 52  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_ACK_QUEUE_HIGH_LEN     = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_REPLAY_BUFFER_SIZE     = 56  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_REPLAY_BUFFER_SIZE_LEN = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_OPT_UNUSED6            = 58  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_FAST_ASYNC_CROSS       = 59  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_RECAL_ABORT_TIMEOUT    = 60  ;
static const uint8_t P9A_OBUS_LL0_IOOL_OPTICAL_CONFIG_RECAL_ABORT_TIMEOUT_LEN = 4   ;

static const uint8_t P9A_OBUS_LL0_IOOL_PERF_COUNTERS_0_PERFMON_COUNTER       = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_COUNTERS_0_PERFMON_COUNTER_LEN   = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_COUNTERS_0_PERFMON_COUNTER_1     = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_COUNTERS_0_PERFMON_COUNTER_1_LEN = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_COUNTERS_0_PERFMON_COUNTER_2     = 32  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_COUNTERS_0_PERFMON_COUNTER_2_LEN = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_COUNTERS_0_PERFMON_COUNTER_3     = 48  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_COUNTERS_0_PERFMON_COUNTER_3_LEN = 16  ;

static const uint8_t P9A_OBUS_LL0_IOOL_PERF_COUNTERS_1_PERFMON_COUNTER_4     = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_COUNTERS_1_PERFMON_COUNTER_4_LEN = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_COUNTERS_1_PERFMON_COUNTER_5     = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_COUNTERS_1_PERFMON_COUNTER_5_LEN = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_COUNTERS_1_PERFMON_COUNTER_6     = 32  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_COUNTERS_1_PERFMON_COUNTER_6_LEN = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_COUNTERS_1_PERFMON_COUNTER_7     = 48  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_COUNTERS_1_PERFMON_COUNTER_7_LEN = 16  ;

static const uint8_t P9A_OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_0              = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_0_LEN          = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_1              = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_1_LEN          = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_2              = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_2_LEN          = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_3              = 24  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_3_LEN          = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_4              = 32  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_4_LEN          = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_5              = 40  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_5_LEN          = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_6              = 48  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_6_LEN          = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_7              = 56  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_7_LEN          = 8   ;

static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_0            = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_0_LEN        = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_1            = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_1_LEN        = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_2            = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_2_LEN        = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_3            = 6   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_3_LEN        = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_4            = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_4_LEN        = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_5            = 10  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_5_LEN        = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_6            = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_6_LEN        = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_7            = 14  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_7_LEN        = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_0              = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_0_LEN          = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_1              = 18  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_1_LEN          = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_2              = 20  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_2_LEN          = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_3              = 22  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_3_LEN          = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_4              = 24  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_4_LEN          = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_5              = 26  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_5_LEN          = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_6              = 28  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_6_LEN          = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_7              = 30  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_7_LEN          = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_PMULET_FREEZE_MODE  = 32  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_COMMON_FREEZE_MODE  = 33  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_RESET_MODE          = 34  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_PERFTRACE_ENABLE    = 35  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW = 36  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_PERFTRACE_PRESCALE  = 37  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_PERFTRACE_MODE      = 38  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_PERFTRACE_MODE_LEN  = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_CONFIG_0            = 40  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_CONFIG_0_LEN        = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_CONFIG_1            = 52  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PERF_TRACE_CONFIG_CONFIG_1_LEN        = 12  ;

static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_TRAIN_A_ADJ                = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_TRAIN_A_ADJ_LEN            = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_TRAIN_B_ADJ                = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_TRAIN_B_ADJ_LEN            = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_TRAIN_TIME                 = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_TRAIN_TIME_LEN             = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_TRAIN_A_HYST               = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_TRAIN_A_HYST_LEN           = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_TRAIN_B_HYST               = 12  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_TRAIN_B_HYST_LEN           = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_PRBS_PHASE_SELECT          = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_PRBS_PHASE_SELECT_LEN      = 24  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_PRBS                       = 40  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_PRBS_LEN                   = 10  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_PRBS_INVERT                = 50  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_UNUSED1                    = 51  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_ODL0_ENABLED               = 52  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_ODL1_ENABLED               = 53  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_ODL2_ENABLED               = 54  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_UNUSED2                    = 55  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_NV0_NPU_ENABLED            = 56  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_NV1_NPU_ENABLED            = 57  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_LINK0_OLL_ENABLED          = 58  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_LINK1_OLL_ENABLED          = 59  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_NV2_NPU_ENABLED            = 60  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_NV3_NPU_ENABLED            = 61  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_NV4_NPU_ENABLED            = 62  ;
static const uint8_t P9A_OBUS_LL0_IOOL_PHY_CONFIG_NV5_NPU_ENABLED            = 63  ;

static const uint8_t P9A_OBUS_LL0_IOOL_REPLAY_THRESHOLD_THRESH_TB_SEL        = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_REPLAY_THRESHOLD_THRESH_TB_SEL_LEN    = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_REPLAY_THRESHOLD_THRESH_TAP_SEL       = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_REPLAY_THRESHOLD_THRESH_TAP_SEL_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_REPLAY_THRESHOLD_THRESH_ENABLE        = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_REPLAY_THRESHOLD_THRESH_ENABLE_LEN    = 3   ;
static const uint8_t P9A_OBUS_LL0_IOOL_REPLAY_THRESHOLD_THRESH_UNUSED1       = 11  ;
static const uint8_t P9A_OBUS_LL0_IOOL_REPLAY_THRESHOLD_THRESH_UNUSED1_LEN   = 15  ;
static const uint8_t P9A_OBUS_LL0_IOOL_REPLAY_THRESHOLD_THRESH_LINK0_CLEAR   = 26  ;
static const uint8_t P9A_OBUS_LL0_IOOL_REPLAY_THRESHOLD_THRESH_LINK1_CLEAR   = 27  ;
static const uint8_t P9A_OBUS_LL0_IOOL_REPLAY_THRESHOLD_THRESH_DIS_TB_CLEAR  = 28  ;
static const uint8_t P9A_OBUS_LL0_IOOL_REPLAY_THRESHOLD_THRESH_DIS_TAP_CLEAR = 29  ;
static const uint8_t P9A_OBUS_LL0_IOOL_REPLAY_THRESHOLD_THRESH_DIS_TAP_STOP  = 30  ;
static const uint8_t P9A_OBUS_LL0_IOOL_REPLAY_THRESHOLD_THRESH_UNUSED2       = 31  ;
static const uint8_t P9A_OBUS_LL0_IOOL_REPLAY_THRESHOLD_THRESH_LINK0_COUNT   = 32  ;
static const uint8_t P9A_OBUS_LL0_IOOL_REPLAY_THRESHOLD_THRESH_LINK0_COUNT_LEN = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_REPLAY_THRESHOLD_THRESH_LINK1_COUNT   = 48  ;
static const uint8_t P9A_OBUS_LL0_IOOL_REPLAY_THRESHOLD_THRESH_LINK1_COUNT_LEN = 16  ;

static const uint8_t P9A_OBUS_LL0_IOOL_RETRAIN_THRESHOLD_THRESH_TB_SEL       = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_RETRAIN_THRESHOLD_THRESH_TB_SEL_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_RETRAIN_THRESHOLD_THRESH_TAP_SEL      = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_RETRAIN_THRESHOLD_THRESH_TAP_SEL_LEN  = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_RETRAIN_THRESHOLD_THRESH_ENABLE       = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_RETRAIN_THRESHOLD_THRESH_ENABLE_LEN   = 9   ;
static const uint8_t P9A_OBUS_LL0_IOOL_RETRAIN_THRESHOLD_THRESH_UNUSED1      = 17  ;
static const uint8_t P9A_OBUS_LL0_IOOL_RETRAIN_THRESHOLD_THRESH_UNUSED1_LEN  = 9   ;
static const uint8_t P9A_OBUS_LL0_IOOL_RETRAIN_THRESHOLD_THRESH_LINK0_CLEAR  = 26  ;
static const uint8_t P9A_OBUS_LL0_IOOL_RETRAIN_THRESHOLD_THRESH_LINK1_CLEAR  = 27  ;
static const uint8_t P9A_OBUS_LL0_IOOL_RETRAIN_THRESHOLD_THRESH_DIS_TB_CLEAR = 28  ;
static const uint8_t P9A_OBUS_LL0_IOOL_RETRAIN_THRESHOLD_THRESH_DIS_TAP_CLEAR = 29  ;
static const uint8_t P9A_OBUS_LL0_IOOL_RETRAIN_THRESHOLD_THRESH_DIS_TAP_STOP = 30  ;
static const uint8_t P9A_OBUS_LL0_IOOL_RETRAIN_THRESHOLD_THRESH_UNUSED2      = 31  ;
static const uint8_t P9A_OBUS_LL0_IOOL_RETRAIN_THRESHOLD_THRESH_LINK0_COUNT  = 32  ;
static const uint8_t P9A_OBUS_LL0_IOOL_RETRAIN_THRESHOLD_THRESH_LINK0_COUNT_LEN = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_RETRAIN_THRESHOLD_THRESH_LINK1_COUNT  = 48  ;
static const uint8_t P9A_OBUS_LL0_IOOL_RETRAIN_THRESHOLD_THRESH_LINK1_COUNT_LEN = 16  ;

static const uint8_t P9A_OBUS_LL0_IOOL_SEC_CONFIG_ENABLE_ERR_INJ             = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_SEC_CONFIG_ENABLE_TRACE               = 1   ;
static const uint8_t P9A_OBUS_LL0_IOOL_SEC_CONFIG_RESET_INJ                  = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_SEC_CONFIG_UNUSED4                    = 3   ;
static const uint8_t P9A_OBUS_LL0_IOOL_SEC_CONFIG_UNUSED4_LEN                = 13  ;
static const uint8_t P9A_OBUS_LL0_IOOL_SEC_CONFIG_SBE_ERROR_RATE             = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_SEC_CONFIG_SBE_ERROR_RATE_LEN         = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_SEC_CONFIG_RAND_ERROR_RATE            = 18  ;
static const uint8_t P9A_OBUS_LL0_IOOL_SEC_CONFIG_RAND_ERROR_RATE_LEN        = 6   ;
static const uint8_t P9A_OBUS_LL0_IOOL_SEC_CONFIG_INV_SH_ERROR_RATE          = 24  ;
static const uint8_t P9A_OBUS_LL0_IOOL_SEC_CONFIG_INV_SH_ERROR_RATE_LEN      = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_SEC_CONFIG_SYNC_HEADER_ERROR_RATE     = 26  ;
static const uint8_t P9A_OBUS_LL0_IOOL_SEC_CONFIG_SYNC_HEADER_ERROR_RATE_LEN = 6   ;
static const uint8_t P9A_OBUS_LL0_IOOL_SEC_CONFIG_UNUSED5                    = 32  ;
static const uint8_t P9A_OBUS_LL0_IOOL_SEC_CONFIG_UNUSED5_LEN                = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_SEC_CONFIG_EDPL_RATE                  = 48  ;
static const uint8_t P9A_OBUS_LL0_IOOL_SEC_CONFIG_EDPL_RATE_LEN              = 16  ;

static const uint8_t P9A_OBUS_LL0_IOOL_SL_ECC_THRESHOLD_THRESH_TB_SEL        = 0   ;
static const uint8_t P9A_OBUS_LL0_IOOL_SL_ECC_THRESHOLD_THRESH_TB_SEL_LEN    = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_SL_ECC_THRESHOLD_THRESH_TAP_SEL       = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_SL_ECC_THRESHOLD_THRESH_TAP_SEL_LEN   = 4   ;
static const uint8_t P9A_OBUS_LL0_IOOL_SL_ECC_THRESHOLD_THRESH_ENABLE        = 8   ;
static const uint8_t P9A_OBUS_LL0_IOOL_SL_ECC_THRESHOLD_THRESH_ENABLE_LEN    = 2   ;
static const uint8_t P9A_OBUS_LL0_IOOL_SL_ECC_THRESHOLD_THRESH_UNUSED1       = 10  ;
static const uint8_t P9A_OBUS_LL0_IOOL_SL_ECC_THRESHOLD_THRESH_UNUSED1_LEN   = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_SL_ECC_THRESHOLD_THRESH_LINK0_CLEAR   = 26  ;
static const uint8_t P9A_OBUS_LL0_IOOL_SL_ECC_THRESHOLD_THRESH_LINK1_CLEAR   = 27  ;
static const uint8_t P9A_OBUS_LL0_IOOL_SL_ECC_THRESHOLD_THRESH_DIS_TB_CLEAR  = 28  ;
static const uint8_t P9A_OBUS_LL0_IOOL_SL_ECC_THRESHOLD_THRESH_DIS_TAP_CLEAR = 29  ;
static const uint8_t P9A_OBUS_LL0_IOOL_SL_ECC_THRESHOLD_THRESH_DIS_TAP_STOP  = 30  ;
static const uint8_t P9A_OBUS_LL0_IOOL_SL_ECC_THRESHOLD_THRESH_UNUSED2       = 31  ;
static const uint8_t P9A_OBUS_LL0_IOOL_SL_ECC_THRESHOLD_THRESH_LINK0_COUNT   = 32  ;
static const uint8_t P9A_OBUS_LL0_IOOL_SL_ECC_THRESHOLD_THRESH_LINK0_COUNT_LEN = 16  ;
static const uint8_t P9A_OBUS_LL0_IOOL_SL_ECC_THRESHOLD_THRESH_LINK1_COUNT   = 48  ;
static const uint8_t P9A_OBUS_LL0_IOOL_SL_ECC_THRESHOLD_THRESH_LINK1_COUNT_LEN = 16  ;

static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_TRAINED = 0   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_TRAINED = 1   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_OP_IRQ  = 2   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_OP_IRQ  = 3   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_REPLAY_THRESHOLD = 4   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_REPLAY_THRESHOLD = 5   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_CRC_ERROR = 6   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_CRC_ERROR = 7   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_NAK_RECEIVED = 8   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_NAK_RECEIVED = 9   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL = 10  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL = 11  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD = 12  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD = 13  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE = 14  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE = 15  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_SL_ECC_UE = 16  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_SL_ECC_UE = 17  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD = 18  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD = 19  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN = 20  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN = 21  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_INVALID_BLOCK = 22  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_INVALID_BLOCK = 23  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_DESKEW_ERROR = 24  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_DESKEW_ERROR = 25  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_DESKEW_OVERFLOW = 26  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_DESKEW_OVERFLOW = 27  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_SW_RETRAIN = 28  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_SW_RETRAIN = 29  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW = 30  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW = 31  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW = 32  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW = 33  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_NUM_REPLAY = 34  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_NUM_REPLAY = 35  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED = 36  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED = 37  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR = 38  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR = 39  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_TCOMPLETE_BAD = 40  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_TCOMPLETE_BAD = 41  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_NO_SPARE = 42  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_NO_SPARE = 43  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_SPARE_DONE = 44  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_SPARE_DONE = 45  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS = 46  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS = 47  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_NPU_DLX_ERROR = 48  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_NPU_DLX_ERROR = 49  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINKX_NPU_ERROR = 50  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_OSC_SWITCH    = 51  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR = 52  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR = 53  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR = 54  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR = 55  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_TRAINING_FAILED = 56  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_TRAINING_FAILED = 57  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR = 58  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR = 59  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_INTERNAL_ERROR = 60  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_INTERNAL_ERROR = 61  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_SCOM_ERR_DUP  = 62  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_SCOM_ERR      = 63  ;

static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_TRAINED      = 0   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_TRAINED      = 1   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_OP_IRQ       = 2   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_OP_IRQ       = 3   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_REPLAY_THRESHOLD = 4   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_REPLAY_THRESHOLD = 5   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_CRC_ERROR    = 6   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_CRC_ERROR    = 7   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_NAK_RECEIVED = 8   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_NAK_RECEIVED = 9   ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_REPLAY_BUFFER_FULL = 10  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_REPLAY_BUFFER_FULL = 11  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_SL_ECC_THRESHOLD = 12  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_SL_ECC_THRESHOLD = 13  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_SL_ECC_CORRECTABLE = 14  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_SL_ECC_CORRECTABLE = 15  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_SL_ECC_UE    = 16  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_SL_ECC_UE    = 17  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_RETRAIN_THRESHOLD = 18  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_RETRAIN_THRESHOLD = 19  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_LOSS_BLOCK_ALIGN = 20  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_LOSS_BLOCK_ALIGN = 21  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_INVALID_BLOCK = 22  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_INVALID_BLOCK = 23  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_DESKEW_ERROR = 24  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_DESKEW_ERROR = 25  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_DESKEW_OVERFLOW = 26  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_DESKEW_OVERFLOW = 27  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_SW_RETRAIN   = 28  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_SW_RETRAIN   = 29  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_ACK_QUEUE_OVERFLOW = 30  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_ACK_QUEUE_OVERFLOW = 31  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_ACK_QUEUE_UNDERFLOW = 32  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_ACK_QUEUE_UNDERFLOW = 33  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_NUM_REPLAY   = 34  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_NUM_REPLAY   = 35  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_TRAINING_SET_RECEIVED = 36  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_TRAINING_SET_RECEIVED = 37  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_PRBS_SELECT_ERROR = 38  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_PRBS_SELECT_ERROR = 39  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_TCOMPLETE_BAD = 40  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_TCOMPLETE_BAD = 41  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_NO_SPARE     = 42  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_NO_SPARE     = 43  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_SPARE_DONE   = 44  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_SPARE_DONE   = 45  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_TOO_MANY_CRC_ERRORS = 46  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_TOO_MANY_CRC_ERRORS = 47  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_NPU_DLX_ERROR = 48  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_NPU_DLX_ERROR = 49  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINKX_NPU_ERROR    = 50  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_OSC_SWITCH         = 51  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_CORRECTABLE_ARRAY_ERROR = 52  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_CORRECTABLE_ARRAY_ERROR = 53  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR = 54  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR = 55  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_TRAINING_FAILED = 56  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_TRAINING_FAILED = 57  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_UNRECOVERABLE_ERROR = 58  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_UNRECOVERABLE_ERROR = 59  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_INTERNAL_ERROR = 60  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_INTERNAL_ERROR = 61  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_SCOM_ERR_DUP       = 62  ;
static const uint8_t P9A_OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_SCOM_ERR           = 63  ;

static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_RESET                      = 0   ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_RETRAIN                    = 1   ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_VERSION                    = 2   ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_VERSION_LEN                = 6   ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_TRAIN_MODE                 = 8   ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_TRAIN_MODE_LEN             = 4   ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_SUPPORTED_MODES            = 12  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_SUPPORTED_MODES_LEN        = 4   ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_X4_BACKOFF_ENABLE          = 16  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_X1_BACKOFF_ENABLE          = 17  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_PWRMGT_ENABLE              = 18  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_TX_EP_MODE                 = 19  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_PHY_CNTR_LIMIT             = 20  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_PHY_CNTR_LIMIT_LEN         = 4   ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_128_130_ENCODING_ENABLED   = 24  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_TRAINING_STATUS_REGISTER_SELECT = 25  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_UNUSED2                    = 26  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_CRC_TX_INJECTION           = 27  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_ECC_CE_INJECTION           = 28  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_ECC_UE_INJECTION           = 29  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_DL2TL_CONTROL_PARITY_INJECT = 30  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_DL2TL_DATA_PARITY_INJECT   = 31  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_UNUSED1                    = 32  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_DEBUG_ENABLE               = 33  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_DEBUG_SELECT               = 34  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_DEBUG_SELECT_LEN           = 2   ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_REPLAY_RSVD_ENTRIES        = 36  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_REPLAY_RSVD_ENTRIES_LEN    = 4   ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_FWD_PROGRESS_TIMER         = 40  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_FWD_PROGRESS_TIMER_LEN     = 4   ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_TLERROR_LINKDOWN           = 44  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_TLERROR_ILATRIG            = 45  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_TLERROR_AFUFREEZE          = 46  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_TLERROR_ALLFREEZE          = 47  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_TLEVENT_LINKDOWN           = 48  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_TLEVENT_ILATRIG            = 49  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_TLEVENT_AFUFREEZE          = 50  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_TLEVENT_ALLFREEZE          = 51  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_CFG_SPARE                  = 52  ;
static const uint8_t P9A_OBUS_LL0_ODL0_CONFIG_CFG_CFG_SPARE_LEN              = 12  ;

static const uint8_t P9A_OBUS_LL0_ODL0_DLX_CONFIG_CFG_DLX0                   = 0   ;
static const uint8_t P9A_OBUS_LL0_ODL0_DLX_CONFIG_CFG_DLX0_LEN               = 32  ;

static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_RESET                      = 0   ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_RETRAIN                    = 1   ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_VERSION                    = 2   ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_VERSION_LEN                = 6   ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_TRAIN_MODE                 = 8   ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_TRAIN_MODE_LEN             = 4   ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_SUPPORTED_MODES            = 12  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_SUPPORTED_MODES_LEN        = 4   ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_X4_BACKOFF_ENABLE          = 16  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_X1_BACKOFF_ENABLE          = 17  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_PWRMGT_ENABLE              = 18  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_TX_EP_MODE                 = 19  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_PHY_CNTR_LIMIT             = 20  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_PHY_CNTR_LIMIT_LEN         = 4   ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_128_130_ENCODING_ENABLED   = 24  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_TRAINING_STATUS_REGISTER_SELECT = 25  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_UNUSED2                    = 26  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_CRC_TX_INJECTION           = 27  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_ECC_CE_INJECTION           = 28  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_ECC_UE_INJECTION           = 29  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_DL2TL_CONTROL_PARITY_INJECT = 30  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_DL2TL_DATA_PARITY_INJECT   = 31  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_UNUSED1                    = 32  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_DEBUG_ENABLE               = 33  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_DEBUG_SELECT               = 34  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_DEBUG_SELECT_LEN           = 2   ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_REPLAY_RSVD_ENTRIES        = 36  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_REPLAY_RSVD_ENTRIES_LEN    = 4   ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_FWD_PROGRESS_TIMER         = 40  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_FWD_PROGRESS_TIMER_LEN     = 4   ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_TLERROR_LINKDOWN           = 44  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_TLERROR_ILATRIG            = 45  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_TLERROR_AFUFREEZE          = 46  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_TLERROR_ALLFREEZE          = 47  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_TLEVENT_LINKDOWN           = 48  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_TLEVENT_ILATRIG            = 49  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_TLEVENT_AFUFREEZE          = 50  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_TLEVENT_ALLFREEZE          = 51  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_CFG_SPARE                  = 52  ;
static const uint8_t P9A_OBUS_LL0_ODL1_CONFIG_CFG_CFG_SPARE_LEN              = 12  ;

static const uint8_t P9A_OBUS_LL0_ODL1_DLX_CONFIG_CFG_DLX1                   = 0   ;
static const uint8_t P9A_OBUS_LL0_ODL1_DLX_CONFIG_CFG_DLX1_LEN               = 32  ;

static const uint8_t P9A_OBUS_LL0_PB_IOOL_FIR_ACTION0_REG_ACTION0            = 0   ;
static const uint8_t P9A_OBUS_LL0_PB_IOOL_FIR_ACTION0_REG_ACTION0_LEN        = 64  ;

static const uint8_t P9A_OBUS_LL0_PB_IOOL_FIR_ACTION1_REG_ACTION1            = 0   ;
static const uint8_t P9A_OBUS_LL0_PB_IOOL_FIR_ACTION1_REG_ACTION1_LEN        = 64  ;

static const uint8_t P9A_OBUS_MIB_XIICAC_ICACHE_TAG_ADDR                     = 0   ;
static const uint8_t P9A_OBUS_MIB_XIICAC_ICACHE_TAG_ADDR_LEN                 = 27  ;
static const uint8_t P9A_OBUS_MIB_XIICAC_ICACHE_ERR                          = 32  ;
static const uint8_t P9A_OBUS_MIB_XIICAC_PIB_IFETCH_PENDING                  = 34  ;
static const uint8_t P9A_OBUS_MIB_XIICAC_XIMEM_MEM_IFETCH_PENDING            = 35  ;
static const uint8_t P9A_OBUS_MIB_XIICAC_ICACHE_VALID                        = 36  ;
static const uint8_t P9A_OBUS_MIB_XIICAC_ICACHE_VALID_LEN                    = 4   ;
static const uint8_t P9A_OBUS_MIB_XIICAC_ICACHE_LINE2_VALID                  = 40  ;
static const uint8_t P9A_OBUS_MIB_XIICAC_ICACHE_LINE2_VALID_LEN              = 4   ;
static const uint8_t P9A_OBUS_MIB_XIICAC_ICACHE_LINE_PTR                     = 45  ;
static const uint8_t P9A_OBUS_MIB_XIICAC_ICACHE_LINE2_ERR                    = 46  ;
static const uint8_t P9A_OBUS_MIB_XIICAC_ICACHE_PREFETCH_PENDING             = 47  ;

static const uint8_t P9A_OBUS_MIB_XIMEM_MEM_ADDR                             = 0   ;
static const uint8_t P9A_OBUS_MIB_XIMEM_MEM_ADDR_LEN                         = 32  ;
static const uint8_t P9A_OBUS_MIB_XIMEM_MEM_R_NW                             = 32  ;
static const uint8_t P9A_OBUS_MIB_XIMEM_MEM_BUSY                             = 33  ;
static const uint8_t P9A_OBUS_MIB_XIMEM_MEM_IMPRECISE_ERROR_PENDING          = 34  ;
static const uint8_t P9A_OBUS_MIB_XIMEM_MEM_BYTE_ENABLE                      = 35  ;
static const uint8_t P9A_OBUS_MIB_XIMEM_MEM_BYTE_ENABLE_LEN                  = 8   ;
static const uint8_t P9A_OBUS_MIB_XIMEM_MEM_LINE_MODE                        = 43  ;
static const uint8_t P9A_OBUS_MIB_XIMEM_MEM_ERROR                            = 49  ;
static const uint8_t P9A_OBUS_MIB_XIMEM_MEM_ERROR_LEN                        = 3   ;
static const uint8_t P9A_OBUS_MIB_XIMEM_MEM_IFETCH_PENDING                   = 62  ;
static const uint8_t P9A_OBUS_MIB_XIMEM_MEM_DATAOP_PENDING                   = 63  ;

static const uint8_t P9A_OBUS_MIB_XISGB_STORE_ADDRESS                        = 0   ;
static const uint8_t P9A_OBUS_MIB_XISGB_STORE_ADDRESS_LEN                    = 32  ;
static const uint8_t P9A_OBUS_MIB_XISGB_XIMEM_MEM_IMPRECISE_ERROR_PENDING    = 35  ;
static const uint8_t P9A_OBUS_MIB_XISGB_SGB_BYTE_VALID                       = 36  ;
static const uint8_t P9A_OBUS_MIB_XISGB_SGB_BYTE_VALID_LEN                   = 4   ;
static const uint8_t P9A_OBUS_MIB_XISGB_SGB_FLUSH_PENDING                    = 63  ;

static const uint8_t P9A_OBUS_NV0_ODL0_DLX_INFO_STS                          = 0   ;
static const uint8_t P9A_OBUS_NV0_ODL0_DLX_INFO_STS_LEN                      = 64  ;

static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_TRAINED_MODE               = 0   ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_TRAINED_MODE_LEN           = 4   ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_RX_LANE_REVERSED           = 4   ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_TX_LANE_REVERSED           = 5   ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_RSVD0                      = 6   ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_ACK_PTRS_EQUAL             = 7   ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_RSVD1                      = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_RSVD1_LEN                  = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_RX_TRAINED_LANES           = 16  ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_RX_TRAINED_LANES_LEN       = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_TX_TRAINED_LANES           = 24  ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_TX_TRAINED_LANES_LEN       = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_ENDPOINT_INFO              = 32  ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_ENDPOINT_INFO_LEN          = 16  ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_RSVD2                      = 48  ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_TRAINING_STATE_MACHINE     = 49  ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_TRAINING_STATE_MACHINE_LEN = 3   ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_RSVD3                      = 52  ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_RSVD3_LEN                  = 3   ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_DESKEW_DONE                = 55  ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_LANES_DISABLED             = 56  ;
static const uint8_t P9A_OBUS_NV0_ODL0_STATUS_STS_LANES_DISABLED_LEN         = 8   ;

static const uint8_t P9A_OBUS_NV0_ODL0_TRAINING_STATUS_STS_RX_PATTERN_A      = 0   ;
static const uint8_t P9A_OBUS_NV0_ODL0_TRAINING_STATUS_STS_RX_PATTERN_A_LEN  = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL0_TRAINING_STATUS_STS_RX_PATTERN_B      = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL0_TRAINING_STATUS_STS_RX_PATTERN_B_LEN  = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL0_TRAINING_STATUS_STS_SYNC_PATTERN      = 16  ;
static const uint8_t P9A_OBUS_NV0_ODL0_TRAINING_STATUS_STS_SYNC_PATTERN_LEN  = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL0_TRAINING_STATUS_STS_PHY_INIT_DONE     = 24  ;
static const uint8_t P9A_OBUS_NV0_ODL0_TRAINING_STATUS_STS_PHY_INIT_DONE_LEN = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL0_TRAINING_STATUS_STS_BLOCK_LOCKED      = 32  ;
static const uint8_t P9A_OBUS_NV0_ODL0_TRAINING_STATUS_STS_BLOCK_LOCKED_LEN  = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL0_TRAINING_STATUS_STS_RX_TS1            = 40  ;
static const uint8_t P9A_OBUS_NV0_ODL0_TRAINING_STATUS_STS_RX_TS1_LEN        = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL0_TRAINING_STATUS_STS_RX_TS2            = 48  ;
static const uint8_t P9A_OBUS_NV0_ODL0_TRAINING_STATUS_STS_RX_TS2_LEN        = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL0_TRAINING_STATUS_STS_RX_TS3            = 56  ;
static const uint8_t P9A_OBUS_NV0_ODL0_TRAINING_STATUS_STS_RX_TS3_LEN        = 8   ;

static const uint8_t P9A_OBUS_NV0_ODL1_DLX_INFO_STS                          = 0   ;
static const uint8_t P9A_OBUS_NV0_ODL1_DLX_INFO_STS_LEN                      = 64  ;

static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_TRAINED_MODE               = 0   ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_TRAINED_MODE_LEN           = 4   ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_RX_LANE_REVERSED           = 4   ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_TX_LANE_REVERSED           = 5   ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_RSVD0                      = 6   ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_ACK_PTRS_EQUAL             = 7   ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_RSVD1                      = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_RSVD1_LEN                  = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_RX_TRAINED_LANES           = 16  ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_RX_TRAINED_LANES_LEN       = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_TX_TRAINED_LANES           = 24  ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_TX_TRAINED_LANES_LEN       = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_ENDPOINT_INFO              = 32  ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_ENDPOINT_INFO_LEN          = 16  ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_RSVD2                      = 48  ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_TRAINING_STATE_MACHINE     = 49  ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_TRAINING_STATE_MACHINE_LEN = 3   ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_RSVD3                      = 52  ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_RSVD3_LEN                  = 3   ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_DESKEW_DONE                = 55  ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_LANES_DISABLED             = 56  ;
static const uint8_t P9A_OBUS_NV0_ODL1_STATUS_STS_LANES_DISABLED_LEN         = 8   ;

static const uint8_t P9A_OBUS_NV0_ODL1_TRAINING_STATUS_STS_RX_PATTERN_A      = 0   ;
static const uint8_t P9A_OBUS_NV0_ODL1_TRAINING_STATUS_STS_RX_PATTERN_A_LEN  = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL1_TRAINING_STATUS_STS_RX_PATTERN_B      = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL1_TRAINING_STATUS_STS_RX_PATTERN_B_LEN  = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL1_TRAINING_STATUS_STS_SYNC_PATTERN      = 16  ;
static const uint8_t P9A_OBUS_NV0_ODL1_TRAINING_STATUS_STS_SYNC_PATTERN_LEN  = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL1_TRAINING_STATUS_STS_PHY_INIT_DONE     = 24  ;
static const uint8_t P9A_OBUS_NV0_ODL1_TRAINING_STATUS_STS_PHY_INIT_DONE_LEN = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL1_TRAINING_STATUS_STS_BLOCK_LOCKED      = 32  ;
static const uint8_t P9A_OBUS_NV0_ODL1_TRAINING_STATUS_STS_BLOCK_LOCKED_LEN  = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL1_TRAINING_STATUS_STS_RX_TS1            = 40  ;
static const uint8_t P9A_OBUS_NV0_ODL1_TRAINING_STATUS_STS_RX_TS1_LEN        = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL1_TRAINING_STATUS_STS_RX_TS2            = 48  ;
static const uint8_t P9A_OBUS_NV0_ODL1_TRAINING_STATUS_STS_RX_TS2_LEN        = 8   ;
static const uint8_t P9A_OBUS_NV0_ODL1_TRAINING_STATUS_STS_RX_TS3            = 56  ;
static const uint8_t P9A_OBUS_NV0_ODL1_TRAINING_STATUS_STS_RX_TS3_LEN        = 8   ;

static const uint8_t P9A_OBUS_PCBSLOB0_ASSIST_INTERRUPT_REG_ATTN             = 0   ;
static const uint8_t P9A_OBUS_PCBSLOB0_ASSIST_INTERRUPT_REG_RECOV            = 1   ;
static const uint8_t P9A_OBUS_PCBSLOB0_ASSIST_INTERRUPT_REG_XSTOP            = 2   ;

static const uint8_t P9A_OBUS_PCBSLOB0_ATOMIC_LOCK_REG_ENABLE                = 0   ;
static const uint8_t P9A_OBUS_PCBSLOB0_ATOMIC_LOCK_REG_ID                    = 1   ;
static const uint8_t P9A_OBUS_PCBSLOB0_ATOMIC_LOCK_REG_ID_LEN                = 4   ;
static const uint8_t P9A_OBUS_PCBSLOB0_ATOMIC_LOCK_REG_ACTIVITY              = 8   ;
static const uint8_t P9A_OBUS_PCBSLOB0_ATOMIC_LOCK_REG_ACTIVITY_LEN          = 8   ;

static const uint8_t P9A_OBUS_PCBSLOB0_ATTN_INTERRUPT_REG_ATTN               = 0   ;

static const uint8_t P9A_OBUS_PCBSLOB0_EDRAM_STATUS_STAT                     = 0   ;
static const uint8_t P9A_OBUS_PCBSLOB0_EDRAM_STATUS_STAT_LEN                 = 4   ;

static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_CE                          = 0   ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_CHIPLET_ERRORS              = 1   ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_CHIPLET_ERRORS_LEN          = 3   ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_PARITY                      = 4   ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_DATA_BUFFER                 = 5   ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_ADDR_BUFFER                 = 6   ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_PCB_FSM                     = 7   ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_CL_FSM                      = 8   ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_INT_RX_FSM                  = 9   ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_INT_TX_FSM                  = 10  ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_INT_TYPE                    = 11  ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_CL_DATA                     = 12  ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_INFO                        = 13  ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_UNUSED_0                    = 14  ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_CHIPLET_ATOMIC_LOCK         = 15  ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_PCB_INTERFACE               = 16  ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_CHIPLET_OFFLINE             = 17  ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_EDRAM_SEQUENCE_ERR          = 18  ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_CTRL_PARITY                 = 19  ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_ADDRESS_PARITY              = 20  ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_TIMEOUT_PARITY              = 21  ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_CONFIG_PARITY               = 22  ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_UNUSED_1                    = 23  ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_DIV_PARITY                  = 24  ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_PLL_UNLOCK                  = 25  ;
static const uint8_t P9A_OBUS_PCBSLOB0_ERROR_REG_PLL_UNLOCK_LEN              = 4   ;

static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_0_REG_0                    = 0   ;
static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_0_REG_0_LEN                = 6   ;
static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_0_REG_SUPPRESS             = 6   ;

static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_1_REG_1                    = 0   ;
static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_1_REG_1_LEN                = 6   ;
static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_1_REG_SUPPRESS             = 6   ;

static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_2_REG_2                    = 0   ;
static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_2_REG_2_LEN                = 6   ;
static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_2_REG_SUPPRESS             = 6   ;

static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_3_REG_3                    = 0   ;
static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_3_REG_3_LEN                = 6   ;
static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_3_REG_SUPPRESS             = 6   ;

static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_4_REG_4                    = 0   ;
static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_4_REG_4_LEN                = 6   ;
static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_4_REG_SUPPRESS             = 6   ;

static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_5_REG_5                    = 0   ;
static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_5_REG_5_LEN                = 6   ;
static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_5_REG_SUPPRESS             = 6   ;

static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_6_REG_6                    = 0   ;
static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_6_REG_6_LEN                = 6   ;
static const uint8_t P9A_OBUS_PCBSLOB0_HANG_PULSE_6_REG_SUPPRESS             = 6   ;

static const uint8_t P9A_OBUS_PCBSLOB0_HEARTBEAT_REG_DEAD                    = 0   ;

static const uint8_t P9A_OBUS_PCBSLOB0_MULTICAST_GROUP_1_MULTICAST1          = 3   ;
static const uint8_t P9A_OBUS_PCBSLOB0_MULTICAST_GROUP_1_MULTICAST1_LEN      = 3   ;

static const uint8_t P9A_OBUS_PCBSLOB0_MULTICAST_GROUP_2_MULTICAST2          = 3   ;
static const uint8_t P9A_OBUS_PCBSLOB0_MULTICAST_GROUP_2_MULTICAST2_LEN      = 3   ;

static const uint8_t P9A_OBUS_PCBSLOB0_MULTICAST_GROUP_3_MULTICAST3          = 3   ;
static const uint8_t P9A_OBUS_PCBSLOB0_MULTICAST_GROUP_3_MULTICAST3_LEN      = 3   ;

static const uint8_t P9A_OBUS_PCBSLOB0_MULTICAST_GROUP_4_MULTICAST4          = 3   ;
static const uint8_t P9A_OBUS_PCBSLOB0_MULTICAST_GROUP_4_MULTICAST4_LEN      = 3   ;

static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_CHIPLET_ENABLE = 0   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_PCB_EP_RESET = 1   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_CLK_ASYNC_RESET = 2   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_PLL_TEST_EN = 3   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_PLL_RESET = 4   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_PLL_BYPASS = 5   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_VITAL_SCAN = 6   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_VITAL_SCAN_IN = 7   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_VITAL_PHASE = 8   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_FLUSH_ALIGN_OVR = 9   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_VITAL_AL  = 10  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_ACT_DIS   = 11  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_MPW1      = 12  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_MPW2      = 13  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_MPW3      = 14  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_DELAY_LCLKR = 15  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_VITAL_THOLD = 16  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_FLUSH_SCAN_N = 17  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_FENCE_EN  = 18  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_CPLT_RCTRL = 19  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_CPLT_DCTRL = 20  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_ADJ_FUNC_CLKSEL = 22  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_TP_SRAM_ENABLE = 23  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_TP_FENCE_PCB = 25  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_LVLTRANS_FENCE = 26  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_ARRAY_WRITE_ASSIST_EN = 27  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_HTB_INTEST = 28  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_HTB_EXTEST = 29  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_PM_ACCESS = 30  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL0_PLLFORCE_OUT_EN = 31  ;

static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_PLL_CLKIN_SEL = 0   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_CLK_DCC_BYPASS_EN = 1   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_CLK_PDLY_BYPASS_EN = 2   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_CLK_DIV_BYPASS_EN = 3   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_REFCLK_CLKMUX0_SEL = 4   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_REFCLK_CLKMUX1_SEL = 5   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_PLL_BNDY_BYPASS_EN = 6   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_DPLL_TEST_SEL = 8   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_DPLL_TEST_SEL_LEN = 8   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_SB_STRENGTH = 16  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_SB_STRENGTH_LEN = 4   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_ASYNC_TYPE = 20  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_ASYNC_OBS = 21  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_CPM_CAL_SET = 22  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_SENSEADJ_RESET0 = 23  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_SENSEADJ_RESET1 = 24  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_CLK_PULSE_EN = 25  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_CLK_PULSE_MODE = 26  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_CLK_PULSE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_PCB_ACCESS = 28  ;
static const uint8_t P9A_OBUS_PCBSLOB0_PCBSLOB0_PCBSLOB0_NET_CTRL1_PCB_ACCESS_LEN = 4   ;

static const uint8_t P9A_OBUS_PCBSLOB0_PLL_LOCK_REG_LOCK                     = 0   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PLL_LOCK_REG_LOCK_LEN                 = 4   ;

static const uint8_t P9A_OBUS_PCBSLOB0_PRE_COUNTER_REG_COUNTER               = 0   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PRE_COUNTER_REG_COUNTER_LEN           = 8   ;

static const uint8_t P9A_OBUS_PCBSLOB0_PRIMARY_ADDRESS_REG_PRIMARY_ADDRESS   = 0   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PRIMARY_ADDRESS_REG_PRIMARY_ADDRESS_LEN = 6   ;

static const uint8_t P9A_OBUS_PCBSLOB0_PROTECT_MODE_REG_READ_ENABLE          = 0   ;
static const uint8_t P9A_OBUS_PCBSLOB0_PROTECT_MODE_REG_WRITE_ENABLE         = 1   ;

static const uint8_t P9A_OBUS_PCBSLOB0_RECOV_INTERRUPT_REG_RECOV             = 0   ;

static const uint8_t P9A_OBUS_PCBSLOB0_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK = 0   ;
static const uint8_t P9A_OBUS_PCBSLOB0_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN = 1   ;
static const uint8_t P9A_OBUS_PCBSLOB0_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP = 2   ;
static const uint8_t P9A_OBUS_PCBSLOB0_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK = 3   ;
static const uint8_t P9A_OBUS_PCBSLOB0_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT = 4   ;
static const uint8_t P9A_OBUS_PCBSLOB0_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO = 5   ;
static const uint8_t P9A_OBUS_PCBSLOB0_SLAVE_CONFIG_REG_CFG_PM_DISABLE       = 6   ;
static const uint8_t P9A_OBUS_PCBSLOB0_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE   = 7   ;
static const uint8_t P9A_OBUS_PCBSLOB0_SLAVE_CONFIG_REG_CFG_MASK_PARITY_ERRS = 8   ;
static const uint8_t P9A_OBUS_PCBSLOB0_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS = 9   ;
static const uint8_t P9A_OBUS_PCBSLOB0_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS = 10  ;
static const uint8_t P9A_OBUS_PCBSLOB0_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS  = 11  ;
static const uint8_t P9A_OBUS_PCBSLOB0_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS    = 12  ;
static const uint8_t P9A_OBUS_PCBSLOB0_SLAVE_CONFIG_REG_CFG_MASK_EDRAM_ERRS  = 13  ;

static const uint8_t P9A_OBUS_PCBSLOB0_TIMEOUT_REG_INT_TIMEOUT               = 0   ;
static const uint8_t P9A_OBUS_PCBSLOB0_TIMEOUT_REG_INT_TIMEOUT_LEN           = 2   ;

static const uint8_t P9A_OBUS_PCBSLOB0_XSTOP_INTERRUPT_REG_XSTOP             = 0   ;

static const uint8_t P9A_OBUS_PPE_FIR_ACTION0_REG_ACTION0                    = 0   ;
static const uint8_t P9A_OBUS_PPE_FIR_ACTION0_REG_ACTION0_LEN                = 13  ;

static const uint8_t P9A_OBUS_PPE_FIR_ACTION1_REG_ACTION1                    = 0   ;
static const uint8_t P9A_OBUS_PPE_FIR_ACTION1_REG_ACTION1_LEN                = 13  ;

static const uint8_t P9A_OBUS_PPE_FIR_MASK_REG_ERROR                         = 0   ;
static const uint8_t P9A_OBUS_PPE_FIR_MASK_REG_ERROR_LEN                     = 4   ;
static const uint8_t P9A_OBUS_PPE_FIR_MASK_REG_HALTED                        = 4   ;
static const uint8_t P9A_OBUS_PPE_FIR_MASK_REG_WATCHDOG_TIMEOUT              = 5   ;
static const uint8_t P9A_OBUS_PPE_FIR_MASK_REG_MMIO_DATA_IN                  = 6   ;
static const uint8_t P9A_OBUS_PPE_FIR_MASK_REG_ARB_MISSED_SCRUB_TICK         = 7   ;
static const uint8_t P9A_OBUS_PPE_FIR_MASK_REG_ARB_ARY_UE                    = 8   ;
static const uint8_t P9A_OBUS_PPE_FIR_MASK_REG_ARB_ARY_CE                    = 9   ;
static const uint8_t P9A_OBUS_PPE_FIR_MASK_REG_RESERVED                      = 10  ;
static const uint8_t P9A_OBUS_PPE_FIR_MASK_REG_INTERNAL_SCOM_ERROR           = 11  ;
static const uint8_t P9A_OBUS_PPE_FIR_MASK_REG_INTERNAL_SCOM_ERROR_CLONE     = 12  ;

static const uint8_t P9A_OBUS_PPE_FIR_REG_ERROR                              = 0   ;
static const uint8_t P9A_OBUS_PPE_FIR_REG_ERROR_LEN                          = 4   ;
static const uint8_t P9A_OBUS_PPE_FIR_REG_HALTED                             = 4   ;
static const uint8_t P9A_OBUS_PPE_FIR_REG_WATCHDOG_TIMEOUT                   = 5   ;
static const uint8_t P9A_OBUS_PPE_FIR_REG_MMIO_DATA_IN                       = 6   ;
static const uint8_t P9A_OBUS_PPE_FIR_REG_ARB_MISSED_SCRUB_TICK              = 7   ;
static const uint8_t P9A_OBUS_PPE_FIR_REG_ARB_ARY_UE                         = 8   ;
static const uint8_t P9A_OBUS_PPE_FIR_REG_ARB_ARY_CE                         = 9   ;
static const uint8_t P9A_OBUS_PPE_FIR_REG_RESERVED                           = 10  ;
static const uint8_t P9A_OBUS_PPE_FIR_REG_SCOMFIR_ERROR                      = 11  ;
static const uint8_t P9A_OBUS_PPE_FIR_REG_SCOMFIR_ERROR_CLONE                = 12  ;

static const uint8_t P9A_OBUS_PPE_FIR_WOF_REG_WOF                            = 0   ;
static const uint8_t P9A_OBUS_PPE_FIR_WOF_REG_WOF_LEN                        = 13  ;

static const uint8_t P9A_OBUS_PPE_XIDBGPRO_XSR_HS                            = 0   ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_XSR_HC                            = 1   ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_XSR_HC_LEN                        = 3   ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_XSR_HCP                           = 4   ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_XSR_RIP                           = 5   ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_XSR_SIP                           = 6   ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_XSR_TRAP                          = 7   ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_XSR_IAC                           = 8   ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_NULL_MSR_SIBRC                    = 9   ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_NULL_MSR_SIBRC_LEN                = 3   ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_XSR_DACR                          = 12  ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_XSR_DACW                          = 13  ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_NULL_MSR_WE                       = 14  ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_XSR_TRH                           = 15  ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_XSR_SMS                           = 16  ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_XSR_SMS_LEN                       = 4   ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_NULL_MSR_LP                       = 20  ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_XSR_EP                            = 21  ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_XSR_PTR                           = 24  ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_XSR_ST                            = 25  ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_XSR_MFE                           = 28  ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_XSR_MCS                           = 29  ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_XSR_MCS_LEN                       = 3   ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_IAR                               = 32  ;
static const uint8_t P9A_OBUS_PPE_XIDBGPRO_IAR_LEN                           = 30  ;

static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XSR_HS                            = 0   ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XSR_HC                            = 1   ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XSR_HC_LEN                        = 3   ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XSR_HCP                           = 4   ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XSR_RIP                           = 5   ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XSR_SIP                           = 6   ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XSR_TRAP                          = 7   ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XSR_IAC                           = 8   ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_NULL_MSR_SIBRC                    = 9   ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_NULL_MSR_SIBRC_LEN                = 3   ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XSR_DACR                          = 12  ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XSR_DACW                          = 13  ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_NULL_MSR_WE                       = 14  ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XSR_TRH                           = 15  ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XSR_SMS                           = 16  ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XSR_SMS_LEN                       = 4   ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_NULL_MSR_LP                       = 20  ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XSR_EP                            = 21  ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XSR_PTR                           = 24  ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XSR_ST                            = 25  ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XSR_MFE                           = 28  ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XSR_MCS                           = 29  ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XSR_MCS_LEN                       = 3   ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XIRAMRA_SPRG0                     = 32  ;
static const uint8_t P9A_OBUS_PPE_XIRAMDBG_XIRAMRA_SPRG0_LEN                 = 32  ;

static const uint8_t P9A_OBUS_PPE_XIRAMEDR_XIRAMGA_IR                        = 0   ;
static const uint8_t P9A_OBUS_PPE_XIRAMEDR_XIRAMGA_IR_LEN                    = 32  ;
static const uint8_t P9A_OBUS_PPE_XIRAMEDR_EDR                               = 32  ;
static const uint8_t P9A_OBUS_PPE_XIRAMEDR_EDR_LEN                           = 32  ;

static const uint8_t P9A_OBUS_PPE_XIRAMGA_IR                                 = 0   ;
static const uint8_t P9A_OBUS_PPE_XIRAMGA_IR_LEN                             = 32  ;
static const uint8_t P9A_OBUS_PPE_XIRAMGA_XIRAMRA_SPRG0                      = 32  ;
static const uint8_t P9A_OBUS_PPE_XIRAMGA_XIRAMRA_SPRG0_LEN                  = 32  ;

static const uint8_t P9A_OBUS_PPE_XIRAMRA_XIXCR_XCR                          = 1   ;
static const uint8_t P9A_OBUS_PPE_XIRAMRA_XIXCR_XCR_LEN                      = 3   ;
static const uint8_t P9A_OBUS_PPE_XIRAMRA_SPRG0                              = 32  ;
static const uint8_t P9A_OBUS_PPE_XIRAMRA_SPRG0_LEN                          = 32  ;

static const uint8_t P9A_OBUS_PPE_XIXCR_XCR                                  = 1   ;
static const uint8_t P9A_OBUS_PPE_XIXCR_XCR_LEN                              = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE0_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE1_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE2_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS0_SLICE3_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE0_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE1_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE2_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS1_SLICE3_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE0_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE1_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE2_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS2_SLICE3_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE0_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE1_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE2_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS3_SLICE3_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE0_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE1_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE2_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS4_SLICE3_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE0_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE1_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE2_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL_PR_EDGE_TRACK_CNTL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL_PR_WOBBLE_EDGE = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DDC_A = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DDC_B = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_A = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_TO_EDGE_B = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_SL_1UI = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL_PR_BUMP_SR_1UI = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_A = 59  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL_PR_DATA_OFFSET_DISABLE_B = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_A = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL_PR_USE_DFE_CLOCK_B = 62  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_A_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL3_EO_PL_PR_DATA_B_OFFSET_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL3_EO_PL_PR_LOCK_DONE = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_FILTER_EN = 61  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL3_EO_PL_PR_INVALID_LOCK_BUMP_SIZE_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_STOP = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_DDC_SM_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_STOP = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL4_EO_PL_PR_TRACE_WOBBLE_SM_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL4_EO_PL_PR_RESET = 62  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL4_EO_PL_IORESET = 63  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SL_1STEP_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL5_EO_PL_RX_PR_BUMP_SR_1STEP_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t
P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL5_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTLX1_EO_PL_CAL_LANE_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTLX1_EO_PL_PIPE_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTLX1_EO_PL_PIPE_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTLX1_EO_PL_BANK_SEL_A = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTLX1_EO_PL_PIPE_MARGIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTLX1_EO_PL_SCOPE_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTLX1_EO_PL_BIST_PIPE_DATA_SHIFT = 57  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE1_EO_PL_LANE_DIG_PDWN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE1_EO_PL_BER_DPIPE_MUX_SEL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_A = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE1_EO_PL_DECOUPLE_EDGE_B = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE1_EO_PL_PSAVE_DIG_REQ_DIS = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE1_EO_PL_PSAVE_ANA_REQ_DIS = 53  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE2_EO_PL_PR_FW_OFF = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE2_EO_PL_PR_FW_INERTIA_AMT_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE2_EO_PL_PR_PHASE_STEP_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE3_EO_PL_BER_CFG = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE3_EO_PL_BER_CFG_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE3_EO_PL_FIFO_DLY_CFG_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE3_EO_PL_DDC_CFG = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE3_EO_PL_DDC_CFG_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_EN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE4_EO_PL_PR_INVALID_LOCK_COARSE_EN = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE4_EO_PL_PR_FW_INERTIA_AMT_COARSE_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE4_EO_PL_PR_PHASE_STEP_COARSE_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE4_EO_PL_PR_COARSE_MODE_TIMER_SEL_LEN = 2   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT1_EO_PL_RX_PSAVE_MODE_ACTIVE_RO_SIGNAL = 56  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_LEFT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT1_O_PL_RX_PR_RIGHT_EDGE_B_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT1_O_PL_B_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_A_IP_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_B_IP_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_WOBBLE_EDGE_IP_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_DDC_DONE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_DDC_FAILED_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SL_1UI_DONE_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_BUMP_SR_1UI_DONE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT2_EO_PL_RX_PR_TRACE_STOPPED_RO_SIGNAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_LEFT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT3_EO_PL_RX_PR_RIGHT_EDGE_A_RO_SIGNAL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT3_EO_PL_A_PR_DFE_CLKADJ_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_IN_COARSE_MODE_STICKY_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT4_EO_PL_RX_PR_FW_GRAY_CODED_RO_SIGNAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL10_O_PL_E_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_EO_PL_A_BANK_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_EO_PL_LANE_ANA_PDWN = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_EO_PL_PRBS_TEST_DATA_LEN = 3   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS = 58  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_EO_PL_B_BANK_CONTROLS_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_O_PL_B_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_O_PL_B_CONTROLS_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_EO_PL_A_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_EO_PL_A_CONTROLS_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_EO_PL_CM_CNTL = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_EO_PL_CM_CNTL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_O_PL_B_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_EO_PL_A_OFFSET_E1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_O_PL_B_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O0_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1 = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_EO_PL_A_OFFSET_O1_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_O_PL_B_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_O_PL_B_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_O_PL_B_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_EO_PL_A_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_EO_PL_A_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_EO_PL_A_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_O_PL_B_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_COARSE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_EO_PL_A_CTLE_GAIN_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_O_PL_B_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_O_PL_B_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_O_PL_B_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_O_PL_B_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1E_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1E_VAL_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1O_VAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL7_EO_PL_A_H1O_VAL_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL7_O_PL_E_CONTROLS = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL7_O_PL_E_CONTROLS_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL8_EO_PL_AMP_VAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL8_EO_PL_AMP_VAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET_E = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET_E_LEN = 7   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET = 56  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL8_O_PL_E_OFFSET_LEN = 7   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL9_O_PL_E_INTEG_COARSE_GAIN_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL9_O_PL_E_EVEN_INTEG_FINE_GAIN_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN = 57  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL9_O_PL_E_ODD_INTEG_FINE_GAIN_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_0 = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_1 = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_2 = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_3 = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_4 = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_5 = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_6 = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_7 = 55  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC = 60  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_DATA_DAC_SPARE_MODE_PL_CFG_LTE_MC_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_FIR_ERROR_INJECT_PL_ERR_INJ_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_FIR_MASK_PL_ERRS        = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_FIR_MASK_PL_ERRS_LEN    = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3   ;

static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_SPARE_MODE_PL_0         = 48  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_SPARE_MODE_PL_1         = 49  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_SPARE_MODE_PL_2         = 50  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_SPARE_MODE_PL_3         = 51  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_SPARE_MODE_PL_4         = 52  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_SPARE_MODE_PL_5         = 53  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_SPARE_MODE_PL_6         = 54  ;
static const uint8_t P9A_OBUS_RX0_RXPACKS5_SLICE3_RX_SPARE_MODE_PL_7         = 55  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL10_EO_PG_BIST_PRBS_TEST_TIME    = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL10_EO_PG_BIST_PRBS_TEST_TIME_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL10_EO_PG_BIST_BUS_DATA_MODE     = 52  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL10_EO_PG_BIST_PRBS_PROP_TIME    = 53  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL10_EO_PG_BIST_PRBS_PROP_TIME_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL11_EO_PG_DACTEST_LLMT           = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL11_EO_PG_DACTEST_LLMT_LEN       = 9   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL11_EO_PG_DACTEST_RESET          = 57  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL11_EO_PG_DACTEST_START          = 58  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL12_EO_PG_DACTEST_HLMT           = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL12_EO_PG_DACTEST_HLMT_LEN       = 9   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL13_EO_PG_HIST_MIN_EYE_WIDTH_VALID = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL13_EO_PG_HIST_MIN_EYE_WIDTH_LANE = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL13_EO_PG_HIST_MIN_EYE_WIDTH_LANE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL13_EO_PG_HIST_MIN_EYE_WIDTH     = 54  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL13_EO_PG_HIST_MIN_EYE_WIDTH_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL14_EO_PG_HIST_MIN_EYE_HEIGHT_VALID = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL14_EO_PG_HIST_MIN_EYE_HEIGHT_LANE = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL14_EO_PG_HIST_MIN_EYE_HEIGHT_LANE_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL14_EO_PG_HIST_MIN_EYE_HEIGHT    = 54  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL14_EO_PG_HIST_MIN_EYE_HEIGHT_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL1_EO_PG_BER_EN                  = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL1_EO_PG_BER_TIMER_FREEZE_EN     = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL1_EO_PG_BER_COUNT_FREEZE_EN     = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL1_EO_PG_BER_COUNT_SEL           = 51  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL1_EO_PG_BER_COUNT_SEL_LEN       = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL1_EO_PG_BER_TIMER_SEL           = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL1_EO_PG_BER_TIMER_SEL_LEN       = 3   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL1_EO_PG_BER_CLR_COUNT_ON_READ_EN = 59  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL1_EO_PG_BER_CLR_TIMER_ON_READ_EN = 60  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL2_EO_PG_TRC_MODE                = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL2_EO_PG_TRC_MODE_LEN            = 4   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL3_EO_PG_INT_MODE                = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL3_EO_PG_INT_MODE_LEN            = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL3_EO_PG_INT_CURRENT_STATE       = 52  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL3_EO_PG_INT_CURRENT_STATE_LEN   = 12  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL4_EO_PG_INT_ENABLE_ENC          = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL4_EO_PG_INT_ENABLE_ENC_LEN      = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL4_EO_PG_INT_NEXT_STATE          = 52  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL4_EO_PG_INT_NEXT_STATE_LEN      = 12  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL5_EO_PG_INT_GOTO_STATE          = 52  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL5_EO_PG_INT_GOTO_STATE_LEN      = 12  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL6_EO_PG_INT_RETURN_STATE        = 52  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL6_EO_PG_INT_RETURN_STATE_LEN    = 12  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL8_EO_PG_SERVO_OP                = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL8_EO_PG_SERVO_OP_LEN            = 15  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL8_EO_PG_SERVO_DONE              = 63  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL9_EO_PG_BIST_EN                 = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL9_EO_PG_BIST_EXT_START_MODE     = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL9_EO_PG_BIST_INIT_DISABLE       = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL9_EO_PG_BIST_INIT_DISABLE_LEN   = 3   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL9_EO_PG_BIST_CUPLL_LOCK_CHECK_EN = 53  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL9_EO_PG_BIST_STORE_EYES_LANE_SEL = 54  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL9_EO_PG_BIST_STORE_EYES_LANE_SEL_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL9_EO_PG_BIST_STORE_EYES_BANK_SEL = 60  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL9_EO_PG_BIST_STORE_EYES_BANK_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL9_EO_PG_PERVASIVE_CAPT          = 62  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTL9_EO_PG_BIST_LL_TEST_EN         = 63  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTLX7_EO_PG_CAL_LANE_PHY_GCRMSG    = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_CNTLX7_EO_PG_CAL_LANE_PHY_GCRMSG_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE10_EO_PG_AMP_INIT_CFG           = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE10_EO_PG_AMP_INIT_CFG_LEN       = 3   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE10_EO_PG_AMP_RECAL_CFG          = 51  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE10_EO_PG_AMP_RECAL_CFG_LEN      = 3   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE10_EO_PG_PEAK_INIT_CFG          = 54  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE10_EO_PG_PEAK_INIT_CFG_LEN      = 3   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE10_EO_PG_PEAK_RECAL_CFG         = 57  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE10_EO_PG_PEAK_RECAL_CFG_LEN     = 3   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE10_EO_PG_AMP_CFG                = 60  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE10_EO_PG_AMP_CFG_LEN            = 4   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE11_EO_PG_OFF_INIT_CFG           = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE11_EO_PG_OFF_INIT_CFG_LEN       = 3   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE11_EO_PG_OFF_RECAL_CFG          = 51  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE11_EO_PG_OFF_RECAL_CFG_LEN      = 3   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE11_EO_PG_CM_CFG                 = 54  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE11_EO_PG_CM_CFG_LEN             = 3   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE11_EO_PG_AMIN_CFG               = 57  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE11_EO_PG_AMIN_CFG_LEN           = 3   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE11_EO_PG_USERDEF_CFG            = 60  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE11_EO_PG_USERDEF_CFG_LEN        = 4   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE12_EO_PG_SERVO_CHG_CFG          = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE12_EO_PG_SERVO_CHG_CFG_LEN      = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE12_EO_PG_DAC_BO_CFG             = 52  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE12_EO_PG_DAC_BO_CFG_LEN         = 3   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE12_EO_PG_FILTER_MODE            = 55  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE12_EO_PG_FILTER_MODE_LEN        = 2   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE12_EO_PG_MISC_CFG               = 57  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE12_EO_PG_MISC_CFG_LEN           = 2   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE12_EO_PG_DISABLE_H1_CLEAR       = 59  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE12_EO_PG_VOFF_CFG               = 60  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE12_EO_PG_VOFF_CFG_LEN           = 3   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE12_EO_PG_LOFF_AMP_EN            = 63  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE13_EO_PG_CM_OFFSET_VAL          = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE13_EO_PG_CM_OFFSET_VAL_LEN      = 7   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE13_EO_PG_SERVO_THRESH1          = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE13_EO_PG_SERVO_THRESH1_LEN      = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE13_EO_PG_SERVO_THRESH2          = 60  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE13_EO_PG_SERVO_THRESH2_LEN      = 4   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE14_EO_PG_AMP_INIT_TIMEOUT       = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE14_EO_PG_AMP_INIT_TIMEOUT_LEN   = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE14_EO_PG_AMP_RECAL_TIMEOUT      = 52  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE14_EO_PG_AMP_RECAL_TIMEOUT_LEN  = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE14_EO_PG_PEAK_INIT_TIMEOUT      = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE14_EO_PG_PEAK_INIT_TIMEOUT_LEN  = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE14_EO_PG_PEAK_RECAL_TIMEOUT     = 60  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE14_EO_PG_PEAK_RECAL_TIMEOUT_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE15_EO_PG_OFF_INIT_TIMEOUT       = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE15_EO_PG_OFF_INIT_TIMEOUT_LEN   = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE15_EO_PG_OFF_RECAL_TIMEOUT      = 52  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE15_EO_PG_OFF_RECAL_TIMEOUT_LEN  = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE15_EO_PG_CM_TIMEOUT             = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE15_EO_PG_CM_TIMEOUT_LEN         = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE15_EO_PG_AMIN_TIMEOUT           = 60  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE15_EO_PG_AMIN_TIMEOUT_LEN       = 4   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE16_EO_PG_AMP_TIMEOUT            = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE16_EO_PG_AMP_TIMEOUT_LEN        = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE16_EO_PG_USERDEF_TIMEOUT        = 52  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE16_EO_PG_USERDEF_TIMEOUT_LEN    = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE16_EO_PG_BER_TIMEOUT            = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE16_EO_PG_BER_TIMEOUT_LEN        = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE16_EO_PG_SPARE4_TIMEOUT         = 60  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE16_EO_PG_SPARE4_TIMEOUT_LEN     = 4   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE17_EO_PG_AMAX_HIGH              = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE17_EO_PG_AMAX_HIGH_LEN          = 8   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE17_EO_PG_AMAX_LOW               = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE17_EO_PG_AMAX_LOW_LEN           = 8   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE18_EO_PG_AMP0_FILTER_MASK       = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE18_EO_PG_AMP0_FILTER_MASK_LEN   = 8   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE18_EO_PG_AMP1_FILTER_MASK       = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE18_EO_PG_AMP1_FILTER_MASK_LEN   = 8   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE19_EO_PG_CTLE_GAIN_MAX          = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE19_EO_PG_CTLE_GAIN_MAX_LEN      = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE19_EO_PG_AMP_START_VAL          = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE19_EO_PG_AMP_START_VAL_LEN      = 8   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE1_EO_PG_CLKDIST_PDWN            = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE1_EO_PG_CLKDIST_PDWN_LEN        = 3   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE1_EO_PG_BIST_MIN_EYE_WIDTH      = 51  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE1_EO_PG_BIST_MIN_EYE_WIDTH_LEN  = 6   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE1_EO_PG_A_BIST_EN               = 57  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE1_EO_PG_B_BIST_EN               = 58  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE1_EO_PG_E_BIST_EN               = 59  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE1_EO_PG_BISTCLK_EN              = 60  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE1_EO_PG_BISTCLK_EN_LEN          = 2   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE1_EO_PG_DISABLE_BANK_PDWN       = 62  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE1_O_PG_MINIKERF                 = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE1_O_PG_MINIKERF_LEN             = 16  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE20_EO_PG_DFE_CONVERGED_CNT_MAX  = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE20_EO_PG_DFE_CONVERGED_CNT_MAX_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE20_EO_PG_AP110_AP010_DELTA_MAX  = 52  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE20_EO_PG_AP110_AP010_DELTA_MAX_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE21_EO_PG_ENABLE_INTEG_LATCH_OFFSET_CAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE21_EO_PG_ENABLE_CTLE_COARSE_CAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE21_EO_PG_ENABLE_DAC_H1_CAL      = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE21_EO_PG_ENABLE_VGA_CAL         = 51  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE21_EO_PG_ENABLE_DFE_H1_CAL      = 52  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE21_EO_PG_ENABLE_H1AP_TWEAK      = 53  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE21_EO_PG_ENABLE_DDC             = 54  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE21_EO_PG_ENABLE_CM_COARSE_CAL   = 55  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE21_EO_PG_ENABLE_CM_FINE_CAL     = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE21_EO_PG_ENABLE_VGA_EDGE_OFFSET_CAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE21_EO_PG_ENABLE_CTLE_EDGE_OFFSET_CAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE22_EO_PG_RC_ENABLE_INTEG_LATCH_OFFSET_CAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE22_EO_PG_RC_ENABLE_CTLE_COARSE_CAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE22_EO_PG_RC_ENABLE_DAC_H1_CAL   = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE22_EO_PG_RC_ENABLE_VGA_CAL      = 51  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE22_EO_PG_RC_ENABLE_DFE_H1_CAL   = 52  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE22_EO_PG_RC_ENABLE_H1AP_TWEAK   = 53  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE22_EO_PG_RC_ENABLE_DDC          = 54  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE22_EO_PG_RC_ENABLE_CM_COARSE_CAL = 55  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE22_EO_PG_RC_ENABLE_CM_FINE_CAL  = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE22_EO_PG_RC_ENABLE_VGA_EDGE_OFFSET_CAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE22_EO_PG_RC_ENABLE_CTLE_EDGE_OFFSET_CAL = 58  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE23_EO_PG_IREF_RES_DAC           = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE23_EO_PG_IREF_RES_DAC_LEN       = 3   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE23_EO_PG_IREF_BYPASS            = 53  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE23_EO_PG_IREF_PDWN_B            = 54  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE24_EO_PG_H1AP_CFG               = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE24_EO_PG_H1AP_CFG_LEN           = 2   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE24_EO_PG_CTLE_UPDATE_MODE       = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE24_EO_PG_USER_FILTER_MASK       = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE24_EO_PG_USER_FILTER_MASK_LEN   = 8   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE26_EO_PG_ENABLE_CTLE_1ST_LATCH_OFFSET_CAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE26_EO_PG_ENABLE_CTLE_2ND_LATCH_OFFSET_CAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE26_EO_PG_ENABLE_VGA_AMAX_MODE   = 50  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE27_EO_PG_RC_ENABLE_CTLE_1ST_LATCH_OFFSET_CAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE27_EO_PG_RC_ENABLE_CTLE_2ND_LATCH_OFFSET_CAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE27_EO_PG_RC_ENABLE_VGA_AMAX_MODE = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE27_EO_PG_RC_ENABLE_AUTO_RECAL   = 51  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE28_EO_PG_DC_ENABLE_CM_COARSE_CAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE28_EO_PG_DC_ENABLE_CM_FINE_CAL  = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE28_EO_PG_DC_ENABLE_CTLE_1ST_LATCH_OFFSET_CAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE28_EO_PG_DC_ENABLE_CTLE_2ND_LATCH_OFFSET_CAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE28_EO_PG_DC_ENABLE_INTEG_LATCH_OFFSET_CAL = 52  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE29_EO_PG_APX111_HIGH            = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE29_EO_PG_APX111_HIGH_LEN        = 8   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE29_EO_PG_APX111_LOW             = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE29_EO_PG_APX111_LOW_LEN         = 8   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE2_EO_PG_DFE_CA_CFG              = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE2_EO_PG_DFE_CA_CFG_LEN          = 2   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE2_EO_PG_SCOPE_CONTROL           = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE2_EO_PG_SCOPE_CONTROL_LEN       = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE2_EO_PG_RECAL_REQ_DL_MASK       = 54  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE2_EO_PG_RECAL_DONE_DL_MASK      = 55  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE2_EO_PG_RUN_LANE_DL_MASK        = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE2_EO_PG_RECAL_ABORT_DL_MASK     = 57  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE2_EO_PG_INIT_DONE_DL_MASK       = 58  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE2_EO_PG_DATA_PIPE_CLR_ON_READ_MODE = 59  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE2_O_PG_OCTANT_SELECT            = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE2_O_PG_OCTANT_SELECT_LEN        = 3   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE2_O_PG_SPEED_SELECT             = 51  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE2_O_PG_SPEED_SELECT_LEN         = 2   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE2_O_PG_AC_COUPLED               = 53  ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE5_EO_PG_TRACKING_TIMEOUT_SEL    = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE5_EO_PG_TRACKING_TIMEOUT_SEL_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE6_EO_PG_CONVERGED_END_COUNT     = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE6_EO_PG_CONVERGED_END_COUNT_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE6_EO_PG_HIST_MIN_EYE_WIDTH_MODE = 52  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE6_EO_PG_HIST_MIN_EYE_WIDTH_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE6_EO_PG_HIST_MIN_EYE_HEIGHT_MODE = 54  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE6_EO_PG_HIST_MIN_EYE_HEIGHT_MODE_LEN = 2   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE6_EO_PG_AMP_GAIN_CNT_MAX        = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE6_EO_PG_AMP_GAIN_CNT_MAX_LEN    = 4   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE7_EO_PG_ABORT_CHECK_TIMEOUT_SEL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE7_EO_PG_ABORT_CHECK_TIMEOUT_SEL_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE7_EO_PG_POLLING_TIMEOUT_SEL     = 52  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE7_EO_PG_POLLING_TIMEOUT_SEL_LEN = 4   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE9_EO_PG_MIN_EYE_WIDTH           = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE9_EO_PG_MIN_EYE_WIDTH_LEN       = 6   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE9_EO_PG_MIN_EYE_HEIGHT          = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_MODE9_EO_PG_MIN_EYE_HEIGHT_LEN      = 8   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_STAT1_EO_PG_SERVO_RESULT            = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_STAT1_EO_PG_SERVO_RESULT_LEN        = 8   ;

static const uint8_t P9A_OBUS_RX0_RX_CTL_STAT2_EO_PG_BIST_INIT_DONE          = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_STAT2_EO_PG_BIST_DONE               = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_STAT2_EO_PG_BIST_LL_ERR             = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_STAT2_EO_PG_BIST_NO_EDGE_DET        = 51  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_STAT2_EO_PG_BIST_EYE_A_WIDTH        = 52  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_STAT2_EO_PG_BIST_EYE_A_WIDTH_LEN    = 6   ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_STAT2_EO_PG_BIST_EYE_B_WIDTH        = 58  ;
static const uint8_t P9A_OBUS_RX0_RX_CTL_STAT2_EO_PG_BIST_EYE_B_WIDTH_LEN    = 6   ;

static const uint8_t P9A_OBUS_RX0_RX_DATASM_CNTLX1_EO_PG_RX_BER_COUNT_CLR_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_CNTLX1_EO_PG_RX_BER_TIMER_CLR_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_CNTLX1_EO_PG_RX_SCOPE_CAPTURE_WO_PULSE_SLOW_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_CNTLX1_EO_PG_RX_DATA_PIPE_CAPTURE_WO_PULSE_SLOW_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_CNTLX1_EO_PG_RX_RESET_SERVO_STATUS_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_CNTLX1_EO_PG_RX_BER_RESET_WO_PULSE_SLOW_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_RX_DATASM_SPARE_MODE_PG_0                  = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_SPARE_MODE_PG_1                  = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_SPARE_MODE_PG_2                  = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_SPARE_MODE_PG_3                  = 51  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_SPARE_MODE_PG_4                  = 52  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_SPARE_MODE_PG_5                  = 53  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_SPARE_MODE_PG_6                  = 54  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_SPARE_MODE_PG_7                  = 55  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_SPARE_MODE_PG_SERVO_CONFIG       = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_SPARE_MODE_PG_SERVO_CONFIG_LEN   = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_SPARE_MODE_PG_CTL_CLKDIST_PDWN   = 60  ;

static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT10_EO_PG_RX_SCAN_N_16_23_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT10_EO_PG_RX_SCAN_N_16_23_RO_SIGNAL_LEN = 8   ;

static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT11_EO_PG_RX_SCAN_N_0_15_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT11_EO_PG_RX_SCAN_N_0_15_RO_SIGNAL_LEN = 16  ;

static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT1_EO_PG_RX_BER_COUNT_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT1_EO_PG_RX_BER_COUNT_RO_SIGNAL_LEN = 11  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT1_EO_PG_RX_BER_COUNT_SATURATED_RO_SIGNAL = 59  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT1_EO_PG_RX_BER_COUNT_FROZEN_BY_ERR_CNT_RO_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT1_EO_PG_RX_BER_COUNT_FROZEN_BY_TIMER_RO_SIGNAL = 61  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT1_EO_PG_RX_BER_TIMER_SATURATED_RO_SIGNAL = 62  ;

static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT2_EO_PG_RX_BER_TIMER_VALUE_0_15_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT2_EO_PG_RX_BER_TIMER_VALUE_0_15_RO_SIGNAL_LEN = 16  ;

static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT3_EO_PG_RX_BER_TIMER_VALUE_16_31_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT3_EO_PG_RX_BER_TIMER_VALUE_16_31_RO_SIGNAL_LEN = 16  ;

static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT4_EO_PG_RX_DATA_PIPE_0_15_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT4_EO_PG_RX_DATA_PIPE_0_15_RO_SIGNAL_LEN = 16  ;

static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT5_EO_PG_RX_DATA_PIPE_16_31_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT5_EO_PG_RX_DATA_PIPE_16_31_RO_SIGNAL_LEN = 16  ;

static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT6_EO_PG_RX_SERVO_STATUS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT6_EO_PG_RX_SERVO_STATUS_RO_SIGNAL_LEN = 16  ;

static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT7_EO_PG_RX_SERVO_CHG_CNT_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT7_EO_PG_RX_SERVO_CHG_CNT_RO_SIGNAL_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT7_EO_PG_RX_IREF_PARITY_CHK_RO_SIGNAL = 59  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT7_EO_PG_RX_IREF_PARITY_CHK_RO_SIGNAL_LEN = 4   ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT7_EO_PG_RX_PRVCPT_CHANGE_DET_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT8_EO_PG_RX_SCAN_P_0_15_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT8_EO_PG_RX_SCAN_P_0_15_RO_SIGNAL_LEN = 16  ;

static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT9_EO_PG_RX_SCAN_P_16_23_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_DATASM_STAT9_EO_PG_RX_SCAN_P_16_23_RO_SIGNAL_LEN = 9   ;

static const uint8_t P9A_OBUS_RX0_RX_FIR1_ERROR_INJECT_PG_ERR_INJ            = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_FIR1_ERROR_INJECT_PG_ERR_INJ_LEN        = 15  ;

static const uint8_t P9A_OBUS_RX0_RX_FIR1_MASK_PG_ERRS                       = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_FIR1_MASK_PG_ERRS_LEN                   = 15  ;

static const uint8_t P9A_OBUS_RX0_RX_FIR1_PG_RX_PG_FIR_ERR_PG_REGS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_FIR1_PG_RX_PG_FIR_ERR_GCR_BUFF_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_FIR1_PG_RX_PG_FIR_ERR_GCRS_LD_SM_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_FIR1_PG_RX_PG_FIR_ERR_GCRS_UNLD_SM_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RX_FIR1_PG_RX_PG_FIR_ERR_GLBSM_REGS_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_RX_FIR1_PG_RX_PG_FIR_ERR_GLBSM_REGRW_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_RX_FIR1_PG_RX_PG_FIR_ERR_DATASM_REGS_RO_SIGNAL = 54  ;
static const uint8_t P9A_OBUS_RX0_RX_FIR1_PG_RX_PG_FIR_ERR_DATASM_REGRW_RO_SIGNAL = 55  ;
static const uint8_t P9A_OBUS_RX0_RX_FIR1_PG_RX_PG_FIR_ERR_EYEOPT_SM_RO_SIGNAL = 56  ;
static const uint8_t P9A_OBUS_RX0_RX_FIR1_PG_RX_PG_FIR_ERR_BIST_MAIN_STATE_RO_SIGNAL = 57  ;
static const uint8_t P9A_OBUS_RX0_RX_FIR1_PG_RX_PG_FIR_ERR_BIST_INIT_STATE_RO_SIGNAL = 58  ;
static const uint8_t P9A_OBUS_RX0_RX_FIR1_PG_RX_PG_FIR_ERR_RX_SERVO_SM_RO_SIGNAL = 59  ;
static const uint8_t P9A_OBUS_RX0_RX_FIR1_PG_RX_PG_FIR_ERR_WORK_REGS_RO_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_RX0_RX_FIR1_PG_RX_PL_FIR_ERR_RO_SIGNAL         = 62  ;

static const uint8_t P9A_OBUS_RX0_RX_GLBSM_CNTL2_EO_PG_CNT_SINGLE_LANE_RECAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_CNTL2_EO_PG_RECAL_LANE_TO_MONITOR = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_CNTL2_EO_PG_RECAL_LANE_TO_MONITOR_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RX_GLBSM_CNTL3_EO_PG_MANUAL_RECAL_REQUEST  = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_CNTL3_EO_PG_MANUAL_RECAL_LANE     = 51  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_CNTL3_EO_PG_MANUAL_RECAL_LANE_LEN = 5   ;

static const uint8_t P9A_OBUS_RX0_RX_GLBSM_CNTL4_EO_PG_RX_CLR_RECAL_CNT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_CNTL4_EO_PG_RX_INT_RETURN_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_CNTL4_EO_PG_RX_MANUAL_RECAL_ABORT_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_CNTL4_EO_PG_RX_MANUAL_RECAL_CONTINUE_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_RX_GLBSM_CNTLX1_EO_PG_CLR_PAR_ERRS         = 62  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_CNTLX1_EO_PG_FIR_RESET            = 63  ;

static const uint8_t P9A_OBUS_RX0_RX_GLBSM_MODE1_EO_PG_RC_ENABLE_PU_EDGE_TRACK = 48  ;

static const uint8_t P9A_OBUS_RX0_RX_GLBSM_SPARE_MODE_PG_0                   = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_SPARE_MODE_PG_1                   = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_SPARE_MODE_PG_2                   = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_SPARE_MODE_PG_3                   = 51  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_SPARE_MODE_PG_4                   = 52  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_SPARE_MODE_PG_5                   = 53  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_SPARE_MODE_PG_6                   = 54  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_SPARE_MODE_PG_7                   = 55  ;

static const uint8_t P9A_OBUS_RX0_RX_GLBSM_STAT1_EO_PG_RX_EYE_OPT_STATE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_STAT1_EO_PG_RX_EYE_OPT_STATE_RO_SIGNAL_LEN = 12  ;

static const uint8_t P9A_OBUS_RX0_RX_GLBSM_STAT2_EO_PG_RX_RECAL_CNT_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_STAT2_EO_PG_RX_RECAL_CNT_RO_SIGNAL_LEN = 16  ;

static const uint8_t P9A_OBUS_RX0_RX_GLBSM_STAT3_EO_PG_RX_DACTEST_ISGT_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_STAT3_EO_PG_RX_DACTEST_ISLT_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_STAT3_EO_PG_RX_DACTEST_ISEQ_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_STAT3_EO_PG_RX_DACTEST_DIFF_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_STAT3_EO_PG_RX_DACTEST_DIFF_RO_SIGNAL_LEN = 9   ;

static const uint8_t P9A_OBUS_RX0_RX_GLBSM_STAT4_EO_PG_RX_INT_REQ_RO_SIGNAL  = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_STAT4_EO_PG_RX_INT_REQ_RO_SIGNAL_LEN = 16  ;

static const uint8_t P9A_OBUS_RX0_RX_GLBSM_STAT5_EO_PG_RX_LANE_CURRENTLY_INITIALIZING_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_STAT5_EO_PG_RX_LANE_CURRENTLY_RECALIBRATING_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_STAT5_EO_PG_RX_CURRENT_RECAL_INIT_LANE_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_STAT5_EO_PG_RX_CURRENT_RECAL_INIT_LANE_RO_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_RX0_RX_GLBSM_STAT5_EO_PG_RX_MANUAL_RECAL_DONE_RO_SIGNAL = 55  ;

static const uint8_t P9A_OBUS_RX0_RX_ID1_PG_BUS_ID                           = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_ID1_PG_BUS_ID_LEN                       = 6   ;

static const uint8_t P9A_OBUS_RX0_RX_SPARE_MODE_PG_0                         = 48  ;
static const uint8_t P9A_OBUS_RX0_RX_SPARE_MODE_PG_1                         = 49  ;
static const uint8_t P9A_OBUS_RX0_RX_SPARE_MODE_PG_2                         = 50  ;
static const uint8_t P9A_OBUS_RX0_RX_SPARE_MODE_PG_3                         = 51  ;
static const uint8_t P9A_OBUS_RX0_RX_SPARE_MODE_PG_4                         = 52  ;

static const uint8_t P9A_OBUS_RX0_SLICE0_RX_DATA_WORK_SPARE_MODE_PL_0        = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_DATA_WORK_SPARE_MODE_PL_1        = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_DATA_WORK_SPARE_MODE_PL_2        = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_DATA_WORK_SPARE_MODE_PL_3        = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_DATA_WORK_SPARE_MODE_PL_4        = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_DATA_WORK_SPARE_MODE_PL_5        = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_DATA_WORK_SPARE_MODE_PL_6        = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_DATA_WORK_SPARE_MODE_PL_7        = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE0_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE0_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE     = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL    = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ    = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT  = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE0_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE0_RX_WORK_CNTL1_O_PL_REGS_IORESET     = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE0_RX_WORK_STAT1_EO_PL_BIST_ERR_A      = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_WORK_STAT1_EO_PL_BIST_ERR_B      = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_WORK_STAT1_EO_PL_BIST_ERR_E      = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE0_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV  = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_WORK_STAT2_EO_PL_A_AP            = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_WORK_STAT2_EO_PL_A_AP_LEN        = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE0_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE0_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD   = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE0_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE10_RX_DATA_WORK_SPARE_MODE_PL_0       = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_DATA_WORK_SPARE_MODE_PL_1       = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_DATA_WORK_SPARE_MODE_PL_2       = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_DATA_WORK_SPARE_MODE_PL_3       = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_DATA_WORK_SPARE_MODE_PL_4       = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_DATA_WORK_SPARE_MODE_PL_5       = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_DATA_WORK_SPARE_MODE_PL_6       = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_DATA_WORK_SPARE_MODE_PL_7       = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE10_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE10_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE    = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL   = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ   = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE10_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE10_RX_WORK_CNTL1_O_PL_REGS_IORESET    = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE10_RX_WORK_STAT1_EO_PL_BIST_ERR_A     = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_WORK_STAT1_EO_PL_BIST_ERR_B     = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_WORK_STAT1_EO_PL_BIST_ERR_E     = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE10_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_WORK_STAT2_EO_PL_A_AP           = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_WORK_STAT2_EO_PL_A_AP_LEN       = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE10_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE10_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE10_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE11_RX_DATA_WORK_SPARE_MODE_PL_0       = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_DATA_WORK_SPARE_MODE_PL_1       = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_DATA_WORK_SPARE_MODE_PL_2       = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_DATA_WORK_SPARE_MODE_PL_3       = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_DATA_WORK_SPARE_MODE_PL_4       = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_DATA_WORK_SPARE_MODE_PL_5       = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_DATA_WORK_SPARE_MODE_PL_6       = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_DATA_WORK_SPARE_MODE_PL_7       = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE11_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE11_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE    = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL   = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ   = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE11_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE11_RX_WORK_CNTL1_O_PL_REGS_IORESET    = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE11_RX_WORK_STAT1_EO_PL_BIST_ERR_A     = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_WORK_STAT1_EO_PL_BIST_ERR_B     = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_WORK_STAT1_EO_PL_BIST_ERR_E     = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE11_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_WORK_STAT2_EO_PL_A_AP           = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_WORK_STAT2_EO_PL_A_AP_LEN       = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE11_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE11_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE11_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE12_RX_DATA_WORK_SPARE_MODE_PL_0       = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_DATA_WORK_SPARE_MODE_PL_1       = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_DATA_WORK_SPARE_MODE_PL_2       = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_DATA_WORK_SPARE_MODE_PL_3       = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_DATA_WORK_SPARE_MODE_PL_4       = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_DATA_WORK_SPARE_MODE_PL_5       = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_DATA_WORK_SPARE_MODE_PL_6       = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_DATA_WORK_SPARE_MODE_PL_7       = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE12_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE12_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE    = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL   = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ   = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE12_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE12_RX_WORK_CNTL1_O_PL_REGS_IORESET    = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE12_RX_WORK_STAT1_EO_PL_BIST_ERR_A     = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_WORK_STAT1_EO_PL_BIST_ERR_B     = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_WORK_STAT1_EO_PL_BIST_ERR_E     = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE12_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_WORK_STAT2_EO_PL_A_AP           = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_WORK_STAT2_EO_PL_A_AP_LEN       = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE12_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE12_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE12_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE13_RX_DATA_WORK_SPARE_MODE_PL_0       = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_DATA_WORK_SPARE_MODE_PL_1       = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_DATA_WORK_SPARE_MODE_PL_2       = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_DATA_WORK_SPARE_MODE_PL_3       = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_DATA_WORK_SPARE_MODE_PL_4       = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_DATA_WORK_SPARE_MODE_PL_5       = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_DATA_WORK_SPARE_MODE_PL_6       = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_DATA_WORK_SPARE_MODE_PL_7       = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE13_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE13_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE    = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL   = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ   = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE13_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE13_RX_WORK_CNTL1_O_PL_REGS_IORESET    = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE13_RX_WORK_STAT1_EO_PL_BIST_ERR_A     = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_WORK_STAT1_EO_PL_BIST_ERR_B     = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_WORK_STAT1_EO_PL_BIST_ERR_E     = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE13_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_WORK_STAT2_EO_PL_A_AP           = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_WORK_STAT2_EO_PL_A_AP_LEN       = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE13_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE13_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE13_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE14_RX_DATA_WORK_SPARE_MODE_PL_0       = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_DATA_WORK_SPARE_MODE_PL_1       = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_DATA_WORK_SPARE_MODE_PL_2       = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_DATA_WORK_SPARE_MODE_PL_3       = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_DATA_WORK_SPARE_MODE_PL_4       = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_DATA_WORK_SPARE_MODE_PL_5       = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_DATA_WORK_SPARE_MODE_PL_6       = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_DATA_WORK_SPARE_MODE_PL_7       = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE14_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE14_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE    = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL   = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ   = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE14_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE14_RX_WORK_CNTL1_O_PL_REGS_IORESET    = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE14_RX_WORK_STAT1_EO_PL_BIST_ERR_A     = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_WORK_STAT1_EO_PL_BIST_ERR_B     = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_WORK_STAT1_EO_PL_BIST_ERR_E     = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE14_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_WORK_STAT2_EO_PL_A_AP           = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_WORK_STAT2_EO_PL_A_AP_LEN       = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE14_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE14_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE14_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE15_RX_DATA_WORK_SPARE_MODE_PL_0       = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_DATA_WORK_SPARE_MODE_PL_1       = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_DATA_WORK_SPARE_MODE_PL_2       = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_DATA_WORK_SPARE_MODE_PL_3       = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_DATA_WORK_SPARE_MODE_PL_4       = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_DATA_WORK_SPARE_MODE_PL_5       = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_DATA_WORK_SPARE_MODE_PL_6       = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_DATA_WORK_SPARE_MODE_PL_7       = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE15_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE15_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE    = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL   = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ   = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE15_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE15_RX_WORK_CNTL1_O_PL_REGS_IORESET    = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE15_RX_WORK_STAT1_EO_PL_BIST_ERR_A     = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_WORK_STAT1_EO_PL_BIST_ERR_B     = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_WORK_STAT1_EO_PL_BIST_ERR_E     = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE15_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_WORK_STAT2_EO_PL_A_AP           = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_WORK_STAT2_EO_PL_A_AP_LEN       = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE15_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE15_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE15_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE16_RX_DATA_WORK_SPARE_MODE_PL_0       = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_DATA_WORK_SPARE_MODE_PL_1       = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_DATA_WORK_SPARE_MODE_PL_2       = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_DATA_WORK_SPARE_MODE_PL_3       = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_DATA_WORK_SPARE_MODE_PL_4       = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_DATA_WORK_SPARE_MODE_PL_5       = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_DATA_WORK_SPARE_MODE_PL_6       = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_DATA_WORK_SPARE_MODE_PL_7       = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE16_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE16_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE    = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL   = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ   = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE16_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE16_RX_WORK_CNTL1_O_PL_REGS_IORESET    = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE16_RX_WORK_STAT1_EO_PL_BIST_ERR_A     = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_WORK_STAT1_EO_PL_BIST_ERR_B     = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_WORK_STAT1_EO_PL_BIST_ERR_E     = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE16_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_WORK_STAT2_EO_PL_A_AP           = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_WORK_STAT2_EO_PL_A_AP_LEN       = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE16_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE16_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE16_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE17_RX_DATA_WORK_SPARE_MODE_PL_0       = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_DATA_WORK_SPARE_MODE_PL_1       = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_DATA_WORK_SPARE_MODE_PL_2       = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_DATA_WORK_SPARE_MODE_PL_3       = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_DATA_WORK_SPARE_MODE_PL_4       = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_DATA_WORK_SPARE_MODE_PL_5       = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_DATA_WORK_SPARE_MODE_PL_6       = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_DATA_WORK_SPARE_MODE_PL_7       = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE17_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE17_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE    = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL   = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ   = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE17_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE17_RX_WORK_CNTL1_O_PL_REGS_IORESET    = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE17_RX_WORK_STAT1_EO_PL_BIST_ERR_A     = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_WORK_STAT1_EO_PL_BIST_ERR_B     = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_WORK_STAT1_EO_PL_BIST_ERR_E     = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE17_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_WORK_STAT2_EO_PL_A_AP           = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_WORK_STAT2_EO_PL_A_AP_LEN       = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE17_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE17_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE17_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE18_RX_DATA_WORK_SPARE_MODE_PL_0       = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_DATA_WORK_SPARE_MODE_PL_1       = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_DATA_WORK_SPARE_MODE_PL_2       = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_DATA_WORK_SPARE_MODE_PL_3       = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_DATA_WORK_SPARE_MODE_PL_4       = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_DATA_WORK_SPARE_MODE_PL_5       = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_DATA_WORK_SPARE_MODE_PL_6       = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_DATA_WORK_SPARE_MODE_PL_7       = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE18_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE18_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE    = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL   = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ   = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE18_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE18_RX_WORK_CNTL1_O_PL_REGS_IORESET    = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE18_RX_WORK_STAT1_EO_PL_BIST_ERR_A     = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_WORK_STAT1_EO_PL_BIST_ERR_B     = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_WORK_STAT1_EO_PL_BIST_ERR_E     = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE18_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_WORK_STAT2_EO_PL_A_AP           = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_WORK_STAT2_EO_PL_A_AP_LEN       = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE18_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE18_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE18_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE19_RX_DATA_WORK_SPARE_MODE_PL_0       = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_DATA_WORK_SPARE_MODE_PL_1       = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_DATA_WORK_SPARE_MODE_PL_2       = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_DATA_WORK_SPARE_MODE_PL_3       = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_DATA_WORK_SPARE_MODE_PL_4       = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_DATA_WORK_SPARE_MODE_PL_5       = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_DATA_WORK_SPARE_MODE_PL_6       = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_DATA_WORK_SPARE_MODE_PL_7       = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE19_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE19_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE    = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL   = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ   = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE19_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE19_RX_WORK_CNTL1_O_PL_REGS_IORESET    = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE19_RX_WORK_STAT1_EO_PL_BIST_ERR_A     = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_WORK_STAT1_EO_PL_BIST_ERR_B     = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_WORK_STAT1_EO_PL_BIST_ERR_E     = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE19_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_WORK_STAT2_EO_PL_A_AP           = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_WORK_STAT2_EO_PL_A_AP_LEN       = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE19_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE19_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE19_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE1_RX_DATA_WORK_SPARE_MODE_PL_0        = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_DATA_WORK_SPARE_MODE_PL_1        = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_DATA_WORK_SPARE_MODE_PL_2        = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_DATA_WORK_SPARE_MODE_PL_3        = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_DATA_WORK_SPARE_MODE_PL_4        = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_DATA_WORK_SPARE_MODE_PL_5        = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_DATA_WORK_SPARE_MODE_PL_6        = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_DATA_WORK_SPARE_MODE_PL_7        = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE1_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE1_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE     = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL    = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ    = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT  = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE1_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE1_RX_WORK_CNTL1_O_PL_REGS_IORESET     = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE1_RX_WORK_STAT1_EO_PL_BIST_ERR_A      = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_WORK_STAT1_EO_PL_BIST_ERR_B      = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_WORK_STAT1_EO_PL_BIST_ERR_E      = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE1_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV  = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_WORK_STAT2_EO_PL_A_AP            = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_WORK_STAT2_EO_PL_A_AP_LEN        = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE1_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE1_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD   = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE1_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE20_RX_DATA_WORK_SPARE_MODE_PL_0       = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_DATA_WORK_SPARE_MODE_PL_1       = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_DATA_WORK_SPARE_MODE_PL_2       = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_DATA_WORK_SPARE_MODE_PL_3       = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_DATA_WORK_SPARE_MODE_PL_4       = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_DATA_WORK_SPARE_MODE_PL_5       = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_DATA_WORK_SPARE_MODE_PL_6       = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_DATA_WORK_SPARE_MODE_PL_7       = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE20_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE20_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE    = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL   = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ   = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE20_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE20_RX_WORK_CNTL1_O_PL_REGS_IORESET    = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE20_RX_WORK_STAT1_EO_PL_BIST_ERR_A     = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_WORK_STAT1_EO_PL_BIST_ERR_B     = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_WORK_STAT1_EO_PL_BIST_ERR_E     = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE20_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_WORK_STAT2_EO_PL_A_AP           = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_WORK_STAT2_EO_PL_A_AP_LEN       = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE20_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE20_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE20_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE21_RX_DATA_WORK_SPARE_MODE_PL_0       = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_DATA_WORK_SPARE_MODE_PL_1       = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_DATA_WORK_SPARE_MODE_PL_2       = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_DATA_WORK_SPARE_MODE_PL_3       = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_DATA_WORK_SPARE_MODE_PL_4       = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_DATA_WORK_SPARE_MODE_PL_5       = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_DATA_WORK_SPARE_MODE_PL_6       = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_DATA_WORK_SPARE_MODE_PL_7       = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE21_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE21_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE    = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL   = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ   = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE21_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE21_RX_WORK_CNTL1_O_PL_REGS_IORESET    = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE21_RX_WORK_STAT1_EO_PL_BIST_ERR_A     = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_WORK_STAT1_EO_PL_BIST_ERR_B     = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_WORK_STAT1_EO_PL_BIST_ERR_E     = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE21_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_WORK_STAT2_EO_PL_A_AP           = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_WORK_STAT2_EO_PL_A_AP_LEN       = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE21_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE21_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE21_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE22_RX_DATA_WORK_SPARE_MODE_PL_0       = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_DATA_WORK_SPARE_MODE_PL_1       = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_DATA_WORK_SPARE_MODE_PL_2       = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_DATA_WORK_SPARE_MODE_PL_3       = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_DATA_WORK_SPARE_MODE_PL_4       = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_DATA_WORK_SPARE_MODE_PL_5       = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_DATA_WORK_SPARE_MODE_PL_6       = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_DATA_WORK_SPARE_MODE_PL_7       = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE22_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE22_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE    = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL   = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ   = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE22_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE22_RX_WORK_CNTL1_O_PL_REGS_IORESET    = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE22_RX_WORK_STAT1_EO_PL_BIST_ERR_A     = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_WORK_STAT1_EO_PL_BIST_ERR_B     = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_WORK_STAT1_EO_PL_BIST_ERR_E     = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE22_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_WORK_STAT2_EO_PL_A_AP           = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_WORK_STAT2_EO_PL_A_AP_LEN       = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE22_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE22_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE22_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE23_RX_DATA_WORK_SPARE_MODE_PL_0       = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_DATA_WORK_SPARE_MODE_PL_1       = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_DATA_WORK_SPARE_MODE_PL_2       = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_DATA_WORK_SPARE_MODE_PL_3       = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_DATA_WORK_SPARE_MODE_PL_4       = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_DATA_WORK_SPARE_MODE_PL_5       = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_DATA_WORK_SPARE_MODE_PL_6       = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_DATA_WORK_SPARE_MODE_PL_7       = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE23_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE23_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE    = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL   = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ   = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE23_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE23_RX_WORK_CNTL1_O_PL_REGS_IORESET    = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE23_RX_WORK_STAT1_EO_PL_BIST_ERR_A     = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_WORK_STAT1_EO_PL_BIST_ERR_B     = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_WORK_STAT1_EO_PL_BIST_ERR_E     = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE23_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_WORK_STAT2_EO_PL_A_AP           = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_WORK_STAT2_EO_PL_A_AP_LEN       = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE23_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE23_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE23_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE2_RX_DATA_WORK_SPARE_MODE_PL_0        = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_DATA_WORK_SPARE_MODE_PL_1        = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_DATA_WORK_SPARE_MODE_PL_2        = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_DATA_WORK_SPARE_MODE_PL_3        = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_DATA_WORK_SPARE_MODE_PL_4        = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_DATA_WORK_SPARE_MODE_PL_5        = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_DATA_WORK_SPARE_MODE_PL_6        = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_DATA_WORK_SPARE_MODE_PL_7        = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE2_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE2_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE     = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL    = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ    = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT  = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE2_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE2_RX_WORK_CNTL1_O_PL_REGS_IORESET     = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE2_RX_WORK_STAT1_EO_PL_BIST_ERR_A      = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_WORK_STAT1_EO_PL_BIST_ERR_B      = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_WORK_STAT1_EO_PL_BIST_ERR_E      = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE2_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV  = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_WORK_STAT2_EO_PL_A_AP            = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_WORK_STAT2_EO_PL_A_AP_LEN        = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE2_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE2_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD   = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE2_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE3_RX_DATA_WORK_SPARE_MODE_PL_0        = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_DATA_WORK_SPARE_MODE_PL_1        = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_DATA_WORK_SPARE_MODE_PL_2        = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_DATA_WORK_SPARE_MODE_PL_3        = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_DATA_WORK_SPARE_MODE_PL_4        = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_DATA_WORK_SPARE_MODE_PL_5        = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_DATA_WORK_SPARE_MODE_PL_6        = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_DATA_WORK_SPARE_MODE_PL_7        = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE3_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE3_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE     = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL    = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ    = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT  = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE3_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE3_RX_WORK_CNTL1_O_PL_REGS_IORESET     = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE3_RX_WORK_STAT1_EO_PL_BIST_ERR_A      = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_WORK_STAT1_EO_PL_BIST_ERR_B      = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_WORK_STAT1_EO_PL_BIST_ERR_E      = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE3_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV  = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_WORK_STAT2_EO_PL_A_AP            = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_WORK_STAT2_EO_PL_A_AP_LEN        = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE3_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE3_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD   = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE3_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE4_RX_DATA_WORK_SPARE_MODE_PL_0        = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_DATA_WORK_SPARE_MODE_PL_1        = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_DATA_WORK_SPARE_MODE_PL_2        = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_DATA_WORK_SPARE_MODE_PL_3        = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_DATA_WORK_SPARE_MODE_PL_4        = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_DATA_WORK_SPARE_MODE_PL_5        = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_DATA_WORK_SPARE_MODE_PL_6        = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_DATA_WORK_SPARE_MODE_PL_7        = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE4_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE4_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE     = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL    = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ    = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT  = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE4_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE4_RX_WORK_CNTL1_O_PL_REGS_IORESET     = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE4_RX_WORK_STAT1_EO_PL_BIST_ERR_A      = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_WORK_STAT1_EO_PL_BIST_ERR_B      = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_WORK_STAT1_EO_PL_BIST_ERR_E      = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE4_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV  = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_WORK_STAT2_EO_PL_A_AP            = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_WORK_STAT2_EO_PL_A_AP_LEN        = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE4_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE4_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD   = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE4_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE5_RX_DATA_WORK_SPARE_MODE_PL_0        = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_DATA_WORK_SPARE_MODE_PL_1        = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_DATA_WORK_SPARE_MODE_PL_2        = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_DATA_WORK_SPARE_MODE_PL_3        = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_DATA_WORK_SPARE_MODE_PL_4        = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_DATA_WORK_SPARE_MODE_PL_5        = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_DATA_WORK_SPARE_MODE_PL_6        = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_DATA_WORK_SPARE_MODE_PL_7        = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE5_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE5_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE     = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL    = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ    = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT  = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE5_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE5_RX_WORK_CNTL1_O_PL_REGS_IORESET     = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE5_RX_WORK_STAT1_EO_PL_BIST_ERR_A      = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_WORK_STAT1_EO_PL_BIST_ERR_B      = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_WORK_STAT1_EO_PL_BIST_ERR_E      = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE5_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV  = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_WORK_STAT2_EO_PL_A_AP            = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_WORK_STAT2_EO_PL_A_AP_LEN        = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE5_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE5_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD   = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE5_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE6_RX_DATA_WORK_SPARE_MODE_PL_0        = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_DATA_WORK_SPARE_MODE_PL_1        = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_DATA_WORK_SPARE_MODE_PL_2        = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_DATA_WORK_SPARE_MODE_PL_3        = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_DATA_WORK_SPARE_MODE_PL_4        = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_DATA_WORK_SPARE_MODE_PL_5        = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_DATA_WORK_SPARE_MODE_PL_6        = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_DATA_WORK_SPARE_MODE_PL_7        = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE6_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE6_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE     = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL    = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ    = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT  = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE6_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE6_RX_WORK_CNTL1_O_PL_REGS_IORESET     = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE6_RX_WORK_STAT1_EO_PL_BIST_ERR_A      = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_WORK_STAT1_EO_PL_BIST_ERR_B      = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_WORK_STAT1_EO_PL_BIST_ERR_E      = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE6_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV  = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_WORK_STAT2_EO_PL_A_AP            = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_WORK_STAT2_EO_PL_A_AP_LEN        = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE6_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE6_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD   = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE6_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE7_RX_DATA_WORK_SPARE_MODE_PL_0        = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_DATA_WORK_SPARE_MODE_PL_1        = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_DATA_WORK_SPARE_MODE_PL_2        = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_DATA_WORK_SPARE_MODE_PL_3        = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_DATA_WORK_SPARE_MODE_PL_4        = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_DATA_WORK_SPARE_MODE_PL_5        = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_DATA_WORK_SPARE_MODE_PL_6        = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_DATA_WORK_SPARE_MODE_PL_7        = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE7_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE7_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE     = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL    = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ    = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT  = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE7_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE7_RX_WORK_CNTL1_O_PL_REGS_IORESET     = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE7_RX_WORK_STAT1_EO_PL_BIST_ERR_A      = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_WORK_STAT1_EO_PL_BIST_ERR_B      = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_WORK_STAT1_EO_PL_BIST_ERR_E      = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE7_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV  = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_WORK_STAT2_EO_PL_A_AP            = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_WORK_STAT2_EO_PL_A_AP_LEN        = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE7_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE7_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD   = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE7_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE8_RX_DATA_WORK_SPARE_MODE_PL_0        = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_DATA_WORK_SPARE_MODE_PL_1        = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_DATA_WORK_SPARE_MODE_PL_2        = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_DATA_WORK_SPARE_MODE_PL_3        = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_DATA_WORK_SPARE_MODE_PL_4        = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_DATA_WORK_SPARE_MODE_PL_5        = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_DATA_WORK_SPARE_MODE_PL_6        = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_DATA_WORK_SPARE_MODE_PL_7        = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE8_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE8_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE     = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL    = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ    = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT  = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE8_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE8_RX_WORK_CNTL1_O_PL_REGS_IORESET     = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE8_RX_WORK_STAT1_EO_PL_BIST_ERR_A      = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_WORK_STAT1_EO_PL_BIST_ERR_B      = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_WORK_STAT1_EO_PL_BIST_ERR_E      = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE8_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV  = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_WORK_STAT2_EO_PL_A_AP            = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_WORK_STAT2_EO_PL_A_AP_LEN        = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE8_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE8_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD   = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE8_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE9_RX_DATA_WORK_SPARE_MODE_PL_0        = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_DATA_WORK_SPARE_MODE_PL_1        = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_DATA_WORK_SPARE_MODE_PL_2        = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_DATA_WORK_SPARE_MODE_PL_3        = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_DATA_WORK_SPARE_MODE_PL_4        = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_DATA_WORK_SPARE_MODE_PL_5        = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_DATA_WORK_SPARE_MODE_PL_6        = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_DATA_WORK_SPARE_MODE_PL_7        = 55  ;

static const uint8_t P9A_OBUS_RX0_SLICE9_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_LANE_WO_PULSE_SLOW_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_GLBSM_PL_CNTL1X_O_PL_RX_SET_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_GLBSM_PL_CNTL1X_O_PL_RX_CLR_RUN_DCCAL_WO_PULSE_SLOW_SIGNAL = 51  ;

static const uint8_t P9A_OBUS_RX0_SLICE9_RX_GLBSM_PL_CNTL1_O_PL_RUN_LANE     = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_GLBSM_PL_CNTL1_O_PL_RUN_DCCAL    = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_GLBSM_PL_CNTL1_O_PL_RECAL_REQ    = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_GLBSM_PL_CNTL1_O_PL_RECAL_ABORT  = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_GLBSM_PL_CNTL1_O_PL_LANE_DISABLED = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_GLBSM_PL_CNTL1_O_PL_FORCE_INIT_DONE = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_GLBSM_PL_CNTL1_O_PL_FORCE_RECAL_DONE = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE9_RX_GLBSM_PL_STAT1_O_PL_RX_INIT_DONE_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_GLBSM_PL_STAT1_O_PL_RX_DCCAL_DONE_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_GLBSM_PL_STAT1_O_PL_RX_LANE_BUSY_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_DONE_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_GLBSM_PL_STAT1_O_PL_RX_RUN_LANE_ACTIVE_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_REQ_ACTIVE_RO_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_GLBSM_PL_STAT1_O_PL_RX_RECAL_ABORT_ACTIVE_RO_SIGNAL = 54  ;

static const uint8_t P9A_OBUS_RX0_SLICE9_RX_WORK_CNTL1_O_PL_REGS_IORESET     = 48  ;

static const uint8_t P9A_OBUS_RX0_SLICE9_RX_WORK_STAT1_EO_PL_BIST_ERR_A      = 61  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_WORK_STAT1_EO_PL_BIST_ERR_B      = 62  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_WORK_STAT1_EO_PL_BIST_ERR_E      = 63  ;

static const uint8_t P9A_OBUS_RX0_SLICE9_RX_WORK_STAT2_EO_PL_A_BAD_DFE_CONV  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_WORK_STAT2_EO_PL_B_BAD_DFE_CONV  = 49  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_WORK_STAT2_EO_PL_A_H1AP_AT_LIMIT = 50  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_WORK_STAT2_EO_PL_B_H1AP_AT_LIMIT = 51  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_WORK_STAT2_EO_PL_A_AP            = 52  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_WORK_STAT2_EO_PL_A_AP_LEN        = 8   ;

static const uint8_t P9A_OBUS_RX0_SLICE9_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_WORK_STAT3_EO_PL_A_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD  = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_WORK_STAT3_EO_PL_A_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX0_SLICE9_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN  = 48  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_WORK_STAT4_O_PL_B_PATH_OFF_EVEN_LEN = 6   ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD   = 54  ;
static const uint8_t P9A_OBUS_RX0_SLICE9_RX_WORK_STAT4_O_PL_B_PATH_OFF_ODD_LEN = 6   ;

static const uint8_t P9A_OBUS_RX_FIR_ERROR_INJECT_PB_ERRS_INJ                = 48  ;
static const uint8_t P9A_OBUS_RX_FIR_ERROR_INJECT_PB_ERRS_INJ_LEN            = 10  ;

static const uint8_t P9A_OBUS_RX_FIR_MASK_PB_ERRS                            = 48  ;
static const uint8_t P9A_OBUS_RX_FIR_MASK_PB_ERRS_LEN                        = 10  ;

static const uint8_t P9A_OBUS_RX_FIR_PB_RX_PB_FIR_ERRS_RO_SIGNAL             = 48  ;
static const uint8_t P9A_OBUS_RX_FIR_PB_RX_PB_FIR_ERRS_RO_SIGNAL_LEN         = 10  ;

static const uint8_t P9A_OBUS_RX_FIR_RESET_PB_CLR_PAR_ERRS                   = 62  ;
static const uint8_t P9A_OBUS_RX_FIR_RESET_PB_RESET                          = 63  ;

static const uint8_t P9A_OBUS_SCOM_MODE_PB_GCR_TEST                          = 0   ;
static const uint8_t P9A_OBUS_SCOM_MODE_PB_ENABLE_GCR_OFL_BUFF               = 1   ;
static const uint8_t P9A_OBUS_SCOM_MODE_PB_IORESET_HARD_BUS0                 = 2   ;
static const uint8_t P9A_OBUS_SCOM_MODE_PB_MMIO_PG_REG_ACCESS                = 3   ;
static const uint8_t P9A_OBUS_SCOM_MODE_PB_SPARES1                           = 4   ;
static const uint8_t P9A_OBUS_SCOM_MODE_PB_SPARES1_LEN                       = 4   ;
static const uint8_t P9A_OBUS_SCOM_MODE_PB_GCR_HANG_DET_SEL                  = 8   ;
static const uint8_t P9A_OBUS_SCOM_MODE_PB_GCR_HANG_DET_SEL_LEN              = 3   ;
static const uint8_t P9A_OBUS_SCOM_MODE_PB_GCR_BUFFER_ENABLED_RO_SIGNAL      = 11  ;
static const uint8_t P9A_OBUS_SCOM_MODE_PB_GCR_HANG_ERROR_MASK               = 12  ;
static const uint8_t P9A_OBUS_SCOM_MODE_PB_GCR_HANG_ERROR_INJ                = 13  ;
static const uint8_t P9A_OBUS_SCOM_MODE_PB_PPE_GCR                           = 14  ;
static const uint8_t P9A_OBUS_SCOM_MODE_PB_CHAN_FAIL_MASK                    = 15  ;
static const uint8_t P9A_OBUS_SCOM_MODE_PB_CHAN_FAIL_MASK_LEN                = 8   ;
static const uint8_t P9A_OBUS_SCOM_MODE_PB_SPARES2                           = 23  ;
static const uint8_t P9A_OBUS_SCOM_MODE_PB_SPARES2_LEN                       = 8   ;

static const uint8_t P9A_OBUS_SCOM_PPE_CNTL_IORESET                          = 0   ;
static const uint8_t P9A_OBUS_SCOM_PPE_CNTL_PDWN                             = 1   ;
static const uint8_t P9A_OBUS_SCOM_PPE_CNTL_INTERRUPT                        = 2   ;
static const uint8_t P9A_OBUS_SCOM_PPE_CNTL_ARB_ECC_INJECT_ERR               = 3   ;
static const uint8_t P9A_OBUS_SCOM_PPE_CNTL_SPARES                           = 4   ;
static const uint8_t P9A_OBUS_SCOM_PPE_CNTL_SPARES_LEN                       = 12  ;

static const uint8_t P9A_OBUS_SCOM_PPE_FLAGS_FIELD                           = 0   ;
static const uint8_t P9A_OBUS_SCOM_PPE_FLAGS_FIELD_LEN                       = 16  ;

static const uint8_t P9A_OBUS_SCOM_PPE_WORK_REG1_WORK1                       = 0   ;
static const uint8_t P9A_OBUS_SCOM_PPE_WORK_REG1_WORK1_LEN                   = 32  ;

static const uint8_t P9A_OBUS_SCOM_PPE_WORK_REG2_WORK2                       = 0   ;
static const uint8_t P9A_OBUS_SCOM_PPE_WORK_REG2_WORK2_LEN                   = 32  ;

static const uint8_t P9A_OBUS_SPARE_MODE_PB_0                                = 48  ;
static const uint8_t P9A_OBUS_SPARE_MODE_PB_1                                = 49  ;
static const uint8_t P9A_OBUS_SPARE_MODE_PB_2                                = 50  ;
static const uint8_t P9A_OBUS_SPARE_MODE_PB_3                                = 51  ;
static const uint8_t P9A_OBUS_SPARE_MODE_PB_4                                = 52  ;
static const uint8_t P9A_OBUS_SPARE_MODE_PB_5                                = 53  ;
static const uint8_t P9A_OBUS_SPARE_MODE_PB_6                                = 54  ;
static const uint8_t P9A_OBUS_SPARE_MODE_PB_7                                = 55  ;

static const uint8_t P9A_OBUS_TCOB0_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR = 0   ;
static const uint8_t P9A_OBUS_TCOB0_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN = 16  ;
static const uint8_t P9A_OBUS_TCOB0_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR = 16  ;
static const uint8_t P9A_OBUS_TCOB0_ADDR_TRAP_REG_RESERVED_LAST_LT           = 17  ;
static const uint8_t P9A_OBUS_TCOB0_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR = 18  ;
static const uint8_t P9A_OBUS_TCOB0_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN = 13  ;
static const uint8_t P9A_OBUS_TCOB0_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY = 31  ;
static const uint8_t P9A_OBUS_TCOB0_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR = 32  ;
static const uint8_t P9A_OBUS_TCOB0_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION = 33  ;
static const uint8_t P9A_OBUS_TCOB0_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER = 34  ;

static const uint8_t P9A_OBUS_TCOB0_ATOMIC_LOCK_MASK_LATCH_REG_MASK          = 0   ;
static const uint8_t P9A_OBUS_TCOB0_ATOMIC_LOCK_MASK_LATCH_REG_MASK_LEN      = 16  ;

static const uint8_t P9A_OBUS_TCOB0_BIST_TC_START_TEST_DC                    = 0   ;
static const uint8_t P9A_OBUS_TCOB0_BIST_TC_SRAM_ABIST_MODE_DC               = 1   ;
static const uint8_t P9A_OBUS_TCOB0_BIST_TC_EDRAM_ABIST_MODE_DC              = 2   ;
static const uint8_t P9A_OBUS_TCOB0_BIST_TC_IOBIST_MODE_DC                   = 3   ;
static const uint8_t P9A_OBUS_TCOB0_BIST_PERV                                = 4   ;
static const uint8_t P9A_OBUS_TCOB0_BIST_UNIT1                               = 5   ;
static const uint8_t P9A_OBUS_TCOB0_BIST_UNIT2                               = 6   ;
static const uint8_t P9A_OBUS_TCOB0_BIST_UNIT3                               = 7   ;
static const uint8_t P9A_OBUS_TCOB0_BIST_UNIT4                               = 8   ;
static const uint8_t P9A_OBUS_TCOB0_BIST_UNIT5                               = 9   ;
static const uint8_t P9A_OBUS_TCOB0_BIST_UNIT6                               = 10  ;
static const uint8_t P9A_OBUS_TCOB0_BIST_UNIT7                               = 11  ;
static const uint8_t P9A_OBUS_TCOB0_BIST_UNIT8                               = 12  ;
static const uint8_t P9A_OBUS_TCOB0_BIST_UNIT9                               = 13  ;
static const uint8_t P9A_OBUS_TCOB0_BIST_UNIT10                              = 14  ;
static const uint8_t P9A_OBUS_TCOB0_BIST_STROBE_WINDOW_EN                    = 48  ;

static const uint8_t P9A_OBUS_TCOB0_CC_ATOMIC_LOCK_REG_ENABLE                = 0   ;
static const uint8_t P9A_OBUS_TCOB0_CC_ATOMIC_LOCK_REG_ID                    = 1   ;
static const uint8_t P9A_OBUS_TCOB0_CC_ATOMIC_LOCK_REG_ID_LEN                = 4   ;
static const uint8_t P9A_OBUS_TCOB0_CC_ATOMIC_LOCK_REG_ACTIVITY              = 8   ;
static const uint8_t P9A_OBUS_TCOB0_CC_ATOMIC_LOCK_REG_ACTIVITY_LEN          = 8   ;

static const uint8_t P9A_OBUS_TCOB0_CC_PROTECT_MODE_REG_READ_ENABLE          = 0   ;
static const uint8_t P9A_OBUS_TCOB0_CC_PROTECT_MODE_REG_WRITE_ENABLE         = 1   ;

static const uint8_t P9A_OBUS_TCOB0_CLK_REGION_CLOCK_CMD                     = 0   ;
static const uint8_t P9A_OBUS_TCOB0_CLK_REGION_CLOCK_CMD_LEN                 = 2   ;
static const uint8_t P9A_OBUS_TCOB0_CLK_REGION_SLAVE_MODE                    = 2   ;
static const uint8_t P9A_OBUS_TCOB0_CLK_REGION_MASTER_MODE                   = 3   ;
static const uint8_t P9A_OBUS_TCOB0_CLK_REGION_CLOCK_PERV                    = 4   ;
static const uint8_t P9A_OBUS_TCOB0_CLK_REGION_CLOCK_UNIT1                   = 5   ;
static const uint8_t P9A_OBUS_TCOB0_CLK_REGION_CLOCK_UNIT2                   = 6   ;
static const uint8_t P9A_OBUS_TCOB0_CLK_REGION_CLOCK_UNIT3                   = 7   ;
static const uint8_t P9A_OBUS_TCOB0_CLK_REGION_CLOCK_UNIT4                   = 8   ;
static const uint8_t P9A_OBUS_TCOB0_CLK_REGION_CLOCK_UNIT5                   = 9   ;
static const uint8_t P9A_OBUS_TCOB0_CLK_REGION_CLOCK_UNIT6                   = 10  ;
static const uint8_t P9A_OBUS_TCOB0_CLK_REGION_CLOCK_UNIT7                   = 11  ;
static const uint8_t P9A_OBUS_TCOB0_CLK_REGION_CLOCK_UNIT8                   = 12  ;
static const uint8_t P9A_OBUS_TCOB0_CLK_REGION_CLOCK_UNIT9                   = 13  ;
static const uint8_t P9A_OBUS_TCOB0_CLK_REGION_CLOCK_UNIT10                  = 14  ;
static const uint8_t P9A_OBUS_TCOB0_CLK_REGION_SEL_THOLD_SL                  = 48  ;
static const uint8_t P9A_OBUS_TCOB0_CLK_REGION_SEL_THOLD_NSL                 = 49  ;
static const uint8_t P9A_OBUS_TCOB0_CLK_REGION_SEL_THOLD_ARY                 = 50  ;
static const uint8_t P9A_OBUS_TCOB0_CLK_REGION_CLOCK_PULSE_USE_EVEN          = 52  ;

static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_ARY_STATUS_PERV               = 4   ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_ARY_STATUS_UNIT1              = 5   ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_ARY_STATUS_UNIT2              = 6   ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_ARY_STATUS_UNIT3              = 7   ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_ARY_STATUS_UNIT4              = 8   ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_ARY_STATUS_UNIT5              = 9   ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_ARY_STATUS_UNIT6              = 10  ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_ARY_STATUS_UNIT7              = 11  ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_ARY_STATUS_UNIT8              = 12  ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_ARY_STATUS_UNIT9              = 13  ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_ARY_STATUS_UNIT10             = 14  ;

static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_NSL_STATUS_PERV               = 4   ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_NSL_STATUS_UNIT1              = 5   ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_NSL_STATUS_UNIT2              = 6   ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_NSL_STATUS_UNIT3              = 7   ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_NSL_STATUS_UNIT4              = 8   ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_NSL_STATUS_UNIT5              = 9   ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_NSL_STATUS_UNIT6              = 10  ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_NSL_STATUS_UNIT7              = 11  ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_NSL_STATUS_UNIT8              = 12  ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_NSL_STATUS_UNIT9              = 13  ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_NSL_STATUS_UNIT10             = 14  ;

static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_SL_STATUS_PERV                = 4   ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_SL_STATUS_UNIT1               = 5   ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_SL_STATUS_UNIT2               = 6   ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_SL_STATUS_UNIT3               = 7   ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_SL_STATUS_UNIT4               = 8   ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_SL_STATUS_UNIT5               = 9   ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_SL_STATUS_UNIT6               = 10  ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_SL_STATUS_UNIT7               = 11  ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_SL_STATUS_UNIT8               = 12  ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_SL_STATUS_UNIT9               = 13  ;
static const uint8_t P9A_OBUS_TCOB0_CLOCK_STAT_SL_STATUS_UNIT10              = 14  ;

static const uint8_t P9A_OBUS_TCOB0_CONTROL_REG_RESET_TRIP_HISTORY           = 0   ;
static const uint8_t P9A_OBUS_TCOB0_CONTROL_REG_RESET_SAMPLE_PULSE_CNT       = 1   ;
static const uint8_t P9A_OBUS_TCOB0_CONTROL_REG_F_RESET_CPM_RD               = 2   ;
static const uint8_t P9A_OBUS_TCOB0_CONTROL_REG_F_RESET_CPM_WR               = 3   ;
static const uint8_t P9A_OBUS_TCOB0_CONTROL_REG_RESET_SAMPLE_DTS             = 4   ;
static const uint8_t P9A_OBUS_TCOB0_CONTROL_REG_FORCE_SAMPLE_DTS             = 5   ;
static const uint8_t P9A_OBUS_TCOB0_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE = 6   ;
static const uint8_t P9A_OBUS_TCOB0_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS  = 7   ;
static const uint8_t P9A_OBUS_TCOB0_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS  = 8   ;
static const uint8_t P9A_OBUS_TCOB0_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS  = 9   ;
static const uint8_t P9A_OBUS_TCOB0_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE = 10  ;
static const uint8_t P9A_OBUS_TCOB0_CONTROL_REG_FORCE_RESET_MEASURE_VOLT     = 11  ;
static const uint8_t P9A_OBUS_TCOB0_CONTROL_REG_FORCE_SHIFT_SENSOR           = 12  ;

static const uint8_t P9A_OBUS_TCOB0_CPLT_MASK0_CPLTMASK0                     = 0   ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_MASK0_CPLTMASK0_LEN                 = 24  ;

static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_ABIST_DONE_DC                 = 0   ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_UNUSED_1E                     = 1   ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_RESERVED_2E                   = 2   ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_RESERVED_3E                   = 3   ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_TC_DIAG_PORT0_OUT             = 4   ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_TC_DIAG_PORT1_OUT             = 5   ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_RESERVED_6E                   = 6   ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_UNUSED_7E                     = 7   ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC          = 8   ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC = 9   ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_FREE_USAGE_10E                = 10  ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_FREE_USAGE_11E                = 11  ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_FREE_USAGE_12E                = 12  ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_FREE_USAGE_13E                = 13  ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_FREE_USAGE_14E                = 14  ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_FREE_USAGE_15E                = 15  ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_FREE_USAGE_16E                = 16  ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_FREE_USAGE_17E                = 17  ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_FREE_USAGE_18E                = 18  ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_FREE_USAGE_19E                = 19  ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_FREE_USAGE_20E                = 20  ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_FREE_USAGE_21E                = 21  ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_FREE_USAGE_22E                = 22  ;
static const uint8_t P9A_OBUS_TCOB0_CPLT_STAT0_FREE_USAGE_23E                = 23  ;

static const uint8_t P9A_OBUS_TCOB0_CTRL_ATOMIC_LOCK_REG_ENABLE              = 0   ;
static const uint8_t P9A_OBUS_TCOB0_CTRL_ATOMIC_LOCK_REG_ID                  = 1   ;
static const uint8_t P9A_OBUS_TCOB0_CTRL_ATOMIC_LOCK_REG_ID_LEN              = 4   ;
static const uint8_t P9A_OBUS_TCOB0_CTRL_ATOMIC_LOCK_REG_ACTIVITY            = 8   ;
static const uint8_t P9A_OBUS_TCOB0_CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN        = 8   ;

static const uint8_t P9A_OBUS_TCOB0_CTRL_PROTECT_MODE_REG_READ_ENABLE        = 0   ;
static const uint8_t P9A_OBUS_TCOB0_CTRL_PROTECT_MODE_REG_WRITE_ENABLE       = 1   ;

static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_RESET_EP                      = 0   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_OPCG_IP                       = 1   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_VITL_CLKOFF                   = 2   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_TEST_ENABLE                   = 3   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_REQ                           = 4   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_CMD                           = 5   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_CMD_LEN                       = 3   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_STATE                         = 8   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_STATE_LEN                     = 5   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_SECURITY_DEBUG_MODE           = 13  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_PROTOCOL_ERROR                = 14  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_PCB_IDLE                      = 15  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_CURRENT_OPCG_MODE             = 16  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_CURRENT_OPCG_MODE_LEN         = 4   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_LAST_OPCG_MODE                = 20  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_LAST_OPCG_MODE_LEN            = 4   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_PCB_ERROR                     = 24  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_PARITY_ERROR                  = 25  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_ERROR                         = 26  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_CHIPLET_IS_ALIGNED            = 27  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_PCB_REQUEST_SINCE_RESET       = 28  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_PARANOIA_TEST_ENABLE_CHANGE   = 29  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_PARANOIA_VITL_CLKOFF_CHANGE   = 30  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_CBS_CC_TP_TPFSI_ACK                  = 31  ;

static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_COND1_SEL_A         = 0   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN     = 8   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_COND1_SEL_B         = 8   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN     = 8   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_COND2_SEL_A         = 16  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN     = 8   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_COND2_SEL_B         = 24  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN     = 8   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_C1_INAROW_MODE      = 32  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1   = 33  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1   = 34  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1  = 35  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_UNUSED              = 36  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_UNUSED_LEN          = 3   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_C2_INAROW_MODE      = 39  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2   = 40  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2   = 41  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2  = 42  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_UNUSED_2            = 43  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_UNUSED_2_LEN        = 3   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET  = 46  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_EXACT_TO_MODE       = 47  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 = 48  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_RESET_C3_ON_C0      = 49  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_SLOW_TO_MODE        = 50  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO = 51  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_C1_COUNT_LT         = 52  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN     = 4   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_C2_COUNT_LT         = 56  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN     = 4   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_RESET_C3_SELECT     = 60  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN = 3   ;

static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_A = 10  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_A_LEN = 5   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_B = 15  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_B_LEN = 5   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_2_TO_CMP_LT           = 20  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST1_COND_REG_2_TO_CMP_LT_LEN       = 24  ;

static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_COND1_SEL_A         = 0   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN     = 8   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_COND1_SEL_B         = 8   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN     = 8   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_COND2_SEL_A         = 16  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN     = 8   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_COND2_SEL_B         = 24  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN     = 8   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_C1_INAROW_MODE      = 32  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1   = 33  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1   = 34  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1  = 35  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_UNUSED              = 36  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_UNUSED_LEN          = 3   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_C2_INAROW_MODE      = 39  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2   = 40  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2   = 41  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2  = 42  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_UNUSED_2            = 43  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_UNUSED_2_LEN        = 3   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET  = 46  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_EXACT_TO_MODE       = 47  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 = 48  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_RESET_C3_ON_C0      = 49  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_SLOW_TO_MODE        = 50  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO = 51  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_C1_COUNT_LT         = 52  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN     = 4   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_C2_COUNT_LT         = 56  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN     = 4   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_RESET_C3_SELECT     = 60  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN = 3   ;

static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_A = 10  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_A_LEN = 5   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_B = 15  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_B_LEN = 5   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_2_TO_CMP_LT           = 20  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_INST2_COND_REG_2_TO_CMP_LT_LEN       = 24  ;

static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_GLB_BRCST                   = 0   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_GLB_BRCST_LEN               = 3   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_TRACE_SEL                   = 3   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_TRACE_SEL_LEN               = 3   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_TRIG_SEL                    = 6   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_TRIG_SEL_LEN                = 2   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION     = 8   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION    = 10  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_FREEZE_SEL                  = 11  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_SYNC_BRCST                  = 12  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_SYNC_BRCST_LEN              = 2   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_TRACE_RUN_STATUS            = 17  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_TRACE_RUN_STATUS_LEN        = 2   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_IS_FROZEN_STATUS            = 19  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_INST3_CONDITION_HISTORY_STATUS = 26  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_INST3_CONDITION_HISTORY_STATUS_LEN = 3   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_INST4_CONDITION_HISTORY_STATUS = 29  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_MODE_REG_INST4_CONDITION_HISTORY_STATUS_LEN = 2   ;

static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE = 0   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE_LEN = 16  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_MODE_REG_2_IMM_FREEZE          = 16  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_MODE_REG_2_STOP_ON_ERR         = 17  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_MODE_REG_2_BANK_ON_RUNN_MATCH  = 18  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_MODE_REG_2_FORCE_TEST          = 19  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_MODE_REG_2_ACCUM_HIST          = 20  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_MODE_REG_2_FRZ_COUNT_ON_FRZ    = 21  ;

static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST1_COND3_ENABLE       = 0   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST2_COND3_ENABLE       = 1   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST3_COND3_ENABLE       = 2   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST4_COND3_ENABLE       = 3   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST1_SLOW_LFSR_MODE     = 4   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST2_SLOW_LFSR_MODE     = 5   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST3_SLOW_LFSR_MODE     = 6   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST4_SLOW_LFSR_MODE     = 7   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL = 8   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL = 10  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL = 12  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL = 14  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL = 16  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL = 18  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL_LEN = 2   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_EXT_TRIG_ON_STOP         = 32  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_EXT_TRIG_ON_FREEZE       = 33  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL       = 34  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL_LEN   = 5   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL       = 39  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL_LEN   = 5   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_PC_TP_TRIG_SEL           = 44  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_PC_TP_TRIG_SEL_LEN       = 2   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_ARM_SEL                  = 46  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_ARM_SEL_LEN              = 4   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL          = 50  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL_LEN      = 4   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL          = 54  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL_LEN      = 4   ;

static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST1_CONDITION1_ACTION_DO = 0   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST1_CONDITION1_ACTION_DO_LEN = 2   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST1_CONDITION2_ACTION_DO = 2   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST1_CONDITION2_ACTION_DO_LEN = 2   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST1_C2_TIMEOUT_ACTION_DO = 4   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST1_C2_TIMEOUT_ACTION_DO_LEN = 2   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST2_CONDITION1_ACTION_DO = 6   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST2_CONDITION1_ACTION_DO_LEN = 2   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST2_CONDITION2_ACTION_DO = 8   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST2_CONDITION2_ACTION_DO_LEN = 2   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST2_C2_TIMEOUT_ACTION_DO = 10  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST2_C2_TIMEOUT_ACTION_DO_LEN = 2   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST1_CONDITION1_ACTION_WAITN = 24  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST1_CONDITION2_ACTION_WAITN = 25  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST1_C2_TIMEOUT_ACTION_WAITN = 26  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST2_CONDITION1_ACTION_WAITN = 27  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST2_CONDITION2_ACTION_WAITN = 28  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST2_C2_TIMEOUT_ACTION_WAITN = 29  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST1_CONDITION1_ACTION_BANK = 36  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST1_CONDITION2_ACTION_BANK = 37  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST1_C2_TIMEOUT_ACTION_BANK = 38  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST2_CONDITION1_ACTION_BANK = 39  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST2_CONDITION2_ACTION_BANK = 40  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST2_C2_TIMEOUT_ACTION_BANK = 41  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST1_CHECKSTOP_MODE_LT  = 48  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST1_CHECKSTOP_MODE_LT_LEN = 3   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST1_CHECKSTOP_MODE_SELECTOR = 51  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST2_CHECKSTOP_MODE_LT  = 52  ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST2_CHECKSTOP_MODE_LT_LEN = 3   ;
static const uint8_t P9A_OBUS_TCOB0_DBG_TRACE_REG_1_INST2_CHECKSTOP_MODE_SELECTOR = 55  ;

static const uint8_t P9A_OBUS_TCOB0_DEBUG_TRACE_CONTROL_SCOM_TRACE_START     = 0   ;
static const uint8_t P9A_OBUS_TCOB0_DEBUG_TRACE_CONTROL_SCOM_TRACE_STOP      = 1   ;
static const uint8_t P9A_OBUS_TCOB0_DEBUG_TRACE_CONTROL_SCOM_TRACE_RESET     = 2   ;

static const uint8_t P9A_OBUS_TCOB0_DTS_RESULT0_0_RESULT                     = 0   ;
static const uint8_t P9A_OBUS_TCOB0_DTS_RESULT0_0_RESULT_LEN                 = 16  ;
static const uint8_t P9A_OBUS_TCOB0_DTS_RESULT0_1_RESULT                     = 16  ;
static const uint8_t P9A_OBUS_TCOB0_DTS_RESULT0_1_RESULT_LEN                 = 16  ;

static const uint8_t P9A_OBUS_TCOB0_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE   = 0   ;
static const uint8_t P9A_OBUS_TCOB0_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE_LEN = 44  ;
static const uint8_t P9A_OBUS_TCOB0_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR = 44  ;
static const uint8_t P9A_OBUS_TCOB0_DTS_TRC_RESULT_1                         = 48  ;
static const uint8_t P9A_OBUS_TCOB0_DTS_TRC_RESULT_1_LEN                     = 16  ;

static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR   = 0   ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR    = 1   ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR       = 2   ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR   = 3   ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR      = 4   ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR      = 5   ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR = 6   ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR     = 7   ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR   = 8   ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR   = 9   ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR      = 10  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_SCAN_COLLISION_ERR          = 11  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR = 12  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_OPCG_TRIGGER_ERR            = 13  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR    = 14  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR     = 15  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR       = 16  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR = 17  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR      = 18  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR = 19  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR     = 20  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR      = 21  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_CLKCMD_REQUEST_ERR          = 22  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_CBS_PROTOCOL_ERR            = 23  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_VITL_ALIGN_ERR              = 24  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_UNIT_SYNC_LVL_ERR           = 25  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR = 26  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR     = 27  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_EDRAM_SCAN_PREVENTED_ERR    = 28  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_UNUSED_ERROR29              = 29  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_UNUSED_ERROR30              = 30  ;
static const uint8_t P9A_OBUS_TCOB0_ERROR_STATUS_UNUSED_ERROR31              = 31  ;

static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD = 0   ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD = 1   ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD = 2   ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD = 3   ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD = 4   ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD = 5   ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD = 6   ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD      = 7   ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_RUN_STATE_ERR_HOLD        = 8   ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD = 9   ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD = 10  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD   = 11  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD    = 12  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_TIMEOUT_ERR_HOLD          = 13  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_F_SKITTER_ERR_HOLD        = 14  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_PCB_ERR_HOLD_OUT          = 15  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_MASK = 16  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_THERM_MODEREG_PARITY_MASK = 17  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_MASK = 18  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_MASK = 19  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_SCAN_INIT_VERSION_PARITY_MASK = 20  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_VOLT_MODEREG_PARITY_MASK  = 21  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_COUNT_STATE_MASK          = 23  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_RUN_STATE_MASK            = 24  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_THRES_STATE_MASK          = 25  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_OVERFLOW_MASK             = 26  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_SHIFTER_PARITY_MASK       = 27  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_SHIFTER_VALID_MASK        = 28  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_TIMEOUT_MASK              = 29  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_F_SKITTER_READ_MASK       = 30  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_PCB_MASK                  = 31  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_COUNT_STATE_LT            = 40  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_COUNT_STATE_LT_LEN        = 4   ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_RUN_STATE_LT              = 44  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_RUN_STATE_LT_LEN          = 3   ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_SHIFT_DTS_LT              = 47  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_SHIFT_VOLT_LT             = 48  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_READ_STATE_LT             = 49  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_READ_STATE_LT_LEN         = 2   ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_WRITE_STATE_LT            = 51  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_WRITE_STATE_LT_LEN        = 4   ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_SAMPLE_DTS_LT             = 55  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_MEASURE_VOLT_LT           = 56  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_READ_CPM_LT               = 57  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_WRITE_CPM_LT              = 58  ;
static const uint8_t P9A_OBUS_TCOB0_ERR_STATUS_REG_UNUSED                    = 59  ;

static const uint8_t P9A_OBUS_TCOB0_FIR_MASK_IN0                             = 0   ;
static const uint8_t P9A_OBUS_TCOB0_FIR_MASK_IN1                             = 1   ;
static const uint8_t P9A_OBUS_TCOB0_FIR_MASK_IN2                             = 2   ;
static const uint8_t P9A_OBUS_TCOB0_FIR_MASK_IN3                             = 3   ;
static const uint8_t P9A_OBUS_TCOB0_FIR_MASK_IN4                             = 4   ;
static const uint8_t P9A_OBUS_TCOB0_FIR_MASK_IN5                             = 5   ;
static const uint8_t P9A_OBUS_TCOB0_FIR_MASK_IN6                             = 6   ;
static const uint8_t P9A_OBUS_TCOB0_FIR_MASK_IN7                             = 7   ;
static const uint8_t P9A_OBUS_TCOB0_FIR_MASK_IN7_LEN                         = 19  ;
static const uint8_t P9A_OBUS_TCOB0_FIR_MASK_IN26                            = 26  ;

static const uint8_t P9A_OBUS_TCOB0_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN0         = 0   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN1         = 1   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN2         = 2   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN3         = 3   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN4         = 4   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN5         = 5   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN6         = 6   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN7         = 7   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN8         = 8   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN9         = 9   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN10        = 10  ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP0_MASK_REG_GXSTP0_TRIG_IN11        = 11  ;

static const uint8_t P9A_OBUS_TCOB0_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN0         = 0   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN1         = 1   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN2         = 2   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN3         = 3   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN4         = 4   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN5         = 5   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN6         = 6   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN7         = 7   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN8         = 8   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN9         = 9   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN10        = 10  ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP1_MASK_REG_GXSTP1_TRIG_IN11        = 11  ;

static const uint8_t P9A_OBUS_TCOB0_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN0         = 0   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN1         = 1   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN2         = 2   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN3         = 3   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN4         = 4   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN5         = 5   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN6         = 6   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN7         = 7   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN8         = 8   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN9         = 9   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN10        = 10  ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP2_MASK_REG_GXSTP2_TRIG_IN11        = 11  ;

static const uint8_t P9A_OBUS_TCOB0_GXSTOP_TRIG_REG_GXSTP_IN0                = 0   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP_TRIG_REG_GXSTP_IN1                = 1   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP_TRIG_REG_GXSTP_IN2                = 2   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP_TRIG_REG_GXSTP_IN3                = 3   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP_TRIG_REG_GXSTP_IN4                = 4   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP_TRIG_REG_GXSTP_IN5                = 5   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP_TRIG_REG_GXSTP_IN6                = 6   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP_TRIG_REG_GXSTP_IN7                = 7   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP_TRIG_REG_GXSTP_IN8                = 8   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP_TRIG_REG_GXSTP_IN9                = 9   ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP_TRIG_REG_GXSTP_IN10               = 10  ;
static const uint8_t P9A_OBUS_TCOB0_GXSTOP_TRIG_REG_GXSTP_IN11               = 11  ;

static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN0                             = 0   ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN1                             = 1   ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN2                             = 2   ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN3                             = 3   ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN4                             = 4   ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN5                             = 5   ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN6                             = 6   ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN7                             = 7   ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN8                             = 8   ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN9                             = 9   ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN10                            = 10  ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN11                            = 11  ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN12                            = 12  ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN13                            = 13  ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN14                            = 14  ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN15                            = 15  ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN16                            = 16  ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN17                            = 17  ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN18                            = 18  ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN19                            = 19  ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN20                            = 20  ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN21                            = 21  ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_IN22                            = 22  ;

static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_MASK_IN                         = 0   ;
static const uint8_t P9A_OBUS_TCOB0_HOSTATTN_MASK_IN_LEN                     = 22  ;

static const uint8_t P9A_OBUS_TCOB0_INJECT_REG_THERM_TRIP                    = 0   ;
static const uint8_t P9A_OBUS_TCOB0_INJECT_REG_THERM_TRIP_LEN                = 2   ;
static const uint8_t P9A_OBUS_TCOB0_INJECT_REG_THERM_MODE                    = 2   ;
static const uint8_t P9A_OBUS_TCOB0_INJECT_REG_THERM_MODE_LEN                = 2   ;

static const uint8_t P9A_OBUS_TCOB0_LOCAL_FIR_ACTION0_IN                     = 0   ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_FIR_ACTION0_IN_LEN                 = 42  ;

static const uint8_t P9A_OBUS_TCOB0_LOCAL_FIR_ACTION1_IN                     = 0   ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_FIR_ACTION1_IN_LEN                 = 42  ;

static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN0                      = 0   ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN1                      = 1   ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN2                      = 2   ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN3                      = 3   ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN4                      = 4   ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN5                      = 5   ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN6                      = 6   ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN7                      = 7   ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN8                      = 8   ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN9                      = 9   ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN10                     = 10  ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN11                     = 11  ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN12                     = 12  ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN13                     = 13  ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN14                     = 14  ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN15                     = 15  ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN16                     = 16  ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN17                     = 17  ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN18                     = 18  ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN19                     = 19  ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN20                     = 20  ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN21                     = 21  ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_ERR_IN22                     = 22  ;

static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_MASK_IN                      = 0   ;
static const uint8_t P9A_OBUS_TCOB0_LOCAL_XSTOP_MASK_IN_LEN                  = 22  ;

static const uint8_t P9A_OBUS_TCOB0_MODE_REG_IN0                             = 0   ;
static const uint8_t P9A_OBUS_TCOB0_MODE_REG_IN1                             = 1   ;
static const uint8_t P9A_OBUS_TCOB0_MODE_REG_IN2                             = 2   ;
static const uint8_t P9A_OBUS_TCOB0_MODE_REG_IN3                             = 3   ;
static const uint8_t P9A_OBUS_TCOB0_MODE_REG_IN4                             = 4   ;
static const uint8_t P9A_OBUS_TCOB0_MODE_REG_IN5                             = 5   ;
static const uint8_t P9A_OBUS_TCOB0_MODE_REG_IN6                             = 6   ;
static const uint8_t P9A_OBUS_TCOB0_MODE_REG_IN7                             = 7   ;
static const uint8_t P9A_OBUS_TCOB0_MODE_REG_IN8                             = 8   ;
static const uint8_t P9A_OBUS_TCOB0_MODE_REG_IN9                             = 9   ;
static const uint8_t P9A_OBUS_TCOB0_MODE_REG_IN10                            = 10  ;
static const uint8_t P9A_OBUS_TCOB0_MODE_REG_IN11                            = 11  ;
static const uint8_t P9A_OBUS_TCOB0_MODE_REG_IN                              = 12  ;
static const uint8_t P9A_OBUS_TCOB0_MODE_REG_IN_LEN                          = 4   ;

static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_INOP                          = 0   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_INOP_LEN                      = 4   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_SNOP                          = 4   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_SNOP_LEN                      = 4   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_ENOP                          = 8   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_ENOP_LEN                      = 4   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_INOP_WAIT                     = 12  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_INOP_WAIT_LEN                 = 8   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_SNOP_WAIT                     = 20  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_SNOP_WAIT_LEN                 = 12  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_ENOP_WAIT                     = 32  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_ENOP_WAIT_LEN                 = 8   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_INOP_FORCE_SG                 = 40  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_SNOP_FORCE_SG                 = 41  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_ENOP_FORCE_SG                 = 42  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD            = 43  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_SOURCE_SELECT                 = 44  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_SOURCE_SELECT_LEN             = 2   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_UNUSED46                      = 46  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_SCAN_RATIO                    = 47  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_SCAN_RATIO_LEN                = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_WAIT_CYCLES                   = 52  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_ALIGN_WAIT_CYCLES_LEN               = 12  ;

static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_COUNT                         = 0   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_COUNT_LEN                     = 4   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_01                        = 4   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_01_LEN                    = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_02                        = 9   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_02_LEN                    = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_03                        = 14  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_03_LEN                    = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_04                        = 19  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_04_LEN                    = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_05                        = 24  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_05_LEN                    = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_06                        = 29  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_06_LEN                    = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_07                        = 34  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_07_LEN                    = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_08                        = 39  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_08_LEN                    = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_09                        = 44  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_09_LEN                    = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_10                        = 49  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_10_LEN                    = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_11                        = 54  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_11_LEN                    = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_12                        = 59  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT1_SEQ_12_LEN                    = 5   ;

static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_UNUSED                        = 0   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_UNUSED_LEN                    = 4   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_13_01EVEN                 = 4   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_13_01EVEN_LEN             = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_14_01ODD                  = 9   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_14_01ODD_LEN              = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_15_02EVEN                 = 14  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_15_02EVEN_LEN             = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_16_02ODD                  = 19  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_16_02ODD_LEN              = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_17_03EVEN                 = 24  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_17_03EVEN_LEN             = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_18_03ODD                  = 29  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_18_03ODD_LEN              = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_19_04EVEN                 = 34  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_19_04EVEN_LEN             = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_20_04ODD                  = 39  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_20_04ODD_LEN              = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_21_05EVEN                 = 44  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_21_05EVEN_LEN             = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_22_05ODD                  = 49  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_22_05ODD_LEN              = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_23_06EVEN                 = 54  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_23_06EVEN_LEN             = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_24_06ODD                  = 59  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT2_SEQ_24_06ODD_LEN              = 5   ;

static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_UNUSED                        = 0   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_UNUSED_LEN                    = 4   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_07EVEN                    = 4   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_07EVEN_LEN                = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_07ODD                     = 9   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_07ODD_LEN                 = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_08EVEN                    = 14  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_08EVEN_LEN                = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_08ODD                     = 19  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_08ODD_LEN                 = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_09EVEN                    = 24  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_09EVEN_LEN                = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_09ODD                     = 29  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_09ODD_LEN                 = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_10EVEN                    = 34  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_10EVEN_LEN                = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_10ODD                     = 39  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_10ODD_LEN                 = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_11EVEN                    = 44  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_11EVEN_LEN                = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_11ODD                     = 49  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_11ODD_LEN                 = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_12EVEN                    = 54  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_12EVEN_LEN                = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_12ODD                     = 59  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_CAPT3_SEQ_12ODD_LEN                 = 5   ;

static const uint8_t P9A_OBUS_TCOB0_OPCG_REG0_RUNN_MODE                      = 0   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG0_GO                             = 1   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG0_RUN_SCAN0                      = 2   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG0_SCAN0_MODE                     = 3   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG0_IN_SLAVE_MODE                  = 4   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG0_IN_MASTER_MODE                 = 5   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG0_KEEP_MS_MODE                   = 6   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG0_TRIGGER_ON_UNIT0_SYNC_LVL      = 7   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG0_TRIGGER_ON_UNIT1_SYNC_LVL      = 8   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG0_RUN_CHIPLET_SCAN0              = 9   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG0_RUN_CHIPLET_SCAN0_NO_PLL       = 10  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG0_RUN_ON_UPDATE_DR               = 11  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG0_RUN_ON_CAPTURE_DR              = 12  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG0_STOP_RUNN_ON_XSTOP             = 13  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG0_STARTS_BIST                    = 14  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG0_UNUSED1520                     = 15  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG0_UNUSED1520_LEN                 = 6   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG0_LOOP_COUNT                     = 21  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG0_LOOP_COUNT_LEN                 = 43  ;

static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_SCAN_COUNT                     = 0   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_SCAN_COUNT_LEN                 = 12  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_MISR_A_VAL                     = 12  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_MISR_A_VAL_LEN                 = 12  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_MISR_B_VAL                     = 24  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_MISR_B_VAL_LEN                 = 12  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_MISR_INIT_WAIT                 = 36  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_MISR_INIT_WAIT_LEN             = 12  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_SUPPRESS_LAST_RUNN_CLK         = 48  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_SCAN_CLK_USE_EVEN              = 49  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_UNUSED2                        = 50  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_UNUSED2_LEN                    = 2   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_RTIM_THOLD_FORCE               = 52  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL    = 53  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_SG_HIGH_DURING_FILL            = 54  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_LBIST_SKITTER_CTL              = 55  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_LBIST_SKITTER_CTL_LEN          = 2   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_MISR_MODE                      = 57  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_INFINITE_MODE                  = 58  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_NSL_FILL_COUNT                 = 59  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG1_NSL_FILL_COUNT_LEN             = 5   ;

static const uint8_t P9A_OBUS_TCOB0_OPCG_REG2_GO2                            = 0   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG2_PRPG_WEIGHTING                 = 1   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG2_PRPG_WEIGHTING_LEN             = 3   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG2_PRPG_VALUE                     = 4   ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG2_PRPG_VALUE_LEN                 = 12  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG2_PRPG_A_VAL                     = 16  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG2_PRPG_A_VAL_LEN                 = 12  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG2_PRPG_B_VAL                     = 28  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG2_PRPG_B_VAL_LEN                 = 12  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG2_PRPG_MODE                      = 40  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG2_UNUSED41_63                    = 41  ;
static const uint8_t P9A_OBUS_TCOB0_OPCG_REG2_UNUSED41_63_LEN                = 23  ;

static const uint8_t P9A_OBUS_TCOB0_PCB_OPCG_GO_OPCGGO                       = 0   ;

static const uint8_t P9A_OBUS_TCOB0_PCB_OPCG_STOP_OPCGSTOP                   = 0   ;

static const uint8_t P9A_OBUS_TCOB0_PSCOM_ERROR_MASK_PCB_WDATA_PARITY        = 0   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY      = 1   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY  = 2   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_ERROR_MASK_DL_RETURN_P0            = 3   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_ERROR_MASK_UL_RDATA_PARITY         = 4   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_ERROR_MASK_UL_P0                   = 5   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_ERROR_MASK_PARITY_ON_INTERFACE_MACHINE = 6   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_ERROR_MASK_PARITY_ON_P2S_MACHINE   = 7   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_ERROR_MASK_PARALLEL_WRITE_NVLD     = 11  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_ERROR_MASK_PARALLEL_READ_NVLD      = 12  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_ERROR_MASK_PARALLEL_ADDR_INVALID   = 13  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_ERROR_MASK_PCB_COMMAND_PARITY      = 14  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_ERROR_MASK_GENERAL_TIMEOUT         = 15  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17  ;

static const uint8_t P9A_OBUS_TCOB0_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR = 0   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR = 1   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_MODE_REG_UNUSED_BIT_2              = 2   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR = 3   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_MODE_REG_WATCHDOG_ENABLE           = 4   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_MODE_REG_SCOM_HANG_LIMIT           = 5   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN       = 2   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_MODE_REG_FORCE_ALL_RINGS           = 7   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE = 8   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_MODE_REG_RESERVED_LT               = 9   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_MODE_REG_RESERVED_LT_LEN           = 3   ;

static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_WDATA_PARITY = 0   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_ADDRESS_PARITY = 1   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_WDATA_PARITY = 2   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_P0 = 3   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_RDATA_PARITY = 4   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_P0 = 5   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ON_INTERFACE_MACHINE = 6   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ON_P2S_MACHINE = 7   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9   ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARALLEL_WRITE_NVLD = 11  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARALLEL_READ_NVLD = 12  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARALLEL_ADDR_INVALID = 13  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_COMMAND_PARITY = 14  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_ACCUMULATED_GENERAL_TIMEOUT = 15  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_WDATA_PARITY = 18  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_ADDRESS_PARITY = 19  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_WDATA_PARITY = 20  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_P0 = 21  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_TRAPPED_UL_RDATA_PARITY = 22  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_TRAPPED_UL_P0     = 23  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ON_INTERFACE_MACHINE = 24  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ON_P2S_MACHINE = 25  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 26  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 27  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 28  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_TRAPPED_PARALLEL_WRITE_NVLD = 29  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_TRAPPED_PARALLEL_READ_NVLD = 30  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_TRAPPED_PARALLEL_ADDR_INVALID = 31  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_COMMAND_PARITY = 32  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_TRAPPED_GENERAL_TIMEOUT = 33  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 34  ;
static const uint8_t P9A_OBUS_TCOB0_PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 35  ;

static const uint8_t P9A_OBUS_TCOB0_RFIR_IN0                                 = 0   ;
static const uint8_t P9A_OBUS_TCOB0_RFIR_LFIR_RECOV_ERR                      = 1   ;
static const uint8_t P9A_OBUS_TCOB0_RFIR_IN4                                 = 2   ;
static const uint8_t P9A_OBUS_TCOB0_RFIR_IN5                                 = 3   ;
static const uint8_t P9A_OBUS_TCOB0_RFIR_IN6                                 = 4   ;
static const uint8_t P9A_OBUS_TCOB0_RFIR_IN7                                 = 5   ;
static const uint8_t P9A_OBUS_TCOB0_RFIR_IN7_LEN                             = 19  ;

static const uint8_t P9A_OBUS_TCOB0_RING_FENCE_MASK_LATCH_REG_ENABLE         = 1   ;
static const uint8_t P9A_OBUS_TCOB0_RING_FENCE_MASK_LATCH_REG_ENABLE_LEN     = 15  ;

static const uint8_t P9A_OBUS_TCOB0_SCAN32_SCAN32_REG                        = 0   ;
static const uint8_t P9A_OBUS_TCOB0_SCAN32_SCAN32_REG_LEN                    = 32  ;

static const uint8_t P9A_OBUS_TCOB0_SCAN64_SCAN64_REG                        = 0   ;
static const uint8_t P9A_OBUS_TCOB0_SCAN64_SCAN64_REG_LEN                    = 64  ;

static const uint8_t P9A_OBUS_TCOB0_SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG        = 0   ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG_LEN    = 32  ;

static const uint8_t P9A_OBUS_TCOB0_SCAN_CAPTUREDR_LONG_SCAN_CAPTUREDR_LONG_REG = 0   ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_CAPTUREDR_LONG_SCAN_CAPTUREDR_LONG_REG_LEN = 32  ;

static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_SYSTEM_FAST_INIT        = 0   ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_VITL                    = 3   ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_PERV                    = 4   ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_UNIT1                   = 5   ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_UNIT2                   = 6   ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_UNIT3                   = 7   ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_UNIT4                   = 8   ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_UNIT5                   = 9   ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_UNIT6                   = 10  ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_UNIT7                   = 11  ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_UNIT8                   = 12  ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_UNIT9                   = 13  ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_UNIT10                  = 14  ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_FUNC                    = 48  ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_CFG                     = 49  ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_CCFG_GPTR               = 50  ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_REGF                    = 51  ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_LBIST                   = 52  ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_ABIST                   = 53  ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_REPR                    = 54  ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_TIME                    = 55  ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_BNDY                    = 56  ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_FARR                    = 57  ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_CMSK                    = 58  ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_REGION_TYPE_INEX                    = 59  ;

static const uint8_t P9A_OBUS_TCOB0_SCAN_UPDATEDR_SCAN_UPDATEDR_REG          = 0   ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_UPDATEDR_SCAN_UPDATEDR_REG_LEN      = 32  ;

static const uint8_t P9A_OBUS_TCOB0_SCAN_UPDATEDR_LONG_SCAN_UPDATEDR_LONG_REG = 0   ;
static const uint8_t P9A_OBUS_TCOB0_SCAN_UPDATEDR_LONG_SCAN_UPDATEDR_LONG_REG_LEN = 32  ;

static const uint8_t P9A_OBUS_TCOB0_SKITTER_CLKSRC_REG_SKITTER0              = 0   ;
static const uint8_t P9A_OBUS_TCOB0_SKITTER_CLKSRC_REG_SKITTER0_LEN          = 3   ;
static const uint8_t P9A_OBUS_TCOB0_SKITTER_CLKSRC_REG_SKITTER0_DELAY_SELECT = 36  ;
static const uint8_t P9A_OBUS_TCOB0_SKITTER_CLKSRC_REG_SKITTER0_DELAY_SELECT_LEN = 2   ;

static const uint8_t P9A_OBUS_TCOB0_SKITTER_FORCE_REG_F_READ                 = 0   ;

static const uint8_t P9A_OBUS_TCOB0_SKITTER_MODE_REG_HOLD_SAMPLE             = 0   ;
static const uint8_t P9A_OBUS_TCOB0_SKITTER_MODE_REG_DISABLE_STICKINESS      = 1   ;
static const uint8_t P9A_OBUS_TCOB0_SKITTER_MODE_REG_UNUSED1                 = 2   ;
static const uint8_t P9A_OBUS_TCOB0_SKITTER_MODE_REG_UNUSED1_LEN             = 2   ;
static const uint8_t P9A_OBUS_TCOB0_SKITTER_MODE_REG_HOLD_DBGTRIG_SEL        = 4   ;
static const uint8_t P9A_OBUS_TCOB0_SKITTER_MODE_REG_HOLD_DBGTRIG_SEL_LEN    = 2   ;
static const uint8_t P9A_OBUS_TCOB0_SKITTER_MODE_REG_RESET_TRIG_SEL          = 6   ;
static const uint8_t P9A_OBUS_TCOB0_SKITTER_MODE_REG_RESET_TRIG_SEL_LEN      = 2   ;
static const uint8_t P9A_OBUS_TCOB0_SKITTER_MODE_REG_SAMPLE_GUTS             = 8   ;
static const uint8_t P9A_OBUS_TCOB0_SKITTER_MODE_REG_SAMPLE_GUTS_LEN         = 2   ;
static const uint8_t P9A_OBUS_TCOB0_SKITTER_MODE_REG_HOLD_SAMPLE_WITH_TRIGGER = 44  ;
static const uint8_t P9A_OBUS_TCOB0_SKITTER_MODE_REG_DATA_V_LT               = 45  ;

static const uint8_t P9A_OBUS_TCOB0_SPA_MASK_IN                              = 0   ;
static const uint8_t P9A_OBUS_TCOB0_SPA_MASK_IN_LEN                          = 10  ;

static const uint8_t P9A_OBUS_TCOB0_SUM_MASK_REG_SMASK_IN0                   = 0   ;
static const uint8_t P9A_OBUS_TCOB0_SUM_MASK_REG_SMASK_IN1                   = 1   ;
static const uint8_t P9A_OBUS_TCOB0_SUM_MASK_REG_SMASK_IN2                   = 2   ;
static const uint8_t P9A_OBUS_TCOB0_SUM_MASK_REG_SMASK_IN3                   = 3   ;
static const uint8_t P9A_OBUS_TCOB0_SUM_MASK_REG_SMASK_IN4                   = 4   ;

static const uint8_t P9A_OBUS_TCOB0_SYNC_CONFIG_PULSE_DELAY                  = 0   ;
static const uint8_t P9A_OBUS_TCOB0_SYNC_CONFIG_PULSE_DELAY_LEN              = 4   ;
static const uint8_t P9A_OBUS_TCOB0_SYNC_CONFIG_LISTEN_TO_PULSE_DIS          = 4   ;
static const uint8_t P9A_OBUS_TCOB0_SYNC_CONFIG_PULSE_INPUT_SEL              = 5   ;
static const uint8_t P9A_OBUS_TCOB0_SYNC_CONFIG_USE_FOR_SCAN                 = 6   ;
static const uint8_t P9A_OBUS_TCOB0_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED     = 7   ;
static const uint8_t P9A_OBUS_TCOB0_SYNC_CONFIG_UNIT_REGION_CLKCMD_ENABLE    = 8   ;
static const uint8_t P9A_OBUS_TCOB0_SYNC_CONFIG_DISABLE_PCB_ITR              = 9   ;
static const uint8_t P9A_OBUS_TCOB0_SYNC_CONFIG_ENABLE_VITL_ALIGN_CHECK      = 10  ;
static const uint8_t P9A_OBUS_TCOB0_SYNC_CONFIG_PULSE_OUT_DIS                = 11  ;
static const uint8_t P9A_OBUS_TCOB0_SYNC_CONFIG_CHKSW_PCB_RESPONCE_DATA      = 12  ;
static const uint8_t P9A_OBUS_TCOB0_SYNC_CONFIG_CHKSW_2TO1_CLK_GATING        = 13  ;
static const uint8_t P9A_OBUS_TCOB0_SYNC_CONFIG_UNUSED1415                   = 14  ;
static const uint8_t P9A_OBUS_TCOB0_SYNC_CONFIG_UNUSED1415_LEN               = 2   ;
static const uint8_t P9A_OBUS_TCOB0_SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE   = 16  ;
static const uint8_t P9A_OBUS_TCOB0_SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_LEN = 8   ;

static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC = 0   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC_LEN = 6   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_6C       = 6   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_7C       = 7   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC = 8   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC_LEN = 6   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_14C      = 14  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_15C      = 15  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC = 16  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC_LEN = 6   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_22C      = 22  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_23C      = 23  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC = 24  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC_LEN = 6   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_30C      = 30  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_31C      = 31  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_UNUSED_32C        = 32  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC = 33  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_CTRL_CC_SDIS_DC_N = 34  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_CTRL_CC_SCAN_DIAG = 35  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_TEST_CONTROL_36C = 36  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_TEST_CONTROL_37C = 37  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_TEST_CONTROL_38C = 38  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_TEST_CONTROL_39C = 39  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC = 40  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC = 41  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_42C      = 42  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_43C      = 43  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN = 44  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC = 45  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_46C      = 46  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_47C      = 47  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_UNUSED_48C        = 48  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_UNUSED_49C        = 49  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_UNUSED_50C        = 50  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_UNUSED_51C        = 51  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_TC_UNIT_CHIP_ID_DC = 52  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_TC_UNIT_CHIP_ID_DC_LEN = 3   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_ID_55C   = 55  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_UNUSED_56C        = 56  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_UNUSED_57C        = 57  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_UNUSED_58C        = 58  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_UNUSED_59C        = 59  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_UNUSED_60C        = 60  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_ID_61C   = 61  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_ID_62C   = 62  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF0_RESERVED_ID_63C   = 63  ;

static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_0D         = 0   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_1D         = 1   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_2D         = 2   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_3D         = 3   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_TC_PBIOO0_IOVALID = 4   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_TC_PBIOO1_IOVALID = 5   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_TC_PBIOO0_NV0_IOVALID = 6   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_TC_PBIOO0_NV1_IOVALID = 7   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_TC_PBIOO0_NV2_IOVALID = 8   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_9D         = 9   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_10D        = 10  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_11D        = 11  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_12D        = 12  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_13D        = 13  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_14D        = 14  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_15D        = 15  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_TC_OB_RATIO_DC    = 16  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_TC_OB_RATIO_DC_LEN = 2   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_18D        = 18  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_19D        = 19  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_20D        = 20  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_21D        = 21  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_22D        = 22  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_23D        = 23  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_24D        = 24  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_25D        = 25  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_26D        = 26  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_27D        = 27  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_28D        = 28  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_29D        = 29  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_30D        = 30  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CONF1_UNUSED_31D        = 31  ;

static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC = 0   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC = 1   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH_DC = 2   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN_DC = 3   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC = 4   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_UNUSED_5A         = 5   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_UNUSED_6A         = 6   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_UNUSED_7A         = 7   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC = 8   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_UNUSED_9A         = 9   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_UNUSED_10A        = 10  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_RESERVED_11A      = 11  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC = 12  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENABLE_DC = 13  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_UNUSED_14A        = 14  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENABLE_DC = 15  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_UNUSED_16A        = 16  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_UNUSED_17A        = 17  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_RESERVED_18A      = 18  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_RESERVED_19A      = 19  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_TC_PSRO_SEL_DC    = 20  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN = 8   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_TC_BSC_WRAPSEL_DC = 28  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_TC_BSC_INTMODE_DC = 29  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_TC_BSC_INV_DC     = 30  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_TC_BSC_EXTMODE_DC = 31  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_UNUSED_32A        = 32  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_RESERVED_33A      = 33  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_RESERVED_34A      = 34  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_RESERVED_35A      = 35  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_UNUSED_36A        = 36  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_UNUSED_37A        = 37  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_RESERVED_38A      = 38  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_RESERVED_39A      = 39  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC = 40  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN = 2   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_RESERVED_42A      = 42  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_RESERVED_43A      = 43  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_CTRL_CC_DCTEST_DC = 44  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_UNUSED_45A        = 45  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_UNUSED_46A        = 46  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC = 47  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_FREE_USAGE_48A    = 48  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_FREE_USAGE_49A    = 49  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_FREE_USAGE_50A    = 50  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_FREE_USAGE_51A    = 51  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_FREE_USAGE_52A    = 52  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_FREE_USAGE_53A    = 53  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_FREE_USAGE_54A    = 54  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_FREE_USAGE_55A    = 55  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_FREE_USAGE_56A    = 56  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_FREE_USAGE_57A    = 57  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_FREE_USAGE_58A    = 58  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_FREE_USAGE_59A    = 59  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_FREE_USAGE_60A    = 60  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_FREE_USAGE_61A    = 61  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_FREE_USAGE_62A    = 62  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL0_FREE_USAGE_63A    = 63  ;

static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_0B         = 0   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_1B         = 1   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_2B         = 2   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_TC_VITL_REGION_FENCE = 3   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_TC_PERV_REGION_FENCE = 4   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_TC_REGION1_FENCE  = 5   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_TC_REGION2_FENCE  = 6   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_7B         = 7   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_8B         = 8   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_9B         = 9   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_10B        = 10  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_11B        = 11  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_12B        = 12  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_13B        = 13  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_14B        = 14  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_RESERVED          = 15  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE = 16  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_17B        = 17  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_18B        = 18  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_19B        = 19  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_20B        = 20  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_TC_PERV_MESH_CTRL = 21  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_TC_STG_ACT_EN_DC  = 22  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_23B        = 23  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_24B        = 24  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_25B        = 25  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_26B        = 26  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_27B        = 27  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_28B        = 28  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_29B        = 29  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_30B        = 30  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_CPLT_CTRL1_UNUSED_31B        = 31  ;

static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN0                = 0   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN1                = 1   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN2                = 2   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN3                = 3   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN4                = 4   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN5                = 5   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN6                = 6   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN7                = 7   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN8                = 8   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN9                = 9   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN10               = 10  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN11               = 11  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN12               = 12  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN13               = 13  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN14               = 14  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN15               = 15  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN16               = 16  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN17               = 17  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN18               = 18  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN19               = 19  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN20               = 20  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN21               = 21  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN22               = 22  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN23               = 23  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN24               = 24  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN25               = 25  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN26               = 26  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN27               = 27  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN28               = 28  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN29               = 29  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN30               = 30  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN31               = 31  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN32               = 32  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN33               = 33  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN34               = 34  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN35               = 35  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN36               = 36  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN37               = 37  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN38               = 38  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN39               = 39  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN40               = 40  ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_IN41               = 41  ;

static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_MASK_LFIR_IN       = 0   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_LOCAL_FIR_MASK_LFIR_IN_LEN   = 42  ;

static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_SPATTN_IN0                   = 0   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_SPATTN_IN1                   = 1   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_SPATTN_IN2                   = 2   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_SPATTN_IN3                   = 3   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_SPATTN_IN4                   = 4   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_SPATTN_IN5                   = 5   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_SPATTN_IN6                   = 6   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_SPATTN_IN7                   = 7   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_SPATTN_IN8                   = 8   ;
static const uint8_t P9A_OBUS_TCOB0_TCOB0_TCOB0_SPATTN_IN9                   = 9   ;

static const uint8_t P9A_OBUS_TCOB0_THERM_MODE_REG_DIS_CPM_BUBBLE_CORR       = 0   ;
static const uint8_t P9A_OBUS_TCOB0_THERM_MODE_REG_FORCE_THRES_ACT           = 1   ;
static const uint8_t P9A_OBUS_TCOB0_THERM_MODE_REG_THRES_TRIP_ENA            = 2   ;
static const uint8_t P9A_OBUS_TCOB0_THERM_MODE_REG_THRES_TRIP_ENA_LEN        = 3   ;
static const uint8_t P9A_OBUS_TCOB0_THERM_MODE_REG_DTS_SAMPLE_ENA            = 5   ;
static const uint8_t P9A_OBUS_TCOB0_THERM_MODE_REG_SAMPLE_PULSE_CNT          = 6   ;
static const uint8_t P9A_OBUS_TCOB0_THERM_MODE_REG_SAMPLE_PULSE_CNT_LEN      = 4   ;
static const uint8_t P9A_OBUS_TCOB0_THERM_MODE_REG_THRES_ENA                 = 10  ;
static const uint8_t P9A_OBUS_TCOB0_THERM_MODE_REG_THRES_ENA_LEN             = 2   ;
static const uint8_t P9A_OBUS_TCOB0_THERM_MODE_REG_DTS_TRIGGER               = 12  ;
static const uint8_t P9A_OBUS_TCOB0_THERM_MODE_REG_DTS_TRIGGER_SEL           = 13  ;
static const uint8_t P9A_OBUS_TCOB0_THERM_MODE_REG_THRES_OVERFLOW_MASK       = 14  ;
static const uint8_t P9A_OBUS_TCOB0_THERM_MODE_REG_UNUSED                    = 15  ;
static const uint8_t P9A_OBUS_TCOB0_THERM_MODE_REG_DTS_READ_SEL              = 16  ;
static const uint8_t P9A_OBUS_TCOB0_THERM_MODE_REG_DTS_READ_SEL_LEN          = 4   ;
static const uint8_t P9A_OBUS_TCOB0_THERM_MODE_REG_DTS_ENABLE_L1             = 20  ;
static const uint8_t P9A_OBUS_TCOB0_THERM_MODE_REG_DTS_ENABLE_L1_LEN         = 2   ;
static const uint8_t P9A_OBUS_TCOB0_THERM_MODE_REG_THERM_CPM_ENABLE_L1       = 35  ;
static const uint8_t P9A_OBUS_TCOB0_THERM_MODE_REG_THERM_CPM_ENABLE_L1_LEN   = 2   ;

static const uint8_t P9A_OBUS_TCOB0_TIMESTAMP_COUNTER_READ_VALUE             = 0   ;
static const uint8_t P9A_OBUS_TCOB0_TIMESTAMP_COUNTER_READ_VALUE_LEN         = 44  ;
static const uint8_t P9A_OBUS_TCOB0_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR      = 44  ;

static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_HI_DATA_REG_DATA          = 0   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_HI_DATA_REG_DATA_LEN      = 64  ;

static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_LO_DATA_REG_DATA          = 0   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_LO_DATA_REG_DATA_LEN      = 32  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS       = 32  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN   = 10  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK     = 42  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN  = 52  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING       = 53  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS  = 54  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10  ;

static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRCTRL_CONFIG_STORE_ON_TRIG_MODE = 0   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRCTRL_CONFIG_WRITE_ON_RUN_MODE = 1   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRCTRL_CONFIG_EXTEND_TRIG_MODE = 2   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRCTRL_CONFIG_EXTEND_TRIG_MODE_LEN = 8   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRCTRL_CONFIG_BANK_MODE   = 10  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRCTRL_CONFIG_ENH_MODE    = 11  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRCTRL_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRCTRL_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRCTRL_CONFIG_SELECT_CONTROL = 14  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRCTRL_CONFIG_SELECT_CONTROL_LEN = 4   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRCTRL_CONFIG_RUN_HOLD_OFF = 18  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRCTRL_CONFIG_RUN_STATUS  = 19  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRCTRL_CONFIG_RUN_STICKY  = 20  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRCTRL_CONFIG_DISABLE_BANK_EDGE_DETECT = 21  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRCTRL_CONFIG_CONTROL_UNUSED = 22  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRCTRL_CONFIG_CONTROL_UNUSED_LEN = 6   ;

static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_0_CMP_MSK_LT_B_TO_63 = 0   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_0_CMP_MSK_LT_B_TO_63_LEN = 64  ;

static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24  ;

static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_2_PATTERNA  = 0   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_2_PATTERNA_LEN = 24  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_2_PATTERNB  = 24  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_2_PATTERNB_LEN = 24  ;

static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_3_PATTERNC  = 0   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_3_PATTERNC_LEN = 24  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_3_PATTERND  = 24  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_3_PATTERND_LEN = 24  ;

static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_4_MASKA     = 0   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_4_MASKA_LEN = 24  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_4_MASKB     = 24  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_4_MASKB_LEN = 24  ;

static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_5_MASKC     = 0   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_5_MASKC_LEN = 24  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_5_MASKD     = 24  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_5_MASKD_LEN = 24  ;

static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_DISABLE_COMPRESSION = 0   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_MATCHA_MUXSEL = 2   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_MATCHA_MUXSEL_LEN = 2   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_MATCHB_MUXSEL = 4   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_MATCHB_MUXSEL_LEN = 2   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_MATCHC_MUXSEL = 6   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_MATCHC_MUXSEL_LEN = 2   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_MATCHD_MUXSEL = 8   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_MATCHD_MUXSEL_LEN = 2   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_TRIG0_OR_MASK = 10  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_TRIG0_OR_MASK_LEN = 4   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_TRIG0_AND_MASK = 14  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_TRIG0_AND_MASK_LEN = 4   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_TRIG1_OR_MASK = 18  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_TRIG1_OR_MASK_LEN = 4   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_TRIG1_AND_MASK = 22  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_TRIG1_AND_MASK_LEN = 4   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_TRIG0_NOT_MODE = 26  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_TRIG1_NOT_MODE = 27  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_MATCH_NOT_MODE = 28  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_MATCH_NOT_MODE_LEN = 4   ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_ERROR_CMP_MASK = 32  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_ERROR_CMP_PATTERN = 33  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_TRIG0_ERR_CMP = 34  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_TRIG1_ERR_CMP = 35  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36  ;
static const uint8_t P9A_OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9_SPARE_LT  = 37  ;

static const uint8_t P9A_OBUS_TCOB0_WRITE_PROTECT_ENABLE_REG_RING_LOCKING    = 0   ;
static const uint8_t P9A_OBUS_TCOB0_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING = 1   ;

static const uint8_t P9A_OBUS_TCOB0_WRITE_PROTECT_RINGS_REG_RINGS            = 0   ;
static const uint8_t P9A_OBUS_TCOB0_WRITE_PROTECT_RINGS_REG_RINGS_LEN        = 16  ;

static const uint8_t P9A_OBUS_TCOB0_XFIR_IN0                                 = 0   ;
static const uint8_t P9A_OBUS_TCOB0_XFIR_IN1                                 = 1   ;
static const uint8_t P9A_OBUS_TCOB0_XFIR_IN2                                 = 2   ;
static const uint8_t P9A_OBUS_TCOB0_XFIR_IN3                                 = 3   ;
static const uint8_t P9A_OBUS_TCOB0_XFIR_IN4                                 = 4   ;
static const uint8_t P9A_OBUS_TCOB0_XFIR_IN5                                 = 5   ;
static const uint8_t P9A_OBUS_TCOB0_XFIR_IN6                                 = 6   ;
static const uint8_t P9A_OBUS_TCOB0_XFIR_IN7                                 = 7   ;
static const uint8_t P9A_OBUS_TCOB0_XFIR_IN7_LEN                             = 19  ;
static const uint8_t P9A_OBUS_TCOB0_XFIR_IN26                                = 26  ;

static const uint8_t P9A_OBUS_TCOB0_XSTOP1_MASK_B                            = 0   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP1_ALIGNED                           = 1   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP1_TRIGGER_OPCG_ON                   = 2   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP1_WAIT_ALLWAYS                      = 3   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP1_PERV                              = 4   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP1_UNIT1                             = 5   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP1_UNIT2                             = 6   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP1_UNIT3                             = 7   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP1_UNIT4                             = 8   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP1_UNIT5                             = 9   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP1_UNIT6                             = 10  ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP1_UNIT7                             = 11  ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP1_UNIT8                             = 12  ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP1_UNIT9                             = 13  ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP1_UNIT10                            = 14  ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP1_WAIT_CYCLES                       = 48  ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP1_WAIT_CYCLES_LEN                   = 12  ;

static const uint8_t P9A_OBUS_TCOB0_XSTOP2_MASK_B                            = 0   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP2_ALIGNED                           = 1   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP2_TRIGGER_OPCG_ON                   = 2   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP2_WAIT_ALLWAYS                      = 3   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP2_PERV                              = 4   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP2_UNIT1                             = 5   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP2_UNIT2                             = 6   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP2_UNIT3                             = 7   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP2_UNIT4                             = 8   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP2_UNIT5                             = 9   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP2_UNIT6                             = 10  ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP2_UNIT7                             = 11  ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP2_UNIT8                             = 12  ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP2_UNIT9                             = 13  ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP2_UNIT10                            = 14  ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP2_WAIT_CYCLES                       = 48  ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP2_WAIT_CYCLES_LEN                   = 12  ;

static const uint8_t P9A_OBUS_TCOB0_XSTOP3_MASK_B                            = 0   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP3_ALIGNED                           = 1   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP3_TRIGGER_OPCG_ON                   = 2   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP3_WAIT_ALLWAYS                      = 3   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP3_PERV                              = 4   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP3_UNIT1                             = 5   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP3_UNIT2                             = 6   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP3_UNIT3                             = 7   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP3_UNIT4                             = 8   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP3_UNIT5                             = 9   ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP3_UNIT6                             = 10  ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP3_UNIT7                             = 11  ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP3_UNIT8                             = 12  ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP3_UNIT9                             = 13  ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP3_UNIT10                            = 14  ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP3_WAIT_CYCLES                       = 48  ;
static const uint8_t P9A_OBUS_TCOB0_XSTOP3_WAIT_CYCLES_LEN                   = 12  ;

static const uint8_t P9A_OBUS_TCOB0_XTRA_TRACE_MODE_DATA                     = 0   ;
static const uint8_t P9A_OBUS_TCOB0_XTRA_TRACE_MODE_DATA_LEN                 = 42  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE0_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE1_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE2_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS0_SLICE3_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE0_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE1_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE2_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS1_SLICE3_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE0_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE1_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE2_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS2_SLICE3_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE0_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE1_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE2_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS3_SLICE3_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE0_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE1_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE2_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS4_SLICE3_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE0_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE1_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE2_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_CNTL1G_PL_TX_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 5   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_CNTL1G_PL_TX_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_CNTL1G_PL_TX_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_CNTL1G_PL_TX_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_CNTL2_O_PL_IORESET      = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_CNTL3_EO_PL_TDR_ENABLE  = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_FIR_ERROR_INJECT_PL_ERR_INJ = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_FIR_MASK_PL_ERRS        = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_MODE1_PL_LANE_PDWN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_MODE1_PL_LANE_INVERT    = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_MODE1_PL_LANE_QUIESCE   = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_MODE1_PL_LANE_QUIESCE_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_MODE1_PL_PSAVE_REQ_DIS  = 54  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_MODE1_PL_ERR_INJ_A_ENABLE = 55  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_MODE1_PL_ERR_INJ_B_ENABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_MODE1_PL_SPARE_MODE_0   = 60  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_MODE1_PL_SPARE_MODE_1   = 61  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_MODE1_PL_SPARE_MODE_2   = 62  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_MODE1_PL_SPARE_MODE_3   = 63  ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_MODE2_PL_FIFO_L2U_DLY   = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_MODE2_PL_FIFO_L2U_DLY_LEN = 3   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_MODE2_PL_UNLOAD_CLK_DISABLE = 56  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_MODE2_PL_RXCAL          = 57  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_MODE2_PL_UNLOAD_SEL     = 58  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_MODE2_PL_UNLOAD_SEL_LEN = 3   ;

static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_STAT1_PL_LANE_BIST_ERR  = 48  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_STAT1_PL_LANE_BIST_ACTVITY_DET = 49  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_STAT1_PL_SEG_TEST_STATUS = 50  ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_STAT1_PL_SEG_TEST_STATUS_LEN = 2   ;
static const uint8_t P9A_OBUS_TX0_TXPACKS5_SLICE3_TX_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63  ;

static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL1_EO_PG_PSEG_PRE_EN           = 51  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL1_EO_PG_PSEG_PRE_EN_LEN       = 5   ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL1_EO_PG_PSEG_PRE_SEL          = 56  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL1_EO_PG_PSEG_PRE_SEL_LEN      = 5   ;

static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL1_O_PG_PSEG_POST_EN           = 49  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL1_O_PG_PSEG_POST_EN_LEN       = 7   ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL1_O_PG_PSEG_POST_SEL          = 56  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL1_O_PG_PSEG_POST_SEL_LEN      = 7   ;

static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL2_EO_PG_NSEG_PRE_EN           = 51  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL2_EO_PG_NSEG_PRE_EN_LEN       = 5   ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL2_EO_PG_NSEG_PRE_SEL          = 56  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL2_EO_PG_NSEG_PRE_SEL_LEN      = 5   ;

static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL2_O_PG_NSEG_POST_EN           = 49  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL2_O_PG_NSEG_POST_EN_LEN       = 7   ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL2_O_PG_NSEG_POST_SEL          = 56  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL2_O_PG_NSEG_POST_SEL_LEN      = 7   ;

static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL3_EO_PG_PSEG_MARGINPU_EN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL3_EO_PG_PSEG_MARGINPU_EN_LEN  = 8   ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL3_EO_PG_PSEG_MARGINPD_EN      = 56  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL3_EO_PG_PSEG_MARGINPD_EN_LEN  = 8   ;

static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL4_EO_PG_NSEG_MARGINPU_EN      = 48  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL4_EO_PG_NSEG_MARGINPU_EN_LEN  = 8   ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL4_EO_PG_NSEG_MARGINPD_EN      = 56  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL4_EO_PG_NSEG_MARGINPD_EN_LEN  = 8   ;

static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL5_EO_PG_MARGINPU_SEL          = 48  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL5_EO_PG_MARGINPU_SEL_LEN      = 8   ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL5_EO_PG_MARGINPD_SEL          = 56  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL5_EO_PG_MARGINPD_SEL_LEN      = 8   ;

static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL6_EO_PG_PSEG_MAIN_EN          = 51  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL6_EO_PG_PSEG_MAIN_EN_LEN      = 7   ;

static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL7_EO_PG_NSEG_MAIN_EN          = 51  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_CNTL7_EO_PG_NSEG_MAIN_EN_LEN      = 7   ;

static const uint8_t P9A_OBUS_TX0_TX_CTLSM_MODE1_EO_PG_SEG_TEST_MODE         = 50  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_MODE1_EO_PG_SEG_TEST_MODE_LEN     = 8   ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_MODE1_EO_PG_FFE_BOOST_EN          = 59  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_MODE1_EO_PG_SEG_TEST_LEAKAGE_CTRL = 61  ;

static const uint8_t P9A_OBUS_TX0_TX_CTLSM_SPARE_MODE_PG_CTL_SM_0            = 48  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_SPARE_MODE_PG_CTL_SM_1            = 49  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_SPARE_MODE_PG_CTL_SM_2            = 50  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_SPARE_MODE_PG_CTL_SM_3            = 51  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_SPARE_MODE_PG_CTL_SM_4            = 52  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_SPARE_MODE_PG_CTL_SM_5            = 53  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_SPARE_MODE_PG_CTL_SM_6            = 54  ;
static const uint8_t P9A_OBUS_TX0_TX_CTLSM_SPARE_MODE_PG_CTL_SM_7            = 55  ;

static const uint8_t P9A_OBUS_TX0_TX_CTLSM_STAT1_EO_PG_TX_BIST_DONE_RO_SIGNAL = 50  ;

static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL10_EO_PG_TDR_PULSE_WIDTH        = 48  ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL10_EO_PG_TDR_PULSE_WIDTH_LEN    = 8   ;

static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL2_EO_PG_ERR_INJ_A_FINE_SEL      = 48  ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL2_EO_PG_ERR_INJ_A_FINE_SEL_LEN  = 3   ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL2_EO_PG_ERR_INJ_A_COARSE_SEL    = 51  ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL2_EO_PG_ERR_INJ_A_COARSE_SEL_LEN = 4   ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL2_EO_PG_ERR_INJ_A_BER_SEL       = 55  ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL2_EO_PG_ERR_INJ_A_BER_SEL_LEN   = 6   ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL2_EO_PG_ERR_INJ_ENABLE          = 61  ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL2_EO_PG_ERR_INJ_CLOCK_ENABLE    = 62  ;

static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL3_EO_PG_ERR_INJ_B_FINE_SEL      = 48  ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL3_EO_PG_ERR_INJ_B_FINE_SEL_LEN  = 3   ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL3_EO_PG_ERR_INJ_B_COARSE_SEL    = 51  ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL3_EO_PG_ERR_INJ_B_COARSE_SEL_LEN = 4   ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL3_EO_PG_ERR_INJ_B_BER_SEL       = 55  ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL3_EO_PG_ERR_INJ_B_BER_SEL_LEN   = 6   ;

static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL8_EO_PG_TDR_DAC_CNTL            = 48  ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL8_EO_PG_TDR_DAC_CNTL_LEN        = 8   ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL8_EO_PG_TDR_PHASE_SEL           = 57  ;

static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL9_EO_PG_TDR_PULSE_OFFSET        = 48  ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTL9_EO_PG_TDR_PULSE_OFFSET_LEN    = 14  ;

static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTLG1_EO_PG_DRV_DATA_PATTERN_GCRMSG = 50  ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_CNTLG1_EO_PG_DRV_DATA_PATTERN_GCRMSG_LEN = 4   ;

static const uint8_t P9A_OBUS_TX0_TX_CTL_MODE1_EO_PG_CLKDIST_PDWN            = 48  ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_MODE1_EO_PG_CLKDIST_PDWN_LEN        = 3   ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_MODE1_EO_PG_BIST_EN                 = 51  ;
static const uint8_t P9A_OBUS_TX0_TX_CTL_MODE1_EO_PG_EXBIST_MODE             = 52  ;

static const uint8_t P9A_OBUS_TX0_TX_FIR_ERROR_INJECT_PG_ERR_INJ             = 48  ;
static const uint8_t P9A_OBUS_TX0_TX_FIR_ERROR_INJECT_PG_ERR_INJ_LEN         = 5   ;

static const uint8_t P9A_OBUS_TX0_TX_FIR_MASK_PG_ERRS                        = 48  ;
static const uint8_t P9A_OBUS_TX0_TX_FIR_MASK_PG_ERRS_LEN                    = 5   ;
static const uint8_t P9A_OBUS_TX0_TX_FIR_MASK_PG_PL_ERR                      = 63  ;

static const uint8_t P9A_OBUS_TX0_TX_FIR_PG_TX_PG_FIR_ERR_TX_SM_REGS_RO_SIGNAL = 48  ;
static const uint8_t P9A_OBUS_TX0_TX_FIR_PG_TX_PG_FIR_ERR_GCR_BUFF_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_TX0_TX_FIR_PG_TX_PG_FIR_ERR_GCRS_LD_SM_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_TX0_TX_FIR_PG_TX_PG_FIR_ERR_GCRS_UNLD_SM_RO_SIGNAL = 51  ;
static const uint8_t P9A_OBUS_TX0_TX_FIR_PG_TX_PG_FIR_ERR_CTL_REGS_RO_SIGNAL = 52  ;
static const uint8_t P9A_OBUS_TX0_TX_FIR_PG_TX_PL_FIR_ERR_RO_SIGNAL          = 63  ;

static const uint8_t P9A_OBUS_TX0_TX_FIR_RESET_PG_CLR_PAR_ERRS               = 62  ;
static const uint8_t P9A_OBUS_TX0_TX_FIR_RESET_PG_RESET                      = 63  ;

static const uint8_t P9A_OBUS_TX0_TX_ID1_PG_BUS_ID                           = 48  ;
static const uint8_t P9A_OBUS_TX0_TX_ID1_PG_BUS_ID_LEN                       = 6   ;

static const uint8_t P9A_OBUS_TX0_TX_SPARE_MODE_PG_0                         = 48  ;
static const uint8_t P9A_OBUS_TX0_TX_SPARE_MODE_PG_1                         = 49  ;
static const uint8_t P9A_OBUS_TX0_TX_SPARE_MODE_PG_2                         = 50  ;
static const uint8_t P9A_OBUS_TX0_TX_SPARE_MODE_PG_3                         = 51  ;
static const uint8_t P9A_OBUS_TX0_TX_SPARE_MODE_PG_4                         = 52  ;
static const uint8_t P9A_OBUS_TX0_TX_SPARE_MODE_PG_5                         = 53  ;
static const uint8_t P9A_OBUS_TX0_TX_SPARE_MODE_PG_6                         = 54  ;
static const uint8_t P9A_OBUS_TX0_TX_SPARE_MODE_PG_7                         = 55  ;
static const uint8_t P9A_OBUS_TX0_TX_SPARE_MODE_PG_8_9                       = 56  ;
static const uint8_t P9A_OBUS_TX0_TX_SPARE_MODE_PG_8_9_LEN                   = 2   ;

static const uint8_t P9A_OBUS_TX_IMPCAL2_PB_TX_ZCAL_ANS_NOT_FOUND_ERROR_RO_SIGNAL = 49  ;
static const uint8_t P9A_OBUS_TX_IMPCAL2_PB_TX_ZCAL_ANS_RANGE_ERROR_RO_SIGNAL = 50  ;
static const uint8_t P9A_OBUS_TX_IMPCAL2_PB_TX_ZCAL_TEST_ENABLE_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX_IMPCAL2_PB_TX_ZCAL_TEST_STATUS_RO_SIGNAL    = 54  ;
static const uint8_t P9A_OBUS_TX_IMPCAL2_PB_TX_ZCAL_TEST_DONE_RO_SIGNAL      = 55  ;

static const uint8_t P9A_OBUS_TX_IMPCAL_NVAL_PB_ZCAL_N                       = 48  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_NVAL_PB_ZCAL_N_LEN                   = 9   ;

static const uint8_t P9A_OBUS_TX_IMPCAL_PB_TX_ZCAL_REQ_WO_PULSE_SLOW_SIGNAL  = 49  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_PB_TX_ZCAL_DONE_RO_SIGNAL            = 50  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_PB_TX_ZCAL_ERROR_RO_SIGNAL           = 51  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_PB_TX_ZCAL_BUSY_RO_SIGNAL            = 52  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_PB_TX_ZCAL_FORCE_SAMPLE_WO_PULSE_SLOW_SIGNAL = 53  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_PB_TX_ZCAL_CMP_OUT_RO_SIGNAL         = 54  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_PB_TX_ZCAL_SAMPLE_CNT_RO_SIGNAL      = 55  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_PB_TX_ZCAL_SAMPLE_CNT_RO_SIGNAL_LEN  = 9   ;

static const uint8_t P9A_OBUS_TX_IMPCAL_PVAL_PB_ZCAL_P                       = 48  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_PVAL_PB_ZCAL_P_LEN                   = 9   ;

static const uint8_t P9A_OBUS_TX_IMPCAL_P_4X_PB_ZCAL                         = 48  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_P_4X_PB_ZCAL_LEN                     = 5   ;

static const uint8_t P9A_OBUS_TX_IMPCAL_SWO1_PB_ZCAL_SWO_EN                  = 48  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_SWO1_PB_ZCAL_SWO_CAL_SEGS            = 49  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_SWO1_PB_ZCAL_SWO_CMP_INV             = 50  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_SWO1_PB_ZCAL_SWO_CMP_OFFSET          = 51  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_SWO1_PB_ZCAL_SWO_CMP_RESET           = 52  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_SWO1_PB_ZCAL_SWO_POWERDOWN           = 53  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_SWO1_PB_ZCAL_SWO_TCOIL               = 54  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_SWO1_PB_ZCAL_RANGE_CHECK             = 55  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_SWO1_PB_ZCAL_CYA_DATA_INV            = 56  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_SWO1_PB_ZCAL_TEST_OVR_2R             = 57  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_SWO1_PB_ZCAL_TEST_OVR_1R             = 58  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_SWO1_PB_ZCAL_TEST_OVR_4X_SEG         = 59  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_SWO1_PB_ZCAL_TEST_CLK_DIV            = 60  ;

static const uint8_t P9A_OBUS_TX_IMPCAL_SWO2_PB_ZCAL_SM_MIN_VAL              = 48  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_SWO2_PB_ZCAL_SM_MIN_VAL_LEN          = 7   ;
static const uint8_t P9A_OBUS_TX_IMPCAL_SWO2_PB_ZCAL_SM_MAX_VAL              = 55  ;
static const uint8_t P9A_OBUS_TX_IMPCAL_SWO2_PB_ZCAL_SM_MAX_VAL_LEN          = 7   ;

#endif
