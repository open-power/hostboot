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
/// @file p9c_cen_stopclocks.H
/// @brief Assert the tholds (stop the clocks) in the Centaur chip
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB
///

#ifndef CEN_STOPCLOCKSHWPB_H_
#define CEN_STOPCLOCKSHWPB_H_

#include <fapi2.H>


// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9c_cen_stopclocks_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&,
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
    /// @brief cen_stopclocks procedure:  The purpose of this procedure is to assert the tholds (stop the clocks) in the Centaur chip.
    /// @param[in] i_target                 Reference to centaur target
    /// @param[in] i_stop_mem_clks          True if MEM chiplet clocks should be stopped, else false
    /// @param[in] i_stop_nest_clks         True if NEST chiplet clocks (except for refresh clks) should be stopped, else false
    /// @param[in] i_stop_dram_rfrsh_clks   If (i_stop_nest_clks==true) then true if NEST chiplet refresh clocks should be stopped, else false
    /// @param[in] i_stop_tp_clks           True if PERV (TP) chiplet clocks should be stopped, else false
    /// @param[in] i_stop_vitl_clks         True if PERV VITL clocks should be stopped, else false
    /// @return ReturnCode
    fapi2::ReturnCode p9c_cen_stopclocks(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
                                         const bool i_stop_mem_clks,
                                         const bool i_stop_nest_clks,
                                         const bool i_stop_dram_rfrsh_clks,
                                         const bool i_stop_tp_clks,
                                         const bool i_stop_vitl_clks);
} // extern "C"

#endif // CEN_STOPCLOCKSHWPB_H_
