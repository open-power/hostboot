/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/eff_config/ody_attr_engine_traits.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file ody_attr_engine_traits.H
/// @brief Trait class definitions for Odyssey attrs
///

// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:CI

#ifndef _MSS_ODY_ATTR_ENGINE_TRAITS_H_
#define _MSS_ODY_ATTR_ENGINE_TRAITS_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/data_engine/data_engine_traits_def.H>
#include <generic/memory/lib/data_engine/data_engine.H>

namespace mss
{

///
/// @brief Traits associated with DIMM positioning
/// @class dimmPosTraits - ODYSSEY specializattion
///
template<>
class dimmPosTraits<mss::mc_type::ODYSSEY>
{
    private:
        using PT = posTraits<fapi2::TARGET_TYPE_DIMM>;
        using MT = mss::mcTypeTraits<mc_type::ODYSSEY>;

    public:
        // Public interface syntatic sugar
        using pos_type = PT::pos_type;

        // Proc 0 would be DIMM0 - 31,  proc 1 would be DIMM32 - 63, etc. 32 is the stride between processors
        static constexpr auto DIMM_STRIDE_PER_PROC = 32;
        static constexpr auto TOTAL_DIMM = MT::MC_PER_PROC * MT::MI_PER_MC * MT::MCC_PER_MI *
                                           MT::OMI_PER_MCC * MT::OCMB_PER_OMI * MT::PORTS_PER_OCMB * MT::DIMMS_PER_PORT;

        ///
        /// @brief Return the PROC_CHIP parent of a DIMM
        /// @param[in] i_target the dimm target
        /// @return the fapi2 proc target
        ///
        static fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> get_proc(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
        {
            // Using fapi2 rather than mss::find as this is pretty low level stuff.
            const auto l_ocmb = i_target.getParent<fapi2::TARGET_TYPE_MEM_PORT>().getParent<fapi2::TARGET_TYPE_OCMB_CHIP>();
            const auto l_mc = l_ocmb.getParent<fapi2::TARGET_TYPE_OMI>().getParent<fapi2::TARGET_TYPE_MC>();
            return l_mc.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
        }
};

} // namespace mss

#endif
