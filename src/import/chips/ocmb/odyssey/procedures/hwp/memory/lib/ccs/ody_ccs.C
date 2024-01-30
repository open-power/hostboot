/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ccs/ody_ccs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2024                        */
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
/// @file ody_ccs.C
/// @brief Odyssey CCS specializations
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <lib/ecc/ecc_traits_odyssey.H>
#include <lib/ccs/ody_ccs_traits.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <generic/memory/lib/utils/conversions.H>
#include <lib/ccs/ody_ccs.H>
#include <lib/ccs/ody_ccs_read_processing.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/find.H>
#include <ody_scom_ody_odc.H>
#include <generic/memory/lib/ccs/ccs_instruction.H>
#include <generic/memory/lib/ccs/ccs_ddr5_commands.H>
#include <lib/ody_attribute_accessors_manual.H>
#include <generic/memory/lib/utils/fir/gen_mss_fir.H>
#include <lib/fir/ody_fir_traits.H>
#include <lib/fir/ody_unmask.H>
#include <generic/memory/lib/utils/mss_generic_check.H>

// Generates linkage
// CSN Quad encoded settings - Not supported for Odyssey as we only have two ranks so we cannot have a quad encoded CS
// Values do not matter here and are just added to keep the SBE compiler happy
const mss::pair<uint64_t, uint64_t> ccsTraits<mss::mc_type::ODYSSEY>::CS_N[mss::MAX_RANK_PER_DIMM] =
{
    { 0b11, 0b11 },
    { 0b11, 0b11 },
    { 0b11, 0b11 },
    { 0b11, 0b11 },
};

// CSN Setup for Dual Direct Mode
// Odyssey only has one DIMM and only has up to two ranks
// However, attributes can have up to 4 ranks per DIMM -> keeping this constant for consistent code between MC's
// For Odyssey, CS2/3 (the second number in the pair) are command 1's chip selects
const mss::pair<uint64_t, uint64_t> ccsTraits<mss::mc_type::ODYSSEY>::CS_ND[mss::MAX_RANK_PER_DIMM] =
{
    // CMD0 CS0 L CMD0 CS1 H => CMD1 CS0 => H CMD1 CS1 => H Rank 0
    { 0b01, 0b11 },

    // CMD0 CS0 H CMD0 CS1 L => CMD1 CS0 => H CMD1 CS1 => H Rank 1
    { 0b10, 0b11 },

    // Note: Invalid for Odyssey as we can only have two ranks
    // CMD0 CS0 H CMD0 CS1 H => CMD1 CS0 => L CMD1 CS1 => H Rank 2
    { 0b11, 0b11 },

    // Note: Invalid for Odyssey as we can only have two ranks
    // CMD0 CS0 H CMD0 CS1 H => CMD1 CS0 => H CMD1 CS1 => L Rank 3
    { 0b11, 0b11 },
};

// CSN Setup for NT ODT commands
// Odyssey only has one DIMM and only has up to two ranks
// However, attributes can have up to 4 ranks per DIMM -> keeping this constant for consistent code between MC's
// For Odyssey, CS2/3 (the second number in the pair) are command 1's chip selects
const mss::pair<uint64_t, uint64_t> ccsTraits<mss::mc_type::ODYSSEY>::CS_NTODT[mss::MAX_RANK_PER_DIMM] =
{
    // CMD0 CS0 L CMD0 CS1 L => CMD1 CS0 H CMD1 CS1 L Rank 0
    { 0b00, 0b10 },

    // CMD0 CS0 L CMD0 CS1 L => CMD1 CS0 L CMD1 CS1 H Rank 1
    { 0b00, 0b01 },

    // Note: Invalid for Odyssey as we can only have two ranks
    // Rank 2
    { 0b11, 0b11 },

    // Note: Invalid for Odyssey as we can only have two ranks
    // Rank 3
    { 0b11, 0b11 },
};

namespace mss
{
namespace ccs
{
namespace ddr5
{

///
/// @brief Updates the idle count for the write to write data enable - Odyssey specialization
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_inst the instruction to update
/// @return fapi2::ReturnCode SUCCESS iff procedure is successful
/// @note Just updates the idles of the instruction passed in assuming it is a write
/// Also assumes that the idles will just go to the write data enable and that any preprogrammed idles do not matter
/// Keeping this function as requiring specializations for future proofing as this is MC specific
/// This function should be run on a write command or on a command where write data needs to be passed out to the DRAM (legacy PDA or NTTM)
///
template <>
fapi2::ReturnCode update_wr_to_wr_data_enable_timing(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        mss::ccs::instruction_t<mss::mc_type::ODYSSEY>& io_inst)
{
    // CL is used as the base timing here

    // The calculations are as follows:
    // 1. subtract 18 to account for the write command and the staging latch (constant provided by design team)
    // 2. divide by 2 to account for 2:1 clock cycles from the PHY to the MC
    constexpr uint8_t CLOCK_DIVISOR = 2;
    constexpr uint8_t HW_DELAY = 18;
    uint8_t l_cl = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_CL, i_target, l_cl));

