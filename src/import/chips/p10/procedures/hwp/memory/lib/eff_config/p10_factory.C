/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_factory.C $ */
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
/// @file p10_factory.C
/// @brief P10 eff_config decoder factory
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <lib/eff_config/p10_factory.H>

namespace mss
{
namespace efd
{

///
/// @brief Generates the EFD engine based upon the EFD type
/// @param[in] i_target DIMM target
/// @param[in] i_rev SPD revision
/// @param[in] i_rank_info the current rank info class
/// @param[out] o_efd_engine shared pointer to the EFD engine in question
/// @return fapi2::ReturnCode SUCCESS iff the procedure executes successfully
/// @note TODO/TK can be updated in the future for different dimm types and DDR4/5
///
fapi2::ReturnCode factory(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                          const uint8_t i_rev,
                          const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info,
                          std::shared_ptr<mss::efd::ddimm_efd_base>& o_efd_engine)
{
    // Poor man's fallback technique: if we receive a revision that's later than (or numerically
    // greater than) the latest supported, we'll decode as if it's the latest supported rev
    const uint8_t l_fallback_rev = (i_rev > mss::spd::rev::DDIMM_MAX) ? mss::spd::rev::DDIMM_MAX : i_rev;

    switch (l_fallback_rev)
    {
        case mss::spd::rev::V0_3:
            {

                o_efd_engine = std::make_shared<mss::efd::ddimm_efd_0_3>(i_target, i_rank_info);
                return fapi2::FAPI2_RC_SUCCESS;
                break;
            }

        case mss::spd::rev::V0_4:
            {
                o_efd_engine = std::make_shared<mss::efd::ddimm_efd_0_4>(i_target, i_rank_info);
                return fapi2::FAPI2_RC_SUCCESS;
                break;
            }

        default:
            {
                FAPI_ASSERT(false,
                            fapi2::MSS_INVALID_SPD_REVISION()
                            .set_SPD_REVISION(i_rev)
                            .set_FUNCTION_CODE(EFD_FACTORY)
                            .set_DIMM_TARGET(i_target),
                            "Unsupported SPD revision received in EFD decoder factory 0x%02x for %s",
                            i_rev, spd::c_str(i_target));
            }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // ns efd

namespace spd
{

///
/// @brief Generates the SPD engines based upon the rev
/// @param[in] i_target DIMM target
/// @param[in] i_rev SPD revision
/// @param[out] o_base_engine shared pointer to the Base cnfg engine in question
/// @param[out] o_ddimm_engine shared pointer to the DDIMM cnfg engine in question
/// @return fapi2::ReturnCode SUCCESS iff the procedure executes successfully
/// @note TODO/TK can be updated in the future for different dimm types and DDR4/5
///
fapi2::ReturnCode factory(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                          const uint8_t i_rev,
                          std::shared_ptr<mss::spd::base_cnfg_base>& o_base_engine,
                          std::shared_ptr<mss::spd::ddimm_base>& o_ddimm_engine)
{
    // Poor man's fallback technique: if we receive a revision that's later than (or numerically
    // greater than) the latest supported, we'll decode as if it's the latest supported rev
    const uint8_t l_fallback_rev = (i_rev > mss::spd::rev::DDIMM_MAX) ? mss::spd::rev::DDIMM_MAX : i_rev;

    switch (l_fallback_rev)
    {
        case mss::spd::rev::V0_3:
            {
                o_base_engine = std::make_shared<mss::spd::base_0_3>(i_target);
                o_ddimm_engine = std::make_shared<mss::spd::ddimm_0_3>(i_target);
                return fapi2::FAPI2_RC_SUCCESS;
                break;
            }

        case mss::spd::rev::V0_4:
            {
                o_base_engine = std::make_shared<mss::spd::base_0_4>(i_target);
                o_ddimm_engine = std::make_shared<mss::spd::ddimm_0_4>(i_target);
                return fapi2::FAPI2_RC_SUCCESS;
                break;
            }

        default:
            {
                FAPI_ASSERT(false,
                            fapi2::MSS_INVALID_SPD_REVISION()
                            .set_SPD_REVISION(i_rev)
                            .set_FUNCTION_CODE(SPD_FACTORY)
                            .set_DIMM_TARGET(i_target),
                            "Unsupported SPD revision received in SPD decoder factory 0x%02x for %s",
                            i_rev, spd::c_str(i_target));
            }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // ns spd
} // ns mss
