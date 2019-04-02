/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc.H $          */
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

#ifndef __mcc_H_
#define __mcc_H_


namespace scomt
{
namespace mcc
{


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ATCL_CL_CLSCOM_MCAMOC = 0x0c000035ull;

static const uint32_t ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN = 0;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0 = 1;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1 = 2;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC = 3;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES = 4;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES_LEN = 25;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT = 29;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO = 32;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_RESERVED33_47 = 33;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_RESERVED33_47_LEN = 15;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ATCL_CL_CLSCOM_MCBUSYQ = 0x0c000037ull;

static const uint32_t ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS = 0;
static const uint32_t ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT = 1;
static const uint32_t ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0 = 4;
static const uint32_t ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0_LEN = 10;
static const uint32_t ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1 = 14;
static const uint32_t ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1_LEN = 10;
static const uint32_t ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2 = 24;
static const uint32_t ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2_LEN = 10;
static const uint32_t ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY = 34;
static const uint32_t ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43 = 35;
static const uint32_t ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43_LEN = 9;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ATCL_CL_CLSCOM_MCEBUSCL = 0x0c000039ull;

static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0 = 0;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1 = 1;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2 = 2;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3 = 3;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA = 4;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB = 5;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_7 = 6;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_7_LEN = 2;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHA = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHA_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHB = 16;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHB_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHC = 24;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHC_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_RESERVED32_35 = 32;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_RESERVED32_35_LEN = 4;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ATCL_CL_CLSCOM_MCEPSQ = 0x0c000036ull;

static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON = 0;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON = 16;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON = 24;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON = 32;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON = 40;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_EPS_EPSILON = 48;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_EPS_EPSILON_LEN = 8;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ATCL_CL_CLSCOM_MCERRINJ = 0x0c000038ull;

static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_WDF_ERR_INJECT0 = 0;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_WDF_ERR_INJECT0_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_WRITE_ERR_INJECT0 = 4;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_WRITE_ERR_INJECT0_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_CL_DEBUG_SEL = 8;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_CL_DEBUG_SEL_LEN = 32;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_CLX_DEBUG_SUM_MASK = 40;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_CLX_DEBUG_SUM_MASK_LEN = 22;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER = 62;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_RESERVED63 = 63;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ATCL_CL_CLSCOM_MCPERF0 = 0x0c000033ull;

static const uint32_t ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ = 0;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_RESERVED1 = 1;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE = 2;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE_LEN = 6;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT = 8;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD = 12;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD = 16;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT = 20;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_LEN = 5;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT = 25;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT_LEN = 5;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT = 30;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT_LEN = 5;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT = 35;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD = 39;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT = 43;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_RESERVED47_50 = 47;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_RESERVED47_50_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE = 51;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE = 52;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE_LEN = 6;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL = 58;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL_LEN = 2;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD = 60;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD_LEN = 4;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ATCL_CL_CLSCOM_MCPERF2 = 0x0c000034ull;

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
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ATCL_CL_CLSCOM_MCPERF3 = 0x0c00003bull;

static const uint32_t ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL = 0;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP = 1;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY = 2;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00 = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01 = 6;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10 = 9;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11 = 12;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0 = 15;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1 = 19;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2 = 23;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3 = 27;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE = 31;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE = 32;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_MCPERF3_EN_MDI_UPDATE_MIRROR = 33;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_PF_DROP_IF_CNT = 34;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_PF_DROP_IF_CNT_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD = 37;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD = 38;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL = 39;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL = 40;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP = 41;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW = 42;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY = 43;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_WRAP_MODE = 44;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL = 45;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD = 46;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD = 47;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL = 48;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL = 51;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY = 54;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL = 55;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_RESERVED_56_63 = 56;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_RESERVED_56_63_LEN = 8;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ATCL_CL_CLSCOM_MCPERF4 = 0x0c000032ull;

static const uint32_t ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY = 0;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY = 1;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ = 2;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ_LEN = 7;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE = 9;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE_LEN = 7;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF = 16;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF_LEN = 7;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF = 23;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF_LEN = 7;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_RESERVED30_31 = 30;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_RESERVED30_31_LEN = 2;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ATCL_CL_CLSCOM_MCWAT = 0x0c00003aull;

static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CMD_STALL_SEL = 0;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CMD_STALL_SEL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_DISP_RETRY_SEL = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_DISP_RETRY_SEL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_RESERVED8_9 = 9;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG = 10;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE = 11;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_RRQ_STALL_SEL = 12;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_RRQ_STALL_SEL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_WRQ_STALL_SEL = 16;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_WRQ_STALL_SEL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_MERGE_STALL_SEL = 20;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_MERGE_STALL_SEL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_DEALLOC_STALL_SEL = 24;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_DEALLOC_STALL_SEL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CRESP_STALL_SEL = 28;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CRESP_STALL_SEL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CLSTATE_DEBUG_SEL = 32;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CLSTATE_DEBUG_SEL_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_DISP_DEBUG_SEL = 40;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_DISP_DEBUG_SEL_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_DEBUG_SEL = 48;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_DEBUG_SEL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CLSX_DEBUG_SEL = 52;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CLSX_DEBUG_SEL_LEN = 7;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_WAT_BLOCK_WRBUF_AVAIL = 59;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_WAT_BLOCK_WRBUF_AVAIL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL = 63;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CONFIG = 0x0c00000aull;

static const uint32_t CONFIG_LINK_PAIR = 0;
static const uint32_t CONFIG_DISABLE_SL_ECC = 1;
static const uint32_t CONFIG_UNUSED0 = 2;
static const uint32_t CONFIG_UNUSED0_LEN = 2;
static const uint32_t CONFIG_SL_UE_CRC_ERR = 4;
static const uint32_t CONFIG_REPORT_SL_CHKBIT_ERR = 5;
static const uint32_t CONFIG_BW_SAMPLE_SIZE = 6;
static const uint32_t CONFIG_BW_WINDOW_SIZE = 7;
static const uint32_t CONFIG_UNUSED1 = 8;
static const uint32_t CONFIG_UNUSED1_LEN = 3;
static const uint32_t CONFIG_PACKET_DELAY_LIMIT = 11;
static const uint32_t CONFIG_PACKET_DELAY_LIMIT_LEN = 5;
static const uint32_t CONFIG_TDM_DELAY = 16;
static const uint32_t CONFIG_TDM_DELAY_LEN = 4;
static const uint32_t CONFIG_UNUSED3 = 20;
static const uint32_t CONFIG_UNUSED3_LEN = 9;
static const uint32_t CONFIG_RECAL_TIMER = 29;
static const uint32_t CONFIG_RECAL_TIMER_LEN = 15;
static const uint32_t CONFIG_PSAVE_TIMEOUT = 44;
static const uint32_t CONFIG_PSAVE_TIMEOUT_LEN = 4;
static const uint32_t CONFIG_TIMEOUT = 48;
static const uint32_t CONFIG_TIMEOUT_LEN = 4;
static const uint32_t CONFIG_TIMER_1US = 52;
static const uint32_t CONFIG_TIMER_1US_LEN = 12;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CONTROL = 0x0c00000bull;

static const uint32_t CONTROL_LINK0_PHY_TRAINING = 0;
static const uint32_t CONTROL_LINK0_STARTUP = 1;
static const uint32_t CONTROL_LINK0_HOLD_PATT_A = 2;
static const uint32_t CONTROL_LINK0_HOLD_PATT_B = 3;
static const uint32_t CONTROL_LINK0_RUN_LANE_DISABLE = 4;
static const uint32_t CONTROL_LINK0_RUN_LANE_OVERRIDE = 5;
static const uint32_t CONTROL_LINK0_IGNORE_PHY = 6;
static const uint32_t CONTROL_LINK0_IGNORE_FENCE = 7;
static const uint32_t CONTROL_LINK0_ERR_INJ_COMMAND = 8;
static const uint32_t CONTROL_LINK0_ERR_INJ_COMMAND_LEN = 4;
static const uint32_t CONTROL_LINK0_ERR_INJ_COMMAND_LANES = 12;
static const uint32_t CONTROL_LINK0_ERR_INJ_COMMAND_LANES_LEN = 9;
static const uint32_t CONTROL_CONTROL_UNUSED0 = 21;
static const uint32_t CONTROL_CONTROL_UNUSED0_LEN = 7;
static const uint32_t CONTROL_LINK0_COMMAND = 28;
static const uint32_t CONTROL_LINK0_COMMAND_LEN = 4;
static const uint32_t CONTROL_LINK1_PHY_TRAINING = 32;
static const uint32_t CONTROL_LINK1_STARTUP = 33;
static const uint32_t CONTROL_LINK1_HOLD_PATT_A = 34;
static const uint32_t CONTROL_LINK1_HOLD_PATT_B = 35;
static const uint32_t CONTROL_LINK1_RUN_LANE_DISABLE = 36;
static const uint32_t CONTROL_LINK1_RUN_LANE_OVERRIDE = 37;
static const uint32_t CONTROL_LINK1_IGNORE_PHY = 38;
static const uint32_t CONTROL_LINK1_IGNORE_FENCE = 39;
static const uint32_t CONTROL_LINK1_ERR_INJ_COMMAND = 40;
static const uint32_t CONTROL_LINK1_ERR_INJ_COMMAND_LEN = 4;
static const uint32_t CONTROL_LINK1_ERR_INJ_COMMAND_LANES = 44;
static const uint32_t CONTROL_LINK1_ERR_INJ_COMMAND_LANES_LEN = 9;
static const uint32_t CONTROL_CONTROL_UNUSED1 = 53;
static const uint32_t CONTROL_CONTROL_UNUSED1_LEN = 7;
static const uint32_t CONTROL_LINK1_COMMAND = 60;
static const uint32_t CONTROL_LINK1_COMMAND_LEN = 4;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_DECRYPT_CRYPTOCFG = 0x0c000378ull;

static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS = 1;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER = 2;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE = 4;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT = 5;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11 = 6;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11_LEN = 6;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ = 12;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ = 14;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ = 16;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ = 18;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ = 20;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ = 21;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ = 22;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ = 23;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ = 24;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ = 25;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31 = 26;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31_LEN = 6;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_DECRYPT_CRYPTOKEY1A = 0x0c00037aull;

static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A_LEN = 64;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_DECRYPT_CRYPTOKEY1B = 0x0c00037bull;

static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B_LEN = 64;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_DECRYPT_CRYPTOKEY2A = 0x0c00037cull;

static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY2A_KEY2A = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY2A_KEY2A_LEN = 64;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_DECRYPT_CRYPTOKEY2B = 0x0c00037dull;

static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B_LEN = 64;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_DECRYPT_CRYPTONONCEA = 0x0c00037eull;

static const uint32_t CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA_LEN = 64;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_DECRYPT_CRYPTONONCEB = 0x0c00037full;

static const uint32_t CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB_LEN = 17;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_ENCRYPT_CRYPTOCFG = 0x0c000370ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS = 1;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER = 2;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE = 4;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT = 5;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11 = 6;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11_LEN = 6;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ = 12;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ = 14;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ = 16;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ = 18;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ = 20;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ = 21;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ = 22;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ = 23;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ = 24;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ = 25;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE = 26;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE_LEN = 6;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_ENCRYPT_CRYPTOKEY1A = 0x0c000372ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A_LEN = 64;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_ENCRYPT_CRYPTOKEY1B = 0x0c000373ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY1B_KEY1B = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY1B_KEY1B_LEN = 64;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_ENCRYPT_CRYPTOKEY2A = 0x0c000374ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY2A_KEY2A = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY2A_KEY2A_LEN = 64;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_ENCRYPT_CRYPTOKEY2B = 0x0c000375ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B_LEN = 64;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_ENCRYPT_CRYPTONONCEA = 0x0c000376ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA_LEN = 64;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_ENCRYPT_CRYPTONONCEB = 0x0c000377ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB_LEN = 17;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t DLL_STATUS = 0x0c000028ull;

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
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ERR_INJ_LFSR = 0x0c00001bull;

static const uint32_t ERR_INJ_LFSR_ERR_INJ_LFSR = 0;
static const uint32_t ERR_INJ_LFSR_ERR_INJ_LFSR_LEN = 61;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t FIR_ACTION0_REG = 0x0c000006ull;

static const uint32_t FIR_ACTION0_REG_DLP_FIR_ACTION0 = 0;
static const uint32_t FIR_ACTION0_REG_DLP_FIR_ACTION0_LEN = 62;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t FIR_ACTION1_REG = 0x0c000007ull;

static const uint32_t FIR_ACTION1_REG_DLP_FIR_ACTION1 = 0;
static const uint32_t FIR_ACTION1_REG_DLP_FIR_ACTION1_LEN = 62;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t FIR_MASK_REG_ = 0x0c000003ull;

static const uint32_t FIR_MASK_REG_LINK0_TRAINED_MASK = 0;
static const uint32_t FIR_MASK_REG_LINK1_TRAINED_MASK = 1;
static const uint32_t FIR_MASK_REG_LINK0_OP_IRQ_MASK = 2;
static const uint32_t FIR_MASK_REG_LINK1_OP_IRQ_MASK = 3;
static const uint32_t FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK = 4;
static const uint32_t FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK = 5;
static const uint32_t FIR_MASK_REG_LINK0_CRC_ERROR_MASK = 6;
static const uint32_t FIR_MASK_REG_LINK1_CRC_ERROR_MASK = 7;
static const uint32_t FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK = 8;
static const uint32_t FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK = 9;
static const uint32_t FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK = 10;
static const uint32_t FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK = 11;
static const uint32_t FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK = 12;
static const uint32_t FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK = 13;
static const uint32_t FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK = 14;
static const uint32_t FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK = 15;
static const uint32_t FIR_MASK_REG_LINK0_SL_ECC_UE_MASK = 16;
static const uint32_t FIR_MASK_REG_LINK1_SL_ECC_UE_MASK = 17;
static const uint32_t FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK = 18;
static const uint32_t FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK = 19;
static const uint32_t FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK = 20;
static const uint32_t FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK = 21;
static const uint32_t FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK = 22;
static const uint32_t FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK = 23;
static const uint32_t FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK = 24;
static const uint32_t FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK = 25;
static const uint32_t FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK = 26;
static const uint32_t FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK = 27;
static const uint32_t FIR_MASK_REG_LINK0_SW_RETRAIN_MASK = 28;
static const uint32_t FIR_MASK_REG_LINK1_SW_RETRAIN_MASK = 29;
static const uint32_t FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK = 30;
static const uint32_t FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK = 31;
static const uint32_t FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK = 32;
static const uint32_t FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK = 33;
static const uint32_t FIR_MASK_REG_LINK0_NUM_REPLAY_MASK = 34;
static const uint32_t FIR_MASK_REG_LINK1_NUM_REPLAY_MASK = 35;
static const uint32_t FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK = 36;
static const uint32_t FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK = 37;
static const uint32_t FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK = 38;
static const uint32_t FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK = 39;
static const uint32_t FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK = 40;
static const uint32_t FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK = 41;
static const uint32_t FIR_MASK_REG_LINK0_NO_SPARE_MASK = 42;
static const uint32_t FIR_MASK_REG_LINK1_NO_SPARE_MASK = 43;
static const uint32_t FIR_MASK_REG_LINK0_SPARE_DONE_MASK = 44;
static const uint32_t FIR_MASK_REG_LINK1_SPARE_DONE_MASK = 45;
static const uint32_t FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK = 46;
static const uint32_t FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK = 47;
static const uint32_t FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK = 48;
static const uint32_t FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK = 49;
static const uint32_t FIR_MASK_REG_OSC_SWITCH_MASK = 51;
static const uint32_t FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK = 52;
static const uint32_t FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK = 53;
static const uint32_t FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK = 54;
static const uint32_t FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK = 55;
static const uint32_t FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK = 56;
static const uint32_t FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK = 57;
static const uint32_t FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK = 58;
static const uint32_t FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK = 59;
static const uint32_t FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK = 60;
static const uint32_t FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK = 61;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t FIR_REG_ = 0x0c000000ull;

static const uint32_t FIR_REG_LINK0_TRAINED = 0;
static const uint32_t FIR_REG_LINK1_TRAINED = 1;
static const uint32_t FIR_REG_LINK0_OP_IRQ = 2;
static const uint32_t FIR_REG_LINK1_OP_IRQ = 3;
static const uint32_t FIR_REG_LINK0_REPLAY_THRESHOLD = 4;
static const uint32_t FIR_REG_LINK1_REPLAY_THRESHOLD = 5;
static const uint32_t FIR_REG_LINK0_CRC_ERROR = 6;
static const uint32_t FIR_REG_LINK1_CRC_ERROR = 7;
static const uint32_t FIR_REG_LINK0_NAK_RECEIVED = 8;
static const uint32_t FIR_REG_LINK1_NAK_RECEIVED = 9;
static const uint32_t FIR_REG_LINK0_REPLAY_BUFFER_FULL = 10;
static const uint32_t FIR_REG_LINK1_REPLAY_BUFFER_FULL = 11;
static const uint32_t FIR_REG_LINK0_SL_ECC_THRESHOLD = 12;
static const uint32_t FIR_REG_LINK1_SL_ECC_THRESHOLD = 13;
static const uint32_t FIR_REG_LINK0_SL_ECC_CORRECTABLE = 14;
static const uint32_t FIR_REG_LINK1_SL_ECC_CORRECTABLE = 15;
static const uint32_t FIR_REG_LINK0_SL_ECC_UE = 16;
static const uint32_t FIR_REG_LINK1_SL_ECC_UE = 17;
static const uint32_t FIR_REG_LINK0_RETRAIN_THRESHOLD = 18;
static const uint32_t FIR_REG_LINK1_RETRAIN_THRESHOLD = 19;
static const uint32_t FIR_REG_LINK0_LOSS_BLOCK_ALIGN = 20;
static const uint32_t FIR_REG_LINK1_LOSS_BLOCK_ALIGN = 21;
static const uint32_t FIR_REG_LINK0_INVALID_BLOCK = 22;
static const uint32_t FIR_REG_LINK1_INVALID_BLOCK = 23;
static const uint32_t FIR_REG_LINK0_DESKEW_ERROR = 24;
static const uint32_t FIR_REG_LINK1_DESKEW_ERROR = 25;
static const uint32_t FIR_REG_LINK0_DESKEW_OVERFLOW = 26;
static const uint32_t FIR_REG_LINK1_DESKEW_OVERFLOW = 27;
static const uint32_t FIR_REG_LINK0_SW_RETRAIN = 28;
static const uint32_t FIR_REG_LINK1_SW_RETRAIN = 29;
static const uint32_t FIR_REG_LINK0_ACK_QUEUE_OVERFLOW = 30;
static const uint32_t FIR_REG_LINK1_ACK_QUEUE_OVERFLOW = 31;
static const uint32_t FIR_REG_LINK0_ACK_QUEUE_UNDERFLOW = 32;
static const uint32_t FIR_REG_LINK1_ACK_QUEUE_UNDERFLOW = 33;
static const uint32_t FIR_REG_LINK0_NUM_REPLAY = 34;
static const uint32_t FIR_REG_LINK1_NUM_REPLAY = 35;
static const uint32_t FIR_REG_LINK0_TRAINING_SET_RECEIVED = 36;
static const uint32_t FIR_REG_LINK1_TRAINING_SET_RECEIVED = 37;
static const uint32_t FIR_REG_LINK0_PRBS_SELECT_ERROR = 38;
static const uint32_t FIR_REG_LINK1_PRBS_SELECT_ERROR = 39;
static const uint32_t FIR_REG_LINK0_TCOMPLETE_BAD = 40;
static const uint32_t FIR_REG_LINK1_TCOMPLETE_BAD = 41;
static const uint32_t FIR_REG_LINK0_NO_SPARE = 42;
static const uint32_t FIR_REG_LINK1_NO_SPARE = 43;
static const uint32_t FIR_REG_LINK0_SPARE_DONE = 44;
static const uint32_t FIR_REG_LINK1_SPARE_DONE = 45;
static const uint32_t FIR_REG_LINK0_TOO_MANY_CRC_ERRORS = 46;
static const uint32_t FIR_REG_LINK1_TOO_MANY_CRC_ERRORS = 47;
static const uint32_t FIR_REG_LINK0_NPU_DLX_ERROR = 48;
static const uint32_t FIR_REG_LINK1_NPU_DLX_ERROR = 49;
static const uint32_t FIR_REG_OSC_SWITCH = 51;
static const uint32_t FIR_REG_LINK0_CORRECTABLE_ARRAY_ERROR = 52;
static const uint32_t FIR_REG_LINK1_CORRECTABLE_ARRAY_ERROR = 53;
static const uint32_t FIR_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR = 54;
static const uint32_t FIR_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR = 55;
static const uint32_t FIR_REG_LINK0_TRAINING_FAILED = 56;
static const uint32_t FIR_REG_LINK1_TRAINING_FAILED = 57;
static const uint32_t FIR_REG_LINK0_UNRECOVERABLE_ERROR = 58;
static const uint32_t FIR_REG_LINK1_UNRECOVERABLE_ERROR = 59;
static const uint32_t FIR_REG_LINK0_INTERNAL_ERROR = 60;
static const uint32_t FIR_REG_LINK1_INTERNAL_ERROR = 61;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t FIR_WOF_REG = 0x0c000008ull;

static const uint32_t FIR_WOF_REG_DLP_FIR_WOF = 0;
static const uint32_t FIR_WOF_REG_DLP_FIR_WOF_LEN = 62;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t LAT_MEASURE = 0x0c00000eull;

static const uint32_t LAT_MEASURE_LINK0_ROUND_TRIP_VALID = 0;
static const uint32_t LAT_MEASURE_LINK0_ROUND_TRIP = 2;
static const uint32_t LAT_MEASURE_LINK0_ROUND_TRIP_LEN = 10;
static const uint32_t LAT_MEASURE_LINK1_ROUND_TRIP_VALID = 12;
static const uint32_t LAT_MEASURE_LINK1_ROUND_TRIP = 14;
static const uint32_t LAT_MEASURE_LINK1_ROUND_TRIP_LEN = 10;
static const uint32_t LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID = 24;
static const uint32_t LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK = 25;
static const uint32_t LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE = 29;
static const uint32_t LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_LEN = 7;
static const uint32_t LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID = 36;
static const uint32_t LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK = 37;
static const uint32_t LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE = 41;
static const uint32_t LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_LEN = 7;
static const uint32_t LAT_MEASURE_LINK0_TOD_LATENCY = 49;
static const uint32_t LAT_MEASURE_LINK0_TOD_LATENCY_LEN = 7;
static const uint32_t LAT_MEASURE_LINK1_TOD_LATENCY = 57;
static const uint32_t LAT_MEASURE_LINK1_TOD_LATENCY_LEN = 7;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t LINK0_ERROR_STATUS = 0x0c000016ull;

static const uint32_t LINK0_ERROR_STATUS_RESET_KEEPER = 0;
static const uint32_t LINK0_ERROR_STATUS_ERROR_STATUS_CE = 1;
static const uint32_t LINK0_ERROR_STATUS_ERROR_STATUS_CE_LEN = 7;
static const uint32_t LINK0_ERROR_STATUS_ERROR_STATUS_UE = 8;
static const uint32_t LINK0_ERROR_STATUS_ERROR_STATUS_UE_LEN = 4;
static const uint32_t LINK0_ERROR_STATUS_ERROR_STATUS_OSC = 12;
static const uint32_t LINK0_ERROR_STATUS_ERROR_STATUS_OSC_LEN = 2;
static const uint32_t LINK0_ERROR_STATUS_ERROR_STATUS_TRAIN = 16;
static const uint32_t LINK0_ERROR_STATUS_ERROR_STATUS_TRAIN_LEN = 5;
static const uint32_t LINK0_ERROR_STATUS_ERROR_STATUS_UNRECOV = 24;
static const uint32_t LINK0_ERROR_STATUS_ERROR_STATUS_UNRECOV_LEN = 14;
static const uint32_t LINK0_ERROR_STATUS_ERROR_STATUS_INTERNAL = 40;
static const uint32_t LINK0_ERROR_STATUS_ERROR_STATUS_INTERNAL_LEN = 24;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t LINK0_INFO = 0x0c000014ull;

static const uint32_t LINK0_INFO_MAX_TIMEOUT = 0;
static const uint32_t LINK0_INFO_MAX_TIMEOUT_LEN = 16;
static const uint32_t LINK0_INFO_FRAME_CAP_VALID = 16;
static const uint32_t LINK0_INFO_FRAME_CAP_INST = 17;
static const uint32_t LINK0_INFO_FRAME_CAP_ADDR = 18;
static const uint32_t LINK0_INFO_FRAME_CAP_ADDR_LEN = 6;
static const uint32_t LINK0_INFO_FRAME_CAP_SYN = 24;
static const uint32_t LINK0_INFO_FRAME_CAP_SYN_LEN = 8;
static const uint32_t LINK0_INFO_REPLAY_CAP_VALID = 32;
static const uint32_t LINK0_INFO_REPLAY_CAP_INST = 33;
static const uint32_t LINK0_INFO_REPLAY_CAP_INST_LEN = 2;
static const uint32_t LINK0_INFO_REPLAY_CAP_ADDR = 35;
static const uint32_t LINK0_INFO_REPLAY_CAP_ADDR_LEN = 9;
static const uint32_t LINK0_INFO_REPLAY_CAP_SYN = 44;
static const uint32_t LINK0_INFO_REPLAY_CAP_SYN_LEN = 8;
static const uint32_t LINK0_INFO_ACK_FIFO_CAP_VALID = 52;
static const uint32_t LINK0_INFO_ACK_FIFO_CAP_ADDR = 55;
static const uint32_t LINK0_INFO_ACK_FIFO_CAP_ADDR_LEN = 9;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t LINK0_QUALITY = 0x0c000026ull;

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
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t LINK0_RX_LANE_CONTROL = 0x0c000012ull;

static const uint32_t LINK0_RX_LANE_CONTROL_LANE_DISABLED = 0;
static const uint32_t LINK0_RX_LANE_CONTROL_LANE_DISABLED_LEN = 9;
static const uint32_t LINK0_RX_LANE_CONTROL_UNUSED0 = 9;
static const uint32_t LINK0_RX_LANE_CONTROL_UNUSED0_LEN = 3;
static const uint32_t LINK0_RX_LANE_CONTROL_LANE_BRINGUP = 12;
static const uint32_t LINK0_RX_LANE_CONTROL_LANE_BRINGUP_LEN = 9;
static const uint32_t LINK0_RX_LANE_CONTROL_UNUSED1 = 21;
static const uint32_t LINK0_RX_LANE_CONTROL_UNUSED1_LEN = 3;
static const uint32_t LINK0_RX_LANE_CONTROL_LANE_SPARED = 24;
static const uint32_t LINK0_RX_LANE_CONTROL_LANE_SPARED_LEN = 9;
static const uint32_t LINK0_RX_LANE_CONTROL_UNUSED2 = 33;
static const uint32_t LINK0_RX_LANE_CONTROL_UNUSED2_LEN = 3;
static const uint32_t LINK0_RX_LANE_CONTROL_LANE_LOCKED = 36;
static const uint32_t LINK0_RX_LANE_CONTROL_LANE_LOCKED_LEN = 9;
static const uint32_t LINK0_RX_LANE_CONTROL_LANE_FAILED = 48;
static const uint32_t LINK0_RX_LANE_CONTROL_LANE_FAILED_LEN = 9;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t LINK0_TX_LANE_CONTROL = 0x0c000010ull;

static const uint32_t LINK0_TX_LANE_CONTROL_00_CONTROL = 0;
static const uint32_t LINK0_TX_LANE_CONTROL_00_CONTROL_LEN = 4;
static const uint32_t LINK0_TX_LANE_CONTROL_01_CONTROL = 4;
static const uint32_t LINK0_TX_LANE_CONTROL_01_CONTROL_LEN = 4;
static const uint32_t LINK0_TX_LANE_CONTROL_02_CONTROL = 8;
static const uint32_t LINK0_TX_LANE_CONTROL_02_CONTROL_LEN = 4;
static const uint32_t LINK0_TX_LANE_CONTROL_03_CONTROL = 12;
static const uint32_t LINK0_TX_LANE_CONTROL_03_CONTROL_LEN = 4;
static const uint32_t LINK0_TX_LANE_CONTROL_04_CONTROL = 16;
static const uint32_t LINK0_TX_LANE_CONTROL_04_CONTROL_LEN = 4;
static const uint32_t LINK0_TX_LANE_CONTROL_05_CONTROL = 20;
static const uint32_t LINK0_TX_LANE_CONTROL_05_CONTROL_LEN = 4;
static const uint32_t LINK0_TX_LANE_CONTROL_06_CONTROL = 24;
static const uint32_t LINK0_TX_LANE_CONTROL_06_CONTROL_LEN = 4;
static const uint32_t LINK0_TX_LANE_CONTROL_07_CONTROL = 28;
static const uint32_t LINK0_TX_LANE_CONTROL_07_CONTROL_LEN = 4;
static const uint32_t LINK0_TX_LANE_CONTROL_SP_CONTROL = 32;
static const uint32_t LINK0_TX_LANE_CONTROL_SP_CONTROL_LEN = 4;
static const uint32_t LINK0_TX_LANE_CONTROL__FAILED = 48;
static const uint32_t LINK0_TX_LANE_CONTROL__FAILED_LEN = 9;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t LINK1_ERROR_STATUS = 0x0c000017ull;

static const uint32_t LINK1_ERROR_STATUS_RESET_KEEPER = 0;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_CE = 1;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_CE_LEN = 7;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_UE = 8;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_UE_LEN = 4;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_OSC = 12;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_OSC_LEN = 2;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_TRAIN = 16;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_TRAIN_LEN = 5;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_UNRECOV = 24;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_UNRECOV_LEN = 14;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_INTERNAL = 40;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_INTERNAL_LEN = 24;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t LINK1_INFO = 0x0c000015ull;

static const uint32_t LINK1_INFO_MAX_TIMEOUT = 0;
static const uint32_t LINK1_INFO_MAX_TIMEOUT_LEN = 16;
static const uint32_t LINK1_INFO_FRAME_CAP_VALID = 16;
static const uint32_t LINK1_INFO_FRAME_CAP_INST = 17;
static const uint32_t LINK1_INFO_FRAME_CAP_ADDR = 18;
static const uint32_t LINK1_INFO_FRAME_CAP_ADDR_LEN = 6;
static const uint32_t LINK1_INFO_FRAME_CAP_SYN = 24;
static const uint32_t LINK1_INFO_FRAME_CAP_SYN_LEN = 8;
static const uint32_t LINK1_INFO_REPLAY_CAP_VALID = 32;
static const uint32_t LINK1_INFO_REPLAY_CAP_INST = 33;
static const uint32_t LINK1_INFO_REPLAY_CAP_INST_LEN = 2;
static const uint32_t LINK1_INFO_REPLAY_CAP_ADDR = 35;
static const uint32_t LINK1_INFO_REPLAY_CAP_ADDR_LEN = 9;
static const uint32_t LINK1_INFO_REPLAY_CAP_SYN = 44;
static const uint32_t LINK1_INFO_REPLAY_CAP_SYN_LEN = 8;
static const uint32_t LINK1_INFO_ACK_FIFO_CAP_VALID = 52;
static const uint32_t LINK1_INFO_ACK_FIFO_CAP_ADDR = 55;
static const uint32_t LINK1_INFO_ACK_FIFO_CAP_ADDR_LEN = 9;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t LINK1_QUALITY = 0x0c000027ull;

static const uint32_t LINK1_QUALITY_TX_BW = 1;
static const uint32_t LINK1_QUALITY_TX_BW_LEN = 11;
static const uint32_t LINK1_QUALITY_RX_BW = 13;
static const uint32_t LINK1_QUALITY_RX_BW_LEN = 11;
static const uint32_t LINK1_QUALITY_ERROR_RATE = 25;
static const uint32_t LINK1_QUALITY_ERROR_RATE_LEN = 23;
static const uint32_t LINK1_QUALITY_SPARE_COUNTER_1 = 49;
static const uint32_t LINK1_QUALITY_SPARE_COUNTER_1_LEN = 7;
static const uint32_t LINK1_QUALITY_SPARE_COUNTER_2 = 57;
static const uint32_t LINK1_QUALITY_SPARE_COUNTER_2_LEN = 7;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t LINK1_RX_LANE_CONTROL = 0x0c000013ull;

static const uint32_t LINK1_RX_LANE_CONTROL_LANE_DISABLED = 0;
static const uint32_t LINK1_RX_LANE_CONTROL_LANE_DISABLED_LEN = 9;
static const uint32_t LINK1_RX_LANE_CONTROL_UNUSED0 = 9;
static const uint32_t LINK1_RX_LANE_CONTROL_UNUSED0_LEN = 3;
static const uint32_t LINK1_RX_LANE_CONTROL_LANE_BRINGUP = 12;
static const uint32_t LINK1_RX_LANE_CONTROL_LANE_BRINGUP_LEN = 9;
static const uint32_t LINK1_RX_LANE_CONTROL_UNUSED1 = 21;
static const uint32_t LINK1_RX_LANE_CONTROL_UNUSED1_LEN = 3;
static const uint32_t LINK1_RX_LANE_CONTROL_LANE_SPARED = 24;
static const uint32_t LINK1_RX_LANE_CONTROL_LANE_SPARED_LEN = 9;
static const uint32_t LINK1_RX_LANE_CONTROL_UNUSED2 = 33;
static const uint32_t LINK1_RX_LANE_CONTROL_UNUSED2_LEN = 3;
static const uint32_t LINK1_RX_LANE_CONTROL_LANE_LOCKED = 36;
static const uint32_t LINK1_RX_LANE_CONTROL_LANE_LOCKED_LEN = 9;
static const uint32_t LINK1_RX_LANE_CONTROL_LANE_FAILED = 48;
static const uint32_t LINK1_RX_LANE_CONTROL_LANE_FAILED_LEN = 9;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t LINK1_TX_LANE_CONTROL = 0x0c000011ull;

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
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t MISC_ERROR_STATUS = 0x0c000029ull;

static const uint32_t MISC_ERROR_STATUS_MISC_RESET_KEEPER = 0;
static const uint32_t MISC_ERROR_STATUS_DLX0_ERROR_STATUS = 8;
static const uint32_t MISC_ERROR_STATUS_DLX0_ERROR_STATUS_LEN = 8;
static const uint32_t MISC_ERROR_STATUS_DLX1_ERROR_STATUS = 16;
static const uint32_t MISC_ERROR_STATUS_DLX1_ERROR_STATUS_LEN = 8;
static const uint32_t MISC_ERROR_STATUS_OLL_ERROR_STATUS = 24;
static const uint32_t MISC_ERROR_STATUS_OLL_ERROR_STATUS_LEN = 18;
static const uint32_t MISC_ERROR_STATUS_ODL_ERROR_STATUS = 44;
static const uint32_t MISC_ERROR_STATUS_ODL_ERROR_STATUS_LEN = 18;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t OPTICAL_CONFIG = 0x0c00000full;

static const uint32_t OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT = 0;
static const uint32_t OPTICAL_CONFIG_CONFIG_DISABLE_CLEAR_BAD_LANE_COUNT = 1;
static const uint32_t OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE = 2;
static const uint32_t OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR = 3;
static const uint32_t OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION = 4;
static const uint32_t OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION_LEN = 4;
static const uint32_t OPTICAL_CONFIG_CONFIG_OPT_UNUSED2 = 8;
static const uint32_t OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX = 9;
static const uint32_t OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX_LEN = 7;
static const uint32_t OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT = 16;
static const uint32_t OPTICAL_CONFIG_CONFIG_OPT_UNUSED3 = 17;
static const uint32_t OPTICAL_CONFIG_CONFIG_OPT_UNUSED3_LEN = 3;
static const uint32_t OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION = 20;
static const uint32_t OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION_LEN = 4;
static const uint32_t OPTICAL_CONFIG_CONFIG_OPT_UNUSED4 = 24;
static const uint32_t OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX = 25;
static const uint32_t OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX_LEN = 7;
static const uint32_t OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER = 32;
static const uint32_t OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER = 33;
static const uint32_t OPTICAL_CONFIG_CONFIG_OPT_UNUSED5 = 34;
static const uint32_t OPTICAL_CONFIG_CONFIG_OPT_UNUSED5_LEN = 6;
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
static const uint32_t OPTICAL_CONFIG_CONFIG_OPT_UNUSED6 = 56;
static const uint32_t OPTICAL_CONFIG_CONFIG_OPT_UNUSED6_LEN = 3;
static const uint32_t OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS = 59;
static const uint32_t OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT = 60;
static const uint32_t OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT_LEN = 4;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PERF_COUNTERS_0 = 0x0c00001eull;

static const uint32_t PERF_COUNTERS_0_0 = 0;
static const uint32_t PERF_COUNTERS_0_0_LEN = 16;
static const uint32_t PERF_COUNTERS_0_1 = 16;
static const uint32_t PERF_COUNTERS_0_1_LEN = 16;
static const uint32_t PERF_COUNTERS_0_2 = 32;
static const uint32_t PERF_COUNTERS_0_2_LEN = 16;
static const uint32_t PERF_COUNTERS_0_3 = 48;
static const uint32_t PERF_COUNTERS_0_3_LEN = 16;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PERF_COUNTERS_1 = 0x0c00001full;

static const uint32_t PERF_COUNTERS_1_4 = 0;
static const uint32_t PERF_COUNTERS_1_4_LEN = 16;
static const uint32_t PERF_COUNTERS_1_5 = 16;
static const uint32_t PERF_COUNTERS_1_5_LEN = 16;
static const uint32_t PERF_COUNTERS_1_6 = 32;
static const uint32_t PERF_COUNTERS_1_6_LEN = 16;
static const uint32_t PERF_COUNTERS_1_7 = 48;
static const uint32_t PERF_COUNTERS_1_7_LEN = 16;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PERF_COUNT_LSB_0 = 0x0c000020ull;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PERF_COUNT_LSB_1 = 0x0c000021ull;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PERF_SEL_CONFIG = 0x0c00001dull;

static const uint32_t PERF_SEL_CONFIG_0 = 0;
static const uint32_t PERF_SEL_CONFIG_0_LEN = 8;
static const uint32_t PERF_SEL_CONFIG_1 = 8;
static const uint32_t PERF_SEL_CONFIG_1_LEN = 8;
static const uint32_t PERF_SEL_CONFIG_2 = 16;
static const uint32_t PERF_SEL_CONFIG_2_LEN = 8;
static const uint32_t PERF_SEL_CONFIG_3 = 24;
static const uint32_t PERF_SEL_CONFIG_3_LEN = 8;
static const uint32_t PERF_SEL_CONFIG_4 = 32;
static const uint32_t PERF_SEL_CONFIG_4_LEN = 8;
static const uint32_t PERF_SEL_CONFIG_5 = 40;
static const uint32_t PERF_SEL_CONFIG_5_LEN = 8;
static const uint32_t PERF_SEL_CONFIG_6 = 48;
static const uint32_t PERF_SEL_CONFIG_6_LEN = 8;
static const uint32_t PERF_SEL_CONFIG_7 = 56;
static const uint32_t PERF_SEL_CONFIG_7_LEN = 8;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PERF_TRACE_CONFIG = 0x0c00001cull;

static const uint32_t PERF_TRACE_CONFIG_ENABLE_PERF_0 = 0;
static const uint32_t PERF_TRACE_CONFIG_ENABLE_PERF_0_LEN = 2;
static const uint32_t PERF_TRACE_CONFIG_ENABLE_PERF_1 = 2;
static const uint32_t PERF_TRACE_CONFIG_ENABLE_PERF_1_LEN = 2;
static const uint32_t PERF_TRACE_CONFIG_ENABLE_PERF_2 = 4;
static const uint32_t PERF_TRACE_CONFIG_ENABLE_PERF_2_LEN = 2;
static const uint32_t PERF_TRACE_CONFIG_ENABLE_PERF_3 = 6;
static const uint32_t PERF_TRACE_CONFIG_ENABLE_PERF_3_LEN = 2;
static const uint32_t PERF_TRACE_CONFIG_ENABLE_PERF_4 = 8;
static const uint32_t PERF_TRACE_CONFIG_ENABLE_PERF_4_LEN = 2;
static const uint32_t PERF_TRACE_CONFIG_ENABLE_PERF_5 = 10;
static const uint32_t PERF_TRACE_CONFIG_ENABLE_PERF_5_LEN = 2;
static const uint32_t PERF_TRACE_CONFIG_ENABLE_PERF_6 = 12;
static const uint32_t PERF_TRACE_CONFIG_ENABLE_PERF_6_LEN = 2;
static const uint32_t PERF_TRACE_CONFIG_ENABLE_PERF_7 = 14;
static const uint32_t PERF_TRACE_CONFIG_ENABLE_PERF_7_LEN = 2;
static const uint32_t PERF_TRACE_CONFIG_PERF_SIZE_0 = 16;
static const uint32_t PERF_TRACE_CONFIG_PERF_SIZE_0_LEN = 2;
static const uint32_t PERF_TRACE_CONFIG_PERF_SIZE_1 = 18;
static const uint32_t PERF_TRACE_CONFIG_PERF_SIZE_1_LEN = 2;
static const uint32_t PERF_TRACE_CONFIG_PERF_SIZE_2 = 20;
static const uint32_t PERF_TRACE_CONFIG_PERF_SIZE_2_LEN = 2;
static const uint32_t PERF_TRACE_CONFIG_PERF_SIZE_3 = 22;
static const uint32_t PERF_TRACE_CONFIG_PERF_SIZE_3_LEN = 2;
static const uint32_t PERF_TRACE_CONFIG_PERF_SIZE_4 = 24;
static const uint32_t PERF_TRACE_CONFIG_PERF_SIZE_4_LEN = 2;
static const uint32_t PERF_TRACE_CONFIG_PERF_SIZE_5 = 26;
static const uint32_t PERF_TRACE_CONFIG_PERF_SIZE_5_LEN = 2;
static const uint32_t PERF_TRACE_CONFIG_PERF_SIZE_6 = 28;
static const uint32_t PERF_TRACE_CONFIG_PERF_SIZE_6_LEN = 2;
static const uint32_t PERF_TRACE_CONFIG_PERF_SIZE_7 = 30;
static const uint32_t PERF_TRACE_CONFIG_PERF_SIZE_7_LEN = 2;
static const uint32_t PERF_TRACE_CONFIG_PMULET_FREEZE_MODE = 32;
static const uint32_t PERF_TRACE_CONFIG_COMMON_FREEZE_MODE = 33;
static const uint32_t PERF_TRACE_CONFIG_PERF_RESET_MODE = 34;
static const uint32_t PERF_TRACE_CONFIG_PERFTRACE_ENABLE = 35;
static const uint32_t PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW = 36;
static const uint32_t PERF_TRACE_CONFIG_PERFTRACE_PRESCALE = 37;
static const uint32_t PERF_TRACE_CONFIG_PERFTRACE_MODE = 38;
static const uint32_t PERF_TRACE_CONFIG_PERFTRACE_MODE_LEN = 2;
static const uint32_t PERF_TRACE_CONFIG_TRACE_CONFIG_0 = 40;
static const uint32_t PERF_TRACE_CONFIG_TRACE_CONFIG_0_LEN = 12;
static const uint32_t PERF_TRACE_CONFIG_TRACE_CONFIG_1 = 52;
static const uint32_t PERF_TRACE_CONFIG_TRACE_CONFIG_1_LEN = 12;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PHY_CONFIG = 0x0c00000cull;

static const uint32_t PHY_CONFIG_PHY_TRAIN_A_ADJ = 0;
static const uint32_t PHY_CONFIG_PHY_TRAIN_A_ADJ_LEN = 2;
static const uint32_t PHY_CONFIG_PHY_TRAIN_B_ADJ = 2;
static const uint32_t PHY_CONFIG_PHY_TRAIN_B_ADJ_LEN = 2;
static const uint32_t PHY_CONFIG_PHY_TRAIN_TIME = 4;
static const uint32_t PHY_CONFIG_PHY_TRAIN_TIME_LEN = 4;
static const uint32_t PHY_CONFIG_PHY_TRAIN_A_HYST = 8;
static const uint32_t PHY_CONFIG_PHY_TRAIN_A_HYST_LEN = 4;
static const uint32_t PHY_CONFIG_PHY_TRAIN_B_HYST = 12;
static const uint32_t PHY_CONFIG_PHY_TRAIN_B_HYST_LEN = 4;
static const uint32_t PHY_CONFIG_PRBS_PHASE_SELECT = 16;
static const uint32_t PHY_CONFIG_PRBS_PHASE_SELECT_LEN = 24;
static const uint32_t PHY_CONFIG_PRBS_CONFIG = 40;
static const uint32_t PHY_CONFIG_PRBS_CONFIG_LEN = 10;
static const uint32_t PHY_CONFIG_PRBS_INVERT = 50;
static const uint32_t PHY_CONFIG_PHY_UNUSED1 = 51;
static const uint32_t PHY_CONFIG_PHY_UNUSED1_LEN = 5;
static const uint32_t PHY_CONFIG_LINK0_SELECT = 56;
static const uint32_t PHY_CONFIG_LINK1_SELECT = 57;
static const uint32_t PHY_CONFIG_PHY_UNUSED2 = 58;
static const uint32_t PHY_CONFIG_PHY_UNUSED2_LEN = 3;
static const uint32_t PHY_CONFIG_50G_MODE = 61;
static const uint32_t PHY_CONFIG_DL_SELECT = 62;
static const uint32_t PHY_CONFIG_DL_SELECT_LEN = 2;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t REGS_PRX0_DLR_APCR = 0x0c000038ull;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t REGS_PRX0_DLR_APOR = 0x0c00003aull;

static const uint32_t REGS_PRX0_DLR_APOR_ACTIVITY_ACCUM = 0;
static const uint32_t REGS_PRX0_DLR_APOR_ACTIVITY_ACCUM_LEN = 32;
static const uint32_t REGS_PRX0_DLR_APOR_BASE_ACCUM = 32;
static const uint32_t REGS_PRX0_DLR_APOR_BASE_ACCUM_LEN = 32;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t REGS_PRX0_DLR_APSR = 0x0c000039ull;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t REGS_PRX0_DLR_APST = 0x0c00003bull;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t REGS_PRX1_DLR_APCR = 0x0c00003cull;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t REGS_PRX1_DLR_APOR = 0x0c00003eull;

static const uint32_t REGS_PRX1_DLR_APOR_ACTIVITY_ACCUM = 0;
static const uint32_t REGS_PRX1_DLR_APOR_ACTIVITY_ACCUM_LEN = 32;
static const uint32_t REGS_PRX1_DLR_APOR_BASE_ACCUM = 32;
static const uint32_t REGS_PRX1_DLR_APOR_BASE_ACCUM_LEN = 32;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t REGS_PRX1_DLR_APSR = 0x0c00003dull;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t REGS_PRX1_DLR_APST = 0x0c00003full;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t REPLAY_THRESHOLD = 0x0c000018ull;

static const uint32_t REPLAY_THRESHOLD_TB_SEL = 0;
static const uint32_t REPLAY_THRESHOLD_TB_SEL_LEN = 4;
static const uint32_t REPLAY_THRESHOLD_TAP_SEL = 4;
static const uint32_t REPLAY_THRESHOLD_TAP_SEL_LEN = 4;
static const uint32_t REPLAY_THRESHOLD_ENABLE = 8;
static const uint32_t REPLAY_THRESHOLD_ENABLE_LEN = 3;
static const uint32_t REPLAY_THRESHOLD_UNUSED1 = 11;
static const uint32_t REPLAY_THRESHOLD_UNUSED1_LEN = 15;
static const uint32_t REPLAY_THRESHOLD_LINK0_CLEAR = 26;
static const uint32_t REPLAY_THRESHOLD_LINK1_CLEAR = 27;
static const uint32_t REPLAY_THRESHOLD_DIS_TB_CLEAR = 28;
static const uint32_t REPLAY_THRESHOLD_DIS_TAP_CLEAR = 29;
static const uint32_t REPLAY_THRESHOLD_DIS_TAP_STOP = 30;
static const uint32_t REPLAY_THRESHOLD_UNUSED2 = 31;
static const uint32_t REPLAY_THRESHOLD_LINK0_COUNT = 32;
static const uint32_t REPLAY_THRESHOLD_LINK0_COUNT_LEN = 16;
static const uint32_t REPLAY_THRESHOLD_LINK1_COUNT = 48;
static const uint32_t REPLAY_THRESHOLD_LINK1_COUNT_LEN = 16;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RETRAIN_THRESHOLD = 0x0c00001aull;

static const uint32_t RETRAIN_THRESHOLD_TB_SEL = 0;
static const uint32_t RETRAIN_THRESHOLD_TB_SEL_LEN = 4;
static const uint32_t RETRAIN_THRESHOLD_TAP_SEL = 4;
static const uint32_t RETRAIN_THRESHOLD_TAP_SEL_LEN = 4;
static const uint32_t RETRAIN_THRESHOLD_ENABLE = 8;
static const uint32_t RETRAIN_THRESHOLD_ENABLE_LEN = 9;
static const uint32_t RETRAIN_THRESHOLD_UNUSED1 = 17;
static const uint32_t RETRAIN_THRESHOLD_UNUSED1_LEN = 9;
static const uint32_t RETRAIN_THRESHOLD_LINK0_CLEAR = 26;
static const uint32_t RETRAIN_THRESHOLD_LINK1_CLEAR = 27;
static const uint32_t RETRAIN_THRESHOLD_DIS_TB_CLEAR = 28;
static const uint32_t RETRAIN_THRESHOLD_DIS_TAP_CLEAR = 29;
static const uint32_t RETRAIN_THRESHOLD_DIS_TAP_STOP = 30;
static const uint32_t RETRAIN_THRESHOLD_UNUSED2 = 31;
static const uint32_t RETRAIN_THRESHOLD_LINK0_COUNT = 32;
static const uint32_t RETRAIN_THRESHOLD_LINK0_COUNT_LEN = 16;
static const uint32_t RETRAIN_THRESHOLD_LINK1_COUNT = 48;
static const uint32_t RETRAIN_THRESHOLD_LINK1_COUNT_LEN = 16;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t SEC_CONFIG = 0x0c00000dull;

static const uint32_t SEC_CONFIG_ENABLE_ERR_INJ = 0;
static const uint32_t SEC_CONFIG_ENABLE_TRACE = 1;
static const uint32_t SEC_CONFIG_RESET_INJ = 2;
static const uint32_t SEC_CONFIG_UNUSED4 = 3;
static const uint32_t SEC_CONFIG_UNUSED4_LEN = 13;
static const uint32_t SEC_CONFIG_SBE_ERROR_RATE = 16;
static const uint32_t SEC_CONFIG_SBE_ERROR_RATE_LEN = 2;
static const uint32_t SEC_CONFIG_RAND_ERROR_RATE = 18;
static const uint32_t SEC_CONFIG_RAND_ERROR_RATE_LEN = 6;
static const uint32_t SEC_CONFIG_INV_SH_ERROR_RATE = 24;
static const uint32_t SEC_CONFIG_INV_SH_ERROR_RATE_LEN = 2;
static const uint32_t SEC_CONFIG_SYNC_HEADER_ERROR_RATE = 26;
static const uint32_t SEC_CONFIG_SYNC_HEADER_ERROR_RATE_LEN = 6;
static const uint32_t SEC_CONFIG_UNUSED5 = 32;
static const uint32_t SEC_CONFIG_UNUSED5_LEN = 16;
static const uint32_t SEC_CONFIG_EDPL_RATE = 48;
static const uint32_t SEC_CONFIG_EDPL_RATE_LEN = 16;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t SL_ECC_THRESHOLD = 0x0c000019ull;

static const uint32_t SL_ECC_THRESHOLD_TB_SEL = 0;
static const uint32_t SL_ECC_THRESHOLD_TB_SEL_LEN = 4;
static const uint32_t SL_ECC_THRESHOLD_TAP_SEL = 4;
static const uint32_t SL_ECC_THRESHOLD_TAP_SEL_LEN = 4;
static const uint32_t SL_ECC_THRESHOLD_ENABLE = 8;
static const uint32_t SL_ECC_THRESHOLD_ENABLE_LEN = 2;
static const uint32_t SL_ECC_THRESHOLD_UNUSED1 = 10;
static const uint32_t SL_ECC_THRESHOLD_UNUSED1_LEN = 16;
static const uint32_t SL_ECC_THRESHOLD_LINK0_CLEAR = 26;
static const uint32_t SL_ECC_THRESHOLD_LINK1_CLEAR = 27;
static const uint32_t SL_ECC_THRESHOLD_DIS_TB_CLEAR = 28;
static const uint32_t SL_ECC_THRESHOLD_DIS_TAP_CLEAR = 29;
static const uint32_t SL_ECC_THRESHOLD_DIS_TAP_STOP = 30;
static const uint32_t SL_ECC_THRESHOLD_UNUSED2 = 31;
static const uint32_t SL_ECC_THRESHOLD_LINK0_COUNT = 32;
static const uint32_t SL_ECC_THRESHOLD_LINK0_COUNT_LEN = 16;
static const uint32_t SL_ECC_THRESHOLD_LINK1_COUNT = 48;
static const uint32_t SL_ECC_THRESHOLD_LINK1_COUNT_LEN = 16;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t WDF_WBMGR_TAG_INFO = 0x0c000363ull;

static const uint32_t WDF_WBMGR_TAG_INFO_SLICE0_BUFFER_OVERRUN = 0;
static const uint32_t WDF_WBMGR_TAG_INFO_SLICE1_BUFFER_OVERRUN = 1;
static const uint32_t WDF_WBMGR_TAG_INFO_SLICE2_BUFFER_OVERRUN = 2;
static const uint32_t WDF_WBMGR_TAG_INFO_SLICE3_BUFFER_OVERRUN = 3;
static const uint32_t WDF_WBMGR_TAG_INFO_TAG_OVERRUN = 4;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t WDF_WDFCFG = 0x0c000360ull;

static const uint32_t WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS = 0;
static const uint32_t WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS = 1;
static const uint32_t WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE = 2;
static const uint32_t WDF_WDFCFG_RESET_KEEPER = 3;
static const uint32_t WDF_WDFCFG_MERGE_CAPACITY_LIMIT = 4;
static const uint32_t WDF_WDFCFG_MERGE_CAPACITY_LIMIT_LEN = 4;
static const uint32_t WDF_WDFCFG_WDFCFG_8_11_SPARE = 8;
static const uint32_t WDF_WDFCFG_WDFCFG_8_11_SPARE_LEN = 4;
static const uint32_t WDF_WDFCFG_WDFCFG_16_17_SPARE = 16;
static const uint32_t WDF_WDFCFG_WDFCFG_16_17_SPARE_LEN = 2;
static const uint32_t WDF_WDFCFG_DSTL_DW0_ERR_INJ = 18;
static const uint32_t WDF_WDFCFG_DSTL_DW0_ERR_INJ_LEN = 2;
static const uint32_t WDF_WDFCFG_DSTL_DW1_ERR_INJ = 20;
static const uint32_t WDF_WDFCFG_DSTL_DW1_ERR_INJ_LEN = 2;
static const uint32_t WDF_WDFCFG_DSTL_DW2_ERR_INJ = 22;
static const uint32_t WDF_WDFCFG_DSTL_DW2_ERR_INJ_LEN = 2;
static const uint32_t WDF_WDFCFG_DSTL_DW3_ERR_INJ = 24;
static const uint32_t WDF_WDFCFG_DSTL_DW3_ERR_INJ_LEN = 2;
static const uint32_t WDF_WDFCFG_DSTL_ONE_SHOT_INJ = 26;
static const uint32_t WDF_WDFCFG_DSTL_PERSISTANT_INJ = 27;
static const uint32_t WDF_WDFCFG_WDFCFG_28_31_SPARE = 28;
static const uint32_t WDF_WDFCFG_WDFCFG_28_31_SPARE_LEN = 4;
static const uint32_t WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_SELECT = 32;
static const uint32_t WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_SELECT_LEN = 4;
static const uint32_t WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE = 36;
static const uint32_t WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_LEN = 28;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t WDF_WDFDBG = 0x0c000364ull;

static const uint32_t WDF_WDFDBG_DBG_SEL_IN = 0;
static const uint32_t WDF_WDFDBG_DBG_SEL_WDF = 1;
static const uint32_t WDF_WDFDBG_DBG_SEL_PWSEQ0_DEBUG_0 = 2;
static const uint32_t WDF_WDFDBG_DBG_SEL_PWSEQ0_DEBUG_1 = 3;
static const uint32_t WDF_WDFDBG_DBG_SEL_PWSEQ1_DEBUG_0 = 4;
static const uint32_t WDF_WDFDBG_DBG_SEL_PWSEQ1_DEBUG_1 = 5;
static const uint32_t WDF_WDFDBG_DBG_SEL_PWSEQ2_DEBUG_0 = 6;
static const uint32_t WDF_WDFDBG_DBG_SEL_PWSEQ2_DEBUG_1 = 7;
static const uint32_t WDF_WDFDBG_DBG_SEL_PWSEQ3_DEBUG_0 = 8;
static const uint32_t WDF_WDFDBG_DBG_SEL_PWSEQ3_DEBUG_1 = 9;
static const uint32_t WDF_WDFDBG_DBG_SEL_PWSEQ4_DEBUG_0 = 10;
static const uint32_t WDF_WDFDBG_DBG_SEL_PWSEQ4_DEBUG_1 = 11;
static const uint32_t WDF_WDFDBG_DBG_SEL_PWSEQ5_DEBUG_0 = 12;
static const uint32_t WDF_WDFDBG_DBG_SEL_PWSEQ5_DEBUG_1 = 13;
static const uint32_t WDF_WDFDBG_DBG_SEL_PWCTL_DEBUG = 14;
static const uint32_t WDF_WDFDBG_DBG_SEL_SLICE0_WDFMGR_DEBUG = 15;
static const uint32_t WDF_WDFDBG_DBG_SEL_SLICE1_WDFMGR_DEBUG = 16;
static const uint32_t WDF_WDFDBG_DBG_SEL_SLICE2_WDFMGR_DEBUG = 17;
static const uint32_t WDF_WDFDBG_DBG_SEL_SLICE3_WDFMGR_DEBUG = 18;
static const uint32_t WDF_WDFDBG_DBG_SEL_WDFRD_DEBUG_0 = 19;
static const uint32_t WDF_WDFDBG_DBG_SEL_WDFRD_DEBUG_1 = 20;
static const uint32_t WDF_WDFDBG_DBG_SEL_WDFWR_DEBUG_0 = 21;
static const uint32_t WDF_WDFDBG_DBG_SEL_WDFWR_DEBUG_1 = 22;
static const uint32_t WDF_WDFDBG_DBG_SEL_SEC_WDFRD_DEBUG_0 = 23;
static const uint32_t WDF_WDFDBG_DBG_SEL_SEC_WDFRD_DEBUG_1 = 24;
static const uint32_t WDF_WDFDBG_DBG_SPARE = 25;
static const uint32_t WDF_WDFDBG_DBG_SPARE_LEN = 7;
static const uint32_t WDF_WDFDBG_WAT_EVENT_ENABLE = 32;
static const uint32_t WDF_WDFDBG_WAT_SPARE1 = 33;
static const uint32_t WDF_WDFDBG_WAT_SPARE1_LEN = 3;
static const uint32_t WDF_WDFDBG_WAT0_EVENT_SELECT = 36;
static const uint32_t WDF_WDFDBG_WAT0_EVENT_SELECT_LEN = 4;
static const uint32_t WDF_WDFDBG_WAT1_EVENT_SELECT = 40;
static const uint32_t WDF_WDFDBG_WAT1_EVENT_SELECT_LEN = 4;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t WDF_DSTL_ECC = 0x0c000365ull;

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
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t WDF_ECC = 0x0c000361ull;

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
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t WRITE_READCFG = 0x0c00036dull;

static const uint32_t WRITE_READCFG_ECC_RDC_CFG_RD_ERR_INJ = 0;
static const uint32_t WRITE_READCFG_ECC_RDC_CFG_RD_ERR_INJ_LEN = 4;
static const uint32_t WRITE_READCFG_ECC_RDC_CFG_DBG_CNTL = 4;
static const uint32_t WRITE_READCFG_ECC_RDC_CFG_DBG_CNTL_LEN = 3;
static const uint32_t WRITE_READCFG_SPARE_7 = 7;
static const uint32_t WRITE_READCFG_ECC_RDC_CFG_DLY_ND = 8;
static const uint32_t WRITE_READCFG_ECC_RDC_CFG_DLY_ND_LEN = 2;
static const uint32_t WRITE_READCFG_SPARE_10_11 = 10;
static const uint32_t WRITE_READCFG_SPARE_10_11_LEN = 2;
static const uint32_t WRITE_READCFG_ECC_RDC_CFG_DLY_1X = 12;
static const uint32_t WRITE_READCFG_ECC_RDC_CFG_DLY_NULLABLE = 13;
static const uint32_t WRITE_READCFG_ECC_RDC_CFG_RD_PAR_NOT_SEQ = 14;
static const uint32_t WRITE_READCFG_ECC_RDC_CFG_FIFO_TENURE_3 = 15;
static const uint32_t WRITE_READCFG_EICR_PERSIST = 16;
static const uint32_t WRITE_READCFG_EICR_PERSIST_LEN = 2;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t WRITE_WRTCFG = 0x0c000368ull;

static const uint32_t WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS = 0;
static const uint32_t WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS = 1;
static const uint32_t WRITE_WRTCFG_RESET_KEEPER = 2;
static const uint32_t WRITE_WRTCFG_MPIPL = 3;
static const uint32_t WRITE_WRTCFG_ASYNC_INJ = 4;
static const uint32_t WRITE_WRTCFG_ASYNC_INJ_LEN = 4;
static const uint32_t WRITE_WRTCFG_SPARE_8 = 8;
static const uint32_t WRITE_WRTCFG_NEW_WRITE_64B_MODE = 9;
static const uint32_t WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE = 10;
static const uint32_t WRITE_WRTCFG_RESERVED_11 = 11;
static const uint32_t WRITE_WRTCFG_DSTL_DW0_ERR_INJ = 12;
static const uint32_t WRITE_WRTCFG_DSTL_DW0_ERR_INJ_LEN = 2;
static const uint32_t WRITE_WRTCFG_DSTL_DW1_ERR_INJ = 14;
static const uint32_t WRITE_WRTCFG_DSTL_DW1_ERR_INJ_LEN = 2;
static const uint32_t WRITE_WRTCFG_DSTL_DW2_ERR_INJ = 16;
static const uint32_t WRITE_WRTCFG_DSTL_DW2_ERR_INJ_LEN = 2;
static const uint32_t WRITE_WRTCFG_DSTL_DW3_ERR_INJ = 18;
static const uint32_t WRITE_WRTCFG_DSTL_DW3_ERR_INJ_LEN = 2;
static const uint32_t WRITE_WRTCFG_DSTL_ONE_SHOT_INJ = 20;
static const uint32_t WRITE_WRTCFG_DSTL_PERSISTANT_INJ = 21;
static const uint32_t WRITE_WRTCFG_RESERVED_22_31 = 22;
static const uint32_t WRITE_WRTCFG_RESERVED_22_31_LEN = 10;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t WRITE_WRTDBGMCA = 0x0c00036aull;

static const uint32_t WRITE_WRTDBGMCA_MCA_DBG_SEL_IN = 0;
static const uint32_t WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT = 1;
static const uint32_t WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT = 2;
static const uint32_t WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT = 3;
static const uint32_t WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT = 4;
static const uint32_t WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT = 5;
static const uint32_t WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT = 6;
static const uint32_t WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT = 7;
static const uint32_t WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT = 8;
static const uint32_t WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT = 9;
static const uint32_t WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT = 10;
static const uint32_t WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT = 11;
static const uint32_t WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT = 12;
static const uint32_t WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT = 13;
static const uint32_t WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT = 14;
static const uint32_t WRITE_WRTDBGMCA_DBG_SPARE_MCA = 15;
static const uint32_t WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA = 16;
static const uint32_t WRITE_WRTDBGMCA_WAT_SPARE1_MCA = 17;
static const uint32_t WRITE_WRTDBGMCA_WAT_SPARE1_MCA_LEN = 3;
static const uint32_t WRITE_WRTDBGMCA_WAT0_EVENT_SELECT_MCA = 20;
static const uint32_t WRITE_WRTDBGMCA_WAT0_EVENT_SELECT_MCA_LEN = 4;
static const uint32_t WRITE_WRTDBGMCA_WAT1_EVENT_SELECT_MCA = 24;
static const uint32_t WRITE_WRTDBGMCA_WAT1_EVENT_SELECT_MCA_LEN = 4;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t WRITE_WRT_DSTL_ECC = 0x0c00036cull;

static const uint32_t WRITE_WRT_DSTL_ECC_0_ERR_TYPE = 0;
static const uint32_t WRITE_WRT_DSTL_ECC_0_ERR_TYPE_LEN = 3;
static const uint32_t WRITE_WRT_DSTL_ECC_0_SYNDROME = 8;
static const uint32_t WRITE_WRT_DSTL_ECC_0_SYNDROME_LEN = 8;
static const uint32_t WRITE_WRT_DSTL_ECC_1_ERR_TYPE = 16;
static const uint32_t WRITE_WRT_DSTL_ECC_1_ERR_TYPE_LEN = 3;
static const uint32_t WRITE_WRT_DSTL_ECC_1_SYNDROME = 24;
static const uint32_t WRITE_WRT_DSTL_ECC_1_SYNDROME_LEN = 8;
static const uint32_t WRITE_WRT_DSTL_ECC_2_ERR_TYPE = 32;
static const uint32_t WRITE_WRT_DSTL_ECC_2_ERR_TYPE_LEN = 3;
static const uint32_t WRITE_WRT_DSTL_ECC_2_SYNDROME = 40;
static const uint32_t WRITE_WRT_DSTL_ECC_2_SYNDROME_LEN = 8;
static const uint32_t WRITE_WRT_DSTL_ECC_3_ERR_TYPE = 48;
static const uint32_t WRITE_WRT_DSTL_ECC_3_ERR_TYPE_LEN = 3;
static const uint32_t WRITE_WRT_DSTL_ECC_3_SYNDROME = 56;
static const uint32_t WRITE_WRT_DSTL_ECC_3_SYNDROME_LEN = 8;
// mcc/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t WRITE_WRT_WDF_ECC = 0x0c000369ull;

static const uint32_t WRITE_WRT_WDF_ECC_0_ERR_TYPE = 0;
static const uint32_t WRITE_WRT_WDF_ECC_0_ERR_TYPE_LEN = 3;
static const uint32_t WRITE_WRT_WDF_ECC_0_SYNDROME = 8;
static const uint32_t WRITE_WRT_WDF_ECC_0_SYNDROME_LEN = 8;
static const uint32_t WRITE_WRT_WDF_ECC_1_ERR_TYPE = 16;
static const uint32_t WRITE_WRT_WDF_ECC_1_ERR_TYPE_LEN = 3;
static const uint32_t WRITE_WRT_WDF_ECC_1_SYNDROME = 24;
static const uint32_t WRITE_WRT_WDF_ECC_1_SYNDROME_LEN = 8;
static const uint32_t WRITE_WRT_WDF_ECC_2_ERR_TYPE = 32;
static const uint32_t WRITE_WRT_WDF_ECC_2_ERR_TYPE_LEN = 3;
static const uint32_t WRITE_WRT_WDF_ECC_2_SYNDROME = 40;
static const uint32_t WRITE_WRT_WDF_ECC_2_SYNDROME_LEN = 8;
static const uint32_t WRITE_WRT_WDF_ECC_3_ERR_TYPE = 48;
static const uint32_t WRITE_WRT_WDF_ECC_3_ERR_TYPE_LEN = 3;
static const uint32_t WRITE_WRT_WDF_ECC_3_SYNDROME = 56;
static const uint32_t WRITE_WRT_WDF_ECC_3_SYNDROME_LEN = 8;
// mcc/reg00001.H

}
}
#include "mcc/reg00000.H"
#include "mcc/reg00001.H"
#endif
