/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_4.H $       */
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

#ifndef __p10_scom_iohs_4_H_
#define __p10_scom_iohs_4_H_


namespace scomt
{
namespace iohs
{


static const uint64_t AXON_CLOCK_STAT_NSL = 0x18030009ull;

static const uint32_t AXON_CLOCK_STAT_NSL_PERV_NSL = 4;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT1_NSL = 5;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT2_NSL = 6;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT3_NSL = 7;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT4_NSL = 8;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT5_NSL = 9;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT6_NSL = 10;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT7_NSL = 11;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT8_NSL = 12;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT9_NSL = 13;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT10_NSL = 14;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT11_NSL = 15;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT12_NSL = 16;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT13_NSL = 17;
static const uint32_t AXON_CLOCK_STAT_NSL_UNIT14_NSL = 18;
// iohs/reg00004.H

static const uint64_t AXON_CPLT_CTRL3_RW = 0x18000003ull;
static const uint64_t AXON_CPLT_CTRL3_WO_CLEAR = 0x18000023ull;
static const uint64_t AXON_CPLT_CTRL3_WO_OR = 0x18000013ull;

static const uint32_t AXON_CPLT_CTRL3_0_PSCOM_EN = 4;
static const uint32_t AXON_CPLT_CTRL3_1_PSCOM_EN = 5;
static const uint32_t AXON_CPLT_CTRL3_2_PSCOM_EN = 6;
static const uint32_t AXON_CPLT_CTRL3_3_PSCOM_EN = 7;
static const uint32_t AXON_CPLT_CTRL3_4_PSCOM_EN = 8;
static const uint32_t AXON_CPLT_CTRL3_5_PSCOM_EN = 9;
static const uint32_t AXON_CPLT_CTRL3_6_PSCOM_EN = 10;
static const uint32_t AXON_CPLT_CTRL3_7_PSCOM_EN = 11;
static const uint32_t AXON_CPLT_CTRL3_8_PSCOM_EN = 12;
static const uint32_t AXON_CPLT_CTRL3_9_PSCOM_EN = 13;
static const uint32_t AXON_CPLT_CTRL3_10_PSCOM_EN = 14;
static const uint32_t AXON_CPLT_CTRL3_11_PSCOM_EN = 15;
static const uint32_t AXON_CPLT_CTRL3_12_PSCOM_EN = 16;
static const uint32_t AXON_CPLT_CTRL3_13_PSCOM_EN = 17;
static const uint32_t AXON_CPLT_CTRL3_14_PSCOM_EN = 18;
// iohs/reg00004.H

static const uint64_t AXON_EPS_THERM_WSUB_SKITTER_DATA0 = 0x18050019ull;
// iohs/reg00004.H

}
}
#include "iohs/reg00004.H"
#endif
