/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/mcbist/ody_mcbist.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
#include <lib/mcbist/ody_mcbist.H>

namespace mss
{

// Generates linkage
// Registers used to load data patterns
const mss::pair<uint64_t, uint64_t>
mcbistTraits<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>::PATTERN_REGS[EXPECTED_PATTERN_SIZE] =
{
    {scomt::ody::ODC_MCBIST_SCOM_MCBFD0Q, scomt::ody::ODC_MCBIST_SCOM_MCBFD1Q},
    {scomt::ody::ODC_MCBIST_SCOM_MCBFD2Q, scomt::ody::ODC_MCBIST_SCOM_MCBFD3Q},
    {scomt::ody::ODC_MCBIST_SCOM_MCBFD4Q, scomt::ody::ODC_MCBIST_SCOM_MCBFD5Q},
    {scomt::ody::ODC_MCBIST_SCOM_MCBFD6Q, scomt::ody::ODC_MCBIST_SCOM_MCBFD7Q},
    {scomt::ody::ODC_MCBIST_SCOM_MCBFD8Q, scomt::ody::ODC_MCBIST_SCOM_MCBFD9Q},
    {scomt::ody::ODC_MCBIST_SCOM_MCBFDAQ, scomt::ody::ODC_MCBIST_SCOM_MCBFDBQ},
    {scomt::ody::ODC_MCBIST_SCOM_MCBFDCQ, scomt::ody::ODC_MCBIST_SCOM_MCBFDDQ},
    {scomt::ody::ODC_MCBIST_SCOM_MCBFDEQ, scomt::ody::ODC_MCBIST_SCOM_MCBFDFQ},
};

///
/// @brief Gets the attribute for freq
/// @param[in] const ref to the target
/// @param[out] uint64_t& reference to store the value
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note  Frequency of this memory channel in MT/s (Mega Transfers per second)
///
template<>
fapi2::ReturnCode freq<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    uint64_t& o_value)
{
    for (const auto l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        return FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_FREQ, l_port, o_value);
    }

    o_value = 0;
    return fapi2::FAPI2_RC_FALSE;
}

const mss::pair<uint64_t, uint64_t> mcbistTraits<mss::mc_type::ODYSSEY>::address_pairs[] =
{
    { START_ADDRESS_0, END_ADDRESS_0 },
    { START_ADDRESS_1, END_ADDRESS_1 },
    { START_ADDRESS_2, END_ADDRESS_2 },
    { START_ADDRESS_3, END_ADDRESS_3 },
};

constexpr mss::mcbist::op_type mcbistTraits<mss::mc_type::ODYSSEY>::FIFO_MODE_REQUIRED_OP_TYPES[];

// These values are pulled out of the MCBIST specification
// The index is the fixed width - the value is the LFSR_MASK value to be used
const uint64_t mcbistTraits<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>::LFSR_MASK_VALUES[37] =
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
/// @brief Processes the first AADR/AAER into a beat pair
/// @param[in] i_aadr the AADR to process
/// @param[in] i_aaer the AAER to process
/// @param[in,out] io_beat_pair the beat pair to update
///
void process_first_data_compare_trap(const fapi2::buffer<uint64_t>& i_aadr,
                                     const fapi2::buffer<uint64_t>& i_aaer,
                                     mss::beat_pair& io_beat_pair)
{
    constexpr uint64_t BYTE4_IDX = 4;
    constexpr uint64_t BYTE3_IDX = 3;
    constexpr uint64_t BYTE2_IDX = 2;
    constexpr uint64_t BYTE1_IDX = 1;
    constexpr uint64_t BYTE0_IDX = 0;
    constexpr uint64_t BEAT0 = 0;
    constexpr uint64_t BEAT1 = 1;
    constexpr uint64_t AAER_START = 0;
    constexpr uint64_t BYTE0_POS = 0 * BITS_PER_BYTE;
    constexpr uint64_t BYTE1_POS = 1 * BITS_PER_BYTE;
    constexpr uint64_t BYTE2_POS = 2 * BITS_PER_BYTE;
    constexpr uint64_t BYTE3_POS = 3 * BITS_PER_BYTE;
    constexpr uint64_t BYTE4_POS = 4 * BITS_PER_BYTE;
    constexpr uint64_t BYTE5_POS = 5 * BITS_PER_BYTE;
    constexpr uint64_t BYTE6_POS = 6 * BITS_PER_BYTE;
    constexpr uint64_t BYTE7_POS = 7 * BITS_PER_BYTE;
    i_aadr.extractToRight<BYTE0_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE3_IDX][BEAT1]);
    i_aadr.extractToRight<BYTE1_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE3_IDX][BEAT0]);
    i_aadr.extractToRight<BYTE2_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE2_IDX][BEAT1]);
    i_aadr.extractToRight<BYTE3_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE2_IDX][BEAT0]);
    i_aadr.extractToRight<BYTE4_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE1_IDX][BEAT1]);
    i_aadr.extractToRight<BYTE5_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE1_IDX][BEAT0]);
    i_aadr.extractToRight<BYTE6_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE0_IDX][BEAT1]);
    i_aadr.extractToRight<BYTE7_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE0_IDX][BEAT0]);


    i_aaer.extractToRight<AAER_START, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE4_IDX][BEAT0]);
}

