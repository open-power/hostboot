/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_7.H $        */
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

#ifndef __p10_scom_mcc_7_H_
#define __p10_scom_mcc_7_H_


namespace scomt
{
namespace mcc
{


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ATCL_CL_CLSCOM_MCBUSYQ = 0x0c010c37ull;

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
// mcc/reg00071.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ATCL_CL_CLSCOM_MCPERF3 = 0x0c010c3bull;

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
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_RESERVED_34_36 = 34;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_RESERVED_34_36_LEN = 3;
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
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR = 56;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_RESERVED_57_63 = 57;
static const uint32_t ATCL_CL_CLSCOM_MCPERF3_RESERVED_57_63_LEN = 7;
// mcc/reg00071.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_ENCRYPT_CRYPTOKEY1A = 0x0c010f72ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A_LEN = 64;
// mcc/reg00071.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t DSTL_DSTLINJ = 0x0c010d0dull;

static const uint32_t DSTL_DSTLINJ_ERR_INJ_TRIGGER = 0;
static const uint32_t DSTL_DSTLINJ_ERR_INJ_CONT_MODE = 1;
static const uint32_t DSTL_DSTLINJ_ERR_INJ_TYPE = 2;
static const uint32_t DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL = 3;
static const uint32_t DSTL_DSTLINJ_RESERVED_4_15 = 4;
static const uint32_t DSTL_DSTLINJ_RESERVED_4_15_LEN = 12;
// mcc/reg00071.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t MC_OMI_FIR_ACTION0_REG = 0x0c011b46ull;

static const uint32_t MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0 = 0;
static const uint32_t MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0_LEN = 62;
// mcc/reg00071.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t MC_OMI_FIR_ACTION1_REG = 0x0c011b47ull;

static const uint32_t MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1 = 0;
static const uint32_t MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1_LEN = 62;
// mcc/reg00071.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PERF_SEL_CONFIG = 0x0c01101dull;

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
// mcc/reg00071.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t WRITE_READCFG = 0x0c010f6dull;

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
// mcc/reg00071.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t WRITE_WRT_DSTL_ECC = 0x0c010f6cull;

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
// mcc/reg00071.H

}
}
#include "mcc/reg00071.H"
#endif
