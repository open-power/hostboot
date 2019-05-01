/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_c.H $        */
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

#ifndef __p10_scom_mcc_c_H_
#define __p10_scom_mcc_c_H_


namespace scomt
{
namespace mcc
{


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t DSTL_DSTLFIRACT0 = 0x0c010d06ull;

static const uint32_t DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0 = 0;
static const uint32_t DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0_LEN = 35;
// mcc/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t DSTL_DSTLPSAVE1 = 0x0c010d13ull;

static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC = 0;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC_LEN = 8;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC = 8;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC_LEN = 8;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT = 16;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT_LEN = 5;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT = 21;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT_LEN = 5;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE = 26;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE_LEN = 2;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC = 28;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC_LEN = 8;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC = 36;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC_LEN = 8;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT = 44;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT_LEN = 5;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT = 49;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT_LEN = 5;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE = 54;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE_LEN = 2;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE = 56;
static const uint32_t DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE_LEN = 3;
static const uint32_t DSTL_DSTLPSAVE1_RESERVED_59_63 = 59;
static const uint32_t DSTL_DSTLPSAVE1_RESERVED_59_63_LEN = 5;
// mcc/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t DSTL_DSTLTRACK = 0x0c010d0full;

static const uint32_t DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE = 0;
static const uint32_t DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE_LEN = 6;
static const uint32_t DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE = 6;
static const uint32_t DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE_LEN = 6;
static const uint32_t DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE = 12;
static const uint32_t DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE_LEN = 6;
static const uint32_t DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE = 18;
static const uint32_t DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE_LEN = 6;
static const uint32_t DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE = 24;
static const uint32_t DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE_LEN = 4;
static const uint32_t DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE = 28;
static const uint32_t DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE_LEN = 4;
static const uint32_t DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW = 34;
static const uint32_t DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW_LEN = 6;
static const uint32_t DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW = 44;
static const uint32_t DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW_LEN = 4;
static const uint32_t DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW = 50;
static const uint32_t DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW_LEN = 7;
// mcc/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PERF_TRACE_CONFIG = 0x0c01101cull;

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
// mcc/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t REGS_PRX1_DLR_APCR = 0x0c01103cull;
// mcc/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t SEC_CONFIG = 0x0c01100dull;

static const uint32_t SEC_CONFIG_ENABLE_ERR_INJ = 0;
static const uint32_t SEC_CONFIG_ENABLE_TRACE = 1;
static const uint32_t SEC_CONFIG_RESET_INJ = 2;
static const uint32_t SEC_CONFIG_LINK0_PSAVE_OVERRIDE = 12;
static const uint32_t SEC_CONFIG_LINK0_PSAVE_OVERRIDE_LEN = 2;
static const uint32_t SEC_CONFIG_LINK1_PSAVE_OVERRIDE = 14;
static const uint32_t SEC_CONFIG_LINK1_PSAVE_OVERRIDE_LEN = 2;
static const uint32_t SEC_CONFIG_SBE_ERROR_RATE = 16;
static const uint32_t SEC_CONFIG_SBE_ERROR_RATE_LEN = 2;
static const uint32_t SEC_CONFIG_RAND_ERROR_RATE = 18;
static const uint32_t SEC_CONFIG_RAND_ERROR_RATE_LEN = 6;
static const uint32_t SEC_CONFIG_INV_SH_ERROR_RATE = 24;
static const uint32_t SEC_CONFIG_INV_SH_ERROR_RATE_LEN = 2;
static const uint32_t SEC_CONFIG_SYNC_HEADER_ERROR_RATE = 26;
static const uint32_t SEC_CONFIG_SYNC_HEADER_ERROR_RATE_LEN = 6;
static const uint32_t SEC_CONFIG_EDPL_RATE = 48;
static const uint32_t SEC_CONFIG_EDPL_RATE_LEN = 16;
// mcc/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t USTL_USTLDBG = 0x0c010e0dull;

static const uint32_t USTL_USTLDBG_ENABLE = 0;
static const uint32_t USTL_USTLDBG_SEL_TOP = 8;
static const uint32_t USTL_USTLDBG_SEL_WR_TOP = 9;
static const uint32_t USTL_USTLDBG_SEL_BOT = 10;
static const uint32_t USTL_USTLDBG_SEL_WR_BOT = 11;
static const uint32_t USTL_USTLDBG_SEL_FLIT = 12;
static const uint32_t USTL_USTLDBG_SEL_FLIT_CHANB = 13;
static const uint32_t USTL_USTLDBG_SEL_MIRRORLOG_VLDS = 14;
static const uint32_t USTL_USTLDBG_SPARE = 15;
static const uint32_t USTL_USTLDBG_WAT_ENABLE0 = 16;
static const uint32_t USTL_USTLDBG_WAT_ENABLE0_LEN = 2;
static const uint32_t USTL_USTLDBG_WAT_ENABLE1 = 18;
static const uint32_t USTL_USTLDBG_WAT_ENABLE1_LEN = 2;
static const uint32_t USTL_USTLDBG_WAT_ENABLE2 = 20;
static const uint32_t USTL_USTLDBG_WAT_ENABLE2_LEN = 2;
static const uint32_t USTL_USTLDBG_WAT_ENABLE3 = 22;
static const uint32_t USTL_USTLDBG_WAT_ENABLE3_LEN = 2;
// mcc/reg00012.H

}
}
#include "mcc/reg00012.H"
#endif
