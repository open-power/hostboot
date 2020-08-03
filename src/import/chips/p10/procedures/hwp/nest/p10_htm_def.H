/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_htm_def.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// ----------------------------------------------------------------------------
/// @file  p10_htm_def.H
///
/// @brief Common definitions for HTM related values in P10
///
/// ----------------------------------------------------------------------------
//
// *HWP HW Owner: Nicholas Landi <nlandi@ibm.com>
// *HWP FW Owner: Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by: HB
//
/// ----------------------------------------------------------------------------
#ifndef _P10_HTM_DEF_H_
#define _P10_HTM_DEF_H_
//----------------------------------------------------------------------------
// Constant definitions
//----------------------------------------------------------------------------
const uint8_t NUM_NHTM_ENGINES         = 2;
const uint8_t NUM_CHTM_ENGINES         = 32;
const uint8_t NUM_CHTM_REG_MAP_INDEX   = 2;
const uint32_t P10_HTM_CTRL_TIMEOUT_COUNT  = 20;   // HTM control time-out

// HTM operations delay times for HW/sim
const uint32_t P10_HTM_CTRL_HW_NS_DELAY     = 50000;
const uint32_t P10_HTM_CTRL_SIM_CYCLE_DELAY = 50000;

// cHTM IMA FSM definitions
const uint32_t P10_IMA_STATUS_DISABLED = 11;
const uint32_t P10_IMA_STATUS_IDLE     = 10;
const uint32_t P10_IMA_STATUS_CLEAR    =  9;
const uint32_t P10_IMA_STATUS_CAPTURE  =  8;
const uint32_t P10_IMA_STATUS_WR_LDBAR =  7;
const uint32_t P10_IMA_STATUS_WR_PDBAR =  6;
const uint32_t P10_IMA_STATUS_ERROR    =  5;

#endif // _P10_HTM_DEF_H_
