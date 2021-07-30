/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_7.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __p10_scom_iohs_7_H_
#define __p10_scom_iohs_7_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [HANG_PULSE_0_REG]
static const uint64_t HANG_PULSE_0_REG = 0x180f0020ull;

static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0 = 0;
static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN = 6;
static const uint32_t HANG_PULSE_0_REG_SUPPRESS_HANG_0 = 6;
//<< [HANG_PULSE_0_REG]
// iohs/reg00030.H

//>> [HANG_PULSE_1_REG]
static const uint64_t HANG_PULSE_1_REG = 0x180f0021ull;

static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1 = 0;
static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN = 6;
static const uint32_t HANG_PULSE_1_REG_SUPPRESS_HANG_1 = 6;
//<< [HANG_PULSE_1_REG]
// iohs/reg00030.H

//>> [HANG_PULSE_2_REG]
static const uint64_t HANG_PULSE_2_REG = 0x180f0022ull;

static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2 = 0;
static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN = 6;
static const uint32_t HANG_PULSE_2_REG_SUPPRESS_HANG_2 = 6;
//<< [HANG_PULSE_2_REG]
// iohs/reg00030.H

//>> [HANG_PULSE_3_REG]
static const uint64_t HANG_PULSE_3_REG = 0x180f0023ull;

static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3 = 0;
static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN = 6;
static const uint32_t HANG_PULSE_3_REG_SUPPRESS_HANG_3 = 6;
//<< [HANG_PULSE_3_REG]
// iohs/reg00030.H

//>> [HANG_PULSE_4_REG]
static const uint64_t HANG_PULSE_4_REG = 0x180f0024ull;

static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4 = 0;
static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN = 6;
static const uint32_t HANG_PULSE_4_REG_SUPPRESS_HANG_4 = 6;
//<< [HANG_PULSE_4_REG]
// iohs/reg00030.H

//>> [HANG_PULSE_5_REG]
static const uint64_t HANG_PULSE_5_REG = 0x180f0025ull;

static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5 = 0;
static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN = 6;
static const uint32_t HANG_PULSE_5_REG_SUPPRESS_HANG_5 = 6;
//<< [HANG_PULSE_5_REG]
// iohs/reg00030.H

//>> [IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG]
static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG = 0x800a800010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1_LEN = 16;
//<< [IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG]
// iohs/reg00033.H

//>> [IOO_RX0_RXCTL_DATASM_REGS_RX_CNT12_PG]
static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT12_PG = 0x8009e00010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23_LEN = 8;
//<< [IOO_RX0_RXCTL_DATASM_REGS_RX_CNT12_PG]
// iohs/reg00033.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00030.H"
#include "iohs/reg00031.H"
#include "iohs/reg00032.H"
#include "iohs/reg00033.H"
#include "iohs/reg00034.H"
#endif
#endif
