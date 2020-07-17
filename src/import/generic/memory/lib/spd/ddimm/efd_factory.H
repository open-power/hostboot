/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/ddimm/efd_factory.H $       */
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
/// @file efd_decoder.H
/// @brief DDIMM Extended Functional Data (EFD) decoder
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _EFD_FACTORY_H_
#define _EFD_FACTORY_H_

#include <fapi2.H>
#include <generic/memory/lib/spd/ddimm/ddr4/efd_ddr4_custom_microchip_decoder.H>

namespace mss
{

namespace efd
{

///
/// @brief Generates the EFD decoder based upon the EFD type
/// @param[in] i_target DIMM target
/// @param[in] i_rev SPD revision
/// @param[in] i_data SPD data
/// @param[in] i_rank the current rank
/// @param[out] o_decoder shared pointer to the decoder in question
/// @return fapi2::ReturnCode SUCCESS iff the procedure executes successfully
///
// TODO:update this for other types of EFD
inline fapi2::ReturnCode factory(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                 const uint8_t i_rev,
                                 const std::vector<uint8_t>& i_data,
                                 const size_t i_rank,
                                 std::shared_ptr<base_decoder>& o_decoder_ptr)
{
    // Poor man's fallback technique: if we receive a revision that's later than (or numerically
    // greater than) the latest supported, we'll decode as if it's the latest supported rev
    const uint8_t l_fallback_rev = (i_rev > mss::spd::rev::DDIMM_MAX) ? mss::spd::rev::DDIMM_MAX : i_rev;

    switch (l_fallback_rev)
    {
        case mss::spd::rev::V0_3:
            {
                o_decoder_ptr = std::make_shared<mss::efd::decoder<mss::spd::device_type::DDR4,
                DDR4_CUSTOM_MICROCHIP,
                mss::spd::rev::V0_3>>(i_target, i_data, i_rank);
                return fapi2::FAPI2_RC_SUCCESS;
                break;
            }

        case mss::spd::rev::V0_4:
            {
                o_decoder_ptr = std::make_shared<mss::efd::decoder<mss::spd::device_type::DDR4,
                DDR4_CUSTOM_MICROCHIP,
                mss::spd::rev::V0_4>>(i_target, i_data, i_rank);
                return fapi2::FAPI2_RC_SUCCESS;
                break;
            }

        default:
            {
                FAPI_ASSERT(false,
                            fapi2::MSS_INVALID_SPD_PARAMETER_RECEIVED()
                            .set_SPD_PARAM(i_rev)
                            .set_FUNCTION_CODE(EFD_FACTORY)
                            .set_TARGET(i_target),
                            "Unsupported SPD revision received in EFD decoder factory 0x%02x for %s",
                            i_rev, spd::c_str(i_target));
            }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // ns efd
} // ns mss

#endif
