/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_b.H $       */
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

#ifndef __p10_scom_iohs_b_H_
#define __p10_scom_iohs_b_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [ATTN_INTERRUPT_REG]
static const uint64_t ATTN_INTERRUPT_REG = 0x180f001aull;

static const uint32_t ATTN_INTERRUPT_REG_ATTN = 0;
//<< [ATTN_INTERRUPT_REG]
// iohs/reg00046.H

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
//<< [DLP_LINK1_RX_LANE_CONTROL]
// iohs/reg00046.H

//>> [ATOMIC_LOCK_REG]
static const uint64_t ATOMIC_LOCK_REG = 0x180f03ffull;

static const uint32_t ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t ATOMIC_LOCK_REG_ID = 1;
static const uint32_t ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
//<< [ATOMIC_LOCK_REG]
// iohs/reg00046.H

//>> [DLX_CONFIG]
static const uint64_t DLX_CONFIG = 0x18011031ull;

static const uint32_t DLX_CONFIG_CFG_DLX1 = 0;
static const uint32_t DLX_CONFIG_CFG_DLX1_LEN = 32;
//<< [DLX_CONFIG]
// iohs/reg00046.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00046.H"
#include "iohs/reg00047.H"
#include "iohs/reg00048.H"
#include "iohs/reg00049.H"
#include "iohs/reg00050.H"
#endif
#endif