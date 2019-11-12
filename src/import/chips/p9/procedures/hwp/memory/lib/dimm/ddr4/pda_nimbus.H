/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/pda_nimbus.H $ */
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
/// @file pda_nimbus.H
/// @brief Code to support per-DRAM addressability (PDA)
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB Memory Lab

#ifndef _MSS_PDA_NIMBUS_H_
#define _MSS_PDA_NIMBUS_H_

#include <fapi2.H>
#include <lib/shared/mss_const.H>
#include <generic/memory/lib/dimm/ddr4/pda.H>

namespace mss
{

namespace ddr4
{

namespace pda
{

///
/// @brief Holds all PDA specific constants
///
enum consts : uint64_t
{
    // Note: the delay is taken from the PDA timing register's maximum value 2^6
    MAX_PDA_REG = 64,
    // 10 cycles for safety
    SAFETY = 10,
    // Total delay is your register max + safety
    SAFE_COMMAND_DELAY = MAX_PDA_REG + SAFETY,

    // PDA on/off settings
    START_DELAY_VALUE = 0,
    HOLD_DELAY_VALUE = 0xff,

    // Each enable is just 1 bit and there are 4 per reg.  Adding a length here to make the code look better
    NUM_DRAM_PER_REG = 4,

    // DRAM bit constants
    DRAM0 = MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N0,
    DRAM1 = MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N1,
    DRAM2 = MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N2,
    DRAM3 = MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N3,
    DRAM_START = DRAM0,
};

///
/// @brief Write bit for PDA specialization for x4 devices
///
template < >
class pdaBitTraits<fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4, mss::mc_type::NIMBUS>
{
    public:
        // One nibble is needed - the register has one nibble per bit, so one bit
        static constexpr uint64_t NUM_BITS = 1;
        static constexpr uint64_t NUM_DRAMS = MAX_DRAMS_X4;
        static const std::vector<std::pair<uint64_t, uint64_t>> BIT_MAP;
};

///
/// @brief Write bit for PDA specialization for x8 devices
///
template < >
class pdaBitTraits<fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8, mss::mc_type::NIMBUS>
{
    public:
        // Two nibbles are needed - the register has one nibble per bit, so two bits
        static constexpr uint64_t NUM_BITS = 2;
        static constexpr uint64_t NUM_DRAMS = MAX_DRAMS_X8;
        static const std::vector<std::pair<uint64_t, uint64_t>> BIT_MAP;
};


///
/// @brief Configures PDA timings
/// @param[in,out] io_buffer buffer on which the PDA timings live
/// @note Configuring timings is a helper function, as it is used both in PDA and PBA
/// PBA requires that we set the timings, but not enable PDA mode in the WC config, so we have a helper function
///
void configure_timings( fapi2::buffer<uint64_t>& io_buffer );


///
/// @brief Configures PDA timings
/// @param[in] i_target a fapi2::Target MCA
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode configure_timings_and_enable( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

} // ns pda

} // ns ddr4

} // ns mss

#endif