///
/// @brief Processes the second AADR/AAER into a beat pair
/// @param[in] i_aadr the AADR to process
/// @param[in] i_aaer the AAER to process
/// @param[in,out] io_beat_pair the beat pair to update
///
void process_second_data_compare_trap(const fapi2::buffer<uint64_t>& i_aadr,
                                      const fapi2::buffer<uint64_t>& i_aaer,
                                      mss::beat_pair& io_beat_pair)
{
    constexpr uint64_t BYTE4_IDX = 4;
    constexpr uint64_t BYTE9_IDX = 9;
    constexpr uint64_t BYTE8_IDX = 8;
    constexpr uint64_t BYTE7_IDX = 7;
    constexpr uint64_t BYTE6_IDX = 6;
    constexpr uint64_t BEAT0 = 0;
    constexpr uint64_t BEAT1 = 1;
    constexpr uint64_t AAER_START = 0;
    constexpr uint64_t BYTE0_POS = 0 * BITS_PER_BYTE;
    constexpr uint64_t BYTE1_POS = 1 * BITS_PER_BYTE;
    constexpr uint64_t BYTE2_POS = 2 * BITS_PER_BYTE;
    constexpr uint64_t BYTE3_POS = 3 * BITS_PER_BYTE;
    constexpr uint64_t BYTE4_POS = 4 * BITS_PER_BYTE;
    constexpr uint64_t BYTE5_POS = 5 * BITS_PER_BYTE;
    constexpr uint64_t BYTE6_POS = 6 * BITS_PER_BYTE;
    constexpr uint64_t BYTE7_POS = 7 * BITS_PER_BYTE;
    i_aadr.extractToRight<BYTE0_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE9_IDX][BEAT1]);
    i_aadr.extractToRight<BYTE1_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE9_IDX][BEAT0]);
    i_aadr.extractToRight<BYTE2_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE8_IDX][BEAT1]);
    i_aadr.extractToRight<BYTE3_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE8_IDX][BEAT0]);
    i_aadr.extractToRight<BYTE4_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE7_IDX][BEAT1]);
    i_aadr.extractToRight<BYTE5_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE7_IDX][BEAT0]);
    i_aadr.extractToRight<BYTE6_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE6_IDX][BEAT1]);
    i_aadr.extractToRight<BYTE7_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE6_IDX][BEAT0]);


    i_aaer.extractToRight<AAER_START, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE4_IDX][BEAT1]);
}

///
/// @brief Reads in a single beat pair of compare data from a raw data trap
/// @param[in] i_trap the data trap to process
/// @param[in,out] io_beat_pair the beat pair processed from the data trap
///
void process_data_compare_beat_pair(const raw_data_trap& i_trap, beat_pair& io_beat_pair)
{
    process_first_data_compare_trap(i_trap.iv_aadr_first, i_trap.iv_aaer_first, io_beat_pair);
    process_second_data_compare_trap(i_trap.iv_aadr_second, i_trap.iv_aaer_second, io_beat_pair);
}

///
/// @brief Enable a specific port for this test - maint address mode - ODYSSEY specialization
/// @param[in] i_port the port desired to be enabled - int 0, 1, 2, 3
/// @note The port number is relative to the MCBIST
/// @return void
///
template<>
void subtest_t<mss::mc_type::ODYSSEY>::enable_port( const uint64_t i_port )
{
    using TT = mcbistTraits<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>;
    // Odyssey uses COMPL_3RD_CMD to select the port
    iv_mcbmr.template writeBit<TT::COMPL_3RD_CMD>(i_port);
    return;
}

///
/// @brief Enable a specific dimm for this test - maint address mode - ODYSSEY specialization
/// @param[in] i_dimm the dimm desired to be enabled - int 0, 1
/// @return void
///
template<>
void subtest_t<mss::mc_type::ODYSSEY>::enable_dimm( const uint64_t i_dimm )
{
    // Odyssey doesn't use the DIMM field
    return;
}

