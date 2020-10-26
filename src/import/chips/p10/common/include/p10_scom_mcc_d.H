/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_d.H $        */
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

#ifndef __p10_scom_mcc_d_H_
#define __p10_scom_mcc_d_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> [ATCL_CL_CLSCOM_MCPERF0]
static const uint64_t ATCL_CL_CLSCOM_MCPERF0 = 0x0c010c23ull;

static const uint32_t ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ = 0;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM = 1;
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
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM = 47;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE = 51;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE = 52;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE_LEN = 6;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL = 58;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL_LEN = 2;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD = 60;
static const uint32_t ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD_LEN = 4;
//<< [ATCL_CL_CLSCOM_MCPERF0]
// mcc/reg00013.H

//>> [USTL_USTLCFG]
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
static const uint32_t USTL_USTLCFG_RESERVED_12_16 = 12;
static const uint32_t USTL_USTLCFG_RESERVED_12_16_LEN = 5;
static const uint32_t USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE = 17;
static const uint32_t USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE = 18;
static const uint32_t USTL_USTLCFG_RESERVED_19 = 19;
static const uint32_t USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN = 20;
static const uint32_t USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE = 21;
static const uint32_t USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE_LEN = 2;
static const uint32_t USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE = 23;
static const uint32_t USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE = 24;
static const uint32_t USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE_LEN = 7;
static const uint32_t USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE = 32;
static const uint32_t USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT = 33;
static const uint32_t USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_LEN = 3;
static const uint32_t USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS = 36;
static const uint32_t USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE = 37;
static const uint32_t USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE = 38;
static const uint32_t USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE = 39;
static const uint32_t USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD = 40;
static const uint32_t USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD_LEN = 4;
static const uint32_t USTL_USTLCFG_RESERVED_44 = 44;
static const uint32_t USTL_USTLCFG_RESERVED_45 = 45;
static const uint32_t USTL_USTLCFG_CFG_WRAP_MODE = 46;
static const uint32_t USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN = 47;
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
static const uint32_t USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS = 63;
//<< [USTL_USTLCFG]
// mcc/reg00013.H

//>> [DSTL_DSTLCFG2]
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
static const uint32_t DSTL_DSTLCFG2_CHANA_SEL_PSAVE_PMU_EVENTS = 47;
static const uint32_t DSTL_DSTLCFG2_CHANB_SEL_PSAVE_PMU_EVENTS = 48;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY = 49;
static const uint32_t DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY = 50;
static const uint32_t DSTL_DSTLCFG2_RESERVED_51_62 = 51;
static const uint32_t DSTL_DSTLCFG2_RESERVED_51_62_LEN = 12;
//<< [DSTL_DSTLCFG2]
// mcc/reg00013.H

//>> [USTL_USTLFAILMASK]
static const uint64_t USTL_USTLFAILMASK = 0x0c010e13ull;

static const uint32_t USTL_USTLFAILMASK_RECOVER_ENABLE_MASK = 0;
static const uint32_t USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_LEN = 12;
static const uint32_t USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK = 16;
static const uint32_t USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_LEN = 12;
static const uint32_t USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK = 32;
static const uint32_t USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_LEN = 12;
static const uint32_t USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE = 48;
static const uint32_t USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_LEN = 10;
//<< [USTL_USTLFAILMASK]
// mcc/reg00013.H

//>> [USTL_USTLFIRMASK]
static const uint64_t USTL_USTLFIRMASK_RW = 0x0c010e03ull;
static const uint64_t USTL_USTLFIRMASK_WO_AND = 0x0c010e04ull;
static const uint64_t USTL_USTLFIRMASK_WO_OR = 0x0c010e05ull;

static const uint32_t USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK = 0;
static const uint32_t USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK_LEN = 62;
//<< [USTL_USTLFIRMASK]
// mcc/reg00013.H

//>> [CRYPTO_ENCRYPT_CRYPTOKEY1B]
static const uint64_t CRYPTO_ENCRYPT_CRYPTOKEY1B = 0x0c010f53ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY1B_KEY1B = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY1B_KEY1B_LEN = 64;
//<< [CRYPTO_ENCRYPT_CRYPTOKEY1B]
// mcc/reg00013.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mcc/reg00013.H"
#endif
#endif
