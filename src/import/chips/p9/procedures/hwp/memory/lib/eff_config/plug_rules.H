/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/eff_config/plug_rules.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file plug_rules.H
/// @brief Enforcement of rules for plugging in DIMM
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_PLUG_RULES_H_
#define _MSS_PLUG_RULES_H_

#include <fapi2.H>
#include <cstdint>
#include <lib/dimm/kind.H>

namespace mss
{

namespace plug_rule
{


///
/// @brief Enforce the plug-rules per MCS
/// @param[in] i_target FAPI2 target (MCS)
/// @return fapi2::FAPI2_RC_SUCCESS if okay, otherwise a MSS_PLUG_RULE error code
///
fapi2::ReturnCode enforce_plug_rules(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target);

///
/// @brief Enforce the plug-rules per MCA
/// @param[in] i_target FAPI2 target (MCA)
/// @return fapi2::FAPI2_RC_SUCCESS if okay, otherwise a MSS_PLUG_RULE error code
///
fapi2::ReturnCode enforce_plug_rules(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

///
/// @brief Helper to evaluate the unsupported rank config override attribute
/// @param[in] i_dimm0_ranks count of the ranks on DIMM in slot 0
/// @param[in] i_dimm1_ranks count of the ranks on DIMM in slot 1
/// @param[in] i_attr value of the attribute containing the unsupported rank configs
/// @return true iff this rank config is supported according to the unsupported attribute
/// @note not to be used to enforce populated/unpopulated - e.g., 0 ranks in both slots is ignored
///
bool unsupported_rank_helper(const uint64_t i_dimm0_ranks,
                             const uint64_t i_dimm1_ranks,
                             const fapi2::buffer<uint64_t>& i_attr);
///
/// @brief Enforces the DEAD LOAD rules
/// @tparam T fapi2::Target, either MCA or MCS
/// @param[in] i_target the MCA/ port target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note This function will deconfigure the port if it's dual drop and one of the dimms is deconfigured
///
template<fapi2::TargetType T>
fapi2::ReturnCode check_dead_load( const fapi2::Target<T>& i_target);

///
/// @brief Enforce having one solitary DIMM plugged into slot 0
/// @tparam T fapi2::Target, either MCA or MCS
/// @param[in] i_target port target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
template<fapi2::TargetType T>
fapi2::ReturnCode empty_slot_zero(const fapi2::Target<T>& i_target);

///
/// @brief Helper to find the best represented DIMM type in a vector of dimm::kind
/// @param[in, out] io_kinds a vector of dimm::kind
/// @return std::pair representing the type and the count.
/// @note the vector of kinds comes back sorted by DIMM type.
///
std::pair<uint8_t, uint64_t> dimm_type_helper(std::vector<dimm::kind>& io_kinds);

///
/// @brief Rank violation helper
/// Used to record a rank configuration violation. Broken out from other checking
/// so that we can throw a rank violation directly from VPD processing.
/// @tparam T target type for the error log
/// @param[in] i_target the target which constrains the rank violation checking
/// @param[in] l_dimm0_ranks the number of ranks on the DIMM in slot 0
/// @param[in] l_dimm1_ranks the number of ranks on the DIMM in slot 1
/// @note Commits the proper error log; does little else
/// @note Not presently used, but also not compiled in - left here because I think we're
/// gonna need it eventually.
///
template< fapi2::TargetType T >
inline void rank_violation(const fapi2::Target<T>& i_target, const uint8_t l_dimm0_ranks, const uint8_t l_dimm1_ranks)
{
    // fapi2::current_err will NOT be set which is important for the caller - they can return
    // the original ReturnCode which got us here.
    FAPI_ERR("Rank config on %s violates the rank configuration rules. DIMM0 ranks: %d DIMM1 ranks: %d",
             mss::c_str(i_target), l_dimm0_ranks, l_dimm1_ranks);

    fapi2::MSS_PLUG_RULES_INVALID_RANK_CONFIG()
    .set_RANKS_ON_DIMM0(l_dimm0_ranks)
    .set_RANKS_ON_DIMM1(l_dimm1_ranks)
    .set_TARGET(i_target).execute(fapi2::FAPI2_ERRL_SEV_UNDEFINED, true);
}

///
/// @brief Enforce no mixing DIMM types
/// @param[in] i_target the port to check
/// @param[in] i_kinds a vector of DIMM (sorted while procesing)
/// @return fapi2::FAPI2_RC_SUCCESS if okay, otherwise a MSS_PLUG_RULE error code
/// @note This function will commit error logs representing the mixing failure
///
fapi2::ReturnCode dimm_type_mixing(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                   const std::vector<dimm::kind>& i_kinds);

///
/// @brief Enforce rank configs
/// Enforces rank configurations which are not part of the VPD/rank config thing.
/// @note Reads an MRW attribute to further limit rank configs.
/// @param[in] i_target the port
/// @param[in] i_kinds a vector of DIMM (sorted while processing)
/// @param[in] i_ranks_override value of mrw_unsupported_rank_config attribute
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Expects the kind array to represent the DIMM on the port.
///
fapi2::ReturnCode check_rank_config(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                    const std::vector<dimm::kind>& i_kinds,
                                    const uint64_t i_ranks_override);

///
/// @brief Enforce DRAM width checks
/// @note DIMM0's width needs to equal DIMM1's width
/// @param[in] i_target the port
/// @param[in] i_kinds a vector of DIMM (sorted while processing)
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Expects the kind array to represent the DIMM on the port.
///
fapi2::ReturnCode check_dram_width(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                   const std::vector<dimm::kind>& i_kinds);

///
/// @brief Enforce DRAM stack type checks
/// @note No 3DS and non-3DS DIMM's can mix
/// @param[in] i_target the port
/// @param[in] i_kinds a vector of DIMM (sorted while processing)
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Expects the kind array to represent the DIMM on the port.
///
fapi2::ReturnCode check_stack_type(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                   const std::vector<dimm::kind>& i_kinds);

///
/// @brief Enforce hybrid DIMM checks
/// @note No hybrid/non-hybrid and no different hybrid types
/// @param[in] i_target the port
/// @param[in] i_kinds a vector of DIMM (sorted while processing)
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Expects the kind array to represent the DIMM on the port.
///
fapi2::ReturnCode check_hybrid(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                               const std::vector<dimm::kind>& i_kinds);

// Adding in code based plug rules - as supporting code gets added, the following checks can be deleted
namespace code
{

///
/// @brief Checks for invalid LRDIMM plug combinations
/// @param[in] i_kinds a vector of DIMM (sorted while procesing)
/// @return fapi2::FAPI2_RC_SUCCESS if no LRDIMM, otherwise a MSS_PLUG_RULE error code
/// @note This function will commit error logs representing the mixing failure
///
fapi2::ReturnCode check_lrdimm( const std::vector<dimm::kind>& i_kinds );

} // code

} // plug_rule
} // mss

#endif // _MSS_PLUG_RULES_H_
