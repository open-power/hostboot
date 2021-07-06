/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/shared/p10_consts.H $ */
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
/// @file p10_consts.H
/// @brief Constants for p10
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: CI

#ifndef _P10_CONSTS_H_
#define _P10_CONSTS_H_

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

const uint8_t MAX_MC_SIDES_PER_PROC = 2; // MC01, MC23
const uint8_t MAX_MC_PER_PROC = 4; // MC0, MC1, MC2, MC3
const uint8_t MAX_MC_PER_SIDE = 2; // MC0, MC1 or MC2, MC3
const uint8_t MAX_DIMM_PER_OMIC = 2; // NUMBER OF DIMMS on OMIC

namespace mss
{
namespace p10
{

///
/// @brief explorer ffdc codes
///
enum ffdc_codes
{
    CHANNEL_A_BEFORE_CHANNEL_B = 0x9000,
};

// This is a MFG_FLAG that was added in P10, but the enum was not added in the XML or in HWSV
constexpr uint32_t MNFG_OMI_CRC_EDPL_SCREEN = fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_POLICY_FLAG_AVAIL_05;

} // p10
} // mss

#endif
