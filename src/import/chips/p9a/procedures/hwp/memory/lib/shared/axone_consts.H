/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/lib/shared/axone_consts.H $ */
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


///
/// @file axone_consts.H
/// @brief Constants for axone
///
// *HWP HWP Owner: Andre A. Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: CI

#ifndef _AXONE_CONSTS_H_
#define _AXONE_CONSTS_H_

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

const uint8_t MAX_MC_SIDES_PER_PROC = 2; // MC01, MC23
const uint8_t MAX_MC_PER_PROC = 4; // MC0, MC1, MC2, MC3
const uint8_t MAX_MC_PER_SIDE = 2; // MC0, MC1 or MC2, MC3

namespace mss
{
namespace axone
{

///
/// @brief common axone sizes
///
enum sizes
{
    MAX_DIMM_PER_PROC = 16,

    // Enumerations for the Explorer serial number attribute
    // The hostboot team requested that we only use enumerations for attribute values
    // These are attribute positions in an array, so moving them here
    SERIAL_PART_NUMBER = 3,
    SERIAL_PART_NUMBER_LEN = 7,
    SERIAL_RAW_CARD = 10,
    SERIAL_RAW_CARD_LEN = 4,
    SERIAL_SERIAL_NUMBER = 14,
    SERIAL_SERIAL_NUMBER_LEN = 12,
};

///
/// @brief explorer ffdc codes
///
enum ffdc_codes
{
    CHANNEL_A_BEFORE_CHANNEL_B = 0x9000,
};

} // axone
} // mss

#endif
