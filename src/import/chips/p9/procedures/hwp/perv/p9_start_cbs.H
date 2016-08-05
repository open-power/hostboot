/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_start_cbs.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file  p9_start_cbs.H
///
/// @brief Start CBS : Trigger CBS
//------------------------------------------------------------------------------
// *HWP HW Owner        : Abhishek Agarwal <abagarw8@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : sunil kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : SE:HB
//------------------------------------------------------------------------------


#ifndef _P9_START_CBS_H_
#define _P9_START_CBS_H_


#include <fapi2.H>


typedef fapi2::ReturnCode (*p9_start_cbs_FP_t)(const
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&, const bool);

/// @brief --check/wait for VDN_PGOOD = 1
/// --check for OSC ok
/// --check for VDD (VDD status check)
/// --start CBS(CBS runs thru default path)
///
///
/// @param[in]     i_target_chip   Reference to TARGET_TYPE_PROC_CHIP target
/// @param[in]     i_sbe_start     setting of PreventSbeStart
/// @return  FAPI2_RC_SUCCESS if success, else error code.
extern "C"
{
    fapi2::ReturnCode p9_start_cbs(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                   & i_target_chip,
                                   const bool i_sbe_start = 0);
}

#endif
