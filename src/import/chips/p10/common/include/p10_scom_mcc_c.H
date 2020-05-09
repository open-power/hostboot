/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_c.H $        */
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

#ifndef __p10_scom_mcc_c_H_
#define __p10_scom_mcc_c_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> [DSTL_DSTLFIRACT0]
static const uint64_t DSTL_DSTLFIRACT0 = 0x0c010d06ull;

static const uint32_t DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0 = 0;
static const uint32_t DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0_LEN = 39;
//<< [DSTL_DSTLFIRACT0]
// mcc/reg00012.H

//>> [DSTL_DSTLPSAVE1]
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
//<< [DSTL_DSTLPSAVE1]
// mcc/reg00012.H

//>> [DSTL_DSTLTRACK]
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
//<< [DSTL_DSTLTRACK]
// mcc/reg00012.H

//>> [USTL_USTLDBG]
static const uint64_t USTL_USTLDBG = 0x0c010e0dull;

static const uint32_t USTL_USTLDBG_A_STOP_LOL = 0;
static const uint32_t USTL_USTLDBG_A_STOP_LOL_LEN = 4;
static const uint32_t USTL_USTLDBG_B_STOP_LOL = 4;
static const uint32_t USTL_USTLDBG_B_STOP_LOL_LEN = 4;
static const uint32_t USTL_USTLDBG_A_BYPASS_COLD_START = 8;
static const uint32_t USTL_USTLDBG_A_BYPASS_COLD_START_LEN = 4;
static const uint32_t USTL_USTLDBG_B_BYPASS_COLD_START = 12;
static const uint32_t USTL_USTLDBG_B_BYPASS_COLD_START_LEN = 4;
static const uint32_t USTL_USTLDBG_A_FAIL = 16;
static const uint32_t USTL_USTLDBG_A_FAIL_LEN = 4;
static const uint32_t USTL_USTLDBG_B_FAIL = 20;
static const uint32_t USTL_USTLDBG_B_FAIL_LEN = 4;
static const uint32_t USTL_USTLDBG_A_FORCE_BOGUS = 24;
static const uint32_t USTL_USTLDBG_A_FORCE_BOGUS_LEN = 4;
static const uint32_t USTL_USTLDBG_B_FORCE_BOGUS = 28;
static const uint32_t USTL_USTLDBG_B_FORCE_BOGUS_LEN = 4;
//<< [USTL_USTLDBG]
// mcc/reg00012.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mcc/reg00012.H"
#endif
#endif
