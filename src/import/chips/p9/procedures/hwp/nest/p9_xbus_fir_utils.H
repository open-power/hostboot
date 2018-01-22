/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_xbus_fir_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
/// @file p9_xbus_fir_utils.H
/// @brief Shared functions to program XBUS FIRs (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HWP Owner : Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner : Thi N. Tran <thi@us.ibm.com>
// *HWP Team : Nest
// *HWP Level : 3
// *HWP Consumed by : SBE,HB
//

#ifndef _P9_XBUS_FIR_UTILS_H_
#define _P9_XBUS_FIR_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// XBUS chiplet partial good region constants
const uint32_t X_PG_IOX0_REGION_BIT = 5;
const uint32_t X_PG_IOX1_REGION_BIT = 6;
const uint32_t X_PG_IOX2_REGION_BIT = 7;

const uint32_t X_PG_PBIOX0_REGION_BIT = 9;
const uint32_t X_PG_PBIOX1_REGION_BIT = 10;
const uint32_t X_PG_PBIOX2_REGION_BIT = 11;

// FBC EXTFIR constants
// one register per chip (encompassing all links), in N3 chiplet
const uint64_t FBC_EXT_FIR_ACTION0       = 0x0000000000000000ULL;
const uint64_t FBC_EXT_FIR_ACTION1       = 0x0000000000000000ULL;
const uint64_t FBC_EXT_FIR_MASK          = 0x1F00000000000000ULL;

const uint64_t FBC_EXT_FIR_MASK_X0_NF    = 0x8000000000000000ULL;
const uint64_t FBC_EXT_FIR_MASK_X1_NF    = 0x4000000000000000ULL;
const uint64_t FBC_EXT_FIR_MASK_X2_NF    = 0x2000000000000000ULL;

// FBC TL FIR constants
// one register per chip (encompassing all links), in N3 chiplet
const uint64_t FBC_IOE_TL_FIR_ACTION0    = 0x0000000000000000ULL;
const uint64_t FBC_IOE_TL_FIR_ACTION1    = 0x0049000000000000ULL;
const uint64_t FBC_IOE_TL_FIR_MASK       = 0xFF24F0303FFFF11FULL;

const uint64_t FBC_IOE_TL_FIR_MASK_X0_NF = 0x00C00C0C00000880ULL;
const uint64_t FBC_IOE_TL_FIR_MASK_X1_NF = 0x0018030300000440ULL;
const uint64_t FBC_IOE_TL_FIR_MASK_X2_NF = 0x000300C0C0000220ULL;

// FBC DL FIR constants
// one register per link, in XBUS chiplet
const uint64_t FBC_IOE_DL_FIR_ACTION0    = 0x0000000000000000ULL;
const uint64_t FBC_IOE_DL_FIR_ACTION1    = 0x0303C00000001FFCULL;
const uint64_t FBC_IOE_DL_FIR_MASK       = 0xFCFC3FFFFFFFE003ULL;

const uint64_t FBC_IOE_DL_FIR_MASK_NF    = 0xFFFFFFFFFFFFFFFFULL;

// XBUS PHY FIR constants
// one register per link, in XBUS chiplet
const uint64_t XBUS_PHY_FIR_ACTION0 = 0x0000000000000000ULL;
const uint64_t XBUS_PHY_FIR_ACTION1 = 0x2068680000000000ULL;
const uint64_t XBUS_PHY_FIR_MASK    = 0xDF9797FFFFFFC000ULL;

const uint64_t XBUS_PHY_FIR_MASK_NF = 0xFFFFFFFFFFFFC000ULL;

#endif
