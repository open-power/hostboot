/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_cen_stopclocks.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file cen_stopclocks.H
/// @brief Stop Centaur chip clocks (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Perv
// *HWP Level: 3
// *HWP Consumed by: FSP
//

#ifndef _P9C_CEN_STOPCLOCKS_H_
#define _P9C_CEN_STOPCLOCKS_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9c_cen_stopclocks_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&,
    const bool,
    const bool,
    const bool,
    const bool,
    const bool);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Perform Centaur stopclocks
///
/// @param[in] i_target Reference to Centaur chip target
/// @param[in] i_stop_mem_clks Stop MEM chiplet clocks?
/// @param[in] i_stop_mem_clks Stop NEST chiplet clocks?
/// @param[in] i_stop_dram_rfrsh_clks Stop DRAM refresh clocks?
/// @param[in] i_stop_tp_clks Stop TP chiplet clocks?
/// @param[in] i_stop_vitl_clks Stop VITAL clocks?
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9c_cen_stopclocks(
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
        const bool i_stop_mem_clks,
        const bool i_stop_nest_clks,
        const bool i_stop_dram_rfrsh_clks,
        const bool i_stop_tp_clks,
        const bool i_stop_vitl_clks);

} // extern "C"

#endif // _P9C_CEN_STOPCLOCKS_H_
