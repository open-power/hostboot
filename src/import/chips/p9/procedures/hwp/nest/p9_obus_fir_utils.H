/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_obus_fir_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
/// @file p9_obus_fir_utils.H
/// @brief Shared functions to program OBUS FIRs (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HWP Owner : Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner : Thi N. Tran <thi@us.ibm.com>
// *HWP Team : Nest
// *HWP Level : 3
// *HWP Consumed by : SBE,HB,FSP
//

#ifndef _P9_OBUS_FIR_UTILS_H_
#define _P9_OBUS_FIR_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// FBC TL FIR constants
// one register per chip (encompassing all links), in N3 chiplet
const uint64_t FBC_IOO_TL_FIR_ACTION0 = 0x0000000000000000ULL;
const uint64_t FBC_IOO_TL_FIR_ACTION1 = 0x0049200000000000ULL;
const uint64_t FBC_IOO_TL_FIR_MASK    = 0xFF2490000FFFF00FULL;

// in TDM mode, mask framer & parser attention
const uint64_t FBC_IOO0_TL_FIR_MASK_TDM_EVEN = 0x0000080800000000ULL;

// FBC DL FIR constants
// one register per link, in OBUS chiplet
const uint64_t FBC_IOO_DL_FIR_ACTION0 = 0x0000000000000000ULL;
const uint64_t FBC_IOO_DL_FIR_ACTION1 = 0x0303C000033FFFFCULL;
const uint64_t FBC_IOO_DL_FIR_MASK    = 0xFCFC3FFFFCC00003ULL;

// in TDM mode, mask all link specific bits
const uint64_t FBC_IOO_DL_FIR_MASK_TDM_EVEN = 0xAAAAAAAAAAAA8AA8ULL;
const uint64_t FBC_IOO_DL_FIR_MASK_TDM_ODD  = 0x5555555555554554ULL;

// link 0,1 internal errors are a simulation artifact in dd1 so they need to be masked
const uint64_t FBC_IOO_DL_FIR_MASK_SIM = 0xFCFC3FFFFCFF00FFULL;

// OBUS PHY FIR constants
// one register per link, in OBUS chiplet
const uint64_t OBUS_PHY_FIR_ACTION0 = 0x0000000000000000ULL;
const uint64_t OBUS_PHY_FIR_ACTION1 = 0x2000000000000000ULL;
const uint64_t OBUS_PHY_FIR_MASK    = 0xDFFFFFFFFFFFC000ULL;

#endif
