/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_a.H $        */
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

#ifndef __p10_scom_mcc_a_H_
#define __p10_scom_mcc_a_H_


namespace scomt
{
namespace mcc
{


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ATCL_CL_CLSCOM_MCERRINJ = 0x0c010c38ull;

static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_WB_ERR_INJ = 0;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_WB_ERR_INJ_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_RESERVED3_7 = 3;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_RESERVED3_7_LEN = 5;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_CL_DEBUG_SEL = 8;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_CL_DEBUG_SEL_LEN = 32;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_CLX_DEBUG_SUM_MASK = 40;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_CLX_DEBUG_SUM_MASK_LEN = 22;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER = 62;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_RESERVED63 = 63;
// mcc/reg00074.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CONFIG = 0x0c01100aull;

static const uint32_t CONFIG_LINK_PAIR = 0;
static const uint32_t CONFIG_DISABLE_SL_ECC = 1;
static const uint32_t CONFIG_SL_UE_CRC_ERR = 4;
static const uint32_t CONFIG_REPORT_SL_CHKBIT_ERR = 5;
static const uint32_t CONFIG_BW_SAMPLE_SIZE = 6;
static const uint32_t CONFIG_BW_WINDOW_SIZE = 7;
static const uint32_t CONFIG_PACKET_DELAY_LIMIT = 11;
static const uint32_t CONFIG_PACKET_DELAY_LIMIT_LEN = 5;
static const uint32_t CONFIG_TDM_DELAY = 16;
static const uint32_t CONFIG_TDM_DELAY_LEN = 4;
static const uint32_t CONFIG_RECAL_TIMER = 29;
static const uint32_t CONFIG_RECAL_TIMER_LEN = 15;
static const uint32_t CONFIG_PSAVE_TIMEOUT = 44;
static const uint32_t CONFIG_PSAVE_TIMEOUT_LEN = 4;
static const uint32_t CONFIG_TIMEOUT = 48;
static const uint32_t CONFIG_TIMEOUT_LEN = 4;
static const uint32_t CONFIG_TIMER_1US = 52;
static const uint32_t CONFIG_TIMER_1US_LEN = 12;
// mcc/reg00074.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t DLL_STATUS = 0x0c011028ull;

static const uint32_t DLL_STATUS_0_CURRENT_STATE = 4;
static const uint32_t DLL_STATUS_0_CURRENT_STATE_LEN = 4;
static const uint32_t DLL_STATUS_0_PRIOR_STATE = 12;
static const uint32_t DLL_STATUS_0_PRIOR_STATE_LEN = 4;
static const uint32_t DLL_STATUS_0_OPTICS_RST_B = 16;
static const uint32_t DLL_STATUS_0_OPTICS_IRQ = 17;
static const uint32_t DLL_STATUS_0_TRAINING = 18;
static const uint32_t DLL_STATUS_0_MAX_PKT_TIMER = 19;
static const uint32_t DLL_STATUS_0_MAX_PKT_TIMER_LEN = 5;
static const uint32_t DLL_STATUS_1_CURRENT_STATE = 28;
static const uint32_t DLL_STATUS_1_CURRENT_STATE_LEN = 4;
static const uint32_t DLL_STATUS_1_PRIOR_STATE = 36;
static const uint32_t DLL_STATUS_1_PRIOR_STATE_LEN = 4;
static const uint32_t DLL_STATUS_1_OPTICS_RST_B = 40;
static const uint32_t DLL_STATUS_1_OPTICS_IRQ = 41;
static const uint32_t DLL_STATUS_1_TRAINING = 42;
static const uint32_t DLL_STATUS_1_MAX_PKT_TIMER = 43;
static const uint32_t DLL_STATUS_1_MAX_PKT_TIMER_LEN = 5;
static const uint32_t DLL_STATUS_0_LINK_CAP_VALID = 62;
static const uint32_t DLL_STATUS_1_LINK_CAP_VALID = 63;
// mcc/reg00074.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t DSTL_DSTLERRRPT = 0x0c010d0cull;

static const uint32_t DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 0;
static const uint32_t DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 1;
static const uint32_t DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT = 2;
static const uint32_t DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT = 3;
static const uint32_t DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 4;
static const uint32_t DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT = 5;
static const uint32_t DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT = 6;
static const uint32_t DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT = 7;
static const uint32_t DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT = 8;
static const uint32_t DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT = 9;
static const uint32_t DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT = 10;
static const uint32_t DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 11;
static const uint32_t DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 12;
static const uint32_t DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT = 13;
static const uint32_t DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT = 14;
static const uint32_t DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 15;
static const uint32_t DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT = 16;
static const uint32_t DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT = 17;
static const uint32_t DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT = 18;
static const uint32_t DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT = 19;
static const uint32_t DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT = 20;
static const uint32_t DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT = 21;
static const uint32_t DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT = 22;
static const uint32_t DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT = 23;
static const uint32_t DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT = 24;
static const uint32_t DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT = 25;
static const uint32_t DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT = 26;
static const uint32_t DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT = 27;
static const uint32_t DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT = 28;
static const uint32_t DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT = 29;
static const uint32_t DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT = 30;
static const uint32_t DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT = 31;
static const uint32_t DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT = 32;
static const uint32_t DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT = 33;
static const uint32_t DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT = 34;
static const uint32_t DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT = 35;
static const uint32_t DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 36;
static const uint32_t DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 37;
static const uint32_t DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 38;
static const uint32_t DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 39;
static const uint32_t DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT = 40;
static const uint32_t DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT = 41;
static const uint32_t DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE = 62;
static const uint32_t DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE = 63;
// mcc/reg00074.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t DSTL_DSTLFIRWOF = 0x0c010d08ull;

static const uint32_t DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF = 0;
static const uint32_t DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF_LEN = 35;
// mcc/reg00074.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t DSTL_DSTLPSAVE0 = 0x0c010d12ull;

static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE = 0;
static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE_LEN = 2;
static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH = 2;
static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH_LEN = 3;
static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE = 5;
static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE_LEN = 3;
static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT = 8;
static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE = 16;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE_LEN = 2;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH = 18;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH_LEN = 3;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE = 21;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE_LEN = 3;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT = 24;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL = 32;
static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL = 36;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t DSTL_DSTLPSAVE0_RESERVED_40_47 = 40;
static const uint32_t DSTL_DSTLPSAVE0_RESERVED_40_47_LEN = 8;
// mcc/reg00074.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t OPTICAL_CONFIG = 0x0c01100full;

static const uint32_t OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT = 0;
static const uint32_t OPTICAL_CONFIG_CONFIG_DISABLE_CLEAR_BAD_LANE_COUNT = 1;
static const uint32_t OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE = 2;
static const uint32_t OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR = 3;
static const uint32_t OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION = 4;
static const uint32_t OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION_LEN = 4;
static const uint32_t OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX = 9;
static const uint32_t OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX_LEN = 7;
static const uint32_t OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT = 16;
static const uint32_t OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION = 20;
static const uint32_t OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION_LEN = 4;
static const uint32_t OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX = 25;
static const uint32_t OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX_LEN = 7;
static const uint32_t OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER = 32;
static const uint32_t OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER = 33;
static const uint32_t OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP = 39;
static const uint32_t OPTICAL_CONFIG_LINK0_RX_LANE_SWAP = 40;
static const uint32_t OPTICAL_CONFIG_LINK0_TX_LANE_SWAP = 41;
static const uint32_t OPTICAL_CONFIG_LINK1_RX_LANE_SWAP = 42;
static const uint32_t OPTICAL_CONFIG_LINK1_TX_LANE_SWAP = 43;
static const uint32_t OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW = 44;
static const uint32_t OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW_LEN = 4;
static const uint32_t OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START = 48;
static const uint32_t OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START_LEN = 4;
static const uint32_t OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH = 52;
static const uint32_t OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH_LEN = 4;
static const uint32_t OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS = 59;
static const uint32_t OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT = 60;
static const uint32_t OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT_LEN = 4;
// mcc/reg00074.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RETRAIN_THRESHOLD = 0x0c01101aull;

static const uint32_t RETRAIN_THRESHOLD_TB_SEL = 0;
static const uint32_t RETRAIN_THRESHOLD_TB_SEL_LEN = 4;
static const uint32_t RETRAIN_THRESHOLD_TAP_SEL = 4;
static const uint32_t RETRAIN_THRESHOLD_TAP_SEL_LEN = 4;
static const uint32_t RETRAIN_THRESHOLD_ENABLE = 8;
static const uint32_t RETRAIN_THRESHOLD_ENABLE_LEN = 9;
static const uint32_t RETRAIN_THRESHOLD_LINK0_CLEAR = 26;
static const uint32_t RETRAIN_THRESHOLD_LINK1_CLEAR = 27;
static const uint32_t RETRAIN_THRESHOLD_DIS_TB_CLEAR = 28;
static const uint32_t RETRAIN_THRESHOLD_DIS_TAP_CLEAR = 29;
static const uint32_t RETRAIN_THRESHOLD_DIS_TAP_STOP = 30;
static const uint32_t RETRAIN_THRESHOLD_LINK0_COUNT = 32;
static const uint32_t RETRAIN_THRESHOLD_LINK0_COUNT_LEN = 16;
static const uint32_t RETRAIN_THRESHOLD_LINK1_COUNT = 48;
static const uint32_t RETRAIN_THRESHOLD_LINK1_COUNT_LEN = 16;
// mcc/reg00074.H

}
}
#include "mcc/reg00074.H"
#endif
