/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_7.H $        */
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

#ifndef __p10_scom_mcc_7_H_
#define __p10_scom_mcc_7_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> [ATCL_CL_CLSCOM_MCBUSYQ]
static const uint64_t ATCL_CL_CLSCOM_MCBUSYQ = 0x0c010c27ull;

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
static const uint32_t P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37 = 35; // p10:20,
static const uint32_t P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37_LEN = 3;
static const uint32_t P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20 = 38; // p10:20,
static const uint32_t P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20_LEN = 6;
//<< [ATCL_CL_CLSCOM_MCBUSYQ]
// mcc/reg00007.H

//>> [ATCL_CL_CLSCOM_MCPERF3]
static const uint64_t ATCL_CL_CLSCOM_MCPERF3 = 0x0c010c2bull;

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
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR = 33;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM = 34;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36 = 35;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36_LEN = 2;
static const uint32_t P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36 = 35; // p10:20,
static const uint32_t P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36_LEN = 2;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD = 37;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD = 38;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL = 39;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL = 40;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP = 41;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW = 42;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY = 43;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_RESERVED44 = 44;
static const uint32_t P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20 = 44; // p10:20,
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W = 45;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD = 46;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD = 47;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL = 48;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL = 51;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY = 54;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL = 55;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR = 56;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN = 57;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH = 58;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH_LEN = 6;
//<< [ATCL_CL_CLSCOM_MCPERF3]
// mcc/reg00007.H

//>> [CRYPTO_ENCRYPT_CRYPTOKEY1A]
static const uint64_t CRYPTO_ENCRYPT_CRYPTOKEY1A = 0x0c010f52ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A_LEN = 64;
//<< [CRYPTO_ENCRYPT_CRYPTOKEY1A]
// mcc/reg00007.H

//>> [USTL_USTLCFG2]
static const uint64_t USTL_USTLCFG2 = 0x0c010e17ull;

static const uint32_t USTL_USTLCFG2_USTLCFG2_RESP_QUEUE_STALL_THRESH = 0;
static const uint32_t USTL_USTLCFG2_USTLCFG2_RESP_QUEUE_STALL_THRESH_LEN = 6;
//<< [USTL_USTLCFG2]
// mcc/reg00007.H

//>> [WRITE_READCFG]
static const uint64_t WRITE_READCFG = 0x0c010f4dull;

static const uint32_t WRITE_READCFG_CFG_RD_EINJ_TARGET = 0;
static const uint32_t WRITE_READCFG_CFG_RD_EINJ_TARGET_LEN = 3;
static const uint32_t WRITE_READCFG_CFG_RD_EINJ_RATE = 3;
static const uint32_t WRITE_READCFG_CFG_RD_EINJ_RATE_LEN = 3;
static const uint32_t WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER = 6;
static const uint32_t WRITE_READCFG_CFG_RD_FAIL_ACTION = 7;
static const uint32_t WRITE_READCFG_CFG_RD_FAIL_ACTION_LEN = 2;
static const uint32_t WRITE_READCFG_READCFG_RESERVED_9_11 = 9;
static const uint32_t WRITE_READCFG_READCFG_RESERVED_9_11_LEN = 3;
static const uint32_t P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE = 9; // p10:20,
static const uint32_t P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE_LEN = 2;
static const uint32_t P10_20_WRITE_READCFG_READCFG_RESERVED_11 = 11; // p10:20,
static const uint32_t WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA = 12;
static const uint32_t WRITE_READCFG_CFG_RTYFAIL_NO_BD = 13;
static const uint32_t WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME = 14;
static const uint32_t WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE = 15;
static const uint32_t WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS = 16;
static const uint32_t WRITE_READCFG_CFG_BOGUS_NO_BD = 17;
static const uint32_t WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS = 18;
static const uint32_t WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD = 19;
static const uint32_t WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD_LEN = 7;
static const uint32_t WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ = 26;
static const uint32_t WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD = 27;
static const uint32_t WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD_LEN = 7;
static const uint32_t WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT = 34;
static const uint32_t WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT_LEN = 2;
static const uint32_t WRITE_READCFG_CFG_RD_WAT_STALL_EVENT = 36;
static const uint32_t WRITE_READCFG_CFG_RD_WAT_STALL_EVENT_LEN = 2;
static const uint32_t WRITE_READCFG_READCFG_RESERVED_38_39 = 38;
static const uint32_t WRITE_READCFG_READCFG_RESERVED_38_39_LEN = 2;
static const uint32_t P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS = 38; // p10:20,
static const uint32_t P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS_LEN = 2;
//<< [WRITE_READCFG]
// mcc/reg00007.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mcc/reg00007.H"
#endif
#endif
