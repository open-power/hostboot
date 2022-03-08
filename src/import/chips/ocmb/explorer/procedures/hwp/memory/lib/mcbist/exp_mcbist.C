/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mcbist/exp_mcbist.C $ */
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
/// @file exp_mcbist.C
/// @brief Run and manage the MCBIST engine
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
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
    using TT = mcbistTraits<mss::mc_type::EXPLORER, fapi2::TARGET_TYPE_OCMB_CHIP>;

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

///
/// @brief Get the address of mrank 0 buffer
/// @return Address of mrank 0 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_mrank0_bit()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of mrank0 buffer when in 5D mode
/// @return Address of mrank0 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_mrank0_bit_5d()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of mrank1 buffer
/// @return Address of mrank1 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_mrank1_bit()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of mrank1 buffer when in 5D mode
/// @return Address of mrank1 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_mrank1_bit_5d()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of mrank2 buffer when in 5D mode
/// @return Address of mrank2 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_mrank2_bit_5d()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of srank0 buffer
/// @return Address of mrank0 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_srank0_bit()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of srank1 buffer
/// @return Address of srank1 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_srank1_bit()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of srank2 buffer
/// @return Address of srank2 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_srank2_bit()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of bank2 buffer
/// @return Address of bank2 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_bank2_bit()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of bank1 buffer
/// @return Address of bank1 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_bank1_bit()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of bank 0 buffer
/// @return Address of bank 0 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_bank0_bit()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of bank group1 buffer
/// @return Address of bank group1 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_bank_group1_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of bank group0 buffer
/// @return Address of bank group0 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_bank_group0_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of row17 buffer
/// @return Address of row17 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row17_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of row16 buffer
/// @return Address of row16 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row16_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of row15 buffer
/// @return Address of row15 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row15_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of row14 buffer
/// @return Address of row14 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row14_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of row13 buffer
/// @return Address of row13 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row13_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of row12 buffer
/// @return Address of row12 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row12_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of row11 buffer
/// @return Address of row11 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row11_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of row10 buffer
/// @return Address of row10 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row10_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of row9 buffer
/// @return Address of row9 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row9_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of row8 buffer
/// @return Address of row8 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row8_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of row7 buffer
/// @return Address of row7 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row7_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of row6 buffer
/// @return Address of row6 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row6_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of row5 buffer
/// @return Address of row5 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row5_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of row4 buffer
/// @return Address of row4 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row4_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of row3 buffer
/// @return Address of row3 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row3_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of row2 buffer
/// @return Address of row2 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row2_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of row1 buffer
/// @return Address of row1 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row1_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of row0 buffer
/// @return Address of row0 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row0_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of col9 buffer
/// @return Address of col9 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_col9_bit()
{
    return iv_addr_map3;
}

///
/// @brief Get the address of col8 buffer
/// @return Address of col8 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_col8_bit()
{
    return iv_addr_map3;
}

///
/// @brief Get the address of col7 buffer
/// @return Address of col7 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_col7_bit()
{
    return iv_addr_map3;
}

///
/// @brief Get the address of col6 buffer
/// @return Address of col6 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_col6_bit()
{
    return iv_addr_map3;
}

///
/// @brief Get the address of col5 buffer
/// @return Address of col5 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_col5_bit()
{
    return iv_addr_map3;
}

///
/// @brief Get the address of col4 buffer
/// @return Address of col4 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_col4_bit()
{
    return iv_addr_map3;
}

///
/// @brief Get the address of col3 buffer
/// @return Address of col3 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_col3_bit()
{
    return iv_addr_map3;
}

///
/// @brief Get the address of col2 buffer
/// @return Address of col2 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_col2_bit()
{
    return iv_addr_map3;
}

///
/// @brief Change the BANK2 address mapping
/// @param[in] i_bitmap BANK2 bit map in the address counter
/// @note Assumes data is right-aligned
///
template <>
void program<mss::mc_type::EXPLORER>::change_bank2_bit( const uint64_t i_bitmap )
{
    using TT = mcbistTraits<mc_type::EXPLORER, fapi2::TARGET_TYPE_OCMB_CHIP>;
    iv_addr_map0.insertFromRight<TT::CFG_AMAP_BANK2, TT::CFG_AMAP_BANK2_LEN>(i_bitmap);
    return;
}

///
/// @brief Change the DIMM select in the address mapping
/// @param[in] i_bitmap DIMM select bit map in the address counter
/// @note Assumes data is right-aligned
///
template <>
void program<mss::mc_type::EXPLORER>::change_dimm_select_bit( const uint64_t i_bitmap )
{
    using TT = mcbistTraits<mc_type::EXPLORER, fapi2::TARGET_TYPE_OCMB_CHIP>;
    iv_addr_map0.insertFromRight<TT::CFG_AMAP_DIMM_SELECT, TT::CFG_AMAP_DIMM_SELECT_LEN>(i_bitmap);
    return;
}

///
/// @brief Change the COL10 address mapping
/// @param[in] i_bitmap COL10 bit map in the address counter
/// @note Assumes data is right-aligned
///
template <>
void program<mss::mc_type::EXPLORER>::change_col10_bit( const uint64_t i_bitmap )
{
    return;
}

/// @brief Change the ROQ address mapping
/// @param[in] i_bitmap ROQ bit map in the address counter
/// @note Assumes data is right-aligned
///
template <>
void program<mss::mc_type::EXPLORER>::change_roq_bit( const uint64_t i_bitmap )
{
    return;
}

///
/// @brief Change the BANK_GROUP2 address mapping
/// @param[in] i_bitmap BANK_GROUP2 bit map in the address counter
/// @note Assumes data is right-aligned
///
template <>
void program<mss::mc_type::EXPLORER>::change_bank_group2_bit( const uint64_t i_bitmap )
{
    return;
}

} // namespace mcbist
} // namespace mss
