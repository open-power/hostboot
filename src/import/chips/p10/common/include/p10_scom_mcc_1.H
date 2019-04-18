/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_1.H $        */
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

#ifndef __p10_scom_mcc_1_H_
#define __p10_scom_mcc_1_H_


namespace scomt
{
namespace mcc
{


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ATCL_CL_CLSCOM_MCPERF2 = 0x0c010c34ull;

static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0 = 0;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1 = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2 = 6;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3 = 9;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE = 12;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_ALT_WRBUF_M = 13;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_ALT_WRBUF_M_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PERF = 17;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PERF_LEN = 2;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23 = 19;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23_LEN = 5;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL = 24;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL = 28;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL = 32;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL = 33;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL = 34;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL = 35;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_RESERVED36 = 36;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG = 37;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_ALT_M = 40;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_ALT_M_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN = 44;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN_LEN = 5;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_RESERVED_49 = 49;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF = 50;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF_LEN = 5;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH = 55;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL = 59;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL_LEN = 2;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD = 61;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_RESERVED_62 = 62;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES = 63;
// mcc/reg00065.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CONTROL = 0x0c01100bull;

static const uint32_t CONTROL_0_PHY_TRAINING = 0;
static const uint32_t CONTROL_0_STARTUP = 1;
static const uint32_t CONTROL_0_HOLD_PATT_A = 2;
static const uint32_t CONTROL_0_HOLD_PATT_B = 3;
static const uint32_t CONTROL_0_RUN_LANE_DISABLE = 4;
static const uint32_t CONTROL_0_RUN_LANE_OVERRIDE = 5;
static const uint32_t CONTROL_0_IGNORE_PHY = 6;
static const uint32_t CONTROL_0_IGNORE_FENCE = 7;
static const uint32_t CONTROL_0_ERR_INJ_COMMAND = 8;
static const uint32_t CONTROL_0_ERR_INJ_COMMAND_LEN = 4;
static const uint32_t CONTROL_0_ERR_INJ_COMMAND_LANES = 12;
static const uint32_t CONTROL_0_ERR_INJ_COMMAND_LANES_LEN = 9;
static const uint32_t CONTROL_0_COMMAND = 28;
static const uint32_t CONTROL_0_COMMAND_LEN = 4;
static const uint32_t CONTROL_1_PHY_TRAINING = 32;
static const uint32_t CONTROL_1_STARTUP = 33;
static const uint32_t CONTROL_1_HOLD_PATT_A = 34;
static const uint32_t CONTROL_1_HOLD_PATT_B = 35;
static const uint32_t CONTROL_1_RUN_LANE_DISABLE = 36;
static const uint32_t CONTROL_1_RUN_LANE_OVERRIDE = 37;
static const uint32_t CONTROL_1_IGNORE_PHY = 38;
static const uint32_t CONTROL_1_IGNORE_FENCE = 39;
static const uint32_t CONTROL_1_ERR_INJ_COMMAND = 40;
static const uint32_t CONTROL_1_ERR_INJ_COMMAND_LEN = 4;
static const uint32_t CONTROL_1_ERR_INJ_COMMAND_LANES = 44;
static const uint32_t CONTROL_1_ERR_INJ_COMMAND_LANES_LEN = 9;
static const uint32_t CONTROL_1_COMMAND = 60;
static const uint32_t CONTROL_1_COMMAND_LEN = 4;
// mcc/reg00065.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_DECRYPT_CRYPTOKEY1A = 0x0c010f7aull;

static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A_LEN = 64;
// mcc/reg00065.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t LINK0_QUALITY = 0x0c011026ull;

static const uint32_t LINK0_QUALITY_TX_BW = 1;
static const uint32_t LINK0_QUALITY_TX_BW_LEN = 11;
static const uint32_t LINK0_QUALITY_RX_BW = 13;
static const uint32_t LINK0_QUALITY_RX_BW_LEN = 11;
static const uint32_t LINK0_QUALITY_ERROR_RATE = 25;
static const uint32_t LINK0_QUALITY_ERROR_RATE_LEN = 23;
static const uint32_t LINK0_QUALITY_SPARE_COUNTER_1 = 49;
static const uint32_t LINK0_QUALITY_SPARE_COUNTER_1_LEN = 7;
static const uint32_t LINK0_QUALITY_SPARE_COUNTER_2 = 57;
static const uint32_t LINK0_QUALITY_SPARE_COUNTER_2_LEN = 7;
// mcc/reg00065.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t LINK1_TX_LANE_CONTROL = 0x0c011011ull;

static const uint32_t LINK1_TX_LANE_CONTROL_00_CONTROL = 0;
static const uint32_t LINK1_TX_LANE_CONTROL_00_CONTROL_LEN = 4;
static const uint32_t LINK1_TX_LANE_CONTROL_01_CONTROL = 4;
static const uint32_t LINK1_TX_LANE_CONTROL_01_CONTROL_LEN = 4;
static const uint32_t LINK1_TX_LANE_CONTROL_02_CONTROL = 8;
static const uint32_t LINK1_TX_LANE_CONTROL_02_CONTROL_LEN = 4;
static const uint32_t LINK1_TX_LANE_CONTROL_03_CONTROL = 12;
static const uint32_t LINK1_TX_LANE_CONTROL_03_CONTROL_LEN = 4;
static const uint32_t LINK1_TX_LANE_CONTROL_04_CONTROL = 16;
static const uint32_t LINK1_TX_LANE_CONTROL_04_CONTROL_LEN = 4;
static const uint32_t LINK1_TX_LANE_CONTROL_05_CONTROL = 20;
static const uint32_t LINK1_TX_LANE_CONTROL_05_CONTROL_LEN = 4;
static const uint32_t LINK1_TX_LANE_CONTROL_06_CONTROL = 24;
static const uint32_t LINK1_TX_LANE_CONTROL_06_CONTROL_LEN = 4;
static const uint32_t LINK1_TX_LANE_CONTROL_07_CONTROL = 28;
static const uint32_t LINK1_TX_LANE_CONTROL_07_CONTROL_LEN = 4;
static const uint32_t LINK1_TX_LANE_CONTROL_08_CONTROL = 32;
static const uint32_t LINK1_TX_LANE_CONTROL_08_CONTROL_LEN = 4;
static const uint32_t LINK1_TX_LANE_CONTROL__FAILED = 48;
static const uint32_t LINK1_TX_LANE_CONTROL__FAILED_LEN = 9;
// mcc/reg00065.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t WDF_DSTL_ECC = 0x0c010f65ull;

static const uint32_t WDF_DSTL_ECC_0_ERR_TYPE = 0;
static const uint32_t WDF_DSTL_ECC_0_ERR_TYPE_LEN = 3;
static const uint32_t WDF_DSTL_ECC_0_SYNDROME = 8;
static const uint32_t WDF_DSTL_ECC_0_SYNDROME_LEN = 8;
static const uint32_t WDF_DSTL_ECC_1_ERR_TYPE = 16;
static const uint32_t WDF_DSTL_ECC_1_ERR_TYPE_LEN = 3;
static const uint32_t WDF_DSTL_ECC_1_SYNDROME = 24;
static const uint32_t WDF_DSTL_ECC_1_SYNDROME_LEN = 8;
static const uint32_t WDF_DSTL_ECC_2_ERR_TYPE = 32;
static const uint32_t WDF_DSTL_ECC_2_ERR_TYPE_LEN = 3;
static const uint32_t WDF_DSTL_ECC_2_SYNDROME = 40;
static const uint32_t WDF_DSTL_ECC_2_SYNDROME_LEN = 8;
static const uint32_t WDF_DSTL_ECC_3_ERR_TYPE = 48;
static const uint32_t WDF_DSTL_ECC_3_ERR_TYPE_LEN = 3;
static const uint32_t WDF_DSTL_ECC_3_SYNDROME = 56;
static const uint32_t WDF_DSTL_ECC_3_SYNDROME_LEN = 8;
// mcc/reg00065.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t WDF_ECC = 0x0c010f61ull;

static const uint32_t WDF_ECC_0_ERR_TYPE = 0;
static const uint32_t WDF_ECC_0_ERR_TYPE_LEN = 3;
static const uint32_t WDF_ECC_0_SYNDROME = 8;
static const uint32_t WDF_ECC_0_SYNDROME_LEN = 8;
static const uint32_t WDF_ECC_1_ERR_TYPE = 16;
static const uint32_t WDF_ECC_1_ERR_TYPE_LEN = 3;
static const uint32_t WDF_ECC_1_SYNDROME = 24;
static const uint32_t WDF_ECC_1_SYNDROME_LEN = 8;
static const uint32_t WDF_ECC_2_ERR_TYPE = 32;
static const uint32_t WDF_ECC_2_ERR_TYPE_LEN = 3;
static const uint32_t WDF_ECC_2_SYNDROME = 40;
static const uint32_t WDF_ECC_2_SYNDROME_LEN = 8;
static const uint32_t WDF_ECC_3_ERR_TYPE = 48;
static const uint32_t WDF_ECC_3_ERR_TYPE_LEN = 3;
static const uint32_t WDF_ECC_3_SYNDROME = 56;
static const uint32_t WDF_ECC_3_SYNDROME_LEN = 8;
// mcc/reg00065.H

}
}
#include "mcc/reg00065.H"
#endif