    l_cl = l_cl > HW_DELAY ? (l_cl - HW_DELAY) : 0;
    l_cl = l_cl / CLOCK_DIVISOR;
    io_inst.iv_idles = l_cl;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Appends the write data enable latching sequence to the instruction vector
/// @tparam MC The memory controller type of the traits
/// @param[in] i_port_rank the port rank on which to send data
/// @param[in,out] io_insts the instruction vector to update
/// @param[in] i_is_bc8 optional input true if this command is a BC8
/// @param[in] i_idles optional input of the idles before the next command
/// @note Keeping this function as requiring specializations for future proofing as this is MC specific
/// This function should be run after a command in which write data needs to be sent on the bus
///
template <>
void append_wr_data_enable_command<mss::mc_type::ODYSSEY>(const uint64_t i_port_rank,
        std::vector<mss::ccs::instruction_t<mss::mc_type::ODYSSEY>>& io_inst,
        const bool i_is_bc8,
        const uint16_t i_idles)
{
    typedef ccsTraits<mss::mc_type::ODYSSEY> TT;

    constexpr uint64_t PORT_RANK0_SEL = 0b01;
    constexpr uint64_t PORT_RANK1_SEL = 0b10;
    const auto RANK_SEL = i_port_rank == 0 ? PORT_RANK0_SEL : PORT_RANK1_SEL;

    // The data enables need to be started 6 DRAM clocks (3 CCS cycles) before the force data is set
    // For BL16, 4 CCS cycles are needed (leads to 8 DRAM clocks)
    // For BC8, 2 CCS cycles are needed (leads to 4 DRAM clocks)
    // Data on commands
    {
        auto l_inst = des_command<mss::mc_type::ODYSSEY>();
        l_inst.arr0.template insertFromRight<TT::ARR0_CMD0_WRDATA_CSN, TT::ARR0_CMD0_WRDATA_CSN_LEN>(RANK_SEL)
        .template insertFromRight<TT::ARR0_CMD1_WRDATA_CSN, TT::ARR0_CMD1_WRDATA_CSN_LEN>(RANK_SEL)
        .template setBit<TT::ARR0_CMD0_WRDATA_EN>()
        .template setBit<TT::ARR0_CMD1_WRDATA_EN>();

        // Hold the WR data enables for as long as needed
        {
            if(i_is_bc8)
            {
                l_inst.iv_repeats = 1;
                // As 3 cycles are needed, add in one idle here
                l_inst.iv_idles = 1;
            }
            else
            {
                l_inst.iv_repeats = 2;
            }

            io_inst.push_back(l_inst);
        }

        // Pulse data valid
        {
            // BC8? re-initialize the idle command to ensure the data enables are disabled
            if(i_is_bc8)
            {
                l_inst = des_command<mss::mc_type::ODYSSEY>();
            }
            else
            {
                l_inst.iv_repeats = 0;
            }

            l_inst.arr1.template setBit<TT::ARR1_FORCE_DATA>();
            io_inst.push_back(l_inst);
        }

        // Finally, add in the data set to a 0
        // TK check this again w/ logan
        {
            l_inst = des_command<mss::mc_type::ODYSSEY>();
            l_inst.iv_idles = i_idles;
            io_inst.push_back(l_inst);
        }
    }
}

} // namespace ddr5

///
/// @brief Create, initialize a JEDEC Device Deselect CCS command - Odyssey specialization
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the Device Deselect CCS instruction
///
template<>
instruction_t<mss::mc_type::ODYSSEY> des_command<mss::mc_type::ODYSSEY>(const uint16_t i_idle)
{
    // Odyssey uses DDR4 commands
    return mss::ccs::ddr5::des_command<mss::mc_type::ODYSSEY>(i_idle);
}

///
/// @brief Sets the chip selects to inactive for this instruction - Odyssey specialization
///
template<>
void instruction_t<mss::mc_type::ODYSSEY>::set_chipselects_inactive()
{
    using TT = ccsTraits<mss::mc_type::ODYSSEY>;

    arr0.insertFromRight<TT::ARR0_CMD0_CSN_0_1,
                         TT::ARR0_CMD0_CSN_0_1_LEN>(0b11);
    arr0.insertFromRight<TT::ARR0_CMD1_CSN_0_1,
                         TT::ARR0_CMD1_CSN_0_1_LEN>(0b11);
}

///
/// @brief Sets any signals associated with the chip selects for this instruction - Odyssey specialization
/// @param[in] i_target the port target for this instruction
/// @param[in] i_csn01 chip selects 0 and 1
/// @param[in] i_csn23 chip selects 2 and 3
/// @param[in] i_cid the chip ID values to set
/// @param[in] i_update_cid if true, the CID is updated, if not it is ignored
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
/// @note Odyssey specialization CS01 is for command 0, while CS23 is for command 1
///
template<>
fapi2::ReturnCode instruction_t<mss::mc_type::ODYSSEY>::set_chipselects_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const uint8_t i_csn01,
    const uint8_t i_csn23,
    const uint8_t i_cid,
    const bool i_update_cid)
{
    using TT = ccsTraits<mss::mc_type::ODYSSEY>;
    const auto l_dimm_rank = mss::index(iv_port_rank);
    uint8_t l_csn01 = i_csn01;
    uint8_t l_csn23 = i_csn23;
    uint8_t l_rtt_park_rd[mss::ody::MAX_DIMM_PER_PORT][mss::MAX_RANK_PER_DIMM] = {};
    uint8_t l_rtt_park_wr[mss::ody::MAX_DIMM_PER_PORT][mss::MAX_RANK_PER_DIMM] = {};
    bool l_nt_odt_needed = false;

    // Note: Non-target ODT enablement info is stored in the RTT_PARK_RD/WR attributes
    // and is encoded as 0=enable, 1=disable
    FAPI_TRY(mss::attr::get_ddr5_rtt_park_rd(i_target, l_rtt_park_rd));
    FAPI_TRY(mss::attr::get_ddr5_rtt_park_wr(i_target, l_rtt_park_wr));

    l_nt_odt_needed = (mss::ccs::ddr5::needs_nt_odt_rd(*this) && (l_rtt_park_rd[0][l_dimm_rank] == 0)) ||
                      (mss::ccs::ddr5::needs_nt_odt_wr(*this) && (l_rtt_park_wr[0][l_dimm_rank] == 0));

    // DDR5 requires different CSN settings for commands requiring non-target ODT
    if (l_nt_odt_needed)
    {
        l_csn01 = TT::CS_NTODT[l_dimm_rank].first;
        l_csn23 = TT::CS_NTODT[l_dimm_rank].second;
    }

    arr0.insertFromRight<TT::ARR0_CMD0_CSN_0_1,
                         TT::ARR0_CMD0_CSN_0_1_LEN>(l_csn01);
    arr0.insertFromRight<TT::ARR0_CMD1_CSN_0_1,
                         TT::ARR0_CMD1_CSN_0_1_LEN>(l_csn23);

    // CID and update CID are unused (no quad encoded chip select in DDR5)
    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Gets the CKE signals (Memory controller and DRAM technology dependent) - Odyssey specialization
/// @param[out] o_cke the CKE for this instruction
/// @note nothing to do for Odyssey
///
template<>
void instruction_t<mss::mc_type::ODYSSEY>::get_cke_helper(uint8_t& o_cke) const
{
}

///
/// @brief Sets the CKE signals (Memory controller and DRAM technology dependent) - Odyssey specialization
/// @param[in] i_cke the CKE for this instruction
/// @note nothing to do for Odyssey
///
template<>
void instruction_t<mss::mc_type::ODYSSEY>::set_cke_helper(const uint8_t i_cke)
{
}

///
/// @brief Gets the register value for the idles/repeats multiplier
/// @param[in] i_idles the requested number of idles
/// @param[in] i_repeats the requested number of repeats
/// @return the register value for the idles/repeats multiplier
///
uint8_t get_inst_idle_reg_multiplier(const uint16_t i_idles, const uint16_t i_repeats)
{
    typedef ccsTraits<mss::mc_type::ODYSSEY> TT;

    // First up, gets the multiplier
    const uint16_t MAX = std::max(i_idles, i_repeats);

    // The multiplier is just computed based upon the max
    // If the max is less than X padding amount, that's the amount to use
    if(MAX < TT::delay_padding::PADDING_NO_END)
    {
        return TT::delay_padding::REG_MULTIPLIER_0;
    }

    if(MAX < TT::delay_padding::PADDING_2_END)
    {
        return TT::delay_padding::REG_MULTIPLIER_2;
    }

    if(MAX < TT::delay_padding::PADDING_4_END)
    {
        return TT::delay_padding::REG_MULTIPLIER_4;
    }

    // Otherwise, use the max (8 padding bits)
    return TT::delay_padding::REG_MULTIPLIER_8;
}

///
/// @brief Gets the numeric value for the idles/repeats multiplier
/// @param[in] i_reg_multiplier the register value (0b00 to 0b11)
/// @return the register numeric for the idles/repeats multiplier
///
uint16_t get_inst_idle_numeric_multiplier(const uint8_t i_reg_multiplier)
{
    typedef ccsTraits<mss::mc_type::ODYSSEY> TT;

    uint16_t l_mult = TT::delay_padding::NUM_MULTIPLIER_0;

    switch(i_reg_multiplier)
    {
        case TT::delay_padding::REG_MULTIPLIER_0:
            l_mult = TT::delay_padding::NUM_MULTIPLIER_0;
            break;

        case TT::delay_padding::REG_MULTIPLIER_2:
            l_mult = TT::delay_padding::NUM_MULTIPLIER_2;
            break;

        case TT::delay_padding::REG_MULTIPLIER_4:
            l_mult = TT::delay_padding::NUM_MULTIPLIER_4;
            break;

        case TT::delay_padding::REG_MULTIPLIER_8:
        default:
            l_mult = TT::delay_padding::NUM_MULTIPLIER_8;
            break;
    }

    return l_mult;
}

///
/// @brief Updates the idles and repeats based upon the memory controller - Odyssey specialization
/// @param[in] i_target the port target for this instruction - for error logging
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode instruction_t<mss::mc_type::ODYSSEY>::configure_idles_and_repeats(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target )
{
    typedef ccsTraits<mss::mc_type::ODYSSEY> TT;

    // First grab the multipler
    const auto l_reg_multiplier = get_inst_idle_reg_multiplier(iv_idles, iv_repeats);
    const auto l_num_multiplier = get_inst_idle_numeric_multiplier(l_reg_multiplier);

    // Now, recompute idle and repeat values
    // We always want to round up for our number of idles and repeats
    // If there is a remainder, add in the multiplier to the register value to round up
    // More delay is always better than not enough
    const uint8_t l_idles_reg = (iv_idles / l_num_multiplier) + ((iv_idles % l_num_multiplier) == 0 ? 0 : 1);
    const uint8_t l_repeats_reg = (iv_repeats / l_num_multiplier) + ((iv_repeats % l_num_multiplier) == 0 ? 0 : 1);

    arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(l_idles_reg)
    .template insertFromRight<TT::ARR1_REPEAT_CMD_CNT, TT::ARR1_REPEAT_CMD_CNT_LEN>(l_repeats_reg)
    .template insertFromRight<TT::ARR1_PADDING, TT::ARR1_PADDING_LEN>(l_reg_multiplier);

    // At the end, get the idles and the repeats
    // This forces the updates to be in sync with what is in the instructions
    get_idles();
    get_repeats();

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Grabs the idles from the CCS array - Odyssey specialization
///
template<>
void instruction_t<mss::mc_type::ODYSSEY>::get_idles()
{
    typedef ccsTraits<mss::mc_type::ODYSSEY> TT;

    uint8_t l_reg_idles = 0;
    uint8_t l_reg_padding = 0;
    arr1.template extractToRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(l_reg_idles)
    .template extractToRight<TT::ARR1_PADDING, TT::ARR1_PADDING_LEN>(l_reg_padding);

    const auto l_num_multiplier = get_inst_idle_numeric_multiplier(l_reg_padding);
    iv_idles = l_reg_idles * l_num_multiplier;
}

///
/// @brief Grabs the repeats from the CCS array - Odyssey specialization
///
template<>
void instruction_t<mss::mc_type::ODYSSEY>::get_repeats()
{
    typedef ccsTraits<mss::mc_type::ODYSSEY> TT;

    uint8_t l_reg_repeats = 0;
    uint8_t l_reg_padding = 0;
    arr1.template extractToRight<TT::ARR1_REPEAT_CMD_CNT, TT::ARR1_REPEAT_CMD_CNT_LEN>(l_reg_repeats)
    .template extractToRight<TT::ARR1_PADDING, TT::ARR1_PADDING_LEN>(l_reg_padding);

    const auto l_num_multiplier = get_inst_idle_numeric_multiplier(l_reg_padding);
    iv_repeats = l_reg_repeats * l_num_multiplier;
}

///
/// @brief Grabs the repeats from the CCS array - Odyssey specialization
/// @param[in] i_target the port target for this instruction
/// @param[in] i_rank_config the rank configuration
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode instruction_t<mss::mc_type::ODYSSEY>::compute_parity(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
        i_target, const rank_configuration i_rank_config)
{
    // Odyssey does not need to manually compute parity at this time
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Configures the chip to properly execute CCS instructions - ODYSSEY specialization
/// @param[in] i_target The MCBIST containing the CCS engine
/// @param[in] i_ports the vector of ports
/// @param[in] i_program the vector of instructions
/// @param[out] o_periodics_reg the register used to enable periodic calibrations
/// @param[out] o_power_cntl_reg the register used for power control
/// @return FAPI2_RC_SUCCSS iff ok
///
template<>
fapi2::ReturnCode setup_to_execute<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> >& i_ports,
    const ccs::program<mss::mc_type::ODYSSEY>& i_program,
    fapi2::buffer<uint64_t>& o_periodics_reg,
    fapi2::buffer<uint64_t>& o_power_cntl_reg)
{
    fapi2::buffer<uint64_t> l_data;
    fapi2::buffer<uint64_t> l_pwr_cntl_reg_data;

    // Check for read/write commands, and set up workaround bits if needed
    FAPI_TRY(workarounds::setup_ccs_rdwr(i_ports, i_program));

    // Per the design team, periodics needs to be disabled for CCS to function properly
    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB9Q, o_periodics_reg));

    // Clear periodics
    l_data = o_periodics_reg;
    l_data.clearBit<scomt::ody::ODC_SRQ_MBA_FARB9Q_ZQ_PER_CAL_ENABLE>()
    .clearBit<scomt::ody::ODC_SRQ_MBA_FARB9Q_MC_PER_CAL_ENABLE>();

    // Write the register
    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB9Q, l_data));

    // Get the DDR Power control register data and store it away
    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_SRQ_MBARPC0Q, o_power_cntl_reg));

    // Clear Domain Reduction Enable bit
    l_pwr_cntl_reg_data = o_power_cntl_reg;
    l_pwr_cntl_reg_data.clearBit<scomt::ody::ODC_SRQ_MBARPC0Q_CFG_MIN_DOMAIN_REDUCTION_ENABLE>();

    // Write the register
    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_SRQ_MBARPC0Q, l_pwr_cntl_reg_data));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Cleans up from a CCS execution - multiple ports - ODYSSEY specialization
