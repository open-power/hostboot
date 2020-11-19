/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omi_c.H $        */
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

#ifndef __p10_scom_omi_c_H_
#define __p10_scom_omi_c_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> [DLX_INFO]
static const uint64_t DLX_INFO = 0x0c011419ull;

static const uint32_t DLX_INFO_DL0_STS_DLX_INFO = 0;
static const uint32_t DLX_INFO_DL0_STS_DLX_INFO_LEN = 64;
static const uint32_t DLX_INFO_DL1_STS_DLX_INFO = 0;
static const uint32_t DLX_INFO_DL1_STS_DLX_INFO_LEN = 64;
//<< [DLX_INFO]
// omi/reg00024.H

//>> [TRAINING_STATUS]
static const uint64_t TRAINING_STATUS = 0x0c011417ull;

static const uint32_t TRAINING_STATUS_RX_PATTERN_A = 0;
static const uint32_t TRAINING_STATUS_RX_PATTERN_A_LEN = 8;
static const uint32_t TRAINING_STATUS_RX_PATTERN_B = 8;
static const uint32_t TRAINING_STATUS_RX_PATTERN_B_LEN = 8;
static const uint32_t TRAINING_STATUS_SYNC_PATTERN = 16;
static const uint32_t TRAINING_STATUS_SYNC_PATTERN_LEN = 8;
static const uint32_t TRAINING_STATUS_PHY_INIT_DONE = 24;
static const uint32_t TRAINING_STATUS_PHY_INIT_DONE_LEN = 8;
static const uint32_t TRAINING_STATUS_BLOCK_LOCKED = 32;
static const uint32_t TRAINING_STATUS_BLOCK_LOCKED_LEN = 8;
static const uint32_t TRAINING_STATUS_RX_TS1 = 40;
static const uint32_t TRAINING_STATUS_RX_TS1_LEN = 8;
static const uint32_t TRAINING_STATUS_RX_TS2 = 48;
static const uint32_t TRAINING_STATUS_RX_TS2_LEN = 8;
static const uint32_t TRAINING_STATUS_RX_TS3 = 56;
static const uint32_t TRAINING_STATUS_RX_TS3_LEN = 8;
//<< [TRAINING_STATUS]
// omi/reg00025.H

//>> [RXCTL_DATASM_0_PLREGS_RX_CNTL1_PL]
static const uint64_t RXCTL_DATASM_0_PLREGS_RX_CNTL1_PL = 0x8003c04010012c3full;

static const uint32_t RXCTL_DATASM_0_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t RXCTL_DATASM_0_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
//<< [RXCTL_DATASM_0_PLREGS_RX_CNTL1_PL]
// omi/reg00024.H

//>> [RXCTL_DATASM_0_PLREGS_RX_STAT1_PL]
static const uint64_t RXCTL_DATASM_0_PLREGS_RX_STAT1_PL = 0x8003e04010012c3full;

static const uint32_t RXCTL_DATASM_0_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL = 48;
static const uint32_t RXCTL_DATASM_0_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL = 49;
static const uint32_t RXCTL_DATASM_0_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL = 50;
static const uint32_t RXCTL_DATASM_0_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL = 51;
static const uint32_t RXCTL_DATASM_0_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL = 52;
static const uint32_t RXCTL_DATASM_0_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL = 53;
//<< [RXCTL_DATASM_0_PLREGS_RX_STAT1_PL]
// omi/reg00024.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "omi/reg00024.H"
#include "omi/reg00025.H"
#endif
#endif
