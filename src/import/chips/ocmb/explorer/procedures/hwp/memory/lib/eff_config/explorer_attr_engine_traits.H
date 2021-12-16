/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/eff_config/explorer_attr_engine_traits.H $ */
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
/// @file explorer_attr_engine_traits.H
/// @brief Trait class definitions for explorer attrs
///

// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:CI

#ifndef _MSS_EXPLORER_ATTR_ENGINE_TRAITS_H_
#define _MSS_EXPLORER_ATTR_ENGINE_TRAITS_H_

#include <fapi2.H>
#include <lib/shared/exp_consts.H>
#include <generic/memory/lib/data_engine/data_engine_traits_def.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <mss_explorer_attribute_getters.H>
#include <mss_explorer_attribute_setters.H>
#include <mss_generic_attribute_setters.H>
#include <mss_generic_attribute_getters.H>
#include <lib/eff_config/explorer_rc_resp_fields.H>

namespace mss
{

///
/// @brief Traits associated with DIMM positioning
/// @class dimmPosTraits - EXPLORER specializattion
///
template<>
class dimmPosTraits<mss::mc_type::EXPLORER>
{
    private:
        using PT = posTraits<fapi2::TARGET_TYPE_DIMM>;
        using MT = mss::mcTypeTraits<mc_type::EXPLORER>;

    public:
        // Public interface syntatic sugar
        using pos_type = PT::pos_type;

        // Proc 0 would be DIMM0 - 31,  proc 1 would be DIMM32 - 63, etc. 32 is the stride between processors
        static constexpr auto DIMM_STRIDE_PER_PROC = 64;
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
