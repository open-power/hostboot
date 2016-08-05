/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_mem_pll_reset.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file  p9_mem_pll_reset.H
///
/// @brief Reset PLL bucket for MC chiplets
//------------------------------------------------------------------------------
// *HWP HW Owner        : Anusha Reddy Rangareddygari <anusrang@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Sunil Kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 1
// *HWP Consumed by     : HB
//------------------------------------------------------------------------------


#ifndef _P9_MEM_PLL_RESET_H_
#define _P9_MEM_PLL_RESET_H_


#include <fapi2.H>


typedef fapi2::ReturnCode (*p9_mem_pll_reset_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

/// Disable listen_to_sync for MEM chiplet, whenever MEM is not in sync to NEST
/// Move MC PLL into reset state
/// Assert PLL test enable
/// Assert PLL reset
/// Assert PLL bypass"
/// Assert MEM PDLY and DCC  bypass
/// Set scan ratio to 1:1 as long as PLL is in bypass mode

/// @param[in]     i_target_chiplet   Reference to TARGET_TYPE_PROC_CHIP target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
extern "C"
{
    fapi2::ReturnCode p9_mem_pll_reset(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chiplet);
}

#endif