///
/// @brief Get the port from this subtest - ODYSSEY specialization
/// @note The port number is relative to the MCBIST
/// @return the port of the subtest
///
template<>
uint64_t subtest_t<mss::mc_type::ODYSSEY>::get_port() const
{
    using TT = mcbistTraits<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>;
    return iv_mcbmr.template getBit<TT::COMPL_3RD_CMD>() ? 1 : 0;
}

///
/// @brief Get the DIMM from this subtest - ODYSSEY specialization
/// @return the DIMM this subtest has been configured for
///
template<>
uint64_t subtest_t<mss::mc_type::ODYSSEY>::get_dimm() const
{
    // Odyssey doesn't use the DIMM field
    return 0;
}

///
/// @brief Get a list of ports involved in the program
/// Specialization for program<mss::mc_type::ODYSSEY>
/// @param[in] i_target the target for this program
/// @return vector of port targets
///
template<>
std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>>
        program<mss::mc_type::ODYSSEY>::get_port_list( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target ) const
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
        mcbist::program<mss::mc_type::ODYSSEY>& io_program)
{
    // No broadcast mode for ODYSSEY
    return fapi2::FAPI2_RC_SUCCESS;
}

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
    const auto l_pattern_0to7  = generate_eccspare_pattern(i_pattern, i_invert);
    const auto l_pattern_8to15 = generate_eccspare_pattern_beats8to15(i_pattern, i_invert);

    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_MCBIST_SCOM_MCBFDQ, l_pattern_0to7));
    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_MCBIST_SCOM_MCBFDSPQ, l_pattern_0to7));
    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_MCBIST_SCOM_MCBFD_HQ, l_pattern_8to15));
    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_MCBIST_SCOM_MCBFDSP_HQ, l_pattern_8to15));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get the address of mrank 0 buffer
/// @return Address of mrank 0 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_mrank0_bit()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of mrank0 buffer when in 5D mode
/// @return Address of mrank0 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_mrank0_bit_5d()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of mrank1 buffer
/// @return Address of mrank1 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_mrank1_bit()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of mrank1 buffer when in 5D mode
/// @return Address of mrank1 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_mrank1_bit_5d()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of srank0 buffer
/// @return Address of mrank0 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_srank0_bit()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of srank1 buffer
/// @return Address of srank1 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_srank1_bit()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of srank2 buffer
/// @return Address of srank2 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_srank2_bit()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of bank1 buffer
/// @return Address of bank1 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_bank1_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of bank 0 buffer
/// @return Address of bank 0 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_bank0_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of bank group1 buffer
/// @return Address of bank group1 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_bank_group1_bit()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of bank group0 buffer
/// @return Address of bank group0 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_bank_group0_bit()
{
    return iv_addr_map0;
}

///
/// @brief Get the address of row17 buffer
/// @return Address of row17 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_row17_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of row16 buffer
/// @return Address of row16 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_row16_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of row15 buffer
/// @return Address of row15 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_row15_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of row14 buffer
/// @return Address of row14 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_row14_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of row13 buffer
/// @return Address of row13 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_row13_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of row12 buffer
/// @return Address of row12 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_row12_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of row11 buffer
/// @return Address of row11 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_row11_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of row10 buffer
/// @return Address of row10 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_row10_bit()
{
    return iv_addr_map1;
}

///
/// @brief Get the address of row9 buffer
/// @return Address of row9 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_row9_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of row8 buffer
/// @return Address of row8 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_row8_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of row7 buffer
/// @return Address of row7 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_row7_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of row6 buffer
/// @return Address of row6 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_row6_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of row5 buffer
/// @return Address of row5 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_row5_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of row4 buffer
/// @return Address of row4 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_row4_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of row3 buffer
/// @return Address of row3 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_row3_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of row2 buffer
/// @return Address of row2 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_row2_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of row1 buffer
/// @return Address of row1 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_row1_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of row0 buffer
/// @return Address of row0 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_row0_bit()
{
    return iv_addr_map2;
}

///
/// @brief Get the address of col9 buffer
/// @return Address of col9 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_col9_bit()
{
    return iv_addr_map3;
}

///
/// @brief Get the address of col8 buffer
/// @return Address of col8 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_col8_bit()
{
    return iv_addr_map3;
}

///
/// @brief Get the address of col7 buffer
/// @return Address of col7 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_col7_bit()
{
    return iv_addr_map3;
}

///
/// @brief Get the address of col6 buffer
/// @return Address of col6 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_col6_bit()
{
    return iv_addr_map3;
}

///
/// @brief Get the address of col5 buffer
/// @return Address of col5 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_col5_bit()
{
    return iv_addr_map3;
}

