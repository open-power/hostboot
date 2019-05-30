/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/ddimm/efd_factory.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @param[in] i_data SPD data
/// @param[in] i_rank the current rank
/// @param[out] o_decoder shared pointer to the decoder in question
/// @return fapi2::ReturnCode SUCCESS iff the procedure executes successfully
///
// TODO:update this for other types of EFD
inline fapi2::ReturnCode factory(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                 const std::vector<uint8_t>& i_data,
                                 const size_t i_rank,
                                 std::shared_ptr<base_decoder>& o_decoder_ptr)
{
    o_decoder_ptr = std::make_shared<mss::efd::decoder<mss::spd::device_type::DDR4,
    DDR4_CUSTOM_MICROCHIP,
    mss::spd::rev::V0_0>>(i_target, i_data, i_rank);
    return fapi2::FAPI2_RC_SUCCESS;
}

} // ns efd
} // ns mss

#endif