/// @param[in] i_target The MCBIST containing the CCS engine
/// @param[in] i_program the vector of instructions
/// @param[in] i_ports the vector of ports
/// @param[in] i_periodics_reg the register used to enable periodic calibrations
/// @param[in] i_power_cntl_reg the register used for power control
/// @return FAPI2_RC_SUCCSS iff ok
///
template<>
fapi2::ReturnCode cleanup_from_execute<mss::mc_type::ODYSSEY>(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target,
        const ccs::program<mss::mc_type::ODYSSEY>& i_program,
        const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> >& i_ports,
        const fapi2::buffer<uint64_t> i_periodics_reg,
        const fapi2::buffer<uint64_t> i_power_cntl_reg)
{
    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB9Q, i_periodics_reg));
    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_SRQ_MBARPC0Q, i_power_cntl_reg));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup before running concurrent CCS - ODYSSEY specialization
/// @param[in] i_target the ocmb chip target
/// @param[out] o_value returns the original value of ODC_SRQ_MBA_FARB0Q
/// @return FAPI2_RC_SUCCSS iff ok
///
template<>
fapi2::ReturnCode pre_execute_via_mcbist<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    fapi2::buffer<uint64_t>& o_value)
{
    bool l_recov;
    bool l_has_rcd = false;
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB0Q, l_data));
    o_value = l_data;
    l_recov = l_data.getBit<scomt::ody::ODC_SRQ_MBA_FARB0Q_CFG_DISABLE_RCD_RECOVERY>();
    FAPI_TRY(mss::has_rcd(i_target, l_has_rcd));

    // Disable RCD_discovery and set RCD parity FIR bits to XSTOP before concurrent CCS.
    // Do it only if recovery is enabled AND ports have rcd.
    // Needed as a workaround for an Odyssey erratum.
    if(!l_recov && l_has_rcd)
    {
        // for FIR setting
        mss::fir::reg2<scomt::ody::ODC_SRQ_LFIR_RW_WCLEAR> l_srq_reg(i_target);
        const auto& l_ports = mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target);
        // Port specific errors
        // Set the RCD errors to recoverable based upon the port
        FAPI_TRY(mss::unmask::set_fir_bit_if_port_has_rcd<scomt::ody::ODC_SRQ_LFIR_IN04>(l_ports,
                 mss::unmask::IDX_PORT0,
                 mss::fir::action::XSTOP,
                 l_srq_reg));
        FAPI_TRY(mss::unmask::set_fir_bit_if_port_has_rcd<scomt::ody::ODC_SRQ_LFIR_IN33>(l_ports,
                 mss::unmask::IDX_PORT1,
                 mss::fir::action::XSTOP,
                 l_srq_reg));
        FAPI_TRY(l_srq_reg.write(), "Failed to write SRQ FIR register for " GENTARGTIDFORMAT, GENTARGTID(i_target));
        l_data.setBit<scomt::ody::ODC_SRQ_MBA_FARB0Q_CFG_DISABLE_RCD_RECOVERY>();
        FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB0Q, l_data));
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup after running concurrent CCS - ODYSSEY specialization
/// @param[in] i_target the ocmb chip target
/// @param[in] i_value value of ODC_SRQ_MBA_FARB0Q to be restored
/// @return FAPI2_RC_SUCCSS iff ok
///
template<>
fapi2::ReturnCode post_execute_via_mcbist<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const fapi2::buffer<uint64_t>& i_value)
{
    bool l_recov;
    bool l_has_rcd = false;
    mss::fir::reg2<scomt::ody::ODC_SRQ_LFIR_RW_WCLEAR> l_srq_reg(i_target);
    const auto& l_ports = mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

    // Check the recovery bit status before making pre_execute_via_mcbist changes
    l_recov = i_value.getBit<scomt::ody::ODC_SRQ_MBA_FARB0Q_CFG_DISABLE_RCD_RECOVERY>();
    FAPI_TRY(mss::has_rcd(i_target, l_has_rcd));

    // Restore the recovery bit and FIR bits after concurrent CCS.
    if(!l_recov && l_has_rcd)
    {
        // Port specific errors
        // Set the RCD errors to recoverable based upon the port
        FAPI_TRY(mss::unmask::set_fir_bit_if_port_has_rcd<scomt::ody::ODC_SRQ_LFIR_IN04>(l_ports,
                 mss::unmask::IDX_PORT0,
                 mss::fir::action::RECOV,
                 l_srq_reg));
        FAPI_TRY(mss::unmask::set_fir_bit_if_port_has_rcd<scomt::ody::ODC_SRQ_LFIR_IN33>(l_ports,
                 mss::unmask::IDX_PORT1,
                 mss::fir::action::RECOV,
                 l_srq_reg));
        FAPI_TRY(l_srq_reg.write(), "Failed to write SRQ FIR register for " GENTARGTIDFORMAT, GENTARGTID(i_target));
        // Restore the recovery bit to i_value that is stored from pre_execute_via_mcbist
        FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB0Q, i_value));
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configures registers for concurrent CCS execution - ODYSSEY specialization
/// @param[in] i_target The MC target
/// @param[out] o_modeq_reg A buffer to return the original value of modeq
/// @param[in] i_nttm_mode state to write to the NTTM mode bit (default false)
/// @return FAPI2_RC_SUCCESS iff okay
///
template <>
fapi2::ReturnCode config_ccs_regs_for_concurrent<mss::mc_type::ODYSSEY>(const
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        fapi2::buffer<uint64_t>& o_modeq_reg,
        const mss::states i_nttm_mode)
{
    using TT = ccsTraits<mss::mc_type::ODYSSEY>;

    // Use a temp buffer to save original settings
    fapi2::buffer<uint64_t> l_temp = 0;

    // Configure modeq register
    FAPI_TRY(mss::getScom(i_target, TT::MODEQ_REG, o_modeq_reg));
    l_temp = o_modeq_reg;
    l_temp.template writeBit<TT::NTTM_MODE>(i_nttm_mode); // 1 = nontraditional transparent mode
    l_temp.template clearBit<TT::STOP_ON_ERR>();          // 1 = stop on ccs error
    l_temp.template setBit<TT::UE_DISABLE>();             // 1 = hardware ignores UEs
    l_temp.template
    clearBit<TT::DDR_PARITY_ENABLE>();      // HW drives computes the parity rather than using CCS array's value
    l_temp.template
    setBit<TT::IDLE_PAT_ADDRESS_0_13, TT::IDLE_PAT_ADDRESS_0_13_LEN>(); // Setting these to a 1 so the command is a NOP
    FAPI_TRY(mss::putScom(i_target, TT::MODEQ_REG, l_temp));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determine the CCS failure type - ODYSSEY specialization
/// @param[in] i_target OCMB target
/// @param[in] i_type the failure type
/// @param[in] i_port The port the CCS instruction is training
/// @return ReturnCode associated with the fail.
/// @note FFDC is handled here, caller doesn't need to do it
///
template<>
fapi2::ReturnCode fail_type<mss::mc_type::ODYSSEY>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint64_t i_type,
        const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port )
{
    typedef ccsTraits<mss::mc_type::ODYSSEY> TT;

    // Including the PORT_TARGET here and below at CAL_TIMEOUT since these problems likely lie at the MEM_PORT/PHY level
    // So we disable the PORT and hopefully that's it
    // If the problem lies with the OCMB_CHIP (Odyssey memory controller), it'll just have to loop
    FAPI_ASSERT(TT::STAT_READ_MISCOMPARE != i_type,
                fapi2::MSS_ODY_CCS_READ_MISCOMPARE()
                .set_MC_TARGET(i_target)
                .set_FAIL_TYPE(i_type)
                .set_PORT_TARGET(i_port),
                TARGTIDFORMAT " CCS FAIL Read Miscompare", GENTARGTID(i_port));

    // This error is likely due to a bad CCS engine/ Odyssey chip
    FAPI_ASSERT(TT::STAT_UE_SUE != i_type,
                fapi2::MSS_ODY_CCS_UE_SUE()
                .set_FAIL_TYPE(i_type)
                .set_MC_TARGET(i_target),
                TARGTIDFORMAT " CCS FAIL UE or SUE Error", GENTARGTID(i_target));

    // Problem with the CCS engine
    FAPI_ASSERT(TT::STAT_HUNG != i_type,
                fapi2::MSS_ODY_CCS_HUNG().set_MC_TARGET(i_target),
                TARGTIDFORMAT " CCS appears hung", GENTARGTID(i_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // This fail could be related to a lit FIR, but for SPPE we rely on the ody_blame_firs HWP
    // to check them and trigger PRD handling. So here we just return the failing RC
    return fapi2::current_err;
}

///
/// @brief EXP specialization for modeq_copy_cke_to_spare_cke
/// @param[in] fapi2::Target<TARGET_TYPE_OCMB_CHIP>& the target to effect
/// @param[in,out] the buffer representing the mode register
/// @param[in] mss::states - mss::ON iff Copy CKE signals to CKE Spare on both ports
/// @note no-op for Odyssey
///
template<>
void copy_cke_to_spare_cke<mss::mc_type::ODYSSEY>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
        fapi2::buffer<uint64_t>&, states )
{
    return;
}

///
/// @brief Select the port(s) to be used by the CCS - ODYSSEY specialization
/// @param[in] i_target the target to effect
/// @param[in] i_ports the buffer representing the ports
/// @param[in] i_channel_select the channels upon which to operate - DDR5+ only specific
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
/// @note The same channel and port selects will be used across the entire CCS program in a single execution
/// Separate channel/port selects would need to be run on a different CCS execution call
///
template<>
fapi2::ReturnCode select_ports<mss::mc_type::ODYSSEY>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint64_t i_ports,
        const channel_select i_channel_select)
{
    typedef ccsTraits<mss::mc_type::ODYSSEY> TT;
    constexpr uint64_t PORT0_SHIFT = 2;
    const auto l_port_value = i_ports == 0 ? (i_channel_select << PORT0_SHIFT) : i_channel_select;

    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY( mss::getScom(i_target, TT::MODEQ_REG, l_data) );
    l_data.insertFromRight<TT::PORT_SEL, TT::PORT_SEL_LEN>(l_port_value);
    FAPI_TRY( mss::putScom(i_target, TT::MODEQ_REG, l_data) );

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines our rank configuration type - Odyssey specialization
/// @param[in] i_target the MCA target on which to operate
/// @param[out] o_rank_config the rank configuration
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode get_rank_config<mss::mc_type::ODYSSEY>(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        rank_configuration& o_rank_config)
{
    // Odyssey only supports dual direct
    o_rank_config = rank_configuration::DUAL_DIRECT;
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Turns off data inversion before MR access - Odyssey specialization
/// @param[in] i_target the port target on which to operate
/// @param[out] o_orig_recr to restore the RECR register's data inversion bits to original state
/// @return fapi2::FAPI2_RC_SUCCESS iff successful, fapi2 error code otherwise
///
template<>
fapi2::ReturnCode disable_recr_data_inversion<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    fapi2::buffer<uint64_t>& o_orig_recr)

{
    fapi2::buffer<uint64_t> l_data;
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    FAPI_TRY(fapi2::getScom(l_ocmb, scomt::ody::ODC_WDF_REGS_RECR, o_orig_recr));
    l_data = o_orig_recr;
    l_data.clearBit<scomt::ody::ODC_WDF_REGS_RECR_MBSECCQ_DATA_INVERSION, scomt::ody::ODC_WDF_REGS_RECR_MBSECCQ_DATA_INVERSION_LEN>();
    FAPI_TRY(fapi2::putScom(l_ocmb, scomt::ody::ODC_WDF_REGS_RECR, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Process the MR data out of the trace array - Odyssey specialization
/// @param[in] i_target the port target on which to operate
/// @param[out] o_data array of mr values per dram
/// @return fapi2::FAPI2_RC_SUCCESS iff successful, fapi2 error code otherwise
///
template<>
fapi2::ReturnCode mr_data_process<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    uint8_t (&o_data)[ccsTraits<mss::mc_type::ODYSSEY>::NUM_DRAM_X4])
{
    using TT = ccsTraits<mss::mc_type::ODYSSEY>;

    mss::pair<uint64_t, uint16_t> l_processed_data[mss::ody::CCS_BEAT_DATA_SIZE];

    // Read and process the CCS data out of the buffers
    FAPI_TRY(mss::ccs::prepare_ody_ccs_beat_data(i_target, l_processed_data));
    {
        uint8_t l_dram_width[mss::ody::MAX_PORT_PER_OCMB] = {};
        int l_num_dram = 0;

        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_WIDTH, i_target, l_dram_width) );
        l_num_dram = (l_dram_width[0] == 4) ? TT::NUM_DRAM_X4 : TT::NUM_DRAM_X8;

        for (uint8_t l_dq_index = 0; l_dq_index < l_num_dram; l_dq_index++)
        {
            uint8_t l_op_code = 0;
            FAPI_TRY(mss::ccs::get_op_code(l_dq_index, l_dram_width[0], l_processed_data, l_op_code ));
            FAPI_DBG(GENTARGTIDFORMAT " DRAM%d OP=0x%02X", GENTARGTID(i_target), l_dq_index, l_op_code);
            o_data[l_dq_index] = l_op_code;
        }

    }

fapi_try_exit:
    return fapi2::current_err;
}

namespace workarounds
{

///
/// @brief Sets up read/write address workaround bits in FARB2 if necessary
/// @param[in] i_ports the vector of ports
/// @param[in] i_program the vector of instructions
/// @note this function will fail if CCS program contains read/write commands that target different ranks
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode setup_ccs_rdwr(
    const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> >& i_ports,
    const ccs::program<mss::mc_type::ODYSSEY>& i_program)
{
    typedef ccsTraits<mss::mc_type::ODYSSEY> TT;

    if (i_ports.size() == 0)
    {
        // No ports? Just exit
        return fapi2::FAPI2_RC_SUCCESS;
    }

    const auto& l_mc = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_ports[0]);
    uint64_t l_port_rank = NO_CHIP_SELECT_ACTIVE;
    bool l_is_half_dimm_mode = false;
    fapi2::buffer<uint64_t> l_farb2;

    // Check for read/write commands and record what rank they go to
    for (const auto& l_inst : i_program.iv_instructions)
    {
        if (mss::ccs::ddr5::is_write_or_read(l_inst))
        {
            if (l_port_rank == NO_CHIP_SELECT_ACTIVE)
            {
                // This is the first read/write command, so record the rank
                l_port_rank = l_inst.iv_port_rank;
            }
            else
            {
                // This is not the first read/write, so assert that this command uses the same rank as previous
                // Note that if we have some read/write with valid CS along with other(s) that have NO_CHIP_SELECT_ACTIVE
                // this is ok, and the workaround bits in FARB2 only matter if the CS is active in a command
                FAPI_ASSERT((l_inst.iv_port_rank == l_port_rank) || (l_inst.iv_port_rank == NO_CHIP_SELECT_ACTIVE),
                            fapi2::MSS_ODY_CCS_INCONSISTENT_RANK()
                            .set_MC_TARGET(l_mc)
                            .set_FIRST_PORT_RANK(l_port_rank)
                            .set_MISMATCHED_PORT_RANK(l_inst.iv_port_rank),
                            TARGTIDFORMAT " mismatched ports in CCS program (%d, %d). All write and read data must go to same rank",
                            GENTARGTID(l_mc), l_port_rank, l_inst.iv_port_rank);
            }
        }
    }

    if (l_port_rank == NO_CHIP_SELECT_ACTIVE)
    {
        FAPI_DBG(TARGTIDFORMAT " No rank-specific read/write commands, so no need to set RDWR_SET_M0/1", GENTARGTID(l_mc));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Set the workaround bits according to the rank we're targeting
    FAPI_TRY(fapi2::getScom(l_mc, scomt::ody::ODC_SRQ_MBA_FARB2Q, l_farb2));

    // M1 should be set to the port rank of the read/write commands since Odyssey only uses one DIMM per port
    l_farb2.writeBit<scomt::ody::ODC_SRQ_MBA_FARB2Q_CFG_CCS_RDWR_SET_M1>(l_port_rank);
    FAPI_DBG(TARGTIDFORMAT " read/write to rank %d, so setting RDWR_SET_M1 to %d", GENTARGTID(l_mc), l_port_rank,
             l_port_rank);

    FAPI_TRY(mss::ody::half_dimm_mode(l_mc, l_is_half_dimm_mode));

    if (l_is_half_dimm_mode)
    {
        // For XMETA mode, M0 needs to be set to the DIMM half, AKA the selected channel (CHA=0, CHB=1)
        constexpr uint64_t CHA = 0b1010;
        constexpr uint64_t CHB = 0b0101;

        fapi2::buffer<uint64_t> l_modeq;
        uint8_t l_port_sel = 0;

        FAPI_TRY( mss::getScom(l_mc, TT::MODEQ_REG, l_modeq) );
        l_modeq.extractToRight<TT::PORT_SEL, TT::PORT_SEL_LEN>(l_port_sel);

        // Error out if we have both DIMM halves (channels) selected in the CCS mode reg
        // Note that we are currently selecting both channels for every CCS program so this
        // will always fail for XMETA on programs we've set up in our lib code
        FAPI_ASSERT(!((l_port_sel & CHA) && (l_port_sel & CHB)),
                    fapi2::MSS_ODY_CCS_XMETA_BOTH_HALVES_SELECTED()
                    .set_MC_TARGET(l_mc)
                    .set_PORT_SEL(l_port_sel),
                    TARGTIDFORMAT
                    " PORT_SEL bits select both halves in CCS MODEQ (%d). Only one half can be selected at a time in XMETA mode",
                    GENTARGTID(l_mc), l_port_sel);

        l_farb2.writeBit<scomt::ody::ODC_SRQ_MBA_FARB2Q_CFG_CCS_RDWR_SET_M0>(l_port_sel & CHB);
    }

    FAPI_TRY(fapi2::putScom(l_mc, scomt::ody::ODC_SRQ_MBA_FARB2Q, l_farb2));

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace workarounds
} // namespace ccs
} // namespace mss
