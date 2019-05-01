/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_0.H $       */
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

#ifndef __p10_scom_iohs_0_H_
#define __p10_scom_iohs_0_H_


namespace scomt
{
namespace iohs
{


static const uint64_t AXON_EPS_THERM_WSUB_INJECT_REG = 0x18050011ull;

static const uint32_t AXON_EPS_THERM_WSUB_INJECT_REG_TRIP = 0;
static const uint32_t AXON_EPS_THERM_WSUB_INJECT_REG_TRIP_LEN = 2;
static const uint32_t AXON_EPS_THERM_WSUB_INJECT_REG_MODE = 2;
static const uint32_t AXON_EPS_THERM_WSUB_INJECT_REG_MODE_LEN = 2;
// iohs/reg00000.H

static const uint64_t AXON_TRA0_TR0_CONFIG_3 = 0x18010406ull;

static const uint32_t AXON_TRA0_TR0_CONFIG_3_C = 0;
static const uint32_t AXON_TRA0_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t AXON_TRA0_TR0_CONFIG_3_D = 24;
static const uint32_t AXON_TRA0_TR0_CONFIG_3_D_LEN = 24;
// iohs/reg00000.H

static const uint64_t AXON_XSTOP1 = 0x1803000cull;

static const uint32_t AXON_XSTOP1_XSTOP1_MASK_B = 0;
static const uint32_t AXON_XSTOP1_ALIGNED_XSTOP1 = 1;
static const uint32_t AXON_XSTOP1_TRIGGER_OPCG_ON_XSTOP1 = 2;
static const uint32_t AXON_XSTOP1_XSTOP1_WAIT_ALLWAYS = 3;
static const uint32_t AXON_XSTOP1_XSTOP1_PERV = 4;
static const uint32_t AXON_XSTOP1_XSTOP1_UNIT1 = 5;
static const uint32_t AXON_XSTOP1_XSTOP1_UNIT2 = 6;
static const uint32_t AXON_XSTOP1_XSTOP1_UNIT3 = 7;
static const uint32_t AXON_XSTOP1_XSTOP1_UNIT4 = 8;
static const uint32_t AXON_XSTOP1_XSTOP1_UNIT5 = 9;
static const uint32_t AXON_XSTOP1_XSTOP1_UNIT6 = 10;
static const uint32_t AXON_XSTOP1_XSTOP1_UNIT7 = 11;
static const uint32_t AXON_XSTOP1_XSTOP1_UNIT8 = 12;
static const uint32_t AXON_XSTOP1_XSTOP1_UNIT9 = 13;
static const uint32_t AXON_XSTOP1_XSTOP1_UNIT10 = 14;
static const uint32_t AXON_XSTOP1_XSTOP1_UNIT11 = 15;
static const uint32_t AXON_XSTOP1_XSTOP1_UNIT12 = 16;
static const uint32_t AXON_XSTOP1_XSTOP1_UNIT13 = 17;
static const uint32_t AXON_XSTOP1_XSTOP1_UNIT14 = 18;
static const uint32_t AXON_XSTOP1_XSTOP1_WAIT_CYCLES = 48;
static const uint32_t AXON_XSTOP1_XSTOP1_WAIT_CYCLES_LEN = 12;
// iohs/reg00000.H

}
}
#include "iohs/reg00000.H"
#endif
