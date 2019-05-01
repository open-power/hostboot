/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_d.H $        */
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

#ifndef __p10_scom_mcc_d_H_
#define __p10_scom_mcc_d_H_


namespace scomt
{
namespace mcc
{


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ATCL_CL_CLSCOM_MCPERF0 = 0x0c010c33ull;

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
// mcc/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CMN_CONFIG = 0x0c011b4eull;

static const uint32_t CMN_CONFIG_SPARE = 0;
static const uint32_t CMN_CONFIG_SPARE_LEN = 4;
static const uint32_t CMN_CONFIG_PM_CDR_TIMER = 4;
static const uint32_t CMN_CONFIG_PM_CDR_TIMER_LEN = 4;
static const uint32_t CMN_CONFIG_PM_DIDT_TIMER = 8;
static const uint32_t CMN_CONFIG_PM_DIDT_TIMER_LEN = 4;
static const uint32_t CMN_CONFIG_PSAV_STS_ENABLE = 12;
static const uint32_t CMN_CONFIG_RECAL_TIMER = 13;
static const uint32_t CMN_CONFIG_RECAL_TIMER_LEN = 3;
static const uint32_t CMN_CONFIG_1US_TMR = 16;
static const uint32_t CMN_CONFIG_1US_TMR_LEN = 12;
static const uint32_t CMN_CONFIG_DBG_EN = 28;
static const uint32_t CMN_CONFIG_DBG_SEL = 29;
static const uint32_t CMN_CONFIG_DBG_SEL_LEN = 3;
static const uint32_t CMN_CONFIG_RD_RST = 32;
static const uint32_t CMN_CONFIG_PRE_SCALAR = 33;
static const uint32_t CMN_CONFIG_PRE_SCALAR_LEN = 3;
static const uint32_t CMN_CONFIG_FREEZE = 36;
static const uint32_t CMN_CONFIG_PORT_SEL = 37;
static const uint32_t CMN_CONFIG_PORT_SEL_LEN = 3;
static const uint32_t CMN_CONFIG_CNTR3_PS = 40;
static const uint32_t CMN_CONFIG_CNTR3_PS_LEN = 2;
static const uint32_t CMN_CONFIG_CNTR3_ES = 42;
static const uint32_t CMN_CONFIG_CNTR3_ES_LEN = 2;
static const uint32_t CMN_CONFIG_CNTR2_PS = 44;
static const uint32_t CMN_CONFIG_CNTR2_PS_LEN = 2;
static const uint32_t CMN_CONFIG_CNTR2_ES = 46;
static const uint32_t CMN_CONFIG_CNTR2_ES_LEN = 2;
static const uint32_t CMN_CONFIG_CNTR1_PS = 48;
static const uint32_t CMN_CONFIG_CNTR1_PS_LEN = 2;
static const uint32_t CMN_CONFIG_CNTR1_ES = 50;
static const uint32_t CMN_CONFIG_CNTR1_ES_LEN = 2;
static const uint32_t CMN_CONFIG_CNTR0_PS = 52;
static const uint32_t CMN_CONFIG_CNTR0_PS_LEN = 2;
static const uint32_t CMN_CONFIG_CNTR0_ES = 54;
static const uint32_t CMN_CONFIG_CNTR0_ES_LEN = 2;
static const uint32_t CMN_CONFIG_CNTR3_PE = 56;
static const uint32_t CMN_CONFIG_CNTR2_PE = 57;
static const uint32_t CMN_CONFIG_CNTR1_PE = 58;
static const uint32_t CMN_CONFIG_CNTR0_PE = 59;
static const uint32_t CMN_CONFIG_CNTR3_EN = 60;
static const uint32_t CMN_CONFIG_CNTR2_EN = 61;
static const uint32_t CMN_CONFIG_CNTR1_EN = 62;
static const uint32_t CMN_CONFIG_CNTR0_EN = 63;
// mcc/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_ENCRYPT_CRYPTOKEY1B = 0x0c010f73ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY1B_KEY1B = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY1B_KEY1B_LEN = 64;
// mcc/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t DSTL_DSTLCFG2 = 0x0c010d0eull;

static const uint32_t DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING = 0;
static const uint32_t DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING_LEN = 4;
static const uint32_t DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING = 4;
static const uint32_t DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING_LEN = 4;
static const uint32_t DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING = 8;
static const uint32_t DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING_LEN = 4;
static const uint32_t DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING = 12;
static const uint32_t DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING_LEN = 4;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET = 16;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET = 17;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE = 18;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE = 19;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED = 20;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED = 21;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN = 22;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN = 23;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT = 24;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT = 25;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP = 26;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP = 27;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR = 28;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR = 29;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE = 30;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE = 31;
static const uint32_t DSTL_DSTLCFG2_RESERVED_32_35 = 32;
static const uint32_t DSTL_DSTLCFG2_RESERVED_32_35_LEN = 4;
static const uint32_t DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS = 36;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT = 37;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT = 38;
static const uint32_t DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS = 39;
static const uint32_t DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE = 40;
static const uint32_t DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE_LEN = 3;
static const uint32_t DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET = 43;
static const uint32_t DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT = 44;
static const uint32_t DSTL_DSTLCFG2_BOGUS_STALL_MODE_POPS = 45;
static const uint32_t DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL = 46;
static const uint32_t DSTL_DSTLCFG2_RESERVED_47_62 = 47;
static const uint32_t DSTL_DSTLCFG2_RESERVED_47_62_LEN = 16;
// mcc/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t FIR_ACTION0_REG = 0x0c011006ull;

static const uint32_t FIR_ACTION0_REG_DLP_FIR_ACTION0 = 0;
static const uint32_t FIR_ACTION0_REG_DLP_FIR_ACTION0_LEN = 62;
// mcc/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t FIR_ACTION1_REG = 0x0c011007ull;

static const uint32_t FIR_ACTION1_REG_DLP_FIR_ACTION1 = 0;
static const uint32_t FIR_ACTION1_REG_DLP_FIR_ACTION1_LEN = 62;
// mcc/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PERF_COUNTERS_0 = 0x0c01101eull;

static const uint32_t PERF_COUNTERS_0_0 = 0;
static const uint32_t PERF_COUNTERS_0_0_LEN = 16;
static const uint32_t PERF_COUNTERS_0_1 = 16;
static const uint32_t PERF_COUNTERS_0_1_LEN = 16;
static const uint32_t PERF_COUNTERS_0_2 = 32;
static const uint32_t PERF_COUNTERS_0_2_LEN = 16;
static const uint32_t PERF_COUNTERS_0_3 = 48;
static const uint32_t PERF_COUNTERS_0_3_LEN = 16;
// mcc/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t REGS_PRX1_DLR_APSR = 0x0c01103dull;
// mcc/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t USTL_USTLCFG = 0x0c010e0bull;

static const uint32_t USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE = 0;
static const uint32_t USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE = 1;
static const uint32_t USTL_USTLCFG_FAIL_CAPTURE_CONFIG = 2;
static const uint32_t USTL_USTLCFG_FAIL_CAPTURE_CONFIG_LEN = 2;
static const uint32_t USTL_USTLCFG_DEFAULT_META_DATA_ENABLE = 4;
static const uint32_t USTL_USTLCFG_DEFAULT_META_DATA = 5;
static const uint32_t USTL_USTLCFG_DEFAULT_META_DATA_LEN = 2;
static const uint32_t USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO = 7;
static const uint32_t USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE = 8;
static const uint32_t USTL_USTLCFG_LOWLAT_MISS_015_DELAY = 9;
static const uint32_t USTL_USTLCFG_LOWLAT_MISS_015_DELAY_LEN = 3;
static const uint32_t USTL_USTLCFG_RESERVED_12_15 = 12;
static const uint32_t USTL_USTLCFG_RESERVED_12_15_LEN = 4;
static const uint32_t USTL_USTLCFG_ET_DISABLE = 16;
static const uint32_t USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE = 17;
static const uint32_t USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE = 18;
static const uint32_t USTL_USTLCFG_TEMPLATE1_ENABLE = 19;
static const uint32_t USTL_USTLCFG_HALF_MODE_DETECT_ENABLE = 20;
static const uint32_t USTL_USTLCFG_HALF_MODE_DETECT_SEQ_COUNT = 21;
static const uint32_t USTL_USTLCFG_HALF_MODE_DETECT_SEQ_COUNT_LEN = 3;
static const uint32_t USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE = 24;
static const uint32_t USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE_LEN = 7;
static const uint32_t USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE = 32;
static const uint32_t USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT = 33;
static const uint32_t USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_LEN = 3;
static const uint32_t USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS = 36;
static const uint32_t USTL_USTLCFG_DL_WIDTH_HALF_ENABLE = 37;
static const uint32_t USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD = 40;
static const uint32_t USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD_LEN = 4;
static const uint32_t USTL_USTLCFG_CFG_ENABLE_SPEC_ATTN = 44;
static const uint32_t USTL_USTLCFG_CFG_ENABLE_HOST_ATTN = 45;
static const uint32_t USTL_USTLCFG_CFG_WRAP_MODE = 46;
static const uint32_t USTL_USTLCFG_RESERVED_47 = 47;
static const uint32_t USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE = 48;
static const uint32_t USTL_USTLCFG_LOL_LFSR_RATE_SEL = 49;
static const uint32_t USTL_USTLCFG_LOL_LFSR_RATE_SEL_LEN = 3;
static const uint32_t USTL_USTLCFG_CS_HW485610_DISABLE = 52;
static const uint32_t USTL_USTLCFG_CS_HW485610_DISABLE_LEN = 2;
static const uint32_t USTL_USTLCFG_LOL_CAPTURE_CONFIG = 54;
static const uint32_t USTL_USTLCFG_LOL_CAPTURE_CONFIG_LEN = 2;
static const uint32_t USTL_USTLCFG_LAST_OPENCAPI_ENABLE = 56;
static const uint32_t USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW = 57;
static const uint32_t USTL_USTLCFG_PMU_SELECT_FAIL_RSP = 58;
static const uint32_t USTL_USTLCFG_PMU_ENABLE = 59;
static const uint32_t USTL_USTLCFG_PMU_SELECT_ALT_PERF = 60;
static const uint32_t USTL_USTLCFG_CS_HW477424_DISABLE = 61;
static const uint32_t USTL_USTLCFG_CS_HW475333_DISABLE = 62;
// mcc/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t USTL_USTLCFWOF = 0x0c010e15ull;

static const uint32_t USTL_USTLCFWOF_A_CHANFAIL_WOF = 0;
static const uint32_t USTL_USTLCFWOF_A_CHANFAIL_WOF_LEN = 16;
static const uint32_t USTL_USTLCFWOF_B_CHANFAIL_WOF = 16;
static const uint32_t USTL_USTLCFWOF_B_CHANFAIL_WOF_LEN = 16;
// mcc/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t USTL_USTLFAILMASK = 0x0c010e13ull;

static const uint32_t USTL_USTLFAILMASK_RECOVER_ENABLE_MASK = 0;
static const uint32_t USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_LEN = 12;
static const uint32_t USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK = 16;
static const uint32_t USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_LEN = 12;
static const uint32_t USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK = 32;
static const uint32_t USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_LEN = 12;
static const uint32_t USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE = 48;
static const uint32_t USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_LEN = 10;
// mcc/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t USTL_USTLFIRMASK_RW = 0x0c010e03ull;
static const uint64_t USTL_USTLFIRMASK_WO_AND = 0x0c010e04ull;
static const uint64_t USTL_USTLFIRMASK_WO_OR = 0x0c010e05ull;

static const uint32_t USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK = 0;
static const uint32_t USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK_LEN = 62;
// mcc/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t USTL_USTLLOLMASK = 0x0c010e12ull;

static const uint32_t USTL_USTLLOLMASK_RECOVER_ENABLE_MASK = 0;
static const uint32_t USTL_USTLLOLMASK_RECOVER_ENABLE_MASK_LEN = 16;
static const uint32_t USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK = 32;
static const uint32_t USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK_LEN = 16;
// mcc/reg00013.H

}
}
#include "mcc/reg00013.H"
#endif
