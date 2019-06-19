/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_a.H $          */
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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_c_a_H_
#define __p10_scom_c_a_H_


namespace scomt
{
namespace c
{


static const uint64_t EC_PC_FIR_CORE_SYS = 0x2002044aull;
// c/reg00010.H

static const uint64_t EC_PC_FIR_CORE_WOF = 0x20020448ull;
// c/reg00010.H

static const uint64_t EC_PC_FIR_RAM_STATUS = 0x20020450ull;
// c/reg00010.H

static const uint64_t EC_PC_PMC_UPDATE = 0x20020414ull;
// c/reg00010.H

static const uint64_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG = 0x20020a81ull;

static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00010.H

static const uint64_t L2_L2MISC_L2CERRS_FIR_ACTION0_REG = 0x20020006ull;

static const uint32_t L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0 = 0;
static const uint32_t L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0_LEN = 40;
// c/reg00010.H

static const uint64_t L2_L2MISC_L2CERRS_FIR_ACTION1_REG = 0x20020007ull;

static const uint32_t L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1 = 0;
static const uint32_t L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1_LEN = 40;
// c/reg00010.H

static const uint64_t L2TRA_TR0_TRACE_HI_DATA_REG = 0x20020040ull;

static const uint32_t L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00010.H

static const uint64_t L2TRA_TR0_CONFIG_0 = 0x20020043ull;

static const uint32_t L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00010.H

static const uint64_t L2TRA_TR1_CONFIG_9 = 0x20020089ull;

static const uint32_t L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00010.H

static const uint64_t L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG = 0x20010611ull;

static const uint32_t L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG = 0;
static const uint32_t L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG_LEN = 16;
static const uint32_t L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG = 16;
static const uint32_t L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG_LEN = 2;
// c/reg00010.H

}
}
#ifndef __PPE_HCODE__
    #include "c/reg00010.H"
#endif
#endif
