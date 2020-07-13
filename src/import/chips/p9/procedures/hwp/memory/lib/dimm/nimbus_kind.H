/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/nimbus_kind.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file nimbus_kind.H
/// @brief Encapsulation for dimms of all types
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_NIMBUS_KIND_H_
#define _MSS_NIMBUS_KIND_H_

#include <fapi2.H>

#include <lib/shared/mss_const.H>
#include <lib/mss_attribute_accessors.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/dimm/kind.H>

namespace mss
{

namespace dimm
{

///
/// @class mss::dimm::kind specilization for NIMBUS
/// @brief A class containing information about a dimm like ranks, density, configuration - what kind of dimm is it?
///
template<>
inline kind<mss::mc_type::NIMBUS>::kind(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target) :
    iv_target(i_target),
    iv_module_height(0)
{
    FAPI_TRY( mss::eff_dram_gen(i_target, iv_dram_generation) );
    FAPI_TRY( mss::eff_dimm_type(i_target, iv_dimm_type) );
    FAPI_TRY( mss::eff_dram_density(i_target, iv_dram_density) );
    FAPI_TRY( mss::eff_dram_width(i_target, iv_dram_width) );
    FAPI_TRY( mss::eff_num_master_ranks_per_dimm(i_target, iv_master_ranks) );
    FAPI_TRY( mss::eff_num_ranks_per_dimm(i_target, iv_total_ranks) );
    FAPI_TRY( mss::eff_dram_row_bits(i_target, iv_rows) );
    FAPI_TRY( mss::eff_dimm_size(i_target, iv_size) );
    FAPI_TRY( mss::eff_dram_mfg_id(i_target, iv_mfgid) );
    FAPI_TRY( mss::eff_prim_stack_type( i_target, iv_stack_type) );
    FAPI_TRY( mss::eff_hybrid( i_target, iv_hybrid ));
    FAPI_TRY( mss::eff_hybrid_memory_type( i_target, iv_hybrid_memory_type ));
    FAPI_TRY( mss::eff_rcd_mfg_id(i_target, iv_rcd_mfgid) );
    return;

fapi_try_exit:
    // Not 100% sure what to do here ...
    FAPI_ERR("error initializing DIMM structure: %s 0x%016lx", mss::c_str(i_target), uint64_t(fapi2::current_err));
    fapi2::Assert(false);
}

///
/// @brief Check if any dimms exist that have RCD enabled - nimbus/DIMM specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_has_rcd - true iff any DIMM with RCD detected
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode has_rcd<mss::mc_type::NIMBUS>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        bool& o_has_rcd );


} //end dimm ns
} //end mss ns
#endif
