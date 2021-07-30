/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_b.H $       */
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

#ifndef __p10_scom_iohs_b_H_
#define __p10_scom_iohs_b_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [ATOMIC_LOCK_REG]
static const uint64_t ATOMIC_LOCK_REG = 0x180f03ffull;

static const uint32_t ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t ATOMIC_LOCK_REG_ID = 1;
static const uint32_t ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
//<< [ATOMIC_LOCK_REG]
// iohs/reg00048.H

//>> [ATTN_INTERRUPT_REG]
static const uint64_t ATTN_INTERRUPT_REG = 0x180f001aull;

static const uint32_t ATTN_INTERRUPT_REG_ATTN = 0;
//<< [ATTN_INTERRUPT_REG]
// iohs/reg00048.H

//>> [DLP_LINK1_RX_LANE_CONTROL]
static const uint64_t DLP_LINK1_RX_LANE_CONTROL = 0x18011013ull;

static const uint32_t DLP_LINK1_RX_LANE_CONTROL_DISABLED = 0;
static const uint32_t DLP_LINK1_RX_LANE_CONTROL_DISABLED_LEN = 9;
static const uint32_t DLP_LINK1_RX_LANE_CONTROL_BRINGUP = 12;
static const uint32_t DLP_LINK1_RX_LANE_CONTROL_BRINGUP_LEN = 9;
static const uint32_t DLP_LINK1_RX_LANE_CONTROL_SPARED = 24;
static const uint32_t DLP_LINK1_RX_LANE_CONTROL_SPARED_LEN = 9;
static const uint32_t DLP_LINK1_RX_LANE_CONTROL_LOCKED = 36;
static const uint32_t DLP_LINK1_RX_LANE_CONTROL_LOCKED_LEN = 9;
static const uint32_t DLP_LINK1_RX_LANE_CONTROL_FAILED = 48;
static const uint32_t DLP_LINK1_RX_LANE_CONTROL_FAILED_LEN = 9;
static const uint32_t P10_20_DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS = 62; // p10:20,
static const uint32_t P10_20_DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS_LEN = 2;
//<< [DLP_LINK1_RX_LANE_CONTROL]
// iohs/reg00048.H

//>> [P10_20_DLX_CONFIG]
static const uint64_t DLX_CONFIG = 0x18011031ull; // p10:20,

static const uint32_t P10_20_DLX_CONFIG_CFG_DLX1 = 0;
static const uint32_t P10_20_DLX_CONFIG_CFG_DLX1_LEN = 32;
//<< [P10_20_DLX_CONFIG]
// iohs/reg00048.H

//>> [IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG]
static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG = 0x8008800010012c3full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0 = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0_LEN = 3;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH1 = 51;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH1_LEN = 5;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1 = 56;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1_LEN = 3;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH2 = 59;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH2_LEN = 5;
//<< [IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG]
// iohs/reg00051.H

//>> [IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL7_PG]
static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL7_PG = 0x8009b80010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15_LEN = 16;
//<< [IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL7_PG]
// iohs/reg00051.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00048.H"
#include "iohs/reg00049.H"
#include "iohs/reg00050.H"
#include "iohs/reg00051.H"
#include "iohs/reg00052.H"
#endif
#endif
