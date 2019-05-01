/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_6.H $       */
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

#ifndef __p10_scom_iohs_6_H_
#define __p10_scom_iohs_6_H_


namespace scomt
{
namespace iohs
{


static const uint64_t AXON_EPS_THERM_WSUB_SKITTER_FORCE_REG = 0x18050014ull;

static const uint32_t AXON_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ = 0;
// iohs/reg00006.H

static const uint64_t AXON_SCAN_LONG_ROTATE = 0x18039000ull;
// iohs/reg00006.H

static const uint64_t AXON_SPATTN_NCX = 0x18040005ull;
static const uint64_t AXON_SPATTN_ROX = 0x18040004ull;

static const uint32_t AXON_SPATTN_ANY_SPATTN = 0;
static const uint32_t AXON_SPATTN_RESERVED1S = 1;
static const uint32_t AXON_SPATTN_RESERVED2S = 2;
static const uint32_t AXON_SPATTN_RESERVED3S = 3;
static const uint32_t AXON_SPATTN_SPATTN_PERV = 4;
static const uint32_t AXON_SPATTN_SPATTN_IN05 = 5;
static const uint32_t AXON_SPATTN_SPATTN_IN06 = 6;
static const uint32_t AXON_SPATTN_SPATTN_IN07 = 7;
static const uint32_t AXON_SPATTN_SPATTN_IN08 = 8;
static const uint32_t AXON_SPATTN_SPATTN_IN09 = 9;
static const uint32_t AXON_SPATTN_SPATTN_IN10 = 10;
static const uint32_t AXON_SPATTN_SPATTN_IN11 = 11;
static const uint32_t AXON_SPATTN_SPATTN_IN12 = 12;
static const uint32_t AXON_SPATTN_SPATTN_IN13 = 13;
static const uint32_t AXON_SPATTN_SPATTN_IN14 = 14;
static const uint32_t AXON_SPATTN_SPATTN_IN15 = 15;
static const uint32_t AXON_SPATTN_SPATTN_IN16 = 16;
static const uint32_t AXON_SPATTN_SPATTN_IN17 = 17;
static const uint32_t AXON_SPATTN_SPATTN_IN18 = 18;
static const uint32_t AXON_SPATTN_SPATTN_IN19 = 19;
static const uint32_t AXON_SPATTN_SPATTN_IN20 = 20;
static const uint32_t AXON_SPATTN_SPATTN_IN21 = 21;
static const uint32_t AXON_SPATTN_SPATTN_IN22 = 22;
static const uint32_t AXON_SPATTN_SPATTN_IN23 = 23;
static const uint32_t AXON_SPATTN_SPATTN_IN24 = 24;
static const uint32_t AXON_SPATTN_SPATTN_IN25 = 25;
static const uint32_t AXON_SPATTN_SPATTN_IN26 = 26;
static const uint32_t AXON_SPATTN_SPATTN_IN27 = 27;
static const uint32_t AXON_SPATTN_SPATTN_IN28 = 28;
static const uint32_t AXON_SPATTN_SPATTN_IN29 = 29;
static const uint32_t AXON_SPATTN_SPATTN_IN30 = 30;
static const uint32_t AXON_SPATTN_SPATTN_IN31 = 31;
static const uint32_t AXON_SPATTN_SPATTN_IN32 = 32;
static const uint32_t AXON_SPATTN_SPATTN_IN33 = 33;
static const uint32_t AXON_SPATTN_SPATTN_IN34 = 34;
static const uint32_t AXON_SPATTN_SPATTN_IN35 = 35;
// iohs/reg00006.H

static const uint64_t AXON_TRA0_TR0_TRACE_LO_DATA_REG = 0x18010401ull;

static const uint32_t AXON_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t AXON_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t AXON_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t AXON_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t AXON_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t AXON_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t AXON_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t AXON_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t AXON_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t AXON_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t AXON_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// iohs/reg00006.H

static const uint64_t AXON_TRA0_TR0_CONFIG_2 = 0x18010405ull;

static const uint32_t AXON_TRA0_TR0_CONFIG_2_A = 0;
static const uint32_t AXON_TRA0_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t AXON_TRA0_TR0_CONFIG_2_B = 24;
static const uint32_t AXON_TRA0_TR0_CONFIG_2_B_LEN = 24;
// iohs/reg00006.H

}
}
#include "iohs/reg00006.H"
#endif
