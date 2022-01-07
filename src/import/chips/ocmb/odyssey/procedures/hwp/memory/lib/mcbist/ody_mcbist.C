/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/mcbist/ody_mcbist.C $ */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_mcbist.C
/// @brief Run and manage the MCBIST engine
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/mcbist/ody_mcbist_traits.H>

namespace mss
{

const std::pair<uint64_t, uint64_t> mcbistTraits<mss::mc_type::ODYSSEY>::address_pairs[] =
{
    { START_ADDRESS_0, END_ADDRESS_0 },
    { START_ADDRESS_1, END_ADDRESS_1 },
    { START_ADDRESS_2, END_ADDRESS_2 },
    { START_ADDRESS_3, END_ADDRESS_3 },
};

const std::vector< mss::mcbist::op_type > mcbistTraits<mss::mc_type::ODYSSEY>::FIFO_MODE_REQUIRED_OP_TYPES =
{
    mss::mcbist::op_type::WRITE            ,
    mss::mcbist::op_type::READ             ,
    mss::mcbist::op_type::READ_WRITE       ,
    mss::mcbist::op_type::WRITE_READ       ,
    mss::mcbist::op_type::READ_WRITE_READ  ,
    mss::mcbist::op_type::READ_WRITE_WRITE ,
    mss::mcbist::op_type::RAND_SEQ         ,
    mss::mcbist::op_type::READ_READ_WRITE  ,
};

// These values are pulled out of the MCBIST specification
// The index is the fixed width - the value is the LFSR_MASK value to be used
const std::vector< uint64_t > mcbistTraits<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>::LFSR_MASK_VALUES =
{
    0x000000031,
    0x00000001F,
    0x001000000,
    0x100000000,
    0x004000003,
    0x000080000,
    0x040000018,
    0x008000000,
    0x010006000,
    0x004000000,
    0x001000000,
    0x003200000,
    0x001880000,
    0x000200000,
    0x000610000,
    0x000100000,
    0x000040000,
    0x000010000,
    0x000023000,
    0x000002000,
    0x000000400,
    0x000002000,
    0x000005008,
    0x000002000,
    0x000001088,
    0x000000B00,
    0x0000004A0,
    0x000000100,
    0x000000040,
    0x000000010,
    0x000000038,
    0x000000008,
    0x000000010,
    0x000000004,
    0x000000004,
    0x000000002,
    0x000000001,
};

namespace mcbist
{

///
/// @brief Load MCBIST ECC (and?) spare data pattern given a pattern - Odyssey specialization
/// @param[in] i_target the target to effect
/// @param[in] i_pattern an mcbist::patterns
/// @param[in] i_invert whether to invert the pattern or not
/// @return FAPI2_RC_SUCCSS iff ok
///
template< >
fapi2::ReturnCode load_eccspare_pattern<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const pattern& i_pattern,
    const bool i_invert )
{
    // First up assemble the pattern
    const auto l_pattern = generate_eccspare_pattern(i_pattern, i_invert);

    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_MCBIST_SCOM_MCBFDQ, l_pattern));
    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_MCBIST_SCOM_MCBFDSPQ, l_pattern));

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace mcbist
} // namespace mss
