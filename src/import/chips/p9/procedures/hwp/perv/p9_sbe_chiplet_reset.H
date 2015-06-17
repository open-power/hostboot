/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_sbe_chiplet_reset.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
//------------------------------------------------------------------------------
/// @file  p9_sbe_chiplet_reset.H
///
/// @brief Identify all good chiplets excluding EQ/EC
/// Setup multicast groups for all chiplets
/// For all good chiplets excluding EQ/EC
/// For all enabled chiplets
// *!
// *! OWNER NAME  : Abhishek Agarwal  Email: abagarw8@in.ibm.com
// *! BACKUP NAME :                   Email:
//------------------------------------------------------------------------------
// *HWP HWP Owner   : Abhishek Agarwal <abagarw8@in.ibm.com>
// *HWP FW Owner    : Brian Silver <bsilver@us.ibm.com>
// *HWP Team        : Perv
// *HWP Level       : 1
// *HWP Consumed by : SBE
//------------------------------------------------------------------------------


#ifndef _P9_SBE_CHIPLET_RESET_H_
#define _P9_SBE_CHIPLET_RESET_H_


#include <fapi2.H>


typedef fapi2::ReturnCode (*p9_sbe_chiplet_reset_FP_t)(const
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

/// @brief Identify all good chiplets excluding EQ/EC
///      -- All chiplets will be reset and PLLs started
///      -- Partial bad - All nest Chiplets must be good, MC, IO can be partial bad
/// Setup multicast groups for all chiplets
///      -- Can't use the multicast for all non-nest chiplets
///      -- This is intended to be the eventual product setting
///      -- This includes the core/cache chiplets
/// For all good chiplets excluding EQ/EC
///      -- Setup Chiplet GP3 regs
///          -- Reset to default state
///          -- Set chiplet enable on all all good chiplets excluding EQ/EC
/// For all enabled chiplets
///      -- Start vital clocks and release endpoint reset
///      -- PCB Slave error register Reset
///
///
/// @param[in]     i_target_chip   Reference to TARGET_TYPE_PROC_CHIP target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
extern "C"
{
    fapi2::ReturnCode p9_sbe_chiplet_reset(const
                                           fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip);
}

#endif
