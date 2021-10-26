/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mcbist/exp_mcbist.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file exp_mcbist.C
/// @brief Run and manage the MCBIST engine
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/shared/exp_defaults.H>
#include <lib/shared/exp_consts.H>
#include <lib/mcbist/exp_mcbist.H>
#include <mss_explorer_attribute_getters.H>
#include <mss_explorer_attribute_setters.H>
#include <mss_generic_attribute_getters.H>

namespace mss
{

///
/// @brief Gets the attribute for freq
/// @param[in] const ref to the target
/// @param[out] uint64_t& reference to store the value
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note  Frequency of this memory channel in MT/s (Mega Transfers per second)
///
template<>
fapi2::ReturnCode freq<mss::mc_type::EXPLORER, fapi2::TARGET_TYPE_OCMB_CHIP>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    uint64_t& o_value)
{
    // Each OCMB only has one MEM_PORT
    for (const auto l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        return attr::get_freq(l_port, o_value);
    }

    o_value = 0;
    return ~fapi2::FAPI2_RC_SUCCESS;
}

const std::pair<uint64_t, uint64_t> mcbistTraits<mss::mc_type::EXPLORER>::address_pairs[] =
{
    { START_ADDRESS_0, END_ADDRESS_0 },
    { START_ADDRESS_1, END_ADDRESS_1 },
    { START_ADDRESS_2, END_ADDRESS_2 },
    { START_ADDRESS_3, END_ADDRESS_3 },
};

const std::vector< mss::mcbist::op_type > mcbistTraits<mss::mc_type::EXPLORER>::FIFO_MODE_REQUIRED_OP_TYPES =
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

// These valus are pulled out of the MCBIST specification - page 41 10-DEC-19
// The index is the fixed width - the value is the LFSR_MASK value to be used
const std::vector< uint64_t > mcbistTraits<mss::mc_type::EXPLORER, fapi2::TARGET_TYPE_OCMB_CHIP>::LFSR_MASK_VALUES =
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
/// @brief Get a list of ports involved in the program
/// Specialization for program<mss::mc_type::EXPLORER>
/// @param[in] i_target the target for this program
/// @return vector of port targets
///
template<>
std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>>
        program<mss::mc_type::EXPLORER>::get_port_list( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target ) const
{

    return mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target);
}
///
/// @brief Configures broadcast mode, if it is needed
/// @param[in] i_target the target to effect
/// @param[in,out] io_program the mcbist::program
/// @return FAPI2_RC_SUCCSS iff ok
///
template<>
fapi2::ReturnCode configure_broadcast_mode(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        mcbist::program<mss::mc_type::EXPLORER>& io_program)
{
    // No broadcast mode for explorer
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Read entries from MCBIST Read Buffer (RB) array
/// Specialization for EXPLORER/fapi2::TARGET_TYPE_MEM_PORT
/// @param[in] i_target the target to effect
/// @param[in] i_start_addr the array address to read first
/// @param[in] i_num_entries the number of array entries to read
/// @param[out] o_data vector of output data
/// @param[out] o_ecc_data vector of ecc data
/// @return FAPI2_RC_SUCCSS iff ok
///
template<>
fapi2::ReturnCode read_rb_array<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint64_t i_start_addr,
        const uint64_t i_num_entries,
        std::vector< fapi2::buffer<uint64_t> >& o_data,
        std::vector< fapi2::buffer<uint64_t> >& o_ecc_data)
{
    using TT = mcbistTraits<DEFAULT_MC_TYPE, fapi2::TARGET_TYPE_OCMB_CHIP>;

    fapi2::buffer<uint64_t> l_data;
    uint64_t l_array_addr = i_start_addr;

    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    // Clear out any stale values from output vectors
    o_data.clear();
    o_ecc_data.clear();

    for (uint8_t l_index = 0; l_index < i_num_entries; ++l_index)
    {
        fapi2::buffer<uint64_t> l_control_value;

        // set start address
        l_control_value.insertFromRight<TT::RB_ADDRESS, TT::RB_ADDRESS_LEN>(l_array_addr);

        FAPI_INF("Setting the RB array access control register.");
        FAPI_TRY( mss::putScom(l_ocmb, TT::RD_BUF_CTL_REG, l_control_value) );


        // We setup the address to what we need it to be, so let's continue
        FAPI_TRY( mss::getScom(i_target, TT::RD_BUF_DATA_REG, l_data) );
        FAPI_INF("RB data index %d is: 0x%016lx", l_array_addr, l_data);
        o_data.push_back(l_data);

        // Need to read ecc register to increment array index
        FAPI_TRY( mss::getScom(i_target, TT::RD_BUF_ECC_REG, l_data) );
        o_ecc_data.push_back(l_data);
        ++l_array_addr;

        // Array address automatically rolls over if we go beyond NUM_COMPARE_LOG_ENTRIES
        if (l_array_addr >= TT::NUM_COMPARE_LOG_ENTRIES)
        {
            l_array_addr = 0;
        }

    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Load MCBIST ECC (and?) spare data pattern given a pattern - explorer specialization
/// @param[in] i_target the target to effect
/// @param[in] i_pattern an mcbist::patterns
/// @param[in] i_invert whether to invert the pattern or not
/// @return FAPI2_RC_SUCCSS iff ok
///
template< >
fapi2::ReturnCode load_eccspare_pattern<mss::mc_type::EXPLORER>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const pattern& i_pattern,
    const bool i_invert )
{
    // First up assemble the pattern
    const auto l_pattern = generate_eccspare_pattern(i_pattern, i_invert);

    FAPI_TRY(fapi2::putScom(i_target, EXPLR_MCBIST_MCBFDQ, l_pattern));
    FAPI_TRY(fapi2::putScom(i_target, EXPLR_MCBIST_MCBFDSPQ, l_pattern));

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace mcbist
} // namespace mss