///
/// @brief Get the address of col4 buffer
/// @return Address of col4 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_col4_bit()
{
    return iv_addr_map3;
}

///
/// @brief Get the address of col3 buffer
/// @return Address of col3 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_col3_bit()
{
    return iv_addr_map3;
}

///
/// @brief Get the address of col2 buffer
/// @return Address of col2 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::ODYSSEY>::get_addr_map_col2_bit()
{
    return iv_addr_map3;
}

///
/// @brief Change the DIMM select in the address mapping
/// @param[in] i_bitmap DIMM select bit map in the address counter
/// @note Assumes data is right-aligned
///
template <>
void program<mss::mc_type::ODYSSEY>::change_dimm_select_bit( const uint64_t i_bitmap )
{
    return;
}

///
/// @brief Change the BANK2 address mapping
/// @param[in] i_bitmap BANK2 bit map in the address counter
/// @note Assumes data is right-aligned
///
template <>
void program<mss::mc_type::ODYSSEY>::change_bank2_bit( const uint64_t i_bitmap )
{
    return;
}

///
/// @brief Change the COL10 address mapping
/// @param[in] i_bitmap COL10 bit map in the address counter
/// @note Assumes data is right-aligned
///
template <>
void program<mss::mc_type::ODYSSEY>::change_col10_bit( const uint64_t i_bitmap )
{
    using TT = mcbistTraits<mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>;
    iv_addr_map3.insertFromRight<TT::CFG_AMAP_COL10, TT::CFG_AMAP_COL10_LEN>(i_bitmap);
    return;
}

/// @brief Change the ROQ address mapping
/// @param[in] i_bitmap ROQ bit map in the address counter
/// @note Assumes data is right-aligned
///
template <>
void program<mss::mc_type::ODYSSEY>::change_roq_bit( const uint64_t i_bitmap )
{
    using TT = mcbistTraits<mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>;
    iv_addr_map0.insertFromRight<TT::CFG_AMAP_ROQ, TT::CFG_AMAP_ROQ_LEN>(i_bitmap);
    return;
}

///
/// @brief Change the BANK_GROUP2 address mapping
/// @param[in] i_bitmap BANK_GROUP2 bit map in the address counter
/// @note Assumes data is right-aligned
///
template <>
void program<mss::mc_type::ODYSSEY>::change_bank_group2_bit( const uint64_t i_bitmap )
{
    using TT = mcbistTraits<mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>;
    iv_addr_map0.insertFromRight<TT::CFG_AMAP_BANK_GROUP2, TT::CFG_AMAP_BANK_GROUP2_LEN>(i_bitmap);
    return;
}

///
/// @brief Sets the RMW buffer's address into the buffer - Odyssey specialization
/// @param[in] i_addr the address to set in the RMW buffer
/// @param[in,out] io_data the RMW buffer's data
///
template<>
void set_rmw_address<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(const uint64_t i_addr,
        fapi2::buffer<uint64_t>& io_data)
{
    // Due to a chip bug, the 4-bit address field for the RMW buffer is split up over bits 3:5 and bit 9
    constexpr uint64_t ADDR_FIELD2 = 9;
    constexpr uint64_t ADDR_FIELD2_LEN = 1;
    constexpr uint64_t ADDR_FIELD1 = 3;
    constexpr uint64_t ADDR_FIELD1_LEN = 3;
    constexpr uint64_t SOURCE_START = 60;

    io_data.insertFromRight<ADDR_FIELD2, ADDR_FIELD2_LEN>(i_addr)
    .insert<ADDR_FIELD1, ADDR_FIELD1_LEN, SOURCE_START>(i_addr);
}

///
/// @brief Sets the RMW buffer's address into the buffer - Odyssey specialization
/// @param[in] i_addr the address to set in the RMW buffer
/// @param[in,out] io_data the RMW buffer's data
///
template<>
void set_rmw_address<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_MEM_PORT>(const uint64_t i_addr,
        fapi2::buffer<uint64_t>& io_data)
{
    set_rmw_address<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(i_addr, io_data);
}

///
/// @brief Loads the RMW buffer's control register mid loop if needed - Odyssey specialization
/// @param[in] i_target the target on which to operate
/// @param[in] i_data the RMW buffer's data
/// @return FAPI2_RC_SUCCSS iff ok
///
template<>
fapi2::ReturnCode load_rmw_control_mid_loop<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>
(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target, const fapi2::buffer<uint64_t>& i_data)
{
    using TT = mcbistTraits< mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>;
    return fapi2::putScom(i_target, TT::WDF_BUF_CTL_REG, i_data);
}

} // namespace mcbist
} // namespace mss
