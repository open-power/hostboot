/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mc_9.H $         */
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

#ifndef __p10_scom_mc_9_H_
#define __p10_scom_mc_9_H_


namespace scomt
{
namespace mc
{


static const uint64_t CPLT_CTRL4_RW = 0x0c0003c4ull;
static const uint64_t CPLT_CTRL4_WO_CLEAR = 0x0c0003e4ull;
static const uint64_t CPLT_CTRL4_WO_OR = 0x0c0003d4ull;

static const uint32_t CPLT_CTRL4_0_FLUSHMODE_INH = 4;
static const uint32_t CPLT_CTRL4_1_FLUSHMODE_INH = 5;
static const uint32_t CPLT_CTRL4_2_FLUSHMODE_INH = 6;
static const uint32_t CPLT_CTRL4_3_FLUSHMODE_INH = 7;
static const uint32_t CPLT_CTRL4_4_FLUSHMODE_INH = 8;
static const uint32_t CPLT_CTRL4_5_FLUSHMODE_INH = 9;
static const uint32_t CPLT_CTRL4_6_FLUSHMODE_INH = 10;
static const uint32_t CPLT_CTRL4_7_FLUSHMODE_INH = 11;
static const uint32_t CPLT_CTRL4_8_FLUSHMODE_INH = 12;
static const uint32_t CPLT_CTRL4_9_FLUSHMODE_INH = 13;
static const uint32_t CPLT_CTRL4_10_FLUSHMODE_INH = 14;
static const uint32_t CPLT_CTRL4_11_FLUSHMODE_INH = 15;
static const uint32_t CPLT_CTRL4_12_FLUSHMODE_INH = 16;
static const uint32_t CPLT_CTRL4_13_FLUSHMODE_INH = 17;
static const uint32_t CPLT_CTRL4_14_FLUSHMODE_INH = 18;
// mc/reg00009.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT1 = 0x0c0503c1ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN = 16;
// mc/reg00009.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA2 = 0x0c0503dbull;
// mc/reg00009.H

static const uint64_t EPS_THERM_WSUB_SKITTER_FORCE_REG = 0x0c0503d4ull;

static const uint32_t EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ = 0;
// mc/reg00009.H

static const uint64_t MBA_SCOMFIR_AADR = 0x0c010feaull;

static const uint32_t MBA_SCOMFIR_AADR_AADR_DATA = 0;
static const uint32_t MBA_SCOMFIR_AADR_AADR_DATA_LEN = 64;
// mc/reg00009.H

static const uint64_t MBA_SCOMFIR_WATCFG0DQ = 0x0c010fc3ull;

static const uint32_t MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA = 0;
static const uint32_t MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA_LEN = 44;
// mc/reg00009.H

static const uint64_t MBA_SCOMFIR_WATCFG1CQ = 0x0c010fc7ull;

static const uint32_t MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB = 0;
static const uint32_t MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB_LEN = 44;
// mc/reg00009.H

static const uint64_t MULTICAST_GROUP_2 = 0x0c0f03c2ull;

static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP = 3;
static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN = 3;
// mc/reg00009.H

static const uint64_t SCOMFIR_MCFIRMASK_RW = 0x0c010fc3ull;
static const uint64_t SCOMFIR_MCFIRMASK_WO_AND = 0x0c010fc4ull;
static const uint64_t SCOMFIR_MCFIRMASK_WO_OR = 0x0c010fc5ull;

static const uint32_t SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK = 0;
static const uint32_t SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK_LEN = 24;
// mc/reg00009.H

static const uint64_t SCOMFIR_MCFIRWOF = 0x0c010fc8ull;

static const uint32_t SCOMFIR_MCFIRWOF_MCFIRWOF_WOF = 0;
static const uint32_t SCOMFIR_MCFIRWOF_MCFIRWOF_WOF_LEN = 24;
// mc/reg00009.H

static const uint64_t TRA0_TR0_CONFIG_0 = 0x0c0107c3ull;

static const uint32_t TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// mc/reg00009.H

}
}
#include "mc/reg00009.H"
#endif
